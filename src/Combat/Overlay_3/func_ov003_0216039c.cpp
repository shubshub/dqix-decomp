#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0216039c_804 = 0x20c };
enum { Enum_ov003_0216039c_820 = 0x21c };
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
enum { Enum_ov003_0216039c_820 = 0x334 };
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
struct Struct_0205a254;
struct Struct_0205a330;
struct Struct_0205a254_2 {
    char unknown_0_[0x15];
    unsigned char unknown_15_;
};

unsigned char* FindElementByByte0xc4_02081da8(Obj2081* obj, int key);
int GetInnerFlagBit0020e28dc(Outer020e28dc* o);
void SpriteEntryList_SetFirstObject(Container0205a3d0* c, int key, int val);
extern "C" void SpriteContext_DrawEntries(void* obj);
int WindowPane_IsOpen(unsigned char* obj);
void GetLookAndTurnOffsets020809c4(void* obj, int id, int id2, short* out1, short* out2);
void SpriteEntryList_PlayAnimation(Container0205a3d0* c, int key);
Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0* c, int key);
void SpriteEntryList_AdvanceAnimations(Container0205a330* c, int arg);
void SpriteEntryList_SetPosition(Container0205a3d0* c, int key, short a, short b);

struct Struct_ov003_0216039c {
    char unknown_0_[Enum_ov003_0216039c_804];
    Struct_0207fdcc_2* unknown_324_;
    char unknown_328_[Enum_ov003_0216039c_820 - Enum_ov003_0216039c_808];
    char unknown_334_[Enum_ov003_0216039c_908 - Enum_ov003_0216039c_820];
    Struct_0205a254* unknown_38c_;
    Struct_020e28dc* unknown_390_;
    char unknown_394_[Enum_ov003_0216039c_1120 - Enum_ov003_0216039c_916];
    int unknown_460_;
    char unknown_464_[Enum_ov003_0216039c_1136 - Enum_ov003_0216039c_1124];
    short* unknown_470_;
    char unknown_474_[Enum_ov003_0216039c_1160 - Enum_ov003_0216039c_1140];
    short unknown_488_;
};

// USA: func_ov003_0216039c
extern "C" ARM void func_ov003_0216039c(Struct_ov003_0216039c* arg0) {
    if (arg0->unknown_470_ == NULL || arg0->unknown_488_ < 0 || arg0->unknown_324_ == NULL) {
        return;
    }
    unsigned char* var0 = func_02081da8(arg0->unknown_324_, arg0->unknown_488_);
    if (var0 == NULL) {
        return;
    }
    if (self->p390 != NULL && GetInnerFlagBit0020e28dc(self->p390) != 0) {
        SpriteEntryList_SetFirstObject(self->p38c, 0, 0);
        SpriteContext_DrawEntries(self->x334);
        return;
    }
    if (WindowPane_IsOpen(elem) == 0) {
        return;
    }
    short x;
    short y;
    GetLookAndTurnOffsets020809c4(self->p324, self->h488, *self->p470, &x, &y);
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
