#include <globaldefs.h>

struct Struct_02040468;

struct Struct_0203f138_3 {
    char pad0[0x28];
    int field28;
};

struct Struct_0203f138 {
    char pad0[0xc];
    unsigned int* fieldc;
};

extern "C" struct Struct_0203f138_3* func_02040468(struct Struct_02040468* list, int index);
extern "C" void* func_0203f1c8(unsigned char* obj, unsigned int index);
extern int data_02114e50;

struct Struct_0203f138_2 {
    struct Struct_02040468* field0;
    char pad4[0x28 - 4];
    short field28;
    char pad2a[0x30 - 0x2a];
    int unknown_30_;
    int field34;
    int field38;
    unsigned int field3c;
};

// USA: func_0203f138
extern "C" ARM void func_0203f138(struct Struct_0203f138_2* obj, int b) {
    struct Struct_0203f138_3* elem;
    struct Struct_0203f138* stride;

    if (obj->field28 < 0) {
        return;
    }
    elem = func_02040468(obj->field0, obj->field28);
    if (elem == 0 || elem->field28 == 0) {
        return;
    }
    if (b < 0) {
        return;
    }
    if ((unsigned int)elem->field28 <= (unsigned int)b) {
        return;
    }
    if (obj->unknown_30_ == b) {
        return;
    }
    stride = (struct Struct_0203f138*)func_0203f1c8((unsigned char*)elem + 0x10, b);
    if (stride == 0) {
        return;
    }
    obj->field34 = 0;
    obj->unknown_30_ = b;
    obj->field38 = data_02114e50;
    obj->field3c = stride->fieldc[obj->field34];
}
