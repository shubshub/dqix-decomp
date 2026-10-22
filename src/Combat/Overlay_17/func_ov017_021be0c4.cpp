#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021be0c4 { unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; int unknown_8_, unknown_c_; };
struct Struct_02046574_2 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    char* unknown_5c_;
#if defined(jpn)
    char unknown_2c_[0x868 - 0x2c];
#else
    char unknown_60_[0x938];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x100a];
#endif
    unsigned char unknown_19ae_;
    char unknown_19af_[3];
    unsigned char unknown_19b2_;
};
struct Struct_ov017_021be0c4_2 {
#if defined(jpn)
    char unknown_0_[0x26a4];
#else
    char unknown1_0_[0x2664];
#endif
    char unknown_2664_[4];
};
struct Struct_02018300_3;
extern "C" Struct_ov017_021be0c4_2* func_02012fe4();
extern "C" int* func_0202ae18();
Obj02046574* GetGlobalField0x1c020421a0();
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetForwardAndStore0205ebc0(void*, int, int);
void DispatchIfField0xc4NonNeg_0205ebfc(void*, int, int);
void ForwardField0xc0_0205ebec(void*);
extern char g_sePlayer[];
extern "C" int func_0208f748(void*, int*);
extern "C" void __clear(void*, unsigned int);
extern "C" void func_020426bc(BaseCombatStats*, char*, int);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
extern "C" void func_02011744(GameState*);
extern "C" const char* func_020e51cc(int);
extern "C" void func_02046574(Struct_02046574_2*, int, char*);
#if defined(jpn)
extern char data_ov017_021d8658[];
#endif
extern "C" int func_0202b7d8(int*);
extern "C" int func_0202c508(int*);
extern "C" void func_ov017_021cf730(int, int);
extern "C" int func_020100a8(GameState*);
extern "C" void func_ov017_021d1810(int, int, signed char);
extern "C" void func_02011408(void*);
extern "C" void func_ov017_021d3ec8();
extern "C" void func_02043204(char*);
extern "C" void func_020397c0(void*);

// USA: func_ov017_021be0c4
// JPN: func_ov017_021be6bc
extern "C" ARM void func_ov017_021be0c4(Struct_ov017_021be0c4* arg0) {
    GameState* var0 = GameState::GetInstance();
    func_0202ae18();
    GameResources* var1 = GetGameResources();
    Struct_02046574_2* var2 = func_020421a0();
    func_02012fe4();
    GrottoStruct* grotto = game->GetGrottoStruct();
    if (state->step == 0) {
        CancelPendingAction020397cc((Obj020397cc*)game->GetUnknownGameObject(), 1);
        FontBankLoader* global = GetGlobal02109400_02094a00();
        BlankFunction02094b30(global, 0x203, 0);
        if (AlwaysTrue02094b4c(global)) state->step = 1;
    } else if (state->step == 1) {
        SetMainBrightness(resources, 0x10, 0xf);
        SetForwardAndStore0205ebc0(g_sePlayer, 0x83, 0x83);
        DispatchIfField0xc4NonNeg_0205ebfc(g_sePlayer, 0, 0);
        state->step = 2;
    } else if (state->step == 2) {
        if (!IsMainBrightnessTransitionActive(resources)) {
            if (func_0208f748(func_02012fe4()->map, &grotto->entranceX)) {
                grotto->activeMapData.SetDiscoveryState(DiscoveryState_Discovered);
                if (grotto->activeMapData.DiscoveredBy[0] == 0) {
#if defined(jpn)
                    VectorizedInvertedMemcpy(var0->GetProtagonist()->baseStats_, var3->activeMapData.DiscoveredBy, 10);
#else
                    char var5[10];
                    __clear(var5, 10);
                    func_020426bc(var0->GetProtagonist()->baseStats_, var5, 1);
                    VectorizedInvertedMemcpy(var5, var3->activeMapData.DiscoveredBy, 10);
#endif
                }
                func_02011744(var0);
                arg0->unknown_8_ = 3;
            } else arg0->unknown_8_ = 5;
        }
    } else if (arg0->unknown_8_ == 3) {
        SetMainBrightness(var1, 0, 0xf);
        arg0->unknown_c_ = 0;
        arg0->unknown_8_ = 4;
    } else if (arg0->unknown_8_ == 4) {
        arg0->unknown_c_ += var0->GetTickCount();
        if (!IsMainBrightnessTransitionActive(var1) && arg0->unknown_c_ > 30) {
            char* var6 = var2->unknown_5c_;
#if defined(jpn)
            sprintf(var6, data_ov017_021d8658, var0->GetUnknownGameObject()->baseStats_->unk);
            func_0204500c((Struct_02021b84*)var2, var6, 0);
#else
            sprintf(var6, func_020e51cc(0x3f));
            func_02046574(var2, 0, (char*)var0->GetUnknownGameObject()->baseStats_);
            func_0204500c((Struct_02021b84*)var2, var6, 0, 0xe3);
#endif
            var2->unknown_19b2_ = 0;
            var2->unknown_998_ = 1;
            int* var7 = func_0202ae18();
            if (func_0202b7d8(var7) && func_0202c508(var7)) {
                func_ov017_021cf730(-1, 0);
                func_ov017_021d1810(0x2713, -1, func_020100a8(var0));
            }
            func_02011408(var0);
            func_ov017_021d3ec8();
            arg0->unknown_8_ = 5;
        }
    } else if (state->step == 5) {
        controller->field_19ae = 0;
        if (!controller->busy) {
            ReinitController02043204((char*)controller);
            SetByteField0x253_020397c0(game->GetUnknownGameObject());
            FontBankLoader* global = GetGlobal02109400_02094a00();
            BlankFunction02094b38(global, 0x203);
            func_02094ab0(global);
            ForwardField0xc0_0205ebec(g_sePlayer);
            state->done = 1;
        }
    }
}
