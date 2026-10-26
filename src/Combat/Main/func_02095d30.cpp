#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void* Scenario_GetInstance();
struct GameState;
extern "C" void* GameState_GetParty(GameState*);
extern "C" int func_0209645c(void* list, int value);
struct PackedNibbleArray0206e120;
extern "C" int func_0206e120(PackedNibbleArray0206e120*, int);
extern "C" void func_0206e218(unsigned char*, int);
extern "C" void func_0206eb64(unsigned char*, int, int);
struct Obj02086aec;
extern "C" int Party_CountItem(Obj02086aec*, int);
extern "C" int func_02086d88(unsigned char*, int);

struct Struct_02095d30 {
    unsigned short id : 9;
    unsigned short unknown_1_1_ : 1;
    unsigned short unknown_1_2_ : 1;
    unsigned short count : 5;
    unsigned short unknown_2_[13];
    unsigned short count1;
    short list1[5];
    struct Struct_02095d30* next;
};

struct Struct_02095d30_2 {
    unsigned char pad[0xa4];
    struct Struct_02095d30* head;
};

// USA: func_02095d30
extern "C" ARM int func_02095d30(struct Struct_02095d30_2* list, int value, int mode) {
    if (list->head == 0) {
        return 0;
    }
    void* gs = GameState::GetInstance();
    void* nibbles = Scenario_GetInstance();
    void* obj = GameState_GetParty((GameState*)gs);
    struct Struct_02095d30* cur;
    for (cur = list->head; cur != 0; cur = cur->next) {
        if (cur->id != value) {
            continue;
        }
        int ok = (func_0206e120((PackedNibbleArray0206e120*)nibbles, value) == 2);
        if (ok != 0) {
            if (!cur->unknown_1_2_) {
                return 0;
            }
            func_0206e218((unsigned char*)nibbles, value);
            func_0209645c(list, value);
            if (mode != 0) {
                int i = 0;
                int x = 0;
                while (i < cur->count) {
                    func_0206eb64((unsigned char*)nibbles, cur->unknown_2_[i], x);
                    i++;
                }
            }
            int j;
            int n;
            int k = 0;
            for (j = 0; j < cur->count1; j++) {
                short v = cur->list1[j];
                if (v <= 0) {
                    continue;
                }
                n = Party_CountItem((Obj02086aec*)obj, v);
                for (k = 0; k < n; k++) {
                    func_02086d88((unsigned char*)obj, cur->list1[j]);
                }
            }
            break;
        }
    }
    if (cur == 0) { return 0; }
    return 1;
}
