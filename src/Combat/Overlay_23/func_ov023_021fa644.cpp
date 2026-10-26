#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021845f8(void*, int);
extern "C" void* func_ov011_0218466c(void* obj, unsigned short id);

struct Struct_020e03b8;
extern "C" int func_020e03b8(int unused, struct Struct_020e03b8* obj, int val);
extern "C" void* KeyTable_Construct(void* p);
struct Struct020dfc40;
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void KeyTable_Load(void*, void*, void*, unsigned int);
struct Struct_020e03f0;
struct Struct_02072aa8;
extern "C" int func_020e03f0(struct Struct_020e03f0* self, struct Struct_02072aa8* obj);

struct Struct_ov023_021fa644 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_020727d8;
extern "C" void func_020727d8(struct Struct_020727d8* list);

struct StreamHeader;
extern "C" void func_020728ac(int, int, struct StreamHeader*, int, int, unsigned short, unsigned char);

struct Struct_ov023_021fa644_2 {
    char pad0[8];
    unsigned short field8;
    unsigned short fieldA;
#if defined(jpn)
    char unknown_c_[0x28 - 0xc];
#else
    char unknown1_c_[0x2c - 0xc];
#endif

    unsigned char field2c;
};

// USA: func_ov023_021fa644
extern "C" ARM void func_ov023_021fa644(Struct_ov023_021fa644_2* obj, void* ctx, Struct_020e03b8* p2, int p3) {
#if defined(jpn)
 enum {regionalOffset0=0x144};
#else
 enum {regionalOffset0=0x150};
#endif
    if (p2 == 0 || p3 == 0) {
        return;
    }
    void* allocBase = func_ov011_021845f8(ctx, obj->field8);
    void* node = func_ov011_0218466c(ctx, obj->fieldA);
    if (allocBase == 0 || node == 0) {
        return;
    }

    char local[0x18];
    KeyTable_Construct(local);
    if (func_020e03b8((int)local, p2, p3)) {
        KeyTable_Reset((Struct020dfc40*)local);
        KeyTable_Load(local, (char*)allocBase + 4, p2, (unsigned int)p3);
        func_020e03f0((Struct_020e03f0*)local, (Struct_02072aa8*)((char*)obj + 0x20));
        return;
    }

    unsigned char kind = obj->field2c;
    int flag5 = 0;
    if (kind == 1) {
        GameState* bs = GameState::GetInstance();
        int val = GameState_GetProtagonistIndex(bs);
        GameObject* combatant = bs->GetPartyMemberByIndex(val);
        if (combatant != 0) {
            Struct_ov023_021fa644* sub = *(Struct_ov023_021fa644**)((char*)combatant + regionalOffset0);
            flag5 = sub->bit0;
        }
    } else if (kind == 2) {
    } else if (kind == 3) {
        flag5 = 1;
    }

    func_020727d8((Struct_020727d8*)((char*)obj + 0x20));
    func_020728ac((int)((char*)obj + 0x20), (int)((char*)allocBase + 4), (StreamHeader*)p2, p3, 0, 0, flag5);
}
