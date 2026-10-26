#include <globaldefs.h>


typedef void (*Type_ov031_0221ecb4)(int);

struct Struct_ov031_0224f4c0_4 {
    int pad;
    Type_ov031_0221ecb4 handler;
};

extern Struct_ov031_0224f4c0_4 data_ov031_0224f4c0;

// USA: func_ov031_0221ecb4
extern "C" THUMB int func_ov031_0221ecb4(int arg) {
    Type_ov031_0221ecb4 handler = data_ov031_0224f4c0.handler;
    if (handler != NULL) {
        handler(arg);
    }
    return 0;
}
