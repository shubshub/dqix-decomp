#include <globaldefs.h>

struct S020a2c70 {
    char pad[0x2c4];
    unsigned char state;
    unsigned char flag;
};

// USA: func_020a2c70
extern "C" ARM int func_020a2c70(struct S020a2c70* p) {
    if (p->flag != 0) {
        p->state = 1;
        return 1;
    }
    return 0;
}
