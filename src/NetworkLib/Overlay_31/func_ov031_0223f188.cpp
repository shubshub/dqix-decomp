#include <globaldefs.h>

extern int data_ov031_02290dc4;
extern int data_ov031_02290dbc;
extern "C" void* func_ov031_0223fa0c(void);
extern "C" void func_ov031_0223fa20(void);
struct Struct_ov031_0223edb4;
extern "C" void func_ov031_0223edb4(void* p0, struct Struct_ov031_0223edb4* p1);
extern "C" int func_ov031_02240ee8(struct Struct_ov031_0223edb4* p1);

struct Struct_ov031_0223f188 { int field0; };

// USA: func_ov031_0223f188
extern "C" ARM int func_ov031_0223f188(Struct_ov031_0223f188* p0, struct Struct_ov031_0223edb4* p1) {
    func_ov031_0223fa0c();
    int r = func_ov031_02240ee8(p1);
    p0->field0 = r;
    data_ov031_02290dc4 = r;
    func_ov031_0223fa20();
    if (p0->field0 >= 0) {
        return 1;
    }
    func_ov031_0223edb4(p0, p1);
    data_ov031_02290dbc = 3;
    return 0;
}
