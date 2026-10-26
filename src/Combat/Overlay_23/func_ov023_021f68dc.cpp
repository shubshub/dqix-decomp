#include <globaldefs.h>

struct Struct_ov023_021f68dc_2 {
    virtual void v0(void* arg);
    virtual void v1();
    virtual void v2();
    virtual void v3(void* arg);
    virtual void v4(void* arg);
    char pad[0x14];
    Struct_ov023_021f68dc_2* next;
};

struct Struct_ov023_021f68dc {
    Struct_ov023_021f68dc_2* head;
};

extern "C" int func_ov023_021f6ac8(Struct_ov023_021f68dc* obj, void* arg);
extern "C" void func_ov023_021f6a1c(Struct_ov023_021f68dc* obj, void* arg);

// USA: func_ov023_021f68dc
extern "C" ARM void func_ov023_021f68dc(Struct_ov023_021f68dc* obj, void* arg) {
    Struct_ov023_021f68dc_2* node;
    for (node = obj->head; node; node = node->next) {
        node->v3(arg);
    }
    for (node = obj->head; node; node = node->next) {
        node->v0(arg);
    }
    for (node = obj->head; node; node = node->next) {
        node->v4(arg);
    }
    if (func_ov023_021f6ac8(obj, arg) != 0) return;
    func_ov023_021f6a1c(obj, arg);
}
