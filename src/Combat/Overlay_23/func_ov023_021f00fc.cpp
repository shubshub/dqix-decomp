#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_0202c1a4;
struct Struct_ov023_021edf54;

struct Struct_ov023_021f00fc {
    char unknown_0_[8];
    unsigned short unknown_8_;
    char unknown_a_[0x2a - 0xa];
    signed char unknown_2a_;
};

struct Struct_ov023_021f00fc_2 {
    char unknown_0_[4];
    unsigned int unknown_4_;
};

struct Struct_ov023_021f00fc_3 {
    char unknown_0_[0x10];
    unsigned char unknown_10_;
};

struct Struct_ov023_021f00fc_4 {
#if defined(jpn)
    char unknown_0_[0x21c];
#else
    char unknown1_0_[0x2a0];
#endif
    Struct_ov023_021f00fc* unknown_2a0_;
    char unknown_2a4_[0xeac - 0x2a4];
    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0x5948 - 0xe2c];
#else
    char unknown_eb0_[0x5758 - 0xeb0];
#endif
    int unknown_5758_[4];
    int unknown_5768_;
    unsigned char unknown_576c_;
    char unknown_576d_[0x58d0 - 0x576d];
    char unknown_58d0_[0x5900 - 0x58d0];
    unsigned char unknown_5900_;
    signed char unknown_5901_;
    char unknown_5902_[0x6e24 - 0x5902];
    int unknown_6e24_;
    unsigned short unknown_6e28_;
};

extern "C" Struct_ov023_021f00fc_3* _ZZ21inline_ov023_021f4c04vE1s;

void MessageSystem_GetInstance();
int LinkSession_IsActive(int* unknown);
int LinkSession_GetOwnSlot(SearchStruct0202c1a4* unknown);
int CollectCombatantsWithFlag0x1000_02010038(GameState* gameState, unsigned char* members);
int TestBitAt0x34_020a35e0(unsigned char* info, unsigned char member);
BattleResultMember_021f00fc* FindByByteAt118_021f0360(void* end, int member);
unsigned int GetTableEntry138_021eea98(Obj021eea98* member);
void EnqueueEventTag105_021cd4c8(unsigned short, unsigned short, signed char);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* scene, int flag);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void* scene, int flag);

extern "C" {
void __clear(void* buffer, unsigned long size);
void* LinkSession_GetInstance();
void func_ov017_021cd590(unsigned short a, int* experience, unsigned char b, int c);
void func_ov017_021cd35c(unsigned short a, void* drops, unsigned char count, signed char mask);
int func_ov023_021f5150(BattleScene_021f00fc* self, BattleInfo_021f00fc* info, int* experience, int* gold, int legacy);
}

// USA: func_ov023_021f00fc
extern "C" ARM int func_ov023_021f00fc(Struct_ov023_021f00fc_4* arg0)
{
    GameState* gameState = GameState::GetInstance();
    MessageSystem_GetInstance();
    void* unk = LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    if (!LinkSession_IsActive((int*)unk) || self->info_->leader_ == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)unk))
    {
        unsigned char var3[4];
        __clear(var3, sizeof(var3));
        if (arg0->unknown_576c_ != 0)
        {
            unsigned char var4[4];
            int var5 = func_02010038(var0, var4);
            for (int var6 = 0; var6 < var5; var6++)
                var3[var4[var6]] = 1;
        }
        for (int var7 = 0; var7 < 4; var7++)
        {
            if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var7) && var3[var7] != 0)
            {
                Struct_ov023_021f00fc_2* var8 = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var7);
                GameObject* var9 = func_0200ff1c(var0, var7);
                if (var8 != NULL)
                    var8->unknown_4_ = func_ov023_021eea98((Struct_ov023_021edf54*)var9);
                arg0->unknown_5758_[var7] = 0;
            }
        }
        func_ov017_021cd590(arg0->unknown_2a0_->unknown_8_, arg0->unknown_5758_, arg0->unknown_576c_, 0);
        func_ov017_021cd35c(arg0->unknown_2a0_->unknown_8_, arg0->unknown_58d0_, arg0->unknown_5900_, arg0->unknown_5901_);
        if (arg0->unknown_6e24_ != 0)
            func_ov017_021cd4c8(arg0->unknown_2a0_->unknown_8_, arg0->unknown_6e28_, arg0->unknown_5901_);
    }
    else
    {
        if (var2->unknown_42e2_ != 0)
            func_ov000_02160fa8(arg0, 0x2000000);
        if (!func_ov000_02160fd4(arg0, 0x4000))
            return arg0->unknown_eac_;
        if (!func_ov000_02160fd4(arg0, 0x8000))
            return arg0->unknown_eac_;
    }
    _ZZ21inline_ov023_021f4c04vE1s->unknown_10_ =func_ov023_021f5150(arg0, arg0->unknown_2a0_, arg0->unknown_5758_, &arg0->unknown_5768_, arg0->unknown_576c_) ? 1 : 0;
    int var10 = 0;
    for (int var11 = 0; var11 < 4; var11++)
    {
        if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var11))
            var10 += arg0->unknown_5758_[var11];
    }
    if (var10 > 0)
        return 6;
    return 0xb;
}
