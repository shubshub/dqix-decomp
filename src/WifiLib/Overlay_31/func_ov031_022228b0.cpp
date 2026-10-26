#include <globaldefs.h>


typedef void (*Type_ov031_022228b0)(int);

struct Struct_ov031_0224f670_19 {
    int pad[3];
    Type_ov031_022228b0 handler;
};

extern Struct_ov031_0224f670_19 data_ov031_0224f670;

// USA: func_ov031_022228b0
extern "C" THUMB void func_ov031_022228b0(int arg) {
    data_ov031_0224f670.handler(arg);
}
