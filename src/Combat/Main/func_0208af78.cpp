#include <globaldefs.h>

struct Struct_0208a9c0;
extern "C" void func_0208a9c0(struct Struct_0208a9c0* p, unsigned char a, unsigned char b, unsigned char c);

struct Struct_0208aa18;
extern "C" void func_0208aa18(struct Struct_0208aa18* s, int x, int y, int z);

struct Struct_0208af78 {
    char pad0[0x94];
    unsigned char unknown_94_[4];
    unsigned char unknown_98_[4];
    unsigned char f9c;
    char pad1[0xb];
    unsigned char unknown_a8_;
    char pad2[3];
    int unknown_ac_;
    int unknown_b0_;
};

// USA: func_0208af78
extern "C" ARM void func_0208af78(struct Struct_0208af78* obj) {
    func_0208a9c0((struct Struct_0208a9c0*)((char*)obj + 0x4), 0, 1, 0x50);
    func_0208a9c0((struct Struct_0208a9c0*)((char*)obj + 0x24), 0, 1, 0x14);
    func_0208a9c0((struct Struct_0208a9c0*)((char*)obj + 0x40), 1, 5, 0x14);
    func_0208a9c0((struct Struct_0208a9c0*)((char*)obj + 0x5c), 2, 5, 0x14);
    func_0208a9c0((struct Struct_0208a9c0*)((char*)obj + 0x78), 3, 3, 0x14);

    func_0208aa18((struct Struct_0208aa18*)((char*)obj + 0x4), 0x1f, 0, 0x14);
    func_0208aa18((struct Struct_0208aa18*)((char*)obj + 0x24), 0x1f, 0, 0x14);
    func_0208aa18((struct Struct_0208aa18*)((char*)obj + 0x40), 0x1c, 0x1c, 0);
    func_0208aa18((struct Struct_0208aa18*)((char*)obj + 0x5c), 0x1c, 0x1c, 0);
    func_0208aa18((struct Struct_0208aa18*)((char*)obj + 0x78), 0x19, 0, 0);

    unsigned char v = 0x28;
    int i;
    for (i = 0; i < 4; i++) {
        obj->unknown_94_[i] = v;
        obj->unknown_98_[i] = v;
    }

    obj->f9c = 0;
    obj->unknown_a8_ = 0;
    obj->unknown_b0_ = 0;
    obj->unknown_ac_ = -1;
}
