#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Grotto/Main/ActiveGrottoClass.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

struct Struct_0206f01c_2;
struct Struct_02072a68_2;
struct Struct_ov023_021edc08_5;
struct Struct_ov023_021eeaac_2;
struct Struct_020a0110;
struct Struct_020a0330;
struct Struct_020a0388;

struct Struct_ov023_021eefd0_8;
extern "C" void func_ov023_021edf38(void* arg0, Struct_ov023_021edc08_5* arg1);

struct Struct_ov023_021eefd0_8 {
    const char* unknown_0_;
    const char* unknown_4_;
    unsigned int unknown_8_;

    Struct_ov023_021eefd0_8& operator=(const Struct_ov023_021eefd0_8& arg0)
    {
        func_ov023_021edf38(this, (Struct_ov023_021edc08_5*)&arg0);
        return *this;
    }
};

struct Struct_ov023_021eefd0_9 {
    char unknown_0_[0x10];
    Struct_ov023_021eefd0_8* unknown_10_;
    char unknown_14_[0x20 - 0x14];
    Struct_ov023_021eefd0_8* unknown_20_;
#if defined(jpn)
    char unknown1_24_[0x868 - 0x24];
    int unknown_998_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_19b2_;

#else
    char unknown_24_[0x998 - 0x24];
    int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
    char unknown_19b3_[0x19d7 - 0x19b3];
    unsigned char unknown_19d7_;

#endif
};

struct Struct_ov023_021eefd0 {
    char unknown_0_[0xc];
    unsigned int unknown_c_0_ : 7;
    unsigned int unknown_c_7_ : 7;
    unsigned int unknown_d_6_ : 14;
    unsigned int unknown_f_4_ : 4;
    char unknown_10_[0x68 - 0x10];
    char unknown_68_[0xb0 - 0x68];
};

struct Struct_ov023_021eefd0_2 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x240c - 2];
#else
    char unknown1_2_[0x23ec - 2];
#endif

    ActiveGrottoClass unknown_23ec_;
};

struct Struct_ov023_021eefd0_3 {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov023_021eefd0_4 {
    char unknown_0_[0x8e30];
    int unknown_8e30_;
};

struct Struct_ov023_021eefd0_5 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    unsigned char unknown_25_;
    char unknown_26_[0x678 - 0x26];
    char unknown_678_[0xc];
};

struct Struct_ov023_021eefd0_6 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
    char unknown_11_[0x10c - 0x11];
    char unknown_10c_[0xc];
};

struct Struct_ov023_021eefd0_7 {
    char unknown_0_[0x30];
    SafeAllocator unknown_30_;
#if defined(jpn)
    char unknown_44_[0x218 - 0x44];
    Struct_ov023_021eefd0_4* unknown_29c_;
    Struct_ov023_021eefd0_5* unknown_2a0_;
    char unknown_220_[0xe28 - 0x220];
    int unknown_eac_;
    char unknown_e2c_[0x5ab9 - 0xe2c];
    unsigned char unknown_5ab9_;
    unsigned short unknown_58ca_;
    char unknown_5abc_[0x5af4 - 0x5abc];
    char unknown_5904_[0x7028 - 0x5af4];
    int unknown_6e38_;
    char unknown_702c_[0x703a - 0x702c];
    unsigned char unknown_6e4a_;

#else
    char unknown1_44_[0x29c - 0x44];
    Struct_ov023_021eefd0_4* unknown_29c_;
    Struct_ov023_021eefd0_5* unknown_2a0_;
    char unknown_2a4_[0xeac - 0x2a4];
    int unknown_eac_;
    char unknown_eb0_[0x58c9 - 0xeb0];
    unsigned char unknown_58c9_;
    unsigned short unknown_58ca_;
    char unknown_58cc_[0x5904 - 0x58cc];
    char unknown_5904_[0x6e38 - 0x5904];
    int unknown_6e38_;
    char unknown_6e3c_[0x6e4a - 0x6e3c];
    unsigned char unknown_6e4a_;

#endif
};

extern "C" Struct_ov023_021eefd0_6* _ZZ21inline_ov023_021f4c04vE1s;
extern const char data_ov023_021fe230[];
extern const char data_ov023_021fe246[];
extern char g_bgmPlayer[];
#if defined(jpn)
extern const char data_ov023_021fd4ec[];
extern const char data_ov023_021fd504[];
extern "C" void func_0204500c(Struct_ov023_021eefd0_9*, const char*, int);
#endif

MessageSystem_021eefd0* MessageSystem_GetInstance();
void Clear12Bytes0206efc4(void* monsters);
void WrapCall0206f230With1000_0206f200(int monsters, int allocator, int file, int size, int monster);
void* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct* monsters, int id);
void Clear12Bytes020e46c4(void* name);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void LoadBattleBlock020ac4c0(void* records);
void AddClamped24BitFieldAt0x8_020a0330(S_a0330* records, unsigned int value);
void AddClamped16BitFieldHighAt0x10_020a0110(S_a0110* time, unsigned int value);
void AddClamped14BitFieldMidAt0xc_020a0388(S_a0388* records, unsigned int value);
void CopyInBattleField0x7540_020ac494(void* records);
void ResetAndDispatchActorContext0209c6d8(void* obj, int value);
void EnqueueEventTag162_021cfc74(unsigned char value);
void ResetFields_021eefac(Reset_021eefac* end);
int IsInRange0201b588(int zone);
void DispatchAndSetTreasureMapUnknownBit_020117cc(char* gameState, DetailedTreasureMapData* map);

extern "C" {
void __clear(void* arg0, unsigned long arg1);
Struct_ov023_021eefd0_3* func_ov017_021b8478(void* arg0);
Struct_ov023_021eefd0_8 func_ov023_021ed804(Struct_ov023_021eefd0_8 arg0, void* arg1);
#if !defined(jpn)
void func_0204500c(Struct_ov023_021eefd0_9* arg0, const char* arg1, int arg2, int arg3);
#endif
void* func_0202ae18();
int func_0202c508(void* arg0);
int func_0202c540(void* arg0);
int func_ov023_021f4fc8();
ZoneData_021eefd0* Zone3D_GetInstance();
void Font_EncodeText(void* name, char* buffer, int a);
void VectorizedMemset(void* dst, int value, unsigned int size);
void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int size);
void func_02011744(GameState* arg0);
}

// USA: func_ov023_021eefd0
extern "C" ARM int func_ov023_021eefd0(Struct_ov023_021eefd0_7* arg0)
{
    Struct_ov023_021eefd0_6* var0 = _ZZ21inline_ov023_021f4c04vE1s;
    if (var0->unknown_0_ == 0)
    {
        void* monsters = self->info_->monsters_;
        MessageSystem_021eefd0* messages = MessageSystem_GetInstance();
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        int load = 1;
        if (_ZZ17GetGlobal021ffefcvE1s->task3_ > BackgroundLoader::TaskStatus_Invalid)
        {
            if (var3->GetTaskStatus(_ZZ21inline_ov023_021f4c04vE1s->unknown_c_))
            {
                void* var5;
                unsigned int var6;
                var3->GetLoadedFileByID(_ZZ21inline_ov023_021f4c04vE1s->unknown_c_, &var5, &var6);
                if (var5 != NULL)
                {
                    arg0->unknown_30_.Reset();
                    var1 = _ZZ21inline_ov023_021f4c04vE1s->unknown_10c_;
                    func_0206efc4(var1);
                    func_0206f200((int)var1, (int)&arg0->unknown_30_, (int)var5, var6, (short)arg0->unknown_58ca_);
                }
                var3->RemoveTask(_ZZ21inline_ov023_021f4c04vE1s->unknown_c_);
                _ZZ21inline_ov023_021f4c04vE1s->unknown_c_ = -1;
                var4 = 0;
            }
            else
            {
                return arg0->unknown_eac_;
            }
        }
        if (var4 && arg0->unknown_58ca_ != 0 && func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_) == NULL)
        {
            var1 = _ZZ21inline_ov023_021f4c04vE1s->unknown_10c_;
            if (func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_) == NULL)
            {
#if defined(jpn)
                _ZZ21inline_ov023_021f4c04vE1s->unknown_c_ = var3->QueueLoadFile(data_ov023_021fd4ec, NULL);
#else
                _ZZ21inline_ov023_021f4c04vE1s->unknown_c_ = var3->QueueLoadFileInGP2(data_ov023_021fe230, data_ov023_021fe246, NULL);
#endif

                return arg0->unknown_eac_;
            }
        }
        GameResources* var7 = GetGameResources();
        void* var8 = NULL;
        Struct_ov023_021eefd0_3* var9 = NULL;
        int var10 = -1;
        if (var7 != NULL)
            var8 = var7->unknown_ptr_3718;
        if (var8 != NULL)
            var9 = func_ov017_021b8478(var8);
#if defined(jpn)
        char var11[40];
        if (var9 != NULL)
            var10 = var9->unknown_c_;
        __clear(var11, sizeof(var11));
        char var20[80];
        switch (arg0->unknown_5ab9_)
        {
        case 0:
        {
            void* var12 = func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_);
            if (var12 != NULL)
                strcpy(var11, *(const char**)var12);
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 1), var11);
            break;
        }
        case 1:
        {
            void* var13 = func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_);
            if (var13 != NULL)
                sprintf(var11, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 5), *(const char**)var13);
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 1), var11);
            break;
        }
        case 2:
        {
            if (var10 == 0x36 || var10 == 0x43 || var10 == 0x50)
                strcpy(var11, data_ov023_021fd504);
            else
                strcpy(var11, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 4));
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 1), var11);
            break;
        }
        case 3:
        {
            void* var14 = func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_);
            if (var14 != NULL)
                strcpy(var11, *(const char**)var14);
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 3), var11);
            break;
        }
        case 4:
        {
            void* var15 = func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_);
            if (var15 != NULL)
                sprintf(var11, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 5), *(const char**)var15);
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 3), var11);
            break;
        }
        case 5:
        {
            strcpy(var11, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 4));
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 3), var11);
            break;
        }
        case 6:
        {
            void* var16 = func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_);
            if (var16 != NULL)
                strcpy(var11, *(const char**)var16);
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 2), var11);
            break;
        }
        case 7:
        {
            void* var17 = func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_);
            if (var17 != NULL)
                sprintf(var11, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 5), *(const char**)var17);
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 2), var11);
            break;
        }
        case 8:
        {
            strcpy(var11, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 4));
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 2), var11);
            break;
        }
        }

#else
        Struct_ov023_021eefd0_8 var18;
        if (var9 != NULL)
            var10 = var9->unknown_c_;
        func_020e46c4(&var18);
        void* var19 = func_0206f4f0((Struct_0206f01c_2*)var1, (short)arg0->unknown_58ca_);
        if (var10 == 0x36 || var10 == 0x43 || var10 == 0x50)
            var19 = func_0206f4f0((Struct_0206f01c_2*)var1, 0x1fc);
        if (var19 != NULL)
        {
            var18 = func_ov023_021ed804(var18, var19);
            var2->unknown_20_ = &var18;
            var2->unknown_10_ = &var18;
        }
        char var20[0x12c];
        switch (arg0->unknown_58c9_)
        {
        case 0:
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 1));
            break;
        case 1:
            var2->unknown_19d7_ = 1;
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 1));
            break;
        case 2:
            if (var10 == 0x36 || var10 == 0x43 || var10 == 0x50)
                sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 1));
            else
                sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x32));
            break;
        case 3:
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 3));
            break;
        case 4:
            var2->unknown_19d7_ = 1;
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 3));
            break;
        case 5:
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x34));
            break;
        case 6:
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 2));
            break;
        case 7:
            var2->unknown_19d7_ = 1;
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 2));
            break;
        case 8:
            sprintf(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x33));
            break;
        }

#endif
        if (arg0->unknown_2a0_->unknown_25_ != 0)
            strcat(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x22));
        else if (var0->unknown_10_ == 0)
            strcat(var20, func_02072a68((Struct_02072a68_2*)arg0->unknown_5904_, 0x22));
#if defined(jpn)
        func_0204500c(var2, var20, 1);
#else
        func_0204500c(var2, var20, 1, 0xe3);
#endif

        var2->unknown_19b2_ = 0;
        var2->unknown_998_ = 1;
        if (arg0->unknown_29c_->unknown_8e30_ > 0)
        {
            Struct_ov023_021eefd0 var21;
            func_020ac4c0(&var21);
            func_020a0330((Struct_020a0330*)&var21, 1);
            func_020a0110((Struct_020a0110*)var21.unknown_68_, 1);
            func_020ac494(&var21);
        }
        if (!func_0202c540(func_0202ae18()) || self->info_->legacyBoss_ == 0)
            ResetAndDispatchActorContext0209c6d8(g_bgmPlayer, 0x36);
        end->step_++;
        if (self->info_->grotto_ != 0 || self->info_->legacyBoss_ != 0)
        {
            GrottoStruct* var22 = GameState::GetInstance()->GetGrottoStruct();
            arg0->unknown_6e38_ = 1;
            var22->unknown_0[3] = 1;
            func_ov017_021cfc74(1);
        }
        func_0206efc4(_ZZ21inline_ov023_021f4c04vE1s->unknown_10c_);
    }
    else if (var0->unknown_0_ == 100)
    {
        arg0->unknown_6e4a_++;
        if (func_ov023_021f4fc8() || arg0->unknown_6e4a_ > 30)
        {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var0);
            return 0x10;
        }
    }
    else if (var0->unknown_0_ == 1)
    {
        if (func_ov023_021f4fc8())
            var0->unknown_0_ = 2;
    }
    else if (var0->unknown_0_ == 2)
    {
        ResetFields_021eefac((Reset_021eefac*)end);
        void* unk = func_0202ae18();
        ZoneData_021eefd0* zone = Zone3D_GetInstance();
        DetailedTreasureMapData* map = zone->grotto_.GetDetailedData();
        if (self->info_->legacyBoss_ != 0)
        {
            if (func_0201b588(var24->unknown_0_))
            {
                Struct_ov023_021eefd0 var26;
                func_020ac4c0(&var26);
                func_020a0388((Struct_020a0388*)&var26, 1);
                if (var25 != NULL && var25->mapType_ == 2 && var25->legacy_.level_ > var26.unknown_c_7_)
                    var26.unknown_c_7_ = var25->legacy_.level_;
                func_020ac494(&var26);
            }
            return 4;
        }
        if (arg0->unknown_2a0_->unknown_24_ != 0)
        {
            DetailedTreasureMapData* map2 = Zone3D_GetInstance()->grotto_.GetDetailedData();
            GameState* gameState = GameState::GetInstance();
            if (func_0202c508(unk))
            {
                void* var29 = var28->GetProtagonist()->baseStats_;
#if defined(jpn)

#else
                char buffer[0xa];
                __clear(buffer, sizeof(buffer));
                Font_EncodeText(name, buffer, 1);
#endif

                var27->discoveryState_ = 3;
                VectorizedMemset(var27->clearedBy_, 0, sizeof(var27->clearedBy_));
#if defined(jpn)
                VectorizedInvertedMemcpy(var29, var27->clearedBy_, 10);
#else
                VectorizedInvertedMemcpy(var30, var27->clearedBy_, sizeof(var30));
#endif

                func_020117cc((char*)var28, var27);
                func_02011744(var28);
            }
            if (func_0201b588(var24->unknown_0_))
            {
                Struct_ov023_021eefd0 var31;
                func_020ac4c0(&var31);
                func_020a0388((Struct_020a0388*)&var31, 1);
                if (var25 != NULL && var25->mapType_ == 1 && var25->regular_.level_ > var31.unknown_c_0_)
                    var31.unknown_c_0_ = var25->regular_.level_;
                func_020ac494(&var31);
            }
        }
        return var0->unknown_10_ ? 0xe : 6;
    }
    return arg0->unknown_eac_;
}
