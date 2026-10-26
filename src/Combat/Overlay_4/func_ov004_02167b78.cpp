#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02167b78 func_ov004_02168074
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void func_ov004_0216794c(short* p1, short* p2, short* p3, char* p4, int* p5);
int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* g);
struct Obj02046574;
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
struct ItemTable;
struct Element020de650;
Element020de650* ItemTable_Find(ItemTable*, int);
extern "C" ItemTable* func_ov004_02167908(void* a1, int b);
#else
extern "C" int func_ov004_02167908(void* a1, int b);
#endif
struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void* NameText_Clear(void* p);
void DispatchIfCountPositive020dcf7c(int count, void* buf);

struct A2Struct02167b78 {
    short f0;
    short f2;
};
extern struct A2Struct02167b78 data_ov004_02170010[];

struct Sub24_02167b78 {
    void* a;
    void* b;
    unsigned int unknown8;
};
struct Handle24_02167b78 {
    void* bufA;
    struct Sub24_02167b78* sub;
    void* bufB;
};
extern struct Handle24_02167b78 data_ov004_02171024;

struct Local78 {
    char reached;
    short threshold;
    short matches;
    short current;
    int thresholdIndex;
};

// USA: func_ov004_02167b78  (semantic: ComputeAndStoreArrayEntries_02167b78)
extern "C" ARM int func_ov004_02167b78(void* a1, struct A2Struct02167b78* a2) {
    struct Local78 local;
    func_ov004_0216794c(&local.current, &local.matches, &local.threshold, &local.reached, &local.thresholdIndex);

    int sum = (short)(local.current + local.matches);
    if (sum > 0x50) sum = 0x50;

    void* g = (void*)MessageSystem_GetInstance();
    func_02046380(g);

    GameObject* c = GameState::GetInstance()->GetLeader();
    if (c != 0) {
        MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, c->baseStats_->name);
    }

#if defined(jpn)
    ItemTable* haveX = func_ov004_02167908(a1, 5);
#else
    int haveX = func_ov004_02167908(a1, 5);
#endif

    StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 0, local.current);
    StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 1, local.matches);
    StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 2, local.threshold);
    StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 3, sum);

    if (haveX != 0) {
        if (a2 == 0) {
            int idx = local.thresholdIndex;
            if (idx >= 0) {
                a2 = &data_ov004_02170010[idx];
            }
        }
        if (a2 != 0) {
#if defined(jpn)
            Element020de650* entry = ItemTable_Find(haveX, a2->f2);
            if (entry != 0) {
                MessageSystem_SetStringArgument((struct Obj02046574*)g, 1, *(char**)((char*)entry + 4));
            }
#else
            if (data_ov004_02171024.sub != 0 && data_ov004_02171024.bufA != 0 && data_ov004_02171024.bufB != 0) {
                NameText_Clear(data_ov004_02171024.sub);
                data_ov004_02171024.sub->a = data_ov004_02171024.bufA;
                data_ov004_02171024.sub->b = data_ov004_02171024.bufB;
                memset(data_ov004_02171024.bufA, 0, 0x80);
                memset(data_ov004_02171024.bufB, 0, 0x80);
            }
            DispatchIfCountPositive020dcf7c(a2->f2, data_ov004_02171024.sub);
            *(void**)((char*)g + 0x18) = data_ov004_02171024.sub;
#endif
            StoreInArray0x8b0_020465c0((struct StoreStruct*)g, 2, a2->f0);
        }
    }
    return 0;
}
