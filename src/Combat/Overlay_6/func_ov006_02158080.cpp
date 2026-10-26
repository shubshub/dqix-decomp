#include <globaldefs.h>

struct Struct_0207fdcc_2;
struct Struct_0207fdcc;
extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" int func_02080c3c(struct Struct_0207fdcc_2* obj, int key);

// USA: func_ov006_02158080
extern "C" ARM int func_ov006_02158080(struct Struct_0207fdcc_2* obj, int key) {
    if (func_02081da8(obj, key) != NULL) {
        if (func_02080c3c(obj, key) != 0) {
            return 1;
        }
    }
    return 0;
}
