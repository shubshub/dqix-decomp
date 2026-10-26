#include <globaldefs.h>

extern "C" void func_ov004_0215482c(void*);
extern "C" void* func_ov004_02153944(void*, int);
extern "C" int func_ov023_021f809c(void*, void*);
struct Struct_ov004_02154984 { int v[3]; };
struct Struct_ov004_0216fa80 { Struct_ov004_02154984 unknown_0_; };
extern Struct_ov004_0216fa80 data_ov004_0216fa80;

// USA: func_ov004_02154984
extern "C" ARM int func_ov004_02154984(void* a) {
    func_ov004_0215482c(a);
    Struct_ov004_0216fa80 local;
    local.unknown_0_ = data_ov004_0216fa80.unknown_0_;
    int* kinds = local.unknown_0_.v;
    int i = 0;
    while (kinds[i] >= 0) {
        void* node = func_ov004_02153944(a, kinds[i]);
        if (node) {
            func_ov023_021f809c(node, a);
            i++;
        }
    }
    return 0;
}
