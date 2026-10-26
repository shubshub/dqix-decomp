#include <globaldefs.h>

struct Struct_ov031_02234f08 {
    void* payload;
};

extern "C" Struct_ov031_02234f08* data_ov031_02290ce8;
namespace DuplicatePool {
    extern "C" Struct_ov031_02234f08* data_ov031_02290ce8;
}
extern "C" int func_ov031_0223e2e0(int, void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_02234f08
extern "C" ARM void func_ov031_02234f08(void) {
    func_ov031_0223e2e0(1, data_ov031_02290ce8->payload);
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290ce8);
}
