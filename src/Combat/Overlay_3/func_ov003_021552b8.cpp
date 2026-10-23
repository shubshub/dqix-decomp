#include "GameState/GameState.h"
#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif

struct Struct_0201099c_3;
struct Struct_02046574_2;

struct Struct_ov003_021552b8_2 {
    void *unknown_0_;
    char unknown_4_[0xc];
    void *unknown_10_;
    char unknown_14_[0x28 - 0x14];
    void *unknown_28_;
    char unknown_2c_[LOW_REGION(0x868,0x998) - 0x2c];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
};

struct Struct_ov003_021552b8_3 {
    char unknown_0_[LOW_REGION(0x8b8,0x950)];
    int unknown_950_;
};

struct Struct_ov003_021552b8_4 {
#if defined(jpn)
    char unknown_0_[0x134];
    void* unknown_134_;
    char unknown_138_[0x144 - 0x138];
#else
    char unknown1_0_[0x150];
#endif
    Struct_ov003_021552b8_3 *unknown_150_;
};

struct Struct_ov003_021552b8_5 {
    char unknown_0_[4];
    void *unknown_4_;
    char unknown_8_[0xe4 - 8];
    char unknown_e4_[LOW_REGION(0x1e8,0x1ec) - 0xe4];
    short unknown_1ec_;
    short unknown_1ee_;
    char unknown_1f0_[0x1f7 - 0x1f0];
    signed char unknown_1f7_;
    unsigned char unknown_1f8_;
    unsigned char unknown_1f9_;
    unsigned char unknown_1fa_;
    char unknown_1fb_;
    unsigned int unknown_1fc_;
};

struct Struct_ov003_021552b8 {
    char unknown_0_[0xc];
};

MsgGlobals021552b8 *GetGlobalField0x1c020421a0();
extern "C" void func_02046380(MsgGlobals021552b8 *);
int GetArrayEntryByIndex_02156034(void *);
void * KeyTable_Get(Container020e0310*, int);
void InitObjFromCombatantId020e4bf4(void *, int);
extern "C" void func_020e4b34(void *, void *, int, int, int, int, int, int, int, int, int, int);
extern "C" void func_02046574(Struct_02046574_2*, int, char*);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov003_021552b8_2*, void*, int);
#endif
#if !defined(jpn)
extern "C" void func_0204500c(Struct_ov003_021552b8_2 *, void *, int, int);
#endif
extern "C" int func_ov003_021538e0(void *);
extern "C" void func_02043204(char *);
extern "C" void func_02043124(Struct_ov003_021552b8_2 *);

// USA: func_ov003_021552b8
extern "C" ARM void func_ov003_021552b8(Struct_ov003_021552b8_5 *arg0) {
    Struct_ov003_021552b8_2 *var0 = func_020421a0();
    if (arg0->unknown_1fa_ == 0) {
#if !defined(jpn)
        int var1 = arg0->unknown_1ec_;
#endif
        if (arg0->unknown_1fc_ & 1) {
#if defined(jpn)
            int var1 = arg0->unknown_1ec_;
#endif
            switch (var1) {
                case 6: var1 = 0x1b; break;
                case 7: var1 = 0x1c; break;
                case 8: var1 = 0x1d; break;
                case 9: var1 = 0x1e; break;
                case 10: var1 = 0x1f; break;
                case 11: var1 = 0x20; break;
                case 12: var1 = 0x21; break;
                case 13: var1 = 0x22; break;
                case 0x30: var1 = 0x32; break;
                case 0x31: var1 = 0x33; break;
            }
            arg0->unknown_1ec_ = var1;
        }
        func_02046380(var0);
        GameState *var2           = GameState::GetInstance();
        Struct_ov003_021552b8_4 *var3 = (Struct_ov003_021552b8_4 *) var2->GetPartyMemberByIndex(arg0->unknown_1f7_);
#if defined(jpn)
        void* var4 = 0;
        int var5 = 0;
        if (var3) {
            var5 = var3->unknown_150_->unknown_950_;
            var4 = var3->unknown_134_;
        }
        SetIndexedName02046574((Obj02046574*)g, 0, (char*)name);
        short key = GetArrayEntryByIndex_02156034(self) + 0x23;
        SetIndexedName02046574((Obj02046574*)g, 1, (char*)(KeyTable_Get((Container020e0310*)self->messages, key)));
        SetIndexedName02046574((Obj02046574*)g, 2, (char*)(KeyTable_Get((Container020e0310*)self->messages, (short)(vocation + 0x23))));
        SetIndexedName02046574((Obj02046574*)g, 3, (char*)(KeyTable_Get((Container020e0310*)self->messages, (short)(vocation + 0x34))));
        func_0204500c(g, KeyTable_Get((Container020e0310*)self->messages, self->curId), 0);
#else
        int var7            = 0;
        if (var3) {
            var7 = var3->unknown_150_->unknown_950_;
        }
        short key = GetArrayEntryByIndex_02156034(self) + 0x23;
        void *a   = KeyTable_Get((Container020e0310*)self->messages, key);
        void *b   = KeyTable_Get((Container020e0310*)self->messages, (short) (vocation + 0x23));
        StrObj021552b8 unit;
        InitObjFromCombatantId020e4bf4(&unit, self->slot);
        g->subject  = &unit;
        g->subject2 = &unit;
        StrObj021552b8 obj;
        void *pick = a;
        if (id == 0x10 || id == 0x13 || id == 0x16) {
            pick = b;
        }
        func_020e4b34(&obj, pick, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        g->extra = &obj;
        SetIndexedName02046574((Obj02046574*)g, 1, (char*)a);
        SetIndexedName02046574((Obj02046574*)g, 2, (char*)b);
        SetIndexedName02046574((Obj02046574*)g, 3, (char*)(KeyTable_Get((Container020e0310*)self->messages, (short) (vocation + 0x34))));
        func_0204500c(g, KeyTable_Get((Container020e0310*)self->messages, id), 0, 0xe3);
#endif
        var0->unknown_998_  = 1;
        var0->unknown_99c_ = 1;
        arg0->unknown_1fa_++;
    } else if (arg0->unknown_1fa_ == 1) {
        if (var0->unknown_998_ == 0) {
            arg0->unknown_1ec_  = arg0->unknown_1ee_;
            arg0->unknown_1ee_ = -1;
            arg0->unknown_1f8_   = 7;
            arg0->unknown_1fa_   = 0;
            if (func_ov003_021538e0(arg0->unknown_4_) == 0) {
                arg0->unknown_1f8_ = 5;
                arg0->unknown_1f9_  = 0;
            }
        } else if (var0->unknown_9a0_ == 3) {
            arg0->unknown_1ec_  = arg0->unknown_1ee_;
            arg0->unknown_1ee_ = -1;
            if (arg0->unknown_1ec_ < 0 && (arg0->unknown_1fc_ & 2)) {
                func_02043204((char *) var0);
                func_02043124(var0);
                arg0->unknown_1fc_ &= ~2;
            }
            arg0->unknown_1fa_ = 0;
        }
    }
}
