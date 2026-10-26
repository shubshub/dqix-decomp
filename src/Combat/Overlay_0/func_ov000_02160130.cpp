#include <globaldefs.h>

struct Struct_ov000_02184220_2 {
    int flag;
    void* work;
};
extern struct Struct_ov000_02184220_2 data_ov000_02184220;

// USA: func_ov000_02160130
extern "C" ARM void* func_ov000_02160130(void) {
    return data_ov000_02184220.work;
}
