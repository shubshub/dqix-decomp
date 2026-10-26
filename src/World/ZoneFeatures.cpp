#include "World/ZoneWarpScript.h"
#include "World/ZoneFeatures.h"
#include "World/Zone3D.h"
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"

extern Script::OpcodeLookupEntry data_020ef388[];

extern "C"
{
    extern "C" void* GameState_GetZoneTable(GameState*);
    void _ZN15Struct_020134e017Struct_0201cb60_313func_0201ce10Ev(void*);

    Matrix4x3 _Z15RotationMatrixYi(fix32_t);

    fix32_t _Z22fix32ReduceAngle0To2Pii(fix32_t);

    extern "C" unsigned short* ZoneTable_FindEntryByMapCode(void*, const char*);

}

extern "C" int WarpScript_AllocateOpcode64Entries(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode64Entries(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

extern "C" int WarpScript_CreateOpcode64Entry(Script::Parameter* params, int numParams)
{
    const char* var0;
    const char* var1;
    int var2 = params[0].ToInt();
    Vector3fix var3;
    Script::Parameter* var4 = params[1].ToVec3fix(&var3);
    params = var4 + 1;
    const char* var5 = var4->ToString();
    var0 = NULL;
    var1 = NULL;

    if (numParams >= 6)
    {
        var0 = params->ToString();
        params++;
    }
    if (numParams >= 7)
    {
        var1 = params->ToString();
        params++;
    }

    if (var5 == NULL)
        return 0;

    ZoneFeatures::Opcode64Entry entry;
    entry.unk_0 = var2;
    entry.vector_4.vec = var3;
    strcpy(entry.string_10, var5);
    if (var0 == NULL)
        entry.string_20[0] = '\0';
    else
        strcpy(entry.string_20, var0);
    if (var1 == NULL)
        entry.string_30[0] = '\0';
    else
        strcpy(entry.string_30, var1);

    data_020fdc20.warp->CreateOpcode64Entry(entry);
    return 1;
}

extern "C" int func_0201c8a8(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->func_0201e288(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

extern "C" int func_0201c8d0(Script::Parameter* params, int numParams)
{
    TileFeaturePlacementData var0;
    var0.unknown_0_ = (params++)->ToInt();
    strcpy(var0.tilename, (params++)->ToString());

    for (int i = 0; i < 9; i++)
        var0.directionBitmasks[i] = (params++)->ToInt();

    data_020fdc20.warp->func_0201e3c4(var0);
    return 1;
}

extern "C" int ZoneFeaturesScript_AllocateOpcode66Entries(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode66Entries(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

extern "C" int ZoneFeaturesScript_AllocateExits(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateExits(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

void ZoneFeatures::Opcode68Entry::func_0201ce10()
{
    unk_0 = 0;
    unk_1c = -1;
    unk_50 = 0;
    unk_52 = 0;
    unk_54 = 0;
    unk_64[0] = 0;
    unk_64[1] = 0;
    unk_58[0] = 0;
    unk_58[1] = 0;
    unk_58[2] = 0;
    unk_20[0].x = 0;
    unk_20[0].y = 0;
    unk_20[0].z = 0;
    unk_20[1].x = 0;
    unk_20[1].y = 0;
    unk_20[1].z = 0;
    unk_20[2].x = 0;
    unk_20[2].y = 0;
    unk_20[2].z = 0;
    unk_20[3].x = 0;
    unk_20[3].y = 0;
    unk_20[3].z = 0;
    unk_6c = -1;
}

extern "C" int ZoneFeaturesScript_AllocateEntries(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode6aEntries(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

extern "C" int func_0201d044(Script::Parameter* params, int numParams)
{
    Script::Parameter* paramsStart = params;
    ZoneFeatures::Opcode6aEntry entry;
    entry.func_0201d424();
    int var2 = (params++)->ToInt();
    entry.maybeType = var2;
    bool var3 = false;
    if (entry.maybeType >= 10)
    {
        entry.maybeType -= 10;
        var3 = true;
    }

    Vector3fix var4;
    params = params->ToVec3fix(&var4);
    entry.unk_8.vec = var4;
    params = params->ToVec3fix(&var4);
    entry.unk_14.vec = var4;

    if (var3)
    {
        fix32_t angle = 4096.0f * (params++)->ToFloat();
        entry.unk_22 = _Z22fix32ReduceAngle0To2Pii(angle);
    }
    entry.angle = 4096.0f * (params++)->ToFloat();

    fix32_t var6 = entry.unk_14.vec.x / 2;
    fix32_t var7 = entry.unk_14.vec.z / 2;
    fix32_t var8 = FIX32_MULTIPLY(var6, var6);
    fix32_t var9 = FIX32_MULTIPLY(var7, var7);
    entry.unk_24 = var9;
    entry.unk_24 = var8 + var9;

    if (entry.maybeType == 2)
    {
        entry.unk_2c.type2.nodeId = (params++)->ToInt();
        entry.unk_2c.type2.elementId = (params++)->ToInt();
        entry.unk_2c.type2.flags = (params++)->ToInt();
    }
    else if (entry.maybeType == 3)
    {
        entry.unk_2c.type3.unk_0 = (params++)->ToInt();
    }
    else if (entry.maybeType == 4)
    {
        int arg = (params++)->ToInt();
        entry.unk_2c.type4.unk_1 = -1;
        entry.unk_2c.type4.unk_0 = arg;
        entry.unk_2c.type4.unk_0_high = 0;
        switch (entry.unk_2c.type4.unk_0)
        {
        case 0:
            entry.unk_2c.type4.vector_4.vec3.vec.y = 4096.0f * (params++)->ToFloat();
            entry.unk_2c.type4.vector_4.vec3.vec.z = 4096.0f * (params++)->ToFloat();
            break;
        case 1:
            params = params->ToVec3fix(&var4);
            entry.unk_2c.type4.vector_4.vec3.vec = var4;
            break;
        case 2:
        case 3:
            params = params->ToVec3fix(&var4);
            entry.unk_2c.type4.vector_4.vec3.vec = var4;
            break;
        case 4:
        case 5:
        {
            Vector3fix vecB;
            Vector3fix vecA;
            params = params->ToVec3fix(&vecB);
            params = params->ToVec3fix(&vecA);
            MaybeVector4fix difference;
            Vector3fix_Subtract(&vecA, &vecB, &difference.vec3.vec);
            fix32_t distance = Vector3fix_Length(&difference.vec3.vec);
            Vector3fix_Normalize(&difference.vec3.vec, &difference.vec3.vec);
            difference.w = Vector3fix_InnerProduct(&difference.vec3.vec, &vecB);
            Vector3fix var15  = { 0, 0, 0 };
            if (entry.unk_2c.type4.unk_0 == 4)
            {
                var15.x = 4096.0f * (params++)->ToFloat();
            }
            var15.y = 4096.0f * (params++)->ToFloat();
            var15.z = 4096.0f * (params++)->ToFloat();
            Vector3fix var16;
            params = params->ToVec3fix(&var16);
            entry.unk_2c.type4.vector_4.CopyFrom(difference);
            entry.unk_2c.type4.distance_14 = distance;
            entry.unk_2c.type4.vector_18 = var15;
            entry.unk_2c.type4.vector_24 = var16;
            break;
        }
        }
        entry.unk_2c.type4.vector_30.x = 0;
        entry.unk_2c.type4.vector_30.y = 0;
        entry.unk_2c.type4.vector_30.z = 0;
        if (numParams > 12)
        {
            params = params->ToVec3fix(&var4);
            entry.unk_2c.type4.vector_30 = var4;
        }
    }
    else if (entry.maybeType == 5)
    {
        entry.unk_2c.type5.unk_0 = (params++)->ToInt();
        entry.unk_2c.type5.unk_2 = (params++)->ToInt();
        entry.unk_2c.type5.cupboardContainerId = 0;
    }

    ZoneFeatures* instance = data_020fdc20.warp;
    entry.pNext = NULL;
    instance->CreateOpcode6aEntry(entry);
    return 1;
}

void ZoneFeatures::Opcode6aEntry::func_0201d424()
{
    VectorizedMemset(this, 0, sizeof(Opcode6aEntry));
    unk_0 = 0;
    maybeType = 0;
    angle = 0;
    unk_22 = 0;
    unk_24 = 0;
    unk_8.vec.x = 0;
    unk_8.vec.y = 0;
    unk_8.vec.z = 0;
    unk_14.vec.x = 0;
    unk_14.vec.y = 0;
    unk_14.vec.z = 0;
    unk_28 = 0;
    pNext = NULL;
}

MaybeVector4fix &MaybeVector4fix::CopyFrom(const MaybeVector4fix &other)
{
    vec3 = other.vec3;
    fix32_t var0 = other.w;
    w = var0;
    return *this;
}

extern "C" int ZoneFeaturesScript_SetDefaultPositionAndAngle(Script::Parameter* params, int numParams)
{
    Vector3fix var0;
    params = params->ToVec3fix(&var0);
    fix32_t angle = _Z22fix32ReduceAngle0To2Pii(4096.0f * (params++)->ToFloat());

    ZoneFeatures* warp = data_020fdc20.warp;
    warp->vector_70_ = var0;
    warp->angle_7c_ = angle;
    return 1;
}

extern "C" int ZoneFeaturesScript_SetClearColor(Script::Parameter* params, int numParams)
{
    int red = (params++)->ToInt();
    int green = (params++)->ToInt();
    int blue = (params++)->ToInt();
    data_020fdc20.warp->color_7e_ = red | (green << 5) | (blue << 10);
    return 1;
}

extern "C" int ZoneFeaturesScript_AddEntry(Script::Parameter* params, int numParams)
{
    ZoneFeatures::Opcode6aEntry entry;
    entry.func_0201d424();
    entry.maybeType = (params++)->ToInt();
    Vector3fix var1;
    params = params->ToVec3fix(&var1);
    entry.unk_8.vec = var1;
    params = params->ToVec3fix(&var1);
    entry.unk_14.vec = var1;

    entry.unk_22 = _Z22fix32ReduceAngle0To2Pii(4096.0f * (params++)->ToFloat());
    entry.angle = 4096.0f * (params++)->ToFloat();

    fix32_t var2 = entry.unk_14.vec.x / 2;
    fix32_t var3 = entry.unk_14.vec.z / 2;
    fix32_t var4 = FIX32_MULTIPLY(var2, var2);
    fix32_t var5 = FIX32_MULTIPLY(var3, var3);
    entry.unk_24 = var5;
    entry.unk_24 = var4 + var5;

    data_020fdc20.currentEntry = data_020fdc20.warp->CreateOpcode6aEntry(entry);
    return 1;
}

extern "C" int ZoneFeaturesScript_SetEntryData(Script::Parameter* params, int numParams)
{
    if (data_020fdc20.currentEntry == NULL)
        return 0;
    void* worldData = GameState_GetZoneTable(GameState::GetInstance());
    switch (data_020fdc20.currentEntry->maybeType)
    {
    case 0:
        data_020fdc20.currentEntry->unk_2c.type0.unk_0 = 0;
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = params->ToInt();
        break;
    case 6:
        data_020fdc20.currentEntry->maybeType = 0;
        data_020fdc20.currentEntry->unk_2c.type0.unk_0 = 1;
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = params->ToInt();
        break;
    case 1:
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = params->ToInt();
        break;
    case 2:
        if (numParams == 3)
        {
            data_020fdc20.currentEntry->unk_2c.type2.nodeId = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.elementId = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.flags = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.soundIndex = 0;
        }
        else
        {
            int var1 = 0;
            data_020fdc20.currentEntry->unk_2c.type2.nodeId = (params++)->ToInt();
            var1++;
            data_020fdc20.currentEntry->unk_2c.type2.elementId = (params++)->ToInt();
            var1++;
            data_020fdc20.currentEntry->unk_2c.type2.flags = (params++)->ToInt();
            var1++;
            data_020fdc20.currentEntry->unk_2c.type2.soundIndex = (params++)->ToInt();
            var1++;

            if (data_020fdc20.currentEntry->unk_2c.type2.flags & 8)
            {
                if (params->type == 0)
                {
                    const char* zoneName = (params++)->ToString();
                    var1++;
                    unsigned short* maybeZoneData = ZoneTable_FindEntryByMapCode(worldData, zoneName);

                    if (maybeZoneData == NULL)
                        return 0;
                    data_020fdc20.currentEntry->unk_2c.type2.maybeZone = *maybeZoneData;
                }
                else
                {
                    data_020fdc20.currentEntry->unk_2c.type2.maybeZone = (params++)->ToInt();
                    var1++;
                }
                data_020fdc20.currentEntry->unk_2c.type2.unk_6 = (params++)->ToInt();
                var1++;
                data_020fdc20.currentEntry->unk_2c.type2.unk_8 = (params++)->ToInt();
                var1++;
                Vector3fix var4;
                params = params->ToVec3fix(&var4);
                var1 += 3;
                data_020fdc20.currentEntry->unk_2c.type2.vectors_c[0] = var4;
                data_020fdc20.currentEntry->unk_2c.type2.unk_3c = 4096.0f * (params++)->ToFloat();
                var1++;
                data_020fdc20.currentEntry->unk_2c.type2.unk_3e = 4096.0f * (params++)->ToFloat();
                var1++;

                for (int i = 1; i < 4; i++)
                {
                    params = params->ToVec3fix(&var4);
                    var1 += 3;
                    data_020fdc20.currentEntry->unk_2c.type2.vectors_c[i] = var4;
                }
            }
            if (var1 < numParams)
            {
                (void)((params++)->ToFloat());
                var1++;
            }
            if (var1 < numParams)
            {
                (void)((params++)->ToInt());
                var1++;
            }
            if (data_020fdc20.currentEntry->unk_2c.type2.flags & DoorFlag_Slides)
            {
                data_020fdc20.currentEntry->unk_2c.type2.slideDistance = 4096.0f * (params++)->ToFloat();
            }
        }
        break;
    case 3:
        data_020fdc20.currentEntry->unk_2c.type3.unk_0 = (params++)->ToInt();
        break;
    case 4:
    {
        data_020fdc20.currentEntry->unk_2c.type4.unk_0 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type4.unk_1 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type4.unk_0_high = (params++)->ToInt();
        Vector3fix vecA;
        Vector3fix vecB;
        params = params->ToVec3fix(&vecA);
        params = params->ToVec3fix(&vecB);
        MaybeVector4fix vector4;
        Vector3fix_Subtract(&vecB, &vecA, &vector4.vec3.vec);
        fix32_t distance = Vector3fix_Length(&vector4.vec3.vec);
        Vector3fix_Normalize(&vector4.vec3.vec, &vector4.vec3.vec);
        vector4.w = Vector3fix_InnerProduct(&vector4.vec3.vec, &vecA);
        Vector3fix var10 = { 0, 0, 0 };
        if (data_020fdc20.currentEntry->unk_2c.type4.unk_0 == 4)
        {
            params = params->ToVec3fix(&var10);
        }
        else
        {
            var10.y = 4096.0f * (params++)->ToFloat();
            var10.z = 4096.0f * (params++)->ToFloat();
        }
        Vector3fix var11;
        params = params->ToVec3fix(&var11);
        data_020fdc20.currentEntry->unk_2c.type4.vector_4.CopyFrom(vector4);
        data_020fdc20.currentEntry->unk_2c.type4.distance_14 = distance;
        data_020fdc20.currentEntry->unk_2c.type4.vector_18 = var10;
        data_020fdc20.currentEntry->unk_2c.type4.vector_24 = var11;
        break;
    }
    case 5:
        data_020fdc20.currentEntry->unk_2c.type5.unk_0 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type5.unk_2 = (params++)->ToInt();
        if (numParams > 2)
            data_020fdc20.currentEntry->unk_0 = (params++)->ToInt();
        break;
    case 8:
        if (numParams != 0)
            data_020fdc20.currentEntry->unk_0 = (params++)->ToInt();
        break;
    case 9:
        data_020fdc20.currentEntry->unk_2c.type9.unk_0 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type9.unk_2 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type9.unk_4 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type9.unk_5 = (params++)->ToInt();
        if (data_020fdc20.currentEntry->unk_2c.type9.unk_5 & 2)
        {
            if (params->type == 0)
            {
                const char* zoneName = (params++)->ToString();
                unsigned short* maybeZoneData = ZoneTable_FindEntryByMapCode(worldData, zoneName);

                if (maybeZoneData == NULL)
                    return 0;
                data_020fdc20.currentEntry->unk_2c.type9.maybeZone = *maybeZoneData;
            }
            else
            {
                data_020fdc20.currentEntry->unk_2c.type9.maybeZone = (params++)->ToInt();
            }
            data_020fdc20.currentEntry->unk_2c.type9.unk_8 = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type9.unk_a = (params++)->ToInt();
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_c);
            data_020fdc20.currentEntry->unk_2c.type9.unk_3c = 4096.0f * (params++)->ToFloat();
            data_020fdc20.currentEntry->unk_2c.type9.unk_3e = 4096.0f * (params++)->ToFloat();
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_18);
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_24);
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type9.vector_30);
            data_020fdc20.currentEntry->unk_2c.type9.unk_40 = 4096.0f * (params++)->ToFloat();
            data_020fdc20.currentEntry->unk_2c.type9.unk_42 = (params++)->ToInt();
        }
        break;
    case 10:
        data_020fdc20.currentEntry->unk_2c.type10.unk_0 = (params++)->ToInt();
        params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type10.vector_4);
        data_020fdc20.currentEntry->unk_2c.type10.unk_2 = 4096.0f * (params++)->ToFloat();
        data_020fdc20.currentEntry->unk_2c.type10.unk_10 = 4096.0f * (params++)->ToFloat();
        if (numParams > 6)
        {
            params = params->ToVec3fix(&data_020fdc20.currentEntry->unk_2c.type10.vector_14);
            data_020fdc20.currentEntry->unk_2c.type10.unk_20 = 4096.0f * (params++)->ToFloat();
        }
        break;
    case 12:
    {
        VectorizedMemset(&data_020fdc20.currentEntry->unk_2c.type12,
            0, sizeof(data_020fdc20.currentEntry->unk_2c.type12));
        data_020fdc20.currentEntry->unk_2c.type12.subtype = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type12.unk_1 = (params++)->ToInt();
        data_020fdc20.currentEntry->unk_2c.type12.unk_2 = (params++)->ToInt();

        ZoneFeatures::Opcode6aEntry* entry = data_020fdc20.currentEntry;
        switch (entry->unk_2c.type12.subtype)
        {
        case 1:
            entry->unk_2c.type12.subtype1.unk_0 = 0;
            entry->unk_2c.type12.subtype1.unk_1 = 0;
            entry->unk_2c.type12.subtype1.unk_3 = 0;
            entry->unk_2c.type12.subtype1.unk_4 = (params++)->ToInt();
            entry->unk_2c.type12.subtype1.unk_5 = (params++)->ToInt();
            entry->unk_2c.type12.subtype1.unk_2 = (params++)->ToInt();
            break;
        case 2:
            entry->unk_2c.type12.subtype2.unk_0 = 0;
            entry->unk_2c.type12.subtype2.unk_4 = 0;
            entry->unk_2c.type12.subtype2.unk_8 = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype2.unk_c = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype2.unk_10 = 25;
            break;
        case 3:
            entry->unk_2c.type12.subtype3.unk_0 = 0;
            entry->unk_2c.type12.subtype3.unk_1 = 0;
            entry->unk_2c.type12.subtype3.unk_4 = 4096 * 9 / 20;
            entry->unk_2c.type12.subtype3.unk_8 = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype3.unk_c = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype3.unk_10 = 4096.0f * (params++)->ToFloat();
            entry->unk_2c.type12.subtype3.unk_8 = 4096 * 9 / 20;
            entry->unk_2c.type12.subtype3.unk_10 = -4096 / 10;
            break;
        }
        break;
    }
    }
    return 1;
}

extern "C" int ZoneFeaturesScript_AllocateHeadingLockAreas(Script::Parameter* params, int numParams)
{
    int count = params[0].ToInt();
    ZoneFeatures::Opcode7bEntry* alloc =
        (ZoneFeatures::Opcode7bEntry*)data_020fdc20.allocator->Allocate(count * sizeof(ZoneFeatures::Opcode7bEntry));
    if (alloc == NULL)
        return 0;
    data_020fdc20.warp->SetHeadingLockAreas(alloc, count);
    return 1;
}

extern "C" int func_0201e018(Script::Parameter* params, int numParams)
{
    ZoneFeatures::Opcode7bEntry entry;
    params = params->ToVec3fix(&entry.unknown_0_.vec);
    params = params->ToVec3fix(&entry.vector_c.vec);
    entry.unknown_18_ = 4096.0f * (params++)->ToFloat();

    fix32_t var1 = -entry.vector_c.vec.x / 2;
    fix32_t var2 = -entry.vector_c.vec.z / 2;
    fix32_t var3 = entry.vector_c.vec.x / 2;
    fix32_t var4 = entry.vector_c.vec.z / 2;

    Vector3fix vertices[4] = { 0 };

    vertices[0].x = var1;
    vertices[0].z = var2;
    vertices[1].x = var1;
    vertices[1].z = var4;
    vertices[2].x = var3;
    vertices[2].z = var2;
    vertices[3].x = var3;
    vertices[3].z = var4;

    Matrix4x3 matrix;
    matrix = _Z15RotationMatrixYi(entry.unknown_18_);

    for (int i = 0; i < 4; i++)
        Mat4x3_ApplyToVector(&vertices[i], &matrix, &vertices[i]);

    entry.minX = vertices[0].x;
    entry.minZ = vertices[0].z;
    entry.maxX = vertices[0].x;
    entry.maxZ = vertices[0].z;

    for (int i = 1; i < 4; i++)
    {
        if (entry.minX > vertices[i].x)
            entry.minX = vertices[i].x;
        if (entry.minZ > vertices[i].z)
            entry.minZ = vertices[i].z;
        if (entry.maxX < vertices[i].x)
            entry.maxX = vertices[i].x;
        if (entry.maxZ < vertices[i].z)
            entry.maxZ = vertices[i].z;
    }

    fix32_t minX = entry.minX;
    fix32_t maxX = entry.maxX;
    fix32_t minZ = entry.minZ;
    fix32_t maxZ = entry.maxZ;

    fix32_t var13 = entry.unknown_0_.vec.x;
    fix32_t var14 = entry.unknown_0_.vec.z;

    minX = var13 + minX;
    minZ = var14 + minZ;
    maxX = var13 + maxX;
    maxZ = var14 + maxZ;

    entry.minX = minX;
    entry.minZ = minZ;
    entry.maxX = maxX;
    entry.maxZ = maxZ;
    data_020fdc20.warp->func_0201e88c(entry);
    return 1;
}

extern "C" void ZoneFeaturesScript_Run(const void* data, unsigned int length, ZoneFeatures* warp, SafeAllocator* alloc)
{
    if (length == 0)
        return;
    data_020fdc20.warp = warp;
    data_020fdc20.allocator = alloc;
    data_020fdc20.currentEntry = NULL;

    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_020ef388);
    script.Load(data, length);
    script.Execute();

    data_020fdc20.warp = NULL;
    data_020fdc20.allocator = NULL;
    data_020fdc20.currentEntry = NULL;
}

void ZoneFeatures::Reset()
{
    VectorizedMemset(this, 0, sizeof(ZoneFeatures));
}

void ZoneFeatures::AllocateOpcode64Entries(int count, SafeAllocator *alloc)
{
    entries64_ = (Opcode64Entry*)alloc->Allocate(count * sizeof(Opcode64Entry));
    arraySize64_ = 0;
    arrayCapacity64_ = count;
}

void ZoneFeatures::func_0201e288(int count, SafeAllocator* alloc)
{
    unknown_30_ = (TileFeaturePlacementData*)alloc->Allocate(count * sizeof(TileFeaturePlacementData));
    unknown_34_ = 0;
    unknown_38_ = count;
}

void ZoneFeatures::LoadFromScript(SafeAllocator* alloc, const void* script, unsigned int length)
{
    ZoneFeaturesScript_Run(script, length, this, alloc);
}

ZoneFeatures::Opcode64Entry* ZoneFeatures::GetOpcode64Entry(int index)
{
    if (index < 0 || arraySize64_ <= index)
        return NULL;
    return &entries64_[index];
}

void ZoneFeatures::CreateOpcode64Entry(const Opcode64Entry& source)
{
    if (arraySize64_ >= arrayCapacity64_)
        return;
    Opcode64Entry& dest = entries64_[arraySize64_];

    dest.unk_0 = source.unk_0;
    dest.vector_4 = source.vector_4;
    COPY_ARRAY(dest.string_10, source.string_10);
    COPY_ARRAY(dest.string_20, source.string_20);
    COPY_ARRAY(dest.string_30, source.string_30);
    COPY_ARRAY(dest.unknown_40_, source.unknown_40_);
    arraySize64_++;
}

void ZoneFeatures::func_0201e3c4(const TileFeaturePlacementData& source)
{
    if (unknown_34_ >= unknown_38_)
        return;

    TileFeaturePlacementData& dest = unknown_30_[unknown_34_];
    dest.unknown_0_ = source.unknown_0_;
    COPY_ARRAY(dest.directionBitmasks, source.directionBitmasks);
    COPY_ARRAY(dest.tilename, source.tilename);

    unknown_34_++;
}

void ZoneFeatures::AllocateOpcode66Entries(int count, SafeAllocator *alloc)
{
    entries66_ = (Opcode66Entry*)alloc->Allocate(count * sizeof(Opcode66Entry));
    arraySize66_ = 0;
    arrayCapacity66_ = count;
}

void ZoneFeatures::CreateOpcode66Entry(const Opcode66Entry& source)
{
    if (arraySize66_ >= arrayCapacity66_)
        return;
    Opcode66Entry& dest = entries66_[arraySize66_];

    COPY_ARRAY(dest.unk_0, source.unk_0);
    COPY_ARRAY(dest.unknown_18_, source.unknown_18_);
    dest.unk_20 = source.unk_20;

    arraySize66_++;
}

void ZoneFeatures::AllocateExits(int count, SafeAllocator* alloc)
{
    entries68_ = (Opcode68Entry*)alloc->Allocate(count * sizeof(Opcode68Entry));
    arraySize68_ = 0;
    arrayCapacity68_ = count;
}

void ZoneFeatures::CreateExit(const Opcode68Entry& source)
{
    if (arraySize68_ >= arrayCapacity68_)
        return;
    Opcode68Entry& dest = entries68_[arraySize68_];

    dest.unk_0 = source.unk_0;
    COPY_ARRAY(dest.unk_4, source.unk_4);
    dest.unk_1c = source.unk_1c;
    COPY_ARRAY(dest.unk_20, source.unk_20);
    dest.unk_50 = source.unk_50;
    dest.unk_52 = source.unk_52;
    dest.unk_54 = source.unk_54;
    COPY_ARRAY(dest.unk_58, source.unk_58);
    COPY_ARRAY(dest.unk_64, source.unk_64);
    dest.unk_6c = source.unk_6c;

    arraySize68_++;
}

void ZoneFeatures::AllocateOpcode6aEntries(int count, SafeAllocator *alloc)
{
    entries6a_ = (Opcode6aEntry*)alloc->Allocate(count * sizeof(Opcode6aEntry));
    arraySize6a_ = 0;
    arrayCapacity6a_ = count;
}

void ZoneFeatures::SetHeadingLockAreas(Opcode7bEntry* array, unsigned short capacity)
{
    entries7b_ = array;
    arrayCapacity7b_ = capacity;
    arraySize7b_ = 0;
}

void ZoneFeatures::func_0201e88c(const Opcode7bEntry& source)
{
    if (entries7b_ == NULL)
        return;

    Opcode7bEntry& dest = entries7b_[arraySize7b_++];
    dest.unknown_0_ = source.unknown_0_;
    dest.vector_c = source.vector_c;
    dest.unknown_18_ = source.unknown_18_;
    dest.minX = source.minX;
    dest.minZ = source.minZ;
    dest.maxX = source.maxX;
    dest.maxZ = source.maxZ;
}
