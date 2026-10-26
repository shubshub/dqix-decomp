#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021e07b0 {
    int unknown_0_;
    unsigned int id : 12;
    unsigned int pad4 : 20;
    char pad8[0x1c];
    unsigned int unknown_24_0_ : 10;
    unsigned int unknown_25_2_ : 10;
    unsigned int messageId : 10;
    unsigned int unknown_27_6_ : 2;
};

struct Struct_ov024_021e07b0_2 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e07b0_3 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021e07b0_3* obj, int slot, int id, struct Struct_ov024_021e07b0* move, int flag);
extern "C" void* func_ov000_0215e958(void* a0);
struct Struct_ov024_021e04e0;
extern "C" int func_ov024_021e05e4(struct Struct_ov024_021e04e0* obj);
extern "C" void func_020488cc(unsigned char* obj, int value);
extern "C" void func_02088e64(unsigned char* obj);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);
extern "C" void func_ov000_0215a8d4(unsigned char* obj, int amount);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

// USA: func_ov024_021e07b0
extern "C" ARM void* func_ov024_021e07b0(struct Struct_ov024_021e07b0_3* obj, unsigned char slot, int id, struct Struct_ov024_021e07b0* move) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    unsigned long long result = func_ov024_021e4b14(obj, slot, id, move, 1);
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    int added = 0;
    if (func_ov024_021e05e4((struct Struct_ov024_021e04e0*)c)) {
        int isParty = (id >= 0 && id <= 3);
        if (!isParty) {
            func_020488cc((unsigned char*)c, 1);
        }
        func_02088e64((unsigned char*)c->currentStats_);
        func_ov000_0215a88c(obj->unknown_10_, entry, 0x164);
        added = 1;
        if (func_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()), slot) && move->id == 0xc6) {
            func_ov000_0215a8d4((unsigned char*)obj->unknown_10_, added);
        }
    }
    if (result != 0) {
        if (!added) {
            func_ov000_0215a88c(obj->unknown_10_, entry, 0);
        }
        added = 1;
    }
    if (!added) {
        func_ov000_0215a88c(obj->unknown_10_, entry, (unsigned short)move->messageId);
    }
    struct Struct_ov024_021e07b0_2* var5 = (struct Struct_ov024_021e07b0_2*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, result, var5->flag != 0);
    return entry;
}
