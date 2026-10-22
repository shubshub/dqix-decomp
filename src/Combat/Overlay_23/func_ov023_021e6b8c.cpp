#include <globaldefs.h>
#include "NitroSDK/Cache.h"

struct Struct_020200c0_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned char unknown_8_;
};
struct Struct_ov023_021e6b8c {
    int unknown_0_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
};
struct Struct_ov023_021e6b8c_2 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
};
struct Struct_ov023_021e6b8c_3 {
    void* unknown_0_;
    Struct_ov023_021e6b8c_2* unknown_4_;
};
struct Struct_ov023_021e6b8c_4 : Struct_ov023_021e6b8c_3 {
    unsigned char unknown_8_[0x20];
};
struct Struct_ov023_021e6b8c_5 {
    short unknown_0_;
    short unknown_2_;
    const char* unknown_4_;
    const char* unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
};
struct Struct_ov023_021e6b8c_6 {
    Struct_ov023_021e6b8c_5* unknown_0_;
    unsigned char unknown_4_[0x1a];
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unknown_20_;
};
struct Struct_ov023_021e6b8c_7 {
    Struct_ov023_021e6b8c_6* unknown_0_;
    unsigned char unknown_4_[0x1364 - 4];
    Struct_ov023_021e6b8c_4* unknown_1364_;
    unsigned char unknown_1368_[8];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    unsigned char unknown_1372_[10];
    void* unknown_137c_;
};
extern "C" void func_0205b20c(Struct_020200c0_4*);
extern "C" void func_0205b220(void*, int);
extern "C" void func_0205b228(void*, int, unsigned char);
extern "C" {
void Keyboard_GetKeySize(int, short*, short*);
void func_0205b890(WeightedEntry021e6b8c*, int, SpriteEntry021e6b8c*);
void* memcpy(void*, const void*, unsigned int);
int func_020420e8(const char*, int);
void func_0205b734(void*, short, short, short, short, short);
int func_0205b234(void*, short, short, const char*, unsigned char, unsigned char);
void LoadToMainObjVRAM(const void*, unsigned int, unsigned int);
}

// USA: func_ov023_021e6b8c
extern "C" ARM void func_ov023_021e6b8c(LabelState021e6b8c* self, unsigned short address, Label021e6b8c* label, int size) {
    if (self->mode != 14 || self->index <= 1 || self->index >= 10) return;
    label = self->owner->selected;
    if (label == 0 || label->index == 3) return;
    SpriteEntry021e6b8c* sprite = &self->sprites[label->index + 15];
    short x;
    short y;
    Keyboard_GetKeySize(label->index, &x, &y);
    WeightedEntry021e6b8c entries[3];
    for (int i = 0; i < 3; i++) {
        entries[i].field_0 = 0;
        entries[i].offset = 0;
        entries[i].field_6 = 0;
        entries[i].width = 0;
        entries[i].height = 0;
    }
    func_0205b890(var3, 3, var0);
    int var5 = 0;
    arg3 = 0;
    for (int var6 = 0; var6 < 3; var6++) {
        var3[var6].unknown_4_ = var5;
        var5 += var3[var6].unknown_8_;
        arg3 += (var3[var6].unknown_8_ * var3[var6].unknown_a_) >> 1;
    }
    Struct_ov023_021e6b8c_3 var7 = *var0;
    arg1 = (unsigned short)(var7.unknown_4_->unknown_4_ & 0x3ff) << 5;
    memcpy(arg0->unknown_137c_, (const void*)(0x6400000 + arg1), arg3);
    unsigned char var8 = arg0->unknown_0_->unknown_1e_;
    unsigned char var9 = arg0->unknown_0_->unknown_20_;
    const char* var10 = arg2->unknown_4_;
    if (arg2->unknown_d_ == 0 && (var9 != 0 || (var8 & 2) != 0)) var10 = arg2->unknown_8_;
    int var11 = (var1 - func_020420e8(var10, 1)) >> 1;
    Struct_020200c0_4 var12;
    func_0205b20c(&var12);
    func_0205b220(&var12, (int)arg0->unknown_137c_);
    func_0205b228(&var12, (int)var3, 3);
    func_0205b734(&var12, 9, 9, (short)(var1 + 7), (short)(var2 + 7), 9);
    func_0205b234(&var12, (short)(var11 + 8), 10, var10, 2, 1);
    CleanInvalidateCacheRange(arg0->unknown_137c_, arg3);
    LoadToMainObjVRAM(arg0->unknown_137c_, arg1, arg3);
    CleanCacheRange(arg0->unknown_137c_, arg3);
}
