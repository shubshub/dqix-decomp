#include <globaldefs.h>
#if defined(jpn)
#define data_02109cc4 data_0210997c
#define data_020f1758 data_020f18c0
#endif
#include "std_library_functions.h"

struct Struct_020f1758 {
    int key;
    int index;
};

extern int data_02109cc4[49];
extern struct Struct_020f1758 data_020f1758;

extern "C" void func_ov017_021d4cc0(void*, int*, int);

// USA: func_0209dc4c
extern "C" ARM void func_0209dc4c(void* obj) {
    memset(data_02109cc4, 0, sizeof(data_02109cc4));

    for (struct Struct_020f1758* e = &data_020f1758; e != NULL; e++) {
        if (e->key == 0) {
            break;
        }
        if (e->index >= 0 && e->index < 49) {
            if (data_02109cc4[e->index] != 0) {
                for (;;) {}
            } else {
                data_02109cc4[e->index] = e->key;
            }
        }
    }

    func_ov017_021d4cc0(obj, data_02109cc4, 49);
}
