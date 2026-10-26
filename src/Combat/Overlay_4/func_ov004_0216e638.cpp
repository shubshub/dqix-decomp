#include <globaldefs.h>
#if defined(jpn)
enum { stateByteOffset = 0x7fb, Enum_ov004_0216e638_16 = 0xc, Enum_ov004_0216e638_2 = 0 };
#else
enum { stateByteOffset = 0x9ca, Enum_ov004_0216e638_16 = 0x10, Enum_ov004_0216e638_2 = 2 };
#endif
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_02012028(void* obj, unsigned char value);

struct Struct020a9ea4;
extern "C" void func_020a9ea4(struct Struct020a9ea4* p);
extern unsigned char data_ov004_02171034;

extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov004_0216afb0(void* a1, int p2, int p3, int p4,
    int p5, int p6, int p7, int p8, unsigned char p9);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);

extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
extern "C" int func_ov024_021f6f10(void* self);
#endif
extern "C" void* func_ov023_021f79e4(void* obj);
struct BackgroundGraphics;
extern "C" int Background_SetScroll(struct BackgroundGraphics* obj, int a, int b);

struct Struct_ov004_0216e638 { int x, y, z; };
class Struct_ov004_0216e638_2 {
public:
    virtual void v00(); virtual void inline_ov004_0216e638_2(); virtual void inline_ov004_0216e638_3(); virtual void inline_ov004_0216e638_4();
    virtual void v04(); virtual void inline_ov004_0216e638_6(); virtual void inline_ov004_0216e638_7(); virtual void inline_ov004_0216e638_8();
    virtual void v08(); virtual void inline_ov004_0216e638_10(); virtual void v10(); virtual void inline_ov004_0216e638_12();
    virtual void inline_ov004_0216e638_13(); virtual void inline_ov004_0216e638_14(); virtual void v14(); virtual void inline_ov004_0216e638_16();
    virtual void inline_ov004_0216e638_17(); virtual void inline_ov004_0216e638_18(); virtual void v18(); virtual void inline_ov004_0216e638_20();
    virtual void v20(); virtual void inline_ov004_0216e638_22(); virtual void inline_ov004_0216e638_23(); virtual void inline_ov004_0216e638_24();
    virtual void v24(); virtual void inline_ov004_0216e638_26(); virtual void inline_ov004_0216e638_27(); virtual void inline_ov004_0216e638_28();
    virtual void v28(); virtual void inline_ov004_0216e638_30(); virtual void v30(); virtual void inline_ov004_0216e638_32();
    virtual void inline_ov004_0216e638_33(); virtual void inline_ov004_0216e638_34(); virtual void v34(); virtual void inline_ov004_0216e638_36();
    virtual void inline_ov004_0216e638_37(); virtual void inline_ov004_0216e638_38(); virtual void v38(); virtual void inline_ov004_0216e638_40();
    virtual void v40(); virtual void inline_ov004_0216e638_42(); virtual void inline_ov004_0216e638_43(); virtual void inline_ov004_0216e638_44();
    virtual void v44(); virtual void inline_ov004_0216e638_46(); virtual void inline_ov004_0216e638_47(); virtual void inline_ov004_0216e638_48();
    virtual void v48(); virtual void inline_ov004_0216e638_50();
    virtual void inline_ov004_0216e638_51(Struct_ov004_0216e638*);
    virtual Struct_ov004_0216e638 inline_ov004_0216e638_52();
};

extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern unsigned char g_sePlayer;

// USA: func_ov004_0216e638
extern "C" ARM int func_ov004_0216e638(void* a) {
    void* self = a;
    *(unsigned char*)((char*)MessageSystem_GetInstance() + 0x1000 + stateByteOffset) = 0;
    func_02012028(GameState::GetInstance(), 0);

    func_020a9ea4(*(struct Struct020a9ea4**)((char*)&data_ov004_02171034 + Enum_ov004_0216e638_16));
    (&data_ov004_02171034)[Enum_ov004_0216e638_2] = 1;

    func_ov004_0216afb0(self, 0x4b0, 2, 0x3e8, 0x23, 0xc, 5, 0xa, 1);
    func_ov004_0216afb0(self, 0x4b1, 2, 0x3e8, 0x35, 0xc, 0x11, 0xa, 1);

    for (int i = 0; i < 2; i = i + 1) {
        func_ov004_0216b2c8(self, 0x44c, i + 0x4b0, i);
    }

    void* node = func_ov011_021849c8(self);
    for (int j = 0; j < 2; j = j + 1) {
        void* n1 = func_ov023_021f6880(node, j + 0x65);
        if (!n1) continue;
#if defined(jpn)
        if (func_ov023_021f6f10(n1) != 2) continue;
#else
        if (func_ov024_021f6f10(n1) != 2) continue;
#endif
        Background_SetScroll((struct BackgroundGraphics*)func_ov023_021f79e4(n1), 2, 4);

        void* n2 = func_ov023_021f6880(node, j + 0x4b0);
        if (!n2) continue;
#if defined(jpn)
        if (func_ov023_021f6f10(n2) != 8) continue;
#else
        if (func_ov024_021f6f10(n2) != 8) continue;
#endif

        Struct_ov004_0216e638 v = ((Struct_ov004_0216e638_2*)n2)->inline_ov004_0216e638_52();
        v.x = v.x - 0x2000;
        v.y = v.y - 0x4000;
        ((Struct_ov004_0216e638_2*)n2)->inline_ov004_0216e638_51(&v);

        *(short*)((char*)n2 + 0x30) = -2;
        *(short*)((char*)n2 + 0x32) = -4;
    }

    func_ov004_0216b7bc(self, 0x3e8, 0x60, 0);
    SePlayer_Play((struct SePlayer*)&g_sePlayer, 5, 0);
    return 0;
}
