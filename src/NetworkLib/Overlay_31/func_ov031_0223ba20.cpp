#include <globaldefs.h>

struct Struct_ov031_0223ba20_2 {
    int flags;
    int unused;
};

struct Struct_ov031_0223ba20 {
    char pad8[8];
    Struct_ov031_0223ba20_2* arr;
    unsigned char count;
};

extern "C" void func_ov031_0223d8a0(void* obj);
extern "C" void func_ov031_0223bf48(int val, void* obj);
extern void* data_ov031_02290d28;

// USA: func_ov031_0223ba20
extern "C" ARM void func_ov031_0223ba20(void* obj) {
    Struct_ov031_0223ba20* self = (Struct_ov031_0223ba20*)obj;
    int index = 0;

    Struct_ov031_0223ba20_2* p = self->arr;
    int i = 0;
    int count = self->count;
    if (count > 0) {
        do {
            p->flags = (p->flags & 0xc1fffcff) | 0x200;
            i++;
            p++;
        } while (i < self->count);
    }

    func_ov031_0223d8a0(obj);

    void* base = data_ov031_02290d28;
    if ((unsigned int)obj >= (unsigned int)((char*)base + 0x228)) {
        index = 1;
    }
    int val = *(int*)((char*)base + index * 0x228 + 0x224);
    func_ov031_0223bf48(val, obj);
}
