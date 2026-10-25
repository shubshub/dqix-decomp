#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_ov017_021acd7c(void* obj);
void InitCombatPairAndResetGlobal_021adb50(char* obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
struct Field3f8Struct;
Field3f8Struct* GetField0x3f8Address_0200fd0c(GameState* bs);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int length);
struct Struct_02038598_5;
extern "C" int func_02046b60(struct Struct_02038598_5* arg0, int arg1);
extern "C" void func_02046a8c(void* arg0, void* arg1);
extern "C" int func_020ac4f8(int arg0);
extern "C" void func_ov017_021d1118(int arg0, int arg1, int arg2, int arg3);

struct Struct_ov017_0219577c_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_[2];
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    signed char unknown_b_;
    unsigned char unknown_c_;
    unsigned char unknown_d_[3];
    Vector3i unknown_10_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    int unknown_2c_;
    unsigned char unknown_30_[0x35];
    unsigned char unknown_65_;
    unsigned char unknown_66_;
    unsigned char unknown_67_[5];
    short unknown_6c_;
};

struct Struct_ov017_0219577c {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown_3_[0x20c];
#else
    unsigned char unknown1_3_[0x27c];
#endif
    unsigned char unknown_27f_;
    unsigned char unknown_280_;
    unsigned char unknown_281_;
    unsigned char unknown_282_;
};

// USA: func_ov017_0219577c
extern "C" ARM void func_ov017_0219577c(unsigned char arg0, int arg1, int arg2) {
#if defined(jpn)
 enum {Enum_ov017_0219577c_1788=0x4ec,Enum_ov017_0219577c_2848=0x900,Enum_ov017_0219577c_3236=0xa84,Enum_ov017_0219577c_1804=0x4fc,Enum_ov017_0219577c_2968=0x978};
#else
 enum {Enum_ov017_0219577c_1788=0x6fc,Enum_ov017_0219577c_2848=0xb20,Enum_ov017_0219577c_3236=0xca4,Enum_ov017_0219577c_1804=0x70c,Enum_ov017_0219577c_2968=0xb98};
#endif
    GameState* gs = GameState::GetInstance();
    char* ctx = (char*)GetGameResources();
    void* list = *(void**)(ctx + 0x3000 + regionalList);
    Zone3D_GetInstance();
    Node0219577c* node = *(Node0219577c**)(ctx + 0x3000 + regionalNode);
    if (node->busy) return;

    func_ov017_021acd7c(var3);
    var3->unknown_280_ = 1;
    var3->unknown_27f_ = arg0;
    var3->unknown_281_ = arg1 == 0;
    var3->unknown_282_ = arg2 == 0;
    if (arg0 == 0 && arg2 != 0) {
        func_ov017_021adb50((char*)var3);
    }
    func_020469b4((struct Struct_0201bdac_2*)var2, (struct Struct_0201bdac*)var3);

    if (arg1) {
        Struct_ov017_0219577c_2* var4 = (Struct_ov017_0219577c_2*)func_0200fd0c(var0);
        VectorizedMemset(var4, 0, 0x70);
        var4->unknown_4_ = 1;
        var4->unknown_8_ = 1;
        var4->unknown_9_ = 1;
        var4->unknown_b_ = -1;
        var4->unknown_20_ = -1;
        var4->unknown_24_ = -1;
        var4->unknown_28_ = -1;
        var4->unknown_2c_ = -1;
        var4->unknown_1e_ = -1;
        var4->unknown_c_ = 0;
        var4->unknown_6c_ = -1;
        var4->unknown_2_ = 1;
        var4->unknown_0_ = 0xc3b5;
        var4->unknown_7_ = 1;
        var4->unknown_1c_ = 0;
        var4->unknown_10_.x = 0x48cc;
        var4->unknown_10_.y = 0x199;
        var4->unknown_10_.z = -0x733;
        var4->unknown_66_ = 1;
        var4->unknown_65_ = 1;

        if (func_02046b60((struct Struct_02038598_5*)var2, 0x4e)) {
            func_02046a8c(var2, *(void**)(var1 + 0x3000 + Enum_ov017_0219577c_3236));
        }
        if (func_02046b60((struct Struct_02038598_5*)var2, 3)) {
            func_02046a8c(var2, *(void**)(var1 + 0x3000 + Enum_ov017_0219577c_1804));
        }
    }
    if (func_02046b60((struct Struct_02038598_5*)var2, 0x40)) {
        func_02046a8c(var2, *(void**)(var1 + 0x3000 + Enum_ov017_0219577c_2968));
    }
    func_020ac4f8(1);
    if (arg0) {
        func_ov017_021d1118(-1, 1, 1, 2);
    }
}
