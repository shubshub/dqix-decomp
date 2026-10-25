#if defined(jpn)
enum { Enum_ov017_021cfb0c_14076 = 0x34ec, Enum_ov017_021cfb0c_15116 = 0x3afc };
#else
enum { Enum_ov017_021cfb0c_14076 = 0x36fc, Enum_ov017_021cfb0c_15116 = 0x3b0c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02015438;
struct Struct_02038598_5;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_0202c1a4;

struct Struct_ov017_021be40c {
    unsigned char unknown_0_[0x10];
    Vector3i unknown_10_;
    int unknown_1c_;
};

struct Struct_ov017_021cfb0c {
    unsigned char unknown_0_[0x14];
    int unknown_14_;
};

struct Struct_ov017_021cfb0c_2 {
    unsigned char unknown_0_[Enum_ov017_021cfb0c_14076];
    Struct_02015438** unknown_36fc_;
    unsigned char unknown_3700_[Enum_ov017_021cfb0c_15116 - 0x3700];
    struct Struct_ov017_021cfb0c* unknown_3b0c_;
    unsigned char unknown_3b10_[0x3ca4 - 0x3b10];
    struct Struct_ov017_021be40c* unknown_3ca4_;
};

struct Struct_ov017_021cfb0c_3 {
    unsigned char unknown_0_[0xc];
    int unknown_c_;
    Vector3i unknown_10_;
};

extern "C" int func_0202c508(struct SearchStruct0202c1a4* search);
extern "C" unsigned short* Zone3D_GetInstance(void);
void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** list);
int IsInRange0201b588(int v);
int ListContainsId(ListHead02046b60* list, int id);
void InitObj021be40c(struct Obj021be40c* obj);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021cfb0c
extern "C" ARM void func_ov017_021cfb0c(int arg0, void* arg1, GameState* arg2, struct Struct_ov017_021cfb0c_2* arg3, struct Struct_0202c1a4* arg4) {
    int var0;
    unsigned short* var1;
    struct Struct_ov017_021cfb0c_3* var2;
    unsigned short var3;
    Struct_02015438** var4;
    unsigned short* var5;
    struct Struct_ov017_021be40c* var6;

    if (func_0202c508(arg4) != 0) {
        return;
    }

    zone = Zone3D_GetInstance();
    battleStruct->GetUnknownGameObject();
    zoneId = *zone;
    grotto = (struct GrottoEntrance021cfb0c*)battleStruct->GetGrottoStruct();
    list = ov->list;
    flag = 0;
    cur = (unsigned short*)GetField0x3f8Address_0200fd0c(battleStruct);
    if (GetHeadNodeIdOrMinusOne(list) == 3) {
        if (IsInRange0201b588(*cur)) {
            flag = 1;
        }
    }
    if (!func_0201b588(var3) && !var0) {
        return;
    }

    Vector3i var7 = var2->unknown_10_;
    var7.z += 0x2000;
    if (func_02046b60((Struct_02038598_5*)var4, 3) || func_02046b60((Struct_02038598_5*)var4, 1)) {
        unsigned short var8 = *(unsigned short*)func_0200fd0c(arg2);
        if (var8 == 0xc3b5) {
            return;
        }
        if (!func_0201b588(var8)) {
            return;
        }
    }

    if (func_02046b24(var4) == 0x1a) {
        if (arg3->unknown_3b0c_->unknown_14_ >= 6) {
            return;
        }
    }
    if (func_02046b60((Struct_02038598_5*)var4, 0x4e)) {
        return;
    }

    var6 = arg3->unknown_3ca4_;
    func_ov017_021be40c(var6);
    var6->unknown_10_ = var7;
    var6->unknown_1c_ = var2->unknown_c_;
    func_020469b4((Struct_0201bdac_2*)var4, (Struct_0201bdac*)var6);
}
