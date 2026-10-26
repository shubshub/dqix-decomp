#include <globaldefs.h>

struct S_e830 {
    char pad[0x7e];
    unsigned short field7e;
};

// USA: func_0201e830
extern "C" ARM int func_0201e830(struct S_e830* p) {
    return p->field7e;
}
