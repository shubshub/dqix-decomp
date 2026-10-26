#include <globaldefs.h>

extern "C" int func_ov031_02206f3c(int a, int b);

struct Struct_ov031_0224c9e0_3 {
    int first;
    int second;
};
extern Struct_ov031_0224c9e0_3 data_ov031_0224c9e0;

// USA: func_ov031_02206f08
extern "C" ARM int func_ov031_02206f08(int a, int b) {
    if (func_ov031_02206f3c(a, b) == 0) {
        return ~0x26;
    }
    data_ov031_0224c9e0.first = a;
    data_ov031_0224c9e0.second = b;
    return 0;
}
