#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0216039c_804 = 0x20c };
enum { kRegionValue334_21C = 0x21c };
enum { Enum_ov003_0216039c_808 = 0x210 };
enum { Enum_ov003_0216039c_908 = 0x274 };
enum { Enum_ov003_0216039c_1120 = 0x288 };
enum { Enum_ov003_0216039c_916 = 0x27c };
enum { Enum_ov003_0216039c_1136 = 0x298 };
enum { Enum_ov003_0216039c_1124 = 0x28c };
enum { Enum_ov003_0216039c_1160 = 0x2b0 };
enum { Enum_ov003_0216039c_1140 = 0x29c };
#else
enum { Enum_ov003_0216039c_804 = 0x324 };
enum { kRegionValue334_21C = 0x334 };
enum { Enum_ov003_0216039c_808 = 0x328 };
enum { Enum_ov003_0216039c_908 = 0x38c };
enum { Enum_ov003_0216039c_1120 = 0x460 };
enum { Enum_ov003_0216039c_916 = 0x394 };
enum { Enum_ov003_0216039c_1136 = 0x470 };
enum { Enum_ov003_0216039c_1124 = 0x464 };
enum { Enum_ov003_0216039c_1160 = 0x488 };
enum { Enum_ov003_0216039c_1140 = 0x474 };
#endif

struct Struct_0207fdcc_2;
struct Struct_020e28dc;
struct Container0205a3d0;
struct Container0205a330;
struct Elem0205a3d0 {
    char pad0[0x15];
    unsigned char flags;
};

extern "C" unsigned char* func_02081da8(Struct_0207fdcc_2* obj, int key);
extern "C" int func_020e28dc(Struct_020e28dc* o);
extern "C" void SpriteEntryList_SetFirstObject(Container0205a3d0* c, int key, int val);
extern "C" void SpriteContext_DrawEntries(void* obj);
extern "C" int WindowPane_IsOpen(unsigned char* obj);
extern "C" void func_020809c4(void* obj, int id, int id2, short* out1, short* out2);
extern "C" void SpriteEntryList_PlayAnimation(Container0205a3d0* c, int key);
extern "C" Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0* c, int key);
extern "C" void SpriteEntryList_AdvanceAnimations(Container0205a330* c, int arg);
extern "C" void SpriteEntryList_SetPosition(Container0205a3d0* c, int key, short a, short b);

struct Struct_ov003_0216039c {
    char pad0[Enum_ov003_0216039c_804];
    Struct_0207fdcc_2* unknown_324_;
    char unknown_328_[kRegionValue334_21C - Enum_ov003_0216039c_808];
    char x334[Enum_ov003_0216039c_908 - kRegionValue334_21C];
    Container0205a3d0* p38c;
    Struct_020e28dc* unknown_390_;
    char unknown_394_[Enum_ov003_0216039c_1120 - Enum_ov003_0216039c_916];
    int field_460;
    char unknown_464_[Enum_ov003_0216039c_1136 - Enum_ov003_0216039c_1124];
    short* unknown_470_;
    char unknown_474_[Enum_ov003_0216039c_1160 - Enum_ov003_0216039c_1140];
    short unknown_488_;
};

// USA: func_ov003_0216039c
extern "C" ARM void func_ov003_0216039c(Struct_ov003_0216039c* self) {
    if (self->unknown_470_ == NULL || self->unknown_488_ < 0 || self->unknown_324_ == NULL) {
        return;
    }
    unsigned char* elem = func_02081da8(self->unknown_324_, self->unknown_488_);
    if (elem == NULL) {
        return;
    }
    if (self->unknown_390_ != NULL && func_020e28dc(self->unknown_390_) != 0) {
        SpriteEntryList_SetFirstObject(self->p38c, 0, 0);
        SpriteContext_DrawEntries(self->x334);
        return;
    }
    if (WindowPane_IsOpen(elem) == 0) {
        return;
    }
    short x;
    short y;
    func_020809c4(self->unknown_324_, self->unknown_488_, *self->unknown_470_, &x, &y);
    x -= 0x10;
    y -= 3;
    SpriteEntryList_PlayAnimation(self->p38c, 0);
    Elem0205a3d0* e = SpriteEntryList_Find(self->p38c, 0);
    if (e != NULL) {
        e->flags |= 8;
    }
    e = SpriteEntryList_Find(self->p38c, 1);
    if (e != NULL) {
        e->flags &= ~8;
    }
    SpriteEntryList_AdvanceAnimations((Container0205a330*)self->p38c, self->field_460);
    SpriteEntryList_SetPosition(self->p38c, 0, x, y);
    SpriteContext_DrawEntries(self->x334);
}
