#include <globaldefs.h>

struct Struct_ov000_02170c7c {
    char pad[8];
    short unknown_8_;
    short pad2;
    short unknown_c_;
};

// USA: func_ov000_02170c7c
extern "C" ARM int func_ov000_02170c7c(struct Struct_ov000_02170c7c* obj) {
    int result = 0;
    short var1 = obj->unknown_8_;
    if (var1 == 0) return 6;
    short var2 = obj->unknown_c_;
    float ratio = (float)var2 / (float)var1;
    if (ratio <= 0.0f) {
        result = 6;
    } else if (ratio <= 0.08f) {
        result = 5;
    } else if (ratio <= 0.25f) {
        result = 4;
    }
    return result;
}
