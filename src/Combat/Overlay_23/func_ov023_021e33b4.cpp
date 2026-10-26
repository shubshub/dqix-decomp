#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/Field3b0.h"
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct GameResources;
struct Pair020deb08;
struct EntryList020deb24;
struct Obj02159c24;
struct Foo0207df50;
struct Camera;
struct Struct0205a198;
struct PacRecord;
struct Container020e0310;

struct Struct_ov023_021e33b4_2 {
    char unknown_0_[0xc20];
};

struct Struct_ov023_021e33b4_3 {
    char unknown_0_[0x3c];
    void* unknown_3c_;
    void* unknown_40_;
    char unknown_44_[0x4c - 0x44];
    unsigned short unknown_4c_;
    char unknown_4e_[0x50 - 0x4e];
    unsigned char unknown_50_;

    void inline_ov023_021e33b4(void* arg0, int arg1)
    {
        unknown_40_ = arg0;
        unknown_4c_ = arg1;
    }
};

struct Struct_ov023_021e33b4_4 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 2;
    unsigned int unknown_b_2_ : 6;
};

struct Struct_ov023_021e33b4 {
    void* unknown_0_;
    SafeAllocator* unknown_4_;
    char* unknown_8_;
    void* unknown_c_;
    SafeAllocator* unknown_10_;
    SafeAllocator* unknown_14_;
    char unknown_18_[0x2c - 0x18];
    SafeAllocator unknown_2c_;
    SafeAllocator unknown_40_;
#if defined(jpn)
    SafeAllocator unknown_54_;
#else
    char unknown1_54_[0x68 - 0x54];
#endif
    SafeAllocator unknown_68_;
    SafeAllocator unknown_7c_;
    SafeAllocator unknown_90_;
    char unknown_a4_[0xbc - 0xa4];
    unsigned short unknown_bc_;
    unsigned short unknown_be_;
    void* unknown_c0_;
    unsigned int unknown_c4_;
    Struct_ov023_021e33b4_3* unknown_c8_;
    char* unknown_cc_;
    void* unknown_d0_;
#if defined(jpn)
    char unknown_d4_[0x11c - 0xd4];
#else
    char unknown_d4_[0x120 - 0xd4];
#endif
    Struct_ov023_021e33b4_2* unknown_120_[2];
    Struct_ov023_021e33b4_2* unknown_128_[2];
    char unknown_130_[0x138 - 0x130];
    void* unknown_138_;
    char unknown_13c_[0x404 - 0x13c];
    char unknown_404_[0x474 - 0x404];
    char unknown_474_[0x4e4 - 0x474];
    unsigned char unknown_4e4_;
    signed char unknown_4e5_;
    char unknown_4e6_[0x4fc - 0x4e6];
    int unknown_4fc_;
#if defined(jpn)
    char unknown1_4fc_[0x568 - 0x4fc];
#else
    char unknown_500_[0x630 - 0x500];
#endif
    int unknown_630_;
    unsigned short unknown_634_;
    void* unknown_638_;
    void* unknown_63c_;
    void* unknown_640_[2];
};

extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern const char* data_020f2a40;
extern const char data_ov023_021fd66c[];
extern const char data_ov023_021fdca4[];
extern const char data_ov023_021fdcb6[];
extern const char data_ov023_021fdcc4[];
extern const char data_ov023_021fdc94[];

#if defined(jpn)
#define data_020f2a40 data_020f2bcc
#define data_ov023_021fd66c data_ov023_021fc936
#define data_ov023_021fdca4 data_ov023_021fcf60
#define data_ov023_021fdcc4 data_ov023_021fcf75
#define data_ov023_021fdc94 data_ov023_021fcf50
#define func_ov005_0215ae7c func_ov005_0215c33c
#define func_ov023_021e49a4 func_ov023_021e4bc8
struct Struct_ov005_02154da8_2;
extern "C" void func_ov005_02154da8(Struct_ov005_02154da8_2*, int, int);
extern const char* data_020f2bcc;
extern const char data_ov023_021fc936[];
extern const char data_ov023_021fcf60[];
extern const char data_ov023_021fcf75[];
extern const char data_ov023_021fcf50[];
#define BATTLE_SIZE_021e33b4 0x3e9c
#define SPRITE_COUNT_021e33b4 0xf
#else
#define BATTLE_SIZE_021e33b4 0x428c
#define SPRITE_COUNT_021e33b4 0x10
#endif

extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" void* memcpy(void* arg0, const void* arg1, unsigned int arg2);

int IsMainBrightnessTransitionActive(GameResources* resources);
void VramState_Restore(char* tables);
void VramState_Save(char* tables);
void VramState_Rewind(Foo0207df50* tables);
void ItemTable_Init(void* descriptor);
void BuildDescriptorFlag1_020dea40(void* descriptor, void* allocator, void* data, int size, int flag);
int GetMaxOfHalfwords0And4(Pair020deb08* descriptor);
void GetEntryByIndex020deb24(EntryList020deb24* descriptor, int index);
void CharacterModel_Init(void* model);
void CharacterModel_CreateAllocators(void* model, SafeAllocator* allocator);
void CharacterModel_ReserveVram(void* model);
void CharacterModel_SetItemTable(void* model, int value);
void CharacterModel_SetForceStandAnimation(void* model, unsigned char value);
void CharacterModel_SetAngle(void* model, unsigned int value);
void* MessageSystem_GetInstance();
void SetField0x1e28_02042b30(void* messages, void* tables);
void GameState_SetCamera(GameState* gameState, int camera);
int GameState_GetProtagonistIndex(GameState* gameState);
void InitCombatController020a2010(void* camera);
void Camera_SetPosition(Camera* camera, int x, int y, int z);
void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
void FollowCamera_DisableFollow(void* camera);
void SetFogState_020c54a4(int a, unsigned int b, unsigned int c, unsigned short d);
void SpriteContext_Init(char* list);
void Sprite_Init(Struct0205a198* entry);
int Pac_CountFiles(PacRecord* file);
void* Pac_GetFile(PacRecord* file, int index, void** record, int* size);
void NameText_Clear(void* arg);
void NameText_InitFromPartyMember(void* arg, int combatant);
void* KeyTable_Get(Container020e0310* container, int key);
void ClearFields_021e20c0(void* table);
void* GetFieldAt0x150_02053c6c(unsigned char* combatant);
void G3X_SetEdgeColorTable(int addr);
void CopyByteFieldToNextAndSet_021e33a0_021e33a0(char* self, signed char mode);
void InitEntryManagerAndAllocator02159c24(Obj02159c24*, void*, void*);

extern "C" {
void func_ov017_0219ba0c(GameResources* resources, int value);
void func_ov005_02153ba4(void* battle);
void func_ov005_02153954(void* battle, SafeAllocator* allocator, void* unk);
void func_ov004_02154da8(void* battle, void* data, unsigned int size);
void func_ov005_02153b20(void* battle);
int func_ov005_0215436c(void* battle);
void func_ov005_0215a960(void* battle);
void func_ov005_0215ae7c(void* battle);
void func_020dea64(void* descriptor, SafeAllocator* allocator, void* data, unsigned int size, const void* entries, int count);
void VramState_Reserve(void* tables, int a, int b);
void func_020432c4(void* messages);
void SpriteContext_LoadFile(void* sprites, void* record, int size, SafeAllocator* allocator);
void func_02046380(void* messages);
void MessageSystem_FormatText(void* messages, int a, void* format, void* output, int size, int b, int c);
void func_ov023_021e20f0(void* table, void* allocator, void* data, unsigned int size);
void func_ov023_021e3d3c(void* table, int id, int value);
int CharacterModel_Load(void* model, void* a, int combatant, int b, int c);
void func_ov023_021e49a4(BattleSetup021e33b4* self);
void func_ov023_021e2ce8(int combatant, void* sprites);
}

// USA: func_ov023_021e33b4
extern "C" ARM void func_ov023_021e33b4(Struct_ov023_021e33b4* arg0)
{
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();

    if (arg0->unknown_4e4_ == 0)
        arg0->unknown_4e4_++;

    if (IsMainBrightnessTransitionActive(var1))
        return;

    if (arg0->unknown_4e4_ == 1)
    {
        FontBankLoader* music = FontBankLoader_GetInstance();
        BlankFunction02094b40(music);
        BlankFunction02094b34(music, 0x79, 0x1fa, 0, 0);
        self->step_4e4++;
    }
    else if (arg0->unknown_4e4_ == 2)
    {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance()))
        {
            func_ov017_0219ba0c(var1, 1);
#if defined(jpn)
            self->task_630 = loader->QueueLoadGP1(g_itemDataArchive, NULL);
#else
            self->task_630 = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, NULL);
#endif
            arg0->unknown_4e4_++;
        }
    }
    else if (arg0->unknown_4e4_ == 3)
    {
        if (var2->GetTaskStatus(arg0->unknown_630_))
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            SetFlags04(resources, 0x601fe);
            VramState_Restore(self->pairTables_8);
            self->allocator_14->Reset();
            ItemTable_Init(self->descriptor_a4);
            BuildDescriptorFlag1_020dea40(self->descriptor_a4, self->allocator_14, data, size, 0xb);
            self->maxEntry_be = GetMaxOfHalfwords0And4((Pair020deb08*)self->descriptor_a4);
            self->entryCount_bc = self->maxEntry_be + 0x31;
            for (int i = 0; i < self->entryCount_bc; i++)
                GetEntryByIndex020deb24((EntryList020deb24*)self->descriptor_a4, (short)i);
            self->allocator_14->Reset();

            if (arg0->unknown_4e5_ == 3)
            {
                arg0->unknown_0_ = arg0->unknown_10_->Allocate(BATTLE_SIZE_021e33b4);
                func_ov005_02153ba4(arg0->unknown_0_);
                func_ov005_02153954(arg0->unknown_0_, arg0->unknown_10_, arg0->unknown_c_);
#if defined(jpn)
                func_ov005_02154da8((Struct_ov005_02154da8_2*)arg0->unknown_0_, (int)var4, var5);
#else
                func_ov004_02154da8(arg0->unknown_0_, var4, var5);
#endif
            }

            arg0->unknown_2c_.CreateTypeA(arg0->unknown_10_->Allocate(0x800), 0x800);
            arg0->unknown_40_.CreateTypeA(arg0->unknown_10_->Allocate(0x100), 0x100);
#if defined(jpn)
            arg0->unknown_54_.CreateTypeA(arg0->unknown_10_->Allocate(0xc00), 0xc00);
#else
            for (int var7 = 0; var7 < 2; var7++)
            {
                arg0->unknown_640_[var7] = arg0->unknown_2c_.Allocate(0x40);
                memset(arg0->unknown_640_[var7], 0, 0x40);
            }
#endif

            arg0->unknown_68_.CreateTypeA(arg0->unknown_4_->Allocate(0x100), 0x100);
            arg0->unknown_c8_ = (Struct_ov023_021e33b4_3*)arg0->unknown_4_->Allocate(0x54);
            arg0->unknown_cc_ = (char*)arg0->unknown_4_->Allocate(SPRITE_COUNT_021e33b4 * 0x28);
            arg0->unknown_d0_ = arg0->unknown_4_->Allocate(8);
            if (arg0->unknown_0_ != NULL && arg0->unknown_d0_ != NULL && arg0->unknown_c8_ != NULL)
                func_ov005_02159c24((Struct_ov005_02159c24*)arg0->unknown_0_, arg0->unknown_d0_, arg0->unknown_c8_);

            arg0->unknown_7c_.CreateTypeA(arg0->unknown_4_->Allocate(0x300), 0x300);
            arg0->unknown_90_.CreateTypeA(arg0->unknown_4_->Allocate(0x200), 0x200);

            self->models_120[0] = (Model021e33b4*)self->allocator_4->Allocate(0xc20);
            CharacterModel_Init(self->models_120[0]);
            CharacterModel_CreateAllocators(self->models_120[0], self->allocator_4);
            CharacterModel_ReserveVram(self->models_120[0]);
            CharacterModel_SetItemTable(self->models_120[0], (int)self->descriptor_a4);
            CharacterModel_SetForceStandAnimation(self->models_120[0], 1);

            self->models_120[1] = (Model021e33b4*)self->allocator_4->Allocate(0xc20);
            CharacterModel_Init(self->models_120[1]);
            CharacterModel_CreateAllocators(self->models_120[1], self->allocator_4);
            CharacterModel_ReserveVram(self->models_120[1]);
            CharacterModel_SetItemTable(self->models_120[1], (int)self->descriptor_a4);
            CharacterModel_SetForceStandAnimation(self->models_120[1], 1);

            self->allocator_14->Reset();
            ItemTable_Init(self->descriptor_a4);
            func_020dea64(self->descriptor_a4, self->allocator_14, data, size, data_ov023_021fd66c, 9);

            arg0->unknown_638_ = arg0->unknown_2c_.Allocate(0x2a0);
            memset(arg0->unknown_638_, 0, 0x2a0);
            arg0->unknown_63c_ = arg0->unknown_2c_.Allocate(0x400);
            memset(arg0->unknown_63c_, 0, 0x400);

            if (arg0->unknown_0_ != NULL)
                *(void**)((char*)arg0->unknown_0_ + 0xdf4) = arg0->unknown_a4_;

            VramState_Reserve(self->pairTables_474, 0x4000, 0x40);
            VramState_Rewind((Foo0207df50*)self->pairTables_474);
            if (self->mode_4e5 == 3 && self->battle_0 != NULL)
                func_ov005_02153b20(self->battle_0);

            VramState_Reserve(self->pairTables_404, 0, 0);
            VramState_Rewind((Foo0207df50*)self->pairTables_404);

            void* messages = MessageSystem_GetInstance();
            SetField0x1e28_02042b30(messages, self->pairTables_474);
            VramState_Restore(self->pairTables_474);
            func_020432c4(messages);
            VramState_Save(self->pairTables_474);

            self->camera_138 = gameState->GetCamera();
            InitCombatController020a2010(self->camera_13c);
            Camera_SetPosition((Camera*)self->camera_13c, 0xb666, 0xa800, 0x42ccc);
            Camera_SetTarget((struct Camera*)self->camera_13c, 0xb666, 0xa800, 0);
            FollowCamera_DisableFollow(self->camera_13c);
            GameState_SetCamera(gameState, (int)self->camera_13c);
            SetFogState_020c54a4(0, 0, 0, 0);

            var2->RemoveTask(arg0->unknown_630_);
            arg0->unknown_630_ = -1;
            arg0->unknown_630_ = var2->QueueLoadFile(data_020f2a40, NULL);
            arg0->unknown_4e4_++;
        }
    }
    else if (arg0->unknown_4e4_ == 4)
    {
        if (var2->GetTaskStatus(arg0->unknown_630_))
        {
            void* var9;
            unsigned int var10;
            var2->GetLoadedFileByID(arg0->unknown_630_, &var9, &var10);
            arg0->unknown_c0_ = arg0->unknown_90_.Allocate(var10);
            memcpy(arg0->unknown_c0_, var9, var10);
            arg0->unknown_c4_ = var10;
            var2->RemoveTask(arg0->unknown_630_);
            arg0->unknown_630_ = -1;

            SpriteContext_Init((char*)self->sprites_c8);
            self->sprites_c8->flag_50 = 0;
            self->sprites_c8->SetEntries(self->spriteEntries_cc, SPRITE_COUNT_021e33b4);
            self->sprites_c8->ptr_3c = self->spriteExtra_d0;
            for (int i = 0; i < SPRITE_COUNT_021e33b4; i++)
                Sprite_Init((Struct0205a198*)(self->spriteEntries_cc + i * 0x28));

#if defined(jpn)
            arg0->unknown_630_ = var2->QueueLoadFile(data_ov023_021fdca4, NULL);
#else
            arg0->unknown_630_ = var2->QueueLoadFileInGP2(data_ov023_021fdca4, data_ov023_021fdcb6, NULL);
#endif
            arg0->unknown_4e4_++;
        }
    }
    else if (arg0->unknown_4e4_ == 5)
    {
        if (var2->GetTaskStatus(arg0->unknown_630_))
        {
            self->spriteAllocator_68.Reset();
            void* record;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            int count = Pac_CountFiles((PacRecord*)data);
            for (int i = 0; i < count; i++)
            {
                int recordSize;
                void* found = Pac_GetFile((PacRecord*)data, i, &record, &recordSize);
                if (found != NULL)
                    SpriteContext_LoadFile(self->sprites_c8, found, recordSize, &self->spriteAllocator_68);
            }
            var2->RemoveTask(arg0->unknown_630_);
            arg0->unknown_630_ = -1;
            arg0->unknown_4e4_++;
        }
    }
    else if (arg0->unknown_4e4_ == 6)
    {
        if (arg0->unknown_0_ != NULL)
        {
            if (func_ov005_0215436c(arg0->unknown_0_))
                arg0->unknown_4e4_++;
        }
    }
    else if (arg0->unknown_4e4_ == 7)
    {
#if !defined(jpn)
        TextArg021e33b4 arg;
        NameText_Clear(&arg);
        NameText_InitFromPartyMember(&arg, GameState_GetProtagonistIndex(gameState));
        void* messages = MessageSystem_GetInstance();
        Container020e0310* texts = (Container020e0310*)((char*)self->battle_0 + 0xdf8);
        for (int i = 0; i < 2; i++)
        {
            arg.index_8 = i;
            func_02046380(messages);
            *(TextArg021e33b4**)messages = &arg;
            MessageSystem_FormatText(messages, 8, KeyTable_Get(texts, 0x226), self->buffers_640[i], 0x100, 0, 0);
        }
#endif
        arg0->unknown_630_ = var2->QueueLoadFile(data_ov023_021fdcc4, NULL);
        arg0->unknown_4e4_++;
    }
    else if (arg0->unknown_4e4_ == 8)
    {
        if (var2->GetTaskStatus(arg0->unknown_630_))
        {
            void* var23;
            unsigned int var24;
            var2->GetLoadedFileByID(arg0->unknown_630_, &var23, &var24);
            if (var23 != NULL)
            {
                arg0->unknown_7c_.Reset();
                func_ov023_021e20c0(arg0->unknown_d4_);
                func_ov023_021e20f0(arg0->unknown_d4_, &arg0->unknown_7c_, var23, var24);
                func_ov023_021e3d3c(arg0->unknown_d4_, 1, 1);
            }
            var2->RemoveTask(arg0->unknown_630_);
            arg0->unknown_630_ = -1;
            arg0->unknown_4e4_++;
        }
    }
    else
    {
        void* var25 = func_0200ff1c(GameState::GetInstance(), arg0->unknown_4fc_);
        if (var25 != NULL)
        {
            CharacterModel_SetAngle(self->models_120[0], 0x1eb);
            CharacterModel_Load(self->models_120[0], GetFieldAt0x150_02053c6c((unsigned char*)combatant), self->combatant_4fc, 0, 0);
        }
        arg0->unknown_128_[0] = arg0->unknown_120_[0];
        arg0->unknown_128_[1] = arg0->unknown_120_[1];
        arg0->unknown_634_ |= 0xa1;
        func_ov023_021e49a4(arg0);
        if (arg0->unknown_4e5_ == 3 && arg0->unknown_0_ != NULL)
        {
            func_ov005_0215a960(arg0->unknown_0_);
            func_ov005_0215ae7c(arg0->unknown_0_);
        }
        G3X_SetEdgeColorTable((int)data_ov023_021fdc94);
        func_ov023_021e3d3c(self->table_d4, 0x11, 1);
        func_ov023_021e3d3c(self->table_d4, 0x12, 1);
        func_ov023_021e3d3c(self->table_d4, 0x1b, 1);
        func_ov023_021e3d3c(self->table_d4, 0x20, 1);
#if !defined(jpn)
        func_ov023_021e2ce8(arg0->unknown_4fc_, arg0->unknown_c8_);
#endif
        func_ov023_021e33a0((char*)arg0, arg0->unknown_4e5_);
        arg0->unknown_4e4_ = 0;
        arg0->unknown_634_ &= ~0x2000;
    }
}
