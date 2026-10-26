#include <globaldefs.h>

struct Struct_ov031_02235194 {
    void* inner;
    char padding[8];
    void* payload;
};

extern "C" Struct_ov031_02235194* data_ov031_02290cf4;
namespace DuplicatePool {
    extern "C" Struct_ov031_02235194* data_ov031_02290cf4;
}
extern "C" int func_ov031_0223e2e0(int, void*);
extern "C" void func_ov031_0223ba20(void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_02235194
extern "C" ARM void func_ov031_02235194(void) {
    func_ov031_0223e2e0(0, data_ov031_02290cf4->payload);
    func_ov031_0223ba20(data_ov031_02290cf4->inner);
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290cf4);
}
