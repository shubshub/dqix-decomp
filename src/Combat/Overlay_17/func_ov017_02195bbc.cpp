#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/Graphics.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"

struct Struct_0203dde0_2;
struct Struct_02057a10;
struct Struct_020a66a4_2;
struct Struct_020aca30;
struct Struct_0208f820;
struct Struct_0208f410_3;

extern "C" Zone3D* Zone3D_GetInstance();
extern "C" Container02057a10* func_02057924();
void* GetFieldPtrAt0x5ca4_02010768(void* obj);
void ForwardObjAndField0_021a3dcc(int obj);
extern "C" void func_02016874(Zone3D* self);
unsigned char GetByte0x4_0200fb9c(char* obj);
int GetWord0x7f6c_0201201c(void* gs);
extern "C" void func_0202343c(void* obj);
Obj0203dde0* GetGlobalPtr021075f4_0203cf4c();
extern "C" void func_0203de84(void* self);
void UpdateEntrySubObjects0203dde0(Obj0203dde0* obj);
extern "C" void* func_0202ae18(void);
extern "C" int NSBXX_Model_GetMaterialPolygonID(NSBXXInternalModel* model, unsigned int materialIndex);
extern "C" void func_0208f87c(const void* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_02057a10(Struct_02057a10* arg0);
extern "C" void func_ov017_02196398(unsigned int* arg0);
extern "C" void func_020a66a4(Struct_020a66a4_2* arg0);
extern "C" void func_020aca30(Struct_020aca30* arg0);
extern "C" void func_ov017_021b8420(void* arg0);
extern "C" void func_ov017_021c164c(void* arg0);
extern "C" void func_ov017_021b65d8(void* arg0);
extern "C" void func_0208f820(Struct_0208f820* arg0);
extern "C" Struct_0208f410_3* func_0208e9e8();
extern "C" void func_0208f410(Struct_0208f410_3* arg0);

struct Struct_ov017_02195bbc {
    unsigned int unknown_0_[2];
#if defined(jpn)
    char unknown_8_[0x34c0 - 0x8];
    void* unknown_36d0_;
    char unknown_34c4_[0x34ec - 0x34c4];
    int unknown_36fc_;
    char unknown_34f0_[0x3508 - 0x34f0];
    unsigned char* unknown_3718_;
    char unknown_350c_[0x3930 - 0x350c];
    unsigned char* unknown_3b50_;
    char unknown_3934_[0x393c - 0x3934];
    unsigned char* unknown_3b5c_;
    char unknown_3940_[0x41d8 - 0x3940];
#else
    char unknown1_8_[0x36d0 - 0x8];
    void* unknown_36d0_;
    char unknown_36d4_[0x36fc - 0x36d4];
    int unknown_36fc_;
    char unknown_3700_[0x3718 - 0x3700];
    unsigned char* unknown_3718_;
    char unknown_371c_[0x3b50 - 0x371c];
    unsigned char* unknown_3b50_;
    char unknown_3b54_[0x3b5c - 0x3b54];
    unsigned char* unknown_3b5c_;
    char unknown_3b60_[0x4488 - 0x3b60];
#endif
    unsigned char unknown_4488_;
};

// USA: func_ov017_02195bbc
extern "C" ARM void func_ov017_02195bbc(Struct_ov017_02195bbc* arg0) {
    Zone3D* var0;
    Zone3D* var1;
    Struct_02057a10* var2;
    GameState* var3;
    Zone3D** var4;
    Struct_0203dde0_2* var5;
    int var6;
    GameObject* var7;
    int var8;
    unsigned short var9;
    GameState* var10;

    gs = GameState::GetInstance();
    zone = Zone3D_GetInstance();
    entries = func_02057924();
    field5ca4 = (Zone3D**)GetFieldPtrAt0x5ca4_02010768(gs);

    if (IsBrightnessWithinValidRange((GameResources*)arg0, false)) {
        func_ov017_021a3dcc(arg0->unknown_36fc_);
        if (TestFlags04((GameResources*)(arg0->unknown_0_), 2) == 0) {
            func_02016874(var1);
        }
    }
    if (func_0200fb9c((char*)var3) != 6 && func_0201201c(var3) != 5) {
        func_0202343c(arg0->unknown_36d0_);
    }
    if (IsBrightnessOutsideValidRange((GameResources*)arg0, false) != 0) {
        return;
    }

    GXFIFO_MATRIX_MODE = 3;
    GXFIFO_MATRIX_IDENTITY = 0;

    if (func_0200fb9c((char*)var3) != 6 && func_0201201c(var3) != 5 &&
        TestFlags04((GameResources*)(arg0->unknown_0_), 8) == 0) {
        var5 = func_0203cf4c();
        func_0203de84(var5);
        func_0203dde0(var5);
    }
    if (func_0200fb9c((char*)var3) == 6 || func_0201201c(var3) == 5) {
        return;
    }

    if (*var4 != NULL) {
        func_02016874(*var4);
    }

    if (TestFlags04((GameResources*)(arg0->unknown_0_), 0x100) == 0) {
        var10 = GameState::GetInstance();
        func_0202ae18();
        ctx = Zone3D_GetInstance();
        color = ctx->substruct_c_.unknown_2c_;
        for (i = 0xa0; i <= 0xbf; i++) {
            monster = state->GetMaybeWanderingMonsterByIndex(i);
            if (monster == NULL) continue;
            if (!monster->obj3D_.IsVisible()) continue;
            if (monster->obj3D_.GetFlag(0x10) != 0) continue;
            polygonId = 1;
            Model3D* model = monster->obj3D_.pModel_;
            if (model != NULL && model->rawInternalModel_ != NULL) {
                polygonId = NSBXX_Model_GetMaterialPolygonID(model->rawInternalModel_, 0);
            }
            const Vector3fix& var12 = var7->obj3D_.MaybeGetShadowSource();
            func_0208f87c(&var12, var9, 0x1000, var0->substruct_c_.unknown_30_, var6);
        }
    }

    if (arg0->unknown_4488_ != 0 && TestFlags04((GameResources*)(arg0->unknown_0_), 0x20) == 0) {
        func_02057a10(var2);
    }
    func_ov017_02196398(arg0->unknown_0_);
    if (TestFlags04((GameResources*)(arg0->unknown_0_), 0x20000) == 0) {
        func_020a66a4((Struct_020a66a4_2*)arg0);
    }
    if (TestFlags04((GameResources*)(arg0->unknown_0_), 0x40000) == 0) {
        func_020aca30((Struct_020aca30*)arg0);
    }
    if (arg0->unknown_4488_ == 0 && TestFlags04((GameResources*)(arg0->unknown_0_), 0x20) == 0) {
        func_02057a10(var2);
    }
    if (arg0->unknown_3718_[3] != 0) {
        func_ov017_021b8420(arg0->unknown_3718_);
    }
    if (arg0->unknown_3b50_[3] != 0) {
        func_ov017_021c164c(arg0->unknown_3b50_);
    }
    if (arg0->unknown_3b5c_[3] != 0) {
        func_ov017_021b65d8(arg0->unknown_3b5c_);
    }
    if (TestFlags04((GameResources*)(arg0->unknown_0_), 2) == 0) {
        func_0208f820((Struct_0208f820*)var1->unk_2664);
    }
    LightingManager::GetInstance()->MaybeComputeHorizonPosition();
    func_0208f410(func_0208e9e8());
}
