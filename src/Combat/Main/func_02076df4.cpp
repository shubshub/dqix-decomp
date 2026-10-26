#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02039df4 { char unknown_0_[0x6]; unsigned short unknown_6_; };

struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

extern "C" void* LinkSession_GetInstance(void);

struct CheckField0AndGlobalHalfStruct0202c508 { int field0; };
extern "C" int LinkSession_IsHostOrSolo(struct CheckField0AndGlobalHalfStruct0202c508* obj);

struct Struct_02076df4;
extern "C" unsigned short func_02079040(struct Struct_02076df4* arg0, unsigned char* arg1);

extern "C" unsigned short func_02078e60(void* arg0, char* arg1);

extern "C" int func_02076ccc(void*, int);

struct Struct_02076df4_2 {
    char unknown_0_[0x134];
    int unknown_134_;
    unsigned char unknown_138_;
    char unknown_139_[0x13];
    unsigned int unknown_14c_;
    char unknown_150_[0x14];
    unsigned short unknown_164_;
    unsigned short unknown_166_;
    char unknown_168_[0x13];
    unsigned char unknown_17b_;
    unsigned char unknown_17c_;
    unsigned char unknown_17d_;
};

// USA: func_02076df4
extern "C" ARM void func_02076df4(struct Actor02076df4* obj) {
    GameState* battleStruct = GameState::GetInstance();
    void* g = LinkSession_GetInstance();
    struct Entry_02028bd0* table = ZoneRecords_GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(obj->field166);
    int key = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
    struct Entry_02028bd0* entry = ZoneRecords_Find(table, key);
    if (entry == 0) {
        return;
    }
    if (LinkSession_IsHostOrSolo((struct CheckField0AndGlobalHalfStruct0202c508*)g) == 0) {
        return;
    }
    if (arg0->unknown_17c_ != 0) {
        return;
    }
    int var6 = 1;
    if (var3 != 0 && arg0->unknown_17b_ != 0) {
        if (*((unsigned char*)var3 + 0xbe) == 0) {
            int var7 = ((Object3D*)((struct Struct_02039df4*)var3))->GetField06();
            int var8 = ((Object3D*)((struct Struct_02039df4*)arg0))->GetField06();
            if (var7 == var8) {
                var6 = 0;
            }
        }
    }
    if (arg0->unknown_14c_ <= 0xfa0) {
        return;
    }
    if (var6 == 0) {
        return;
    }
    unsigned short var9 = arg0->unknown_164_;
    unsigned char var10 = 0;
    int var11 = 0;
    if ((arg0->unknown_17d_ & 0x40) == 0) {
        var11 = 1;
    }
    arg0->unknown_17b_ = 0;
    switch (arg0->unknown_138_) {
    case 1:
    case 3:
    case 4:
    case 5:
        if (arg0->unknown_134_ == 4 || arg0->unknown_134_ == 5 || arg0->unknown_134_ == 6) {
            arg0->unknown_164_ = func_02079040((struct Struct_02076df4*)arg0, &var10);
        } else {
            arg0->unknown_164_ = func_02078e60((void*)arg0, (char*)&var10);
        }
        if (var11 == 0 && var10 == 0) {
            func_02076ccc(arg0, 2);
            return;
        }
        if ((var9 == arg0->unknown_164_ && var11 == 0) || var10 != 0) {
            func_02076ccc(arg0, 1);
        } else {
            func_02076ccc(arg0, 2);
        }
        return;
    case 2:
        arg0->unknown_17d_ |= 0x40;
        arg0->unknown_164_ = func_02078e60((void*)arg0, (char*)&var10);
        if (var9 == arg0->unknown_164_ && var11 == 0) {
            func_02076ccc(arg0, 1);
        } else {
            func_02076ccc(arg0, 3);
        }
        return;
    }
}
