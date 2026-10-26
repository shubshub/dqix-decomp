#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"


extern "C" {
    void HaltSystem();
    void _ZN6Zone3D17QueueLoadATS_AMBLEv(void* obj);
}

void RunBufferedStream0205e104(char*, SafeAllocator*, const void*, unsigned int);
#if defined(jpn)
#define data_020ef13e data_020ef07a
#define data_020ef145 data_020ef081
#define data_020ef14b data_020ef087
#define data_020ef150 data_020ef08c
#endif

// "ARC" (the archive's name for NarcHandle), then the extensions of the files inside: ".nsbtx" (textures, first pass),
// ".bmbl", ".dat" (an LZ77 stream run into substruct_c_.buffer1) and ".bpos" (second pass)
extern char data_020ef13a;
extern char data_020ef13e;
extern char data_020ef145;
extern char data_020ef14b;
extern char data_020ef150;

enum { kTexturePass = 0, kScriptPass = 1, kPassCount = 2 };

// KEEP-NAME
// USA: func_02014108
// Main, originally Zone3D::UnpackMapAMBL_02014108 (USA 0x02014108, EUR 0x02014118, JPN 0x02013ed4)
ARM int Zone3D::UnpackMapAMBL() {
    if (mapAMBLLoadHandle_ < 0) {
        return 1;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(mapAMBLLoadHandle_)) {
        return 0;
    }

    if (loader->GetDetailedTaskStatus(mapAMBLLoadHandle_) != BackgroundLoader::TaskStatus_Complete) {
        loader->RemoveTask(mapAMBLLoadHandle_);
        mapAMBLLoadHandle_ = -1;
        return 1;
    }

    void* archiveData;
    unsigned int archiveLength;
    loader->GetLoadedFileByID(mapAMBLLoadHandle_, &archiveData, &archiveLength);

    for (int pass = kTexturePass; pass < kPassCount; pass++) {
        NarcHandle narc;
        if (narc.Initialize(&data_020ef13a, static_cast<const unsigned char*>(archiveData))) {
            NitroVM vm;
            unsigned int fileID = 0;
            NitroVM_Initialize(&vm);
            while (PrepareReadFileInNARCByID(&vm, &narc, fileID)) {
                char innerFilePath[0x50];
                NitroVM_WriteOutFilePath(&vm, innerFilePath, sizeof(innerFilePath));
                char* extension = strrchr(innerFilePath, '.');
                if (extension == 0) {
                    NitroVM_FinishRead(&vm);
                    fileID++;
                    continue;
                }
                unsigned int innerFileLength = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
                NitroVM_FinishRead(&vm);
                const void* innerFile = narc.GetFileByIndex(fileID);
                if (pass == kTexturePass) {
                    if (strcmp(&data_020ef13e, extension) == 0) {
                        ProcessNSBTXFile(innerFile, innerFileLength, innerFilePath);
                    }
                } else if (pass == kScriptPass) {
                    if (strcmp(&data_020ef145, extension) == 0) {
                        ProcessBMBLFile(innerFile, innerFileLength);
                    } else if (strcmp(&data_020ef14b, extension) == 0) {
                        SafeAllocator* allocator = pAllocator_68_;
                        unsigned int streamLength;
                        void* stream = DecompressLZ77FileIntoScratchSpace(*allocator, innerFile, streamLength);
                        RunBufferedStream0205e104(substruct_c_.buffer1, allocator, stream, streamLength);
                    } else if (strcmp(&data_020ef150, extension) == 0) {
                        ProcessBPOSFile(innerFile, innerFileLength);
                    }
                }
                fileID++;
            }
            narc.Destroy();
        }

        // after the textures, the rest of pAllocator_4c_'s free space becomes internalAllocator_, which the zone's
        // other data comes from (pAllocator_68_)
        if (pass == kTexturePass) {
            unsigned int freeSize = pAllocator_4c_->GetMaxPossibleAllocation();
            void* freeBlock = pAllocator_4c_->Allocate(freeSize);
            if (freeBlock == 0) {
                HaltSystem();
            }
            internalAllocator_.ResetAllocatorPointer();
            internalAllocator_.CreateTypeA(freeBlock, freeSize);
            pAllocator_68_ = &internalAllocator_;
            internalAllocator_.Reset();
        }
    }

    loader->RemoveTask(mapAMBLLoadHandle_);
    mapAMBLLoadHandle_ = -1;
    _ZN6Zone3D17QueueLoadATS_AMBLEv(this);
    return 1;
}
