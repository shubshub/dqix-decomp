#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
extern struct Elem2081* FindElementByByte0xc4_02081da8(struct Obj2081*, int);
extern int WindowPane_IsOpen(unsigned char*);
extern void GetLookAndTurnOffsets020809c4(void*, int, int, short*, short*);

struct Struct_0205a254;
struct Struct_0205a330;

struct Struct_ov014_02186e2c {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    char unknown_8_[0x15 - 0x8];
    unsigned char unknown_15_;
};

extern struct Elem02186e2c* SpriteEntryList_Find(struct Container0205a3d0*, int);
extern void SpriteEntryList_PlayAnimation(struct Container0205a3d0*, int);
extern void SpriteEntryList_AdvanceAnimations(struct Container0205a330*, int);
extern "C" void SpriteContext_DrawEntries(void*);

struct Struct_ov014_02186e2c_2 {
    char unknown_0_[0xc0];
    void* unknown_c0_;
    char unknown_c4_[0xd0 - 0xc4];
    short* unknown_d0_;
    char unknown_d4_[0xd8 - 0xd4];
    struct Struct_0205a254* unknown_d8_;
    char unknown_dc_[0xf8 - 0xdc];
    char unknown_f8_[0x164 - 0xf8];
    int unknown_164_;
    char unknown_168_[0x170 - 0x168];
    short unknown_170_;
};

// USA: func_ov014_02186e2c
extern "C" ARM void func_ov014_02186e2c(struct Struct_ov014_02186e2c_2* arg0) {
    struct Struct_0207fdcc* var0;
    struct Struct_ov014_02186e2c* var1;
    short var2, var3;
    short var4, var5;

    if (self->field0xd0 == NULL) return;
    if (self->field0x170 < 0) return;
    elem = FindElementByByte0xc4_02081da8((struct Obj2081*)self->field0xc0, self->field0x170);
    if (elem == NULL) return;
    if (WindowPane_IsOpen((unsigned char*)elem) == 0) return;

    func_020809c4(arg0->unknown_c0_, arg0->unknown_170_, *arg0->unknown_d0_, &var2, &var3);
    var2 -= 0x10;
    var3 -= 3;

    SpriteEntryList_PlayAnimation(self->field0xd8, 0);
    e = SpriteEntryList_Find(self->field0xd8, 0);
    if (e != NULL) {
        e->flags15 |= 8;
    }
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)self->field0xd8, self->field0x164);
    unk6val = outA;
    unk4val = outB;
    e = SpriteEntryList_Find(self->field0xd8, 0);
    if (e != NULL) {
        e->unk4 = unk4val;
        e->unk6 = unk6val;
    }
    SpriteContext_DrawEntries(&self->field0xf8);
}
