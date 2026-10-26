#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_021735c4_198 = 0xc4 };
enum { Enum_ov003_021735c4_200 = 0xc6 };
enum { Enum_ov003_021735c4_216 = 0xd4 };
#else
enum { Enum_ov003_021735c4_198 = 0xc6 };
enum { Enum_ov003_021735c4_200 = 0xc8 };
enum { Enum_ov003_021735c4_216 = 0xd8 };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct PacRecord;

extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void func_020a620c(void* obj);
extern "C" int func_020a64a8(unsigned char* obj);
extern "C" int Pac_CountFiles(struct PacRecord* entry);
extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* outSize);

extern char data_ov003_02180a76[];

struct Struct_ov003_021735c4 {
    char pad0[Enum_ov003_021735c4_198];
    short scrollY;
    char unknown_c8_[Enum_ov003_021735c4_216 - Enum_ov003_021735c4_200];
    unsigned char fade[0x15];
    unsigned char mode;
    char unknown_ee_;
    unsigned char state;
    #if defined(jpn)
    char unknown_ec_[12];
#else
    char unknown_f0_[4];
#endif
    int handle;
};

// USA: func_ov003_021735c4
extern "C" ARM void func_ov003_021735c4(struct Struct_ov003_021735c4* self) {
    GameResources* res = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_020a620c(self->fade);

    if (self->state == 0) {
        self->handle = loader->QueueLoadFile(data_ov003_02180a76, 0);
        self->state = 1;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            void* recData;
            void* file;
            unsigned int length;
            unsigned char* recs[3];
            int sizes[3];
            loader->GetLoadedFileByID(self->handle, &file, &length);
            int count = Pac_CountFiles((struct PacRecord*)file);
            for (int i = 0; i < count; i++) {
                recs[i] = (unsigned char*)Pac_GetFile((struct PacRecord*)file, i, &recData, &sizes[i]);
            }
            memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
            unsigned char* palette = recs[2];
            CleanInvalidateCacheRange(palette + 0x4c, 0x40);
            LoadToSubBGStandardPalette(palette + 0x4c, 0x40, 0x40);
            self->scrollY = -0xc0;
            *(volatile unsigned int*)0x4001010 = (self->scrollY << 16) & 0x1ff0000;
            loader->RemoveTask(self->handle);
            self->handle = -1;
            if (func_020a64a8(self->fade) == 0) {
                self->state = 2;
            } else {
                SetSubBrightness(res, 0, 0x18);
                self->state = 3;
            }
        }
    } else if (self->state == 2) {
        if (func_020a64a8(self->fade) != 0) {
            SetSubBrightness(res, 0, 0x18);
            self->state = 3;
        }
    } else if (self->state == 3) {
        if (IsSubBrightnessTransitionActive(res) == 0) {
            self->mode = 2;
            self->state = 0;
        }
    }
}
