#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6a9c {
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned char fielda;
    unsigned char unknown_7_;
    unsigned char pad[8];
};

struct Struct_ov017_021c6a9c_2 {
    unsigned char tag;
    unsigned char pad0[3];
    struct Struct_ov017_021c6a9c fields;
};

// USA: func_ov017_021c6a9c
extern "C" ARM void func_ov017_021c6a9c(unsigned short a0, int a1, int a2, unsigned char a3, unsigned char a4, signed char a5) {
    void* p = LinkMessageQueue_GetInstance();
    Struct_ov017_021c6a9c_2 buf;
    struct Struct_ov017_021c6a9c* var2 = &buf.fields;
    GameState::GetInstance();
    unsigned char var3 = a4;
    signed char var4 = a5;
    var2->field9 = var3;
    buf.tag = 0x43;
    var2->field4 = a0;
    var2->field6 = a2;
    var2->field8 = a3;
    var2->fielda = a1;
    var2->unknown_7_ = var4;
    func_0205e330(p, &buf, 0);
}
