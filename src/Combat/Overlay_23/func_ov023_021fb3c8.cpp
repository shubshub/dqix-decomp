#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_0205a254;
struct Struct_ov023_021fb3c8_2 {
    char unknown_0_[0x15];
    unsigned char unknown_15_;
};
void SpriteEntryList_PlayAnimation(struct Container0205a3d0*, int);
void SpriteEntryList_SetFirstObject(struct Container0205a3d0*, int, int);
struct Elem0205a3d0_021fb3c8* SpriteEntryList_Find(struct Container0205a3d0*, int);

extern "C" void* func_ov011_021849c8(void* arg0);
extern "C" void* func_ov023_021f6880(void* arg0, int arg1);
extern "C" void* func_ov023_021fad18(void* arg0);
extern "C" void func_0205a254(struct Struct_0205a254*, unsigned char, unsigned int);
extern "C" void func_0205addc(void*, unsigned char);

struct Struct_ov023_021fb3c8 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    char unknown_d_[0x20 - 0xd];
    unsigned short unknown_20_;
    unsigned short unknown_22_;
    unsigned short unknown_24_;
    char unknown_26_[0x28 - 0x26];
    short unknown_28_;
    short unknown_2a_;
};

// USA: func_ov023_021fb3c8
extern "C" ARM void func_ov023_021fb3c8(struct Struct_ov023_021fb3c8* arg0, void* arg1) {
    if (arg0->unknown_c_ & 8) {
        return;
    }
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_ov011_021849c8(arg1);
    void* var2 = func_ov023_021f6880(var1, arg0->unknown_20_);
    void* var3 = func_ov023_021fad18(var2);
    struct Struct_0205a254* var4 = *(struct Struct_0205a254**)((char*)var3 + 0x3c);
    if (var4 == NULL) {
        return;
    }
    SpriteEntryList_PlayAnimation(container, obj->field22);
    struct Elem0205a3d0_021fb3c8* entry = SpriteEntryList_Find(container, obj->field22);
    if (entry != NULL) {
        entry->flags15 |= 8;
    }
    SpriteEntryList_SetFirstObject(container, obj->field22, (unsigned char)obj->field24);
    unsigned int scaleCount = battleStruct->GetTickCount();
    func_0205a254(container, (unsigned char)obj->field22, scaleCount);
    short f28, f2a;
    f2a = obj->field2a;
    f28 = obj->field28;
    struct Elem0205a3d0_021fb3c8* entry2 = SpriteEntryList_Find(container, obj->field22);
    if (entry2 != NULL) {
        *(short*)((char*)entry2 + 0x4) = f28;
        *(short*)((char*)entry2 + 0x6) = f2a;
    }
    func_0205addc(var3, (unsigned char)arg0->unknown_22_);
}
