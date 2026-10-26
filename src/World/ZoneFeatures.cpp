#include "World/ZoneWarpScript.h"
#include "World/ZoneFeatures.h"
#include "World/Zone3D.h"
#include "Resource/Script.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"

extern Script::OpcodeLookupEntry data_020ef388[];

extern "C"
{
    extern "C" void* _Z22GameState_GetZoneTablePv(GameState*);
    void _ZN12ZoneFeatures13Opcode68Entry14Reset_0201ce10Ev(void*);

    Matrix4x3 _Z15RotationMatrixYi(fix32_t);

    fix32_t _Z22fix32ReduceAngle0To2Pii(fix32_t);

    extern "C" unsigned short* _Z28ZoneTable_FindEntryByMapCodeP12List0209998cPKc(void*, const char*);

}

int WarpScript_AllocateOpcode64Entries(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode64Entries(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

int WarpScript_CreateOpcode64Entry(Script::Parameter* params, int numParams)
{
    const char* var0;
    const char* var1;
    int var2 = arg0[0].ToInt();
    Vector3fix var3;
    Script::Parameter* var4 = arg0[1].ToVec3fix(&var3);
    arg0 = var4 + 1;
    const char* var5 = var4->ToString();
    var0 = NULL;
    var1 = NULL;

    if (arg1 >= 6)
    {
        var0 = arg0->ToString();
        arg0++;
    }
    if (arg1 >= 7)
    {
        var1 = arg0->ToString();
        arg0++;
    }

    if (var5 == NULL)
        return 0;

    Struct_020134e0::Struct_020146fc var6;
    var6.unknown_0_ = var2;
    var6.unknown_4_.unknown1_0_ = var3;
    strcpy(var6.unknown_10_, var5);
    if (var0 == NULL)
        var6.unknown_20_[0] = '\0';
    else
        strcpy(var6.unknown_20_, var0);
    if (var1 == NULL)
        var6.unknown_30_[0] = '\0';
    else
        strcpy(var6.unknown_30_, var1);

    data_020fdc20.warp->CreateOpcode64Entry(entry);
    return 1;
}

extern "C" int func_0201c8a8(Script::Parameter* arg0, int arg1)
{
    data_020fdc20.unknown_8_->func_0201e288(arg0[0].ToInt(), data_020fdc20.unknown_4_);
    return 1;
}

extern "C" int func_0201c8d0(Script::Parameter* arg0, int arg1)
{
    TileFeaturePlacementData var0;
    var0.unknown_0_ = (arg0++)->ToInt();
    strcpy(var0.tilename, (arg0++)->ToString());

    for (int var1 = 0; var1 < 9; var1++)
        var0.directionBitmasks[var1] = (arg0++)->ToInt();

    data_020fdc20.unknown_8_->func_0201e3c4(var0);
    return 1;
}

int ZoneFeaturesScript_AllocateOpcode66Entries(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode66Entries(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

int ZoneFeaturesScript_AllocateExits(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateExits(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

void Struct_020134e0::Struct_0201cb60_3::func_0201ce10()
{
    unknown_0_ = 0;
    unknown_1c_ = -1;
    unknown_50_ = 0;
    unknown_52_ = 0;
    unknown_54_ = 0;
    unknown_64_[0] = 0;
    unknown_64_[1] = 0;
    unknown_58_[0] = 0;
    unknown_58_[1] = 0;
    unknown_58_[2] = 0;
    unknown_20_[0].x = 0;
    unknown_20_[0].y = 0;
    unknown_20_[0].z = 0;
    unknown_20_[1].x = 0;
    unknown_20_[1].y = 0;
    unknown_20_[1].z = 0;
    unknown_20_[2].x = 0;
    unknown_20_[2].y = 0;
    unknown_20_[2].z = 0;
    unknown_20_[3].x = 0;
    unknown_20_[3].y = 0;
    unknown_20_[3].z = 0;
    unknown_6c_ = -1;
}

int ZoneFeaturesScript_AllocateEntries(Script::Parameter* params, int numParams)
{
    data_020fdc20.warp->AllocateOpcode6aEntries(params[0].ToInt(), data_020fdc20.allocator);
    return 1;
}

extern "C" int func_0201d044(Script::Parameter* arg0, int arg1)
{
    Script::Parameter* var0 = arg0;
    Struct_020134e0::Struct_02018300 var1;
    var1.func_0201d424();
    int var2 = (arg0++)->ToInt();
    var1.unknown_4_ = var2;
    bool var3 = false;
    if (var1.unknown_4_ >= 10)
    {
        var1.unknown_4_ -= 10;
        var3 = true;
    }

    Vector3fix var4;
    arg0 = arg0->ToVec3fix(&var4);
    var1.unknown_8_.unknown1_0_ = var4;
    arg0 = arg0->ToVec3fix(&var4);
    var1.unknown_14_.unknown1_0_ = var4;

    if (var3)
    {
        fix32_t var5 = 4096.0f * (arg0++)->ToFloat();
        var1.unknown_22_ = _Z22fix32ReduceAngle0To2Pii(var5);
    }
    entry.angle = 4096.0f * (params++)->ToFloat();

    fix32_t var6 = var1.unknown_14_.unknown1_0_.x / 2;
    fix32_t var7 = var1.unknown_14_.unknown1_0_.z / 2;
    fix32_t var8 = FIX32_MULTIPLY(var6, var6);
    fix32_t var9 = FIX32_MULTIPLY(var7, var7);
    var1.unknown_24_ = var9;
    var1.unknown_24_ = var8 + var9;

    if (var1.unknown_4_ == 2)
    {
        entry.unk_2c.type2.nodeId = (params++)->ToInt();
        entry.unk_2c.type2.elementId = (params++)->ToInt();
        entry.unk_2c.type2.flags = (params++)->ToInt();
    }
    else if (var1.unknown_4_ == 3)
    {
        var1.unknown_2c_.unknown2_0_.unknown_0_ = (arg0++)->ToInt();
    }
    else if (var1.unknown_4_ == 4)
    {
        int var10 = (arg0++)->ToInt();
        var1.unknown_2c_.unknown3_0_.unknown_1_ = -1;
        var1.unknown_2c_.unknown3_0_.unknown_0_0_ = var10;
        var1.unknown_2c_.unknown3_0_.unknown_0_7_ = 0;
        switch (var1.unknown_2c_.unknown3_0_.unknown_0_0_)
        {
        case 0:
            var1.unknown_2c_.unknown3_0_.unknown_4_.unknown_0_.unknown1_0_.y = 4096.0f * (arg0++)->ToFloat();
            var1.unknown_2c_.unknown3_0_.unknown_4_.unknown_0_.unknown1_0_.z = 4096.0f * (arg0++)->ToFloat();
            break;
        case 1:
            arg0 = arg0->ToVec3fix(&var4);
            var1.unknown_2c_.unknown3_0_.unknown_4_.unknown_0_.unknown1_0_ = var4;
            break;
        case 2:
        case 3:
            arg0 = arg0->ToVec3fix(&var4);
            var1.unknown_2c_.unknown3_0_.unknown_4_.unknown_0_.unknown1_0_ = var4;
            break;
        case 4:
        case 5:
        {
            Vector3fix var11;
            Vector3fix var12;
            arg0 = arg0->ToVec3fix(&var11);
            arg0 = arg0->ToVec3fix(&var12);
            Struct_0201d044 var13;
            Vector3fix_Subtract(&var12, &var11, &var13.unknown_0_.unknown1_0_);
            fix32_t var14 = Vector3fix_Length(&var13.unknown_0_.unknown1_0_);
            Vector3fix_Normalize(&var13.unknown_0_.unknown1_0_, &var13.unknown_0_.unknown1_0_);
            var13.unknown_c_ = Vector3fix_InnerProduct(&var13.unknown_0_.unknown1_0_, &var11);
            Vector3fix var15  = { 0, 0, 0 };
            if (var1.unknown_2c_.unknown3_0_.unknown_0_0_ == 4)
            {
                var15.x = 4096.0f * (arg0++)->ToFloat();
            }
            vecC.y = 4096.0f * (params++)->ToFloat();
            vecC.z = 4096.0f * (params++)->ToFloat();
            Vector3fix vecD;
            params = params->ToVec3fix(&vecD);
            entry.unk_2c.type4.vector_4.CopyFrom(difference);
            entry.unk_2c.type4.distance_14 = distance;
            entry.unk_2c.type4.vector_18 = vecC;
            entry.unk_2c.type4.vector_24 = vecD;
            break;
        }
        }
        var1.unknown_2c_.unknown3_0_.unknown_30_.x = 0;
        var1.unknown_2c_.unknown3_0_.unknown_30_.y = 0;
        var1.unknown_2c_.unknown3_0_.unknown_30_.z = 0;
        if (arg1 > 12)
        {
            arg0 = arg0->ToVec3fix(&var4);
            var1.unknown_2c_.unknown3_0_.unknown_30_ = var4;
        }
    }
    else if (var1.unknown_4_ == 5)
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

void Struct_020134e0::Struct_02018300::func_0201d424()
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
    unknown_0_ = arg0.unknown_0_;
    fix32_t var0 = arg0.unknown_c_;
    unknown_c_ = var0;
    return *this;
}

int ZoneFeaturesScript_SetDefaultPositionAndAngle(Script::Parameter* params, int numParams)
{
    Vector3fix var0;
    arg0 = arg0->ToVec3fix(&var0);
    fix32_t var1 = _Z22fix32ReduceAngle0To2Pii(4096.0f * (arg0++)->ToFloat());

    Struct_020134e0* var2 = data_020fdc20.unknown_8_;
    var2->unknown_70_ = var0;
    var2->unknown_7c_ = var1;
    return 1;
}

int ZoneFeaturesScript_SetClearColor(Script::Parameter* params, int numParams)
{
    int var0 = (arg0++)->ToInt();
    int var1 = (arg0++)->ToInt();
    int var2 = (arg0++)->ToInt();
    data_020fdc20.unknown_8_->unknown_7e_ = var0 | (var1 << 5) | (var2 << 10);
    return 1;
}

int ZoneFeaturesScript_AddEntry(Script::Parameter* params, int numParams)
{
    Struct_020134e0::Struct_02018300 var0;
    var0.func_0201d424();
    var0.unknown_4_ = (arg0++)->ToInt();
    Vector3fix var1;
    arg0 = arg0->ToVec3fix(&var1);
    var0.unknown_8_.unknown1_0_ = var1;
    arg0 = arg0->ToVec3fix(&var1);
    var0.unknown_14_.unknown1_0_ = var1;

    entry.unk_22 = _Z22fix32ReduceAngle0To2Pii(4096.0f * (params++)->ToFloat());
    entry.angle = 4096.0f * (params++)->ToFloat();

    fix32_t var2 = var0.unknown_14_.unknown1_0_.x / 2;
    fix32_t var3 = var0.unknown_14_.unknown1_0_.z / 2;
    fix32_t var4 = FIX32_MULTIPLY(var2, var2);
    fix32_t var5 = FIX32_MULTIPLY(var3, var3);
    var0.unknown_24_ = var5;
    var0.unknown_24_ = var4 + var5;

    data_020fdc20.currentEntry = data_020fdc20.warp->CreateOpcode6aEntry(entry);
    return 1;
}

int ZoneFeaturesScript_SetEntryData(Script::Parameter* params, int numParams)
{
    if (data_020fdc20.unknown_0_ == NULL)
        return 0;
    void* worldData = _Z22GameState_GetZoneTablePv(GameState::GetInstance());
    switch (data_020fdc20.currentEntry->maybeType)
    {
    case 0:
        data_020fdc20.unknown_0_->unknown_2c_.unknown_0_.unknown_0_ = 0;
        if (arg1 != 0)
            data_020fdc20.unknown_0_->unknown_0_ = arg0->ToInt();
        break;
    case 6:
        data_020fdc20.unknown_0_->unknown_4_ = 0;
        data_020fdc20.unknown_0_->unknown_2c_.unknown_0_.unknown_0_ = 1;
        if (arg1 != 0)
            data_020fdc20.unknown_0_->unknown_0_ = arg0->ToInt();
        break;
    case 1:
        if (arg1 != 0)
            data_020fdc20.unknown_0_->unknown_0_ = arg0->ToInt();
        break;
    case 2:
        if (arg1 == 3)
        {
            data_020fdc20.currentEntry->unk_2c.type2.nodeId = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.elementId = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.flags = (params++)->ToInt();
            data_020fdc20.currentEntry->unk_2c.type2.soundIndex = 0;
        }
        else
        {
            int numArgsConsumed = 0;
            data_020fdc20.currentEntry->unk_2c.type2.nodeId = (params++)->ToInt();
            numArgsConsumed++;
            data_020fdc20.currentEntry->unk_2c.type2.elementId = (params++)->ToInt();
            numArgsConsumed++;
            data_020fdc20.currentEntry->unk_2c.type2.flags = (params++)->ToInt();
            numArgsConsumed++;
            data_020fdc20.currentEntry->unk_2c.type2.soundIndex = (params++)->ToInt();
            numArgsConsumed++;

            if (data_020fdc20.currentEntry->unk_2c.type2.flags & 8)
            {
                if (arg0->type == 0)
                {
                    const char* zoneName = (params++)->ToString();
                    numArgsConsumed++;
                    unsigned short* maybeZoneData = _Z28ZoneTable_FindEntryByMapCodeP12List0209998cPKc(worldData, zoneName);

                    if (var3 == NULL)
                        return 0;
                    data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_4_ = *var3;
                }
                else
                {
                    data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_4_ = (arg0++)->ToInt();
                    var1++;
                }
                data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_6_ = (arg0++)->ToInt();
                var1++;
                data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_8_ = (arg0++)->ToInt();
                var1++;
                Vector3fix var4;
                arg0 = arg0->ToVec3fix(&var4);
                var1 += 3;
                data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_c_[0] = var4;
                data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_3c_ = 4096.0f * (arg0++)->ToFloat();
                var1++;
                data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_3e_ = 4096.0f * (arg0++)->ToFloat();
                var1++;

                for (int var5 = 1; var5 < 4; var5++)
                {
                    arg0 = arg0->ToVec3fix(&var4);
                    var1 += 3;
                    data_020fdc20.unknown_0_->unknown_2c_.unknown1_0_.unknown_c_[var5] = var4;
                }
            }
            if (var1 < arg1)
            {
                (void)((arg0++)->ToFloat());
                var1++;
            }
            if (var1 < arg1)
            {
                (void)((arg0++)->ToInt());
                var1++;
            }
            if (data_020fdc20.currentEntry->unk_2c.type2.flags & DoorFlag_Slides)
            {
                data_020fdc20.currentEntry->unk_2c.type2.slideDistance = 4096.0f * (params++)->ToFloat();
            }
        }
        break;
    case 3:
        data_020fdc20.unknown_0_->unknown_2c_.unknown2_0_.unknown_0_ = (arg0++)->ToInt();
        break;
    case 4:
    {
        data_020fdc20.unknown_0_->unknown_2c_.unknown3_0_.unknown_0_0_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown3_0_.unknown_1_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown3_0_.unknown_0_7_ = (arg0++)->ToInt();
        Vector3fix var6;
        Vector3fix var7;
        arg0 = arg0->ToVec3fix(&var6);
        arg0 = arg0->ToVec3fix(&var7);
        Struct_0201d044 var8;
        Vector3fix_Subtract(&var7, &var6, &var8.unknown_0_.unknown1_0_);
        fix32_t var9 = Vector3fix_Length(&var8.unknown_0_.unknown1_0_);
        Vector3fix_Normalize(&var8.unknown_0_.unknown1_0_, &var8.unknown_0_.unknown1_0_);
        var8.unknown_c_ = Vector3fix_InnerProduct(&var8.unknown_0_.unknown1_0_, &var6);
        Vector3fix var10 = { 0, 0, 0 };
        if (data_020fdc20.unknown_0_->unknown_2c_.unknown3_0_.unknown_0_0_ == 4)
        {
            arg0 = arg0->ToVec3fix(&var10);
        }
        else
        {
            var10.y = 4096.0f * (arg0++)->ToFloat();
            var10.z = 4096.0f * (arg0++)->ToFloat();
        }
        Vector3fix vecD;
        params = params->ToVec3fix(&vecD);
        data_020fdc20.currentEntry->unk_2c.type4.vector_4.CopyFrom(vector4);
        data_020fdc20.currentEntry->unk_2c.type4.distance_14 = distance;
        data_020fdc20.currentEntry->unk_2c.type4.vector_18 = vecC;
        data_020fdc20.currentEntry->unk_2c.type4.vector_24 = vecD;
        break;
    }
    case 5:
        data_020fdc20.unknown_0_->unknown_2c_.unknown4_0_.unknown_0_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown4_0_.unknown_2_ = (arg0++)->ToInt();
        if (arg1 > 2)
            data_020fdc20.unknown_0_->unknown_0_ = (arg0++)->ToInt();
        break;
    case 8:
        if (arg1 != 0)
            data_020fdc20.unknown_0_->unknown_0_ = (arg0++)->ToInt();
        break;
    case 9:
        data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_0_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_2_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_4_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_5_ = (arg0++)->ToInt();
        if (data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_5_ & 2)
        {
            if (arg0->type == 0)
            {
                const char* zoneName = (params++)->ToString();
                unsigned short* maybeZoneData = _Z28ZoneTable_FindEntryByMapCodeP12List0209998cPKc(worldData, zoneName);

                if (var13 == NULL)
                    return 0;
                data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_6_ = *var13;
            }
            else
            {
                data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_6_ = (arg0++)->ToInt();
            }
            data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_8_ = (arg0++)->ToInt();
            data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_a_ = (arg0++)->ToInt();
            arg0 = arg0->ToVec3fix(&data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_c_);
            data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_3c_ = 4096.0f * (arg0++)->ToFloat();
            data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_3e_ = 4096.0f * (arg0++)->ToFloat();
            arg0 = arg0->ToVec3fix(&data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_18_);
            arg0 = arg0->ToVec3fix(&data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_24_);
            arg0 = arg0->ToVec3fix(&data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_30_);
            data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_40_ = 4096.0f * (arg0++)->ToFloat();
            data_020fdc20.unknown_0_->unknown_2c_.unknown5_0_.unknown_42_ = (arg0++)->ToInt();
        }
        break;
    case 10:
        data_020fdc20.unknown_0_->unknown_2c_.unknown6_0_.unknown_0_ = (arg0++)->ToInt();
        arg0 = arg0->ToVec3fix(&data_020fdc20.unknown_0_->unknown_2c_.unknown6_0_.unknown_4_);
        data_020fdc20.unknown_0_->unknown_2c_.unknown6_0_.unknown_2_ = 4096.0f * (arg0++)->ToFloat();
        data_020fdc20.unknown_0_->unknown_2c_.unknown6_0_.unknown_10_ = 4096.0f * (arg0++)->ToFloat();
        if (arg1 > 6)
        {
            arg0 = arg0->ToVec3fix(&data_020fdc20.unknown_0_->unknown_2c_.unknown6_0_.unknown_14_);
            data_020fdc20.unknown_0_->unknown_2c_.unknown6_0_.unknown_20_ = 4096.0f * (arg0++)->ToFloat();
        }
        break;
    case 12:
    {
        VectorizedMemset(&data_020fdc20.unknown_0_->unknown_2c_.unknown7_0_,
            0, sizeof(data_020fdc20.unknown_0_->unknown_2c_.unknown7_0_));
        data_020fdc20.unknown_0_->unknown_2c_.unknown7_0_.unknown_0_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown7_0_.unknown_1_ = (arg0++)->ToInt();
        data_020fdc20.unknown_0_->unknown_2c_.unknown7_0_.unknown_2_ = (arg0++)->ToInt();

        Struct_020134e0::Struct_02018300* var14 = data_020fdc20.unknown_0_;
        switch (var14->unknown_2c_.unknown7_0_.unknown_0_)
        {
        case 1:
            var14->unknown_2c_.unknown7_0_.unknown_4_.unknown_0_ = 0;
            var14->unknown_2c_.unknown7_0_.unknown_4_.unknown_1_ = 0;
            var14->unknown_2c_.unknown7_0_.unknown_4_.unknown_3_ = 0;
            var14->unknown_2c_.unknown7_0_.unknown_4_.unknown_4_ = (arg0++)->ToInt();
            var14->unknown_2c_.unknown7_0_.unknown_4_.unknown_5_ = (arg0++)->ToInt();
            var14->unknown_2c_.unknown7_0_.unknown_4_.unknown_2_ = (arg0++)->ToInt();
            break;
        case 2:
            var14->unknown_2c_.unknown7_0_.unknown1_4_.unknown_0_ = 0;
            var14->unknown_2c_.unknown7_0_.unknown1_4_.unknown_4_ = 0;
            var14->unknown_2c_.unknown7_0_.unknown1_4_.unknown_8_ = 4096.0f * (arg0++)->ToFloat();
            var14->unknown_2c_.unknown7_0_.unknown1_4_.unknown_c_ = 4096.0f * (arg0++)->ToFloat();
            var14->unknown_2c_.unknown7_0_.unknown1_4_.unknown_10_ = 25;
            break;
        case 3:
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_0_ = 0;
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_1_ = 0;
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_4_ = 4096 * 9 / 20;
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_8_ = 4096.0f * (arg0++)->ToFloat();
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_c_ = 4096.0f * (arg0++)->ToFloat();
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_10_ = 4096.0f * (arg0++)->ToFloat();
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_8_ = 4096 * 9 / 20;
            var14->unknown_2c_.unknown7_0_.unknown2_4_.unknown_10_ = -4096 / 10;
            break;
        }
        break;
    }
    }
    return 1;
}

int ZoneFeaturesScript_AllocateHeadingLockAreas(Script::Parameter* params, int numParams)
{
    int var0 = arg0[0].ToInt();
    Struct_020134e0::Struct_0201dfcc* var1 =
        (Struct_020134e0::Struct_0201dfcc*)data_020fdc20.unknown_4_->Allocate(var0 * sizeof(Struct_020134e0::Struct_0201dfcc));
    if (var1 == NULL)
        return 0;
    data_020fdc20.warp->SetHeadingLockAreas(alloc, count);
    return 1;
}

extern "C" int func_0201e018(Script::Parameter* arg0, int arg1)
{
    Struct_020134e0::Struct_0201dfcc var0;
    arg0 = arg0->ToVec3fix(&var0.unknown_0_.unknown1_0_);
    arg0 = arg0->ToVec3fix(&var0.unknown_c_.unknown1_0_);
    var0.unknown_18_ = 4096.0f * (arg0++)->ToFloat();

    fix32_t var1 = -var0.unknown_c_.unknown1_0_.x / 2;
    fix32_t var2 = -var0.unknown_c_.unknown1_0_.z / 2;
    fix32_t var3 = var0.unknown_c_.unknown1_0_.x / 2;
    fix32_t var4 = var0.unknown_c_.unknown1_0_.z / 2;

    Vector3fix var5[4] = { 0 };

    var5[0].x = var1;
    var5[0].z = var2;
    var5[1].x = var1;
    var5[1].z = var4;
    var5[2].x = var3;
    var5[2].z = var2;
    var5[3].x = var3;
    var5[3].z = var4;

    Matrix4x3 var6;
    var6 = _Z15RotationMatrixYi(var0.unknown_18_);

    for (int var7 = 0; var7 < 4; var7++)
        Mat4x3_ApplyToVector(&var5[var7], &var6, &var5[var7]);

    var0.unknown_1c_ = var5[0].x;
    var0.unknown_20_ = var5[0].z;
    var0.unknown_24_ = var5[0].x;
    var0.unknown_28_ = var5[0].z;

    for (int var8 = 1; var8 < 4; var8++)
    {
        if (var0.unknown_1c_ > var5[var8].x)
            var0.unknown_1c_ = var5[var8].x;
        if (var0.unknown_20_ > var5[var8].z)
            var0.unknown_20_ = var5[var8].z;
        if (var0.unknown_24_ < var5[var8].x)
            var0.unknown_24_ = var5[var8].x;
        if (var0.unknown_28_ < var5[var8].z)
            var0.unknown_28_ = var5[var8].z;
    }

    fix32_t var9 = var0.unknown_1c_;
    fix32_t var10 = var0.unknown_24_;
    fix32_t var11 = var0.unknown_20_;
    fix32_t var12 = var0.unknown_28_;

    fix32_t var13 = var0.unknown_0_.unknown1_0_.x;
    fix32_t var14 = var0.unknown_0_.unknown1_0_.z;

    var9 = var13 + var9;
    var11 = var14 + var11;
    var10 = var13 + var10;
    var12 = var14 + var12;

    var0.unknown_1c_ = var9;
    var0.unknown_20_ = var11;
    var0.unknown_24_ = var10;
    var0.unknown_28_ = var12;
    data_020fdc20.unknown_8_->func_0201e88c(var0);
    return 1;
}

void ZoneFeaturesScript_Run(const void* data, unsigned int length, ZoneFeatures* warp, SafeAllocator* alloc)
{
    if (arg1 == 0)
        return;
    data_020fdc20.unknown_8_ = arg2;
    data_020fdc20.unknown_4_ = arg3;
    data_020fdc20.unknown_0_ = NULL;

    Script var0;
    var0.Initialize();
    var0.SetOpcodeLookup(data_020ef388);
    var0.Load(arg0, arg1);
    var0.Execute();

    data_020fdc20.unknown_8_ = NULL;
    data_020fdc20.unknown_4_ = NULL;
    data_020fdc20.unknown_0_ = NULL;
}

void ZoneFeatures::Reset()
{
    VectorizedMemset(this, 0, sizeof(Struct_020134e0));
}

void ZoneFeatures::AllocateOpcode64Entries(int count, SafeAllocator *alloc)
{
    unknown_0_ = (Struct_020146fc*)arg1->Allocate(arg0 * sizeof(Struct_020146fc));
    unknown_4_ = 0;
    unknown_8_ = arg0;
}

void Struct_020134e0::func_0201e288(int arg0, SafeAllocator* arg1)
{
    unknown_30_ = (TileFeaturePlacementData*)arg1->Allocate(arg0 * sizeof(TileFeaturePlacementData));
    unknown_34_ = 0;
    unknown_38_ = arg0;
}

void ZoneFeatures::LoadFromScript(SafeAllocator* alloc, const void* script, unsigned int length)
{
    ZoneFeaturesScript_Run(script, length, this, alloc);
}

ZoneFeatures::Opcode64Entry* ZoneFeatures::GetOpcode64Entry(int index)
{
    if (arg0 < 0 || unknown_4_ <= arg0)
        return NULL;
    return &unknown_0_[arg0];
}

void ZoneFeatures::CreateOpcode64Entry(const Opcode64Entry& source)
{
    if (unknown_4_ >= unknown_8_)
        return;
    Struct_020146fc& var0 = unknown_0_[unknown_4_];

    var0.unknown_0_ = arg0.unknown_0_;
    var0.unknown_4_ = arg0.unknown_4_;
    COPY_ARRAY(var0.unknown_10_, arg0.unknown_10_);
    COPY_ARRAY(var0.unknown_20_, arg0.unknown_20_);
    COPY_ARRAY(var0.unknown_30_, arg0.unknown_30_);
    COPY_ARRAY(var0.unknown_40_, arg0.unknown_40_);
    unknown_4_++;
}

void Struct_020134e0::func_0201e3c4(const TileFeaturePlacementData& arg0)
{
    if (unknown_34_ >= unknown_38_)
        return;

    TileFeaturePlacementData& var0 = unknown_30_[unknown_34_];
    var0.unknown_0_ = arg0.unknown_0_;
    COPY_ARRAY(var0.directionBitmasks, arg0.directionBitmasks);
    COPY_ARRAY(var0.tilename, arg0.tilename);

    unknown_34_++;
}

void ZoneFeatures::AllocateOpcode66Entries(int count, SafeAllocator *alloc)
{
    unknown_c_ = (Struct_0201c96c*)arg1->Allocate(arg0 * sizeof(Struct_0201c96c));
    unknown_10_ = 0;
    unknown_14_ = arg0;
}

void ZoneFeatures::CreateOpcode66Entry(const Opcode66Entry& source)
{
    if (unknown_10_ >= unknown_14_)
        return;
    Struct_0201c96c& var0 = unknown_c_[unknown_10_];

    COPY_ARRAY(var0.unknown_0_, arg0.unknown_0_);
    COPY_ARRAY(var0.unknown_18_, arg0.unknown_18_);
    var0.unknown_20_ = arg0.unknown_20_;

    unknown_10_++;
}

void ZoneFeatures::AllocateExits(int count, SafeAllocator* alloc)
{
    unknown_18_ = (Struct_0201cb60_3*)arg1->Allocate(arg0 * sizeof(Struct_0201cb60_3));
    unknown_1c_ = 0;
    unknown_20_ = arg0;
}

void ZoneFeatures::CreateExit(const Opcode68Entry& source)
{
    if (unknown_1c_ >= unknown_20_)
        return;
    Struct_0201cb60_3& var0 = unknown_18_[unknown_1c_];

    var0.unknown_0_ = arg0.unknown_0_;
    COPY_ARRAY(var0.unknown_4_, arg0.unknown_4_);
    var0.unknown_1c_ = arg0.unknown_1c_;
    COPY_ARRAY(var0.unknown_20_, arg0.unknown_20_);
    var0.unknown_50_ = arg0.unknown_50_;
    var0.unknown_52_ = arg0.unknown_52_;
    var0.unknown_54_ = arg0.unknown_54_;
    COPY_ARRAY(var0.unknown_58_, arg0.unknown_58_);
    COPY_ARRAY(var0.unknown_64_, arg0.unknown_64_);
    var0.unknown_6c_ = arg0.unknown_6c_;

    unknown_1c_++;
}

void ZoneFeatures::AllocateOpcode6aEntries(int count, SafeAllocator *alloc)
{
    unknown_24_ = (Struct_02018300*)arg1->Allocate(arg0 * sizeof(Struct_02018300));
    unknown_28_ = 0;
    unknown_2c_ = arg0;
}

void ZoneFeatures::SetHeadingLockAreas(Opcode7bEntry* array, unsigned short capacity)
{
    unknown_84_ = arg0;
    unknown_82_ = arg1;
    unknown_80_ = 0;
}

void Struct_020134e0::func_0201e88c(const Struct_0201dfcc& arg0)
{
    if (unknown_84_ == NULL)
        return;

    Struct_0201dfcc& var0 = unknown_84_[unknown_80_++];
    var0.unknown_0_ = arg0.unknown_0_;
    var0.unknown_c_ = arg0.unknown_c_;
    var0.unknown_18_ = arg0.unknown_18_;
    var0.unknown_1c_ = arg0.unknown_1c_;
    var0.unknown_20_ = arg0.unknown_20_;
    var0.unknown_24_ = arg0.unknown_24_;
    var0.unknown_28_ = arg0.unknown_28_;
}
