#include <globaldefs.h>
#include "Combat/BattleHeapOwner.h"
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"

struct Struct_02018300_3;
struct Struct_ov017_021b2c88;

void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
int GetFieldIfFlag4_020100f8(char* obj);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void PushInputLogA_020a1df8(int id);
void PushInputLogB_020a1ef0(int id);
void SetByteField0x253_020397c0(void* obj);
extern "C" void func_020a0cc4(unsigned int size, int ticks);
extern "C" void func_020a0c0c(void);
extern "C" void func_ov003_02174114(void* arg0);
extern "C" int func_ov003_021745fc(void* arg0);
extern "C" void func_ov003_02174454(void* arg0);
extern "C" void func_ov017_021b2c88(Struct_ov017_021b2c88* arg0);

struct Struct_ov017_021b2ce8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    int unknown_8_;
    SafeAllocator unknown_c_;
};

extern AllocatorUnion data_02114e20;

// USA: func_ov017_021b2ce8
extern "C" ARM void func_ov017_021b2ce8(Struct_ov017_021b2ce8* arg0) {
#if defined(jpn)
 enum { Enum_ov017_021b2ce8_4176 = 0xfcc };
#else
 enum { Enum_ov017_021b2ce8_4176 = 0x1050 };
#endif
    GameState* gs = GameState::GetInstance();
    GameResources* res = gs->GetResources();
    SetFlags04(res, 0xc0);
    GameObject* leader = gs->GetUnknownGameObject();
    CancelPendingAction020397cc((Obj020397cc*)leader, 1);
    unsigned char* camera = (unsigned char*)GetFieldIfFlag4_020100f8((char*)gs);
    SetFlagsAt0x244_020a28a0(camera, 3);
    int ticks = gs->GetTickCount();
    if (ticks < 0) {
        ticks = 1;
    }

    if (arg0->unknown_8_ == 0) {
        func_020a0cc4(0x33820, var4);
        void* var5 = func_02012d88(&data_02114e20, 0x32000);
        if (var5 == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_c_.CreateTypeA(var5, 0x32000);
        arg0->unknown_c_.Reset();
        data_ov017_021d840c = static_cast<Struct_ov003_02173f70*>(arg0->unknown_c_.Allocate(Enum_ov017_021b2ce8_4176));
        if (data_ov017_021d840c == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        func_020a1df8(3);
        func_020a1ef0(1);
        func_ov003_02174114(data_ov017_021d840c);
        func_ov003_02173f70(data_ov017_021d840c, &arg0->unknown_c_);
        SetFlags00(var1, 0x6000);
        arg0->unknown_8_++;
    } else if (arg0->unknown_8_ == 1) {
        if (func_ov003_021745fc(data_ov017_021d840c)) {
            Struct_0208cb08* var6 = func_02094a00();
            func_02094b40(var6);
            func_02094ab0(var6);
            func_02094b34(var6, 0x6f, 5000, 1, 1);
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 2) {
        if (func_02094b4c(func_02094a00())) {
            func_ov003_02174454(data_ov017_021d840c);
            arg0->unknown_8_++;
        }
    } else {
        ClearFlags04(var1, 0xc0);
        DISPCNT = (data_ov017_021d840c->unknown_38_ << 8) | (DISPCNT & ~0x1f00);
        func_020a28b0(var3, 3);
        func_ov017_021b2c88((Struct_ov017_021b2c88*)arg0);
        func_020a0c0c();
        arg0->unknown_1_ = 1;
        ClearFlags00(var1, 0x6000);
        func_020397c0(var2);
    }
}
