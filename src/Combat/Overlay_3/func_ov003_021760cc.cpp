#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include <globaldefs.h>

struct Struct_0201099c_10;
struct Struct_0201099c_3;

struct Struct_ov003_021760cc {
    char unknown_0_[0x1a];
    unsigned short unknown_1a_;
};
struct Struct_ov003_021760cc_3 {
    void *unknown_0_;
    void *unknown_4_;
    int unknown_8_;
};
struct Struct_ov003_021760cc_4 {
#if defined(jpn)
    char unknown_0_[0x2c];
    char *unknown_2c_;
    char *unknown_30_;
    char unknown_34_[0x868 - 0x34];
    int unknown_868_;
    int unknown_86c_;
    int unknown_870_;
#else
    char unknown1_0_[0x10];
    void *unknown_10_;
    char unknown_14_[4];
    void *unknown_18_;
    char unknown_1c_[0x60 - 0x1c];
    char *unknown_60_;
    char *unknown_64_;
    char unknown_68_[0x998 - 0x68];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
#endif
};
struct Struct_ov003_021760cc_5 {
    char unknown_0_[0xc];
    char unknown_c_[0x74 - 0xc];
    char unknown_74_[0x800];
    char unknown_874_[0xfec - 0x874];
    int unknown_fec_;
    int unknown_ff0_;
    char unknown_ff4_[0x1004 - 0xff4];
    short unknown_1004_;
    char unknown_1006_[0x1036 - 0x1006];
    short unknown_1036_;
    short unknown_1038_;
    short unknown_103a_;
    unsigned char unknown_103c_;
    char unknown_103d_;
    unsigned char unknown_103e_;
    unsigned char unknown_103f_;
    unsigned char unknown_1040_;
    char unknown_1041_[2];
    signed char unknown_1043_;
    char unknown_1044_[2];
    unsigned short unknown_1046_;
    short unknown_1048_;
};

extern "C" int func_02042058(char *, const char *);
extern "C" Struct_ov003_021760cc_4 *func_020421a0();
extern "C" void __clear(void *, int);
void Clear12Bytes020e46c4(void *);
extern "C" void func_020e5334(Loaded021760cc *, void *, unsigned int, int);
extern "C" void func_02046380(Messages021760cc *);
void InitObjFromCombatantId020e4bf4(void *, int);
Element021760cc *FindElementByKey020dedd0(Container020dedd0 *, int);
int ComputeRatio_02175898(char *, void *);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(StoreStruct *, int, int);
const char *KeyTable_Get(Container020e0310 *, int);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov003_021760cc_4 *, const char *, int);
#else
extern "C" void func_0204500c(Struct_ov003_021760cc_4 *, const char *, int, int);
#endif
extern "C" void func_ov003_021749c0(char *);
extern "C" void func_02043204(char *);
extern "C" void func_02043124(Struct_ov003_021760cc_4 *);

extern const char data_ov003_02180b9f[];
extern const char data_ov003_02180bb5[];

#if defined(jpn)
struct Struct_ov003_021760cc_2 {
    char unknown_0_[0xc];
    char unknown_c_[0x7ec - 0xc];
    unsigned char unknown_7ec_;
    char unknown_7ed_[3];
    char unknown_7f0_[0xf68 - 0x7f0];
    int unknown_f68_;
    int unknown_f6c_;
    char unknown_f70_[0xf80 - 0xf70];
    short unknown_f80_;
    char unknown_f82_[0xfb2 - 0xf82];
    short unknown_fb2_;
    short unknown_fb4_;
    short unknown_fb6_;
    unsigned char unknown_fb8_;
    char unknown_fb9_;
    unsigned char unknown_fba_;
    unsigned char unknown_fbb_;
    unsigned char unknown_fbc_;
    char unknown_fbd_[2];
    signed char unknown_fbf_;
    char unknown_fc0_[2];
    unsigned short unknown_fc2_;
    short unknown_fc4_;
};
struct Struct_02046574_2;
extern "C" void func_02046574(Struct_02046574_2 *, int, char *);
extern "C" char *func_020e046c(char *arg0, void *arg1, unsigned int arg2, int arg3);
extern const char data_ov003_0217eddd[];
extern const unsigned char data_ov003_0217e326[];
extern const unsigned char data_ov003_0217e320[];

// USA: func_ov003_021760cc
extern "C" ARM void func_ov003_021760cc(Struct_ov003_021760cc_2 *arg0) {
    BackgroundLoader *var0 = BackgroundLoader::GetInstance();
    Struct_ov003_021760cc_4 *var1   = func_020421a0();
    if (arg0->unknown_fbc_ == 0) {
        if (arg0->unknown_f68_ > 0) {
            var0->RemoveTask(arg0->unknown_f68_);
            arg0->unknown_f68_ = -1;
        }
        arg0->unknown_f68_ = var0->QueueLoadFile(data_ov003_0217eddd, 0);
        arg0->unknown_fbc_++;
    } else if (arg0->unknown_fbc_ == 1) {
        if (var0->GetTaskStatus(arg0->unknown_f68_)) {
            char var2[0x40];
            __clear(var2, 0x40);
            void *var3;
            unsigned int var4;
            var0->GetLoadedFileByID(arg0->unknown_f68_, &var3, &var4);
            if (var3) {
                if (arg0->unknown_fb2_ == 0x1e && arg0->unknown_fc4_ != -1) {
                    func_020e046c(var2, var3, var4, arg0->unknown_fc4_);
                } else {
                    func_020e046c(var2, var3, var4, arg0->unknown_fb6_);
                }
            }
            var0->RemoveTask(arg0->unknown_f68_);
            short var5 = arg0->unknown_fb2_;
            func_02046380(var1);
            GameObject *var6 = GameState::GetInstance()->GetPartyMemberByIndex(arg0->unknown_fbf_);
            if (var6) {
                func_02046574((Struct_02046574_2 *) var1, 0, (char *) var6->baseStats_);
            }
            Struct_ov003_021760cc *var7 = func_020dedd0((Struct_0201099c_10 *) arg0->unknown_7f0_, arg0->unknown_fb6_);
            if (var7) {
                int var8;
                if (arg0->unknown_f80_ == 4) {
                    var8 = func_ov003_02175898((char *) arg0, var7);
                } else {
                    var8 = var7->unknown_1a_;
                }
                var8 *= arg0->unknown_fb8_;
                func_02046574((Struct_02046574_2 *) var1, 1, var2);
                func_020465c0((Struct_020465c0 *) var1, 0, var8);
                func_020465c0((Struct_020465c0 *) var1, 1, arg0->unknown_fb8_);
            }
            unsigned char kind = menu->kind;
            char *first  = (char *) KeyTable_Get((Container020e0310 *) menu->messages, (short) (data_ov003_0217e326[kind] + 0x25));
            char *second = (char *) KeyTable_Get((Container020e0310 *) menu->messages, (short) (data_ov003_0217e320[kind] + 0x25));
            SetIndexedName02046574((Obj02046574 *) msgs, 2, first);
            SetIndexedName02046574((Obj02046574 *) msgs, 3, second);
            if (menu->flags & 0x200) {
                char *text = msgs->text;
                AppendString02042058(text, KeyTable_Get((Container020e0310 *) menu->messages, cur));
                char *buffer = msgs->buffer;
                memset(buffer, 0, 0x800);
                memcpy(buffer, text, 0x800);
                func_0204500c(msgs, buffer, 0);
                menu->flags &= ~0x200;
            } else {
                func_0204500c(msgs, KeyTable_Get((Container020e0310 *) menu->messages, cur), 0);
            }
            var1->unknown_86c_ = arg0->unknown_f6c_;
            var1->unknown_868_     = 1;
            arg0->unknown_fbc_++;
        }
    } else if (arg0->unknown_fbc_ == 2) {
        if (!(arg0->unknown_fc2_ & 0x40)) {
            if (var1->unknown_868_ == 0) {
                arg0->unknown_fb2_       = arg0->unknown_fb4_;
                arg0->unknown_fb4_      = -1;
                arg0->unknown_fba_ = 9;
                arg0->unknown_fbb_ = 0;
                if (arg0->unknown_fc2_ & 0x2000) {
                    func_ov003_021749c0((char *) arg0);
                    arg0->unknown_fc2_ &= ~0x2000;
                }
            } else if (var1->unknown_870_ == 3) {
                *(unsigned char *) ((char *) func_020421a0() + 0x17de) = 0;
                arg0->unknown_fb2_  = arg0->unknown_fb4_;
                arg0->unknown_fb4_ = -1;
                if (arg0->unknown_fb2_ < 0) {
                    if (arg0->unknown_fc2_ & 0x20) {
                        func_02043204((char *) var1);
                        func_02043124(var1);
                        arg0->unknown_fc2_ &= ~0x20;
                    }
                    if (arg0->unknown_fc2_ & 0x2000) {
                        func_ov003_021749c0((char *) arg0);
                        arg0->unknown_fc2_ &= ~0x2000;
                    }
                }
                arg0->unknown_fbc_ = 0;
            }
        }
    }
}
#else
// USA: func_ov003_021760cc
extern "C" ARM void func_ov003_021760cc(Struct_ov003_021760cc_5 *arg0) {
    BackgroundLoader *var14 = BackgroundLoader::GetInstance();
    Struct_ov003_021760cc_4 *var15   = func_020421a0();
    if (arg0->unknown_1040_ == 0) {
        if (arg0->unknown_fec_ >= 0) {
            var14->RemoveTask(arg0->unknown_fec_);
            arg0->unknown_fec_ = -1;
        }
        arg0->unknown_fec_ = var14->QueueLoadFileInGP2(data_ov003_02180b9f, data_ov003_02180bb5, 0);
        arg0->unknown_1040_++;
    } else if (arg0->unknown_1040_ == 1) {
        if (var14->GetTaskStatus(arg0->unknown_fec_)) {
            char var16[0x48];
            char var17[0x48];
            Struct_ov003_021760cc_3 var18;
            __clear(var16, 0x48);
            __clear(var17, 0x48);
            func_020e46c4(&var18);
            var18.unknown_0_ = var16;
            var18.unknown_4_ = var17;
            char var19[12];
            void *var20;
            unsigned int var21;
            var14->GetLoadedFileByID(arg0->unknown_fec_, &var20, &var21);
            if (var20) {
                if (arg0->unknown_1036_ == 0x1e && arg0->unknown_1048_ != -1) {
                    func_020e5334(&var18, var20, var21, arg0->unknown_1048_);
                } else {
                    func_020e5334(&var18, var20, var21, arg0->unknown_103a_);
                }
            }
            var14->RemoveTask(arg0->unknown_fec_);
            arg0->unknown_fec_ = -1;
            short var22  = arg0->unknown_1036_;
            func_02046380(var15);
            func_020e4bf4(var19, arg0->unknown_1043_);
            var15->unknown_10_             = var19;
            Struct_ov003_021760cc *var23 = func_020dedd0(
                (Struct_0201099c_10 *) (arg0->unknown_74_ + 0x800), arg0->unknown_103a_);
            if (var23) {
                int var24 = (arg0->unknown_1004_ == 4 ? func_ov003_02175898((char *) arg0, var23) : var23->unknown_1a_);
                var24 *= arg0->unknown_103c_;
                func_020465c0((Struct_020465c0 *) var15, 0, var24);
                func_020465c0((Struct_020465c0 *) var15, 1, arg0->unknown_103c_);
            }
            msgs->loaded = &loaded;
            if (menu->flags & 0x200) {
                char *text = msgs->text;
                AppendString02042058(
                    text, KeyTable_Get((Container020e0310 *) (menu->messages), cur));
                char *buffer = msgs->buffer;
                memset(buffer, 0, 0x960);
                memcpy(buffer, text, 0x960);
                func_0204500c(msgs, buffer, 0, 0xe3);
                menu->flags &= ~0x200;
            } else {
                func_0204500c(msgs,
                              KeyTable_Get((Container020e0310 *) (menu->messages), cur), 0,
                              0xe3);
            }
            var15->unknown_99c_ = arg0->unknown_ff0_;
            var15->unknown_998_     = 1;
            arg0->unknown_1040_++;
        }
    } else if (arg0->unknown_1040_ == 2) {
        if (!(arg0->unknown_1046_ & 0x40)) {
            if (var15->unknown_998_ == 0) {
                arg0->unknown_1036_       = arg0->unknown_1038_;
                arg0->unknown_1038_      = -1;
                arg0->unknown_103e_ = 9;
                arg0->unknown_103f_ = 0;
                if (arg0->unknown_1046_ & 0x2000) {
                    func_ov003_021749c0((char *) arg0);
                    arg0->unknown_1046_ &= ~0x2000;
                }
            } else if (var15->unknown_9a0_ == 3) {
                *(unsigned char *) ((char *) func_020421a0() + 0x19ae) = 0;
                arg0->unknown_1036_                                                                = arg0->unknown_1038_;
                arg0->unknown_1038_                                                               = -1;
                if (arg0->unknown_1036_ < 0) {
                    if (arg0->unknown_1046_ & 0x20) {
                        func_02043204((char *) var15);
                        func_02043124(var15);
                        arg0->unknown_1046_ &= ~0x20;
                    }
                    if (arg0->unknown_1046_ & 0x2000) {
                        func_ov003_021749c0((char *) arg0);
                        arg0->unknown_1046_ &= ~0x2000;
                    }
                }
                arg0->unknown_1040_ = 0;
            }
        }
    }
}
#endif
