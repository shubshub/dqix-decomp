#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_02012028(void* arg0, unsigned char arg1);
extern "C" void func_ov004_0216afb0(void* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
extern "C" int func_ov004_0216b7bc(void* arg0, int arg1, int arg2, int arg3);
extern "C" void* func_ov004_0216b1c4(void* arg0, int arg1);
extern "C" int func_ov004_0216b2c8(void* arg0, int arg1, int arg2, int arg3);
extern "C" int func_ov004_0216b338(void* arg0, int arg1, int arg2);
extern "C" void func_ov004_0216b20c(void* arg0, int arg1, int arg2, int arg3);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;
extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216d1c4
extern "C" ARM int func_ov004_0216d1c4(void* arg0) {
    func_02012028(GameState::GetInstance(), 0);
#if defined(jpn)
    int var0 = *(int*)&data_ov004_02171034[0x10];
#else
    int var0 = *(int*)&data_ov004_02171034[0xc];
#endif

    func_ov004_0216afb0(arg0, 0x37, 2, 0xd4, 0x39, 0xa, 0xa, 0xc, 1);
    var0 = func_ov004_0216b7bc(arg0, 0xd4, var0, 1);
    func_ov004_0216b1c4(arg0, 0x12d);

    func_ov004_0216afb0(arg0, 0x38, 2, 0xd3, 0x3d, 0xa, 0x6, 0xc, 1);
    func_ov004_0216afb0(arg0, 0x39, 2, 0xd3, 0x3e, 0xa, 0x14, 0xc, 1);

    for (int var1 = 0; var1 < 2; var1++) {
        func_ov004_0216b2c8(arg0, 0x12d, var1 + 0x38, var1);
    }
    func_ov004_0216b338(arg0, 0x12d, 1);

    func_ov004_0216b20c(arg0, 0x38, 0x97, 0);
    func_ov004_0216b20c(arg0, 0x39, 0x64, 0);
    func_ov004_0216b7bc(arg0, 0xd3, var0, 0);

    SePlayer_Play(&g_sePlayer, 5, 0);
    return 0;
}
