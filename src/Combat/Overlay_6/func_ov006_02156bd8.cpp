#include <globaldefs.h>
#include "Graphics/Background.h"

#if defined(jpn)
enum { Enum_ov006_02156bd8_1908 = 0x6f0 };
#else
enum { Enum_ov006_02156bd8_1908 = 0x774 };
#endif

#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_020dbd9c {
    char unknown_0_[0x10];
    int unknown_10_;
    unsigned char unknown_14_;
};

struct Struct_ov006_02154614_2 {
    char unknown_0_[Enum_ov006_02156bd8_1908];
    unsigned short unknown_774_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unknown_0_[0x7c];
};

struct Struct_ov006_021537d0 {
    short unknown_0_;
};

struct Struct_ov006_021555b0 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char unknown_0_[3][0x80];
#endif
    SafeAllocator* unknown_180_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* unknown_1a0_;
    void* unknown_1a4_;
    unsigned char* unknown_1a8_;
    void* unknown_1ac_;
    void* unknown_1b0_;
    Struct_ov006_021537d0* unknown_1b4_;
    Struct_ov006_021537d0* unknown_1b8_;
    int unknown_1bc_;
    Struct_ov006_021555b0* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* unknown_1c8_;
    void* unknown_1cc_;
    void* unknown_1d0_;
    void* unknown_1d4_;
    void* unknown_1d8_;
    void* unknown_1dc_;
    void* unknown_1e0_;
    char unknown_1e4_[0x54];
    Object3D unknown_238_;
    Object3D unknown_2e4_;
    Object3D unknown_390_;
    Object3D unknown_43c_;
    Object3D unknown_4e8_;
    char unknown_594_[0x38];
    char unknown_5cc_[0x2c8];
    Struct_ov006_02156e54 unknown_894_[4];
    SafeAllocator unknown_a84_[4];
    int unknown_ad4_;
    int unknown_ad8_;
    unsigned char unknown_adc_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short unknown_ae2_;
    Struct_ov006_02154614_2 unknown_ae4_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char unknown_1288_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short unknown_12b8_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

struct PacRecord;
struct BackgroundGraphics;


extern "C" void func_ov023_021dcd90(ItemInfoWindow* window, unsigned char inMenu);
int Pac_CountFiles(PacRecord* pac);
void Background_Init(BackgroundGraphics* background);
void Background_SetMapSize(unsigned char* background, int a);
extern "C" void Background_SetPriority(void* background, int a);
void Background_SetScroll(BackgroundGraphics* background, int a, int b);
void* Pac_GetFile(PacRecord* pac, int index, void** name, int* size);
void Background_FlushFile(void* background, char* file);
void Background_UploadFile(BackgroundGraphics* background, char* file);

extern char data_ov006_021601b6[];
extern char data_ov006_021601cc[];

// USA: func_ov006_02156bd8
extern "C" ARM void func_ov006_02156bd8(Struct_ov006_02154614* arg0) {
    if (!(arg0->unknown_ae2_ & 1))
        return;
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_adf_ == 0) {
        if (arg0->unknown_ae2_ & 8)
            arg0->unknown_ad8_ = var0->QueueLoadFile(data_ov006_021601b6, 0);
        else
            self->backgroundTask_ = loader->QueueLoadFile(data_ov006_021601cc, 0);
        func_ov023_021dcd90(&self->window_, 0);
        self->backgroundStep_++;
    } else if (self->backgroundStep_ == 1) {
        if (loader->GetTaskStatus(self->backgroundTask_)) {
            void* name;
            void* pac;
            unsigned int pacSize;
            loader->GetLoadedFileByID(self->backgroundTask_, &pac, &pacSize);
            int count = Pac_CountFiles((PacRecord*)pac);
            BackgroundGraphics background;
            Background_Init((BackgroundGraphics*)&background);
            Background_SetMapSize((unsigned char*)&background, 0);
            background.subScreen_ = 0;
            background.bgNumber_ = 3;
            Background_SetPriority(&background, 3);
            Background_SetScroll((BackgroundGraphics*)&background, 0, 0);
            for (int i = 0; i < count; i++) {
                int size;
                void* file = Pac_GetFile((PacRecord*)pac, i, &name, &size);
                if (file != 0) {
                    Background_FlushFile(&background, (char*)file);
                    Background_UploadFile((BackgroundGraphics*)&background, (char*)file);
                }
            }
            var0->RemoveTask(arg0->unknown_ad8_);
            arg0->unknown_ad8_ = -1;
            arg0->unknown_adf_ = 0;
            arg0->unknown_ae2_ &= ~1;
            arg0->unknown_ae2_ &= ~4;
        }
    }
}
