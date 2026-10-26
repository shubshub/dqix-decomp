#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/Field3b0.h"
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct GameResources;
struct Struct_020deb08;
struct Struct_0205faf4_9;
struct Struct_ov005_02159c24;
struct Foo0207df50;
struct Camera;
struct Struct0205a198;
struct PacRecord;
struct Container020e0310;

struct Struct_ov023_021e33b4_2 {
    char unk_0[0xc20];
};

struct Struct_ov023_021e33b4_3 {
    char unk_0[0x3c];
    void* unknown_3c_;
    void* unknown_40_;
    char unknown_44_[0x4c - 0x44];
    unsigned short unknown_4c_;
    char unknown_4e_[0x50 - 0x4e];
    unsigned char unknown_50_;

    void inline_ov023_021e33b4(void* entries, int count)
    {
        unknown_40_ = entries;
        unknown_4c_ = count;
    }
};

struct Struct_ov023_021e33b4_4 {
    int unk_0;
    int unk_4;
    unsigned int unknown_8_0_ : 24;
    unsigned int unknown_b_0_ : 2;
    unsigned int unknown_b_2_ : 6;
};

struct Struct_ov023_021e33b4 {
    void* unknown_0_;
    SafeAllocator* allocator_4;
    char* pairTables_8;
    void* unk_c;
    SafeAllocator* unknown_10_;
    SafeAllocator* unknown_14_;
    char unknown_18_[0x2c - 0x18];
    SafeAllocator unknown_2c_;
    SafeAllocator unknown_40_;
#if defined(jpn)
    SafeAllocator unknown_54_;
#else
    char unk_54[0x68 - 0x54];
#endif
    SafeAllocator spriteAllocator_68;
    SafeAllocator unknown_7c_;
    SafeAllocator unknown_90_;
    char descriptor_a4[0xbc - 0xa4];
    unsigned short unknown_bc_;
    unsigned short unknown_be_;
    void* unknown_c0_;
    unsigned int unknown_c4_;
    Struct_ov023_021e33b4_3* sprites_c8;
    char* spriteEntries_cc;
    void* unknown_d0_;
#if defined(jpn)
    char unknown_d4_[0x11c - 0xd4];
#else
    char unknown_d4_[0x120 - 0xd4];
#endif
    Struct_ov023_021e33b4_2* models_120[2];
    Struct_ov023_021e33b4_2* unknown_128_[2];
    char unknown_130_[0x138 - 0x130];
    void* camera_138;
    char camera_13c[0x404 - 0x13c];
    char pairTables_404[0x474 - 0x404];
    char pairTables_474[0x4e4 - 0x474];
    unsigned char unknown_4e4_;
    signed char unknown_4e5_;
    char unknown_4e6_[0x4fc - 0x4e6];
    int combatant_4fc;
#if defined(jpn)
    char unknown1_4fc_[0x568 - 0x4fc];
#else
    char unknown_500_[0x630 - 0x500];
#endif
    int task_630;
    unsigned short unknown_634_;
    void* unknown_638_;
    void* unknown_63c_;
    void* buffers_640[2];
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

extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);

int IsMainBrightnessTransitionActive(GameResources* resources);
extern "C" void VramState_Restore(char* tables);
extern "C" void VramState_Save(char* tables);
extern "C" void VramState_Rewind(Foo0207df50* tables);
extern "C" void ItemTable_Init(void* descriptor);
extern "C" void func_020dea40(void* descriptor, void* allocator, void* data, int size, int flag);
extern "C" int func_020deb08(Struct_020deb08* descriptor);
extern "C" void func_020deb24(Struct_0205faf4_9* descriptor, int index);
extern "C" void CharacterModel_Init(void* model);
extern "C" void CharacterModel_CreateAllocators(void* model, SafeAllocator* allocator);
extern "C" void CharacterModel_ReserveVram(void* model);
extern "C" void CharacterModel_SetItemTable(void* model, int value);
extern "C" void CharacterModel_SetForceStandAnimation(void* model, unsigned char value);
extern "C" void CharacterModel_SetAngle(void* model, unsigned int value);
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02042b30(void* messages, void* tables);
extern "C" void GameState_SetCamera(GameState* gameState, int camera);
extern "C" int GameState_GetProtagonistIndex(GameState* gameState);
extern "C" void func_020a2010(void* camera);
extern "C" void Camera_SetPosition(Camera* camera, int x, int y, int z);
extern "C" void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
extern "C" void FollowCamera_DisableFollow(void* camera);
extern "C" void func_020c54a4(int a, unsigned int b, unsigned int c, unsigned short d);
extern "C" void SpriteContext_Init(char* list);
extern "C" void Sprite_Init(Struct0205a198* entry);
extern "C" int Pac_CountFiles(PacRecord* file);
extern "C" void* Pac_GetFile(PacRecord* file, int index, void** record, int* size);
extern "C" void NameText_Clear(void* arg);
extern "C" void NameText_InitFromPartyMember(void* arg, int combatant);
extern "C" void* KeyTable_Get(Container020e0310* container, int key);
extern "C" void func_ov023_021e20c0(void* table);
extern "C" void* func_02053c6c(unsigned char* combatant);
extern "C" void G3X_SetEdgeColorTable(int addr);
extern "C" void func_ov023_021e33a0(char* self, signed char mode);
extern "C" void func_ov005_02159c24(Struct_ov005_02159c24*, void*, void*);

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
void func_ov023_021e49a4(Struct_ov023_021e33b4* self);
void func_ov023_021e2ce8(int combatant, void* sprites);
}

// USA: func_ov023_021e33b4
extern "C" ARM void func_ov023_021e33b4(Struct_ov023_021e33b4* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->unknown_4e4_ == 0)
        self->unknown_4e4_++;

    if (IsMainBrightnessTransitionActive(resources))
        return;

    if (self->unknown_4e4_ == 1)
    {
        FontBankLoader* music = FontBankLoader_GetInstance();
        func_02094b40(music);
        func_02094b34(music, 0x79, 0x1fa, 0, 0);
        self->unknown_4e4_++;
    }
    else if (self->unknown_4e4_ == 2)
    {
        if (func_02094b4c(FontBankLoader_GetInstance()))
        {
            func_ov017_0219ba0c(resources, 1);
#if defined(jpn)
            self->task_630 = loader->QueueLoadGP1(g_itemDataArchive, NULL);
#else
            self->task_630 = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, NULL);
#endif
            self->unknown_4e4_++;
        }
    }
    else if (self->unknown_4e4_ == 3)
    {
        if (loader->GetTaskStatus(self->task_630))
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            SetFlags04(resources, 0x601fe);
            VramState_Restore(self->pairTables_8);
            self->unknown_14_->Reset();
            ItemTable_Init(self->descriptor_a4);
            func_020dea40(self->descriptor_a4, self->unknown_14_, data, size, 0xb);
            self->unknown_be_ = func_020deb08((Struct_020deb08*)self->descriptor_a4);
            self->unknown_bc_ = self->unknown_be_ + 0x31;
            for (int i = 0; i < self->unknown_bc_; i++)
                func_020deb24((Struct_0205faf4_9*)self->descriptor_a4, (short)i);
            self->unknown_14_->Reset();

            if (self->unknown_4e5_ == 3)
            {
                self->unknown_0_ = self->unknown_10_->Allocate(BATTLE_SIZE_021e33b4);
                func_ov005_02153ba4(self->unknown_0_);
                func_ov005_02153954(self->unknown_0_, self->unknown_10_, self->unk_c);
#if defined(jpn)
                func_ov005_02154da8((Struct_ov005_02154da8_2*)self->unknown_0_, (int)data, size);
#else
                func_ov004_02154da8(self->unknown_0_, data, size);
#endif
            }

            self->unknown_2c_.CreateTypeA(self->unknown_10_->Allocate(0x800), 0x800);
            self->unknown_40_.CreateTypeA(self->unknown_10_->Allocate(0x100), 0x100);
#if defined(jpn)
            self->unknown_54_.CreateTypeA(self->unknown_10_->Allocate(0xc00), 0xc00);
#else
            for (int i = 0; i < 2; i++)
            {
                self->buffers_640[i] = self->unknown_2c_.Allocate(0x40);
                memset(self->buffers_640[i], 0, 0x40);
            }
#endif

            self->spriteAllocator_68.CreateTypeA(self->allocator_4->Allocate(0x100), 0x100);
            self->sprites_c8 = (Struct_ov023_021e33b4_3*)self->allocator_4->Allocate(0x54);
            self->spriteEntries_cc = (char*)self->allocator_4->Allocate(SPRITE_COUNT_021e33b4 * 0x28);
            self->unknown_d0_ = self->allocator_4->Allocate(8);
            if (self->unknown_0_ != NULL && self->unknown_d0_ != NULL && self->sprites_c8 != NULL)
                func_ov005_02159c24((Struct_ov005_02159c24*)self->unknown_0_, self->unknown_d0_, self->sprites_c8);

            self->unknown_7c_.CreateTypeA(self->allocator_4->Allocate(0x300), 0x300);
            self->unknown_90_.CreateTypeA(self->allocator_4->Allocate(0x200), 0x200);

            self->models_120[0] = (Struct_ov023_021e33b4_2*)self->allocator_4->Allocate(0xc20);
            CharacterModel_Init(self->models_120[0]);
            CharacterModel_CreateAllocators(self->models_120[0], self->allocator_4);
            CharacterModel_ReserveVram(self->models_120[0]);
            CharacterModel_SetItemTable(self->models_120[0], (int)self->descriptor_a4);
            CharacterModel_SetForceStandAnimation(self->models_120[0], 1);

            self->models_120[1] = (Struct_ov023_021e33b4_2*)self->allocator_4->Allocate(0xc20);
            CharacterModel_Init(self->models_120[1]);
            CharacterModel_CreateAllocators(self->models_120[1], self->allocator_4);
            CharacterModel_ReserveVram(self->models_120[1]);
            CharacterModel_SetItemTable(self->models_120[1], (int)self->descriptor_a4);
            CharacterModel_SetForceStandAnimation(self->models_120[1], 1);

            self->unknown_14_->Reset();
            ItemTable_Init(self->descriptor_a4);
            func_020dea64(self->descriptor_a4, self->unknown_14_, data, size, data_ov023_021fd66c, 9);

            self->unknown_638_ = self->unknown_2c_.Allocate(0x2a0);
            memset(self->unknown_638_, 0, 0x2a0);
            self->unknown_63c_ = self->unknown_2c_.Allocate(0x400);
            memset(self->unknown_63c_, 0, 0x400);

            if (self->unknown_0_ != NULL)
                *(void**)((char*)self->unknown_0_ + 0xdf4) = self->descriptor_a4;

            VramState_Reserve(self->pairTables_474, 0x4000, 0x40);
            VramState_Rewind((Foo0207df50*)self->pairTables_474);
            if (self->unknown_4e5_ == 3 && self->unknown_0_ != NULL)
                func_ov005_02153b20(self->unknown_0_);

            VramState_Reserve(self->pairTables_404, 0, 0);
            VramState_Rewind((Foo0207df50*)self->pairTables_404);

            void* messages = MessageSystem_GetInstance();
            func_02042b30(messages, self->pairTables_474);
            VramState_Restore(self->pairTables_474);
            func_020432c4(messages);
            VramState_Save(self->pairTables_474);

            self->camera_138 = gameState->GetCamera();
            func_020a2010(self->camera_13c);
            Camera_SetPosition((Camera*)self->camera_13c, 0xb666, 0xa800, 0x42ccc);
            Camera_SetTarget((struct Camera*)self->camera_13c, 0xb666, 0xa800, 0);
            FollowCamera_DisableFollow(self->camera_13c);
            GameState_SetCamera(gameState, (int)self->camera_13c);
            func_020c54a4(0, 0, 0, 0);

            loader->RemoveTask(self->task_630);
            self->task_630 = -1;
            self->task_630 = loader->QueueLoadFile(data_020f2a40, NULL);
            self->unknown_4e4_++;
        }
    }
    else if (self->unknown_4e4_ == 4)
    {
        if (loader->GetTaskStatus(self->task_630))
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            self->unknown_c0_ = self->unknown_90_.Allocate(size);
            memcpy(self->unknown_c0_, data, size);
            self->unknown_c4_ = size;
            loader->RemoveTask(self->task_630);
            self->task_630 = -1;

            SpriteContext_Init((char*)self->sprites_c8);
            self->sprites_c8->unknown_50_ = 0;
            self->sprites_c8->inline_ov023_021e33b4(self->spriteEntries_cc, SPRITE_COUNT_021e33b4);
            self->sprites_c8->unknown_3c_ = self->unknown_d0_;
            for (int i = 0; i < SPRITE_COUNT_021e33b4; i++)
                Sprite_Init((Struct0205a198*)(self->spriteEntries_cc + i * 0x28));

#if defined(jpn)
            self->task_630 = loader->QueueLoadFile(data_ov023_021fdca4, NULL);
#else
            self->task_630 = loader->QueueLoadFileInGP2(data_ov023_021fdca4, data_ov023_021fdcb6, NULL);
#endif
            self->unknown_4e4_++;
        }
    }
    else if (self->unknown_4e4_ == 5)
    {
        if (loader->GetTaskStatus(self->task_630))
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
            loader->RemoveTask(self->task_630);
            self->task_630 = -1;
            self->unknown_4e4_++;
        }
    }
    else if (self->unknown_4e4_ == 6)
    {
        if (self->unknown_0_ != NULL)
        {
            if (func_ov005_0215436c(self->unknown_0_))
                self->unknown_4e4_++;
        }
    }
    else if (self->unknown_4e4_ == 7)
    {
#if !defined(jpn)
        Struct_ov023_021e33b4_4 arg;
        NameText_Clear(&arg);
        NameText_InitFromPartyMember(&arg, GameState_GetProtagonistIndex(gameState));
        void* messages = MessageSystem_GetInstance();
        Container020e0310* texts = (Container020e0310*)((char*)self->unknown_0_ + 0xdf8);
        for (int i = 0; i < 2; i++)
        {
            arg.unknown_b_0_ = i;
            func_02046380(messages);
            *(Struct_ov023_021e33b4_4**)messages = &arg;
            MessageSystem_FormatText(messages, 8, KeyTable_Get(texts, 0x226), self->buffers_640[i], 0x100, 0, 0);
        }
#endif
        self->task_630 = loader->QueueLoadFile(data_ov023_021fdcc4, NULL);
        self->unknown_4e4_++;
    }
    else if (self->unknown_4e4_ == 8)
    {
        if (loader->GetTaskStatus(self->task_630))
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            if (data != NULL)
            {
                self->unknown_7c_.Reset();
                func_ov023_021e20c0(self->unknown_d4_);
                func_ov023_021e20f0(self->unknown_d4_, &self->unknown_7c_, data, size);
                func_ov023_021e3d3c(self->unknown_d4_, 1, 1);
            }
            loader->RemoveTask(self->task_630);
            self->task_630 = -1;
            self->unknown_4e4_++;
        }
    }
    else
    {
        void* combatant = func_0200ff1c(GameState::GetInstance(), self->combatant_4fc);
        if (combatant != NULL)
        {
            CharacterModel_SetAngle(self->models_120[0], 0x1eb);
            CharacterModel_Load(self->models_120[0], func_02053c6c((unsigned char*)combatant), self->combatant_4fc, 0, 0);
        }
        self->unknown_128_[0] = self->models_120[0];
        self->unknown_128_[1] = self->models_120[1];
        self->unknown_634_ |= 0xa1;
        func_ov023_021e49a4(self);
        if (self->unknown_4e5_ == 3 && self->unknown_0_ != NULL)
        {
            func_ov005_0215a960(self->unknown_0_);
            func_ov005_0215ae7c(self->unknown_0_);
        }
        G3X_SetEdgeColorTable((int)data_ov023_021fdc94);
        func_ov023_021e3d3c(self->unknown_d4_, 0x11, 1);
        func_ov023_021e3d3c(self->unknown_d4_, 0x12, 1);
        func_ov023_021e3d3c(self->unknown_d4_, 0x1b, 1);
        func_ov023_021e3d3c(self->unknown_d4_, 0x20, 1);
#if !defined(jpn)
        func_ov023_021e2ce8(self->combatant_4fc, self->sprites_c8);
#endif
        func_ov023_021e33a0((char*)self, self->unknown_4e5_);
        self->unknown_4e4_ = 0;
        self->unknown_634_ &= ~0x2000;
    }
}
