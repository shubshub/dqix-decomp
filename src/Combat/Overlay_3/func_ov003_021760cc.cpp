#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include <globaldefs.h>

struct ItemTable;
struct Container020e0310;

struct Element021760cc {
    char pad0[0x1a];
    unsigned short value;
};
struct Struct_ov003_021760cc_3 {
    void *a;
    void *b;
    int c;
};
struct Messages021760cc {
#if defined(jpn)
    char pad0[0x2c];
    char *text;
    char *buffer;
    char unknown_34_[0x868 - 0x34];
    int busy;
    int unknown_86c_;
    int state;
#else
    char pad0[0x10];
    void *target;
    char unknown_14_[4];
    void *loaded;
    char unknown_1c_[0x60 - 0x1c];
    char *text;
    char *buffer;
    char pad68[0x998 - 0x68];
    int busy;
    int unknown_99c_;
    int state;
#endif
};
struct Struct_ov003_021760cc_5 {
    char pad0[0xc];
    char messages[0x74 - 0xc];
    char container[0x800];
    char unknown_874_[0xfec - 0x874];
    int task;
    int unknown_ff0_;
    char unknown_ff4_[0x1004 - 0xff4];
    short mode;
    char unknown_1006_[0x1036 - 0x1006];
    short cur;
    short next;
    short selected;
    unsigned char count;
    char unknown_103d_;
    unsigned char unknown_103e_;
    unsigned char unknown_103f_;
    unsigned char step;
    char unknown_1041_[2];
    signed char character;
    char unknown_1044_[2];
    unsigned short flags;
    short unknown_1048_;
};

extern "C" int Text_Append(char *, const char *);
extern "C" Messages021760cc *MessageSystem_GetInstance();
extern "C" void __clear(void *, int);
extern "C" void NameText_Clear(void *);
extern "C" void func_020e5334(Struct_ov003_021760cc_3 *, void *, unsigned int, int);
extern "C" void func_02046380(Messages021760cc *);
extern "C" void NameText_InitFromPartyMember(void *, int);
extern "C" Element021760cc *ItemTable_Find(ItemTable *, int);
extern "C" int func_ov003_02175898(char *, void *);
struct StoreStruct;
extern "C" void func_020465c0(StoreStruct *, int, int);
extern "C" const char *KeyTable_Get(Container020e0310 *, int);
#if defined(jpn)
extern "C" void func_0204500c(Messages021760cc *, const char *, int);
#else
extern "C" void func_0204500c(Messages021760cc *, const char *, int, int);
#endif
extern "C" void func_ov003_021749c0(char *);
extern "C" void MessageSystem_Reset(char *);
extern "C" void MessageSystem_Stop(Messages021760cc *);

extern const char data_ov003_02180b9f[];
extern const char data_ov003_02180bb5[];

#if defined(jpn)
struct Struct_ov003_021760cc_2 {
    char pad0[0xc];
    char messages[0x7ec - 0xc];
    unsigned char kind;
    char unknown_7ed_[3];
    char container[0xf68 - 0x7f0];
    int task;
    int unknown_f6c_;
    char unknown_f70_[0xf80 - 0xf70];
    short mode;
    char unknown_f82_[0xfb2 - 0xf82];
    short cur;
    short next;
    short selected;
    unsigned char count;
    char unknown_fb9_;
    unsigned char unknown_fba_;
    unsigned char unknown_fbb_;
    unsigned char step;
    char unknown_fbd_[2];
    signed char character;
    char unknown_fc0_[2];
    unsigned short flags;
    short unknown_fc4_;
};
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574 *, int, char *);
extern "C" char *func_020e046c(char *buf, void *data, unsigned int size, int idx);
extern const char data_ov003_0217eddd[];
extern const unsigned char data_ov003_0217e326[];
extern const unsigned char data_ov003_0217e320[];

// USA: func_ov003_021760cc
extern "C" ARM void func_ov003_021760cc(Struct_ov003_021760cc_2 *menu) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Messages021760cc *msgs   = MessageSystem_GetInstance();
    if (menu->step == 0) {
        if (menu->task > 0) {
            loader->RemoveTask(menu->task);
            menu->task = -1;
        }
        menu->task = loader->QueueLoadFile(data_ov003_0217eddd, 0);
        menu->step++;
    } else if (menu->step == 1) {
        if (loader->GetTaskStatus(menu->task)) {
            char title[0x40];
            __clear(title, 0x40);
            void *file;
            unsigned int length;
            loader->GetLoadedFileByID(menu->task, &file, &length);
            if (file) {
                if (menu->cur == 0x1e && menu->unknown_fc4_ != -1) {
                    func_020e046c(title, file, length, menu->unknown_fc4_);
                } else {
                    func_020e046c(title, file, length, menu->selected);
                }
            }
            loader->RemoveTask(menu->task);
            short cur = menu->cur;
            func_02046380(msgs);
            GameObject *member = GameState::GetInstance()->GetPartyMemberByIndex(menu->character);
            if (member) {
                MessageSystem_SetStringArgument((Obj02046574 *) msgs, 0, (char *) member->baseStats_);
            }
            Element021760cc *element = ItemTable_Find((ItemTable *) menu->container, menu->selected);
            if (element) {
                int value;
                if (menu->mode == 4) {
                    value = func_ov003_02175898((char *) menu, element);
                } else {
                    value = element->value;
                }
                value *= menu->count;
                MessageSystem_SetStringArgument((Obj02046574 *) msgs, 1, title);
                func_020465c0((StoreStruct *) msgs, 0, value);
                func_020465c0((StoreStruct *) msgs, 1, menu->count);
            }
            unsigned char kind = menu->kind;
            char *first  = (char *) KeyTable_Get((Container020e0310 *) menu->messages, (short) (data_ov003_0217e326[kind] + 0x25));
            char *second = (char *) KeyTable_Get((Container020e0310 *) menu->messages, (short) (data_ov003_0217e320[kind] + 0x25));
            MessageSystem_SetStringArgument((Obj02046574 *) msgs, 2, first);
            MessageSystem_SetStringArgument((Obj02046574 *) msgs, 3, second);
            if (menu->flags & 0x200) {
                char *text = msgs->text;
                Text_Append(text, KeyTable_Get((Container020e0310 *) menu->messages, cur));
                char *buffer = msgs->buffer;
                memset(buffer, 0, 0x800);
                memcpy(buffer, text, 0x800);
                func_0204500c(msgs, buffer, 0);
                menu->flags &= ~0x200;
            } else {
                func_0204500c(msgs, KeyTable_Get((Container020e0310 *) menu->messages, cur), 0);
            }
            msgs->unknown_86c_ = menu->unknown_f6c_;
            msgs->busy     = 1;
            menu->step++;
        }
    } else if (menu->step == 2) {
        if (!(menu->flags & 0x40)) {
            if (msgs->busy == 0) {
                menu->cur       = menu->next;
                menu->next      = -1;
                menu->unknown_fba_ = 9;
                menu->unknown_fbb_ = 0;
                if (menu->flags & 0x2000) {
                    func_ov003_021749c0((char *) menu);
                    menu->flags &= ~0x2000;
                }
            } else if (msgs->state == 3) {
                *(unsigned char *) ((char *) MessageSystem_GetInstance() + 0x17de) = 0;
                menu->cur  = menu->next;
                menu->next = -1;
                if (menu->cur < 0) {
                    if (menu->flags & 0x20) {
                        MessageSystem_Reset((char *) msgs);
                        MessageSystem_Stop(msgs);
                        menu->flags &= ~0x20;
                    }
                    if (menu->flags & 0x2000) {
                        func_ov003_021749c0((char *) menu);
                        menu->flags &= ~0x2000;
                    }
                }
                menu->step = 0;
            }
        }
    }
}
#else
// USA: func_ov003_021760cc
extern "C" ARM void func_ov003_021760cc(Struct_ov003_021760cc_5 *menu) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Messages021760cc *msgs   = MessageSystem_GetInstance();
    if (menu->step == 0) {
        if (menu->task >= 0) {
            loader->RemoveTask(menu->task);
            menu->task = -1;
        }
        menu->task = loader->QueueLoadFileInGP2(data_ov003_02180b9f, data_ov003_02180bb5, 0);
        menu->step++;
    } else if (menu->step == 1) {
        if (loader->GetTaskStatus(menu->task)) {
            char first[0x48];
            char second[0x48];
            Struct_ov003_021760cc_3 loaded;
            __clear(first, 0x48);
            __clear(second, 0x48);
            NameText_Clear(&loaded);
            loaded.a = first;
            loaded.b = second;
            char name[12];
            void *file;
            unsigned int length;
            loader->GetLoadedFileByID(menu->task, &file, &length);
            if (file) {
                if (menu->cur == 0x1e && menu->unknown_1048_ != -1) {
                    func_020e5334(&loaded, file, length, menu->unknown_1048_);
                } else {
                    func_020e5334(&loaded, file, length, menu->selected);
                }
            }
            loader->RemoveTask(menu->task);
            menu->task = -1;
            short cur  = menu->cur;
            func_02046380(msgs);
            NameText_InitFromPartyMember(name, menu->character);
            msgs->target             = name;
            Element021760cc *element = ItemTable_Find(
                (ItemTable *) (menu->container + 0x800), menu->selected);
            if (element) {
                int value = (menu->mode == 4 ? func_ov003_02175898((char *) menu, element) : element->value);
                value *= menu->count;
                func_020465c0((StoreStruct *) msgs, 0, value);
                func_020465c0((StoreStruct *) msgs, 1, menu->count);
            }
            msgs->loaded = &loaded;
            if (menu->flags & 0x200) {
                char *text = msgs->text;
                Text_Append(
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
            msgs->unknown_99c_ = menu->unknown_ff0_;
            msgs->busy     = 1;
            menu->step++;
        }
    } else if (menu->step == 2) {
        if (!(menu->flags & 0x40)) {
            if (msgs->busy == 0) {
                menu->cur       = menu->next;
                menu->next      = -1;
                menu->unknown_103e_ = 9;
                menu->unknown_103f_ = 0;
                if (menu->flags & 0x2000) {
                    func_ov003_021749c0((char *) menu);
                    menu->flags &= ~0x2000;
                }
            } else if (msgs->state == 3) {
                *(unsigned char *) ((char *) MessageSystem_GetInstance() + 0x19ae) = 0;
                menu->cur                                                                = menu->next;
                menu->next                                                               = -1;
                if (menu->cur < 0) {
                    if (menu->flags & 0x20) {
                        MessageSystem_Reset((char *) msgs);
                        MessageSystem_Stop(msgs);
                        menu->flags &= ~0x20;
                    }
                    if (menu->flags & 0x2000) {
                        func_ov003_021749c0((char *) menu);
                        menu->flags &= ~0x2000;
                    }
                }
                menu->step = 0;
            }
        }
    }
}
#endif
