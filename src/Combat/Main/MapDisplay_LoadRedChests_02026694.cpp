#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/MapDisplay.h"

struct Struct_02026780;
extern "C" int func_02026780(MapDisplay* context, void* archive, unsigned int archiveSize);

extern const char data_020ef6d7[];

// Main, originally HandleQueuedEntry02026694 (USA 0x02026694, EUR 0x020266a4, JPN 0x02025ff8)
extern "C" ARM void MapDisplay_LoadRedChests(MapDisplay* context) {
    if (context->field9b8 == 0) return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (context->field9b9 == 0) {
        loader->RemoveTask(context->taska2c);
        loader->AddFence();
        context->taska2c = loader->QueueLoadFile(data_020ef6d7, NULL);
        context->field9b9++;
        return;
    }
    if (context->field9b9 != 1) return;
    if (loader->GetTaskStatus(context->taska2c) == 0) return;

    void* archive = NULL;
    unsigned int archiveSize = 0;
    loader->GetLoadedFileByID(context->taska2c, &archive, &archiveSize);
    if (func_02026780(context, archive, archiveSize) == 0) {
        context->field9ba = 1;
    } else {
        context->refreshRecords = 1;
        context->field9ba = 1;
    }
    loader->RemoveTask(context->taska2c);
    context->taska2c = -1;
    context->field9b8 = 0;
    context->field9b9++;
}
