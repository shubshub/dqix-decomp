#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/LootableContainer.h>
#include <Filesystem/BackgroundLoader.h>
#include <Resource/GameResources.h>
#include <World/Zone3D.h>

struct Foo02048004;
struct StructAt020473c8;
struct GetElement02094d5cList;
struct Holder020159c0;
struct ItemTable;
struct StructDE234_020de234;
struct HeadNode02046b24;
struct State0207dfc8;
struct Vec3copy0202ec84;

// LootableContainerManager::Container's first fields (this file's copy)
struct LootableContainer02015ef4 {
    unsigned short uniqueID;
    short itemIDOrRank;             // the item (or gold amount) it holds
    unsigned short lock : 2;
    unsigned short lootType : 2;
    unsigned short containerType : 3;
};

// One record of the item table (ItemTable_Find), as CharacterModel_Load's copy names it
struct ItemRecord {
    void* model_;
    int unk_4;
    int unk_8;
    int unk_c;
    unsigned int maleFileNumber_ : 10;
    unsigned int femaleFileNumber_ : 10;
    unsigned int letter_ : 8;       // the icon file's letter (/data/ani/d_%c%03d.spr)
    unsigned int unk_10_28 : 4;
    short unk_14;
    short unk_16;
    short itemId_;
};

// ZoneChestRenderRecord (this file's copy)
struct ChestRecord02015ef4 {
    Vector3i position;
    short angleY;
    unsigned short lidAngle;
    unsigned short counter;
    short iconTask;
    signed char opener;
    char pad15;
    unsigned char state;            // ZoneChestState
    unsigned char kind;
    unsigned char special;
    unsigned char iconRise;
    short recordIndex;
    unsigned short uniqueID;
    char pad1e[2];
    Foo02048004* icon;
};

void SprSprite_Unload(Foo02048004*);
extern "C" int ZoneChest_LiftLid(ChestRecord02015ef4*);
extern "C" int ZoneChest_SettleLid(ChestRecord02015ef4*);
void* GrottoChestList_Get(GetElement02094d5cList*, int);
void Zone3D_ClearChestIconsByOpener(Holder020159c0*, int);
void* ItemTable_Find(ItemTable*, int);
int ItemRecord_GetFileNumber(StructDE234_020de234*, int);
extern "C" int sprintf(char*, const char*, ...);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void SprSprite_Init(void*);
void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
void VramState_Restore(char*);
void SprSprite_LoadFile(void*, int, int, int);
void VramState_Save(char*);
void Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);

struct IconPath02015ef4 {
    char text[0x20];
};
extern IconPath02015ef4 ZoneChest_goldIconPath;   // "/data/ani/d_i127.spr", the gold bag
extern char ZoneChest_itemIconPathFormat[];   // "/data/ani/d_%c%03d.spr"

// Main, originally func_02015ef4 (USA 0x02015ef4, EUR 0x02015f04, JPN 0x02015cc0)
extern "C" ARM int ZoneChest_UpdateOpening(Zone3D* self, int index) {
    GameState* gameState = GameState::GetInstance();
    ChestRecord02015ef4* chest = &reinterpret_cast<ChestRecord02015ef4*>(self->chests_)[index];
    LootableContainerManager* containers = LootableContainerManager::GetMainInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int protagonistId = gameState->GetProtagonist()->obj3D_.actorIndex_;
    int playerId = gameState->GetUnknownGameObject()->obj3D_.actorIndex_;
    int visible = 0;
    self->unk_23bc[1] = 0;
    if (chest->state == ZoneChestState_Gone || chest->state == ZoneChestState_Open) {
        if (chest->icon) {
            SprSprite_Unload((Foo02048004*)chest->icon);
            chest->icon = 0;
        }
        return -1;
    }
    unsigned int delta = gameState->GetEffectiveDeltaTime();
    int tick = gameState->GetTickCount() + 1;
    if (chest->state == ZoneChestState_Opening) {
        self->unk_23bc[1] = 1;
        ZoneChest_LiftLid(chest);
        LootableContainer02015ef4* container = 0;
        if (chest->kind == ZoneChestKind_Red || chest->kind == ZoneChestKind_Blue) {
            container = (LootableContainer02015ef4*)containers->GetContainerByID(chest->uniqueID, 0);
        } else if (chest->kind == ZoneChestKind_Grotto) {
            container = (LootableContainer02015ef4*)GrottoChestList_Get((GetElement02094d5cList*)self->grottoChestList_, chest->uniqueID);
        }
        if (!container) {
            chest->state = ZoneChestState_Open;
            return 0;
        }
        Zone3D_ClearChestIconsByOpener((Holder020159c0*)self, (signed char)protagonistId);
        if (chest->opener == playerId) {
            if (container->lootType == LootType_Gold) {
                IconPath02015ef4 goldIconPath = ZoneChest_goldIconPath;
                chest->iconTask = loader->QueueLoadFile(goldIconPath.text, 0);
                chest->state = ZoneChestState_LoadingIcon;
                return 0;
            } else if (container->lootType == LootType_Item) {
                ItemRecord* item = (ItemRecord*)ItemTable_Find((ItemTable*)self->containerItems_, container->itemIDOrRank);
                if (item && item->itemId_ != 0x5617) {
                    int fileNumber = ItemRecord_GetFileNumber((StructDE234_020de234*)item, 0);
                    char path[0x50];
                    sprintf(path, ZoneChest_itemIconPathFormat, (signed char)item->letter_, fileNumber);
                    chest->iconTask = loader->QueueLoadFile(path, 0);
                    chest->state = ZoneChestState_LoadingIcon;
                    return 0;
                }
            }
        }
        chest->icon = 0;
        chest->state = ZoneChestState_LiftingLid;
    } else if (chest->state == ZoneChestState_LoadingIcon) {
        self->unk_23bc[1] = 1;
        ZoneChest_LiftLid(chest);
        if (loader->GetTaskStatus(chest->iconTask) == 0) return 0;
        void* file = 0;
        unsigned int size = 0;
        loader->GetLoadedFileByID(chest->iconTask, &file, &size);
        GameResources* resources = GetGameResources();
        HeadNode02046b24** taskQueue = (HeadNode02046b24**)resources->fieldTaskQueue_;   // the field task queue
        if (file && GetHeadNodeIdOrMinusOne(taskQueue) != 4) {
            Foo02048004* slot = &self->lootIcons_[chest->opener];
            chest->icon = slot;
            SprSprite_Init(slot);
            chest->icon->bit2 = 1;
            char vramState[0x70];
            VramState_CopyCurrentTo((State0207dfc8*)self->vramState_, (State0207dfc8*)vramState);
            VramState_Restore(vramState);
            SprSprite_LoadFile(chest->icon, (int)file, size, (int)self->pAllocator_68_);
            VramState_Save(vramState);
            self->lootIconAlpha_ = 0x1f;
            chest->iconRise = 0;
        } else {
            chest->icon = 0;
        }
        loader->RemoveTask(chest->iconTask);
        chest->iconTask = -1;
        chest->state = ZoneChestState_LiftingLid;
    } else if (chest->state == ZoneChestState_LiftingLid) {
        self->unk_23bc[1] = 1;
        if (chest->counter > 0xd) visible = 1;
        if (ZoneChest_LiftLid(chest)) {
            chest->counter = 0;
            chest->state = ZoneChestState_ShowingIcon;
        }
    } else if (chest->state == ZoneChestState_ShowingIcon) {
        self->unk_23bc[1] = 1;
        visible = 1;
        chest->counter += delta;
        if (chest->counter > 500) {
            chest->state = ZoneChestState_SettlingLid;
            chest->counter = 0;
        }
    } else if (chest->state == ZoneChestState_SettlingLid) {
        self->unk_23bc[1] = 1;
        visible = 1;
        if (chest->special == 1) {
            if (ZoneChest_SettleLid(chest)) {
                chest->lidAngle = ZoneChestLid_Closed;
                chest->state = ZoneChestState_Closed;
                if (chest->icon) {
                    SprSprite_Unload((Foo02048004*)chest->icon);
                    chest->icon = 0;
                }
            }
        } else if (ZoneChest_SettleLid(chest)) {
            chest->lidAngle = ZoneChestLid_Open;
            chest->state = ZoneChestState_Open;
            if (chest->icon) {
                SprSprite_Unload((Foo02048004*)chest->icon);
                chest->icon = 0;
            }
        }
    }
    if (static_cast<unsigned char*>(GetGameResources()->fieldTasks_[0x22])[3] != 0) visible = 0;
    if (chest->icon && visible) {
        self->unk_23bc[1] = 1;
        int screenX = 0;
        int screenY = 0;
        void* camera = gameState->GetCamera();
        if (camera) Camera_WorldToScreen(camera, (Vec3copy0202ec84*)chest, &screenX, &screenY);
        screenX -= 12;
        screenY -= 0x28;
        if (chest->iconRise < 10) chest->iconRise++;
        if (chest->state == ZoneChestState_SettlingLid && chest->icon) {
            if (tick < self->lootIconAlpha_) {
                self->lootIconAlpha_ -= tick;
            } else {
                self->lootIconAlpha_ = 0;
                chest->icon = 0;
                return 0;
            }
        }
        if (screenX >= -24 && screenX < 256 && screenY >= -24 && screenY < 192) {
            int timer = self->lootIconAlpha_;
            chest->icon->alpha = timer;
            int iconX = screenX;
            int iconY = screenY - chest->iconRise;
            Foo02048004* icon = chest->icon;
            icon->position.x = iconX << 12;
            icon->position.y = iconY << 12;
            icon->position.z = 0;
            RenderFlaggedIndexedEntry((StructAt020473c8*)chest->icon, 1);
        }
    }
    return 0;
}
