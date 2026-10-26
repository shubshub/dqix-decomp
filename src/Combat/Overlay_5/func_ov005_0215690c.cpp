#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include "Resource/GameResources.h"


struct SePlayer;
struct Vec3copy0202ec84;
struct Struct_02052df8;

struct Struct_ov005_0215690c_2 {
    char unk_0[0x50];
    Vector3fix rotation_;
};

struct MemberScreen {
#if defined(jpn)
    char unk_0[0x4f8];
#else
    char unk_0[0x4fc];
#endif
    int member_;
#if defined(jpn)
    char unknown1_4fc_[0x56c - 0x4fc];
#else
    char unknown_500_[0x634 - 0x500];
#endif
    unsigned short flags_;
};

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct EquipmentMenu {
#if defined(jpn)
    char unk_0[0x196c];
#else
    char unk_0[0x19f4];
#endif
    char cursor_[0x2d90 - 0x19f4];
    Struct_ov005_02153ba4 slots_[24];
    char slotModels_[0x3d78 - 0x3030];
    short dragged_;
    char unknown_3d7a_[0x3d98 - 0x3d7a];
    short unknown_3d98_[8];
    unsigned char unknown_3da8_;
    unsigned char unknown_3da9_;
    unsigned char unknown_3daa_;
    char unknown_3dab_[0x3db8 - 0x3dab];
    unsigned char state_;
    unsigned char unknown_3db9_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    signed char unknown_3dc0_;
    char unknown_3dc1_[0x3dcc - 0x3dc1];
    unsigned int flags_;
    char unknown_3dd0_[0x3dfc - 0x3dd0];
    unsigned char pages_[8];
};

#if defined(jpn)
#define data_ov005_0215cc84 data_ov005_0215e064
#define data_ov005_0215cc14 data_ov005_0215dff4
#define data_ov005_0215cd58 data_ov005_0215e138
#define data_ov005_0215cd50 data_ov005_0215e130
#endif

extern const Vector3fix data_ov005_0215cc84[8];
extern const signed char data_ov005_0215cc14[8];
extern unsigned char data_ov005_0215cd58[8];
extern unsigned char data_ov005_0215cd50[8];
extern int g_sePlayer;

extern "C" MemberScreen* func_ov017_021a193c(int* p);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
struct Obj021e4e20;
extern "C" Struct_ov005_0215690c_2* func_ov023_021e4e20(Obj021e4e20*);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);
extern "C" int Camera_WorldToScreen(void* obj, Vec3copy0202ec84* src, int* out1, int* out2);
extern "C" GameObject* func_0200ff1c(GameState* gs, int id);
extern "C" double sqrt(double x);
extern "C" short func_02052df8(Struct_02052df8* obj, int index);
extern "C" int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" void* GameState_GetParty(GameState* gs);
extern "C" short* func_0207c5f8(unsigned char* obj, unsigned int index);
extern "C" void GridCursor_SetSelectedIndex(void* cursor, int index);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);

// USA: func_ov005_0215690c
extern "C" ARM void func_ov005_0215690c(EquipmentMenu* self, int x, int y) {
    GameState* gameState;
    Struct_ov005_0215690c_2* body;
    gameState = GameState::GetInstance();
    unsigned char page;
    MemberScreen* screen = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
    unsigned int member = screen->member_;
    if (!func_ov005_02157ae8(self, member))
        return;
    body = func_ov023_021e4e20((Obj021e4e20*)screen);
    func_ov005_02155670(self, x, y);
    short item = -1;
    unsigned char kind = 0xff;
    if (x > 0 && x < 0x80) {
        int screenX[8];
        void* camera;
        int dx;
        int screenY[8];
        camera = gameState->GetCamera();
        int count;
        Matrix4x3 matrix;
        Vector3fix positions[8];
        matrix = RotationMatrixY(body->rotation_.y);
        for (int i = 0; i < 8; i++) {
            Mat4x3_ApplyToVector(&data_ov005_0215cc84[i], &matrix, &positions[i]);
            Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&positions[i], &screenX[i], &screenY[i]);
        }
        GameObject* partyMember = func_0200ff1c(gameState, member);
        count = 0;
        float radii[8];
        int touched[8];
        for (int i = 0; i < 8; i++) {
            radii[i] = 20.0f;
            int dy = y - screenY[i];
            int dx = x - screenX[i];
            if ((float)sqrt(dx * dx + dy * dy) < radii[i])
                touched[count++] = i;
        }
        if (count > 0) {
            int var21 = 0;
            int found = 0;
            int equipped[8];
            for (int i = 0; i < count; i++) {
                int part = touched[i];
                if (func_02052df8((Struct_02052df8*)partyMember, data_ov005_0215cc14[part]) > 0) {
                    equipped[var21] = part;
                    found = 1;
                    var21++;
                }
            }
            if (found) {
                int best = equipped[0];
                int var27 = positions[best].z;
                for (int i = 1; i < var21; i++) {
                    int part = equipped[i];
                    if (var27 < positions[part].z) {
                        best = part;
                        var27 = positions[part].z;
                    }
                }
                kind = data_ov005_0215cd58[best];
                item = func_02052df8((Struct_02052df8*)partyMember, data_ov005_0215cc14[best]);
            } else {
                int best = touched[0];
                int var31 = positions[best].z;
                for (int i = 1; i < count; i++) {
                    int part = touched[i];
                    if (var31 < positions[part].z) {
                        best = part;
                        var31 = positions[part].z;
                    }
                }
                kind = data_ov005_0215cd58[best];
                if (self->kind_ != kind) {
                    func_ov005_02158560(self, kind, 1);
                    self->slot_ = 8;
                    func_ov005_0215792c(self, 4);
                    func_ov005_021579ec(self, self->state_, self->slot_);
                    self->flags_ |= 0x100;
                    func_ov005_021555c0(self);
                    return;
                }
            }
        }
    } else if (x > 0x84 && x < 0x9d && y > 0x16 && y < 0x2d) {
        kind = self->kind_;
        item = self->slots_[kind].item_;
    }
    if (item <= 0)
        return;
    int changed = 0;
    if (self->kind_ != kind) {
        changed = 1;
        func_ov005_02158560(self, kind, 1);
        self->flags_ |= 0x100;
    }
    short* items = func_0207c5f8((unsigned char*)GameState_GetParty(gameState) + 0x1d4, data_ov005_0215cd50[self->kind_]);
    int empty = -1;
    int index = -1;
    for (short i = 0; i < self->unknown_3d98_[self->kind_]; i++) {
        short other = items[i];
        if (item == other) {
            index = i;
            break;
        }
        if (empty < 0 && other == -1)
            empty = i;
    }
    if (index < 0)
        index = empty;
    page = index / 16;
    if (self->page_ != page) {
        self->unknown_3dbf_ = self->page_;
        self->page_ = page;
        changed = 1;
        self->pages_[self->kind_] = self->page_;
    }
    if (changed) {
        func_ov005_021555c0(self);
        self->flags_ |= 0x40;
        self->unknown_3daa_ = 0;
    }
    func_ov005_0215792c(self, 3);
    self->dragged_ = self->kind_;
    self->slot_ = self->dragged_;
    GridCursor_SetSelectedIndex(self->cursor_, self->dragged_);
    self->unknown_3dc0_ = 1;
    self->flags_ |= 0x80;
    SePlayer_Play((SePlayer*)&g_sePlayer, 2, 0);
    screen->flags_ &= ~1;
    screen->flags_ &= ~0x80;
    self->flags_ &= ~4;
    self->flags_ &= ~8;
}
