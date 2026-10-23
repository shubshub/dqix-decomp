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

struct Struct_02020cb8_4;
struct Struct_02020aec;

extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void func_020a620c(void* obj);
int IsFieldSet_020a64a8(unsigned char* obj);
int Pac_CountFiles(struct ActiveEntry02046900* entry);
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* outSize);

extern char data_ov003_02180a76[];

struct Struct_ov003_021735c4 {
    char unknown_0_[Enum_ov003_021735c4_198];
    short unknown_c6_;
    char unknown_c8_[Enum_ov003_021735c4_216 - Enum_ov003_021735c4_200];
    unsigned char unknown_d8_[0x15];
    unsigned char unknown_ed_;
    char unknown_ee_;
    unsigned char unknown_ef_;
    #if defined(jpn)
    char unknown_ec_[12];
#else
    char unknown_f0_[4];
#endif
    int unknown_f4_;
};

// USA: func_ov003_021735c4
extern "C" ARM void func_ov003_021735c4(struct Struct_ov003_021735c4* arg0) {
    GameResources* var0 = GetGameResources();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    func_020a620c(arg0->unknown_d8_);

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
            int count = Pac_CountFiles((struct ActiveEntry02046900*)file);
            for (int i = 0; i < count; i++) {
                recs[i] = (unsigned char*)Pac_GetFile((struct Rec020467f0*)file, i, &recData, &sizes[i]);
            }
            memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
            unsigned char* var9 = var5[2];
            CleanInvalidateCacheRange(var9 + 0x4c, 0x40);
            LoadToSubBGStandardPalette(var9 + 0x4c, 0x40, 0x40);
            arg0->unknown_c6_ = -0xc0;
            *(volatile unsigned int*)0x4001010 = (arg0->unknown_c6_ << 16) & 0x1ff0000;
            var1->RemoveTask(arg0->unknown_f4_);
            arg0->unknown_f4_ = -1;
            if (func_020a64a8(arg0->unknown_d8_) == 0) {
                arg0->unknown_ef_ = 2;
            } else {
                SetSubBrightness(var0, 0, 0x18);
                arg0->unknown_ef_ = 3;
            }
        }
    } else if (arg0->unknown_ef_ == 2) {
        if (func_020a64a8(arg0->unknown_d8_) != 0) {
            SetSubBrightness(var0, 0, 0x18);
            arg0->unknown_ef_ = 3;
        }
    } else if (arg0->unknown_ef_ == 3) {
        if (IsSubBrightnessTransitionActive(var0) == 0) {
            arg0->unknown_ed_ = 2;
            arg0->unknown_ef_ = 0;
        }
    }
}
