#include <globaldefs.h>

struct Struct_ov031_0223da0c {
    char padding[0x808];
    void* payload;
};

extern "C" Struct_ov031_0223da0c* data_ov031_02290d60;
namespace DuplicatePool {
    extern "C" Struct_ov031_0223da0c* data_ov031_02290d60;
}
extern "C" int func_ov031_0223e2e0(int, void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_0223da0c
extern "C" ARM void func_ov031_0223da0c(void) {
    func_ov031_0223e2e0(1, data_ov031_02290d60->payload);
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290d60);
}
