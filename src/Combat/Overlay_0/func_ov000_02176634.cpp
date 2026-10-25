#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Struct_0201099c_3;

struct Struct_ov000_02176634_5 {
    char* unknown_0_;
    char* unknown_4_;
    unsigned int unknown_8_;
};

struct Struct_ov000_02176634_9 {
    Struct_ov000_02176634_5* unknown_0_;
    char unknown_4_[0x10 - 0x4];
    Struct_ov000_02176634_5* unknown_10_;
    char unknown_14_[0x18 - 0x14];
    Struct_ov000_02176634_5* unknown_18_;
    char unknown_1c_[LOW_REGION(0x28,0x5c) - 0x1c];
    char* unknown_5c_;
#if defined(jpn)
    char* inline_ov000_02176634_2() const { char* var0 = unknown_5c_; return var0; }
#endif
};

struct Struct_ov000_02176634_10 {
    char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_02176634_11 {
    char unknown_0_[0x70];
    signed char unknown_70_[0xb8 - 0x70];
    char unknown_b8_[0x188 - 0xb8];
    Struct_ov000_02176634_10 unknown_188_;
    char unknown_23a_[LOW_REGION(0x1fa3,0x1d6b) - 0x188 - sizeof(Struct_ov000_02176634_10)];
    signed char unknown_1d6b_;
    char unknown_1d6c_[0x1d7a - 0x1d6c];
    unsigned char unknown_1d7a_;
};

struct Struct_ov000_02176634 {
    char unknown_0_[0x1e];
    short unknown_1e_;
    char unknown_20_[0x44 - 0x20];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
};

struct Struct_ov000_02176634_2 {
    unsigned int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    char unknown_8_[0x2c - 0x8];
    unsigned int unknown_2c_0_ : 10;
    unsigned int unknown_2d_2_ : 4;
    unsigned int unknown_2d_6_ : 18;
};

struct Struct_ov000_02176634_3 {
    void* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 9;
    unsigned int unknown_a_2_ : 1;
    unsigned int unknown_a_3_ : 13;
    char unknown_c_[0x18 - 0xc];
    short unknown_18_;
};

struct Struct_ov000_02176634_4 {
    char unknown_0_[0x4c];
    int unknown_4c_;
};

struct Struct_ov000_02176634_6 {
    char unknown_0_[0x14];
    unsigned int unknown_14_;
};

struct Struct_ov000_02176634_7 {
#if defined(jpn)
    char unknown_0_[0x134];
    char* unknown_134_;
    char* inline_ov000_02176634() const { char* var0 = unknown_134_; return var0; }
#else
    char unknown1_0_[0x138];
#endif
    Struct_ov000_02176634_6* unknown_138_;
};

struct Struct_ov000_02176634_8 {
    char unknown_0_[0xa8];
    unsigned int unknown_a8_;
};

extern "C" void func_ov000_02177184(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02177454(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_0217768c(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_021779b4(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02177bf0(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02177e50(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02178074(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_021784d4(Menu02176634*, Entry02176634*, int, int);
struct Struct02170fd0;
void CallHandlerIfF38Set02170fd0(Struct02170fd0*, int);
extern "C" void func_ov000_021787b8(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02178ba8(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02179018(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_021794cc(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_0217992c(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02179b70(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_02179f94(Menu02176634*, Entry02176634*, int, int);
extern "C" void func_ov000_0217a514(Menu02176634*, Entry02176634*, int, int);
Formatter02176634* MessageSystem_GetInstance();
extern "C" void func_02046380(Formatter02176634*);
extern "C" void __clear(void*, int);
extern "C" void func_020e46c4(void*);
extern "C" void* memset(void*, int, unsigned int);
void NameText_InitFromPartyMember(void*, int);
char* KeyTable_Get(Container020e0310*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" Node02176634* func_ov000_02161318(Menu02176634*, int);
Skill02176634* GetBoundedField420_0217199c(void*, int);
int GetAdjustedByteField0x1d6b_ov000_021815c8(void*);
Item02176634* FindElementByComputedKey021815e4(char*);
PartyData02176634* GetFieldAt0x150_02053c6c(unsigned char*);
struct Outer_02054000;
Item02176634* GetActiveSub_02054000(Outer_02054000*);
void DispatchIfCountPositive020dcf7c(int, void*);
void ResetAndDispatchActorContext0209c6d8(void*, int);
extern "C" void func_0207c378(char*, short, int, int);
extern "C" void func_02052d7c(Struct_ov000_02176634_7*, int, short);
struct Struct_0207c484;
extern "C" void func_0207c484(Struct_0207c484*, int, int, int);
extern "C" void func_020483f0(unsigned char*, unsigned short);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void MessageSystem_FormatText(Formatter02176634*, int, char*, char*, int, int, int);
extern "C" void func_ov000_0217ab8c(Entry02176634*, int, int);
#if defined(jpn)
extern "C" void Window_OpenPane(Window02176634*, char*, int, int, int, int, int);
extern "C" void func_0203bdf4(void*, char*);
extern "C" int func_020dd4c4(int, Item02176634*);
extern "C" void func_020474a8(Formatter02176634*, int, char*, char*);
int Text_Append(char*, const char*);
extern unsigned int data_ov000_02184550[];
#else
extern "C" void Window_OpenPane(Window02176634*, char*, int, int, int, int, int, int);
#endif

struct Struct_ov000_0218352a {
    unsigned short unknown_0_;
    short unknown_2_;
};

extern MessagePair02176634 data_ov000_0218352a[];
extern MessagePair02176634 data_ov000_0218352c[];
extern char g_bgmPlayer[];

// USA: func_ov000_02176634
extern "C" ARM void func_ov000_02176634(Struct_ov000_02176634_11* arg0, Struct_ov000_02176634* arg1, int arg2, int arg3, int arg4) {
#if defined(jpn)
    char* var0;
#endif
    int var1;
    int var2;
    short var3;
    short var4;
    Struct_ov000_02176634_3* var5;
    char* var6;
    Struct_ov000_02176634_7* var7;
    Struct_ov000_02176634_8* var8;
    short var9;
    int var10;
#if !defined(jpn)
    char* var11;
#endif
    int var12;
    if (arg2 < 0 || arg1 == NULL) {
        return;
    }
    var1 = arg1->unknown_44_;
    var2 = arg1->unknown_48_;
    switch (arg2) {
    case 1:
        func_ov000_02177184(arg0, arg1, arg3, arg4);
        return;
    case 2:
        func_ov000_02177454(arg0, arg1, arg3, arg4);
        return;
    case 3:
        func_ov000_0217768c(arg0, arg1, arg3, arg4);
        return;
    case 4:
        func_ov000_021779b4(arg0, arg1, arg3, arg4);
        return;
    case 5:
        func_ov000_02177bf0(arg0, arg1, arg3, arg4);
        return;
    case 6:
        func_ov000_02177e50(arg0, arg1, arg3, arg4);
        return;
    case 7:
        func_ov000_02178074(arg0, arg1, arg3, arg4);
        return;
    case 8:
        func_ov000_021784d4(arg0, arg1, arg3, arg4);
        return;
    case 13:
        func_ov000_02170fd0((Struct_ov000_02170fd0*)arg1, 0);
        return;
    case 14:
        func_ov000_021787b8(arg0, arg1, arg3, arg4);
        return;
    case 15:
        func_ov000_02178ba8(arg0, arg1, arg3, arg4);
        return;
    case 16:
        func_ov000_02179018(arg0, arg1, arg3, arg4);
        return;
    case 17:
        func_ov000_021794cc(arg0, arg1, arg3, arg4);
        return;
    case 18:
    case 19:
    case 20:
        func_ov000_0217992c(arg0, arg1, arg3, arg4);
        return;
    case 21:
        func_ov000_02179b70(arg0, arg1, arg3, arg4);
        return;
    case 23:
        func_ov000_02179f94(arg0, arg1, arg3, arg4);
        return;
    case 25:
        func_ov000_0217a514(arg0, arg1, arg3, arg4);
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
        Struct_ov000_02176634_4* var15 = func_ov000_02161318(arg0, arg0->unknown_70_[arg0->unknown_1d6b_]);
        if (var15 != NULL) {
            memset(var14, 0, 0x20);
            func_0203bdf4((char*)var15 + 0x88, var14);
        }
        kind = 0x2b;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, name);
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, 0x23), buf);
        break;
    }
    case 0x1a: {
        short msgId = 0x7544;
        Skill02176634* skill = GetBoundedField420_0217199c(entry, entry->cursor);
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
        short var18 = 0x18;
        Struct_ov000_02176634_2* var19 = func_ov000_0217199c(arg1, arg1->unknown_1e_);
        if (var19 != NULL) {
            for (int var20 = 0; data_ov000_0218352a[var20].unknown_0_ != 0; var20++) {
                if (data_ov000_0218352a[var20].unknown_0_ == var19->unknown_4_0_) {
                    var18 = data_ov000_0218352c[var20].unknown_0_;
                    break;
                }
            }
        }
        kind = 0x1e;
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x1f: {
        Struct_ov000_02176634_3* var21 = func_ov000_021815e4((char*)arg0);
        int var22 = func_020dd4c4(func_ov000_021815c8(arg0), var21);
        short var23 = 0x1a;
        for (unsigned char var24 = 0; data_ov000_02184550[var24] != 0; var24++) {
            if (var22 & data_ov000_02184550[var24]) {
                var23 = (short)(var24 + 0x1a);
                break;
            }
        }
        kind = 0x1f;
        func_020474a8(formatter, 10, KeyTable_Get((Container020e0310*)menu->messages, msgId), buf);
        break;
    }
    case 0x20: {
        menu->dispatched = 0;
        short msgId = 0x14;
        combatantId = GetAdjustedByteField0x1d6b_ov000_021815c8(menu);
        elem = FindElementByComputedKey021815e4((char*)menu);
        GameState* gs = GameState::GetInstance();
        bag = (char*)GameState_GetParty(gs);
        combatant = (Combatant02176634*)GetCombatantWithFlag0x100_0200ff1c(gs, combatantId);
        data = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
        Item02176634* sub = GetActiveSub_02054000((Outer_02054000*)combatant);
        kind = 0x20;
        item = elem->id;
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 0, combatant->GetName());
        MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, (char*)elem->f4);

        if (var27 != NULL && var5->unknown_18_ == var27->unknown_18_) {
            var25 += 2;
            var9 = -1;
        }
        handled = 0;
        if (sub != NULL && sub->id > 0 && sub->category == 0 && sub->rank <= 0xb && sub->cursed) {
            handled = 1;
            msgId = 0x25;
            MessageSystem_SetStringArgument((Obj02046574*)formatter, 1, (char*)sub->f4);
            ResetAndDispatchActorContext0209c6d8(g_bgmPlayer, 0x3d);
            menu->dispatched = 1;
        }
        if (var10 == 0) {
            if (var27 != NULL) {
                func_0207c378(var6 + 0x1d4, var27->unknown_18_, 1, var27->unknown_8_0_);
            }
            func_02052d7c(combatant, 7, item);
            DecrementKeyedStackAmount0207c484((KeyedList0207c484*)(bag + 0x1d4), item, 1, 0);
            if (combatant->stats->flags & 1) msgId++;
            if (elem->cursed) {
                msgId = 0x24;
                TrySetFlags0x130_020483f0((unsigned char*)combatant, 4);
                data->flags |= 4;
                func_ov017_021c9e00(combatantId, 0, 0, 1);
                ResetAndDispatchActorContext0209c6d8(g_bgmPlayer, 0x3d);
                menu->dispatched = 1;
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
    char singular[0x80];
    char plural[0x80];
    __clear(singular, 0x80);
    __clear(plural, 0x80);
    NameParts02176634 targetName;
    NameParts02176634 itemName;
    Clear12Bytes020e46c4(&itemName);
    itemName.singular = singular;
    itemName.plural = plural;
    int kind;
    short msgId = 0x7554;
    buf = MessageSystem_GetInstance()->textBuffer;
    memset(buf, 0, 0x960);
    memset(buf, 0, 0x960);
    NameText_InitFromPartyMember(&targetName, entry->combatantId);
    left = (x >> 3) + 9;
    top = (short)(y >> 3) + 1;
    formatter->target = &targetName;
    formatter->subject = &targetName;

    switch (arg2) {
    case 0xc:
        var32 = 0xc;
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
        Node02176634* node = func_ov000_02161318(menu, menu->slots[menu->slot]);
        if (node != NULL) {
            NameText_InitFromPartyMember(&targetName, node->combatantId);
        }
        var32 = 0x2b;
        var33 = 0x23;
        break;
    }
    case 0x1a: {
        var33 = 0x7544;
        Struct_ov000_02176634_2* var35 = func_ov000_0217199c(arg1, arg1->unknown_1e_);
        if (var35 != NULL && var35->unknown_2d_2_ == 6) {
            var33 = 0x22;
        }
        var32 = 0x1a;
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
        var32 = 0x1d;
        var33 = 0x7548;
        break;
    case 0x1e: {
        var33 = 0x18;
        Struct_ov000_02176634_2* var36 = func_ov000_0217199c(arg1, arg1->unknown_1e_);
        if (var36 != NULL) {
            for (int var37 = 0; data_ov000_0218352a[var37].unknown_0_ != 0; var37++) {
                if (data_ov000_0218352a[var37].unknown_0_ == var36->unknown_4_0_) {
                    var33 = data_ov000_0218352c[var37].unknown_0_;
                    break;
                }
            }
        }
        var32 = 0x1e;
        break;
    }
    case 0x20: {
        menu->dispatched = 0;
        msgId = 0x14;
        combatantId = GetAdjustedByteField0x1d6b_ov000_021815c8(menu);
        elem = FindElementByComputedKey021815e4((char*)menu);
        GameState* gs = GameState::GetInstance();
        bag = (char*)GameState_GetParty(gs);
        combatant = (Combatant02176634*)GetCombatantWithFlag0x100_0200ff1c(gs, combatantId);
        data = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
        Item02176634* sub = GetActiveSub_02054000((Outer_02054000*)combatant);
        kind = 0x20;
        item = elem->id;
        NameText_InitFromPartyMember(&targetName, combatantId);
        if (sub != NULL && elem->id == sub->id) {
            msgId += 2;
            item = -1;
        }
        handled = 0;
        if (sub != NULL && sub->id > 0 && sub->category == 0 && sub->rank <= 0xb && sub->cursed) {
            handled = 1;
            msgId = 0x25;
            DispatchIfCountPositive020dcf7c(sub->id, &itemName);
            formatter->item = &itemName;
            ResetAndDispatchActorContext0209c6d8(g_bgmPlayer, 0x3d);
            menu->dispatched = 1;
        }
        if (var10 == 0) {
            if (var39 != NULL) {
                func_0207c378(var6 + 0x1d4, var39->unknown_18_, 1, var39->unknown_8_0_);
            }
            if (var9 < 0) {
                func_020dcf7c(var39->unknown_18_, &var31);
            } else {
                func_020dcf7c(var9, &var31);
            }
            var13->unknown_18_ = &var31;
            func_02052d7c(var7, 7, var9);
            func_0207c484((Struct_0207c484*)(var6 + 0x1d4), var9, 1, 0);
            if (var7->unknown_138_->unknown_14_ & 1) {
                var33++;
            }
            if (elem->cursed) {
                msgId = 0x24;
                TrySetFlags0x130_020483f0((unsigned char*)combatant, 4);
                data->flags |= 4;
                func_ov017_021c9e00(combatantId, 0, 0, 1);
                ResetAndDispatchActorContext0209c6d8(g_bgmPlayer, 0x3d);
                menu->dispatched = 1;
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
    func_ov000_0217ab8c(arg1, arg3, arg4);
    Struct_ov000_02176634_10* var40 = &arg0->unknown_188_;
    var40->unknown_a0_ = 8;
    var40->unknown_a2_ = 7;
    var40->unknown_a4_ = var3;
    var40->unknown_a6_ = var4;
    var40->unknown_a8_ = 10;
    var40->unknown_aa_ = 4;
    var40->unknown_ac_ = 10;
    var40->unknown_ae_ = 0x11;
    var40->unknown_b1_ = var32;
#if defined(jpn)
    Window_OpenPane(window, buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(window, buf, 0, 1, 0, 1, 0, 0);
    func_02046380(formatter);
#endif
}
