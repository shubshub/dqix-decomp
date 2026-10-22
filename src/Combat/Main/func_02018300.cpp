#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Entry_02028bd0;
struct Obj02028c64;
struct SePlayer;
struct Obj020397cc;
struct ProtagonistSpeed {
    char pad_00[0xb2];
    short speed;
};
struct Struct_020e6e74 { int unknown_0_[5]; };
struct Struct_02018300_5 {
    char unknown_0_[0xc];
    int unknown_c_;
    char unknown_10_[0xc];
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    char unknown_20_[8];
    short unknown_28_;
    char unknown_2a_[0xa];
};
extern "C" void* func_0205ec34();
extern "C" int func_02064b24(void*, int, unsigned short, void*);
#if defined(jpn)
#define data_020e6e74 data_020e7718
#endif
int fix32ReduceAngle0To2Pi(int);
int fix32cos(int);
int fix32sin(int);
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);
void* GetPointerFromArray0x3c_0201e838(unsigned char*, unsigned int);
void SePlayer_Play(SePlayer*, int, int);
void CancelPendingAction020397cc(Obj020397cc*, int);
void EnqueueEventTag175_021d196c(unsigned short, unsigned short, int);
Entry_02028bd0* GetEntryTableBase_02027ca4();
Obj02028c64* FindInlineEntryById(Entry_02028bd0*, int);
void SetFlagBit02028c64(Obj02028c64*, int);
extern const SoundTable data_020e6e74;
extern SePlayer g_sePlayer;

// USA: func_02018300
extern "C" ARM void func_02018300(Zone3D* arg0, Struct_020134e0::Struct_02018300* arg1, int arg2, int arg3, int arg4) {
    Struct_02016874_2* var0 = func_02018b34(arg0, arg1);
    if (!var0) return;
    if (!arg3 && (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 8)) return;
    if (!arg3 && (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 4)) return;
    if (!arg3) {
        void* var1 = func_0205ec34();
        Struct_02018300_5 var2;
        var2.unknown_28_ = arg1->unknown_20_;
        var2.unknown_1e_ = arg1->unknown_2c_.unknown1_0_.unknown_1_;
        var2.unknown_1c_ = arg1->unknown_2c_.unknown1_0_.unknown_0_;
        var2.unknown_c_ = arg0->currentZoneID_;
        func_02064b24(var1, 17, 108, &var2);
        func_02064b24(var1, 3, 108, &var2);
        if (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 4) {
            arg1->unknown_2c_.unknown1_0_.unknown_2_4_ = (unsigned short)(arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & ~4);
            arg1->unknown_2c_.unknown1_0_.unknown_2_4_ = (unsigned short)(arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & ~1);
            return;
        }
    }
    if (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 32) {
        short var3 = fix32ReduceAngle0To2Pi((short)(arg1->unknown_20_ + 0x1922));
        int var4 = fix32cos(var3);
        Vector3i var5;
        var5.x = fix32sin(var3);
        var5.y = 0;
        var5.z = var4;
        Vector3fix_Normalize(&var5, &var5);
        Vector3fixMultiplyScalar(&var5, arg1->unknown_2c_.unknown1_0_.unknown_40_, &var5);
        Vector3i var6;
        Vector3fix_Normalize(&var5, &var6);
        var0->unknown_48_ = var6;
        Vector3i var7;
        Vector3fix_Add(&var0->unknown_8_, &var5, &var7);
        var0->unknown_3c_ = var7;
        var0->unknown_3a_ = 0x266;
    } else {
        int var8 = (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 64) ? 0x1922 : 0x141b;
        if (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 256) {
            if (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 128) {
                var0->unknown_2_ |= 16;
                if (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 2) {
                    var0->unknown_34_ = var0->unknown_6_ - var8;
                    var0->unknown_38_ = var0->unknown_34_;
                } else {
                    var0->unknown_34_ = var0->unknown_6_ + var8;
                    var0->unknown_38_ = var0->unknown_34_;
                }
            } else var0->unknown_2_ |= 4;
        } else {
            if (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 128) var0->unknown_2_ |= 16;
            if (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 2) {
                var0->unknown_34_ = var0->unknown_6_ - var8;
            } else {
                var0->unknown_34_ = var0->unknown_6_ + var8;
            }
        }
        var0->unknown_36_ = 0x199;
    }
    arg1->unknown_2c_.unknown1_0_.unknown_2_4_ = (unsigned short)(arg1->unknown_2c_.unknown1_0_.unknown_2_4_ | 1);
    var0->unknown_2_ |= 1;
    for (int var9 = 0; var9 < arg0->unknown_82c_; var9++) {
        Struct_02016874_2* var10 = arg0->unknown_824_[var9];
        if (var10->unknown_28_ == var0) {
            var10->unknown_2_ |= 1;
            break;
        }
    }
    Struct_020134e0::Struct_02018300* var11 = (Struct_020134e0::Struct_02018300*)func_0201e838((unsigned char*)&arg0->substruct_6c_, 2);
    while (var11) {
        if (var11->unknown_2c_.unknown1_0_.unknown_0_ == arg1->unknown_2c_.unknown1_0_.unknown_0_ && var11->unknown_2c_.unknown1_0_.unknown_1_ == arg1->unknown_2c_.unknown1_0_.unknown_1_)
            var11->unknown_2c_.unknown1_0_.unknown_2_4_ = (unsigned short)(var11->unknown_2c_.unknown1_0_.unknown_2_4_ | 1);
        var11 = var11->unknown_70_;
    }
    if (sound) {
        SoundTable sounds = data_020e6e74;
        SePlayer_Play(&g_sePlayer, sounds.values[param->unk_2c.type2.unk_2_low], 0);
    }
    if (arg3 && (arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 8)) {
        GameObject* var13 = GameState::GetInstance()->GetProtagonist();
        ((Struct_02018300_4*)var13)->unknown_b2_ = 0;
        func_020397cc((Struct_02018300_3*)var13, 1);
        arg0->unk_830[0] = 8;
        return;
    }
    int var14 = func_02018bc4(arg0, arg1);
    if (arg3 && arg4) func_ov017_021d196c(arg0->currentZoneID_, (unsigned short)var14, arg2);
    Struct_02018300_2* var15 = func_02028bd0(func_02027ca4(), arg0->currentZoneID_);
    if (var15 && !(arg1->unknown_2c_.unknown1_0_.unknown_2_4_ & 512)) func_02028c64(var15, var14);
}
