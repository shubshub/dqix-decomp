#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/FieldTask.h"

struct Struct_02018300_3 {
    char unknown_0_[0xb2];
    short unknown_b2_;
};

struct SearchStruct;
struct ItemTable;
struct Container020e0310;
struct Struct020dfc40;

struct Struct_020465c0 {
#if defined(jpn)
    char unknown_0_[0x28];
    char* unknown_5c_;
    char unknown_2c_[0x868 - 0x2c];
#else
    void* unknown1_0_;
    char unknown_4_[0x14];
    void* unknown_18_;
    char unknown_1c_[0xc];
    void* unknown_28_;
    char unknown1_2c_[0x30];
    char* unknown_5c_;
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x19ae - 0x9a4];
#endif
    unsigned char unknown_19ae_;
};

struct Struct_ov017_021a7e14_6 {
    char unknown_0_[0x950];
    int unknown_950_;
};

struct Struct_ov017_021a7e14 {
    char unknown_0_[0x150];
    Struct_ov017_021a7e14_6* unknown_150_;
};

struct Struct_ov017_021a7e14_2 {
    char* unknown_0_;
    char* unknown_4_;
    int unknown_8_;
};

struct Struct_ov017_021a7e14_3 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
};

struct Obj021a7e14 {
    unsigned char byte0;
    unsigned char finished;
    unsigned char pad2[6];
    SafeAllocator alloc;
    Container020e0310* strings;
    char* message;
    int state;
    int taskId;
    ItemTable* container;
    short key;
    short pad32;
    int combatantId;
    short timer;
    unsigned short flags;
#if !defined(jpn)
    Struct_ov017_021a7e14_2* unknown_3c_;
    void* unknown_40_;
    void* unknown_44_;
    char* unknown_48_;
    char* unknown_4c_;
#endif
};

StoreStruct* MessageSystem_GetInstance();
extern "C" SearchStruct* LinkSession_GetInstance();
int GameState_GetProtagonistIndex(GameState* gs);
void GameObject_DisableControl(Obj020397cc* obj, int arg);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void ROMFilesystem_InitFileTables();
#if defined(jpn)
#define func_ov017_021a7dd8 func_ov017_021a8754
#endif
extern "C" void func_ov017_021a7dd8(Obj021a7e14* self);
void KeyTable_Reset(Struct020dfc40* p);
extern "C" void KeyTable_Load(void* dest, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
void ItemTable_Init(void* p);
void BuildDescriptorFlag1_020de980(void* dest, void* alloc, void* data, int size, int key);
void NameText_Clear(void* p);
extern "C" void* memset(void* dst, int c, unsigned int n);
void DispatchIfCountPositive020dcf7c(int key, void* p);
Element021a7e14* ItemTable_Find(ItemTable* c, int key);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
void NameText_InitFromPartyMember(void* obj, int combatantId);
char* StandardStrings_Get(int value);
extern "C" void func_020e4b34(void* obj, char* name, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" void func_02046380(StoreStruct* g);
void StoreInArray0x8b0_020465c0(StoreStruct* g, int a, int b);
void SetByteInRange_020465f0(unsigned char* p, int a, unsigned char b);
char* KeyTable_Get(Container020e0310* c, int key);
void Text_Append(char* dst, const char* src);
int SumKeyedLookups02086bf4(char* p, int key);
extern "C" int func_020457e0(StoreStruct* g);
int LinkSession_IsSlotLost(SearchStruct* s, int id);
int DecrementField38Clamped_021a85e8(unsigned char* obj, int amount);
void* ItemTable_Construct(void* p);
void InitStruct0207cbe8(char* p);
extern "C" void func_0207cf30(void* ctx, int key, int amount, int arg);
void MessageSystem_Reset(char* g);
void GameObject_EnableControl(void* obj);

extern AllocatorUnion g_mainAllocator;
#if defined(jpn)
extern const char data_ov017_021d7bf0[];
extern "C" void func_020de968(int, char*);
extern "C" void* func_020e08f0(int, unsigned int*);
extern "C" void __clear(void*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#else
extern const char data_ov017_021d77c4[];
extern const char data_ov017_021d77de[];
extern const char* data_020f2a18;
extern const char* data_020f2a0c;
#endif

// USA: FieldTask_ReceiveItem
// JPN: func_ov017_021a8790
// Overlay 17, originally func_ov017_021a7e14 (USA/EUR 0x021a7e14, JPN 0x021a8790)
extern "C" ARM void FieldTask_ReceiveItem(Obj021a7e14* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    StoreStruct* g = MessageSystem_GetInstance();
    FontBankLoader* bank = FontBankLoader_GetInstance();
    GetGameResources();
    SearchStruct* search = LinkSession_GetInstance();
    Obj020397cc* obj = (Obj020397cc*)gs->GetLeader();
    int val = GameState_GetProtagonistIndex(gs);
    GameObject_DisableControl(obj, 1);
    int done = 0;
    obj->fieldB2 = 0;

    if (arg0->unknown_24_ == 0) {
        func_020a0cc4(0x2000);
        void* heap = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x2000);
        if (heap == NULL) {
            ROMFilesystem_InitFileTables();
            self->finished = 1;
            return;
        }
        self->alloc.CreateTypeA(heap, 0x2000);
        self->alloc.Reset();
        self->strings = (Container020e0310*)self->alloc.Allocate(0x18);
        if (self->strings == NULL) {
            func_ov017_021a7dd8(self);
            ROMFilesystem_InitFileTables();
            self->finished = 1;
            return;
        }
#if defined(jpn)
        arg0->unknown_28_ = var1->QueueLoadFile(data_ov017_021d7bf0, NULL);
#else
        arg0->unknown_28_ = var1->QueueLoadFileInGP2(data_ov017_021d77c4, data_ov017_021d77de, NULL);
#endif
        self->state = 1;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(self->taskId, &data, &length);
            self->strings = (Container020e0310*)self->alloc.Allocate(0x18);
            KeyTable_Reset((Struct020dfc40*)self->strings);
            KeyTable_Load(self->strings, &self->alloc, data, length);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->message = g->message;
#if defined(jpn)
            func_02094b40(var3);
            func_02094b30(var3, 0x208, 0);
#endif
            arg0->unknown_24_ = 2;
        }
    } else if (arg0->unknown_24_ == 2) {
#if defined(jpn)
        if (!func_02094b4c(var3)) return;
        char var11[0x40];
#endif
        BackgroundLoader::AddLockGlobal();
        unsigned int var12;
#if defined(jpn)
        void* var13 = func_020e08f0(8, &var12);
#else
        void* var13 = ExtractFileFromGP2(data_020f2a18, data_020f2a0c, &var12);
#endif
        self->container = (ItemTable*)self->alloc.Allocate(0x18);
        ItemTable_Init(self->container);
        if (file != NULL) {
            BuildDescriptorFlag1_020de980(self->container, &self->alloc, file, size, self->key);
        }
#if defined(jpn)
        __clear(var11, sizeof(var11));
        func_020de968(arg0->unknown_30_, var11);
#else
        self->buffers = (MessageBuffers021a7e14*)self->alloc.Allocate(0xc);
        self->firstBuffer = (char*)self->alloc.Allocate(0x40);
        self->secondBuffer = (char*)self->alloc.Allocate(0x40);
        if (self->buffers != NULL && self->firstBuffer != NULL && self->secondBuffer != NULL) {
            NameText_Clear(self->buffers);
            memset(self->firstBuffer, 0, 0x40);
            memset(self->secondBuffer, 0, 0x40);
            self->buffers->first = self->firstBuffer;
            self->buffers->second = self->secondBuffer;
            DispatchIfCountPositive020dcf7c(self->key, self->buffers);
        }
#endif
        BackgroundLoader::RemoveLockGlobal();
#if !defined(jpn)
        arg0->unknown_40_ = arg0->unknown_8_.Allocate(0xc);
        arg0->unknown_44_ = arg0->unknown_8_.Allocate(0xc);
#endif
        Combatant021a7e14* combatant = (Combatant021a7e14*)GetCombatantWithFlag0x100_0200ff1c(gs, self->combatantId);
        if (ItemTable_Find(self->container, self->key) == NULL || combatant == NULL
#if !defined(jpn)
            || arg0->unknown_3c_ == NULL || arg0->unknown_48_ == NULL || arg0->unknown_4c_ == NULL ||
            arg0->unknown_40_ == NULL || arg0->unknown_44_ == NULL
#endif
        ) {
            func_ov017_021d0198(5, arg0->unknown_34_, var6, arg0->unknown_30_);
            arg0->unknown_24_ = 7;
            return;
        }
#if defined(jpn)
        func_02046380(g);
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, ((GameObject*)combatant)->baseStats_->name);
        MessageSystem_SetStringArgument((Obj02046574*)g, 1, itemName);
#else
        NameText_Clear(self->actorText);
        NameText_InitFromPartyMember(self->actorText, self->combatantId);
        NameText_Clear(self->listText);
        char* name = StandardStrings_Get((short)combatant->params->nameId);
        func_020e4b34(self->listText, name, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        func_02046380(g);
        StoreInArray0x8b0_020465c0(g, 0, 1);
        SetByteInRange_020465f0((unsigned char*)g, 0, 1);
        g->nameText = self->actorText;
        g->listText = self->buffers;
        g->actorText = self->listText;
#endif
        char* var16 = var2->unknown_5c_;
#if defined(jpn)
        memset(var16, 0, 0x800);
#else
        memset(var16, 0, 0x960);
#endif
        Text_Append(message, (char*)KeyTable_Get(self->strings, 0x64));
        Text_Append(message, (char*)KeyTable_Get(self->strings, 0x78));
        if (SumKeyedLookups02086bf4((char*)GameState_GetParty(gs), self->key) == 0x63) {
            Text_Append(message, (char*)KeyTable_Get(self->strings, 0x70));
            self->flags |= 1;
        } else {
            Text_Append(message, (char*)KeyTable_Get(self->strings, 0x6e));
        }
        var2->unknown_998_ = 1;
#if defined(jpn)
        func_0204500c((Struct_02021b84*)var2, var16, 0);
#else
        func_0204500c((Struct_02021b84*)var2, var16, 0, 0xe3);
#endif
        arg0->unknown_24_ = 3;
    } else if (arg0->unknown_24_ == 3) {
        if (var2->unknown_9a0_ == 3 || var2->unknown_9a0_ == 0) {
            var2->unknown_19ae_ = 0;
            int var17 = func_020457e0(var2);
            if (var17 == 0) {
                if (arg0->unknown_3a_ & 1) {
                    func_ov017_021d0198(8, arg0->unknown_34_, var6, arg0->unknown_30_);
                    arg0->unknown_3a_ &= ~1;
                    arg0->unknown_24_ = 7;
                } else {
                    func_ov017_021d0198(6, arg0->unknown_34_, var6, arg0->unknown_30_);
                    arg0->unknown_24_ = 4;
                    arg0->unknown_38_ = 0xe10;
                }
            } else if (var17 == 1) {
                func_ov017_021d0198(7, arg0->unknown_34_, var6, arg0->unknown_30_);
                arg0->unknown_24_ = 7;
            }
        }
    } else if (self->state == 4) {
        g->pending = 0;
        if (LinkSession_IsSlotLost(search, 0) || LinkSession_IsSlotLost(search, self->combatantId)) {
            done = 1;
        }
        int var18 = var0->GetTickCount();
        if (var18 == 0) {
            var18 = 1;
        }
        if (func_ov017_021a85e8((unsigned char*)arg0, var18) == 0) {
            var7 = 1;
        }
        if (var7) {
#if defined(jpn)
            func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0);
#else
            func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0, 0xe3);
#endif
            arg0->unknown_24_ = 7;
        }
    } else if (arg0->unknown_24_ == 5) {
        var2->unknown_19ae_ = 0;
        int var19 = var0->GetTickCount();
        if (var19 == 0) {
            var19 = 1;
        }
        if (DecrementField38Clamped_021a85e8((unsigned char*)self, ticks) == 0 && g->windowState == 3) {
            if (LinkSession_IsSlotLost(search, 0) || LinkSession_IsSlotLost(search, self->combatantId)) {
#if defined(jpn)
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0);
#else
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0, 0xe3);
#endif
                arg0->unknown_24_ = 7;
            } else {
                Element021a7e14* element = ItemTable_Find(self->container, self->key);
                LootTextContext context;
                context.allocator.ResetAllocatorPointer();
                ItemTable_Construct(context.itemTable);
                InitStruct0207cbe8((char*)&context);
                InitStruct0207cbe8((char*)&context);
                context.containerItems = self->container;
                if ((unsigned char)element->kind == 8) {
                    func_0207cf30(&context, self->key, 1, 0);
                }
#if !defined(jpn)
                func_02046380(var2);
                func_020465c0(var2, 0, 1);
                func_020465f0((unsigned char*)var2, 0, 1);
                var2->unknown1_0_ = arg0->unknown_40_;
                var2->unknown_18_ = arg0->unknown_3c_;
                var2->unknown_28_ = arg0->unknown_44_;
#endif
#if defined(jpn)
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x6f), 0);
#else
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x6f), 0, 0xe3);
#endif
                arg0->unknown_24_ = 7;
            }
        }
    } else if (self->state == 6) {
        MessageSystem_Reset((char*)g);
        g->busy = 1;
#if defined(jpn)
        func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x65), done);
#else
        func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x65), done, 0xe3);
#endif
        arg0->unknown_24_ = 7;
    } else if (arg0->unknown_24_ == 7) {
        if (var2->unknown_998_ == 0) {
            var7 = 1;
        }
        if (done) {
            MessageSystem_Reset((char*)g);
            GameObject_EnableControl(obj);
            func_ov017_021a7dd8(self);
            ROMFilesystem_InitFileTables();
            self->finished = 1;
        }
    }
}
