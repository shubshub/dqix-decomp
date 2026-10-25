#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020465c0 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    char* unknown_5c_;
};

struct Struct_ov000_02179cdc {
    char unknown_0_[0xa0];
    short unknown_a0_;
    short unknown_a2_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_02176e3c {
    char unknown_0_[0x188];
    Struct_ov000_02179cdc unknown_188_;
};

struct Struct_ov000_02179cdc_2 {
    char unknown_0_[0xe];
    short unknown_e_;
    char unknown_10_[0x44 - 0x10];
    int unknown_44_;
    int unknown_48_;
    int unknown_4c_;
};

struct Struct_0209a678 {
    char unknown_0_[4];
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
};

struct Struct_ov000_02179cdc_3 {
#if defined(jpn)
    char unknown_0_[0x8b8];
#else
    char unknown1_0_[0x950];
#endif
    int unknown_950_;
};

struct Struct_ov000_02179cdc_4 {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov000_02179cdc_3* unknown_150_;
};

#if defined(jpn)
#define data_ov000_02183510 data_ov000_02184590
#endif
extern unsigned short data_ov000_02183510[];

StoreStruct* MessageSystem_GetInstance(void);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" SkillEntry* func_ov000_02170cf8(MenuEntry* entry, int key);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int idx);
void NotifyLocalizedResourceLoad020dd040(int id, char* buf);
extern "C" void MessageSystem_FormatText(StoreStruct* store, int kind, char* src, char* dst, int a, int b, int c);
extern "C" void func_02046380(StoreStruct* store);
int IsFlag0x18Bit0x200Set_ov000_02153a8c(GameObject* obj);
int AdjustValueByFieldFlag_020dd290(void*, unsigned int);
void StoreInArray0x8b0_020465c0(StoreStruct* store, int index, int value);
const char* StandardStrings_Get(int key);
void Text_Append(char* dst, const char* src);
struct Struct_0205d81c;
extern "C" void* func_0205d81c(Struct_0205d81c*, int);
#if defined(jpn)
extern "C" void Window_OpenPane(ElemList* list, char* text, int a, int b, int c, int d, int e);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void SetByteAtIndex_020465d8(unsigned char*, int, unsigned char);
extern char data_ov000_02185169[];
#else
extern "C" void Window_OpenPane(ElemList* list, char* text, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02179cdc
extern "C" ARM void func_ov000_02179cdc(Struct_ov000_02176e3c* arg0, Struct_ov000_02179cdc_2* arg1) {
    char* var0;
    Struct_020465c0* var1;
    if (arg1 == 0) {
        return;
    }
    char* buf = MessageSystem_GetInstance()->textBuffer;
#if defined(jpn)
    memset(var2, 0, 0x800);
#else
    memset(var2, 0, 0x960);
#endif
    GameState* var3 = GameState::GetInstance();
    GameObject* var4 = var3->GetCombatantByIndex(arg1->unknown_4c_);
    if (var4 == 0) {
        return;
    }
    Struct_ov000_02179cdc_4* var5 = (Struct_ov000_02179cdc_4*)var3->GetPartyMemberByIndex(arg1->unknown_4c_);
    if (var5 == 0) {
        return;
    }
    Struct_0209a678* var6 = func_ov000_02170cf8(arg1, data_ov000_02183510[var5->unknown_150_->unknown_950_]);
    GameObject* var7 = func_0200ff1c(var3, arg1->unknown_4c_);
    if (var7 == 0) {
        return;
    }
    func_020dd040(var6->unknown_4_0_, var2);
#if !defined(jpn)
    char var8[0x800];
#endif
#if defined(jpn)
    var0 = var2;
#else
    MessageSystem_FormatText(MessageSystem_GetInstance(), 10, buf, text, 0x72, 0, 0);
    msg = text;
#endif
    store = MessageSystem_GetInstance();
    func_02046380(store);
    int value;
    if (IsFlag0x18Bit0x200Set_ov000_02153a8c(combatant) != 0) {
        value = 0;
    } else if (skill->adjustFlag >= 0xff) {
        value = entry->value;
    } else {
        var9 = func_020dd290(var7, var6->unknown_8_0_);
    }
    func_020465c0(var1, 0, var9);
    func_020465c0(var1, 1, arg1->unknown_e_);
#if defined(jpn)
    SetByteInRange_020465f0((unsigned char*)store, 0, 3);
    SetByteInRange_020465f0((unsigned char*)store, 1, 3);
    SetByteAtIndex_020465d8((unsigned char*)store, 0, 1);
    SetByteAtIndex_020465d8((unsigned char*)store, 1, 1);
    Text_Append(msg, data_ov000_02185169);
#else
    Text_Append(msg, StandardStrings_Get(0x3ec));
#endif
    Struct_ov000_02179cdc* var10 = &arg0->unknown_188_;
    if (func_0205d81c((Struct_0205d81c*)var10, 0x16) != 0) {
#if defined(jpn)
        Window_SetPaneText((StructA0205d5d0*)list, 0x16, (int)msg, 1);
#else
        Window_SetPaneText((StructA0205d5d0*)list, 0x16, (int)msg, 1, 0);
#endif
        return;
    }
    int var11 = arg1->unknown_44_;
    int var12 = arg1->unknown_48_;
#if defined(jpn)
    var10->unknown_a0_ = 0xc;
#else
    var10->unknown_a0_ = 0x10;
#endif
#if defined(jpn)
    var10->unknown_a2_ = 6;
#else
    var10->unknown_a2_ = 0xa;
#endif
#if defined(jpn)
    var10->unknown_a4_ = (var11 >> 3) + 0x16;
#else
    var10->unknown_a4_ = (var11 >> 3) + 0x10;
#endif
#if defined(jpn)
    var10->unknown_a6_ = var12 >> 3;
#else
    var10->unknown_a6_ = (short)(var12 >> 3) + 3;
#endif
    var10->unknown_a8_ = 7;
#if defined(jpn)
    var10->unknown_aa_ = 8;
#else
    var10->unknown_aa_ = 6;
#endif
    var10->unknown_ac_ = 0xa;
    var10->unknown_ae_ = 0xe;
    var10->unknown_b1_ = 0x16;
#if defined(jpn)
    Window_OpenPane(list, msg, 1, 0, 0, 1, 0);
#else
    Window_OpenPane(list, msg, 1, 0, 0, 1, 0, 0);
#endif
}
