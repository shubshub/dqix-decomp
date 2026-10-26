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

Messages0217df08* MessageSystem_GetInstance();
extern "C" Node0217df08* func_ov000_02161318(void* obj, int id);
int IsFlag0x28Bit0Set_ov000_02171a60(void*);
void NameText_Clear(void*);
struct Container020e0310;
const char* KeyTable_Get(Container020e0310*, int);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int sprintf(char* buffer, const char* format, ...);
Combatant0217df08* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(NameParts0217df08*, Combatant0217df08*, int);
extern "C" int func_ov000_0217ff34(void* self, int id, int* amount);
extern "C" void func_02046380(Messages0217df08*);
void NameText_InitFromPartyMember(void*, int);
void Text_Append(char*, const char*);
extern "C" char* func_020e046c(char* buf, void* data, unsigned int size, int idx);
extern "C" void MessageSystem_FormatText(Messages0217df08*, int, char*, char*, int, int, int);
extern "C" void __clear(void*, int);
extern "C" void func_ov000_0217aa08(char*, char*);
extern "C" void func_020e4f18(Struct_ov000_0217df08*, Struct_ov000_0217df08*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_ov000_0217df08_8*, char*, int, int);
#endif
extern "C" void MessageSystem_Stop(Messages0217df08*);
void MessageSystem_Reset(char*);
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

struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020474a8(MessagesJ0217df08*, int, char*, char*);
extern "C" void func_0204500c(MessagesJ0217df08*, char*, int);
extern "C" void func_ov000_0217c638(BattleJ0217df08* obj, int arg1, int arg2);
extern "C" void func_ov000_02176e3c(BattleJ0217df08* obj, int zero, int val, int arg1, int arg2, int one);
extern const char data_ov000_021851cc[];

// USA: func_ov000_0217df08
extern "C" ARM void func_ov000_0217df08(BattleJ0217df08* self, int arg1, int arg2) {
    GameState* gs = GameState::GetInstance();
    MessagesJ0217df08* g = (MessagesJ0217df08*)MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

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
                            func_02046380((Messages0217df08*)g);
                            MessageSystem_SetStringArgument((Obj02046574*)g, 0, c->name);
                            MessageSystem_SetStringArgument((Obj02046574*)g, 1, memberName);
                            if (appended != 0) {
                                Text_Append(text, separator);
                            }
                            appended = 1;
                            memset(work, 0, 0x800);
                            func_020e046c(work, data, size, msg);
                            Text_Append(text, work);
                            memset(work, 0, 0x800);
                            func_020474a8(g, 0xc, text, work);
                            memset(text, 0, 0x800);
                            sprintf(text, work);
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
                    func_02046380((Messages0217df08*)g);
                    MessageSystem_SetStringArgument((Obj02046574*)g, 2, name);
                    func_020e046c(text, data, size, msg);
                    func_020474a8(g, 0xc, text, work);
                }
                func_0204500c(var1, var6, 0);
                var1->unknown_868_ = 1;
            }
            var2->RemoveTask(arg0->unknown_90c_);
            arg0->unknown_90c_ = -1;
            arg0->unknown_1fa8_++;
        }
    } else if (self->state == 2) {
        if (g->active == 0 || g_keyManager.TestKeysPressed(0x800) != 0) {
            MessageSystem_Stop((Messages0217df08*)g);
            MessageSystem_Reset((char*)g);
            self->state = 0;
            self->commands[self->index] = 0;
            self->index = self->index - 1;
            func_ov000_0217c638(self, arg1, arg2);
            self->flags |= 0x100;
            func_ov000_02176e3c(self, 0, 1, arg1, arg2, 0);
        }
    }
}
#else
// USA: func_ov000_0217df08
extern "C" ARM void func_ov000_0217df08(Battle0217df08* self, int arg1, int arg2) {
    GameState* gs = GameState::GetInstance();
    Messages0217df08* g = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

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
                NameText_Clear(&names);
                NameText_Clear(&parts);
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
                appended = 0;
                for (j = 0; j < arg2; j++) {
                    Combatant0217df08* c = GetCombatantWithFlag0x400_0200fea4(gs, self->combatantIds[j]);
                    if (c != 0) {
                        int amount = -1;
                        msg = func_ov000_0217ff34(self, self->combatantIds[j], &amount);
                        if (msg >= 0) {
                            func_02046380(g);
                            func_020e4ce8(&parts, c, 1);
                            func_020e4ce8(&original, c, 0);
                            NameText_InitFromPartyMember(&names, amount);
                            g->parts = &parts;
                            g->names = &names;
                            if (appended != 0) {
                                Text_Append(text, separator);
                            }
                            appended = 1;
                            memset(work, 0, 0x960);
                            func_020e046c(work, data, size, msg);
                            Text_Append(text, work);
                            memset(work, 0, 0x960);
                            g->count30 = present;
                            g->count31 = ready;
                            MessageSystem_FormatText(g, 0xc, text, work, 0xe3, 0, 1);
                            memset(text, 0, 0x960);
                            sprintf(text, work);
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
                    func_02046380(g);
                    char singular[0x80];
                    __clear(singular, 0x80);
                    char plural[0x80];
                    __clear(plural, 0x80);
                    TrimTrailingLetterCode_0217aa08(parts.singular, singular);
                    TrimTrailingLetterCode_0217aa08(parts.plural, plural);
                    parts.singular = singular;
                    parts.plural = plural;
                    func_020e4f18(&original, &parts, 2);
                    parts.flags &= ~0x80000000;
                    g->parts = &parts;
                    func_020e046c(text, data, size, msg);
                    g->count30 = present;
                    g->count31 = ready;
                    MessageSystem_FormatText(g, 0xc, text, work, 0xe3, 0, 1);
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
    } else if (self->state == 2) {
        if (g->active == 0 || g_keyManager.TestKeysPressed(0x800) != 0) {
            MessageSystem_Stop(g);
            MessageSystem_Reset((char*)g);
            self->state = 0;
            self->commands[self->index] = 0;
            self->index = self->index - 1;
            func_ov000_0217c638(self, arg1, arg2);
            self->flags |= 0x100;
            func_ov000_02176e3c(self, 0, 1, arg1, arg2, 0);
        }
    }
}
#endif
