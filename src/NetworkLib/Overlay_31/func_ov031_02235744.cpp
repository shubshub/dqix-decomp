#include <globaldefs.h>

struct Struct_ov031_02235744 {
    void* field0;
    char pad0[0xc];
    unsigned short field10;
    unsigned short field12;
    char unknown_14_[6];
    unsigned char unknown_1a_;
};
extern Struct_ov031_02235744* data_ov031_02290cf4;
extern "C" void func_ov031_0223bbd8(void*, int, int, int);

// USA: func_ov031_02235744
extern "C" ARM void func_ov031_02235744(int a) {
    Struct_ov031_02235744* p = data_ov031_02290cf4;
    func_ov031_0223bbd8(p->field0, -1, p->field10, a + p->field12);
    data_ov031_02290cf4->unknown_1a_ = (unsigned char)a;
}
