#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_020ef1d6 data_020ef112
#endif
extern char data_020ef1d6[];  // "%s.bats": the BATS file named after substruct_c_.buffer1

// Main, originally Zone3D::UnpackATS_AMBL_02014c04 (USA 0x02014c04, EUR 0x02014c14, JPN 0x020149d0)
ARM int Zone3D::UnpackATS_AMBL() {
    if (atsAMBLLoadHandle_ < 0) return 1;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader->GetTaskStatus(atsAMBLLoadHandle_)) return 0;
    if (loader->GetDetailedTaskStatus(atsAMBLLoadHandle_) != BackgroundLoader::TaskStatus_Complete) {
        loader->RemoveTask(atsAMBLLoadHandle_);
        atsAMBLLoadHandle_ = -1;
        QueueLoadMapAMDJ();
        return 1;
    }
    void* archive;
    unsigned int archiveSize;
    const void* script;
    unsigned int scriptSize;
    char filename[0x28];
    loader->GetLoadedFileByID(atsAMBLLoadHandle_, &archive, &archiveSize);
    sprintf(filename, data_020ef1d6, substruct_c_.buffer1);
    if (!GetFileInNarc(archive, filename, &script, &scriptSize, 0)) {
        loader->RemoveTask(atsAMBLLoadHandle_);
        atsAMBLLoadHandle_ = -1;
        QueueLoadMapAMDJ();
        return 1;
    }
    ProcessBATSFile(script, scriptSize);
    loader->RemoveTask(atsAMBLLoadHandle_);
    atsAMBLLoadHandle_ = -1;
    QueueLoadMapAMDJ();
    return 1;
}
