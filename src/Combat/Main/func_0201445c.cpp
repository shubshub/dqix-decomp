#include <globaldefs.h>

#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);

// USA: ProcessNSBTXFile
// Main, originally Zone3D::ProcessNSBTXFile_0201445c (USA 0x0201445c, EUR 0x0201446c, JPN 0x02014228)
ARM bool Zone3D::ProcessNSBTXFile(const void* pFile, unsigned int fileSize, const char* pName)
{
    SafeAllocator* pAlloc = pAllocator_68_;
    char* vramState = (char*)vramState_;
    unsigned int rawLength;
    void* pRaw;
    Zone3D::Model3DListNode* var4 =
        (Zone3D::Model3DListNode*)pAlloc->Allocate(sizeof(Zone3D::Model3DListNode));
    Model3D* pModel;

    if (var4) {
        pModel = &var4->model_;
        pModel->Clear();
        var4->filename_ = 0;
        var4->pNext_ = 0;
        var4->filename_ = (char*)pAlloc->Allocate(strlen(pName) + 1);
        if (var4->filename_) {
            strcpy((char*)var4->filename_, pName);
            var4->pNext_ = firstModel_418_;
            firstModel_418_ = var4;
            pRaw = DecompressLZ77FileIntoScratchSpace(*pAlloc, pFile, rawLength);
            if (pRaw) {
                VramState_Restore(vramState);
                pModel->SetRawFile(pRaw, rawLength);
                pModel->ClearRawFileCache();
                pModel->ProcessRawFile(Model3D::TextureStagingMode_Immediate);
                VramState_Save(vramState);

                NSBXXTex* pTex = pModel->GetTEX0();
                if (pTex) {
                    textureImageMemory_ += NSBXX_Tex_GetBlock1Length(pTex);
                    texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(pTex);
                }
                bool var7 = false;
                if (pTex) {
                    // keep the TEX0 block up to its first data block (the textures are in VRAM now)
                    unsigned int nTexHeaderSize = pTex->block1Offset_;
                    void* pCopy = pAlloc->Allocate(nTexHeaderSize);
                    if (pCopy) {
                        memcpy(pCopy, pTex, nTexHeaderSize);
                        pModel->SetTEX0((NSBXXTex*)pCopy);
                        var7 = true;
                    }
                }
                if (!var7) {
                    pModel->Clear();
                }
            }
        }
    }
    return true;
}
