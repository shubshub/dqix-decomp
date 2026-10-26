#include <globaldefs.h>


typedef void (*Type_ov031_02220af0)(void*);

struct Struct_ov031_0224f670_21 {
    int pad[31];
    Type_ov031_02220af0 handler;
};

struct Struct_ov031_02222af0 {
    int a;
    int b;
    int c;
};

extern Struct_ov031_0224f670_21 data_ov031_0224f670;
extern "C" THUMB void func_ov031_02222aa4(Struct_ov031_02222af0* ctx);

// USA: func_ov031_02222af0
extern "C" THUMB void func_ov031_02222af0(void) {
    Struct_ov031_02222af0 ctx;
    func_ov031_02222aa4(&ctx);
    data_ov031_0224f670.handler(&ctx);
}
