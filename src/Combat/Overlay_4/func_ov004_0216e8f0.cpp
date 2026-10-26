#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov004_0216e8f0 {
    char pad[0xc];
    unsigned char unknown_c_;
};

struct Struct_ov004_0216b7bc;
extern "C" void func_ov011_02184ad8(struct Struct_ov004_0216b7bc* obj);
extern "C" void func_02012028(void* obj, unsigned char value);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" Struct_ov004_0216e8f0* func_ov023_021f6880(void* obj, int key);
extern "C" int func_ov024_021f6f10(void* self);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#endif
static inline int inline_ov004_0216e8f0(void* node) {
#if defined(jpn)
    return func_ov023_021f6f10(node);
#else
    return func_ov024_021f6f10(node);
#endif
}

extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216e8f0
extern "C" ARM int func_ov004_0216e8f0(void* obj) {
#if defined(jpn)
    enum { Enum_ov004_0216e8f0_10 = 0x8, stateOffset = 5 };
#else
    enum { Enum_ov004_0216e8f0_10 = 0xa, stateOffset = 3 };
#endif
    void* p = func_ov011_021849c8(obj);
    if (p) {
        Struct_ov004_0216e8f0* node = func_ov023_021f6880(p, *(unsigned short*)(data_ov004_02171034 + Enum_ov004_0216e8f0_10));
        if (node) {
            node->unknown_c_ &= ~0x10;
        }
    }
    func_ov011_02184ad8((struct Struct_ov004_0216b7bc*)obj);
    GameState* bs = GameState::GetInstance();
    if (data_ov004_02171034[stateOffset] != 6) {
        Struct_ov004_0216e8f0* node2 = func_ov023_021f6880(p, 1);
        if (node2 && inline_ov004_0216e8f0(node2) == 0xb) {
            node2->unknown_c_ &= ~0x8;
            func_02012028(bs, 1);
        }
    }
    return 0;
}
