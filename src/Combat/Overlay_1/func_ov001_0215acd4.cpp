#include <globaldefs.h>

struct Struct_ov001_02165880_8 { void* unused0; char* base; };
extern Struct_ov001_02165880_8 data_ov001_02165880;
extern "C" void func_ov001_0215acb4(void* entry);

// USA: func_ov001_0215acd4
extern "C" ARM void func_ov001_0215acd4(int idx) {
    char* base = data_ov001_02165880.base;
    if (base == NULL) return;
    func_ov001_0215acb4(base + (idx << 4));
}
