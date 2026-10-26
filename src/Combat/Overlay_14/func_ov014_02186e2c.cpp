#include <globaldefs.h>

struct Struct_0207fdcc_2;
struct Struct_0207fdcc;
extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2*, int);
extern "C" int WindowPane_IsOpen(unsigned char*);
extern "C" void func_020809c4(void*, int, int, short*, short*);

struct Container0205a3d0;
struct Container0205a330;

struct Elem02186e2c {
    char unk0[4];
    unsigned short unk4;
    unsigned short unknown_6_;
    char unknown_8_[0x15 - 0x8];
    unsigned char unknown_15_;
};

extern "C" struct Elem02186e2c* SpriteEntryList_Find(struct Container0205a3d0*, int);
extern "C" void SpriteEntryList_PlayAnimation(struct Container0205a3d0*, int);
extern "C" void SpriteEntryList_AdvanceAnimations(struct Container0205a330*, int);
extern "C" void SpriteContext_DrawEntries(void*);

struct Struct_ov014_02186e2c_2 {
    char pad0[0xc0];
    void* unknown_c0_;
    char pad1[0xd0 - 0xc4];
    short* unknown_d0_;
    char pad2[0xd8 - 0xd4];
    struct Container0205a3d0* field0xd8;
    char pad3[0xf8 - 0xdc];
    char field0xf8[0x164 - 0xf8];
    int field0x164;
    char pad4[0x170 - 0x168];
    short unknown_170_;
};

// USA: func_ov014_02186e2c
extern "C" ARM void func_ov014_02186e2c(struct Struct_ov014_02186e2c_2* self) {
    struct Struct_0207fdcc* elem;
    struct Elem02186e2c* e;
    short outB, outA;
    short var4, var5;

    if (self->unknown_d0_ == NULL) return;
    if (self->unknown_170_ < 0) return;
    elem = func_02081da8((struct Struct_0207fdcc_2*)self->unknown_c0_, self->unknown_170_);
    if (elem == NULL) return;
    if (WindowPane_IsOpen((unsigned char*)elem) == 0) return;

    func_020809c4(self->unknown_c0_, self->unknown_170_, *self->unknown_d0_, &outB, &outA);
    outB -= 0x10;
    outA -= 3;

    SpriteEntryList_PlayAnimation(self->field0xd8, 0);
    e = SpriteEntryList_Find(self->field0xd8, 0);
    if (e != NULL) {
        e->unknown_15_ |= 8;
    }
    SpriteEntryList_AdvanceAnimations((struct Container0205a330*)self->field0xd8, self->field0x164);
    var5 = outA;
    var4 = outB;
    e = SpriteEntryList_Find(self->field0xd8, 0);
    if (e != NULL) {
        e->unk4 = var4;
        e->unknown_6_ = var5;
    }
    SpriteContext_DrawEntries(&self->field0xf8);
}
