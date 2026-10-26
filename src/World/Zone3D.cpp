#include "World/ZoneResourceInitialization.h"
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "NitroSDK/Filesystem/FileAccessor.h"
#include "NitroSDK/Filesystem/LowNitroHandle.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
#include "NitroSDK/NSBXX/NSBXX.h"


extern "C"
{
    void* _Z22GameState_GetZoneTablePv(GameState*);

    void* func_02053c6c(void*);
    void _Z25RunBufferedStream0205e104iiP12StreamHeaderi(const char*, SafeAllocator*, const void*, unsigned int);

    void* _Z16VramState_RewindP11Foo0207df50(void*);
    void _Z17VramState_RestorePc(void*);
    void _Z14VramState_SavePc(void*);

    void* _Z24GetData02108f0c_0208a9b4v();
    void _Z21GrottoChestList_ClearP29ClearThreeWords02094d00Struct(void*);
    Zone3D_StructPtr_8* _Z19ZoneTable_FindEntryP11SearchTablei(void*, unsigned short id);

    void HaltSystem();
    void _Z14ItemTable_InitPv(void*);

    void _Z13Zone3D_UnloadPvi(Zone3D*, bool);

    bool _Z24ZoneId_IsMainGrottoFloori(int id);
    bool _Z24ZoneId_IsGrottoBossFloori(int id);

}

extern char data_020ef0f0[];
extern char data_020ef106[];
extern char data_020ef116[];
extern char data_020ef11f[];
extern char data_020ef12f[];
extern char data_020ef13a[];
extern char data_020ef13e[];
extern char data_020ef145[];
extern char data_020ef14b[];
extern char data_020ef150[];
extern char data_020ef156[];
extern char data_020ef166[];
extern char data_020ef176[];
extern char data_020ef182[];
extern char data_020ef18e[];
extern char data_020ef199[];
extern char data_020ef19f[];
extern char data_020ef1a9[];
extern char data_020ef1b3[];
extern char data_020ef1bd[];
extern char data_020ef1c7[];
extern char data_020ef1d6[];
extern char data_020ef1de[];
extern char data_020ef1e6[];
extern char data_020ef1e8[];
extern char data_020ef1ee[];
extern char data_020ef1f3[];
extern char data_020ef1f8[];
extern char data_020ef1fe[];
extern char data_020ef204[];
extern char ZoneChest_itemIconPathFormat[];
extern char data_020ef222[];
extern char data_020ef22c[];

// The grotto floor's tile map: GrottoTileMapRecords allocated and reset on entering a grotto floor
enum { kGrottoTileMapSize = 256 };

// Main, originally Zone3D::SwitchZone_0201383c (USA 0x0201383c, EUR 0x0201384c, JPN 0x02013604)
void Zone3D::SwitchZone(unsigned short newID, int)
{
    GameState* gameState = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    void* zoneTable = _Z22GameState_GetZoneTablePv(gameState);
    (void)GetGameResources();
    GameObject* player = gameState->GetLeader();

    pAllocator_68_ = pAllocator_4c_;
    pAllocator_68_->Reset();

    _Z16VramState_RewindP11Foo0207df50(vramState_);
    _Z13Zone3D_UnloadPvi(this, true);

    previousZoneID_ = currentZoneID_;
    currentZoneID_ = newID;

    textureImageMemory_ = 0;
    texturePaletteMemory_ = 0;
    unknown_424_ = 1;
    firstBMDJStruct_41c_ = 0;
    firstModel_418_ = NULL;
    numLootables_ = 0;
    numChests_ = 0;
    terrainElementCount_ = 0;
    unknown_474_ = 0;
    terrainElementCount_ = 0;
    unknown_42c_ = 0;

    mapListLoadHandle_ = -1;
    unknown_434_ = -1;
    mapAMBLLoadHandle_ = -1;
    mapAMDJLoadHandle_ = -1;
    atsAMBLLoadHandle_ = -1;

    lootables_ = 0;
    chests_ = 0;
    unknown_834_ = 0;
    unknown_2820_ = 0;

    substruct_6c_.Reset();

    substruct_c_.unknown_0_[0] = 0;
    substruct_c_.unknown_a_[0] = 0;
    substruct_c_.unknown_1a_[0] = 0;
    substruct_c_.unknown_2a_ = 0x7fff;
    substruct_c_.unknown_2c_ = 0;
    substruct_c_.unknown_30_ = 10;
    substruct_c_.unknown_34_ = 0;
    substruct_c_.unknown_38_ = 0;
    substruct_c_.unknown_3c_ = 0;

    atmosphericEffects_.Reset();
    lighting_.Reset();
    _Z14ItemTable_InitPv(&containerItems_[0]);

    pUnknownStruct_8_ = _Z19ZoneTable_FindEntryP11SearchTablei(zoneTable, newID);
    unknown_4_ = pUnknownStruct_8_->unknown_2_;
    if (pUnknownStruct_8_->unknown_c_low_ == 0)
    {
        GameObject* protagonist = gameState->GetProtagonist();
        if (protagonist != NULL)
        {
            void* characterData = _Z24GetFieldAt0x150_02053c6cPh(protagonist);
            if (characterData != NULL)
                *(unsigned short*)((int)characterData + 0x566) = pUnknownStruct_8_->unknown_0_;
        }
    }

    *(bool*)((int)_Z24GetData02108f0c_0208a9b4v() + 0x9c) = pUnknownStruct_8_->unknown_c_high_ != 0;
    _Z21GrottoChestList_ClearP29ClearThreeWords02094d00Struct(&grottoChestList_[0]);

    grottoTileMapData_420_ = NULL;

    if (_Z24ZoneId_IsMainGrottoFloori(previousZoneID_))
    {
        grotto_.floorMap_.Clear();
    }

    if (_Z24ZoneId_IsMainGrottoFloori(newID))
    {
        isInMainGrottoFloor_23b8_ = true;
        currentGrottoFloor_23ba_ = newID % 20;
        copyOfCurrentGrottoFloor_23bb_ = currentGrottoFloor_23ba_;
        int width = grotto_.CalculateAndStoreFloorWidth(currentGrottoFloor_23ba_);
        int height = grotto_.CalculateAndStoreFloorHeight(currentGrottoFloor_23ba_);

        grottoTileMapData_420_ = (GrottoTileMapRecord*)pAllocator_68_->Allocate(sizeof(GrottoTileMapRecord) * kGrottoTileMapSize);
        for (int i = 0; i < kGrottoTileMapSize; i++)
        {
            GrottoTileMapRecord_Reset(&grottoTileMapData_420_[i]);
        }
        grotto_.ClearGenerator(false);
        grotto_.AllocateGenerator(pAllocator_68_, false);
        grotto_.CalculateFloorMap(currentGrottoFloor_23ba_, width, height, NULL);
    }
    else
    {
        if (currentGrottoFloor_23ba_ != -1)
        {
            copyOfCurrentGrottoFloor_23bb_ = currentGrottoFloor_23ba_;
            position_23c0_ = player->obj3D_.position_;
            unknown_23cc_ = *(short*)((int)player + 0xae);
        }
        isInMainGrottoFloor_23b8_ = false;
        currentGrottoFloor_23ba_ = -1;
    }

    mapListLoadHandle_ = loader->QueueLoadFile(data_020ef0f0, NULL);
}

// USA: func_02013b54
Vector3i &Vector3i::operator=(const Vector3i &arg0) {
    x = arg0.x;
    y = arg0.y;
    z = arg0.z;
    return *this;
}
