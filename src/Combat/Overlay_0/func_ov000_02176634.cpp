#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Container020e0310;

struct Struct_ov000_02176634_5 {
    char* unknown_0_;
    char* unknown_4_;
    unsigned int flags;
};

struct Formatter02176634 {
    Struct_ov000_02176634_5* target;
    char pad4[0x10 - 0x4];
    Struct_ov000_02176634_5* unknown_10_;
    char unknown_14_[0x18 - 0x14];
    Struct_ov000_02176634_5* item;
    char unknown_1c_[LOW_REGION(0x28,0x5c) - 0x1c];
    char* textBuffer;
#if defined(jpn)
    char* GetTextBuffer() const { char* value = textBuffer; return value; }
#endif
};

struct Window02176634 {
    char pad0[0xa0];
    short left;
    short top;
    short x;
    short y;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char id;
};

struct Struct_ov000_02176634_11 {
    char pad0[0x70];
    signed char slots[0xb8 - 0x70];
    char messages[0x188 - 0xb8];
    Window02176634 window;
    char unknown_23a_[LOW_REGION(0x1fa3,0x1d6b) - 0x188 - sizeof(Window02176634)];
    signed char slot;
    char unknown_1d6c_[0x1d7a - 0x1d6c];
    unsigned char unknown_1d7a_;
};

struct Struct_ov000_02176634 {
    char pad0[0x1e];
    short cursor;
    char pad20[0x44 - 0x20];
    int x;
    int y;
    int combatantId;
};

struct Struct_ov000_02176634_2 {
    unsigned int unknown_0_;
    unsigned int skill : 12;
    unsigned int unknown_5_4_ : 20;
    char pad8[0x2c - 0x8];
    unsigned int unknown_2c_0_ : 10;
    unsigned int kind : 4;
    unsigned int unknown_2d_6_ : 18;
};

struct Struct_ov000_02176634_3 {
    void* unknown_0_;
    int f4;
    unsigned int category : 4;
    unsigned int rank : 5;
    unsigned int pad1 : 9;
    unsigned int unknown_a_2_ : 1;
    unsigned int pad2 : 13;
    char unknown_c_[0x18 - 0xc];
    short id;
};

struct Struct_ov000_02176634_4 {
    char pad0[0x4c];
    int combatantId;
};

struct Struct_ov000_02176634_6 {
    char pad0[0x14];
    unsigned int flags;
};

struct Struct_ov000_02176634_7 {
#if defined(jpn)
    char pad0[0x134];
    char* name;
    char* GetName() const { char* value = name; return value; }
#else
    char pad0[0x138];
#endif
    Struct_ov000_02176634_6* stats;
};

struct Struct_ov000_02176634_8 {
    char pad0[0xa8];
    unsigned int flags;
};

extern "C" void func_ov000_02177184(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02177454(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_0217768c(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_021779b4(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02177bf0(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02177e50(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02178074(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_021784d4(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
struct Struct_ov000_02170fd0;
extern "C" void func_ov000_02170fd0(Struct_ov000_02170fd0*, int);
extern "C" void func_ov000_021787b8(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02178ba8(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02179018(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_021794cc(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_0217992c(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02179b70(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_02179f94(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" void func_ov000_0217a514(Struct_ov000_02176634_11*, Struct_ov000_02176634*, int, int);
extern "C" Formatter02176634* MessageSystem_GetInstance();
extern "C" void func_02046380(Formatter02176634*);
extern "C" void __clear(void*, int);
extern "C" void NameText_Clear(void*);
extern "C" void* memset(void*, int, unsigned int);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" char* KeyTable_Get(Container020e0310*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" Struct_ov000_02176634_4* func_ov000_02161318(Struct_ov000_02176634_11*, int);
extern "C" Struct_ov000_02176634_2* func_ov000_0217199c(void*, int);
extern "C" int func_ov000_021815c8(void*);
extern "C" Struct_ov000_02176634_3* func_ov000_021815e4(char*);
extern "C" Struct_ov000_02176634_8* func_02053c6c(unsigned char*);
struct Struct_02054000;
extern "C" Struct_ov000_02176634_3* func_02054000(Struct_02054000*);
extern "C" void func_020dcf7c(int, void*);
extern "C" void func_0209c6d8(void*, int);
extern "C" void func_0207c378(char*, short, int, int);
extern "C" void func_02052d7c(Struct_ov000_02176634_7*, int, short);
struct Struct_0207c484;
extern "C" void func_0207c484(Struct_0207c484*, int, int, int);
extern "C" void func_020483f0(unsigned char*, unsigned short);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void MessageSystem_FormatText(Formatter02176634*, int, char*, char*, int, int, int);
extern "C" void func_ov000_0217ab8c(Struct_ov000_02176634*, int, int);
#if defined(jpn)
extern "C" void Window_OpenPane(Window02176634*, char*, int, int, int, int, int);
extern "C" void func_0203bdf4(void*, char*);
extern "C" int func_020dd4c4(int, Struct_ov000_02176634_3*);
extern "C" void func_020474a8(Formatter02176634*, int, char*, char*);
extern "C" int Text_Append(char*, const char*);
extern unsigned int data_ov000_02184550[];
#else
extern "C" void Window_OpenPane(Window02176634*, char*, int, int, int, int, int, int);
#endif

struct Struct_ov000_0218352a {
    unsigned short key;
    short message;
};

extern Struct_ov000_0218352a data_ov000_0218352a[];
extern Struct_ov000_0218352a data_ov000_0218352c[];
extern char g_bgmPlayer[];

// USA: func_ov000_02176634
extern "C" ARM void func_ov000_02176634(Struct_ov000_02176634_11* menu, Struct_ov000_02176634* entry, int mode, int a, int b) {
#if defined(jpn)
    char* buf;
#endif
    int x;
    int y;
    short left;
    short top;
    Struct_ov000_02176634_3* elem;
    char* bag;
    Struct_ov000_02176634_7* combatant;
    Struct_ov000_02176634_8* data;
    short item;
    int handled;
#if !defined(jpn)
    char* buf;
#endif
    int combatantId;
    if (mode < 0 || entry == NULL) {
        return;
    }
    x = entry->x;
    y = entry->y;
    switch (mode) {
    case 1:
        func_ov000_02177184(menu, entry, a, b);
        return;
    case 2:
        func_ov000_02177454(menu, entry, a, b);
        return;
    case 3:
        func_ov000_0217768c(menu, entry, a, b);
        return;
    case 4:
        func_ov000_021779b4(menu, entry, a, b);
        return;
    case 5:
        func_ov000_02177bf0(menu, entry, a, b);
        return;
    case 6:
        func_ov000_02177e50(menu, entry, a, b);
        return;
    case 7:
        func_ov000_02178074(menu, entry, a, b);
        return;
    case 8:
        func_ov000_021784d4(menu, entry, a, b);
        return;
    case 13:
        func_ov000_02170fd0((Struct_ov000_02170fd0*)entry, 0);
        return;
    case 14:
        func_ov000_021787b8(menu, entry, a, b);
        return;
    case 15:
        func_ov000_02178ba8(menu, entry, a, b);
        return;
    case 16:
        func_ov000_02179018(menu, entry, a, b);
        return;
    case 17:
        func_ov000_021794cc(menu, entry, a, b);
        return;
    case 18:
    case 19:
    case 20:
        func_ov000_0217992c(menu, entry, a, b);
        return;
    case 21:
        func_ov000_02179b70(menu, entry, a, b);
        return;
    case 23:
        func_ov000_02179f94(menu, entry, a, b);
        return;
    case 25:
        func_ov000_0217a514(menu, entry, a, b);
        return;
    }

    Formatter02176634* formatter = MessageSystem_GetInstance();
    func_02046380(formatter);
#if defined(jpn)
    char name[0x20];
    __clear(name, 0x20);
    int kind;
    buf = MessageSystem_GetInstance()->GetTextBuffer();
    memset(buf, 0, 0x800);
    memset(buf, 0, 0x800);
    func_0203bdf4((char*)entry + 0x88, name);
    left = (x >> 3) + 9;
    top = (short)(y >> 3) + 1;
    switch (mode) {
    case 0xc:
        kind = 0xc;
        Text_Append(buf, KeyTable_Get((Container020e0310*)menu->messages, 0x7554));
        break;
    case 0x29:
        kind = 0x29;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7558));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x2a:
        kind = 0x2a;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7557));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x2b: {
        Struct_ov000_02176634_4* node = func_ov000_02161318(menu, menu->slots[menu->slot]);
        if (node != NULL) {
            memset(name, 0, 0x20);
            func_0203bdf4((char*)node + 0x88, name);
        }
        kind = 0x2b;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x23), buf);
        break;
    }
    case 0x1a: {
        short msgId = 0x7544;
        Struct_ov000_02176634_2* skill = func_ov000_0217199c(entry, entry->cursor);
        if (skill != NULL && skill->kind == 6) msgId = 0x22;
        kind = 0x1a;
        Text_Append(buf, KeyTable_Get((Container020e0310*)menu->messages, msgId));
        break;
    }
    case 0x1b:
        kind = 0x1b;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7545));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7547), buf);
        break;
    case 0x1c:
        kind = 0x1c;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7546));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7547), buf);
        break;
    case 0x1d:
        kind = 0x1d;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7548), buf);
        break;
    case 0x1e: {
        short msgId = 0x18;
        Struct_ov000_02176634_2* skill = func_ov000_0217199c(entry, entry->cursor);
        if (skill != NULL) {
            for (int i = 0; data_ov000_0218352a[i].key != 0; i++) {
                if (data_ov000_0218352a[i].key == skill->skill) {
                    msgId = data_ov000_0218352c[i].key;
                    break;
                }
            }
        }
        kind = 0x1e;
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x1f: {
        Struct_ov000_02176634_3* selected = func_ov000_021815e4((char*)menu);
        int flags = func_020dd4c4(func_ov000_021815c8(menu), selected);
        short msgId = 0x1a;
        for (unsigned char i = 0; data_ov000_02184550[i] != 0; i++) {
            if (flags & data_ov000_02184550[i]) {
                msgId = (short)(i + 0x1a);
                break;
            }
        }
        kind = 0x1f;
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x20: {
        menu->unknown_1d7a_ = 0;
        short msgId = 0x14;
        combatantId = func_ov000_021815c8(menu);
        elem = func_ov000_021815e4((char*)menu);
        GameState* gs = GameState::GetInstance();
        bag = (char*)GameState_GetParty(gs);
        combatant = (Struct_ov000_02176634_7*)func_0200ff1c(gs, combatantId);
        data = func_02053c6c((unsigned char*)combatant);
        Struct_ov000_02176634_3* sub = func_02054000((Struct_02054000*)combatant);
        kind = 0x20;
        item = elem->id;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, combatant->GetName());
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, (char*)elem->f4);

        if (sub != NULL && elem->id == sub->id) {
            msgId += 2;
            item = -1;
        }
        handled = 0;
        if (sub != NULL && sub->id > 0 && sub->category == 0 && sub->rank <= 0xb && sub->unknown_a_2_) {
            handled = 1;
            msgId = 0x25;
            MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, (char*)sub->f4);
            func_0209c6d8(g_bgmPlayer, 0x3d);
            menu->unknown_1d7a_ = 1;
        }
        if (handled == 0) {
            if (sub != NULL) {
                func_0207c378(bag + 0x1d4, sub->id, 1, sub->category);
            }
            func_02052d7c(combatant, 7, item);
            func_0207c484((Struct_0207c484*)(bag + 0x1d4), item, 1, 0);
            if (combatant->stats->flags & 1) msgId++;
            if (elem->unknown_a_2_) {
                msgId = 0x24;
                func_020483f0((unsigned char*)combatant, 4);
                data->flags |= 4;
                func_ov017_021c9e00(combatantId, 0, 0, 1);
                func_0209c6d8(g_bgmPlayer, 0x3d);
                menu->unknown_1d7a_ = 1;
            }
        }
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x25:
        kind = 0x25;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7545));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x26:
        kind = 0x26;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7546));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x27:
        kind = 0x27;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7556));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    case 0x28:
        kind = 0x28;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7559));
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x7555), buf);
        break;
    default:
        return;
    }

#else
    char var28[0x80];
    char var29[0x80];
    __clear(var28, 0x80);
    __clear(var29, 0x80);
    Struct_ov000_02176634_5 targetName;
    Struct_ov000_02176634_5 itemName;
    NameText_Clear(&itemName);
    itemName.unknown_0_ = var28;
    itemName.unknown_4_ = var29;
    int kind;
    short msgId = 0x7554;
    buf = MessageSystem_GetInstance()->textBuffer;
    memset(buf, 0, 0x960);
    memset(buf, 0, 0x960);
    NameText_InitFromPartyMember(&targetName, entry->combatantId);
    left = (x >> 3) + 9;
    top = (short)(y >> 3) + 1;
    formatter->target = &targetName;
    formatter->unknown_10_ = &targetName;

    switch (mode) {
    case 0xc:
        kind = 0xc;
        break;
    case 0x29:
        kind = 0x29;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7558));
        msgId = 0x7555;
        break;
    case 0x2a:
        kind = 0x2a;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7557));
        msgId = 0x7555;
        break;
    case 0x2b: {
        Struct_ov000_02176634_4* node = func_ov000_02161318(menu, menu->slots[menu->slot]);
        if (node != NULL) {
            NameText_InitFromPartyMember(&targetName, node->combatantId);
        }
        kind = 0x2b;
        msgId = 0x23;
        break;
    }
    case 0x1a: {
        msgId = 0x7544;
        Struct_ov000_02176634_2* skill = func_ov000_0217199c(entry, entry->cursor);
        if (skill != NULL && skill->kind == 6) {
            msgId = 0x22;
        }
        kind = 0x1a;
        break;
    }
    case 0x1b:
        kind = 0x1b;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7545));
        msgId = 0x7547;
        break;
    case 0x1c:
        kind = 0x1c;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7546));
        msgId = 0x7547;
        break;
    case 0x1d:
        kind = 0x1d;
        msgId = 0x7548;
        break;
    case 0x1e: {
        msgId = 0x18;
        Struct_ov000_02176634_2* skill = func_ov000_0217199c(entry, entry->cursor);
        if (skill != NULL) {
            for (int i = 0; data_ov000_0218352a[i].key != 0; i++) {
                if (data_ov000_0218352a[i].key == skill->skill) {
                    msgId = data_ov000_0218352c[i].key;
                    break;
                }
            }
        }
        kind = 0x1e;
        break;
    }
    case 0x20: {
        menu->unknown_1d7a_ = 0;
        msgId = 0x14;
        combatantId = func_ov000_021815c8(menu);
        elem = func_ov000_021815e4((char*)menu);
        GameState* gs = GameState::GetInstance();
        bag = (char*)GameState_GetParty(gs);
        combatant = (Struct_ov000_02176634_7*)func_0200ff1c(gs, combatantId);
        data = func_02053c6c((unsigned char*)combatant);
        Struct_ov000_02176634_3* sub = func_02054000((Struct_02054000*)combatant);
        kind = 0x20;
        item = elem->id;
        NameText_InitFromPartyMember(&targetName, combatantId);
        if (sub != NULL && elem->id == sub->id) {
            msgId += 2;
            item = -1;
        }
        handled = 0;
        if (sub != NULL && sub->id > 0 && sub->category == 0 && sub->rank <= 0xb && sub->unknown_a_2_) {
            handled = 1;
            msgId = 0x25;
            func_020dcf7c(sub->id, &itemName);
            formatter->item = &itemName;
            func_0209c6d8(g_bgmPlayer, 0x3d);
            menu->unknown_1d7a_ = 1;
        }
        if (handled == 0) {
            if (sub != NULL) {
                func_0207c378(bag + 0x1d4, sub->id, 1, sub->category);
            }
            if (item < 0) {
                func_020dcf7c(sub->id, &itemName);
            } else {
                func_020dcf7c(item, &itemName);
            }
            formatter->item = &itemName;
            func_02052d7c(combatant, 7, item);
            func_0207c484((Struct_0207c484*)(bag + 0x1d4), item, 1, 0);
            if (combatant->stats->flags & 1) {
                msgId++;
            }
            if (elem->unknown_a_2_) {
                msgId = 0x24;
                func_020483f0((unsigned char*)combatant, 4);
                data->flags |= 4;
                func_ov017_021c9e00(combatantId, 0, 0, 1);
                func_0209c6d8(g_bgmPlayer, 0x3d);
                menu->unknown_1d7a_ = 1;
            }
        }
        break;
    }
    case 0x25:
        kind = 0x25;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7545));
        msgId = 0x7555;
        break;
    case 0x26:
        kind = 0x26;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7546));
        msgId = 0x7555;
        break;
    case 0x27:
        kind = 0x27;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7556));
        msgId = 0x7555;
        break;
    case 0x28:
        kind = 0x28;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, KeyTable_Get((Container020e0310*)menu->messages, 0x7559));
        msgId = 0x7555;
        break;
    default:
        return;
    }

    MessageSystem_FormatText(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, msgId), buf, 0xa4, 0, 0);
#endif
    func_ov000_0217ab8c(entry, a, b);
    Window02176634* window = &menu->window;
    window->left = 8;
    window->top = 7;
    window->x = left;
    window->y = top;
    window->unknown_a8_ = 10;
    window->unknown_aa_ = 4;
    window->unknown_ac_ = 10;
    window->unknown_ae_ = 0x11;
    window->id = kind;
#if defined(jpn)
    Window_OpenPane(window, buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(window, buf, 0, 1, 0, 1, 0, 0);
    func_02046380(formatter);
#endif
}
