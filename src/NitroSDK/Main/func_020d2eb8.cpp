#include <globaldefs.h>

extern "C" void func_020d21f8(void);
extern "C" void func_020d220c(void);
void CleanCacheRange(const void* addr, unsigned int size);

struct Struct_020be4f4 { unsigned char pad[0x3c]; int entries[1]; };

// USA: func_020d2eb8
extern "C" ARM void func_020d2eb8(struct Struct_020be4f4* obj, int index, int value) {
    func_020d21f8();
    obj->entries[index] = value;
    CleanCacheRange((const void*)((int)&obj->entries[index]), 4);
    func_020d220c();
}
