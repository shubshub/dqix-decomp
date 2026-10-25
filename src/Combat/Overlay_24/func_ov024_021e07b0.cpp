#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021e07b0 {
    int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    char unknown_8_[0x1c];
    unsigned int unknown_24_0_ : 10;
    unsigned int unknown_25_2_ : 10;
    unsigned int unknown_26_4_ : 10;
    unsigned int unknown_27_6_ : 2;
};

struct Struct_ov024_021e07b0_2 { unsigned char unknown_0_0_ : 7; unsigned char unknown_0_7_ : 1; };
struct Struct_ov024_021e07b0_3 { char unknown_0_[0xc]; void* unknown_c_; void* unknown_10_; };

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021e07b0_3* arg0, int arg1, int arg2, struct Struct_ov024_021e07b0* arg3, int arg4);
extern "C" void* func_ov000_0215e958(void* arg0);
struct Struct_ov024_021e04e0;
extern "C" int func_ov024_021e05e4(struct Struct_ov024_021e04e0* arg0);
extern "C" void func_020488cc(unsigned char* arg0, int arg1);
extern "C" void func_02088e64(unsigned char* arg0);
extern "C" void func_ov000_0215a88c(void* arg0, void* arg1, int arg2);
struct Struct_02048150;
extern "C" int func_02086ef0(struct Struct_02048150* arg0, int arg1);
extern "C" void func_ov000_0215a8d4(unsigned char* arg0, int arg1);
extern "C" void func_ov000_0215cd44(void* arg0, void* arg1, void* arg2, int arg3, unsigned long long arg4, int arg5);

// USA: func_ov024_021e07b0
extern "C" ARM void* func_ov024_021e07b0(struct Struct_ov024_021e07b0_3* arg0, unsigned char arg1, int arg2, struct Struct_ov024_021e07b0* arg3) {
    GameObject* var0 = GetCombatantByID((int)arg0->unknown_10_, arg2);
    if (!var0) return 0;
    unsigned long long var1 = func_ov024_021e4b14(arg0, arg1, arg2, arg3, 1);
    void* var2 = func_ov000_0215e958(arg0->unknown_10_);
    if (!var2) return 0;
    int var3 = 0;
    if (func_ov024_021e05e4((struct Struct_ov024_021e04e0*)var0)) {
        int var4 = (arg2 >= 0 && arg2 <= 3);
        if (!var4) {
            func_020488cc((unsigned char*)var0, 1);
        }
        ClearFlag0x1000AndBytes7eA1_02088e64((unsigned char*)c->currentStats_);
        AddEntryAndIncrementCount0215a88c(obj->field0x10, entry, 0x164);
        added = 1;
        if (ArrayContainsByte_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()), slot) && move->id == 0xc6) {
            IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)obj->field0x10, added);
        }
    }
    if (var1 != 0) {
        if (!var3) {
            func_ov000_0215a88c(arg0->unknown_10_, var2, 0);
        }
        var3 = 1;
    }
    if (!var3) {
        func_ov000_0215a88c(arg0->unknown_10_, var2, (unsigned short)arg3->unknown_26_4_);
    }
    struct Struct_ov024_021e07b0_2* var5 = (struct Struct_ov024_021e07b0_2*)((char*)arg0->unknown_c_ + 0x1c);
    func_ov000_0215cd44(arg0->unknown_10_, var2, var0, 0, var1, var5->unknown_0_7_ != 0);
    return var2;
}
