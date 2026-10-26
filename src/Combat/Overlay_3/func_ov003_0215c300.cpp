#include <globaldefs.h>

struct Struct_ov003_02158e94_2 { char unk[0x598]; int counter; };

// USA: func_ov003_0215c300
#pragma optimize_for_size off
extern "C" ARM int func_ov003_0215c300(struct Struct_ov003_02158e94_2* obj, int amount) {
    if (obj->counter > amount) {
        obj->counter -= amount;
    } else {
        obj->counter = 0;
        return 0;
    }
    return 1;
}
