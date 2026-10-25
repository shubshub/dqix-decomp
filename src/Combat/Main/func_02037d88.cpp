#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

extern "C" void func_0202ae18(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020391ac(void* obj);
extern "C" void func_02038138(void* obj);
extern "C" void func_02038598(void* obj);

struct Vector3i;

struct Struct_02037d88_8;

struct Struct_02037d88_9;

struct Struct_02037d88_10;
extern "C" void func_02039df4(struct Struct_02037d88_10* arg0);

struct Struct_02037d88_11;
extern "C" void func_02052ae8(struct Struct_02037d88_11* arg0);

extern "C" int func_020535c8(signed char* arg0);
extern "C" int func_ov017_0219a370(unsigned char* arg0);
extern "C" int func_02046b08(void** arg0);

struct Struct_0203402c;
extern "C" int func_0203402c(struct Struct_0203402c* arg0);

int MessageSystem_GetInstance();

unsigned char GameState_GetLeaderIndex(GameState* battleStruct);
int GetFieldIfFlag4_020100f8(char* obj);

struct Struct_02037d88_12;
extern "C" int func_020a2c70(struct Struct_02037d88_12* arg0);

struct Struct_02037d88;
extern "C" int func_02052e44(Struct_02037d88*, signed char);

struct Struct_02037d88_2;
extern "C" int func_02052f44(struct Struct_02037d88_2* arg0, signed char* arg1, int arg2);

extern "C" int func_020ac4c0(void* arg0);

struct Struct_02037d88_3;
extern "C" void func_020a06b0(struct Struct_02037d88_3* arg0, unsigned int arg1);

struct Struct_02037d88_4;
extern "C" void func_020a0140(struct Struct_02037d88_4* arg0, unsigned int arg1);

extern "C" int func_020ac494(void* arg0);

extern "C" void func_020a2c8c(unsigned char* arg0);

#if defined(jpn)
enum { Enum_02037d88_0 = 12, Enum_02037d88_0_2 = 0x2d4, Enum_02037d88_0_3 = 0x1d0,
       Enum_02037d88_1060 = 0x444, Enum_02037d88_16384 = 0x3000, Enum_02037d88_128 = 0xe60,
       Enum_02037d88_1788 = 0x4ec };
#else
enum { Enum_02037d88_0 = 0, Enum_02037d88_0_2 = 0, Enum_02037d88_0_3 = 0,
       Enum_02037d88_1060 = 0x424, Enum_02037d88_16384 = 0x4000, Enum_02037d88_128 = 0x80,
       Enum_02037d88_1788 = 0x6fc };
#endif

struct Struct_02037d88_5 {
    char unknown_0_[0x9b1 - Enum_02037d88_0_3];
    unsigned char unknown_9b1_;
};
struct Struct_02037d88_6 {
    char unknown_0_[0x1000];
    struct Struct_02037d88_5 unknown_1000_;
};

struct Struct_02037d88_7 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[0x44 - 6];
    int unknown_44_[3];
    char unknown_50_[0x54 - 0x50];
    int unknown_54_;
    char unknown_58_[0xb2 - 0x58];
    short unknown_b2_;
    short unknown_b4_;
    char unknown_b6_[0xc2 - 0xb6];
    unsigned char unknown_c2_0_ : 5;
    unsigned char unknown_c2_5_ : 1;
    unsigned char unknown_c2_6_ : 2;
    char unknown_c3_[0x130 - 0xc3];
    void* unknown_130_;
    char unknown_134_[0x1ce - Enum_02037d88_0 - 0x134];
    unsigned char unknown_1ce_;
    char unknown_1cf_[0x260 - 0x1cf];
    int unknown_260_;
};

// USA: func_02037d88
extern "C" ARM void func_02037d88(struct Struct_02037d88_7* arg0) {
    void* var0 = GameState::GetInstance();
    func_0202ae18();
    unsigned char* var1 = (unsigned char*)((int)GetGameResources());

    int var2 = (arg0->unknown_1ce_ & 4) != 0;
    if (var2) {
        if (arg0->unknown_b2_ > 0) {
            arg0->unknown_1ce_ &= ~4;
            ((Object3D*)((struct Struct_02037d88_8*)arg0))->SetInheritedAlpha(0);
            ((Object3D*)((struct Struct_02037d88_9*)arg0))->TransitionInheritedAlpha(0x1f, 0x64);
        }
    }
    func_02039df4((struct Struct_02037d88_10*)arg0);

    if (arg0->unknown_4_ == 0xce) {
        *(int*)((char*)var0 + 0x7f5c - Enum_02037d88_0_2) = arg0->unknown_54_;
        *(Vector3i*)((int*)((char*)var0 + 0x7f60 - Enum_02037d88_0_2)) = *(Vector3i const*)arg0->unknown_44_;
    }

    {
        char* var3 = (char*)arg0 + 0x100;
        signed char var4 = ((signed char*)var3)[0xc9 - Enum_02037d88_0];
        if (var4 != 0) {
            func_02052ae8((struct Struct_02037d88_11*)arg0);
            func_020391ac(arg0);
            return;
        }
    }

    {
        void* bsOrig = GameState::GetInstance();
        void* field3b0 = ((GameState*)bsOrig)->GetCamera();
        void* ctx = Zone3D_GetInstance();
        int* ptr130 = (int*)obj->field130;

        if ((*var8 & 1) != 0
            || func_020535c8((signed char*)arg0) != 0
            || *(int*)((char*)var7 + Enum_02037d88_1060) != 0
            || var6 == 0
            || arg0->unknown_c2_5_) {
            func_02052ae8((struct Struct_02037d88_11*)arg0);
            return;
        }

        {
            short var9 = arg0->unknown_b4_;
            func_02052ae8((struct Struct_02037d88_11*)arg0);
            arg0->unknown_b4_ = var9;
        }

        unsigned int* var10 = (unsigned int*)(var1 + Enum_02037d88_16384);
        int var11 = *(int*)((char*)var10 + Enum_02037d88_128);
        unsigned int* var12 = (unsigned int*)(var1 + 0x3000);
        void* var13 = *(void**)((char*)var12 + Enum_02037d88_1788);

        if (var11 != 0
            && func_ov017_0219a370(var1) != 0
            && func_02046b08((void**)var13) != 0
            && g_keyManager.TestKeysHeld(2) != 0
            && CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)obj) == 0
            && ((struct GlobalOuter020421a0*)MessageSystem_GetInstance())->sub.flag == 0) {

            unsigned char* ptr2a04 = (unsigned char*)GameState_GetParty((GameState*)bsOrig);

            void* bsOrig2 = GameState::GetInstance();
            short id3 = obj->combatantId;
            unsigned char field397c_1 = GameState_GetLeaderIndex((GameState*)bsOrig2);
            if (field397c_1 == id3) {
                int p2 = GetFieldIfFlag4_020100f8((char*)bsOrig2);
                if (p2 != 0) {
                    if (IsCountAtLeast4_0219a370(r6) != 0) {
                        if (MarkStateIfFlag020a2c70((struct S020a2c70*)p2) != 0) {
                            SetFlags04((GameResources*)r6, 0x80);
                        }
                    }
                }
            }

            int var19 = 0;
            if (g_keyManager.TestKeysPressed(0x40)) {
                signed char var20 = var14[0x2c8d];
                var19 = func_02052e44((struct Struct_02037d88*)arg0, var20);
                arg0->unknown_260_ = 0;
            } else if (g_keyManager.TestKeysPressed(0x10)) {
                signed char var21 = var14[0x2c8f];
                var19 = func_02052e44((struct Struct_02037d88*)arg0, var21);
                arg0->unknown_260_ = 2;
            } else if (g_keyManager.TestKeysPressed(0x20)) {
                signed char var22 = var14[0x2c8e];
                var19 = func_02052e44((struct Struct_02037d88*)arg0, var22);
                arg0->unknown_260_ = 1;
            } else if (g_keyManager.TestKeysPressed(0x80)) {
                var19 = func_02052f44((struct Struct_02037d88_2*)arg0, (signed char*)(var14 + 0x2c90), 4);
                arg0->unknown_260_ = 3;
            }

            if (var19 != 0) {
                char var23[0xb0];
                func_020ac4c0(var23);
                func_020a06b0((struct Struct_02037d88_3*)var23, 1);
                func_020a0140((struct Struct_02037d88_4*)(var23 + 0x68), 1);
                func_020ac494(var23);
                return;
            }
        } else {
            void* bs3 = GameState::GetInstance();
            short id2 = obj->combatantId;
            unsigned char field397c_2 = GameState_GetLeaderIndex((GameState*)bs3);
            if (field397c_2 == id2) {
                int p = GetFieldIfFlag4_020100f8((char*)bs3);
                if (p != 0) {
                    unsigned char* state = (unsigned char*)p + 0x2c4;
                    if (state != 0) {
                        unsigned char stateByte = state[0];
                        if (stateByte == 1) {
                            SetByte0x2c4To2IfByte0x2c5Set_020a2c8c((unsigned char*)p);
                        } else if (stateByte == 2) {
                            short v = *(short*)(state + 2);
                            if (v < 0x199) {
                                ClearFlags04((GameResources*)r6, 0x80);
                            }
                        }
                    }
                }
            }
        }

        arg0->unknown_260_ = -1;
        if (((Object3D*)arg0)->GetFlag(0x1000000) == 0) {
            func_02038138(arg0);
        }
        func_02038598(arg0);
    }
}
