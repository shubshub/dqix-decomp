#include <globaldefs.h>
#include "GameState/GameState.h"

int MessageSystem_GetInstance(void);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;
void SetByte0x7f70_02012028(void* obj, unsigned char value);
struct Struct020a9ea4;
void ClearStruct020a9ea4(struct Struct020a9ea4* p);
extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);

struct Struct_ov004_02171034_3 {
#if defined(jpn)
#else
    unsigned char unknown_0_[2];
#endif
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown_1_[4];
#else
#endif
    unsigned char unknown_3_;
#if defined(jpn)
    unsigned char unknown_6_[6];
#else
    unsigned char unknown_4_[0xc];
#endif
    struct Struct_020a9ea4* unknown_10_;
};
extern struct Struct_ov004_02171034_3 data_ov004_02171034;

// USA: func_ov004_0216d004
extern "C" ARM int func_ov004_0216d004(void* a) {
    char* g = (char*)MessageSystem_GetInstance();
#if defined(jpn)
    var0[0x1000 + 0x7fb] = 0;
#else
    var0[0x1000 + 0x9ca] = 0;
#endif
    SePlayer_Play(&g_sePlayer, 5, 0);

    func_02012028((void*)GameState::GetInstance(), 0);
    func_020a9ea4(data_ov004_02171034.unknown_10_);
    data_ov004_02171034.unknown_2_ = 1;

    if (data_ov004_02171034.unknown_3_ == 4) {
        func_ov004_0216afb0(arg0, 0x38, 2, 0xd3, 0x3d, 0xc, 0x6, 0xc, 1);
        func_ov004_0216afb0(arg0, 0x39, 2, 0xd3, 0x3e, 0xc, 0x14, 0xc, 1);
    } else {
        func_ov004_0216afb0(arg0, 0x38, 2, 0xd3, 0x23, 0xa, 0x6, 0xa, 1);
        func_ov004_0216afb0(arg0, 0x39, 2, 0xd3, 0x35, 0xa, 0x14, 0xa, 1);
    }

    for (int var1 = 0; var1 < 2; var1++) {
        func_ov004_0216b2c8(arg0, 0x12d, var1 + 0x38, var1);
    }
    func_ov004_0216b7bc(arg0, 0xd3, 0x60, 0);
    return 0;
}
