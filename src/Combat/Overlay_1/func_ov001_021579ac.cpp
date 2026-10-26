#include <globaldefs.h>

struct Struct_02028460_3 { int x; int y; int z; };

extern "C" int Vector3fix_Distance(struct Struct_02028460_3* a, struct Struct_02028460_3* b);

struct Struct_ov001_02157570_2 {
    unsigned char pad0[0x38c];
    int x;
    int y;
    int z;
};
struct Struct_ov001_02157570 {
    int x;
    int y;
    int z;
};
extern "C" void func_ov001_02157570(struct Struct_ov001_02157570_2* src, struct Struct_ov001_02157570* dst);

extern "C" ARM int fix32_Divide(unsigned int arg0, unsigned int arg1);

extern "C" int func_ov001_021573c0(void* p);
extern "C" void func_ov001_02156c14(void* dst, void* self, int* arr, int count, int extra);

struct Struct_ov001_021579ac {
    struct Struct_02028460_3 slots[16];
    int unknown_c0_;
    int count;
};

// USA: func_ov001_021579ac
extern "C" ARM int func_ov001_021579ac(struct Struct_ov001_021579ac* self) {
    if (self->count <= 0) {
        return 1;
    }

    int var0[32];
    struct Struct_02028460_3 vecB;
    struct Struct_02028460_3 vecA;

    int i;
    int total = 0;
    for (i = 0; i < self->count - 1; i++) {
        var0[i] = Vector3fix_Distance(&self->slots[i], &self->slots[i + 1]);
        total += var0[i];
    }

    i = 0;
    int* var5 = var0 + 16;
    while (i < self->count - 1) {
        var5[i] = self->unknown_c0_ / (self->count - 1);
        i++;
    }

    func_ov001_02156c14((char*)self + 0xc8, self, var0 + 16, self->count, 0);

    total = 0;
    do {
        func_ov001_02157570((struct Struct_ov001_02157570_2*)((char*)self + 0xc8), (struct Struct_ov001_02157570*)&vecB);
        if (func_ov001_021573c0((char*)self + 0xc8) != 0) {
            break;
        }
        func_ov001_02157570((struct Struct_ov001_02157570_2*)((char*)self + 0xc8), (struct Struct_ov001_02157570*)&vecA);
        total += Vector3fix_Distance(&vecB, &vecA);
    } while (1);

    int var6 = fix32_Divide(total, self->unknown_c0_ << 12);
    func_ov001_02156c14((char*)self + 0xc8, self, var0 + 16, self->count, var6);

    return 0;
}
