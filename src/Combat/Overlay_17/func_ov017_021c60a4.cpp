#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
struct Struct_02053f7c_3;
extern "C" void func_02053f7c(struct Struct_02053f7c_3* obj, unsigned short a, int b);
extern "C" void func_ov017_021c6034(signed char* arr);

struct Struct_0207dcf0 {
    unsigned short field0;
    unsigned short field2;
    unsigned char flags[4];
    unsigned char field8;
    unsigned char field9;
    short fieldA;
};

struct Struct_ov017_021c60a4 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short field4;
    unsigned short field6;
    unsigned char arr[4];
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    short unknown_e_;
    unsigned char pad2[2];
};

// USA: func_ov017_021c60a4
extern "C" ARM void func_ov017_021c60a4(struct Struct_0207dcf0* obj) {
    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c60a4 msg;
    msg.tag = 0x65;
    msg.field4 = obj->field0;
    int n = 4;
    unsigned char* dst = msg.arr;
    unsigned char* src = obj->flags;
    msg.field6 = obj->field2;
    do {
        *dst = *src;
        dst++;
        src++;
    } while (--n);
    msg.unknown_c_ = obj->field8;
    msg.unknown_d_ = obj->field9;
    msg.unknown_e_ = obj->fieldA;
    func_0205e330(data, &msg, 0);

    GameState* bs = GameState::GetInstance();
    for (unsigned int i = 0; i < 4; i++) {
        if ((signed char)obj->flags[i] == 0) continue;
        GameObject* c = func_0200ff1c(bs, i);
        if (c == NULL) continue;
        func_02053f7c((struct Struct_02053f7c_3*)c, obj->field0, 1);
    }

    func_ov017_021c6034((signed char*)msg.arr);
}
