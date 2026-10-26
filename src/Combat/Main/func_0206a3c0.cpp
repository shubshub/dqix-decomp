#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/EntryGetterTypes.h"
#include "std_library_functions.h"

#if defined(jpn)
#define func_0206a3c0 func_0206bed8
#define func_02042b98 func_02043270
#define data_020f0934 data_020f0a2c
#define data_020f093d data_020f0a54
#define data_020f0943 data_020f0a5a
#define data_020f0949 data_020f0abb
#define data_020f0950 data_020f0ac2
#define data_020f0956 data_020f0ac8
#define data_020f095c data_020f0ace
#define data_020f0963 data_020f0ad5
#define data_020f096a data_020f0adc
#define data_020f0972 data_020f0ae4
extern const char data_020e88a5[][3];
extern const unsigned short data_020e884a[];
extern "C" int memcmp(const void*, const void*, unsigned int);
#endif

struct EntryList_203dce4;
struct Node020406f8;
struct SePlayer;
struct Vec3_020406f8 { int v[3]; };
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
int IsPrefixMatch020d857c(signed char*, signed char*);
int StringStartsWithCI020d85dc(const char*, const char*);
void SePlayer_Play(SePlayer*, int, int);
extern SePlayer g_sePlayer;
extern "C" int func_02005a94(const char*);
extern "C" void func_02042b98(void*, int, int, int, int);
extern const char data_020f0934[], data_020f093d[], data_020f0943[], data_020f0949[];
extern const char data_020f0950[], data_020f0956[], data_020f095c[], data_020f0963[];
extern const char data_020f096a[], data_020f0972[];

struct Struct_0206a3c0
{
#if defined(jpn)
    char unknown_0_[0x708];
#else
    char unknown1_0_[0x838];
#endif
    int unknown_838_;
    int unknown_83c_;
    int unknown_840_;
    int unknown_844_;
    char unknown_848_[0x18];
    int unknown_860_;
    int unknown_864_;
    char unknown_868_[0x14];
    unsigned short unknown_87c_;
#if defined(jpn)
    char unknown_74e_[0x39];
#else
    char unknown_87e_[0xdb];
#endif
    unsigned char unknown_959_;
    char unknown_95a_[2];
    unsigned char unknown_95c_;
#if defined(jpn)
    char unknown_78b_[0x56];
#else
    char unknown_95d_[0x54];
#endif
    unsigned char unknown_9b1_;
    char unknown_9b2_[4];
    unsigned char unknown_9b6_;
    unsigned char unknown_9b7_;
    unsigned char unknown_9b8_;
    char unknown_9b9_[2];
    unsigned char unknown_9bb_;
};
struct Struct_0206a3c0_2
{
#if defined(jpn)
    char unknown_0_[0x874];
#else
    char unknown1_0_[0x9a4];
#endif
    int unknown_9a4_;
#if defined(jpn)
    char unknown_878_[0x788];
#else
    char unknown_9a8_[0x658];
#endif
    Struct_0206a3c0 unknown_1000_;
};

// JPN: func_0206bed8
// USA: func_0206a3c0
extern "C" ARM const char* func_0206a3c0(Struct_0206a3c0_2* arg0, const char* arg1)
{
    unsigned char scanning = 1;
    self->state.active = (unsigned char)scanning;
    GameObject* object = GameState::GetInstance()->GetLeader();
    Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4(GetGlobalPtr021075f4_0203cf4c(), self->state.entryId);
    if (object != NULL && entry != NULL)
    {
        Struct_0203de84 var3;
        Struct_0203de84 var4;
        Struct_0203de84 var5;
        var3 = *(Struct_0203de84*)&var1->obj3D_.position_;
        func_020406f8(&var5, (Struct_0203de84_2*)var2);
        var4 = var5;
        arg0->unknown_1000_.unknown_844_ = fix32ReduceAngle0To2Pi(fix32_Atan2(var3.unknown_0_[0] - var4.unknown_0_[0], var3.unknown_0_[2] - var4.unknown_0_[2]));
        arg0->unknown_1000_.unknown_9b6_ = 1;
    }
    arg0->unknown_1000_.unknown_959_ = 0;
    arg0->unknown_1000_.unknown_9b7_ = 0;
    while (var0)
    {
        if (func_020d857c((signed char*)arg1, (signed char*)data_020f0934))
        {
            arg0->unknown_1000_.unknown_844_ = arg0->unknown_1000_.unknown_83c_;
            arg0->unknown_1000_.unknown_9b6_ = 0;
            arg1 += 8;
        }
        else if (func_020d857c((signed char*)arg1, (signed char*)data_020f093d))
        {
            self->state.wait = 60;
            self->state.animation = 1;
            self->state.variant = 0;
            text += 5;
            SePlayer_Play(&g_sePlayer, 6, 0);
        }
        else if (func_020d857c((signed char*)arg1, (signed char*)data_020f0943))
        {
            self->state.wait = 60;
            self->state.animation = 1;
            self->state.variant = 1;
            text += 5;
            SePlayer_Play(&g_sePlayer, 28, 0);
        }
        else if (func_020d85dc(arg1, data_020f0949))
        {
            unsigned char var6;
            int var7 = 6;
            int var8 = var7;
            var6 = 0;
            while (arg1[var8] != '>')
            {
                if (arg1[var8] == 0) return arg1 + var8;
                var8++;
            }
            int var9 = func_02005a94(arg1 + 6);
            while (arg1[var7] != ',')
            {
                if (arg1[var7] == '>')
                {
                    arg1 += var7 + 1;
                    var6 = 1;
                    break;
                }
                var7++;
            }
            if (var6) return arg1;
            var7++;
            int var10 = func_02005a94(arg1 + var7);
            while (arg1[var7] != ',')
            {
                if (arg1[var7] == '>')
                {
                    arg1 += var7 + 1;
                    var6 = 1;
                    break;
                }
                var7++;
            }
            if (var6) return arg1;
            var7++;
            int var11 = func_02005a94(arg1 + var7);
            while (arg1[var7] != ',')
            {
                if (arg1[var7] == '>')
                {
                    arg1 += var7 + 1;
                    var6 = 1;
                    break;
                }
                var7++;
            }
            if (var6) return arg1;
            int var12 = func_02005a94(arg1 + (var7 + 1));
            if (var9 < 0) var9 = 0;
            if (var9 > 256) var9 = 256;
            if (var10 < 0) var10 = 0;
            if (var10 > 192) var10 = 192;
            if (var11 < 0) var11 = 256 - var9;
            if (var11 > 256) var11 = 256 - var9;
            if (var12 < 0) var12 = 192 - var10;
            if (var12 > 192) var12 = 192 - var10;
            func_02042b98(arg0, var9, var10, var11, var12);
            arg1 += var8 + 1;
        }
        else if (func_020d85dc(arg1, data_020f0950))
        {
            arg0->unknown_1000_.unknown_9b1_ = 0;
            arg1 += 5;
        }
        else if (func_020d85dc(arg1, data_020f0956))
        {
            arg0->unknown_1000_.unknown_9b8_ = 1;
            arg1 += 5;
        }
        else if (func_020d85dc(arg1, data_020f095c))
        {
            int var13 = 6;
            int var14 = func_02005a94(arg1 + 6);
            while (arg1[var13] != '>')
            {
                if (arg1[var13] == 0) return arg1 + var13;
                var13++;
            }
            if (var14 < 1) var14 = 1;
            arg0->unknown_9a4_ = var14;
            arg1 += var13 + 1;
        }
        else if (func_020d85dc(arg1, data_020f0963))
        {
            int var15 = 6;
            int var16 = var15;
            while (arg1[var16] != '>')
            {
                if (arg1[var16] == 0) return arg1 + var16;
                var16++;
            }
            int var17 = func_02005a94(arg1 + 6);
            if (var17 <= 0) var17 = 12;
            while (arg1[var15] != ',')
            {
                if (arg1[var15] == '>')
                {
                    arg1 += var15 + 1;
                    break;
                }
                var15++;
            }
            int var18 = func_02005a94(arg1 + (var15 + 1));
            if (var18 <= 0) var18 = 16;
            arg0->unknown_1000_.unknown_860_ = var17;
            arg0->unknown_1000_.unknown_864_ = var18;
            arg1 += var16 + 1;
        }
        else if (func_020d85dc(arg1, data_020f096a))
        {
            int var19 = 7;
            int var20 = var19;
            while (arg1[var20] != '>')
            {
                if (arg1[var20] == 0) return arg1 + var20;
                var20++;
            }
            unsigned char var21 = 0;
#if defined(jpn)
            char name[3] = {};
            signed char colorIndex = 0;
            memcpy(name, text + 7, 2);
            for (; data_020e88a5[colorIndex][0]; colorIndex++) {
                if (memcmp(name, data_020e88a5[colorIndex], 2) == 0) {
                    self->state.color = data_020e884a[colorIndex];
                    text += close + 1;
                    done = 1;
                    break;
                }
            }
            if (var21) continue;
#endif
            int var24 = func_02005a94(arg1 + 7);
            if (var24 < 0) var24 = 255;
            if (var24 > 255) var24 = 255;
            while (arg1[var19] != ',')
            {
                if (arg1[var19] == '>')
                {
                    arg1 += var19 + 1;
                    var21 = 1;
                    break;
                }
                var19++;
            }
            if (var21) continue;
            var19++;
            int var25 = func_02005a94(arg1 + var19);
            if (var25 < 0) var25 = 255;
            if (var25 > 255) var25 = 255;
            while (arg1[var19] != ',')
            {
                if (arg1[var19] == '>')
                {
                    arg1 += var19 + 1;
                    var21 = 1;
                    break;
                }
                var19++;
            }
            if (var21) continue;
            int var26 = func_02005a94(arg1 + (var19 + 1));
            if (var26 < 0) var26 = 255;
            if (var26 > 255) var26 = 255;
            arg0->unknown_1000_.unknown_87c_ = (var24 >> 3) | ((var25 >> 3) << 5) | ((var26 >> 3) << 10);
            arg1 += var20 + 1;
        }
        else if (func_020d85dc(arg1, data_020f0972))
        {
            arg0->unknown_1000_.unknown_9bb_ = 0;
            arg1 += 6;
        }
        else var0 = 0;
    }
    return arg1;
}

#if defined(jpn)
#undef func_0206a3c0
#undef func_02042b98
#undef data_020f0934
#undef data_020f093d
#undef data_020f0943
#undef data_020f0949
#undef data_020f0950
#undef data_020f0956
#undef data_020f095c
#undef data_020f0963
#undef data_020f096a
#undef data_020f0972
#endif
