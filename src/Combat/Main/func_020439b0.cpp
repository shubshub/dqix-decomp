#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"
#include "Resource/MessageSystem.h"

#define REG_BG_SCROLL_020439b0 (*(volatile unsigned int*)0x04000018)
#define REG_DISPLAY_020439b0 (*(volatile unsigned int*)0x04000000)

extern "C" void func_0206b804(char* arg0, int* arg1, int* arg2);
extern "C" void func_02044c74(void* arg0, void* arg1);
extern "C" void func_02066cf0(void* arg0, int arg1);
#if defined(jpn)
#define func_02044074 func_0204483c
#endif
extern "C" void func_02044074(struct Struct_02044074* arg0);
#if defined(jpn)
#define func_02042b98 func_02043270
#define func_02043600 func_02043de0
#endif
extern "C" void func_02042b98(void* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_0204408c(struct Struct_020439b0_7* arg0, short arg1, short arg2, short arg3, short arg4);
extern "C" void func_02043600(void* arg0, void* arg1);
#include "Resource/MessageUpdate.h"
extern "C" void MessageSystem_Stop(void* self);
extern "C" void func_020437bc(void* buf, void* box, int index);

struct Struct_0204394c;
#if defined(jpn)
#define func_0204394c func_02044104
#endif
extern "C" void func_0204394c(struct Struct_0204394c* arg0);

struct Struct_020439b0;
extern "C" void func_020e2cc4(struct Struct_020439b0* arg0, int arg1);

void VramState_Restore(char* obj);
struct Obj02041754;
void DisableField16Bit002041754(MessageGlyphSlot* obj);
void VramState_Save(char* obj);
void ClearBitInArray_02042af4(int unused, unsigned char* arr, int index);

struct Struct_020439b0_3;
extern "C" void func_020e2d2c(struct Struct_020439b0_3* arg0, int arg1, int arg2, int arg3, int arg4);

struct Struct_020439b0_4;
extern "C" void func_020e2c34(struct Struct_020439b0_4* arg0);

struct Struct_020439b0_5 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    int unknown_8_;
};

struct Struct_02042b98_3 {
    char unknown_0_[0x440];
    Struct_020439b0_5* unknown_440_;
};

struct Struct_020439b0_6 { char unknown_0_[8]; int unknown_8_; char unknown_c_[0xa8-0xc]; short unknown_a8_, unknown_aa_, unknown_ac_, unknown_ae_; };
struct Struct_02044074 { unsigned short unknown_0_, unknown_2_, unknown_4_, unknown_6_; };
struct Struct_020439b0_7 { short unknown_0_, unknown_2_, unknown_4_, unknown_6_; };
union Struct_020439b0_8 { Struct_02044074 unknown_0_; Struct_020439b0_7 unknown1_0_; };
#if defined(jpn)
enum { Enum_020439b0_52 = 0, Enum_020439b0_324 = 0x104, Enum_020439b0_332 = 0x10c,
       Enum_020439b0_707 = 0x213, Enum_020439b0_2324 = 0x7e4,
       Enum_020439b0_2352 = 0x800, Enum_020439b0_6624 = 0x1804,
       Enum_020439b0_116 = 0x40, Enum_020439b0_6586 = 0x17ea,
       Enum_020439b0_6603 = 0x17fc, Enum_020439b0_6498 = 0x1790 };
#else
enum { Enum_020439b0_52 = 0x34, Enum_020439b0_324 = 0x144, Enum_020439b0_332 = 0x14c,
       Enum_020439b0_707 = 0x2c3, Enum_020439b0_2324 = 0x914,
       Enum_020439b0_2352 = 0x930, Enum_020439b0_6624 = 0x19e0,
       Enum_020439b0_116 = 0x74, Enum_020439b0_6586 = 0x19ba,
       Enum_020439b0_6603 = 0x19cb, Enum_020439b0_6498 = 0x1962 };
#endif

struct Struct_020439b0_9 { short unknown_0_[0x400]; short unknown_800_[0x400]; };
extern void* data_02107800;
#if defined(jpn)
#define TILE_MAP_BUFFER (*(void**)((char*)&data_02107800 + 0x30))
#else
#define TILE_MAP_BUFFER data_02107800
#endif

static inline short inline_020439b0(Struct_020439b0_6* arg0) { return arg0->unknown_a8_; }

// USA: func_020439b0
extern "C" ARM void func_020439b0(char* arg0, int arg1) {
    Struct_02021b84* var0 = (Struct_02021b84*)arg0;
    int var1, var2;
    Struct_020439b0_8 var3, var4, var5;

    if (var0->unknown_19cc_ != 0) {
        func_0206b804(arg0, &var1, &var2);
        func_02044c74(arg0, (*(Struct_020439b0_6**)(arg0 + Enum_020439b0_52)));

        Struct_020439b0_6* var6 = (*(Struct_020439b0_6**)(arg0 + Enum_020439b0_52));
        int var7 = var6->unknown_8_;
        if (var7 != 0) {
            var6->unknown_8_ = var7;

            var0->unknown_19cc_ = 0;
            func_02066cf0(arg0, 1);
            var0->unknown_19cc_ = 1;
            if (var0->unknown_19c0_ != 0) {
                var0->unknown_40_ = 0;
            }

            func_02044074(&var3.unknown_0_);
            func_02044074(&var4.unknown_0_);
            func_02044074(&var5.unknown_0_);

            if (var0->unknown_998_ != 0 && var0->unknown_19b1_ != 0) {
                goto prepareBounds;
            }
            if ((*(unsigned char*)(arg0 + Enum_020439b0_6603)) != 0) {
            prepareBounds:
                if (var0->unknown_19b1_ != 0) {
                    func_02042b98(arg0, 2, 0x74, 0xfc, 0x4a);
                    func_0204408c(&var3.unknown1_0_, var1 + 2, var2 + 0x74, 0xfc, 0x4a);
                    func_02043600((*(Struct_020439b0_6**)(arg0 + Enum_020439b0_52)), &var3);
                    func_0204408c(&var3.unknown1_0_, 2, 0x74, 0xfc, 0x4a);

                }

                if (var0->unknown_19c4_ != 0 && var0->unknown_19c3_ != 0) {
                    struct Struct_02042b98_3* var8 = (Struct_02042b98_3*)(arg0 + Enum_020439b0_6624);
                    var8->unknown_440_ = &(*(Struct_020439b0_5*)(arg0 + Enum_020439b0_2352));
                    int var9 = (var8->unknown_440_ != 0) ? (var8->unknown_440_->unknown_8_ == 2) : 0;
                    if (var9) {
                        short var10, var11, var12, var13;
                        if (var8->unknown_440_ != 0) {
                            var10 = var8->unknown_440_->unknown_0_;
                            var11 = var8->unknown_440_->unknown_2_;
                        }
                        if (var8->unknown_440_ != 0) {
                            var12 = var8->unknown_440_->unknown_4_;
                            var13 = var8->unknown_440_->unknown_6_;
                        }
                        func_0204408c(&var4.unknown1_0_, var10 + var1, var11 + var2, var12, var13);
                        func_02043600((*(Struct_020439b0_6**)(arg0 + Enum_020439b0_52)), &var4);
                        func_0204408c(&var4.unknown1_0_, var10, var11, var12, var13);
                    }
                    var8->unknown_440_ = &(*(Struct_020439b0_5*)(arg0 + Enum_020439b0_2324));
                }

                if (var0->unknown_9a0_ == 6) {
                    if ((*(unsigned char*)(arg0 + Enum_020439b0_6586)) != 0 && (*(unsigned char*)(arg0 + Enum_020439b0_707)) != 0) {
                        func_0204408c(&var5.unknown1_0_, (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_0_, (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_2_,
                            (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_4_, (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_6_);
                        func_02043600((*(Struct_020439b0_6**)(arg0 + Enum_020439b0_52)), &var5);
                    }
                }
            }

            Struct_020439b0_6* var14 = (*(Struct_020439b0_6**)(arg0 + Enum_020439b0_52));
            if (var14 != 0) {
                short var15;
                int var16;
                int var17;
                short var18;
                int var19;
                short var20 = var14->unknown_ac_;
                short var21 = var14->unknown_ae_;
                short var22 = inline_020439b0(var14);
                var18 = var14->unknown_aa_;
                var16 = (var20 + (var21 << 5)) << 5;
                var17 = var14->unknown_8_;
                var15 = 0;
                for (; var15 < var18; var15++) {
                    var19 = var22 << 5;
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Character, (const void*)var17, var16, var19, 1, 0);
                    var17 += var19;
                    var16 += 0x400;
                }
            }

            int var23 = var0->unknown_94c_[0];
            int var24 = var0->unknown_94c_[1];
            REG_BG_SCROLL_020439b0 = ((-var23) & 0x1ff) | (((-var24) << 16) & 0x1ff0000);
            var0->unknown_94c_[0] = var1;
            var0->unknown_94c_[1] = var2;

            if (var0->unknown_9a0_ != 1 && var0->unknown_9a0_ != 0) {
                memset(TILE_MAP_BUFFER, 0, 0x800);

                if (var0->unknown_998_ != 0 && var0->unknown_19b1_ != 0) {
                    goto stageBounds;
                }
                if ((*(unsigned char*)(arg0 + Enum_020439b0_6603)) != 0) {
                stageBounds:
                    if (var0->unknown_19b1_ != 0) {
                        void* var25 = TILE_MAP_BUFFER;
                        func_020437bc(var25, &var3, 0);
                        func_020437bc(var25, &var4, 1);
                        func_020437bc(var25, &var5, 2);
                        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, var25, 0, 0x800, 1, 0);
                    }
                }

                if (var0->unknown_19b1_ == 0) {
                    StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, TILE_MAP_BUFFER, 0, 0x800, 1, 0);
                }

                if (!((*(unsigned int*)(arg0 + Enum_020439b0_116)) != var0->unknown_78_ && var0->unknown_998_ != 0)) {
                    Struct_020439b0_9* var26 = (Struct_020439b0_9*)TILE_MAP_BUFFER;
                    unsigned short var27;
                    for (var27 = 0; var27 < 0x100; var27++) {
                        var26->unknown_800_[var27] = 0;
                    }
                    for (unsigned short var28 = 0x100; var28 < 0x300; var28++) {
                        var26->unknown_800_[var28] = (short)var28;
                    }
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Screen, var26->unknown_800_, 0, 0x800, 1, 0);
                }
            }

            REG_DISPLAY_020439b0 = (REG_DISPLAY_020439b0 & ~0x1f00) | 0x1d00;
        }

        FreeVRAMStagingMemory((const void*)(*(Struct_020439b0_6**)(arg0 + Enum_020439b0_52))->unknown_8_);

        if (controller->active == 0) {
            InitCombatSlots02043040((MessageSystem*)self);
            MessageSystem_Stop(self);
            ResetControllerState020430b0((MessageSystem*)self);
        }
    }

    if ((
#if defined(jpn)
            var0->unknown_17ff_.unknown_0_0_
#else
            var0->unknown_19ce_
#endif
        ) != 0 && var0->unknown_44_ == 0) {
        func_0204394c((struct Struct_0204394c*)(var0->unknown_1e28_));
    }
    {
        int var29;
        for (var29 = 0; var29 < 2; var29++) {
            func_020e2cc4((Struct_020439b0*)&var0->unknown_1964_[var29], 0);
        }
    }

    if (arg1 != 0 && var0->unknown_998_ == 0) return;
    {
        void* var30 = var0->unknown_1e28_;
        if (var30 != 0) {
            Struct_0204166c* var31;
            int var32;
            for (var32 = 0; var32 < 0x80; var32++) {
                if (var0->unknown_17b8_[var32] != 0) {
                    var31 = &var0->unknown_9b8_[var32];
                    if (var31->unknown_16_0_) {
                        if (var0->unknown_19cc_ != 0 || (
#if defined(jpn)
            var0->unknown_17ff_.unknown_0_0_
#else
            var0->unknown_19ce_
#endif
        ) != 0) {
                            var31->unknown_16_0_ = 0;
                        } else {
                            VramState_Restore((char*)controller->encoder);
                            DisableField16Bit002041754(entry);
                            VramState_Save((char*)controller->encoder);
                        }
                        func_02042af4((int)arg0, var0->unknown_2cc_, var31->unknown_8_);
                    }
                }
            }
        }
    }

    if ((*(Struct_020439b0_5*)(arg0 + Enum_020439b0_2324)).unknown_8_ >= 2) {
        func_020e2d2c((Struct_020439b0_3*)&var0->unknown_1964_[0], 4, 0x76, 0xf8, 0x46);
        if ((*(unsigned char*)(arg0 + Enum_020439b0_6498)) != 0) {
            func_020e2cc4((Struct_020439b0*)&var0->unknown_1964_[0], 1);
        }
    }

    if ((*(int*)(arg0 + Enum_020439b0_332)) >= 2) {
        int var33 = (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_0_;
        int var34 = (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_2_;
        int var35 = (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_4_;
        int var36 = (*(Struct_020439b0_7*)(arg0 + Enum_020439b0_324)).unknown_6_;
        func_020e2d2c((Struct_020439b0_3*)&var0->unknown_1964_[1], var33 + 2, var34 + 2, var35 - 4, var36 - 4);
        if ((*(unsigned char*)(arg0 + Enum_020439b0_6498)) != 0) {
            func_020e2cc4((Struct_020439b0*)&var0->unknown_1964_[1], 1);
        }
    }

    int var37;
    for (var37 = 0; var37 < 2; var37++) {
        func_020e2c34((Struct_020439b0_4*)&var0->unknown_1964_[var37]);
    }
}
