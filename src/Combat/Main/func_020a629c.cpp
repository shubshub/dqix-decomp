#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <NitroSDK/Cache.h>
#include <NitroSDK/LoadToVRAM.h>
#include "Resource/GameResources.h"
struct Obj020a629c { char pad[0xa]; unsigned char ready, state; int task; };
struct Resource020a629c { char pad[0xc]; unsigned int size; char data[1]; };
struct Palette020a629c { char pad[0xc]; char data[0x200]; };
struct PacRecord;
extern char data_020f1b28;
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
// USA: func_020a629c
extern "C" ARM void func_020a629c(Struct_020a629c* arg0) {
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
        Resource020a629c* chars = (Resource020a629c*)resources[0];
        unsigned int charsSize = chars->size;
        CleanInvalidateCacheRange(chars->data, charsSize);
        LoadToSubBG1CharacterData(((Resource020a629c*)resources[0])->data, 0, charsSize);
        Palette020a629c* palette = (Palette020a629c*)resources[1];
        CleanInvalidateCacheRange(palette->data, 0x200);
        LoadToSubBGStandardPalette(palette->data, 0, 0x40);
        LoadToSubBGStandardPalette(palette->data+0x180, 0x180, 0x80);
        unsigned int screenSize;
        Resource020a629c* screen = (Resource020a629c*)resources[2];
        screenSize = screen->size;
        CleanInvalidateCacheRange(screen->data, screenSize);
        LoadToSubBG1ScreenData(screen->data, 0, screenSize);
        loader->RemoveTask(self->task);
        self->task = -1;
        self->ready = 1;
        self->state = 0;
    }
}
