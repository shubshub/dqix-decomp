#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021d3950_3 {
    unsigned char mode;
    signed char idx;
    unsigned char mask;
    unsigned char id;
};

struct Struct_ov017_021d3950 {
    unsigned int timer : 9;
    unsigned int unknown_1_1_ : 8;
    unsigned int flags : 8;
    unsigned int count : 4;
    unsigned int unknown_3_5_ : 2;
    unsigned int active : 1;
};

struct Struct_ov017_021d3950_2 {
    unsigned int unk0 : 16;
    unsigned int id : 7;
    unsigned int unknown_2_7_ : 9;
    unsigned int unknown_4_0_ : 21;
    unsigned int flags : 8;
    unsigned int unknown_7_5_ : 3;
    char pad8[0x6c - 8];
    struct Struct_ov017_021d3950_2* next;
};

struct Head0208e7a4 {
    char pad0[4];
    struct Struct_ov017_021d3950_2* head;
};

struct Struct_0208f3b4;

extern "C" Head0208e7a4* LootPointList_GetInstance(void);
extern "C" Struct_ov017_021d3950* func_020120b8(char* obj, int index);
extern "C" Struct_ov017_021d3950_2* func_0208e7a4(Head0208e7a4* owner, unsigned int key);
extern "C" Struct_0208f3b4* func_0208e9e8(void);
extern "C" void func_0208f3b4(Struct_0208f3b4* c, int key);

// USA: func_ov017_021d3950
extern "C" ARM int func_ov017_021d3950(Struct_ov017_021d3950_3* req) {
    GameState* gs = GameState::GetInstance();
    Head0208e7a4* list = LootPointList_GetInstance();
    Struct_ov017_021d3950* entry = func_020120b8((char*)gs, req->id);
    if (entry != NULL && (req->mask & entry->flags) != 0) {
        entry->flags = ~req->mask & entry->flags;
        entry->timer = entry->count * 30;
        Struct_ov017_021d3950_2* node = func_0208e7a4(list, req->id);
        if (node == NULL) {
            return 1;
        }
        node->flags = ~req->mask & node->flags;
        Struct_ov017_021d3950_2* p;
        int i = 0;
        for (p = list->head; p != NULL; p = p->next, i++) {
            if (p->id == req->id) {
                break;
            }
        }
        if (p == NULL) {
            return 1;
        }
        int bit;
        for (bit = 0; bit < 8; bit++) {
            if (req->mask & (1 << bit)) {
                break;
            }
        }
        if (p != NULL && bit < 8) {
            func_0208f3b4(func_0208e9e8(), bit + i * 8);
        }
        return 1;
    }
    return 0;
}
