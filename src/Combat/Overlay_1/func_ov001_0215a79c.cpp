#include <globaldefs.h>

extern "C" void NNS_SndHandleInit(int* field);

struct Struct_ov001_021658b8 { char pad[0xe0]; int unknown_e0_; int unknown_e4_; int fieldE8; int unknown_ec_; char pad2[0x4b4 - 0xf0]; int unknown_4b4_; int unknown_4b8_; };
extern struct Struct_ov001_021658b8 data_ov001_021658b8;
extern int data_ov001_021659a8[0xe9];
extern int data_ov001_02165958[0x10];

// USA: func_ov001_0215a79c
extern "C" ARM void func_ov001_0215a79c(void) {
    data_ov001_021658b8.fieldE8 = 0;
    data_ov001_021658b8.unknown_ec_ = 0;
    data_ov001_021658b8.unknown_e0_ = 0;
    for (int i = 0; i < 0xe9; i++) {
        data_ov001_021659a8[i] = 0;
    }
    data_ov001_021658b8.unknown_e4_ = 0;
    for (int i = 0; i < 0x10; i++) {
        NNS_SndHandleInit(&data_ov001_02165958[i]);
    }
    data_ov001_021658b8.unknown_4b4_ = 0;
    data_ov001_021658b8.unknown_4b8_ = 0;
}
