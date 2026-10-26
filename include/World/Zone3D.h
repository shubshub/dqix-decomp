#pragma once

#include "Grotto/Main/ActiveGrottoClass.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Vector.h"
#include "Graphics/Model3D.h"
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/LightingInfo.h"
#include "Grotto/Main/TileFeatures.h"
#include "World/ZoneLootableRecord.h"
#include "World/BmdjScriptNode.h"
#include "ZoneFeatures.h"

struct Zone3D_StructPtr_8
{
    unsigned short unknown_0_;
    unsigned short unknown_2_ : 15;
    char unk_4;
     // e.g. "F02" or "B01M13", corresponding to file data/map/%s.ambl and similar
    char mapShortName_[7];
    unsigned char unknown_c_low_ : 4;
    unsigned char unknown_c_high_ : 1;
};

// ZoneChestRenderRecord::state. A chest opens through Opening .. SettlingLid (ZoneChest_UpdateOpening, every frame
// from Zone3D_UpdateChests), seen in-game in that order opening the Angel Falls well's blue chest.
enum ZoneChestState {
    ZoneChestState_Gone = 0,        // not drawn: a mimic took its place (FieldTask_OpenChest's Ambush step)
    ZoneChestState_Closed = 1,      // can be opened (only these: the interaction finder, GameResources_StartOpenChest)
    ZoneChestState_Opening = 2,     // ZoneChest_StartOpening: next, queue the contents' icon (gold or the item's)
    ZoneChestState_LoadingIcon = 4, // waiting for the icon file
    ZoneChestState_LiftingLid = 5,  // ZoneChest_LiftLid until it's done
    ZoneChestState_ShowingIcon = 6, // the icon above the chest, 500 ms
    ZoneChestState_SettlingLid = 7, // ZoneChest_SettleLid until it's done
    ZoneChestState_Open = 8,        // its container's opened flag is set (Zone3D_SetUpContainers), or it just opened
};

// ZoneChestRenderRecord::kind. Zone3D_DrawChests draws Red in its first pass, the others in the second.
enum ZoneChestKind {
    ZoneChestKind_Red = 0,      // a LootableContainerType_RedChest container (Zone3D_SetUpContainers)
    ZoneChestKind_Blue = 1,     // a LootableContainerType_BlueChest container
    ZoneChestKind_Grotto = 2,   // a grotto floor's chest (func_0201afd0); its contents are in grottoChestList_
};

// ZoneChestRenderRecord::lidAngle values (Zone3D_DrawChests turns the lid about x by it)
enum ZoneChestLid {
    ZoneChestLid_Closed = 0x647a,
    ZoneChestLid_Lifted = 0x4800,   // ZoneChest_LiftLid ends here; ZoneChest_SettleLid goes on to Open
    ZoneChestLid_Open = 0x4000,
};

struct ZoneChestRenderRecord
{
    Vector3i position;
    short angleY;                   // which way it faces (its container's angle)
    short lidAngle;                 // ZoneChestLid
    unsigned short counter;         // into the current step: frames (the lid), milliseconds (the icon)
    short iconTask;                 // the background load of the contents' icon file (-1: none)
    signed char opener;             // the actor opening it (ZoneChest_StartOpening; -1: none); only the
                                    // player's own opening shows the icon
    unsigned char pad15;            // nothing reads or writes it (the sources; live, opening a chest)
    unsigned char state;            // ZoneChestState
    unsigned char kind;             // ZoneChestKind
    unsigned char special;          // 1: closes again once opened (ZoneChest_SettleLid); Zone3D_SetUpContainers sets it on
                                    // blue chests while LinkSession_GetInstance's flag is set
    unsigned char iconRise;         // pixels the contents' icon has risen above the chest (up to 10)
    short recordIndex;
    unsigned short uniqueID;
    unsigned char pad1e[2];         // nothing reads or writes it (the sources; live, opening a chest)
    Foo02048004* icon;              // the contents' icon sprite while it shows (ZoneChest_UpdateOpening)
};

struct ZoneSavedActorState
{
    Vector3i position;
    int rotationY;
    short nodeId;
    unsigned short zoneId;
    unsigned char active;
};

// sizeof == 0x2824, as seen in the dynamic allocation of one
// of these in func_ov001_02163b14 (usa).
// In JPN version, sizeof == 0x2864.
// Represents a 3D zone such as a town, field or grotto floor,
// but also a battlefield.
class Zone3D
{
public:
    struct Model3DListNode
    {
        Model3D model_;
        const char* filename_;
        Model3DListNode* pNext_;
    };

    unsigned short currentZoneID_;
    unsigned short previousZoneID_;

    short unknown_4_;
    char unk_6[2];
    Zone3D_StructPtr_8* pUnknownStruct_8_;
    struct
    {
        char buffer1[10];
        char buffer2[16];
        char buffer3[16];
#if defined(jpn)
        char jpbuffer[0x20];
#endif
        short unknown_2a_;
        short unknown_2c_;
        char pad_2e[2];
        int unknown_30_;
        short unknown_34_;
        char pad_36[2];
        int unknown_38_;
        int unknown_3c_;
    } substruct_c_;
    SafeAllocator* pAllocator_4c_;
    void* vramState_;               // the zone's VramState: VramState_Rewind on zone change (Zone3D.cpp), the state an icon
                                    // is loaded against (ZoneChest_UpdateOpening); the nsbtx processor reads it
    SafeAllocator internalAllocator_;
    SafeAllocator* pAllocator_68_;

    // Populated from BMBL and BPOS scripts, among other things holds data
    // about warps and placement of stairs/chests in grottos
    ZoneFeatures substruct_6c_;
    AtmosphericEffectSet atmosphericEffects_;
    // populated by BATS files.
    // If you remove it, lighting goes weird outdoors, but I don't see any 
    // change in towns / battlefields
    LightingInfo lighting_;
    Model3DListNode* firstModel_418_;
    BmdjScriptNode* firstBMDJStruct_41c_;
    GrottoTileMapRecord* grottoTileMapData_420_;
    int unknown_424_;
    char unk_428[4];
    unsigned char unknown_42c_;
    char unk_42d[3];
    int mapListLoadHandle_; // for loading data/map/maplist9.bin
    int unknown_434_;
    int mapAMBLLoadHandle_; // loads things like data/map/Z02M01.ambl
    int mapAMDJLoadHandle_;
    int atsAMBLLoadHandle_; // data/map/ats_%c.ambl

    char unk_444[0x474 - 0x444];

    short unknown_474_;
    unsigned char numLootables_;
    // this seems to include blue and red chests
    unsigned char numChests_;
    ZoneLootableRecord* lootables_;
    ZoneChestRenderRecord* chests_;

    Foo02048004* lootableTemplates_[6];
    Model3D models_498_[2];
    int chestPaletteOffsets_5f0_[4];
    Foo02048004 lootIcons_[4];      // the icon of what a player found, by the player's index: a chest's contents
                                    // (ZoneChest_UpdateOpening, by opener), a pot's item (SearchPotTask_WaitSprite)
    int lootIconAlpha_;             // 0x1f when a chest's icon loads, counted down while its lid settles, written to
                                    // the icon's alpha (ZoneChest_UpdateOpening); Zone3D_ClearChestIconsByOpener zeroes it
    BmdjSceneElement** terrainElements_;
    int unknown_828_;

    int terrainElementCount_;

    char unk_830[4];
    char unknown_834_;
    char unk_835[3];

    int textureImageMemory_;
    int texturePaletteMemory_;

    char unk_840[0x23b8 - 0x840];


    // 0x20 extra bytes unaccounted for in JPN version
    bool isInMainGrottoFloor_23b8_;
    char unknown_23b9_;
    char currentGrottoFloor_23ba_;
    char copyOfCurrentGrottoFloor_23bb_;
    char unk_23bc[4];
    // when you change zones such that you are no longer in a main
    // grotto floor (e.g. you go to boss zone, leave at the top or cast evac)
    // this stores your character position right before you left
    Vector3i position_23c0_;
    unsigned short unknown_23cc_;
    char unk_23ce[0x23ec - 0x23ce];
    ActiveGrottoClass grotto_; // offset 23ec in USA. this is 0x20 bytes larger in JPN
    char unk_2664[0x2724 - 0x2664];
    char grottoChestList_[0xc];     // a grotto floor's chest contents (func_0201afd0), read by GrottoChestList_Get
    char unk_2730[0x274c - 0x2730];
    int chestRenderingEnabled_274c_;
    char unknown_2750_[0x2754 - 0x2750];
    char containerItems_[0x18];     // item data for every item the zone's containers can give (Zone3D_SetUpContainers
                                    // loads it on entry; the pot search reads an item's name from it)
    union {
        char unk_276c[0x2820 - 0x276c];
        struct {
            char unknown_276c_[8];
            ZoneSavedActorState savedActor_;
            char unknown_278c_[0x27d8 - 0x278c];
            unsigned short pendingType2Mask_;
            unsigned short pendingLootableMask_;
            char unknown_27dc_[0x281e - 0x27dc];
            unsigned char unknown_281e_;
            char unknown_281f_;
        };
    };
    char unknown_2820_;
    char unk_2821[3];
public:
    // usa: _ZN6Zone3D10SwitchZoneEti
    void SwitchZone(unsigned short newID, int);

    inline ActiveGrottoClass* GetActiveGrotto() { return &grotto_; }

    inline ZoneSavedActorState* inline_020a6728() { return &savedActor_; }

    // usa: _ZN6Zone3D13UnpackMapAMDJEv
    int UnpackMapAMDJ();

    int UnpackMapAMBL();
    int UnpackATS_AMBL();
    int ProcessBMBLFile(const void* source, unsigned int sourceLength);
    int ProcessBPOSFile(const void* source, unsigned int sourceLength);
    int ProcessBATSFile(const void* source, unsigned int sourceLength);
    bool ProcessNSBTXFile(const void* source, unsigned int sourceLength, const char* name);

    void QueueLoadMapAMDJ();
    void QueueLoadMapAMBL();
};

#if defined(jpn)
typedef char ZoneSavedActorStateSizeCheck[sizeof(ZoneSavedActorState) == 0x18 ? 1 : -1];
typedef char Zone3DSavedActorOffsetCheck[offsetof(Zone3D, savedActor_) == 0x27b4 ? 1 : -1];
typedef char Zone3DNodeHeadOffsetCheck[offsetof(Zone3D, firstBMDJStruct_41c_) == 0x43c ? 1 : -1];
typedef char Zone3DTerrainArrayOffsetCheck[offsetof(Zone3D, terrainElements_) == 0x844 ? 1 : -1];
typedef char Zone3DLootIconsOffsetCheck[offsetof(Zone3D, lootIcons_) == 0x620 ? 1 : -1];
typedef char Zone3DStorageSizeCheck[sizeof(Zone3D) == 0x2864 ? 1 : -1];
#else
typedef char ZoneSavedActorStateSizeCheck[sizeof(ZoneSavedActorState) == 0x18 ? 1 : -1];
typedef char Zone3DSavedActorOffsetCheck[offsetof(Zone3D, savedActor_) == 0x2774 ? 1 : -1];
typedef char Zone3DNodeHeadOffsetCheck[offsetof(Zone3D, firstBMDJStruct_41c_) == 0x41c ? 1 : -1];
typedef char Zone3DTerrainArrayOffsetCheck[offsetof(Zone3D, terrainElements_) == 0x824 ? 1 : -1];
typedef char Zone3DLootIconsOffsetCheck[offsetof(Zone3D, lootIcons_) == 0x600 ? 1 : -1];
typedef char Zone3DStorageSizeCheck[sizeof(Zone3D) == 0x2824 ? 1 : -1];
#endif
