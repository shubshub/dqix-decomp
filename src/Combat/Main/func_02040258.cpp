#include <globaldefs.h>

struct Struct_0203fca0;
extern "C" ARM void func_0203fca0(struct Struct_0203fca0* obj);

struct Struct_02040258 {
    unsigned char field0;
    unsigned char pad[0x37];
    int field38;
};

// USA: func_02040258
extern "C" ARM void func_02040258(struct Struct_02040258* obj) {
    obj->field0 = 0;
    func_0203fca0((struct Struct_0203fca0*)((char*)obj + 0x10));
    obj->field38 = -1;
}
