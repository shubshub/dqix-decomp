#include <globaldefs.h>
extern "C" void func_0205d904(unsigned char*);

struct Struct_0205dee8 {
    char pad0[0xb0];
    unsigned char fieldB0;           // 0xb0
};


// USA: func_0205dee8
extern "C" ARM void func_0205dee8(struct Struct_0205dee8* obj, int val) {
    obj->fieldB0 = val;
    func_0205d904((unsigned char*)(obj));
}
