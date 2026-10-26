#include <globaldefs.h>

struct Struct_0201e828 {
    char pad[0x7e];
    short field7e;
};

// USA: func_0201e828
extern "C" ARM void func_0201e828(Struct_0201e828* p, unsigned short v) {
    p->field7e = v;
}
