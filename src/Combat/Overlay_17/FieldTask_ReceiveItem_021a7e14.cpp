#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/FieldTask.h"

struct Obj020397cc {
    char pad0[0xb2];
    short fieldB2;
};

struct SearchStruct;
struct ItemTable;
struct Container020e0310;
struct Struct020dfc40;

struct StoreStruct {
#if defined(jpn)
    char pad0[0x28];
    char* message;
    char pad2c[0x868 - 0x2c];
#else
    void* nameText;
    char pad4[0x14];
    void* listText;
    char unknown_1c_[0xc];
    void* actorText;
    char pad2c[0x30];
    char* message;
    char pad60[0x998 - 0x60];
#endif
    int busy;
    char unknown_99c_[4];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x19ae - 0x9a4];
#endif
    unsigned char pending;
};

struct Struct_ov017_021a7e14_6 {
    char pad0[0x950];
    int nameId;
};

struct Struct_ov017_021a7e14 {
    char pad0[0x150];
    Struct_ov017_021a7e14_6* params;
};

struct Struct_ov017_021a7e14_2 {
    char* first;
    char* second;
    int unknown_8_;
};

struct Element021a7e14 {
    char pad0[8];
    unsigned int kind : 4;
};

struct Obj021a7e14 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char pad2[6];
    SafeAllocator alloc;
    Container020e0310* strings;
    char* message;
    int state;
    int taskId;
    ItemTable* container;
    short key;
    short unknown_32_;
    int combatantId;
    short timer;
    unsigned short flags;
#if !defined(jpn)
    Struct_ov017_021a7e14_2* buffers;
    void* actorText;
    void* listText;
    char* unknown_48_;
    char* unknown_4c_;
#endif
};

extern "C" StoreStruct* MessageSystem_GetInstance();
extern "C" SearchStruct* LinkSession_GetInstance();
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int arg);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void ROMFilesystem_InitFileTables();
#if defined(jpn)
#define func_ov017_021a7dd8 func_ov017_021a8754
#endif
extern "C" void func_ov017_021a7dd8(Obj021a7e14* self);
extern "C" void KeyTable_Reset(Struct020dfc40* p);
extern "C" void KeyTable_Load(void* dest, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" void ItemTable_Init(void* p);
extern "C" void func_020de980(void* dest, void* alloc, void* data, int size, int key);
extern "C" void NameText_Clear(void* p);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void func_020dcf7c(int key, void* p);
extern "C" Element021a7e14* ItemTable_Find(ItemTable* c, int key);
extern "C" void func_ov017_021d0198(int a, int b, int c, int d);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" char* StandardStrings_Get(int value);
extern "C" void func_020e4b34(void* obj, char* name, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" void func_02046380(StoreStruct* g);
extern "C" void func_020465c0(StoreStruct* g, int a, int b);
extern "C" void func_020465f0(unsigned char* p, int a, unsigned char b);
extern "C" char* KeyTable_Get(Container020e0310* c, int key);
extern "C" void Text_Append(char* dst, const char* src);
extern "C" int func_02086bf4(char* p, int key);
extern "C" int func_020457e0(StoreStruct* g);
extern "C" int LinkSession_IsSlotLost(SearchStruct* s, int id);
extern "C" int func_ov017_021a85e8(unsigned char* obj, int amount);
extern "C" void* ItemTable_Construct(void* p);
extern "C" void func_0207cbe8(char* p);
extern "C" void func_0207cf30(void* ctx, int key, int amount, int arg);
extern "C" void MessageSystem_Reset(char* g);
extern "C" void GameObject_EnableControl(void* obj);

extern AllocatorUnion g_mainAllocator;
#if defined(jpn)
extern const char data_ov017_021d7bf0[];
extern "C" void func_020de968(int, char*);
extern "C" void* func_020e08f0(int, unsigned int*);
extern "C" void __clear(void*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
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

    if (self->state == 0) {
        func_020a0cc4(0x2000);
        void* heap = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x2000);
        if (heap == NULL) {
            ROMFilesystem_InitFileTables();
            self->unknown_1_ = 1;
            return;
        }
        self->alloc.CreateTypeA(heap, 0x2000);
        self->alloc.Reset();
        self->strings = (Container020e0310*)self->alloc.Allocate(0x18);
        if (self->strings == NULL) {
            func_ov017_021a7dd8(self);
            ROMFilesystem_InitFileTables();
            self->unknown_1_ = 1;
            return;
        }
#if defined(jpn)
        self->taskId = loader->QueueLoadFile(data_ov017_021d7bf0, NULL);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov017_021d77c4, data_ov017_021d77de, NULL);
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
            func_02094b40(bank);
            func_02094b30(bank, 0x208, 0);
#endif
            self->state = 2;
        }
    } else if (self->state == 2) {
#if defined(jpn)
        if (!func_02094b4c(bank)) return;
        char itemName[0x40];
#endif
        BackgroundLoader::AddLockGlobal();
        unsigned int size;
#if defined(jpn)
        void* file = func_020e08f0(8, &size);
#else
        void* file = ExtractFileFromGP2(data_020f2a18, data_020f2a0c, &size);
#endif
        self->container = (ItemTable*)self->alloc.Allocate(0x18);
        ItemTable_Init(self->container);
        if (file != NULL) {
            func_020de980(self->container, &self->alloc, file, size, self->key);
        }
#if defined(jpn)
        __clear(itemName, sizeof(itemName));
        func_020de968(self->key, itemName);
#else
        self->buffers = (Struct_ov017_021a7e14_2*)self->alloc.Allocate(0xc);
        self->unknown_48_ = (char*)self->alloc.Allocate(0x40);
        self->unknown_4c_ = (char*)self->alloc.Allocate(0x40);
        if (self->buffers != NULL && self->unknown_48_ != NULL && self->unknown_4c_ != NULL) {
            NameText_Clear(self->buffers);
            memset(self->unknown_48_, 0, 0x40);
            memset(self->unknown_4c_, 0, 0x40);
            self->buffers->first = self->unknown_48_;
            self->buffers->second = self->unknown_4c_;
            func_020dcf7c(self->key, self->buffers);
        }
#endif
        BackgroundLoader::RemoveLockGlobal();
#if !defined(jpn)
        self->actorText = self->alloc.Allocate(0xc);
        self->listText = self->alloc.Allocate(0xc);
#endif
        Struct_ov017_021a7e14* combatant = (Struct_ov017_021a7e14*)func_0200ff1c(gs, self->combatantId);
        if (ItemTable_Find(self->container, self->key) == NULL || combatant == NULL
#if !defined(jpn)
            || self->buffers == NULL || self->unknown_48_ == NULL || self->unknown_4c_ == NULL ||
            self->actorText == NULL || self->listText == NULL
#endif
        ) {
            func_ov017_021d0198(5, self->combatantId, val, self->key);
            self->state = 7;
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
        func_020465c0(g, 0, 1);
        func_020465f0((unsigned char*)g, 0, 1);
        g->nameText = self->actorText;
        g->listText = self->buffers;
        g->actorText = self->listText;
#endif
        char* message = g->message;
#if defined(jpn)
        memset(message, 0, 0x800);
#else
        memset(message, 0, 0x960);
#endif
        Text_Append(message, (char*)KeyTable_Get(self->strings, 0x64));
        Text_Append(message, (char*)KeyTable_Get(self->strings, 0x78));
        if (func_02086bf4((char*)GameState_GetParty(gs), self->key) == 0x63) {
            Text_Append(message, (char*)KeyTable_Get(self->strings, 0x70));
            self->flags |= 1;
        } else {
            Text_Append(message, (char*)KeyTable_Get(self->strings, 0x6e));
        }
        g->busy = 1;
#if defined(jpn)
        func_0204500c((MessageSystem*)g, message, 0);
#else
        func_0204500c((MessageSystem*)g, message, 0, 0xe3);
#endif
        self->state = 3;
    } else if (self->state == 3) {
        if (g->unknown_9a0_ == 3 || g->unknown_9a0_ == 0) {
            g->pending = 0;
            int result = func_020457e0(g);
            if (result == 0) {
                if (self->flags & 1) {
                    func_ov017_021d0198(8, self->combatantId, val, self->key);
                    self->flags &= ~1;
                    self->state = 7;
                } else {
                    func_ov017_021d0198(6, self->combatantId, val, self->key);
                    self->state = 4;
                    self->timer = 0xe10;
                }
            } else if (result == 1) {
                func_ov017_021d0198(7, self->combatantId, val, self->key);
                self->state = 7;
            }
        }
    } else if (self->state == 4) {
        g->pending = 0;
        if (LinkSession_IsSlotLost(search, 0) || LinkSession_IsSlotLost(search, self->combatantId)) {
            done = 1;
        }
        int ticks = gs->GetTickCount();
        if (ticks == 0) {
            ticks = 1;
        }
        if (func_ov017_021a85e8((unsigned char*)self, ticks) == 0) {
            done = 1;
        }
        if (done) {
#if defined(jpn)
            func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0);
#else
            func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0, 0xe3);
#endif
            self->state = 7;
        }
    } else if (self->state == 5) {
        g->pending = 0;
        int ticks = gs->GetTickCount();
        if (ticks == 0) {
            ticks = 1;
        }
        if (func_ov017_021a85e8((unsigned char*)self, ticks) == 0 && g->unknown_9a0_ == 3) {
            if (LinkSession_IsSlotLost(search, 0) || LinkSession_IsSlotLost(search, self->combatantId)) {
#if defined(jpn)
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0);
#else
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0, 0xe3);
#endif
                self->state = 7;
            } else {
                Element021a7e14* element = ItemTable_Find(self->container, self->key);
                LootTextContext context;
                context.allocator.ResetAllocatorPointer();
                ItemTable_Construct(context.itemTable);
                func_0207cbe8((char*)&context);
                func_0207cbe8((char*)&context);
                context.containerItems = self->container;
                if ((unsigned char)element->kind == 8) {
                    func_0207cf30(&context, self->key, 1, 0);
                }
#if !defined(jpn)
                func_02046380(g);
                func_020465c0(g, 0, 1);
                func_020465f0((unsigned char*)g, 0, 1);
                g->nameText = self->actorText;
                g->listText = self->buffers;
                g->actorText = self->listText;
#endif
#if defined(jpn)
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x6f), 0);
#else
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x6f), 0, 0xe3);
#endif
                self->state = 7;
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
        self->state = 7;
    } else if (self->state == 7) {
        if (g->busy == 0) {
            done = 1;
        }
        if (done) {
            MessageSystem_Reset((char*)g);
            GameObject_EnableControl(obj);
            func_ov017_021a7dd8(self);
            ROMFilesystem_InitFileTables();
            self->unknown_1_ = 1;
        }
    }
}
