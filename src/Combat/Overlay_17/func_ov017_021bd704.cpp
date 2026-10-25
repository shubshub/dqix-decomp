#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02039d84;
struct Struct_02033834;
struct Struct_ov017_021bd704 {
    unsigned char unknown_0_[5];
    unsigned char unknown_5_;
    unsigned char unknown_6_[4];
    unsigned short unknown_a_;
    unsigned char unknown_c_[0x44 - 0xc];
    unsigned short unknown_44_;
    unsigned short unknown_46_;
    Vector3fix unknown_48_;
    short unknown_54_;
};
struct Struct_ov017_021bd704_2 {
    unsigned char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
extern "C" void* func_0202ae18();
unsigned char GameState_GetLeaderIndex(GameState*);
extern "C" int func_0202c508(void*);
extern "C" void func_02039d48(unsigned char*);
int fix32sin(int);
int fix32cos(int);
extern "C" unsigned char func_02039d7c(char*);
extern "C" void func_02039d84(Struct_02039d84*);
extern "C" void func_ov017_021d440c(int);
extern "C" void func_02033874(Struct_02033834*, int);
extern "C" void func_02039d24(unsigned char*);
extern "C" void func_ov017_021c3e18(int);

// USA: func_ov017_021bd704
extern "C" ARM void func_ov017_021bd704(Struct_ov017_021bd704* arg0) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_0202ae18();
    int var2 = (arg0->unknown_44_ & 0x40) != 0;
    int var3 = (arg0->unknown_44_ & 0x1000) != 0 && arg0->unknown_5_ != 0;
    if (arg0->unknown_5_ == 0 && !var2 && !var3) return;
    Vector3fix var4 = arg0->unknown_48_;
    int var5 = arg0->unknown_54_;
    if (arg0->unknown_5_ == 0 && var2) {
        var4 = var0->GetUnknownGameObject()->obj3D_.position_;
        var5 = var0->GetUnknownGameObject()->obj3D_.rotation_.y;
    }
    PartyList021bd704* party = (PartyList021bd704*)GameState_GetParty(game);
    if (party != 0) {
        for (int i = 0; i < party->count; i++) {
            int id = party->members[i];
            GameObject* member = game->GetPartyMemberByIndex(id);
            if (member == 0) continue;
            if (func_0202c508(search)) {
                int member_id = member->obj3D_.actorIndex_;
                if (member_id != GameState_GetLeaderIndex(game) && anchor) {
                    member->obj3D_.SetInheritedAlpha(0);
                    SetFlag0x1ceBit0x4_02039d48((unsigned char*)member);
                }
            } else if (arg0->unknown_5_ && !var3) {
                if (var8 == 1) {
                    int var11 = FIX32_MULTIPLY(fix32sin(var5), 0x800);
                    int var12 = FIX32_MULTIPLY(fix32cos(var5), -0x1333);
                    var4.z += var12 - var11;
                    var11 = FIX32_MULTIPLY(fix32cos(var5), 0x800);
                    var12 = FIX32_MULTIPLY(fix32sin(var5), -0x1333);
                    var4.x += var12 + var11;
                } else if (var8 == 2) {
                    int var13 = FIX32_MULTIPLY(fix32sin(var5), -0x800);
                    int var14 = FIX32_MULTIPLY(fix32cos(var5), -0x1800);
                    var4.z += var14 - var13;
                    var13 = FIX32_MULTIPLY(fix32cos(var5), -0x800);
                    var14 = FIX32_MULTIPLY(fix32sin(var5), -0x1800);
                    var4.x += var14 + var13;
                } else if (var8 == 3) {
                    int var15 = FIX32_MULTIPLY(fix32cos(var5), -0x1ccc);
                    var4.z += var15;
                    int var16 = FIX32_MULTIPLY(fix32sin(var5), -0x1ccc);
                    var4.x += var16;
                }
            }
            if (arg0->unknown_a_ != 8100 && func_02039d7c((char*)var9)) {
                func_02039d84((Struct_02039d84*)var9);
                func_ov017_021d440c(-1);
            }
            var9->obj3D_.position_ = var4;
            func_02033874((Struct_02033834*)var9, var5);
            var9->obj3D_.EnableFlag(0x4000000);
            func_02039d24((unsigned char*)var9);
        }
    }
    if (func_0202c508(var1)) func_ov017_021c3e18(0);
}
