#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Util/Random.h"
#include "Input/Input.h"

struct Struct_ov000_0217df08 { char* unknown_0_; char* unknown_4_; unsigned int unknown_8_; };

struct Struct_ov000_0217df08_2 {
    char unknown_0_[0xa];
    unsigned short unknown_a_0_ : 7;
    unsigned short unknown_a_7_ : 9;
};

struct Struct_ov000_0217df08_6 {
    char unknown_0_[0x144];
    Struct_ov000_0217df08_2* unknown_144_;
};

struct Struct_ov000_0217df08_7 {
    char unknown_0_[0xc];
    short unknown_c_;
};

struct Struct_ov000_0217df08_8 {
    char unknown_0_[0x10];
    void* unknown_10_;
    char unknown_14_[0x20 - 0x14];
    Struct_ov000_0217df08* unknown_20_;
    char unknown_24_[0x30 - 0x24];
    signed char unknown_30_;
    signed char unknown_31_;
    char unknown_32_[0x5c - 0x32];
    char* unknown_5c_;
    char* unknown_60_;
    char unknown_64_[0x998 - 0x64];
    int unknown_998_;
};

struct Struct_ov000_0217df08_9 {
    char unknown_0_[0xb8];
    char unknown_b8_[0x90c - 0xb8];
    int unknown_90c_;
    char unknown_910_[0x950 - 0x910];
    int unknown_950_;
    unsigned char unknown_954_;
    unsigned char unknown_955_;
    char unknown_956_[0x1d3c - 0x956];
    int unknown_1d3c_[8];
    char unknown_1d5c_[0x1d60 - 0x1d5c];
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    char unknown_1d69_[0x1d70 - 0x1d69];
    unsigned char unknown_1d70_;
    char unknown_1d71_;
    unsigned short unknown_1d72_;
};

Messages0217df08* GetGlobalField0x1c020421a0();
extern "C" Node0217df08* func_ov000_02161318(void* obj, int id);
int IsFlag0x28Bit0Set_ov000_02171a60(void*);
void Clear12Bytes020e46c4(void*);
struct Container020e0310;
const char* KeyTable_Get(Container020e0310*, int);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int sprintf(char* buffer, const char* format, ...);
Combatant0217df08* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(NameParts0217df08*, Combatant0217df08*, int);
extern "C" int func_ov000_0217ff34(void* self, int id, int* amount);
extern "C" void func_02046380(Messages0217df08*);
void InitObjFromCombatantId020e4bf4(void*, int);
void AppendString02042058(char*, const char*);
extern "C" char* func_020e046c(char* buf, void* data, unsigned int size, int idx);
extern "C" void func_02046608(Messages0217df08*, int, char*, char*, int, int, int);
extern "C" void __clear(void*, int);
extern "C" void func_ov000_0217aa08(char*, char*);
extern "C" void func_020e4f18(Struct_ov000_0217df08*, Struct_ov000_0217df08*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_ov000_0217df08_8*, char*, int, int);
#endif
extern "C" void func_02043124(Struct_ov000_0217df08_8*);
extern "C" void func_02043204(char*);
#if !defined(jpn)
extern "C" void func_ov000_0217c638(Struct_ov000_0217df08_9* arg0, int arg1, int arg2);
#endif
#if !defined(jpn)
extern "C" void func_ov000_02176e3c(Struct_ov000_0217df08_9* arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
#endif

extern const char data_ov000_02184070[];
extern const char data_ov000_0218408a[];

#if defined(jpn)
struct Struct_ov000_0217df08_3 {
    char unknown_0_[0x144];
    Struct_ov000_0217df08_2* unknown_144_;
    char unknown_148_[0x14c - 0x148];
    char unknown_14c_[1];
};

struct Struct_ov000_0217df08_4 {
    char unknown_0_[0x28];
    char* unknown_28_;
    char* unknown_2c_;
    char unknown_30_[0x868 - 0x30];
    int unknown_868_;
};

struct Struct_ov000_0217df08_5 {
    char unknown_0_[0xb8];
    char unknown_b8_[0x90c - 0xb8];
    int unknown_90c_;
    char unknown_910_[0x950 - 0x910];
    int unknown_950_;
    unsigned char unknown_954_;
    unsigned char unknown_955_;
    char unknown_956_[0x1f74 - 0x956];
    int unknown_1f74_[8];
    char unknown_1f94_[0x1f98 - 0x1f94];
    signed char unknown_1f98_[8];
    signed char unknown_1fa0_;
    char unknown_1fa1_[0x1fa8 - 0x1fa1];
    unsigned char unknown_1fa8_;
    char unknown_1fa9_;
    unsigned short unknown_1faa_;
};

struct Struct_02046574_2;
extern "C" void func_02046574(Struct_02046574_2*, int, char*);
extern "C" void func_020474a8(Struct_ov000_0217df08_4*, int, char*, char*);
extern "C" void func_0204500c(Struct_ov000_0217df08_4*, char*, int);
extern "C" void func_ov000_0217c638(Struct_ov000_0217df08_5* arg0, int arg1, int arg2);
extern "C" void func_ov000_02176e3c(Struct_ov000_0217df08_5* arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern const char data_ov000_021851cc[];

// USA: func_ov000_0217df08
extern "C" ARM void func_ov000_0217df08(Struct_ov000_0217df08_5* arg0, int arg1, int arg2) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov000_0217df08_4* var1 = (Struct_ov000_0217df08_4*)func_020421a0();
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();

    if (arg0->unknown_1fa8_ == 0) {
        if (arg0->unknown_90c_ >= 0) {
            var2->RemoveTask(arg0->unknown_90c_);
            arg0->unknown_90c_ = -1;
        }
        self->taskId = loader->QueueLoadFile(data_ov000_021851cc, 0);
        self->state++;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->taskId, &data, &size);
            if (data != 0) {
                const char* separator = KeyTable_Get((Container020e0310*)self->messages, 6);
                char* work = g->work;
                char* text = g->text;
                memset(work, 0, 0x800);
                memset(text, 0, 0x800);
                int best = -1;
                char* bestName = 0;
                int appended;
                int i;
                int j;
                CombatantJ0217df08* c;
                int msg;
                Rank0217df08* rank;
                for (i = 0; i < arg2; i++) {
                    CombatantJ0217df08* c = (CombatantJ0217df08*)GetCombatantWithFlag0x400_0200fea4(gs, self->combatantIds[i]);
                    if (c != 0) {
                        rank = c->rank;
                        if (rank == 0) {
                            return;
                        }
                        if (var8 < var15->unknown_a_0_) {
                            var8 = var15->unknown_a_0_;
                            var9 = var16->unknown_14c_;
                        }
                    }
                }
                var10 = 0;
                for (var12 = 0; var12 < arg2; var12++) {
                    var13 = (Struct_ov000_0217df08_3*)func_0200fea4(var0, arg0->unknown_1f74_[var12]);
                    if (var13 != 0) {
                        int var17 = -1;
                        var14 = func_ov000_0217ff34(arg0, arg0->unknown_1f74_[var12], &var17);
                        if (var14 >= 0) {
                            char* var18 = 0;
                            GameObject* var19 = var0->GetPartyMemberByIndex(var17);
                            if (var19 != 0) {
                                var18 = *(char**)((char*)var19 + 0x134);
                            }
                            func_02046380((Struct_ov000_0217df08_8*)var1);
                            func_02046574((Struct_02046574_2*)var1, 0, var13->unknown_14c_);
                            func_02046574((Struct_02046574_2*)var1, 1, var18);
                            if (var10 != 0) {
                                func_02042058(var7, var5);
                            }
                            var10 = 1;
                            memset(var6, 0, 0x800);
                            func_020e046c(var6, var3, var4, var14);
                            func_02042058(var7, var6);
                            memset(var6, 0, 0x800);
                            func_020474a8(var1, 0xc, var7, var6);
                            memset(var7, 0, 0x800);
                            sprintf(var7, var6);
                        }
                    }
                }
                if (var10 == 0) {
                    short var20 = 0;
                    var20 = var20 + (NextRandomMax(GetBTRandom(), 100) & 1);
                    if (arg0->unknown_950_ == 0 && arg0->unknown_954_ == 1) {
                        var20 = arg0->unknown_955_ + 0x3c;
                    }
                    if (arg2 > 1) {
                        var20 = var20 + 2;
                    }
                    char var21[0x40];
                    __clear(var21, 0x40);
                    if (var9 != 0) {
                        func_ov000_0217aa08(var9, var21);
                    }
                    func_02046380((Struct_ov000_0217df08_8*)var1);
                    func_02046574((Struct_02046574_2*)var1, 2, var21);
                    func_020e046c(var7, var3, var4, var20);
                    func_020474a8(var1, 0xc, var7, var6);
                }
                func_0204500c(var1, var6, 0);
                var1->unknown_868_ = 1;
            }
            var2->RemoveTask(arg0->unknown_90c_);
            arg0->unknown_90c_ = -1;
            arg0->unknown_1fa8_++;
        }
    } else if (arg0->unknown_1fa8_ == 2) {
        if (var1->unknown_868_ == 0 || g_keyManager.TestKeysPressed(0x800) != 0) {
            func_02043124((Struct_ov000_0217df08_8*)var1);
            func_02043204((char*)var1);
            arg0->unknown_1fa8_ = 0;
            arg0->unknown_1f98_[arg0->unknown_1fa0_] = 0;
            arg0->unknown_1fa0_ = arg0->unknown_1fa0_ - 1;
            func_ov000_0217c638(arg0, arg1, arg2);
            arg0->unknown_1faa_ |= 0x100;
            func_ov000_02176e3c(arg0, 0, 1, arg1, arg2, 0);
        }
    }
}
#else
// USA: func_ov000_0217df08
extern "C" ARM void func_ov000_0217df08(Struct_ov000_0217df08_9* arg0, int arg1, int arg2) {
    GameState* var22 = GameState::GetInstance();
    Struct_ov000_0217df08_8* var23 = func_020421a0();
    BackgroundLoader* var24 = BackgroundLoader::GetInstance();

    if (arg0->unknown_1d70_ == 0) {
        if (arg0->unknown_90c_ >= 0) {
            var24->RemoveTask(arg0->unknown_90c_);
            arg0->unknown_90c_ = -1;
        }
        arg0->unknown_90c_ = var24->QueueLoadFileInGP2(data_ov000_02184070, data_ov000_0218408a, 0);
        arg0->unknown_1d70_++;
    } else if (arg0->unknown_1d70_ == 1) {
        if (var24->GetTaskStatus(arg0->unknown_90c_) != 0) {
            void* var25;
            unsigned int var26;
            var24->GetLoadedFileByID(arg0->unknown_90c_, &var25, &var26);
            if (var25 != 0) {
                signed char var27 = 0;
                signed char var28 = 0;
                for (int var29 = 0; var29 < 4; var29++) {
                    Struct_ov000_0217df08_7* var30 = func_ov000_02161318(arg0, var29);
                    if (var30 != 0) {
                        var27++;
                        if (!func_ov000_02171a60(var30)) {
                            if (var30->unknown_c_ != 0) {
                                var28++;
                            }
                        }
                    }
                }
                NameParts0217df08 names;
                NameParts0217df08 parts;
                NameParts0217df08 original;
                Clear12Bytes020e46c4(&names);
                Clear12Bytes020e46c4(&parts);
                const char* separator = KeyTable_Get((Container020e0310*)self->messages, 6);
                char* work = g->work;
                char* text = g->text;
                memset(work, 0, 0x960);
                memset(text, 0, 0x960);
                int best = -1;
                int i;
                int j;
                int appended;
                int msg;
                Rank0217df08* rank;
                for (i = 0; i < arg2; i++) {
                    Combatant0217df08* c = GetCombatantWithFlag0x400_0200fea4(gs, self->combatantIds[i]);
                    if (c != 0) {
                        rank = c->rank;
                        if (rank == 0) {
                            return;
                        }
                        if (var37 < var42->unknown_a_0_) {
                            func_020e4ce8(&var32, var43, 1);
                            func_020e4ce8(&var33, var43, 0);
                            var37 = var42->unknown_a_0_;
                        }
                    }
                }
                var40 = 0;
                for (var39 = 0; var39 < arg2; var39++) {
                    Struct_ov000_0217df08_6* var44 = func_0200fea4(var22, arg0->unknown_1d3c_[var39]);
                    if (var44 != 0) {
                        int var45 = -1;
                        var41 = func_ov000_0217ff34(arg0, arg0->unknown_1d3c_[var39], &var45);
                        if (var41 >= 0) {
                            func_02046380(var23);
                            func_020e4ce8(&var32, var44, 1);
                            func_020e4ce8(&var33, var44, 0);
                            func_020e4bf4(&var31, var45);
                            var23->unknown_20_ = &var32;
                            var23->unknown_10_ = &var31;
                            if (var40 != 0) {
                                func_02042058(var36, var34);
                            }
                            var40 = 1;
                            memset(var35, 0, 0x960);
                            func_020e046c(var35, var25, var26, var41);
                            func_02042058(var36, var35);
                            memset(var35, 0, 0x960);
                            var23->unknown_30_ = var27;
                            var23->unknown_31_ = var28;
                            func_02046608(var23, 0xc, var36, var35, 0xe3, 0, 1);
                            memset(var36, 0, 0x960);
                            sprintf(var36, var35);
                        }
                    }
                }
                if (var40 == 0) {
                    short var46 = 0;
                    var46 = var46 + (NextRandomMax(GetBTRandom(), 100) & 1);
                    if (arg0->unknown_950_ == 0 && arg0->unknown_954_ == 1) {
                        var46 = arg0->unknown_955_ + 0x3c;
                    }
                    if (arg2 > 1) {
                        var46 = var46 + 2;
                    }
                    func_02046380(var23);
                    char var47[0x80];
                    __clear(var47, 0x80);
                    char var48[0x80];
                    __clear(var48, 0x80);
                    func_ov000_0217aa08(var32.unknown_0_, var47);
                    func_ov000_0217aa08(var32.unknown_4_, var48);
                    var32.unknown_0_ = var47;
                    var32.unknown_4_ = var48;
                    func_020e4f18(&var33, &var32, 2);
                    var32.unknown_8_ &= ~0x80000000;
                    var23->unknown_20_ = &var32;
                    func_020e046c(var36, var25, var26, var46);
                    var23->unknown_30_ = var27;
                    var23->unknown_31_ = var28;
                    func_02046608(var23, 0xc, var36, var35, 0xe3, 0, 1);
                }
                var23->unknown_30_ = var27;
                var23->unknown_31_ = var28;
                func_0204500c(var23, var35, 0, 0xe3);
                var23->unknown_998_ = 1;
                var23->unknown_30_ = -1;
            }
            var24->RemoveTask(arg0->unknown_90c_);
            arg0->unknown_90c_ = -1;
            arg0->unknown_1d70_++;
        }
    } else if (arg0->unknown_1d70_ == 2) {
        if (var23->unknown_998_ == 0 || g_keyManager.TestKeysPressed(0x800) != 0) {
            func_02043124(var23);
            func_02043204((char*)var23);
            arg0->unknown_1d70_ = 0;
            arg0->unknown_1d60_[arg0->unknown_1d68_] = 0;
            arg0->unknown_1d68_ = arg0->unknown_1d68_ - 1;
            func_ov000_0217c638(arg0, arg1, arg2);
            arg0->unknown_1d72_ |= 0x100;
            func_ov000_02176e3c(arg0, 0, 1, arg1, arg2, 0);
        }
    }
}
#endif
