#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void** func_ov011_021849c8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov023_021f9c60(void* obj, unsigned short v);

class Struct_ov004_0216d720 {
public:
    virtual void v00(); virtual void inline_ov004_0216d720_2(); virtual void inline_ov004_0216d720_3(); virtual void inline_ov004_0216d720_4();
    virtual void v04(); virtual void inline_ov004_0216d720_6(); virtual void inline_ov004_0216d720_7(); virtual void inline_ov004_0216d720_8();
    virtual void v08(); virtual void inline_ov004_0216d720_10(); virtual void v10(); virtual void inline_ov004_0216d720_12();
    virtual void inline_ov004_0216d720_13(); virtual void inline_ov004_0216d720_14(); virtual void v14(); virtual void inline_ov004_0216d720_16();
    virtual void inline_ov004_0216d720_17();
    virtual void inline_ov004_0216d720_18(int a);
    virtual void v18(); virtual void inline_ov004_0216d720_20(); virtual void v20(); virtual void inline_ov004_0216d720_22();
    virtual void inline_ov004_0216d720_23(); virtual void inline_ov004_0216d720_24(); virtual void v24(); virtual void inline_ov004_0216d720_26();
    virtual void inline_ov004_0216d720_27(); virtual void inline_ov004_0216d720_28(); virtual void v28(); virtual void inline_ov004_0216d720_30();
    virtual void v30();
    virtual void inline_ov004_0216d720_32(int a);
    char pad[8];
    unsigned char fieldC;
};
extern "C" Struct_ov004_0216d720* func_ov023_021f6880(void** list, int value);

// USA: func_ov004_0216d720
extern "C" ARM int func_ov004_0216d720(void* a0) {
    GameState::GetInstance();
    Struct_ov004_0216d720* node = func_ov023_021f6880(func_ov011_021849c8(a0), 0x38);
    if (node) {
        node->inline_ov004_0216d720_18(0);
        node->inline_ov004_0216d720_32(0);
        node->fieldC |= 0x50;
    }
    Struct_ov004_0216d720* node2 = func_ov023_021f6880(func_ov011_021849c8(a0), 0x39);
    if (node2) {
        node2->inline_ov004_0216d720_18(0);
        node2->inline_ov004_0216d720_32(0);
        node2->fieldC |= 0x50;
    }
    Struct_ov004_0216d720* node3 = func_ov023_021f6880(func_ov011_021849c8(a0), 0x12d);
    if (node3) {
        func_ov023_021f9c60(node3, 0);
    }
    func_ov011_021848a0(a0, 0x2bd);
    return 0;
}
