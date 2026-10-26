#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_02080cc0;
struct Struct_02080f8c;
struct Struct_02080fa8;
struct Struct_02081198;
struct Struct_02081164;
struct Struct_0201099c_16;
struct Struct_ov003_0215f56c_3;
struct Struct_ov003_02165c9c_5;

int SetSublistEntriesFlag1_02080b54(void* obj, int id);
int CompareThreshold_021614e8(int);
void SetOrClearFlags464_02166164(Outer02166164*, int, int);
extern "C" void Font_DecodeText(void* src, void* dst, int flag);
int PartyMemberRecord_GetVocation(Struct020865b0*);
int ClassifyRatio_0215f56c(S0215f56c*);
int SetEntryFlagById02080b40(void* obj, int id);
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
void ResolveEntryValueByKey02080fe0(void*, int, int);
void SetEntryFirstField02080fa8(struct Container02080fa8*, int, int);
void SetEntryHalfword0xe_0208103c(void*, int, int);
void GetEntryFieldsAt0x602080828(void*, int, short*, short*);
void GetEntryOutputs020808c8(void*, int, short*, short*);
void SetEntryFieldsAt0x602080854(void*, int, int, int);
int KeyTable_Get(struct Container020e0310*, int);
extern "C" void func_ov003_0215f5e8(void* menu, int page, int count);
extern "C" void func_ov003_02160c58(void* self, short* outHigh, short* outLow);
void SetEntryNibbleByShortId(struct StatusOwner02081198* owner, int id, int enable);
void SetEntryFlag0x2ByShortId(struct StatusOwner02081164* obj, int id, int value);
extern "C" int func_020813ec(void* obj, int id);
extern "C" void func_ov003_02160678(void* self);
extern "C" void func_ov003_02160794(void* self);

struct Struct_ov003_02165c9c {
    signed char unknown_0_0_ : 6;
    char unknown_1_[1];
    unsigned char unknown_2_[0xd];
    unsigned char unknown_f_[0x140 - 0xf];
    char unknown_140_[0x34];
    unsigned char unknown_174_0_ : 1;
    char unknown_175_[0x23c - 0x175];
};

struct Struct_ov003_02165c9c_2 {
    char unknown_0_[0xf7c];
    unsigned char unknown_f7c_;
    char unknown_f7d_[0xf80 - 0xf7d];
    Struct_ov003_02165c9c unknown_f80_[(0x2c8c - 0xf80) / 0x23c];
    char unknown_2c8c_[0x2c8c - 0xf80 - ((0x2c8c - 0xf80) / 0x23c) * 0x23c];
    unsigned char unknown1_2c8c_;
};

void* GameState_GetParty(GameState*);

static inline Party02165c9c* GetParty() {
    return (Party02165c9c*)GameState_GetParty(GameState::GetInstance());
}

struct Struct_ov003_02165c9c_3 {
    short unknown_0_[2];
};

struct Struct_ov003_0217f3ec_2 {
#if defined(jpn)
    char unknown_0_[0x18];
#else
    char unknown1_0_[0x10];
#endif
    Struct_ov003_02165c9c_3 unknown_10_;
};

extern Struct_ov003_0217f3ec_2 data_ov003_0217f3ec;

struct Struct_ov003_02165c9c_4 {
#if defined(jpn)
    char unknown_0_[0x1c4];
    Struct_0201099c_3 unknown_2dc_;
    char unknown_1cc_[0x20c - 0x1cc];
    struct Struct_02080cc0* unknown_324_;
    char unknown_210_[0x290 - 0x210];
    unsigned char unknown_468_[4];
    char unknown_294_[0x2a8 - 0x294];
    short unknown_480_;
    char unknown_2aa_[0x2c7 - 0x2aa];
    signed char unknown_49f_;
    char unknown_2c8_[0x2e5 - 0x2c8];
    unsigned char unknown_4bd_;
#else
    char unknown1_0_[0x2dc];
    Struct_0201099c_3 unknown_2dc_;
    char unknown_2e4_[0x324 - 0x2e4];
    struct Struct_02080cc0* unknown_324_;
    char unknown_328_[0x39c - 0x328];
    char unknown_39c_[4][0x30];
    char unknown_45c_[0x468 - 0x45c];
    unsigned char unknown_468_[4];
    char unknown_46c_[0x480 - 0x46c];
    short unknown_480_;
    char unknown_482_[0x49f - 0x482];
    signed char unknown_49f_;
    char unknown_4a0_[0x4bd - 0x4a0];
    unsigned char unknown_4bd_;
#endif
};

struct Struct_ov003_02165c9c_6 {
#if defined(jpn)
    char unknown_0_[0x2a];
#else
    char unknown1_0_[0x36];
#endif
    short unknown_36_;
};

// USA: func_ov003_02165c9c
extern "C" ARM void func_ov003_02165c9c(Struct_ov003_02165c9c_4* arg0) {
    struct Struct_02080cc0* var0 = arg0->unknown_324_;
    Struct_ov003_02165c9c_2* var1;
    int var2;
    Struct_ov003_02165c9c* var3;
    short var4;
    short var5;
    int var6;
    int var7;
    int var8;
    int var9;
    int var10;
    int var11;
    int var12;
    int var13;
    int var14;
    short var15;
    int var16;
    short var17;
    int var18;
    unsigned char var19;
    int var20;
    short var21, var22, var23, var24;
    short var25, var26;
    Struct_ov003_02165c9c_3 var27;

    SetSublistEntriesFlag1_02080b54(elementObj, 6);
    party = GetParty();
    count = party->count;
    idA = 0x15;
    idB = 100;
    row = self->page * 4;
    v = -1;
    idC = 0xcb;
    emptyName = KeyTable_Get(&self->cont2dc, 0x7530);
    otherName = KeyTable_Get(&self->cont2dc, 0x7531);
    self->flag4bd = (unsigned char)idA;
    memset(self->counters, 0, 4);
    if (CompareThreshold_021614e8((int)self) == 0) {
        empty = 1;
    } else {
        var11 = 0;
    }
    var9 = var2 + var11;
    func_ov003_02166164((Struct_ov003_02165c9c_5*)arg0, var9 > 4, 1);
#if !defined(jpn)
    memset(arg0->unknown_39c_, 0, sizeof(arg0->unknown_39c_));
#endif

    for (var15 = 0; var15 < 4; var15++) {
        var3 = &var1->unknown_f80_[var5];
#if defined(jpn)
        func_02080f8c((struct Struct_02080f8c*)var0, var12, (int)var3->unknown_140_);
#else
        off = i * 0x30;
        Font_DecodeText(entry->name, (char*)self->names + off, 1);
        SetEntryFirstField02080f8c((struct Container02080f8c*)elementObj, idA, (int)&self->names[0][off]);
#endif
        if (PartyMemberRecord_GetVocation((Struct020865b0*)entry) != 0) {
            v = (short)(PartyMemberRecord_GetVocation((Struct020865b0*)entry) + 0x11);
        }
        ResolveEntryValueByKey02080fe0(elementObj, (short)(idA + 4), v);
        SetEntryFirstField02080fa8((struct Container02080fa8*)elementObj, (short)(idA + 8),
                                   entry->unk2[PartyMemberRecord_GetVocation((Struct020865b0*)entry)]);
        color = ClassifyRatio_0215f56c((S0215f56c*)entry);
        if (idA == ((struct EntryList02165c9c*)elementObj)->field36 && color == 0xf) {
            color = 0xa;
        }
        if (var5 < var2) {
            if (var3->unknown_0_0_ == arg0->unknown_480_) {
                var14 = 5;
            }
            for (var17 = 0; var17 < 3; var17++) {
                var10 = var12 + var17 * 4;
                func_02080cc0(var0, (short)var10, var14);
                func_02080b40(var0, (short)(unsigned int)var10);
            }
#if !defined(jpn)
            func_02080cc0(var0, var4, var14);
            func_02080b40(var0, var4);
#endif
            kind = entry->unkF[PartyMemberRecord_GetVocation((Struct020865b0*)entry)];
            SetEntryHalfword0xe_0208103c(elementObj, idC, (short)(kind + 100));
            if (kind != 0) {
                color = 5;
                if (kind == 0xa) {
                    color = 0xd;
                }
                func_02080cc0(var0, var13, var14);
                var18 = var15 + 0x19;
                func_02080828(var0, (short)var18, &var21, &var22);
                func_020808c8(var0, (short)(unsigned int)var18, &var23, &var24);
#if defined(jpn)
                func_02080854(var0, var13, (short)(var21 + var23 + 1), (short)(var22 + 2));
#else
                func_02080854(var0, var13, (short)(var21 + var23 + 1), var22);
#endif
                func_02080cc0(var0, var13, var14);
                func_02080b40(var0, var13);
            }
            arg0->unknown_468_[var15] = var3->unknown_174_0_ + 1;
        } else {
            var20 = var7;
            if (var11 != 0 && func_ov003_021614e8((int)arg0) == 0) {
                var11 = 0;
                var20 = var8;
            }
            func_02080cc0(var0, var12, var14);
            func_02080b40(var0, var12);
            func_02080f8c((struct Struct_02080f8c*)var0, var12, var20);
        }
        var5++;
        var12 = (short)(var12 + 1);
        var13 = (short)(var13 + 1);
#if !defined(jpn)
        var4++;
#endif
    }

    func_ov003_0215f5e8(var0, arg0->unknown_49f_, var9);
    func_ov003_02160c58(arg0, &var25, &var26);
    var1 = inline_ov003_02165c9c();
    var26 = var26 - (var1->unknown_f7c_ - 1);
    func_02080fa8((struct Struct_02080fa8*)var0, 0x23, var26);
    func_02080fa8((struct Struct_02080fa8*)var0, 0x24, var25);

    var27 = data_ov003_0217f3ec.unknown_10_;
    for (int var28 = 0; var28 < 2; var28++) {
        short var29 = var27.unknown_0_[var28];
        func_02081198((struct Struct_02081198*)var0, var29, 1);
        func_02081164((struct Struct_02081164*)var0, var29, 1);
        func_020813ec(var0, var29);
    }
    func_ov003_02160678(arg0);
    func_ov003_02160794(arg0);
}
