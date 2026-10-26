#include "Filesystem/BackgroundLoader.h"
#include <globaldefs.h>


extern "C" void MapDisplay_RemoveTask(void *unusedSelf, int *task);

// The MapDisplay fields this resets (header names in brackets)
struct Struct_02022bb0 {
#if defined(jpn)
    char pad0[0x90c];
#else
    char pad0[0x9b8];
#endif
    unsigned char redChestLoadPending; // [field9b8] MapDisplay_LoadRedChests loads treasure.nsarc while it is set
    char unknown_9b9_[8];
    unsigned char currentMode;         // [field9c1] the mode MapDisplay_RunModeLoader loads
    unsigned char loadStage;           // [loadStage]
    unsigned char modeLoading;         // [field9c3]
    unsigned char fadeInPending;       // [field9c4] MapDisplay_Draw fades the sub screen in while it is set
    unsigned char unknown_9c5_;
    char unknown_9c6_[6];
    int iconArchiveTask;               // [fileTask920] obj_mm.pac
    int mapScriptTask;                 // [namesTask] <map>.bmmp
    int patternTask;                   // [fileTask928] <name>.obg, the background pattern
    int pieceTasks[8];                 // [nameTasks] the map pieces' .obg
#if defined(jpn)
    char unknown_94c_[4];
#else
    int mapNameTask;                   // [scriptTask] mapname_<LG>.bin
#endif
    int treasureMapBaseTask;           // [task9fc] tmap_base.pac (modes 1 and 2)
    int taska00;
    int taska04;
    int taska08;
    int unknown_a0c_;
    int taska10;
    int taska14;
    int taska18;
    int taska1c;
    int taska20;
    int taska24;
    int taska28;
    int redChestTask;                  // [taska2c] treasure.nsarc
    int shipPositionsTask;             // [fileTask984] shipMPos.bin
    unsigned char previousMode;
};

// Main, originally func_02022bb0 (USA 0x02022bb0, EUR 0x02022bc0, JPN 0x02022644)
extern "C" ARM void MapDisplay_CancelLoading(void *receiver) {
    Struct_02022bb0 *object = (Struct_02022bb0 *) receiver;
    object->modeLoading             = 0;
    object->loadStage               = 0;
    object->unknown_9c5_                 = 0;
    object->redChestLoadPending     = 0;
    object->previousMode            = 0xff;
    object->fadeInPending           = 0;

    BackgroundLoader::GetInstance()->RemoveTask(object->iconArchiveTask);
    object->iconArchiveTask = -1;
#if !defined(jpn)
    BackgroundLoader::GetInstance()->RemoveTask(object->mapNameTask);
    object->mapNameTask = -1;
#endif
    BackgroundLoader::GetInstance()->RemoveTask(object->mapScriptTask);
    object->mapScriptTask = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->patternTask);
    object->patternTask = -1;

    for (int i = 0; i < 8; i++) {
        MapDisplay_RemoveTask(receiver, &object->pieceTasks[i]);
    }

    BackgroundLoader::GetInstance()->RemoveTask(object->treasureMapBaseTask);
    object->treasureMapBaseTask = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska00);
    object->taska00 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska04);
    object->taska04 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska08);
    object->taska08 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska10);
    object->taska10 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska14);
    object->taska14 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska18);
    object->taska18 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska1c);
    object->taska1c = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska20);
    object->taska20 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska24);
    object->taska24 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->taska28);
    object->taska28 = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->redChestTask);
    object->redChestTask = -1;
    BackgroundLoader::GetInstance()->RemoveTask(object->shipPositionsTask);
    object->shipPositionsTask = -1;

    if (object->currentMode == 2) {
        BackgroundLoader::GetInstance()->RemoveTask(object->unknown_a0c_);
        object->unknown_a0c_ = -1;
    }
}
