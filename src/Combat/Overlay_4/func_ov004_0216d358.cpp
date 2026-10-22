#include <globaldefs.h>


extern "C" void func_ov004_0216afb0(void* arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
extern "C" int func_ov004_0216b7bc(void* arg0, int arg1, int arg2, int arg3);
extern "C" void* func_ov004_0216b1c4(void* arg0, int arg1);
extern "C" int func_ov004_0216b2c8(void* arg0, int arg1, int arg2, int arg3);
extern "C" int func_ov004_0216b338(void* arg0, int arg1, int arg2);
extern "C" void func_ov004_0216b20c(void* arg0, int arg1, int arg2, int arg3);
extern "C" void* func_ov011_021849c8(void*);

class Struct_ov004_0216d358 {
public:
    virtual void inline_ov004_0216d358_13(); virtual void inline_ov004_0216d358_14(); virtual void inline_ov004_0216d358_15(); virtual void inline_ov004_0216d358_16();
    virtual void inline_ov004_0216d358_17(); virtual void inline_ov004_0216d358_18(); virtual void inline_ov004_0216d358_19(); virtual void inline_ov004_0216d358_20();
    virtual void inline_ov004_0216d358_21(); virtual void inline_ov004_0216d358_22(); virtual void inline_ov004_0216d358_23(); virtual void inline_ov004_0216d358_24();
    virtual void inline_ov004_0216d358_25(); virtual void inline_ov004_0216d358_26(); virtual void inline_ov004_0216d358_27(); virtual void inline_ov004_0216d358_28();
    virtual void inline_ov004_0216d358_29();
    virtual void inline_ov004_0216d358_30(int arg0);
    virtual void inline_ov004_0216d358_31(); virtual void inline_ov004_0216d358_32(); virtual void inline_ov004_0216d358(); virtual void inline_ov004_0216d358_2();
    virtual void inline_ov004_0216d358_3(); virtual void inline_ov004_0216d358_4(); virtual void inline_ov004_0216d358_5(); virtual void inline_ov004_0216d358_6();
    virtual void inline_ov004_0216d358_7(); virtual void inline_ov004_0216d358_8(); virtual void inline_ov004_0216d358_9(); virtual void inline_ov004_0216d358_10();
    virtual void inline_ov004_0216d358_11();
    virtual void inline_ov004_0216d358_12(int arg0);
};
extern "C" Struct_ov004_0216d358* func_ov023_021f6880(void*, int);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;
extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216d358
extern "C" ARM int func_ov004_0216d358(void* arg0) {
#if defined(jpn)
    int var0 = *(int*)&data_ov004_02171034[0x10];
#else
    int var0 = *(int*)&data_ov004_02171034[0xc];
#endif

    func_ov004_0216afb0(arg0, 0x37, 2, 0xd4, 0x3a, 0xa, 0xa, 0xc, 1);
    var0 = func_ov004_0216b7bc(arg0, 0xd4, var0, 1);
    func_ov004_0216b1c4(arg0, 0x12d);

    func_ov004_0216afb0(arg0, 0x38, 2, 0xd3, 0x3d, 0xa, 0x6, 0xc, 1);
    func_ov004_0216afb0(arg0, 0x39, 2, 0xd3, 0x3e, 0xa, 0x14, 0xc, 1);

    for (int var1 = 0; var1 < 2; var1++) {
        func_ov004_0216b2c8(arg0, 0x12d, var1 + 0x38, var1);
    }
    func_ov004_0216b338(arg0, 0x12d, 1);

    Struct_ov004_0216d358* var2 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x38);
    if (var2) {
        var2->inline_ov004_0216d358_30(9);
        var2->inline_ov004_0216d358_12(9);
    }

    func_ov004_0216b20c(arg0, 0x39, 0x64, 0);
    func_ov004_0216b7bc(arg0, 0xd3, var0, 0);

    SePlayer_Play(&g_sePlayer, 5, 0);
    return 0;
}
