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
extern "C" Struct_02057a10* func_02057924();
extern "C" void* func_02010768(void* obj);
extern "C" void func_ov017_021a3dcc(int obj);
extern "C" void Zone3D_Draw(Zone3D* self);
extern "C" unsigned char func_0200fb9c(char* obj);
extern "C" int func_0201201c(void* gs);
extern "C" void MapDisplay_Draw(void* obj);
extern "C" Struct_0203dde0_2* func_0203cf4c();
extern "C" void func_0203de84(void* self);
extern "C" void func_0203dde0(Struct_0203dde0_2* obj);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int NSBXX_Model_GetMaterialPolygonID(NSBXXInternalModel* model, unsigned int materialIndex);
extern "C" void func_0208f87c(const void* self, int b, int c, int d, int polygonId);
extern "C" void func_02057a10(Struct_02057a10* c);
extern "C" void func_ov017_02196398(unsigned int* obj);
extern "C" void func_020a66a4(Struct_020a66a4_2* obj);
extern "C" void func_020aca30(Struct_020aca30* obj);
extern "C" void func_ov017_021b8420(void* obj);
extern "C" void func_ov017_021c164c(void* obj);
extern "C" void func_ov017_021b65d8(void* obj);
extern "C" void func_0208f820(Struct_0208f820* p);
extern "C" Struct_0208f410_3* func_0208e9e8();
extern "C" void func_0208f410(Struct_0208f410_3* obj);

struct Struct_ov017_02195bbc {
    unsigned int flags[2];
#if defined(jpn)
    char pad8[0x34c0 - 0x8];
    void* f36d0;
    char unknown_34c4_[0x34ec - 0x34c4];
    int nodeList;
    char unknown_34f0_[0x3508 - 0x34f0];
    unsigned char* unknown_3718_;
    char unknown_350c_[0x3930 - 0x350c];
    unsigned char* unknown_3b50_;
    char unknown_3934_[0x393c - 0x3934];
    unsigned char* unknown_3b5c_;
    char unknown_3940_[0x41d8 - 0x3940];
#else
    char pad8[0x36d0 - 0x8];
    void* f36d0;
    char unknown_36d4_[0x36fc - 0x36d4];
    int nodeList;
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
extern "C" ARM void func_ov017_02195bbc(Struct_ov017_02195bbc* self) {
    Zone3D* ctx;
    Zone3D* zone;
    Struct_02057a10* entries;
    GameState* gs;
    Zone3D** field5ca4;
    Struct_0203dde0_2* g;
    int polygonId;
    GameObject* monster;
    int i;
    unsigned short color;
    GameState* state;

    gs = GameState::GetInstance();
    zone = Zone3D_GetInstance();
    entries = func_02057924();
    field5ca4 = (Zone3D**)func_02010768(gs);

    if (IsScreenNotFullyFaded((GameResources*)self, false)) {
        func_ov017_021a3dcc(self->nodeList);
        if (TestFlags04((GameResources*)(self->flags), 2) == 0) {
            Zone3D_Draw(zone);
        }
    }
    if (func_0200fb9c((char*)gs) != 6 && func_0201201c(gs) != 5) {
        MapDisplay_Draw(self->f36d0);
    }
    if (IsScreenFullyFaded((GameResources*)self, false) != 0) {
        return;
    }

    GXFIFO_MATRIX_MODE = 3;
    GXFIFO_MATRIX_IDENTITY = 0;

    if (func_0200fb9c((char*)gs) != 6 && func_0201201c(gs) != 5 &&
        TestFlags04((GameResources*)(self->flags), 8) == 0) {
        g = func_0203cf4c();
        func_0203de84(g);
        func_0203dde0(g);
    }
    if (func_0200fb9c((char*)gs) == 6 || func_0201201c(gs) == 5) {
        return;
    }

    if (*field5ca4 != NULL) {
        Zone3D_Draw(*field5ca4);
    }

    if (TestFlags04((GameResources*)(self->flags), 0x100) == 0) {
        state = GameState::GetInstance();
        LinkSession_GetInstance();
        ctx = Zone3D_GetInstance();
        color = ctx->substruct_c_.unknown_2c_;
        for (i = 0xa0; i <= 0xbf; i++) {
            monster = state->GetWanderingMonsterByIndex(i);
            if (monster == NULL) continue;
            if (!monster->obj3D_.IsVisible()) continue;
            if (monster->obj3D_.GetFlag(0x10) != 0) continue;
            polygonId = 1;
            Model3D* model = monster->obj3D_.pModel_;
            if (model != NULL && model->rawInternalModel_ != NULL) {
                polygonId = NSBXX_Model_GetMaterialPolygonID(model->rawInternalModel_, 0);
            }
            const Vector3fix& pos = monster->obj3D_.MaybeGetShadowSource();
            func_0208f87c(&pos, color, 0x1000, ctx->substruct_c_.unknown_30_, polygonId);
        }
    }

    if (self->unknown_4488_ != 0 && TestFlags04((GameResources*)(self->flags), 0x20) == 0) {
        func_02057a10(entries);
    }
    func_ov017_02196398(self->flags);
    if (TestFlags04((GameResources*)(self->flags), 0x20000) == 0) {
        func_020a66a4((Struct_020a66a4_2*)self);
    }
    if (TestFlags04((GameResources*)(self->flags), 0x40000) == 0) {
        func_020aca30((Struct_020aca30*)self);
    }
    if (self->unknown_4488_ == 0 && TestFlags04((GameResources*)(self->flags), 0x20) == 0) {
        func_02057a10(entries);
    }
    if (self->unknown_3718_[3] != 0) {
        func_ov017_021b8420(self->unknown_3718_);
    }
    if (self->unknown_3b50_[3] != 0) {
        func_ov017_021c164c(self->unknown_3b50_);
    }
    if (self->unknown_3b5c_[3] != 0) {
        func_ov017_021b65d8(self->unknown_3b5c_);
    }
    if (TestFlags04((GameResources*)(self->flags), 2) == 0) {
        func_0208f820((Struct_0208f820*)zone->unk_2664);
    }
    LightingManager::GetInstance()->MaybeComputeHorizonPosition();
    func_0208f410(func_0208e9e8());
}
