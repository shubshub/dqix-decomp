#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Timing.h"
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Mutex.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_ov031_022075a4;
struct Struct_ov031_02207230 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned char unknown_4_[4];
};
struct Struct_ov031_02244e44_5 { unsigned long long unknown_0_; };
struct Struct_02245528 {
    unsigned char unknown_0_[0x2d];
    signed char unknown_2d_;
    unsigned char unknown_2e_;
    unsigned char unknown_2f_[6];
    unsigned char unknown_35_;
    unsigned char unknown_36_[0x390 - 0x36];
    unsigned char unknown_390_;
    unsigned char unknown_391_;
    unsigned char unknown_392_[0x16];
    Struct_ov031_02244e44_5 unknown_3a8_;
    unsigned char unknown_3b0_[8];
    Struct_ov031_02244e44_5 unknown_3b8_;
    Struct_ov031_02244e44_5 unknown_3c0_;
    Struct_ov031_02244e44_5 unknown_3c8_;
    unsigned char unknown_3d0_[0x5c];
    Struct_ov031_022075a4* unknown_42c_;
};
struct Struct_ov031_02244e44 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_[6];
    signed short unknown_a_;
    void** unknown_c_;
};
struct Struct_ov031_02291e04_4 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_[5];
    unsigned short unknown_8_;
#if defined(jpn)
    unsigned char unknown_a_[6];
    Struct_ov031_022075a4* unknown_34_;
    unsigned char unknown_14_[4];
    Struct_ov031_02244e44* unknown_18_;
#else
    unsigned char unknown1_a_[0xe];
    Struct_ov031_02244e44* unknown_18_;
    unsigned char unknown_1c_[0x18];
    Struct_ov031_022075a4* unknown_34_;
#endif
};
struct Struct_ov031_02244e44_2 {
    unsigned char unknown_0_[6];
    unsigned char unknown_6_;
    unsigned char unknown_7_;
};
struct Struct_ov031_02244e44_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x7cdc];
#else
    unsigned char unknown1_0_[0x7fb0];
#endif
    Struct_ov031_02244e44_2 unknown_7fb0_[8];
    Struct_ov031_02244e44_2* inline_ov031_02244e44() { return unknown_7fb0_; }
};
struct Struct_ov031_02249594 { int unknown_0_; int unknown_4_; };
struct Struct_ov031_02244e44_4 { unsigned char unknown_0_[0x14]; };
extern Struct_ov031_02249594 data_ov031_02249594[4];
extern int data_ov031_0224c8a4;
extern Mutex data_ov031_02291e50;
extern Struct_ov031_02291e04_4 data_ov031_02291e04;
extern "C" Struct_ov031_022075a4* func_ov031_022071d8(int, int, int);
extern "C" int func_ov031_022075a4(Struct_ov031_022075a4*, int, int);
extern "C" Struct_ov031_02244e44* func_ov031_02207440(Struct_ov031_022075a4*);
extern "C" int func_ov031_02207230(void*, Struct_ov031_02207230*);
extern "C" int func_ov031_0220783c(int*, int, int, int);
int CallWithZeroZeroZero_0220728c(int, int, int);
extern "C" int memcmp(const void*, const void*, int);
extern "C" int func_ov031_02245750(Struct_02245528*, PeerReply02244e44*);
extern "C" int func_ov031_02207434(Obj022075a4*);
extern "C" void func_ov031_022077c0();
extern "C" void func_ov031_02245938();
extern "C" int func_ov031_0220d540();
extern "C" void func_ov031_02245528(Struct_02245528*, int);

// USA: func_ov031_02244e44
extern "C" ARM void func_ov031_02244e44(Struct_02245528* arg0) {
    switch (arg0->unknown_35_) {
    case 0:
        arg0->unknown_42c_ = func_ov031_022071d8(2, 1, 0);
        if ((int)arg0->unknown_42c_ < 0) { arg0->unknown_35_ = 5; break; }
        func_ov031_022075a4(arg0->unknown_42c_, 4, func_ov031_022075a4(arg0->unknown_42c_, 3, 0) & ~4);
        arg0->unknown_35_ = 1;
        arg0->unknown_2d_ = -1;
        arg0->unknown_2e_ = 0;
    case 2: {
        int var0 = arg0->unknown_2d_;
        if (var0 >= 0 || arg0->unknown_2e_) {
            if (var0 < 0) var0 = 0;
            else if (var0 >= 4) var0 = 3;
            signed char var1 = var0;
            int var2 = arg0->unknown_2e_ ? 0 : data_ov031_02249594[var1].unknown_0_;
            unsigned long long var3 = GetCurrentTimestamp();
            unsigned long long var4 = arg0->unknown_3c8_.unknown_0_;
            if (((var3 - var4) << 6) / 0x82ea >= (unsigned long long)var2 || var3 < var4) {
                arg0->unknown_35_ = 1;
                if (arg0->unknown_2e_) arg0->unknown_2e_ = 0;
                else {
                    arg0->unknown_2d_++;
                    arg0->unknown_3c0_.unknown_0_ = GetCurrentTimestamp();
                }
            } else {
                SleepCurrentContext(5);
                break;
            }
        } else {
            arg0->unknown_35_ = 1;
            arg0->unknown_2d_ = 0;
            arg0->unknown_2e_ = 0;
            arg0->unknown_3b8_.unknown_0_ = GetCurrentTimestamp();
            arg0->unknown_3c0_ = arg0->unknown_3b8_;
        }
    }
    case 1: {
        if (data_ov031_0224c8a4) {
            ZeroInitializeMutex(&data_ov031_02291e50);
            data_ov031_0224c8a4 = 0;
        }
        LockMutex(&data_ov031_02291e50);
        Struct_ov031_02244e44* var5 = func_ov031_02207440(data_ov031_02291e04.unknown_34_);
        UnlockMutex(&data_ov031_02291e50);
        if (!var5) { arg0->unknown_35_ = 5; break; }
        Struct_ov031_02207230 var6;
        memset(&var6, 0, 8);
        unsigned short var7 = data_ov031_02291e04.unknown_8_;
        var6.unknown_0_ = 8;
        var6.unknown_1_ = 2;
        var6.unknown_2_ = ((var7 >> 8) & 0xff) | ((var7 << 8) & 0xff00);
        VectorizedInvertedMemcpy(*var5->unknown_c_, var6.unknown_4_, var5->unknown_a_);
        GetCurrentTimestamp();
        func_ov031_022075a4(arg0->unknown_42c_, 4, func_ov031_022075a4(arg0->unknown_42c_, 3, 0) | 4);
        int var8 = func_ov031_02207230(arg0->unknown_42c_, &var6);
        if (var8 == -26) {
            unsigned long long var9 = ((GetCurrentTimestamp() - arg0->unknown_3c0_.unknown_0_) << 6) / 0x82ea;
            if (var9 >= 0x3a98) var8 = -76;
        }
        if (var8 == -26) {
            arg0->unknown_3c8_.unknown_0_ = GetCurrentTimestamp();
            arg0->unknown_2e_ = 1;
            arg0->unknown_35_ = 2;
            SleepCurrentContext(5);
            break;
        }
        if (var8 >= 0 || var8 == -30) {
            arg0->unknown_35_ = 4;
            break;
        }
        if (var8 != -76) goto Failed;
        arg0->unknown_2d_ = 5;
        arg0->unknown_2e_ = 0;
        unsigned long long var10 = ((GetCurrentTimestamp() - arg0->unknown_3b8_.unknown_0_) << 6) / 0x82ea;
        if (var10 >= 0xafc8) {
            arg0->unknown_2d_ = 5;
            arg0->unknown_2e_ = 0;
        }
        if (arg0->unknown_2d_ < 5) {
            arg0->unknown_3c8_.unknown_0_ = GetCurrentTimestamp();
            arg0->unknown_35_ = 2;
            SleepCurrentContext(5);
        } else {
        Failed:
            arg0->unknown_35_ = 5;
        }
        break;
    }
    case 4: {
        GetCurrentTimestamp();
        func_ov031_022075a4(arg0->unknown_42c_, 4, func_ov031_022075a4(arg0->unknown_42c_, 3, 0) | 4);
        int var11[2];
        if (func_ov031_0220783c(var11, 1, 0x7fd88, 0) > 0) {
            Struct_ov031_02244e44_4 var12;
            memset(&var12, 0, 0x14);
            if (func_ov031_0220728c((int)arg0->unknown_42c_, (int)&var12, 0x14) < 0) {
                GetCurrentTimestamp();
                if (data_ov031_02291e04.peer) {
                    SavedPeer02244e44* peer = ((SessionGame02244e44*)GameState::GetInstance())->GetPeers();
                    for (int index = 0; index < 8; index++, peer++) {
                        if (!memcmp(peer, data_ov031_02291e04.peer->address, 6)) {
                            if (!data_ov031_02291e04.present) peer->status = 0xff;
                            else memset(peer, 0, 8);
                            break;
                        }
                    }
                }
                arg0->unknown_35_ = 5;
            } else {
                GetCurrentTimestamp();
                Struct_ov031_02244e44_4 var15;
                memcpy(&var15, &var12, 0x14);
                arg0->unknown_390_ = func_ov031_02245750(arg0, &var15);
                arg0->unknown_35_ = 5;
            }
        } else {
            arg0->unknown_35_ = 5;
            func_ov031_022075a4(arg0->unknown_42c_, 4, func_ov031_022075a4(arg0->unknown_42c_, 3, 0) & ~4);
        }
        break;
    }
    case 5:
        GetCurrentTimestamp();
        func_ov031_022075a4(arg0->unknown_42c_, 4, func_ov031_022075a4(arg0->unknown_42c_, 3, 0) | 4);
        func_ov031_022075a4(arg0->unknown_42c_, 4, func_ov031_022075a4(arg0->unknown_42c_, 3, 0) | 4);
        if (func_ov031_02207434(arg0->unknown_42c_) == 0) {
            SleepCurrentContext(1);
            for (int var16 = 0; var16 < 0x7530; var16++) {
                if (func_ov031_02207434(arg0->unknown_42c_) != -26) break;
                SleepCurrentContext(1);
            }
        }
        arg0->unknown_42c_ = (Struct_ov031_022075a4*)-1;
        func_ov031_022077c0();
        func_ov031_02245938();
        arg0->unknown_3a8_.unknown_0_ = GetCurrentTimestamp() + 0xefb5f7;
        arg0->unknown_35_ = 6;
        break;
    case 6:
        if (!func_ov031_0220d540()) {
            GetCurrentTimestamp();
            func_ov031_02245528(arg0, 0);
            arg0->unknown_391_ = 1;
        }
        break;
    }
}
