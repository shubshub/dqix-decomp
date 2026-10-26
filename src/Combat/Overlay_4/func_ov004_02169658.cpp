#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov023_021f6600 func_ov004_02168ed8
#define func_ov023_021f6680 func_ov004_02168fa4
#endif

struct Struct_ov004_02153e20;
struct Struct_ov004_021700e0 { int unknown_0_, unknown_4_, unknown_8_; };

class Struct_ov004_02169658_3 {
public:
    char unknown_4_[0x8];
    unsigned char unknown_c_;
    char unknown_d_[0x13];
    void* unknown_20_;

    virtual void inline_ov004_02169658_12();
    virtual void inline_ov004_02169658_13();
    virtual void inline_ov004_02169658_14();
    virtual void inline_ov004_02169658_15();
    virtual void inline_ov004_02169658_16();
    virtual void inline_ov004_02169658_17();
    virtual void inline_ov004_02169658_18();
    virtual void inline_ov004_02169658_19(struct Struct_ov004_021700e0* arg0);
    virtual void inline_ov004_02169658_20();
    virtual void inline_ov004_02169658_21();
    virtual void inline_ov004_02169658_22();
    virtual void inline_ov004_02169658_23();
    virtual void inline_ov004_02169658_24();
    virtual void inline_ov004_02169658_25();
    virtual void inline_ov004_02169658_26();
    virtual void inline_ov004_02169658_27();
    virtual void inline_ov004_02169658_28();
    virtual void inline_ov004_02169658_29(int arg0);
    virtual void inline_ov004_02169658_30();
    virtual void inline_ov004_02169658_31(int arg0);
    virtual void inline_ov004_02169658_32();
    virtual void inline_ov004_02169658(int arg0);
    virtual void inline_ov004_02169658_2();
    virtual void inline_ov004_02169658_3();
    virtual void inline_ov004_02169658_4();
    virtual void inline_ov004_02169658_5();
    virtual void inline_ov004_02169658_6();
    virtual void inline_ov004_02169658_7();
    virtual void inline_ov004_02169658_8();
    virtual void inline_ov004_02169658_9();
    virtual void inline_ov004_02169658_10();
    virtual void inline_ov004_02169658_11(int arg0);
};

struct Struct_ov004_02169658 {
    #if defined(jpn)
 char unknown_0_[0x18];
#else
 char unknown1_0_[0x198];
#endif
    unsigned char unknown_198_;
};

struct Struct_ov004_02169658_2 {
    char unknown_0_[0x1be];
    short unknown_1be_;
};

extern "C" unsigned char* func_02053c6c(unsigned char* arg0);
extern "C" Struct_ov004_02169658_3* func_ov023_021f6524(void* arg0, int arg1);
extern "C" Struct_ov004_02169658_3* func_ov004_02168a6c(void* arg0, int arg1);
extern "C" Struct_ov004_02169658_3* func_ov004_02168a38(void* arg0, int arg1);
extern "C" Struct_ov004_02169658_3* func_ov004_02168ad4(void* arg0, int arg1);
extern "C" int func_ov023_021f9b30(struct Struct_ov004_02153e20* arg0, unsigned short arg1, unsigned int arg2, unsigned int arg3);
#if defined(jpn)
extern "C" void func_ov004_02168ed8(void* arg0, int arg1, int arg2);
#else
extern "C" void func_ov023_021f6600(void* arg0, int arg1, int arg2);
#endif
extern "C" void func_ov023_021f9ba8(void* arg0, int arg1);
#if defined(jpn)
extern "C" void* func_ov004_02168fa4(void*, int);
extern "C" void func_ov023_021f809c(void*, void*);
#else
extern "C" int func_ov023_021f6680(void* arg0, int arg1);
#endif
extern "C" void func_ov004_02169b4c(void* arg0);

extern struct Struct_ov004_021700e0 data_ov004_021700e0;
extern struct Struct_ov004_02169658* data_ov004_02171030;

// USA: func_ov004_02169658
extern "C" ARM int func_ov004_02169658(struct Scene02169658* scene) {
    unsigned char* base = GetFieldAt0x150_02053c6c((unsigned char*)GameState::GetInstance()->GetLeader()) + 0x3c;
    Node02169658* grid = func_ov023_021f6524(scene, 0x64);
    int i;
    for (i = 0; i < 8; i++) {
        Node02169658* a = GetNodeIfType8_02168a6c(scene, i + 0xc8);
        Node02169658* b = GetNodeIfType8_02168a6c(scene, i + 0xd8);
        Node02169658* c = GetNodeIfType15_02168a38(scene, i + 0xd0);
        Node02169658* d = GetNodeIfType15_02168a38(scene, i + 0xe0);
        if (i == 0) {
            a->f20 = base;
            a->flags &= ~8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((struct Grid021f9b30*)grid, (unsigned short)(i + 0xc8), (unsigned short)i, 0);
            a->SetVisible(0);
        } else {
            var3->unknown_c_ |= 8;
            func_ov023_021f9b30((struct Struct_ov004_02153e20*)var1, 0, (unsigned short)var2, 0);
            var3->inline_ov004_02169658_31(0);
        }
        var4->unknown_c_ |= 8;
        var5->unknown_c_ |= 8;
        var6->unknown_c_ |= 8;
    }
    func_ov023_021f6600(arg0, 2, 8);
    func_ov023_021f9ba8(var1, 0);
    func_ov023_021f6600(arg0, 0x14, 4);
#if defined(jpn)
    void* var7 = func_ov004_02168fa4(arg0, 0x14);
    if (var7) func_ov023_021f809c(var7, arg0);
#else
    func_ov023_021f6680(arg0, 0x14);
#endif
    var1->inline_ov004_02169658(0);
    Struct_ov004_02169658_3* var8 = func_ov004_02168a6c(arg0, 0xc8);
    var8->inline_ov004_02169658_29(0);
    var8->inline_ov004_02169658_11(0);
    Struct_ov004_02169658_3* var9 = func_ov004_02168ad4(arg0, 2);
    struct Struct_ov004_021700e0 var10 = data_ov004_021700e0;
    var9->inline_ov004_02169658_19(&var10);
    data_ov004_02171030->unknown_198_ = 1;
    func_ov004_02169b4c(arg0);
    arg0->unknown_1be_ = 0;
    return 0;
}
