#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include "Filesystem/BackgroundLoader.h"

extern "C" void* OamManager_GetInstance();
extern "C" unsigned int OamManager_GetMainOamBuffer(void* vram);

struct Struct_ov006_02156e54_2 {
    char unk_0[0x14];
    unsigned int unk_14;
    char unknown_18_[0x38 - 0x18];
    unsigned int unknown_38_;
    unsigned int unk_3c;
    int unk_40;
    int unknown_44_;
    char unknown_48_[4];
    int unknown_4c_;
    char unk_50[0x5e - 0x50];
    unsigned char unknown_5e_;
    char unknown_5f_[0x70 - 0x5f];
};

struct Struct_ov006_02156e54 {
    Struct_ov006_02156e54_2 graphics_;
    int task_;
    short item_;
    short x_;
    short y_;
    unsigned char loading_;
};

extern "C" void func_ov006_0215479c(Struct_ov006_02156e54* self);

struct Struct_ov006_02154614 {
    char unk_0[LOW_REGION(0x714, 0x894)];
    Struct_ov006_02156e54 ingredients_[4];
};

// USA: func_ov006_02156e54
extern "C" ARM void func_ov006_02156e54(Struct_ov006_02154614* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Struct_ov006_02156e54* ingredient = self->ingredients_;
    for (unsigned char i = 0; i < 4; i++) {
        if (ingredient->task_ > 0)
            loader->RemoveTask(ingredient->task_);
        ingredient->task_ = -1;
        func_ov006_0215479c(ingredient);
        ingredient->graphics_.unknown_5e_ = 0;
        ingredient->graphics_.unk_14 = OamManager_GetMainOamBuffer(OamManager_GetInstance()) + (i << 6) + 0x100;
        ingredient->graphics_.unknown_38_ = i * 0x120 + 0x240;
        ingredient->graphics_.unk_3c = (i + LOW_REGION(8, 10)) & 0xf;
        ingredient->graphics_.unk_40 = 0;
        ingredient->x_ = (i << 5) + 0x20;
        ingredient->y_ = 0x80;
        ingredient++;
    }
}
