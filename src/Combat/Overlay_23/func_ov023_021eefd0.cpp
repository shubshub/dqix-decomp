#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Grotto/Main/ActiveGrottoClass.h>
#include <GameState/GameState.h>
#include "Resource/GameResources.h"

struct Struct_0206f01c_2;
struct TableA68;
struct Struct_ov023_021edc08_5;
struct Struct_ov023_021eeaac_2;
struct Struct_020a0110;
struct Struct_020a0330;
struct Struct_020a0388;

struct Struct_ov023_021eefd0_8;
extern "C" void func_ov023_021edf38(void* dst, Struct_ov023_021edc08_5* src);

struct Struct_ov023_021eefd0_8 {
    const char* text_;
    const char* unk_4;
    unsigned int unk_8;

    Struct_ov023_021eefd0_8& operator=(const Struct_ov023_021eefd0_8& other)
    {
        func_ov023_021edf38(this, (Struct_ov023_021edc08_5*)&other);
        return *this;
    }
};

struct MessageSystem_021eefd0 {
    char unk_0[0x10];
    Struct_ov023_021eefd0_8* unk_10;
    char unk_14[0x20 - 0x14];
    Struct_ov023_021eefd0_8* unk_20;
#if defined(jpn)
    char unk_24[0x868 - 0x24];
    int busy_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_19b2_;

#else
    char unk_24[0x998 - 0x24];
    int busy_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
    char unknown_19b3_[0x19d7 - 0x19b3];
    unsigned char unknown_19d7_;

#endif
};

struct Struct_ov023_021eefd0 {
    char unk_0[0xc];
    unsigned int unknown_c_0_ : 7;
    unsigned int unknown_c_7_ : 7;
    unsigned int unknown_d_6_ : 14;
    unsigned int unknown_f_4_ : 4;
    char unk_10[0x68 - 0x10];
    char unknown_68_[0xb0 - 0x68];
};

struct ZoneData_021eefd0 {
    unsigned short id_;
#if defined(jpn)
    char unk_2[0x240c - 2];
#else
    char unk_2[0x23ec - 2];
#endif

    ActiveGrottoClass grotto_;
};

struct Struct_ov023_021eefd0_3 {
    char unk_0[0xc];
    int unk_c;
};

struct Struct_ov023_021eefd0_4 {
    char unk_0[0x8e30];
    int unknown_8e30_;
};

struct Struct_ov023_021eefd0_5 {
    char unk_0[0x24];
    unsigned char grotto_;
    unsigned char legacyBoss_;
    char unknown_26_[0x678 - 0x26];
    char monsters_[0xc];
};

struct Struct_ov023_021eefd0_6 {
    int step_;
    int task_;
    int unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
    char unknown_11_[0x10c - 0x11];
    char monsters_[0xc];
};

struct Struct_ov023_021eefd0_7 {
    char unk_0[0x30];
    SafeAllocator allocator_;
#if defined(jpn)
    char unknown_44_[0x218 - 0x44];
    Struct_ov023_021eefd0_4* unknown_29c_;
    Struct_ov023_021eefd0_5* info_;
    char unknown_220_[0xe28 - 0x220];
    int unknown_eac_;
    char unknown_e2c_[0x5ab9 - 0xe2c];
    unsigned char unknown_5ab9_;
    unsigned short unknown_58ca_;
    char unknown_5abc_[0x5af4 - 0x5abc];
    char texts_[0x7028 - 0x5af4];
    int unknown_6e38_;
    char unknown_702c_[0x703a - 0x702c];
    unsigned char unknown_6e4a_;

#else
    char unknown1_44_[0x29c - 0x44];
    Struct_ov023_021eefd0_4* unknown_29c_;
    Struct_ov023_021eefd0_5* info_;
    char unknown_2a4_[0xeac - 0x2a4];
    int unknown_eac_;
    char unknown_eb0_[0x58c9 - 0xeb0];
    unsigned char unknown_58c9_;
    unsigned short unknown_58ca_;
    char unknown_58cc_[0x5904 - 0x58cc];
    char texts_[0x6e38 - 0x5904];
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
extern "C" void func_0204500c(MessageSystem_021eefd0*, const char*, int);
#endif

extern "C" MessageSystem_021eefd0* MessageSystem_GetInstance();
extern "C" void func_0206efc4(void* monsters);
extern "C" void func_0206f200(int monsters, int allocator, int file, int size, int monster);
extern "C" void* func_0206f4f0(Struct_0206f01c_2* monsters, int id);
extern "C" void NameText_Clear(void* name);
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" void func_020ac4c0(void* records);
extern "C" void func_020a0330(Struct_020a0330* records, unsigned int value);
extern "C" void func_020a0110(Struct_020a0110* time, unsigned int value);
extern "C" void func_020a0388(Struct_020a0388* records, unsigned int value);
extern "C" void func_020ac494(void* records);
extern "C" void func_0209c6d8(void* obj, int value);
extern "C" void func_ov017_021cfc74(unsigned char value);
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2* end);
extern "C" int ZoneId_IsGrotto(int zone);
extern "C" void func_020117cc(char* gameState, DetailedTreasureMapData* map);

extern "C" {
void __clear(void* buffer, unsigned long size);
Struct_ov023_021eefd0_3* func_ov017_021b8478(void* unk);
Struct_ov023_021eefd0_8 func_ov023_021ed804(Struct_ov023_021eefd0_8 name, void* monster);
#if !defined(jpn)
void func_0204500c(MessageSystem_021eefd0* messages, const char* text, int a, int b);
#endif
void* LinkSession_GetInstance();
int LinkSession_IsHostOrSolo(void* unk);
int LinkSession_IsGuest(void* unk);
int func_ov023_021f4fc8();
ZoneData_021eefd0* Zone3D_GetInstance();
void Font_EncodeText(void* name, char* buffer, int a);
void VectorizedMemset(void* dst, int value, unsigned int size);
void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int size);
void func_02011744(GameState* gameState);
}

// USA: func_ov023_021eefd0
extern "C" ARM int func_ov023_021eefd0(Struct_ov023_021eefd0_7* self)
{
    Struct_ov023_021eefd0_6* end = _ZZ21inline_ov023_021f4c04vE1s;
    if (end->step_ == 0)
    {
        void* monsters = self->info_->monsters_;
        MessageSystem_021eefd0* messages = MessageSystem_GetInstance();
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        int load = 1;
        if (_ZZ21inline_ov023_021f4c04vE1s->unknown_c_ > BackgroundLoader::TaskStatus_Invalid)
        {
            if (loader->GetTaskStatus(_ZZ21inline_ov023_021f4c04vE1s->unknown_c_))
            {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(_ZZ21inline_ov023_021f4c04vE1s->unknown_c_, &file, &size);
                if (file != NULL)
                {
                    self->allocator_.Reset();
                    monsters = _ZZ21inline_ov023_021f4c04vE1s->monsters_;
                    func_0206efc4(monsters);
                    func_0206f200((int)monsters, (int)&self->allocator_, (int)file, size, (short)self->unknown_58ca_);
                }
                loader->RemoveTask(_ZZ21inline_ov023_021f4c04vE1s->unknown_c_);
                _ZZ21inline_ov023_021f4c04vE1s->unknown_c_ = -1;
                load = 0;
            }
            else
            {
                return self->unknown_eac_;
            }
        }
        if (load && self->unknown_58ca_ != 0 && func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_) == NULL)
        {
            monsters = _ZZ21inline_ov023_021f4c04vE1s->monsters_;
            if (func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_) == NULL)
            {
#if defined(jpn)
                _ZZ21inline_ov023_021f4c04vE1s->unknown_c_ = loader->QueueLoadFile(data_ov023_021fd4ec, NULL);
#else
                _ZZ21inline_ov023_021f4c04vE1s->unknown_c_ = loader->QueueLoadFileInGP2(data_ov023_021fe230, data_ov023_021fe246, NULL);
#endif

                return self->unknown_eac_;
            }
        }
        GameResources* resources = GetGameResources();
        void* unk = NULL;
        Struct_ov023_021eefd0_3* unk2 = NULL;
        int kind = -1;
        if (resources != NULL)
            unk = resources->unknown_ptr_3718;
        if (unk != NULL)
            unk2 = func_ov017_021b8478(unk);
#if defined(jpn)
        char name[40];
        if (unk2 != NULL)
            kind = unk2->unk_c;
        __clear(name, sizeof(name));
        char text[80];
        switch (self->unknown_5ab9_)
        {
        case 0:
        {
            void* monster = func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_);
            if (monster != NULL)
                strcpy(name, *(const char**)monster);
            sprintf(text, func_02072a68((TableA68*)self->texts_, 1), name);
            break;
        }
        case 1:
        {
            void* monster = func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_);
            if (monster != NULL)
                sprintf(name, func_02072a68((TableA68*)self->texts_, 5), *(const char**)monster);
            sprintf(text, func_02072a68((TableA68*)self->texts_, 1), name);
            break;
        }
        case 2:
        {
            if (kind == 0x36 || kind == 0x43 || kind == 0x50)
                strcpy(name, data_ov023_021fd504);
            else
                strcpy(name, func_02072a68((TableA68*)self->texts_, 4));
            sprintf(text, func_02072a68((TableA68*)self->texts_, 1), name);
            break;
        }
        case 3:
        {
            void* monster = func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_);
            if (monster != NULL)
                strcpy(name, *(const char**)monster);
            sprintf(text, func_02072a68((TableA68*)self->texts_, 3), name);
            break;
        }
        case 4:
        {
            void* monster = func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_);
            if (monster != NULL)
                sprintf(name, func_02072a68((TableA68*)self->texts_, 5), *(const char**)monster);
            sprintf(text, func_02072a68((TableA68*)self->texts_, 3), name);
            break;
        }
        case 5:
        {
            strcpy(name, func_02072a68((TableA68*)self->texts_, 4));
            sprintf(text, func_02072a68((TableA68*)self->texts_, 3), name);
            break;
        }
        case 6:
        {
            void* monster = func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_);
            if (monster != NULL)
                strcpy(name, *(const char**)monster);
            sprintf(text, func_02072a68((TableA68*)self->texts_, 2), name);
            break;
        }
        case 7:
        {
            void* monster = func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_);
            if (monster != NULL)
                sprintf(name, func_02072a68((TableA68*)self->texts_, 5), *(const char**)monster);
            sprintf(text, func_02072a68((TableA68*)self->texts_, 2), name);
            break;
        }
        case 8:
        {
            strcpy(name, func_02072a68((TableA68*)self->texts_, 4));
            sprintf(text, func_02072a68((TableA68*)self->texts_, 2), name);
            break;
        }
        }

#else
        Struct_ov023_021eefd0_8 name;
        if (unk2 != NULL)
            kind = unk2->unk_c;
        NameText_Clear(&name);
        void* monster = func_0206f4f0((Struct_0206f01c_2*)monsters, (short)self->unknown_58ca_);
        if (kind == 0x36 || kind == 0x43 || kind == 0x50)
            monster = func_0206f4f0((Struct_0206f01c_2*)monsters, 0x1fc);
        if (monster != NULL)
        {
            name = func_ov023_021ed804(name, monster);
            messages->unk_20 = &name;
            messages->unk_10 = &name;
        }
        char text[0x12c];
        switch (self->unknown_58c9_)
        {
        case 0:
            sprintf(text, func_02072a68((TableA68*)self->texts_, 1));
            break;
        case 1:
            messages->unknown_19d7_ = 1;
            sprintf(text, func_02072a68((TableA68*)self->texts_, 1));
            break;
        case 2:
            if (kind == 0x36 || kind == 0x43 || kind == 0x50)
                sprintf(text, func_02072a68((TableA68*)self->texts_, 1));
            else
                sprintf(text, func_02072a68((TableA68*)self->texts_, 0x32));
            break;
        case 3:
            sprintf(text, func_02072a68((TableA68*)self->texts_, 3));
            break;
        case 4:
            messages->unknown_19d7_ = 1;
            sprintf(text, func_02072a68((TableA68*)self->texts_, 3));
            break;
        case 5:
            sprintf(text, func_02072a68((TableA68*)self->texts_, 0x34));
            break;
        case 6:
            sprintf(text, func_02072a68((TableA68*)self->texts_, 2));
            break;
        case 7:
            messages->unknown_19d7_ = 1;
            sprintf(text, func_02072a68((TableA68*)self->texts_, 2));
            break;
        case 8:
            sprintf(text, func_02072a68((TableA68*)self->texts_, 0x33));
            break;
        }

#endif
        if (self->info_->legacyBoss_ != 0)
            strcat(text, func_02072a68((TableA68*)self->texts_, 0x22));
        else if (end->unknown_10_ == 0)
            strcat(text, func_02072a68((TableA68*)self->texts_, 0x22));
#if defined(jpn)
        func_0204500c(messages, text, 1);
#else
        func_0204500c(messages, text, 1, 0xe3);
#endif

        messages->unknown_19b2_ = 0;
        messages->busy_ = 1;
        if (self->unknown_29c_->unknown_8e30_ > 0)
        {
            Struct_ov023_021eefd0 records;
            func_020ac4c0(&records);
            func_020a0330((Struct_020a0330*)&records, 1);
            func_020a0110((Struct_020a0110*)records.unknown_68_, 1);
            func_020ac494(&records);
        }
        if (!LinkSession_IsGuest(LinkSession_GetInstance()) || self->info_->legacyBoss_ == 0)
            func_0209c6d8(g_bgmPlayer, 0x36);
        end->step_++;
        if (self->info_->grotto_ != 0 || self->info_->legacyBoss_ != 0)
        {
            GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
            self->unknown_6e38_ = 1;
            grotto->unknown_0[3] = 1;
            func_ov017_021cfc74(1);
        }
        func_0206efc4(_ZZ21inline_ov023_021f4c04vE1s->monsters_);
    }
    else if (end->step_ == 100)
    {
        self->unknown_6e4a_++;
        if (func_ov023_021f4fc8() || self->unknown_6e4a_ > 30)
        {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)end);
            return 0x10;
        }
    }
    else if (end->step_ == 1)
    {
        if (func_ov023_021f4fc8())
            end->step_ = 2;
    }
    else if (end->step_ == 2)
    {
        func_ov023_021eefac((Struct_ov023_021eeaac_2*)end);
        void* unk = LinkSession_GetInstance();
        ZoneData_021eefd0* zone = Zone3D_GetInstance();
        DetailedTreasureMapData* map = zone->grotto_.GetDetailedData();
        if (self->info_->legacyBoss_ != 0)
        {
            if (ZoneId_IsGrotto(zone->id_))
            {
                Struct_ov023_021eefd0 records;
                func_020ac4c0(&records);
                func_020a0388((Struct_020a0388*)&records, 1);
                if (map != NULL && map->mapType_ == 2 && map->legacy_.level_ > records.unknown_c_7_)
                    records.unknown_c_7_ = map->legacy_.level_;
                func_020ac494(&records);
            }
            return 4;
        }
        if (self->info_->grotto_ != 0)
        {
            DetailedTreasureMapData* map2 = Zone3D_GetInstance()->grotto_.GetDetailedData();
            GameState* gameState = GameState::GetInstance();
            if (LinkSession_IsHostOrSolo(unk))
            {
                void* name = gameState->GetProtagonist()->baseStats_;
#if defined(jpn)

#else
                char buffer[0xa];
                __clear(buffer, sizeof(buffer));
                Font_EncodeText(name, buffer, 1);
#endif

                map2->discoveryState_ = 3;
                VectorizedMemset(map2->clearedBy_, 0, sizeof(map2->clearedBy_));
#if defined(jpn)
                VectorizedInvertedMemcpy(name, map2->clearedBy_, 10);
#else
                VectorizedInvertedMemcpy(buffer, map2->clearedBy_, sizeof(buffer));
#endif

                func_020117cc((char*)gameState, map2);
                func_02011744(gameState);
            }
            if (ZoneId_IsGrotto(zone->id_))
            {
                Struct_ov023_021eefd0 records;
                func_020ac4c0(&records);
                func_020a0388((Struct_020a0388*)&records, 1);
                if (map != NULL && map->mapType_ == 1 && map->regular_.level_ > records.unknown_c_0_)
                    records.unknown_c_0_ = map->regular_.level_;
                func_020ac494(&records);
            }
        }
        return end->unknown_10_ ? 0xe : 6;
    }
    return self->unknown_eac_;
}
