#include <globaldefs.h>

extern "C" float func_ov017_021d6110(void*);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov001_02159168(void* node, int a, int b, int c, int d, int e, int f);

struct Struct_ov001_02165880_26 { char pad[0x24]; void* field24; };
extern Struct_ov001_02165880_26 data_ov001_02165880;

// USA: func_ov001_0215d684
extern "C" ARM int func_ov001_0215d684(void* self, int mode) {
    int a = (int)(4096.0f * func_ov017_021d6110(self));
    int b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    int c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    int e;
    void* dp = (char*)self + 0x18;
    self = (char*)self + 0x20;
    int d = func_ov017_021d60f4(dp);
    e = -1;
    if (mode >= 5) {
        e = func_ov017_021d60f4(self);
        self = (char*)self + 0x8;
    }
    int f = 0;
    if (mode >= 6) {
        f = (func_ov017_021d60f4(self) != 0) ? 1 : 0;
    }
    void* node = data_ov001_02165880.field24;
    func_ov001_02159168(node, a, b, c, d, e, f);
    return 1;
}
