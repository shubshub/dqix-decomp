#include "Grotto/Main/TreasureMapDataStructs.h"
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"
#include <asmhacks.h>

#ifdef jpn

#define _Z18LoadFileIntoMemoryPKcPvPj func_02076224
#define _Z13GetFileInNarcPKvPKcPS0_Pjj func_02076378

#define data_020f1ae4 data_020f1c5c
#define data_020f1af8 data_020f1c70
#endif

extern "C"
{
    void func_020a1df8(unsigned int);
    void func_020a1e54(unsigned int);

    void Font_EncodeText(void*, char* buffer, int);

    const char* _Z19StandardStrings_Geti(int);

    int _Z21GameState_GetLanguageP14Struct0200fb08(GameState*);
}

#define BINARY_READ_AND_ADVANCE(buffer, offset, dst, len) \
    (VectorizedInvertedMemcpy((buffer) + (offset), (dst), (len)), offset += (len))

#define TMAPLANGDATA_READ(offset, into, len) \
    BINARY_READ_AND_ADVANCE(GameState::GetInstance()->GetTreasureMapLanguageData(), offset, into, len)

void DetailedTreasureMapData::LoadTreasures()
{
    if (GameState::GetInstance()->GetTreasureMapLanguageData() == NULL)
        return;

    TreasureMapLanguageDataOffsets* offsets = GetGameResources()->pTMapLanguageOffsets;
    unsigned int offset;
    bool foundBoss = false;

    if (mapType_ == TreasureMapType_Regular)
    {
        if (treasureItemIDs_[0] != 0 && treasureItemIDs_[1] != 0 && treasureItemIDs_[2] != 0)
            return;
        offset = offsets->grottoBossDrops;
        do
        {
            unsigned char bossIndex;
            unsigned short regularID;
            unsigned int innerOffset = offset;
            TMAPLANGDATA_READ(innerOffset, &bossIndex, 1);
            TMAPLANGDATA_READ(innerOffset, &regularID, 2);
            if (regularID == regular_.bossMonsterID_)
            {
                rand();
                foundBoss = true;
                offset = innerOffset;
                break;
            }
            else
                offset += 12;
        } while (offset < offsets->legacyBossDrops);
    }
    else
    {
        offset = offsets->legacyBossDrops;
        do
        {
            unsigned short legacyID;
            TMAPLANGDATA_READ(offset, &legacyID, 2);
            if (legacyID == legacy_.bossMonsterID_)
            {
                foundBoss = true;
                offset += (legacy_.stats_.dropListIndex - 1) * 9;
                break;
            }
            else
                offset += 90;
        } while (offset < offsets->legacyBossData);
    }

    if (foundBoss)
    {
        for (int i = 0; i < 3; i++)
        {
            TMAPLANGDATA_READ(offset, &treasureItemIDs_[i], 2);
            TMAPLANGDATA_READ(offset, &treasureDropRates_[i], 1);
        }
    }
}
