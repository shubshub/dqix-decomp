#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"

#if defined(jpn)
#define data_ov000_02183198 data_ov000_02184244
#define data_ov000_021831d8 data_ov000_02184284
#define data_ov000_021830d8 data_ov000_02184184
#endif
extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
extern "C" void func_ov000_02167b54(int* obj, int a, int b, int c);
extern "C" int func_020493a4(unsigned char* obj);
extern "C" void func_02049390(unsigned char* obj, unsigned char value);
extern "C" void func_02049bd4(unsigned char* obj, int* src);
extern "C" void func_02049c60(unsigned char* obj, int* src);

struct Struct_ov000_021830d8 { int v[3]; };
extern struct Struct_ov000_021830d8 data_ov000_021830d8;
extern int data_ov000_02183198[16];
extern int data_ov000_021831d8[16];

struct Struct_ov000_02167fb0 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    void* unknown_29c_;
};

// USA: func_ov000_02167fb0
extern "C" ARM void func_ov000_02167fb0(struct Struct_ov000_02167fb0* battle, GameObject* target) {
    if (target == NULL) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    short ids[0x10];
    int count = func_ov000_02153e40(battle->unknown_29c_, ids, 0x10, 0);
    int rotation[3];
    int* cells;
    int isParty = (target->obj3D_.actorIndex_ >= 0 && target->obj3D_.actorIndex_ <= 3) ? 1 : 0;
    if (isParty) {
        cells = data_ov000_02183198;
        func_ov000_02167b54(rotation, 0, 0x3244, 0);
    } else {
        int isGuest = (target->obj3D_.actorIndex_ >= 0xc0 && target->obj3D_.actorIndex_ <= 0xc7) ? 1 : 0;
        if (!isGuest) {
            return;
        }
        cells = data_ov000_021831d8;
        func_ov000_02167b54(rotation, 0, 0, 0);
    }
    for (int i = 0; i < 0x10; i++) {
        int cell = cells[i];
        int taken = 0;
        for (int j = 0; j < count; j++) {
            GameObject* c = gs->GetCombatantByIndex(ids[j]);
            if (c != NULL && cell == func_020493a4((unsigned char*)c)) {
                taken = 1;
                break;
            }
        }
        if (!taken) {
            struct Struct_02048cf0 pos = func_ov000_0216f74c(&cell);
            func_02049390((unsigned char*)target, cell & 0xff);
            struct Struct_ov000_021830d8 position = data_ov000_021830d8;
            position.v[0] = pos.x;
            position.v[2] = pos.y;
            func_02049bd4((unsigned char*)target, position.v);
            func_02049c60((unsigned char*)target, rotation);
            return;
        }
    }
}
