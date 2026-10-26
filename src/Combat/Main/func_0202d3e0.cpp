#include <globaldefs.h>
#include "NitroSDK/RequestSubmission.h"

#if defined(jpn)
#define data_021023c0 data_02102100
#define data_020ef7a8 data_020ef698
#endif

struct Struct_0202d3e0 { unsigned short unknown_0_, unknown_2_, unknown_4_; };
struct Struct_021015a0_4 {
    char unknown_0_[0x10];
    int unknown_10_;
    int unknown_14_;
    void (*unknown_18_)(Struct_0202d3e0*);
    char unknown_1c_[0x34 - 0x1c];
    int unknown_34_;
};
extern Struct_021015a0_4 data_021015a0 __attribute__((aligned(4)));
struct Struct_021023c0;
extern Struct_021023c0 data_021023c0, data_02102be0;
extern int data_020ef7a8;
void SetField0x48UnlessState9Or10_0202c848(int);
extern "C" void WH_Finalize();

// USA: func_0202d3e0
extern "C" ARM void func_0202d3e0(Struct_0202d3e0* arg0) {
    if (arg0->unknown_2_ != 0) {
        if (arg0->unknown_2_ != 15 && arg0->unknown_2_ != 9 && arg0->unknown_2_ != 13) {
            func_0202c848(arg0->unknown_2_);
            data_021015a0.unknown_10_ = 9;
        }
    } else {
        switch (arg0->unknown_4_) {
        case 10:
            if (data_021015a0.unknown_34_ == 3) {
                if (data_021015a0.unknown_10_ == 6) break;
                if (data_021015a0.unknown_10_ == 4) {
                    int var0;
                    if (data_021015a0.unknown_10_ == 6) var0 = 1;
                    else if (data_021015a0.unknown_10_ != 4) var0 = 0;
                    else {
                        data_021015a0.unknown_10_ = 6;
                        int var1 = func_020d68b4(&data_021023c0, 13);
                        if (var1 == 0) var0 = 1;
                        else { func_0202c848(var1); var0 = 0; }
                    }
                    if (!submitted) WH_Finalize();
                    break;
                }
            } else if (data_021015a0.mode == 5) {
                int mask = 15;
                int result = func_020d5d34(&data_02102be0, 13, mask, 0x74, data_020ef7a8);
                if (result) {
                    SetField0x48UnlessState9Or10_0202c848(result);
                    WH_Finalize();
                } else {
                    data_021015a0.unknown_10_ = 5;
                    if (data_021015a0.unknown_18_) data_021015a0.unknown_18_(arg0);
                }
                break;
            }
            data_021015a0.unknown_10_ = 4;
            if (data_021015a0.unknown_18_) data_021015a0.unknown_18_(arg0);
            break;
        case 11:
        case 12:
        case 13:
            break;
        }
    }
}
