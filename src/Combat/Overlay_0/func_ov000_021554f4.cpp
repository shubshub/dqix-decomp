#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "GameState/BattleRecordSnapshot.h"

#if defined(jpn)
#define func_020a0644 func_020a23bc
#endif

struct Struct_ov000_021554f4_5 {
    signed int unknown_0_0_ : 3;
    signed int unknown_0_3_ : 3;
    signed int unknown_0_6_ : 3;
    signed int unknown_1_1_ : 3;
    signed int unknown_1_4_ : 3;
    signed int unknown_1_7_ : 3;
    signed int unknown_2_2_ : 3;
};

struct Struct_ov000_021554f4_9 {
    unsigned short unknown_0_0_ : 2;
    unsigned short unknown_0_2_ : 4;
    unsigned short unknown_0_6_ : 3;
    unsigned short unknown_1_1_ : 3;
};

struct Struct_ov000_021554f4_10 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov000_021554f4_11 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
};

struct Struct_ov000_021554f4_12 {
    unsigned short unknown_0_;
    char unknown_2_[0x14 - 0x2];
    Struct_ov000_021554f4_11 unknown_14_;
    char unknown_1c_[0x21 - 0x1c];
    unsigned char unknown_21_;
    Struct_ov000_021554f4_9 unknown_22_;
    unsigned char unknown_24_;
    char unknown_25_[0x2e - 0x25];
    short unknown_2e_;
    char unknown_30_[0x58 - 0x30];
    Struct_ov000_021554f4_5 unknown_58_;

    unsigned short inline_ov000_021554f4() { return unknown_22_.unknown_0_0_; }
    unsigned short inline_ov000_021554f4_2() { return unknown_22_.unknown_0_2_; }
    unsigned short inline_ov000_021554f4_3() { return unknown_22_.unknown_0_6_; }
    unsigned short inline_ov000_021554f4_4() { return unknown_22_.unknown_1_1_; }
    unsigned char inline_ov000_021554f4_5() { return unknown_21_; }
    unsigned char inline_ov000_021554f4_6() { return unknown_24_; }
};

struct Struct_ov000_021554f4 {
    char unknown_0_[8];
    short unknown_8_;
};

struct Struct_ov000_021554f4_2 {
    char unknown_0_[0x138];
    Struct_ov000_021554f4_12* unknown_138_;
    char unknown_13c_[0x144 - 0x13c];
    Struct_ov000_021554f4* unknown_144_;
    char unknown_148_[0x181 - 0x148];
    unsigned char unknown_181_;
    unsigned char unknown_182_;

    Struct_ov000_021554f4_12* inline_ov000_021554f4_7() { return unknown_138_; }
};

struct Struct_ov000_021554f4_3 {
    Struct_ov000_021554f4_11 unknown_0_[2];
    short unknown_10_;
    short unknown_12_;
    unsigned short unknown_14_;
    short unknown_16_;
    Struct_ov000_021554f4_9 unknown_18_[2];
    Struct_ov000_021554f4_10 unknown_1c_[2];
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    float unknown_20_;
    unsigned char unknown_24_;
    unsigned char unknown_25_;
    unsigned char unknown_26_;
    Struct_ov000_021554f4_5 unknown_28_[2];
    unsigned short unknown_30_[8];
};

struct Struct_ov000_021554f4_4 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    unsigned char unknown_25_;
};

struct Struct_ov000_021554f4_6 {
    char unknown_0_[0x5c60];
    Struct_ov000_021554f4_3 unknown_5c60_[16];
    char unknown_6060_[0x8e04 - 0x6060];
    short unknown_8e04_;
    signed char unknown_8e06_;
    unsigned char unknown_8e07_;
    char unknown_8e08_[0x8e18 - 0x8e08];
    Struct_ov000_021554f4_4* unknown_8e18_;
    char unknown_8e1c_[4];
    int unknown_8e20_;
};

struct Struct_ov000_021554f4_7 {
    char unknown_0_[4];
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
};

struct Struct_ov000_021554f4_8 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
};

struct Struct_02048150;
struct Struct_02054000;
struct Struct_02052df8;

extern "C" Struct_ov000_021554f4_2* func_0200fea4(GameState*, int);
extern "C" int func_ov000_02155154(GameObject*);
extern "C" int func_02086ef0(Struct_02048150*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" float func_ov000_02155a04(char*);
Active021554f4* GetActiveSub_02054000(Outer_02054000*);
unsigned short GetHalfwordEntryFromField150(Field150Holder02052df8*, int);
struct S_a0840;
struct S_a02d0;
struct S_a0644;
void AddSaturateField0x44_020a0840(S_a0840*, unsigned int);
void AddClamped24BitFieldAt0x20_020a02d0(S_a02d0*, unsigned int);
void AddClamped16BitHighAt0x24_020a0644(S_a0644*, unsigned int);
int GameState_GetProtagonistIndex(GameState*);
int CopyInBattleField0x7540_020ac494(void*);

extern const signed char data_ov000_02182a7c[9];

static inline int inline_ov000_021554f4_8(int arg0) { return arg0 >= 0 && arg0 <= 3; }

// USA: func_ov000_021554f4
extern "C" ARM void func_ov000_021554f4(Root021554f4* self, int id, int other, Rec021554f4* rec, unsigned char arg, int flags) {
    GameState* gs = GameState::GetInstance();
    ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance());
    Unit021554f4* c = GetCombatantWithFlag0x400_0200fea4(gs, id);
    if (!c) return;
    if (c->GetStats()->currHP == 0 && flags == 8) {
        int idx = self->curIdx;
        if (idx < 0) return;
        if (self->curId == id) self->entries[idx].flags = flags;
        return;
    }
    if (var2->unknown_144_ && var2->unknown_144_->unknown_8_ == 0xf5 && func_ov000_02155154((GameObject*)var2)
        && func_02086ef0(var1, var2->inline_ov000_021554f4_7()->unknown_2e_)) {
        if (!(func_ov000_02155154((GameObject*)var2) && var2->unknown_181_) && var2->unknown_182_
            && func_02086ef0(var1, arg2)) {
            Struct_ov000_021554f4_2* var4 = (Struct_ov000_021554f4_2*)GameState::GetInstance()->GetCombatantByIndex(arg2);
            if (var4 && var4->inline_ov000_021554f4_7()->unknown_58_.unknown_1_1_ == 2) func_ov000_0215a8d4((unsigned char*)arg0, 8);
        }
    }
    arg0->unknown_8e04_ = -1;
    arg0->unknown_8e06_ = -1;
    if (arg0->unknown_8e07_ >= 16) return;
    if (inline_ov000_021554f4_8(arg1)) return;
    arg0->unknown_8e04_ = arg1;
    arg0->unknown_8e06_ = arg0->unknown_8e07_;
    Struct_ov000_021554f4_3* var5;
    Struct_ov000_021554f4* var6 = var2->unknown_144_;
    Struct_ov000_021554f4_2* var7 = (Struct_ov000_021554f4_2*)GameState::GetInstance()->GetCombatantByIndex(arg2);
    var5 = &arg0->unknown_5c60_[arg0->unknown_8e07_++];
    memset(var5, 0, sizeof(*var5));
    unsigned int var8 = var2->inline_ov000_021554f4_7()->unknown_14_.unknown_4_;
    if (var2->unknown_181_) var8 &= ~0x1000;
    var5->unknown_0_[0].unknown_0_ = var2->inline_ov000_021554f4_7()->unknown_14_.unknown_0_;
    var5->unknown_0_[0].unknown_4_ = var8;
    var5->unknown_18_[0].unknown_0_0_ = var2->inline_ov000_021554f4_7()->inline_ov000_021554f4();
    var5->unknown_18_[0].unknown_0_2_ = var2->inline_ov000_021554f4_7()->inline_ov000_021554f4_2();
    var5->unknown_18_[0].unknown_0_6_ = var2->inline_ov000_021554f4_7()->inline_ov000_021554f4_3();
    var5->unknown_1c_[0].unknown_0_0_ = var2->inline_ov000_021554f4_7()->inline_ov000_021554f4_5();
    var5->unknown_1c_[0].unknown_0_4_ = var2->inline_ov000_021554f4_7()->inline_ov000_021554f4_6();
    var5->unknown_18_[0].unknown_1_1_ = var2->inline_ov000_021554f4_7()->inline_ov000_021554f4_4();
    var5->unknown_28_[0] = var2->inline_ov000_021554f4_7()->unknown_58_;
    var5->unknown_0_[1].unknown_0_ = var7->inline_ov000_021554f4_7()->unknown_14_.unknown_0_;
    var5->unknown_0_[1].unknown_4_ = var7->inline_ov000_021554f4_7()->unknown_14_.unknown_4_;
    var5->unknown_18_[1].unknown_0_0_ = var7->inline_ov000_021554f4_7()->inline_ov000_021554f4();
    var5->unknown_18_[1].unknown_0_2_ = var7->inline_ov000_021554f4_7()->inline_ov000_021554f4_2();
    var5->unknown_18_[1].unknown_0_6_ = var7->inline_ov000_021554f4_7()->inline_ov000_021554f4_3();
    var5->unknown_1c_[1].unknown_0_0_ = var7->inline_ov000_021554f4_7()->inline_ov000_021554f4_5();
    var5->unknown_1c_[1].unknown_0_4_ = var7->inline_ov000_021554f4_7()->inline_ov000_021554f4_6();
    var5->unknown_18_[1].unknown_1_1_ = var7->inline_ov000_021554f4_7()->inline_ov000_021554f4_4();
    var5->unknown_28_[1] = var7->inline_ov000_021554f4_7()->unknown_58_;
    var5->unknown_10_ = var6->unknown_8_;
    var5->unknown_12_ = arg2;
    var5->unknown_1e_ = arg5;
    var5->unknown_1f_ = arg4;
    var5->unknown_16_ = arg0->unknown_8e20_;
    var5->unknown_20_ = func_ov000_02155a04((char*)var2);
    var5->unknown_24_ = 0;
    var5->unknown_25_ = arg0->unknown_8e18_->unknown_24_;
    var5->unknown_26_ = arg0->unknown_8e18_->unknown_25_;
    if (arg3) var5->unknown_14_ = arg3->unknown_4_0_;
    if (inline_ov000_021554f4_8(arg2)) {
        GameObject* var9 = func_0200ff1c(var0, arg2);
        if (!var9) return;
        Struct_ov000_021554f4_8* var10 = func_02054000((Struct_02054000*)var9);
        if (var10) var5->unknown_24_ = var10->unknown_8_4_;
        for (int var11 = 0; data_ov000_02182a7c[var11] != -1; var11++)
            var5->unknown_30_[var11] = func_02052df8((Struct_02052df8*)var9, data_ov000_02182a7c[var11]);
    }
    if (!ArrayContainsByte_02086ef0(party, other)) return;
    if (flags & 1) return;
    if (flags & 2) return;
    if (flags & 4) return;
    if (flags & 0x10) return;
    if (flags & 0x20) return;
    BattleRecordSnapshot snap;
    LoadBattleBlock020ac4c0(&snap);
    AddSaturateField0x44_020a0840((S_a0840*)&snap, 1);
    AddClamped24BitFieldAt0x20_020a02d0((S_a02d0*)&snap.secondaryClocks, 1);
    if (other == GameState_GetProtagonistIndex(gs)) AddClamped16BitHighAt0x24_020a0644((S_a0644*)&snap, 1);
    CopyInBattleField0x7540_020ac494(&snap);
}
