#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Object3D.h"
#include "World/ZoneFeatures.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_ov025_021db458 { char pad0[0x20]; unsigned short id; char unknown_22_[0xe]; Struct_ov025_021db458* next; };
struct Struct_ov025_021db458_2 { char pad0[0xe]; short ids[4]; char pad16; unsigned char count; char pad18[8]; Struct_ov025_021db458_2* next; };
struct Struct_ov025_021db458_3 { char pad0[4]; short id; char pad6[0x3e]; Struct_02014900 position; };

struct Struct_ov025_021db458_4 {
#if defined(jpn)
    char pad0[0x218];
    void* unknown_29c_;
    char unknown_21c_[0xe10 - 0x21c];
    void* list;
    char unknown_e14_[0x5b41 - 0xe14];
#else
    char pad0[0x29c];
    void* unknown_29c_;
    char unknown_2a0_[0xe94 - 0x2a0];
    void* list;
    char unknown_e98_[0x5951 - 0xe98];
#endif
    unsigned char mode : 2;
    unsigned char flags : 6;
};

extern "C" void* func_ov000_02160f20(void*);
extern "C" int func_ov000_0215e9fc(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* obj, short* buf, int max, int start);
extern "C" int func_02049afc(unsigned char* obj);
extern "C" void* __clear(void* dst, int count);
extern "C" Struct_ov025_021db458* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov025_021db458_2* func_ov000_021600f8(Struct_ov000_0215440c*, int);

// USA: func_ov025_021db458
extern "C" ARM void func_ov025_021db458(Struct_ov025_021db458_4* work) {
    int var0;
    int j;
    func_ov000_02160f20(work);
    GameState* game = GameState::GetInstance();
    if (work->mode != 2) return;
    void* list;
    short ids[16];
    int count = 0;
    count = count + func_ov000_0215e9fc(work->unknown_29c_, ids, 0x10, count);
    count = count + func_ov000_0215ec1c(work->unknown_29c_, ids + count, 0x10 - count, 0);
    for (int i = 0; i < count; i++) {
        GameObject* obj = game->GetCombatantByIndex(ids[i]);
        if (!obj) continue;
        if (!func_02049afc((unsigned char*)obj) || (list = work->list) == 0) continue;
        Struct_02014900 dir;
        Struct_02014900 var9;
        Struct_02014900 pos;
        Struct_02014900 var11;
        Struct_ov025_021db458* actors;
        GameState* state = GameState::GetInstance();
        __clear(&var11.vec, sizeof(var11));
        Struct_ov025_021db458_3* body = (Struct_ov025_021db458_3*)obj;
        int k;
        short* id = ids;
        pos = body->position;
        pos.vec.y = 0xcc;
        actors = func_ov000_02160094((Struct_ov000_0215440c_2*)list, 0);
        Struct_ov025_021db458_2* targets = func_ov000_021600f8((Struct_ov000_0215440c*)list, 0);
        Struct_ov025_021db458* a = actors;
        int self = body->id;
        for (; a; a = a->next) {
            if (a->id == body->id) goto next;
        }
        for (Struct_ov025_021db458_2* t = targets; t; t = t->next) {
            short* p = t->ids;
            for (j = 0; j < t->count; j++, p++) {
                if (*p == self) goto next;
            }
        }
        for (k = 0; k < (short)count; id++, k++) {
            Struct_ov025_021db458* b;
            int unique = 1;
            for (b = actors; b; b = b->next) {
                if (b->id == *id) { unique = 0; break; }
            }
            if (!unique || *id == body->id) continue;
            GameObject* other = state->GetGameObjectByIndex(*id);
            if (!other) continue;
            var0 = obj->obj3D_.GetRadius();
            var0 += other->obj3D_.GetRadius();
            var9 = ((Struct_ov025_021db458_3*)other)->position;
            var9.vec.y = 0xcc;
            int dist = Vector3fix_Distance(&pos.vec, &var9.vec);
            if (dist <= 0 || dist >= (var0 >> 1)) continue;
            Vector3fix_Subtract(&pos.vec, &var9.vec, &dir.vec);
            Vector3fixMultiplyScalar(&dir.vec, fix32_Divide(((var0 >> 1) - dist) >> 2, dist), &dir.vec);
            Vector3fix_Add(&var11.vec, &dir.vec, &var11.vec);
        }
        Vector3fix_Add(&pos.vec, &var11.vec, &pos.vec);
        body->position.vec = pos.vec;
    next:;
    }
}
