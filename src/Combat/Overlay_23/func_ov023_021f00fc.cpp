#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct SearchStruct0202c1a4;
struct Struct_ov023_021edf54;

struct Struct_ov023_021f00fc {
    char unk_0[8];
    unsigned short unk_8;
    char unk_a[0x2a - 0xa];
    signed char leader_;
};

struct Struct_ov023_021f00fc_2 {
    char unk_0[4];
    unsigned int experience_;
};

struct Struct_ov023_021f00fc_3 {
    char unk_0[0x10];
    unsigned char unknown_10_;
};

struct Struct_ov023_021f00fc_4 {
#if defined(jpn)
    char unk_0[0x21c];
#else
    char unk_0[0x2a0];
#endif
    Struct_ov023_021f00fc* info_;
    char unknown_2a4_[0xeac - 0x2a4];
    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0x5948 - 0xe2c];
#else
    char unknown_eb0_[0x5758 - 0xeb0];
#endif
    int experience_[4];
    int unknown_5768_;
    unsigned char unknown_576c_;
    char unknown_576d_[0x58d0 - 0x576d];
    char unknown_58d0_[0x5900 - 0x58d0];
    unsigned char unknown_5900_;
    signed char unknown_5901_;
    char unknown_5902_[0x6e24 - 0x5902];
    int map_;
    unsigned short unknown_6e28_;
};

extern "C" Struct_ov023_021f00fc_3* _ZZ21inline_ov023_021f4c04vE1s;

extern "C" void MessageSystem_GetInstance();
extern "C" int LinkSession_IsActive(int* unknown);
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4* unknown);
extern "C" int func_02010038(GameState* gameState, unsigned char* members);
extern "C" int func_020a35e0(unsigned char* info, unsigned char member);
extern "C" Struct_ov023_021f00fc_2* func_ov023_021f0360(void* end, int member);
extern "C" unsigned int func_ov023_021eea98(Struct_ov023_021edf54* member);
extern "C" void func_ov017_021cd4c8(unsigned short, unsigned short, signed char);
extern "C" void func_ov000_02160fa8(void* scene, int flag);
extern "C" int func_ov000_02160fd4(void* scene, int flag);

extern "C" {
void __clear(void* buffer, unsigned long size);
void* LinkSession_GetInstance();
void func_ov017_021cd590(unsigned short a, int* experience, unsigned char b, int c);
void func_ov017_021cd35c(unsigned short a, void* arg1, unsigned char count, signed char mask);
int func_ov023_021f5150(Struct_ov023_021f00fc_4* self, Struct_ov023_021f00fc* info, int* experience, int* arg3, int arg4);
}

// USA: func_ov023_021f00fc
extern "C" ARM int func_ov023_021f00fc(Struct_ov023_021f00fc_4* self)
{
    GameState* gameState = GameState::GetInstance();
    MessageSystem_GetInstance();
    void* unk = LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    if (!LinkSession_IsActive((int*)unk) || self->info_->leader_ == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)unk))
    {
        unsigned char var3[4];
        __clear(var3, sizeof(var3));
        if (self->unknown_576c_ != 0)
        {
            unsigned char members[4];
            int count = func_02010038(gameState, members);
            for (int i = 0; i < count; i++)
                var3[members[i]] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            if (func_020a35e0((unsigned char*)self->info_, i) && var3[i] != 0)
            {
                Struct_ov023_021f00fc_2* member = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, i);
                GameObject* partyMember = func_0200ff1c(gameState, i);
                if (member != NULL)
                    member->experience_ = func_ov023_021eea98((Struct_ov023_021edf54*)partyMember);
                self->experience_[i] = 0;
            }
        }
        func_ov017_021cd590(self->info_->unk_8, self->experience_, self->unknown_576c_, 0);
        func_ov017_021cd35c(self->info_->unk_8, self->unknown_58d0_, self->unknown_5900_, self->unknown_5901_);
        if (self->map_ != 0)
            func_ov017_021cd4c8(self->info_->unk_8, self->unknown_6e28_, self->unknown_5901_);
    }
    else
    {
        if (resources->unknown_42e2_ != 0)
            func_ov000_02160fa8(self, 0x2000000);
        if (!func_ov000_02160fd4(self, 0x4000))
            return self->unknown_eac_;
        if (!func_ov000_02160fd4(self, 0x8000))
            return self->unknown_eac_;
    }
    _ZZ21inline_ov023_021f4c04vE1s->unknown_10_ =func_ov023_021f5150(self, self->info_, self->experience_, &self->unknown_5768_, self->unknown_576c_) ? 1 : 0;
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        if (func_020a35e0((unsigned char*)self->info_, i))
            total += self->experience_[i];
    }
    if (total > 0)
        return 6;
    return 0xb;
}
