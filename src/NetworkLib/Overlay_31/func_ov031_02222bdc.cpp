#include <globaldefs.h>

struct Struct_ov031_0223da58;
struct Struct_ov031_02222bdc {
    void* payload;
    Struct_ov031_0223da58* unknown_4_;
};
extern "C" Struct_ov031_02222bdc* data_ov031_02250ba4;
namespace DuplicatePool {
    extern "C" Struct_ov031_02222bdc* data_ov031_02250ba4;
}
extern "C" int func_ov031_0223e2e0(int, void*);
extern "C" int func_ov031_0223da58(Struct_ov031_0223da58*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_02222bdc
extern "C" ARM void func_ov031_02222bdc(void) {
    func_ov031_0223e2e0(1, data_ov031_02250ba4->payload);
    func_ov031_0223da58(data_ov031_02250ba4->unknown_4_);
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02250ba4);
}
