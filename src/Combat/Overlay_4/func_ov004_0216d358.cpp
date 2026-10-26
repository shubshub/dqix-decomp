#include <globaldefs.h>


extern "C" void func_ov004_0216afb0(void* obj, int a, int b, int c, int d, int e, int f, int g, int h);
extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);
extern "C" void* func_ov004_0216b1c4(void* a, int id);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);
extern "C" int func_ov004_0216b338(void* a, int id, int val);
extern "C" void func_ov004_0216b20c(void* a0, int key, int b, int c);
extern "C" void* func_ov011_021849c8(void*);

class Struct_ov004_0216d358 {
public:
    virtual void v00(); virtual void inline_ov004_0216d358_14(); virtual void inline_ov004_0216d358_15(); virtual void inline_ov004_0216d358_16();
    virtual void v04(); virtual void inline_ov004_0216d358_18(); virtual void inline_ov004_0216d358_19(); virtual void inline_ov004_0216d358_20();
    virtual void v08(); virtual void inline_ov004_0216d358_22(); virtual void v10(); virtual void inline_ov004_0216d358_24();
    virtual void inline_ov004_0216d358_25(); virtual void inline_ov004_0216d358_26(); virtual void v14(); virtual void inline_ov004_0216d358_28();
    virtual void inline_ov004_0216d358_29();
    virtual void inline_ov004_0216d358_30(int arg);
    virtual void v18(); virtual void inline_ov004_0216d358_32(); virtual void v20(); virtual void inline_ov004_0216d358_2();
    virtual void inline_ov004_0216d358_3(); virtual void inline_ov004_0216d358_4(); virtual void v24(); virtual void inline_ov004_0216d358_6();
    virtual void inline_ov004_0216d358_7(); virtual void inline_ov004_0216d358_8(); virtual void v28(); virtual void inline_ov004_0216d358_10();
    virtual void v30();
    virtual void inline_ov004_0216d358_12(int arg);
};
extern "C" Struct_ov004_0216d358* func_ov023_021f6880(void*, int);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;
extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216d358
extern "C" ARM int func_ov004_0216d358(void* a) {
#if defined(jpn)
    int v0c = *(int*)&data_ov004_02171034[0x10];
#else
    int v0c = *(int*)&data_ov004_02171034[0xc];
#endif

    func_ov004_0216afb0(a, 0x37, 2, 0xd4, 0x3a, 0xa, 0xa, 0xc, 1);
    v0c = func_ov004_0216b7bc(a, 0xd4, v0c, 1);
    func_ov004_0216b1c4(a, 0x12d);

    func_ov004_0216afb0(a, 0x38, 2, 0xd3, 0x3d, 0xa, 0x6, 0xc, 1);
    func_ov004_0216afb0(a, 0x39, 2, 0xd3, 0x3e, 0xa, 0x14, 0xc, 1);

    for (int i = 0; i < 2; i++) {
        func_ov004_0216b2c8(a, 0x12d, i + 0x38, i);
    }
    func_ov004_0216b338(a, 0x12d, 1);

    Struct_ov004_0216d358* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x38);
    if (node) {
        node->inline_ov004_0216d358_30(9);
        node->inline_ov004_0216d358_12(9);
    }

    func_ov004_0216b20c(a, 0x39, 0x64, 0);
    func_ov004_0216b7bc(a, 0xd3, v0c, 0);

    SePlayer_Play(&g_sePlayer, 5, 0);
    return 0;
}
