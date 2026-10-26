#include <globaldefs.h>

struct Struct_ov001_02158ab8;
extern "C" int func_ov001_02158ab8(struct Struct_ov001_02158ab8* obj);
extern "C" void func_ov017_021d6134(void*, int);

struct Struct_ov001_02165880_19 { char pad[0x24]; struct Struct_ov001_02158ab8* p; };
extern struct Struct_ov001_02165880_19 data_ov001_02165880;

// USA: func_ov001_0215d168
extern "C" ARM int func_ov001_0215d168(void* obj) {
    int r = func_ov001_02158ab8(data_ov001_02165880.p);
    func_ov017_021d6134(obj, r == 0 ? 1 : 0);
    return 1;
}
