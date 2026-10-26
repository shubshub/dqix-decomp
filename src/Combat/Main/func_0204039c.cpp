#include <globaldefs.h>

struct Struct_0203fca0;
extern "C" void func_0203fcd4(struct Struct_0203fca0* obj);

struct Struct_02040258 {
    unsigned char field0;
    unsigned char pad[0x37];
    int field38;
};
extern "C" void func_02040258(struct Struct_02040258* obj);

struct Struct_0204039c {
    int count;
    char pad4[4];
    struct Struct_02040258* table;
};

// USA: func_0204039c
extern "C" ARM void func_0204039c(struct Struct_0204039c* obj, int index) {
    struct Struct_02040258* table = obj->table;
    if (table == 0) {
        return;
    }
    if (index < 0) {
        return;
    }
    if ((unsigned int)obj->count <= (unsigned int)index) {
        return;
    }
    if (table[index].field38 < 0) {
        return;
    }
    if (table[index].field38 > 0) {
        table[index].field38--;
        return;
    }
    func_0203fcd4((struct Struct_0203fca0*)((char*)&table[index] + 0x10));
    func_02040258(&obj->table[index]);
}
