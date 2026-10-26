#include <globaldefs.h>

extern "C" void func_01ff8000(void);

struct Struct_ov031_0220f2e0 {
    unsigned char pad0[8];
    void *field8;
    int counter;
};

// USA: func_ov031_0220f2e0
extern "C" ARM int func_ov031_0220f2e0(struct Struct_ov031_0220f2e0 *obj) {
    if (obj->field8 == NULL) {
        obj->field8 = (void *)func_01ff8000;
        obj->counter++;
        return 1;
    }
    if (obj->field8 != (void *)func_01ff8000) {
        return 0;
    }
    obj->counter++;
    return 1;
}
