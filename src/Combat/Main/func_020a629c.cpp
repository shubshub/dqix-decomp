#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <NitroSDK/Cache.h>
#include <NitroSDK/LoadToVRAM.h>
#include "Resource/GameResources.h"
struct Struct_020a629c { char pad[0xa]; unsigned char unknown_a_, state; int task; };
struct Struct_020a629c_2 { char pad[0xc]; unsigned int size; char data[1]; };
struct Struct_020a629c_3 { char pad[0xc]; char data[0x200]; };
struct PacRecord;
extern char data_020f1b28;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
// USA: func_020a629c
extern "C" ARM void func_020a629c(Struct_020a629c* self) {
    GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->state == 0) {
        self->task = loader->QueueLoadFile(&data_020f1b28, 0);
        self->state = 1;
    } else if (self->state == 1 && loader->GetTaskStatus(self->task)) {
        void* record;
        void* file;
        unsigned int size;
        void* resources[3];
        int fields[3];
        loader->GetLoadedFileByID(self->task, &file, &size);
        int count = Pac_CountFiles((PacRecord*)file);
        for (int i = 0;i < count;i++) resources[i] = Pac_GetFile((PacRecord*)file, i, &record, &fields[i]);
        Struct_020a629c_2* var8 = (Struct_020a629c_2*)resources[0];
        unsigned int var9 = var8->size;
        CleanInvalidateCacheRange(var8->data, var9);
        LoadToSubBG1CharacterData(((Struct_020a629c_2*)resources[0])->data, 0, var9);
        Struct_020a629c_3* palette = (Struct_020a629c_3*)resources[1];
        CleanInvalidateCacheRange(palette->data, 0x200);
        LoadToSubBGStandardPalette(palette->data, 0, 0x40);
        LoadToSubBGStandardPalette(palette->data+0x180, 0x180, 0x80);
        unsigned int screenSize;
        Struct_020a629c_2* screen = (Struct_020a629c_2*)resources[2];
        screenSize = screen->size;
        CleanInvalidateCacheRange(screen->data, screenSize);
        LoadToSubBG1ScreenData(screen->data, 0, screenSize);
        loader->RemoveTask(self->task);
        self->task = -1;
        self->unknown_a_ = 1;
        self->state = 0;
    }
}
