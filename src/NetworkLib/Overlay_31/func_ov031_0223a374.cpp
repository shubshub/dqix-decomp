#include <globaldefs.h>

struct Struct_ov031_0223a374 {
    int pad[0x10];
    int mode;
    int step;
};

typedef void (*Type_ov031_0223a374)(int, const char*, ...);

struct Struct_ov031_02290d18_27 {
    Type_ov031_0223a374 unknown_0_;
    Struct_ov031_0223a374* state;
};

extern Struct_ov031_02290d18_27 data_ov031_02290d18;
extern const char data_ov031_0224c4fc[];
extern const char data_ov031_0224c520[];

extern "C" void func_ov031_02239368(int);
extern "C" int func_ov031_02239a24();
extern "C" int func_ov031_02239a74();
extern "C" int func_ov031_0223a358();
extern "C" int func_ov031_02239924();
extern "C" int func_ov031_02239954();

// USA: func_ov031_0223a374
extern "C" ARM void func_ov031_0223a374(void) {
    int phase = data_ov031_02290d18.state->mode;
    if (phase == 1) {
        Type_ov031_0223a374 var1 = data_ov031_02290d18.unknown_0_;
        if (var1 != 0) {
            var1(0x8000000, data_ov031_0224c4fc);
        }
        return;
    }
    {
        Type_ov031_0223a374 var2 = data_ov031_02290d18.unknown_0_;
        if (var2 != 0) {
            var2(0x8000000, data_ov031_0224c520, phase);
        }
    }

    int mode = data_ov031_02290d18.state->mode;
    if (mode != 6 && mode != 5 && mode != 4) {
        func_ov031_02239368(3);
        func_ov031_0223a358();
        return;
    }
    func_ov031_02239368(3);
    switch (data_ov031_02290d18.state->step) {
    case 3:
        if (func_ov031_02239a24() == 0) {
            func_ov031_0223a358();
        }
        break;
    case 1:
    case 5:
        if (func_ov031_02239a74() == 0) {
            func_ov031_0223a358();
        }
        break;
    case 2:
        if (func_ov031_02239924() == 0) {
            func_ov031_0223a358();
        }
        break;
    case 0:
    case 4:
        if (func_ov031_02239954() == 0) {
            func_ov031_0223a358();
        }
        break;
    }
}
