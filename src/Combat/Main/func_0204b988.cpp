#include <globaldefs.h>

extern "C" void func_0204b938(void* obj, void* p, int a3, int a4, unsigned short a5);

struct Struct_0204b988 {
    char pad0[0x10];
    char* field10;
    char unknown_14_[0x9];
    unsigned char unknown_1d_;
};

// USA: func_0204b988
extern "C" ARM void func_0204b988(struct Struct_0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5) {
    char* base;
    if (obj->unknown_1d_ <= index) return;
    base = obj->field10;
    if (base == NULL) return;
    func_0204b938(obj, base + index * 16, a3, a4, a5);
}
