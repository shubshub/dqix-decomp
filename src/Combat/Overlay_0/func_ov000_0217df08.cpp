#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Util/Random.h"
#include "Input/Input.h"

struct Struct_ov000_0217df08 { char* unknown_0_; char* unknown_4_; unsigned int flags; };

struct Struct_ov000_0217df08_2 {
    char pad0[0xa];
    unsigned short level : 7;
    unsigned short rest : 9;
};

struct Struct_ov000_0217df08_6 {
    char pad0[0x144];
    Struct_ov000_0217df08_2* rank;
};

struct Struct_ov000_0217df08_7 {
    char pad0[0xc];
    short fc;
};

struct Messages0217df08 {
    char pad0[0x10];
    void* names;
    char unknown_14_[0x20 - 0x14];
    Struct_ov000_0217df08* parts;
    char pad24[0x30 - 0x24];
    signed char unknown_30_;
    signed char unknown_31_;
    char unknown_32_[0x5c - 0x32];
    char* work;
    char* text;
    char unknown_64_[0x998 - 0x64];
    int active;
};

struct Struct_ov000_0217df08_9 {
    char pad0[0xb8];
    char messages[0x90c - 0xb8];
    int taskId;
    char unknown_910_[0x950 - 0x910];
    int unknown_950_;
    unsigned char unknown_954_;
    unsigned char unknown_955_;
    char unknown_956_[0x1d3c - 0x956];
    int unknown_1d3c_[8];
    char unknown_1d5c_[0x1d60 - 0x1d5c];
    signed char commands[8];
    signed char index;
    char unknown_1d69_[0x1d70 - 0x1d69];
    unsigned char state;
    char unknown_1d71_;
    unsigned short flags;
};

extern "C" Messages0217df08* MessageSystem_GetInstance();
extern "C" Struct_ov000_0217df08_7* func_ov000_02161318(void* obj, int id);
extern "C" int func_ov000_02171a60(void*);
extern "C" void NameText_Clear(void*);
struct Container020e0310;
extern "C" const char* KeyTable_Get(Container020e0310*, int);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" Struct_ov000_0217df08_6* func_0200fea4(GameState*, int);
extern "C" void func_020e4ce8(Struct_ov000_0217df08*, Struct_ov000_0217df08_6*, int);
extern "C" int func_ov000_0217ff34(void* self, int id, int* amount);
extern "C" void func_02046380(Messages0217df08*);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" void Text_Append(char*, const char*);
extern "C" char* func_020e046c(char* buf, void* data, unsigned int size, int idx);
extern "C" void MessageSystem_FormatText(Messages0217df08*, int, char*, char*, int, int, int);
extern "C" void __clear(void*, int);
extern "C" void func_ov000_0217aa08(char*, char*);
extern "C" void func_020e4f18(Struct_ov000_0217df08*, Struct_ov000_0217df08*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Messages0217df08*, char*, int, int);
#endif
extern "C" void MessageSystem_Stop(Messages0217df08*);
extern "C" void MessageSystem_Reset(char*);
#if !defined(jpn)
extern "C" void func_ov000_0217c638(Struct_ov000_0217df08_9* obj, int arg1, int arg2);
#endif
#if !defined(jpn)
extern "C" void func_ov000_02176e3c(Struct_ov000_0217df08_9* obj, int zero, int val, int arg3, int arg4, int one);
#endif

extern const char data_ov000_02184070[];
extern const char data_ov000_0218408a[];

#if defined(jpn)
struct Struct_ov000_0217df08_3 {
    char pad0[0x144];
    Struct_ov000_0217df08_2* rank;
    char unknown_148_[0x14c - 0x148];
    char name[1];
};

struct MessagesJ0217df08 {
    char pad0[0x28];
    char* work;
    char* text;
    char unknown_30_[0x868 - 0x30];
    int active;
};

struct Struct_ov000_0217df08_5 {
    char pad0[0xb8];
    char messages[0x90c - 0xb8];
    int taskId;
    char unknown_910_[0x950 - 0x910];
    int unknown_950_;
    unsigned char unknown_954_;
    unsigned char unknown_955_;
    char unknown_956_[0x1f74 - 0x956];
    int unknown_1f74_[8];
    char unknown_1f94_[0x1f98 - 0x1f94];
    signed char commands[8];
    signed char index;
    char unknown_1fa1_[0x1fa8 - 0x1fa1];
    unsigned char state;
    char unknown_1fa9_;
    unsigned short flags;
};

struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" void func_020474a8(MessagesJ0217df08*, int, char*, char*);
extern "C" void func_0204500c(MessagesJ0217df08*, char*, int);
extern "C" void func_ov000_0217c638(Struct_ov000_0217df08_5* obj, int arg1, int arg2);
extern "C" void func_ov000_02176e3c(Struct_ov000_0217df08_5* obj, int zero, int val, int arg3, int arg4, int one);
extern const char data_ov000_021851cc[];

// USA: func_ov000_0217df08
extern "C" ARM void func_ov000_0217df08(Struct_ov000_0217df08_5* self, int arg1, int arg2) {
    GameState* gs = GameState::GetInstance();
    MessagesJ0217df08* g = (MessagesJ0217df08*)MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        if (self->taskId >= 0) {
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
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
                char* var9 = 0;
                int appended;
                int i;
                int j;
                Struct_ov000_0217df08_3* c;
                int msg;
                Struct_ov000_0217df08_2* rank;
                for (i = 0; i < arg2; i++) {
                    Struct_ov000_0217df08_3* c = (Struct_ov000_0217df08_3*)func_0200fea4(gs, self->unknown_1f74_[i]);
                    if (c != 0) {
                        rank = c->rank;
                        if (rank == 0) {
                            return;
                        }
                        if (best < rank->level) {
                            best = rank->level;
                            var9 = c->name;
                        }
                    }
                }
                appended = 0;
                for (j = 0; j < arg2; j++) {
                    c = (Struct_ov000_0217df08_3*)func_0200fea4(gs, self->unknown_1f74_[j]);
                    if (c != 0) {
                        int amount = -1;
                        msg = func_ov000_0217ff34(self, self->unknown_1f74_[j], &amount);
                        if (msg >= 0) {
                            char* memberName = 0;
                            GameObject* member = gs->GetPartyMemberByIndex(amount);
                            if (member != 0) {
                                memberName = *(char**)((char*)member + 0x134);
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
                if (appended == 0) {
                    short msg = 0;
                    msg = msg + (NextRandomMax(GetBTRandom(), 100) & 1);
                    if (self->unknown_950_ == 0 && self->unknown_954_ == 1) {
                        msg = self->unknown_955_ + 0x3c;
                    }
                    if (arg2 > 1) {
                        msg = msg + 2;
                    }
                    char name[0x40];
                    __clear(name, 0x40);
                    if (var9 != 0) {
                        func_ov000_0217aa08(var9, name);
                    }
                    func_02046380((Messages0217df08*)g);
                    MessageSystem_SetStringArgument((Obj02046574*)g, 2, name);
                    func_020e046c(text, data, size, msg);
                    func_020474a8(g, 0xc, text, work);
                }
                func_0204500c(g, work, 0);
                g->active = 1;
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
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
extern "C" ARM void func_ov000_0217df08(Struct_ov000_0217df08_9* self, int arg1, int arg2) {
    GameState* gs = GameState::GetInstance();
    Messages0217df08* g = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        if (self->taskId >= 0) {
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
        }
        self->taskId = loader->QueueLoadFileInGP2(data_ov000_02184070, data_ov000_0218408a, 0);
        self->state++;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->taskId, &data, &size);
            if (data != 0) {
                signed char present = 0;
                signed char var28 = 0;
                for (int i = 0; i < 4; i++) {
                    Struct_ov000_0217df08_7* node = func_ov000_02161318(self, i);
                    if (node != 0) {
                        present++;
                        if (!func_ov000_02171a60(node)) {
                            if (node->fc != 0) {
                                var28++;
                            }
                        }
                    }
                }
                Struct_ov000_0217df08 names;
                Struct_ov000_0217df08 parts;
                Struct_ov000_0217df08 original;
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
                Struct_ov000_0217df08_2* rank;
                for (i = 0; i < arg2; i++) {
                    Struct_ov000_0217df08_6* c = func_0200fea4(gs, self->unknown_1d3c_[i]);
                    if (c != 0) {
                        rank = c->rank;
                        if (rank == 0) {
                            return;
                        }
                        if (best < rank->level) {
                            func_020e4ce8(&parts, c, 1);
                            func_020e4ce8(&original, c, 0);
                            best = rank->level;
                        }
                    }
                }
                appended = 0;
                for (j = 0; j < arg2; j++) {
                    Struct_ov000_0217df08_6* c = func_0200fea4(gs, self->unknown_1d3c_[j]);
                    if (c != 0) {
                        int amount = -1;
                        msg = func_ov000_0217ff34(self, self->unknown_1d3c_[j], &amount);
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
                            g->unknown_30_ = present;
                            g->unknown_31_ = var28;
                            MessageSystem_FormatText(g, 0xc, text, work, 0xe3, 0, 1);
                            memset(text, 0, 0x960);
                            sprintf(text, work);
                        }
                    }
                }
                if (appended == 0) {
                    short msg = 0;
                    msg = msg + (NextRandomMax(GetBTRandom(), 100) & 1);
                    if (self->unknown_950_ == 0 && self->unknown_954_ == 1) {
                        msg = self->unknown_955_ + 0x3c;
                    }
                    if (arg2 > 1) {
                        msg = msg + 2;
                    }
                    func_02046380(g);
                    char var47[0x80];
                    __clear(var47, 0x80);
                    char var48[0x80];
                    __clear(var48, 0x80);
                    func_ov000_0217aa08(parts.unknown_0_, var47);
                    func_ov000_0217aa08(parts.unknown_4_, var48);
                    parts.unknown_0_ = var47;
                    parts.unknown_4_ = var48;
                    func_020e4f18(&original, &parts, 2);
                    parts.flags &= ~0x80000000;
                    g->parts = &parts;
                    func_020e046c(text, data, size, msg);
                    g->unknown_30_ = present;
                    g->unknown_31_ = var28;
                    MessageSystem_FormatText(g, 0xc, text, work, 0xe3, 0, 1);
                }
                g->unknown_30_ = present;
                g->unknown_31_ = var28;
                func_0204500c(g, work, 0, 0xe3);
                g->active = 1;
                g->unknown_30_ = -1;
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
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
