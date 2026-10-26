#include <globaldefs.h>

typedef int (*Type_020db894)(void);
extern Type_020db894 data_020f28fc[];

struct Struct_020db894 { char pad[0x5c]; int slots[2]; };

// USA: func_020db964
extern "C" ARM void func_020db964(struct Struct_020db894* obj) {
    int i;
    for (i = 0; i < 2; i++) {
        int result = data_020f28fc[i]();
        if (result != 0x10) {
            if (result != obj->slots[i]) {
                obj->slots[i] = result;
            }
        }
    }
}
