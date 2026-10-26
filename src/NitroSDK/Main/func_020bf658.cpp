#include <globaldefs.h>

struct Struct_020bf658 { unsigned int a; unsigned int b; };

struct Struct_020bf658_2 {
    char pad0[0xc0];
    unsigned char state;
    char pad1[0xc4 - 0xc1];
    unsigned short unknown_c4_;
    char pad2[0x110 - 0xc6];
    unsigned int unknown_110_;
    char pad3[0x13c - 0x114];
    int (*unknown_13c_)(int, Struct_020bf658*, Struct_020bf658*, int);
    int unknown_140_;
    int unknown_144_;
    int unknown_148_;
    char pad4[0x160 - 0x14c];
    int unknown_160_;
    int (*unknown_164_)(void*, unsigned int);
    void (*unknown_168_)(void*);
};

extern "C" void* func_020bd5e4(int index);
extern "C" void func_020bffc4(void* obj, unsigned int id);

// USA: func_020bf658
extern "C" ARM void func_020bf658(struct Struct_020bf658_2* obj) {
    Struct_020bf658 p1, p2;
    unsigned int var2;
    unsigned short var3, var4;
    unsigned int* entry;
    unsigned int id;
    unsigned long long prod;

    p1.a = obj->unknown_148_;
    p1.b = obj->unknown_144_;
    p2.a = obj->unknown_144_;
    p2.b = 0;
    if (!obj->unknown_13c_(0, &p1, &p2, obj->unknown_140_)) return;

    entry = (unsigned int*)func_020bd5e4(p2.a);
    if (entry == 0) return;

    var2 = obj->state;
    var3 = obj->unknown_c4_;
    obj->unknown_168_(obj);

    id = *entry;
    func_020bffc4(obj, id);

    id = *entry;
    if (!obj->unknown_164_(obj, id)) return;

    var4 = obj->unknown_c4_;
    if (var3 != var4) return;

    if (var2 == 0) {
        if (obj->state != 0) return;
    }
    if (var2 != 0) {
        if (obj->state == 0) return;
    }

    obj->unknown_144_ = p2.a;
    prod = (unsigned long long)obj->unknown_c4_ * (unsigned long long)p2.b;
    obj->unknown_160_ = (int)(prod / 1000);

    if (obj->unknown_160_ != 0 && obj->state == 2) {
        obj->unknown_110_ |= 0x10;
    } else {
        obj->unknown_110_ &= ~0x10;
    }
    obj->unknown_110_ &= ~0x20;
}
