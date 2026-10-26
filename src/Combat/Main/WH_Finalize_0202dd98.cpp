#include <globaldefs.h>
#if defined(jpn)
#define data_021023c0 data_02102100
#endif

struct Struct_021015a0_7 { char pad0[0x10]; int state_; char unknown_14_[0x34 - 0x14]; int mode_; };
struct Struct_021023c0 { char unknown_0_[0x820]; };
extern Struct_021015a0_7 data_021015a0;
extern Struct_021023c0 data_021023c0, data_02102be0;
extern "C" int func_0202d0b4();
extern "C" void WH_Reset();
extern "C" int func_020d68d0(void*);
extern "C" void func_0202c848(int);
extern "C" int func_0202d54c();
extern "C" int func_020d5f88(void*);
extern "C" int func_0202cca4();

static inline int inline_0202dd98() { return data_021015a0.state_; }

// Main, originally func_0202dd98 (USA 0x0202dd98, EUR 0x0202dda8, JPN 0x0202d908)
extern "C" ARM void WH_Finalize() {
    if (data_021015a0.state_ == 1) return;
    if (data_021015a0.state_ == 2) {
        if (!func_0202d0b4()) WH_Reset();
        return;
    }
    if (data_021015a0.state_ != 6 && data_021015a0.state_ != 5 && data_021015a0.state_ != 4) {
        data_021015a0.state_ = 3;
        WH_Reset();
        return;
    }
    data_021015a0.state_ = 3;
    switch (data_021015a0.mode_) {
    case 3: {
        int result;
        int state = inline_0202dd98();
        if (state != 6) result = 0;
        else {
            data_021015a0.state_ = state;
            int status = func_020d68d0(&data_021023c0);
            if (status) { func_0202c848(status); result = 0; }
            else if (!func_0202d54c()) result = 0;
            else result = 1;
        }
        if (!result) WH_Reset();
        break;
    }
    case 5:
        if (func_020d5f88(&data_02102be0)) { WH_Reset(); break; }
    case 1:
        if (!func_0202d54c()) WH_Reset();
        break;
    case 2: {
        int result;
        int status = func_020d68d0(&data_021023c0);
        if (status) { func_0202c848(status); result = 0; }
        else if (func_0202cca4()) result = 1;
        else { WH_Reset(); result = 0; }
        if (!result) WH_Reset();
        break;
    }
    case 4:
        if (func_020d5f88(&data_02102be0)) { WH_Reset(); break; }
    case 0:
        if (!func_0202cca4()) WH_Reset();
        break;
    }
}
