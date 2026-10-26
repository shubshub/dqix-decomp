#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/LootableContainer.h"
#include "Resource/Brightness.h"
#include "Resource/TextQueue.h"
#include "World/FieldTask.h"
#include "World/Zone3D.h"

#if defined(jpn)
enum { ContainerListOffset = 0x2764, ContainerItemsOffset = 0x2794, MessageBufferOffset = 0x2c, MessageBufferSize = 0x800 };
extern const char* data_ov017_021d7f9c[];
extern const char* FieldTask_ambushMonsterNames[];
extern char data_ov017_021d8068[], data_ov017_021d8082[], data_ov017_021d80ac[];
extern char data_ov017_021d80b0[], data_ov017_021d80b3[];
extern unsigned char FieldTask_ambushMonsterIds[];
#else
enum { ContainerListOffset = 0x2724, ContainerItemsOffset = 0x2754, MessageBufferOffset = 0x60, MessageBufferSize = 0x960 };
extern const short FieldTask_ambushMonsterNames[];
extern const unsigned char FieldTask_ambushMonsterIds[];
#endif

struct Obj020397cc;
struct Obj02033834;
struct Obj02033b68;
struct Obj02086aec;
struct Obj020d7aa0;
struct BitFlags020d805c;
struct Struct0218d618;
struct SePlayer;
struct Obj02046574;
struct TailList020469b4;
struct TailNode020469b4;
struct List02046a3c;
struct Node02046a3c;
struct GetElement02094d5cList;
struct ItemTable;

typedef LootableContainerManager::Container Container;


void* MessageSystem_GetInstance(void);
extern "C" unsigned char* Zone3D_GetInstance(void);
void* TextQueue_GetInstance(void);
extern "C" void FieldTask_EndOpenChest(OpenChestTask* self);
void GameResources_UpdateSpecialItemEffect(void* res);
void* GameState_GetFollowCamera(char* gs);
void FollowCamera_DisableFollow(void* obj);
void FollowCamera_EnableFollow(void* obj);
void GameObject_SetFacing(Obj02033834* obj, int arg);
extern "C" int* LinkSession_GetInstance(void);
unsigned char* Zone3D_GetChest(unsigned char* p, int i);
Container* GrottoChestList_Get(GetElement02094d5cList* list, int id);
void* GameState_GetParty(GameState* gs);
int LinkSession_IsActive(int* p);
extern "C" int LinkSession_IsGuest(void* p);
void NameText_InitFromPartyMember(void* obj, int combatantId);
int StandardStrings_Get(int key);
extern "C" void MessageSystem_FormatText(void* messages, int mode, int fmt, char* out, int size, int a, int b);
void GameObject_DisableControl(Obj020397cc* obj, int arg);
int GetByte0x150Bit6(BitFlags020d805c* obj);
void TextQueue_Reset(Obj020d7aa0* obj);
short Party_CountItem(Obj02086aec* obj, int key);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void GameState_SetGrottoChestOpened(void* arr, int bit, int value);
void GameObject_SetMotionState(Obj02033b68* obj, int v);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void GameResources_LoadSpecialItemEffect(GameResources* res, SafeAllocator* alloc);
void GameObject_EnableControl(void* obj);
struct UpdateStateStruct;
void ZoneChest_StartOpening(UpdateStateStruct*, int, int, int);
void LinkMessageQueue_SendChestOpened(unsigned char a, unsigned short b, unsigned short c);
int GameResources_IsSpecialItemEffectLoaded(Struct0218d618* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* Scenario_GetInstance(void);
extern "C" void FieldTask_InitAcquireTreasureMap(void* node, int flag);
extern "C" void AcquireTreasureMapTask_CreateMap(void* node, int a, int b, int c, int d);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void* ItemTable_Construct(void*);
void InitStruct0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
extern "C" void GameResources_PlaySpecialItemEffect(GameResources*, Vector3fix*, int);
void SePlayer_UnloadExtraArchiveA(void* obj);
void SePlayer_LoadExtraArchiveA(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b);
void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" void func_ov017_021cdb00(int, int, int, int);
int GameResources_IsSpecialItemEffectPlaying(void* obj);
void MessageSystem_SetStringArgument(Obj02046574* obj, int index, char* str);
void FieldTask_InitWhistle(WhistleTask* self);
void InsertNodeAfterHead(List02046a3c* list, Node02046a3c* node);

extern AllocatorUnion g_mainAllocator;
extern char g_sePlayer;

// USA: FieldTask_OpenChest
// Overlay 17, originally func_ov017_021adcb0 (USA/EUR 0x021adcb0, JPN 0x021ae4b8)
extern "C" ARM void FieldTask_OpenChest(OpenChestTask* self) {
    GameState* gs = GameState::GetInstance();
    void* messages = MessageSystem_GetInstance();
    unsigned char* zone = Zone3D_GetInstance();
    LootableContainerManager* containers = LootableContainerManager::GetMainInstance();
    GetElement02094d5cList* zoneContainers = (GetElement02094d5cList*)(zone + ContainerListOffset);
    void* textQueue = TextQueue_GetInstance();
    GameObject* opener = gs->GetPartyMemberByIndex(self->opener);
    GameResources* res = GetGameResources();
    TailList020469b4* taskQueue = (TailList020469b4*)res->fieldTaskQueue_;

    if (opener == NULL) {
        FieldTask_EndOpenChest(self);
        return;
    }
    if (res) {
        GameResources_UpdateSpecialItemEffect(res);
    }

    if (self->step == OpenChestStep_Start) {
        GameState* gs2 = GameState::GetInstance();
        void* camera = GameState_GetFollowCamera((char*)gs2);
        if (camera) {
            FollowCamera_DisableFollow(camera);
        }
        if (res) {
            SetFlags04(res, 0x80);
        }
        *(unsigned short*)((char*)opener + 0xb2) = 0;
        GameObject_SetFacing((Obj02033834*)opener, self->facing);
        int* search = LinkSession_GetInstance();
        ZoneChestRenderRecord* elem = (ZoneChestRenderRecord*)Zone3D_GetChest(zone, self->chestIndex);
        Container* container = NULL;
        if (elem) {
            if (self->fromZoneList) {
                container = GrottoChestList_Get(zoneContainers, elem->uniqueID);
            } else {
                container = containers->GetContainerByID(elem->uniqueID, NULL);
            }
        }
        Obj02086aec* party = (Obj02086aec*)GameState_GetParty(gs2);
        if (LinkSession_IsActive(search) && LinkSession_IsGuest(search) && container && container->containerType == 0) {
#if !defined(jpn)
            char who[0xc];
#endif
            char text[0x50];
#if defined(jpn)
            sprintf(text, data_ov017_021d7f9c[2], opener->baseStats_->name);
            TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1);
#else
            NameText_InitFromPartyMember(who, self->opener);
            *(char**)messages = who;
            MessageSystem_FormatText(messages, 0xc, StandardStrings_Get(0x28), text, 0xe3, 0, 1);
            TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1, 1);
#endif
            FieldTask_EndOpenChest(self);
        } else if (container && container->lock != 0) {
            GameObject_DisableControl((Obj020397cc*)opener, 1);
            void* textQueue2 = TextQueue_GetInstance();
            if (GetByte0x150Bit6((BitFlags020d805c*)textQueue2)) {
                TextQueue_Reset((Obj020d7aa0*)textQueue2);
            }
            int canOpen = 0;
            int count561c = Party_CountItem(party, 0x561c);
            int count561a = Party_CountItem(party, 0x561a);
            int count561b = Party_CountItem(party, 0x561b);
            if (count561c > 0) {
                canOpen = 1;
            } else if (container->lock == 1 && (count561a > 0 || count561b > 0)) {
                canOpen = 1;
            } else if (container->lock == 2 && count561b > 0) {
                canOpen = 1;
            }
            if (canOpen) {
#if defined(jpn)
                char text[0x78];
                sprintf(text, data_ov017_021d8068, data_ov017_021d7f9c[1], opener->baseStats_->name);
                TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1);
#else
                char text[0x100];
                char who[0xc];
                char fmt[0x100];
                int name = StandardStrings_Get(0x29);
                sprintf(fmt, "%s %s", name, StandardStrings_Get(0x2b));
                NameText_InitFromPartyMember(who, self->opener);
                *(char**)messages = who;
                MessageSystem_FormatText(messages, 0xc, (int)fmt, text, 0xe3, 0, 1);
                TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1, 1);
#endif
                self->delay = 0xf;
                self->step = OpenChestStep_Unlock;
            } else {
#if defined(jpn)
                char text[0x78];
                if (count561a > 0 || count561b > 0) {
                    sprintf(text, data_ov017_021d8082, data_ov017_021d7f9c[1]);
                } else {
                    sprintf(text, data_ov017_021d80ac, data_ov017_021d7f9c[1]);
                }
                TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1);
#else
                char text[0x100];
                if (count561a > 0 || count561b > 0) {
                    int name = StandardStrings_Get(0x29);
                    sprintf(text, "%s %s", name, StandardStrings_Get(0x2c));
                } else {
                    sprintf(text, "%s", StandardStrings_Get(0x29));
                }
                TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1, 1);
#endif
                self->timer = 0;
                self->step = OpenChestStep_Locked;
            }
        } else {
            GameObject_DisableControl((Obj020397cc*)opener, 1);
            if (self->fromZoneList) {
                GameState_SetGrottoChestOpened(gs2, *(unsigned short*)zone % 20, self->chestIndex);
            }
            GameObject_SetMotionState((Obj02033b68*)opener, 7);
            self->step = OpenChestStep_LiftLid;
        }
        if ((self->step == OpenChestStep_LiftLid || self->step == OpenChestStep_Unlock) && container && container->itemIDOrRank == 0x5617) {
            self->special = 1;
            self->allocator.ResetAllocatorPointer();
            self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x4000), 0x4000);
            self->allocator.Reset();
            GameResources_LoadSpecialItemEffect(GetGameResources(), &self->allocator);
        }
    } else if (self->step == OpenChestStep_Locked) {
        self->timer += gs->GetEffectiveDeltaTime();
        if (self->timer > 0x2ee) {
            GameObject* leader = gs->GetLeader();
            if (leader) {
                GameObject_EnableControl(leader);
            }
            FieldTask_EndOpenChest(self);
        }
    } else if (self->step == OpenChestStep_Unlock) {
        self->delay--;
        if (self->delay <= 0) {
            GameObject_SetMotionState((Obj02033b68*)opener, 7);
            self->step = OpenChestStep_LiftLid;
        }
    } else if (self->step == OpenChestStep_LiftLid) {
        if (opener->obj3D_.normalizedAnimationTime_ >= 0x666) {
            ZoneChestRenderRecord* elem = (ZoneChestRenderRecord*)Zone3D_GetChest(zone, self->chestIndex);
            if (elem) {
                if (elem->kind == 2 || elem->kind == 1) {
                    ZoneChest_StartOpening((UpdateStateStruct*)elem, opener->obj3D_.actorIndex_, 1, 1);
                } else {
                    ZoneChest_StartOpening((UpdateStateStruct*)elem, opener->obj3D_.actorIndex_, 1, 0);
                }
            }
            LinkMessageQueue_SendChestOpened(opener->obj3D_.actorIndex_, *(unsigned short*)zone, self->chestIndex);
            self->step = OpenChestStep_Open;
        }
    } else if (self->step == OpenChestStep_Open) {
        if (opener->obj3D_.normalizedAnimationTime_ >= 0xb33) {
            if (self->special && !GameResources_IsSpecialItemEffectLoaded((Struct0218d618*)GetGameResources())) {
                return;
            }
            if (!self->ambush && !self->special) {
                GameObject* leader = gs->GetLeader();
                if (leader) {
                    GameObject_EnableControl(leader);
                }
                void* camera = GameState_GetFollowCamera((char*)GameState::GetInstance());
                if (camera) {
                    FollowCamera_EnableFollow(camera);
                }
                if (res) {
                    ClearFlags04(res, 0x80);
                }
            }
            self->step = OpenChestStep_GiveContents;
        }
    } else if (self->step == OpenChestStep_GiveContents) {
        zone = Zone3D_GetInstance();
        ZoneChestRenderRecord* elem = (ZoneChestRenderRecord*)Zone3D_GetChest(zone, self->chestIndex);
        if (elem) {
            char* text = *(char**)((char*)messages + MessageBufferOffset);
            memset(text, 0, MessageBufferSize);
            int done = 0;
            if (elem) {
                Scenario_GetInstance();
                unsigned short pos = 0;
                Container* container;
                if (self->fromZoneList) {
                    container = GrottoChestList_Get(zoneContainers, elem->uniqueID);
                } else {
                    container = containers->GetContainerByID(elem->uniqueID, &pos);
                }
                if (container) {
                    if (container->lootType == 4) {
                        void* node = res->fieldTasks_[0x1b];
                        FieldTask_InitAcquireTreasureMap(node, 0);
                        AcquireTreasureMapTask_CreateMap(node, 1, 0, 0, 0);
                        AppendNodeToTail(taskQueue, (TailNode020469b4*)node);
                        done = 1;
                    } else if (container->lootType == LootType_Ambush) {
                        done = 1;
                        self->ambush = done;
                        self->monsterId = container->itemIDOrRank;
                    } else {
                        LootTextContext context;
                        context.allocator.ResetAllocatorPointer();
                        ItemTable_Construct(context.itemTable);
                        InitStruct0207cbe8((char*)&context);
                        char item[0x80] = {};
                        InitStruct0207cbe8((char*)&context);
                        context.containerItems = (ItemTable*)(zone + ContainerItemsOffset);
                        if (func_0207d538(&context, container->lootType, container->itemIDOrRank, item, 1)) {
#if defined(jpn)
                            sprintf(text, data_ov017_021d80b0, item);
#else
                            sprintf(text, "%s", item);
#endif
                            done = 1;
                        }
                    }
                }
            }
            if (!done) {
#if defined(jpn)
                sprintf(text, data_ov017_021d80b3);
#else
                sprintf(text, (char*)StandardStrings_Get(0x2d));
#endif
            }
        }
        ZoneChestRenderRecord* elem2 = (ZoneChestRenderRecord*)Zone3D_GetChest(zone, self->chestIndex);
        if (elem2) {
            LootableContainerManager* mgr2 = LootableContainerManager::GetMainInstance();
            unsigned short pos2 = 0;
            Container* chest;
            if (self->fromZoneList) {
                chest = GrottoChestList_Get(zoneContainers, elem2->uniqueID);
            } else {
                chest = mgr2->GetContainerByID(elem2->uniqueID, &pos2);
            }
            if (chest) {
                GameResources* res2 = GetGameResources();
                if (self->special) {
                    GameResources_PlaySpecialItemEffect(res2, &chest->position, 0);
                }
                int type = chest->lootType;
                if (type != 4) {
#if defined(jpn)
                    TextQueue_Push(textQueue, *(char**)((char*)messages + MessageBufferOffset), type == 2, chest->lootType == 2, 0);
#else
                    TextQueue_Push(textQueue, *(char**)((char*)messages + MessageBufferOffset), type == 2, chest->lootType == 2, 0, 0);
#endif
                    if (self->ambush) {
                        SePlayer_UnloadExtraArchiveA(&g_sePlayer);
                        SePlayer_LoadExtraArchiveA(&g_sePlayer, 0x15e, 0x15e);
                        DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, 0, 0);
                    } else if (chest->lootType != 0 && chest->itemIDOrRank != 0x5617) {
                        SePlayer_Play((SePlayer*)&g_sePlayer, 0xe, 0);
                    }
                }
                int id = chest->uniqueID;
                unsigned char* flags = (unsigned char*)Scenario_GetInstance();
                if (chest->containerType == 0) {
                    Scenario_SetFlag(flags, flags + 0x8c, id + 0x212, 1);
                    func_ov017_021cdb00(1, id, 1, -1);
                } else if (!self->fromZoneList) {
                    Scenario_SetFlag(flags, flags + 0x8c, id + 0x79e, 1);
                }
                chest->lock = 0;
                chest->lootType = 0;
            }
        }
        self->step = OpenChestStep_Finish;
    } else if (self->step == OpenChestStep_Finish) {
        if (self->special) {
            if (!GameResources_IsSpecialItemEffectPlaying(GetGameResources())) {
                GameObject* leader = gs->GetLeader();
                if (leader) {
                    GameObject_EnableControl(leader);
                }
                FieldTask_EndOpenChest(self);
            }
        } else if (self->ambush) {
            self->step = OpenChestStep_Ambush;
        } else {
            FieldTask_EndOpenChest(self);
        }
    } else if (self->step == OpenChestStep_Ambush) {
        WhistleTask* whistle = (WhistleTask*)res->fieldTasks_[0x2c];
        if (whistle->inList == 0) {
            ZoneChestRenderRecord* elem = (ZoneChestRenderRecord*)Zone3D_GetChest(zone, self->chestIndex);
            if (elem) {
                elem->state = ZoneChestState_Gone;  // the mimic takes its place
            }
            char text[0x78];
            text[0] = 0;
#if defined(jpn)
            const char** msgs = FieldTask_ambushMonsterNames;
            const unsigned char* ids = FieldTask_ambushMonsterIds;
#else
            const short* msgs = FieldTask_ambushMonsterNames;
            const unsigned char* ids = FieldTask_ambushMonsterIds;
#endif
            for (int i = 0; i < 3; i++) {
                unsigned char id = ids[i];
                if (id == self->monsterId) {
#if defined(jpn)
                    sprintf(text, data_ov017_021d7f9c[0], msgs[i]);
#else
                    MessageSystem_SetStringArgument((Obj02046574*)messages, 0, (char*)StandardStrings_Get(msgs[i]));
                    MessageSystem_FormatText(messages, 0xc, StandardStrings_Get(0x2a), text, 0xe3, 0, 1);
#endif
                }
            }
#if defined(jpn)
            TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1);
#else
            TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1, 1);
#endif
            FieldTask_InitWhistle(whistle);
            whistle->partyMember = opener->obj3D_.actorIndex_;
            whistle->silent = 1;
            whistle->monsterId = self->monsterId;
            InsertNodeAfterHead((List02046a3c*)taskQueue, (Node02046a3c*)whistle);
        }
        FieldTask_EndOpenChest(self);
    }
}
