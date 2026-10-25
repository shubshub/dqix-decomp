#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void* Scenario_GetInstance();
struct GameState;
void* GameState_GetParty(GameState*);
extern "C" int func_0209645c(void* list, int value);
struct PackedNibbleArray0206e120;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
void SetNibbleBit0206e218(unsigned char*, int);
void SetBitWithOffset0206eb64(unsigned char*, int, int);
struct Obj02086aec;
int Party_CountItem(Obj02086aec*, int);
int DecrementKeyEverywhere02086d88(unsigned char*, int);

struct Struct_02095d30 {
    unsigned short unknown_0_0_ : 9;
    unsigned short unknown_1_1_ : 1;
    unsigned short unknown_1_2_ : 1;
    unsigned short unknown_1_3_ : 5;
    unsigned short unknown_2_[13];
    unsigned short unknown_1c_;
    short unknown_1e_[5];
    struct Struct_02095d30* unknown_28_;
};

struct Struct_02095d30_2 {
    unsigned char unknown_0_[0xa4];
    struct Struct_02095d30* unknown_a4_;
};

// USA: func_02095d30
extern "C" ARM int func_02095d30(struct Struct_02095d30_2* arg0, int arg1, int arg2) {
    if (arg0->unknown_a4_ == 0) {
        return 0;
    }
    void* gs = GameState::GetInstance();
    void* nibbles = Scenario_GetInstance();
    void* obj = GameState_GetParty((GameState*)gs);
    struct Node02095d30* cur;
    for (cur = list->head; cur != 0; cur = cur->next) {
        if (cur->id != value) {
            continue;
        }
        int var4 = (func_0206e120((Struct_0205faf4_3*)var1, arg1) == 2);
        if (var4 != 0) {
            if (!var3->unknown_1_2_) {
                return 0;
            }
            func_0206e218((unsigned char*)var1, arg1);
            func_0209645c(arg0, arg1);
            if (arg2 != 0) {
                int var5 = 0;
                int var6 = 0;
                while (var5 < var3->unknown_1_3_) {
                    func_0206eb64((unsigned char*)var1, var3->unknown_2_[var5], var6);
                    var5++;
                }
            }
            int var7;
            int var8;
            int var9 = 0;
            for (var7 = 0; var7 < var3->unknown_1c_; var7++) {
                short var10 = var3->unknown_1e_[var7];
                if (var10 <= 0) {
                    continue;
                }
                n = Party_CountItem((Obj02086aec*)obj, v);
                for (k = 0; k < n; k++) {
                    DecrementKeyEverywhere02086d88((unsigned char*)obj, cur->list1[j]);
                }
            }
            break;
        }
    }
    if (var3 == 0) { return 0; }
    return 1;
}
