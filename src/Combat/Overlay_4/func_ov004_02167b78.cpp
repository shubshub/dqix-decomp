#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02167b78 func_ov004_02168074
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"
#if defined(jpn)
#define func_ov004_02168074 func_ov004_021684bc
#endif

extern "C" void func_ov004_0216794c(short* p1, short* p2, short* p3, char* p4, int* p5);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* g);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
struct ItemTable;
struct Element020de650;
extern "C" Element020de650* ItemTable_Find(ItemTable*, int);
extern "C" ItemTable* func_ov004_02167908(void* a1, int b);
#else
extern "C" int func_ov004_02167908(void* a1, int b);
#endif
struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void* NameText_Clear(void* p);
extern "C" void func_020dcf7c(int count, void* buf);

struct Struct_ov004_02170010_2 {
    short f0;
    short f2;
};
extern struct Struct_ov004_02170010_2 data_ov004_02170010[];

struct Struct_ov004_02167b78 {
    void* a;
    void* b;
    unsigned int unknown8;
};
struct Struct_ov004_02171024 {
    void* bufA;
    struct Struct_ov004_02167b78* sub;
    void* unknown_8_;
};
extern struct Struct_ov004_02171024 data_ov004_02171024;

struct Struct_ov004_02167b78_2 {
    char reached;
    short threshold;
    short matches;
    short current;
    int unknown_8_;
};

// USA: func_ov004_02167b78
extern "C" ARM int func_ov004_02167b78(void* a1, struct Struct_ov004_02170010_2* a2) {
    struct Struct_ov004_02167b78_2 local;
    func_ov004_0216794c(&local.current, &local.matches, &local.threshold, &local.reached, &local.unknown_8_);

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

    func_020465c0((struct StoreStruct*)g, 0, local.current);
    func_020465c0((struct StoreStruct*)g, 1, local.matches);
    func_020465c0((struct StoreStruct*)g, 2, local.threshold);
    func_020465c0((struct StoreStruct*)g, 3, sum);

    if (haveX != 0) {
        if (a2 == 0) {
            int idx = local.unknown_8_;
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
            if (data_ov004_02171024.sub != 0 && data_ov004_02171024.bufA != 0 && data_ov004_02171024.unknown_8_ != 0) {
                NameText_Clear(data_ov004_02171024.sub);
                data_ov004_02171024.sub->a = data_ov004_02171024.bufA;
                data_ov004_02171024.sub->b = data_ov004_02171024.unknown_8_;
                memset(data_ov004_02171024.bufA, 0, 0x80);
                memset(data_ov004_02171024.unknown_8_, 0, 0x80);
            }
            func_020dcf7c(a2->f2, data_ov004_02171024.sub);
            *(void**)((char*)g + 0x18) = data_ov004_02171024.sub;
#endif
            func_020465c0((struct StoreStruct*)g, 2, a2->f0);
        }
    }
    return 0;
}
