#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_02156f04_2196 = 0x714, Enum_ov006_02156f04_4795 = 0x10b7 };
#else
enum { Enum_ov006_02156f04_2196 = 0x894, Enum_ov006_02156f04_4795 = 0x12bb };
#endif

#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"

struct StructDE234_020de234 {
    void* model_;
    int unk_4;
    int unk_8;
    int unk_c;
    unsigned int unknown_10_0_ : 20;
    unsigned int letter_ : 8;
    unsigned int unk_10_28 : 4;
    int unk_14;
    short unknown_18_;
    char unk_1a[0x20 - 0x1a];
};

extern "C" unsigned short ItemRecord_GetFileNumber(StructDE234_020de234* p, int preferMid);

extern const char data_ov006_021601e5[];

struct Struct_ov006_02156f04 {
    StructDE234_020de234 entry_;
    char model_[0x20];
    char unk_40[0x30];
    short item_;
};

struct Struct_ov006_02156e54 {
    char graphics_[0x70];
    int task_;
    short item_;
    short x_;
    short y_;
    unsigned char loading_;
};

struct Struct_ov006_02154614 {
    char unk_0[Enum_ov006_02156f04_2196];
    Struct_ov006_02156e54 ingredients_[4];
    char unknown_a84_[Enum_ov006_02156f04_4795 - Enum_ov006_02156f04_2196 - 4 * sizeof(Struct_ov006_02156e54)];
    unsigned char unknown_12bb_;
};

extern "C" void func_ov006_02156e54(Struct_ov006_02154614* self);

// USA: func_ov006_02156f04
extern "C" ARM void func_ov006_02156f04(Struct_ov006_02154614* self, Struct_ov006_02156f04* ingredients) {
    func_ov006_02156e54(self);
    Struct_ov006_02156e54* ingredient = self->ingredients_;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    self->unknown_12bb_ = 0;
    for (unsigned char i = 0; i < 4; i++) {
        short item = ingredients->item_;
        ingredient->item_ = item;
        if (item > 0) {
            ingredient->loading_ = 1;
            int number = ItemRecord_GetFileNumber(&ingredients->entry_, 0);
            char path[0x40] = {0};
            sprintf(path, data_ov006_021601e5, ingredients->entry_.letter_, number);
            ingredient->task_ = loader->QueueLoadFile(path, 0);
            if (i != 0)
                self->unknown_12bb_++;
        }
        ingredients++;
        ingredient++;
    }
}
