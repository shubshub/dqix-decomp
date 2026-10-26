#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Memory.h"
#include "Resource/Script.h"
#include "World/ZoneWarpScript.h"
#include "Combat/Main/ElementLookup.h"

extern "C" void __clear(void* buf, int n);

// The entry the last opcode 0x73 created, which this opcode fills in by its type
#define ENTRY (data_020fdc20.currentEntry)

// Main, originally WarpScript_Opcode_74_0201d638 (USA 0x0201d638, EUR 0x0201d648, JPN 0x0201d3c4)
extern "C" ARM int ZoneFeaturesScript_SetEntryData(Script::Parameter* params, int numParams) {
    if (ENTRY == 0) return 0;

    void* zoneTable = GameState_GetZoneTable((void*)GameState::GetInstance());

    switch (ENTRY->maybeType) {
    case 0:
        ENTRY->unk_2c.type0.unk_0 = 0;
        if (numParams != 0) {
            ENTRY->unk_0 = params[0].ToInt();
        }
        goto ret1;

    case 6:
        ENTRY->maybeType = 0;
        ENTRY->unk_2c.type0.unk_0 = 1;
        if (numParams != 0) {
            ENTRY->unk_0 = params[0].ToInt();
        }
        goto ret1;

    case 1:
        if (numParams != 0) {
            ENTRY->unk_0 = params[0].ToInt();
        }
        goto ret1;

    case 2: {
        if (numParams == 3) {
            ENTRY->unk_2c.type2.nodeId = params[0].ToInt();
            ENTRY->unk_2c.type2.elementId = params[1].ToInt();
            ENTRY->unk_2c.type2.flags = params[2].ToInt();
            ENTRY->unk_2c.type2.soundIndex = 0;
            goto ret1;
        }

        int numParamsRead = 0;
        ENTRY->unk_2c.type2.nodeId = params[0].ToInt();
        ENTRY->unk_2c.type2.elementId = params[1].ToInt();
        ENTRY->unk_2c.type2.flags = params[2].ToInt();
        Script::Parameter* soundIndexParam = params + 3;
        params += 4;
        ENTRY->unk_2c.type2.soundIndex = soundIndexParam->ToInt();
        numParamsRead += 4;

        if (ENTRY->unk_2c.type2.flags & 8) {
            if (params->type == 0) {
                const char* zoneName = params->ToString();
                params += 1;
                numParamsRead += 1;
                struct Elem0209998c* zoneEntry = ZoneTable_FindEntryByMapCode((struct List0209998c*)zoneTable, zoneName);
                if (zoneEntry == 0) return 0;
                ENTRY->unk_2c.type2.maybeZone = zoneEntry->f0;
            } else {
                ENTRY->unk_2c.type2.maybeZone = params->ToInt();
                params += 1;
                numParamsRead += 1;
            }

            ENTRY->unk_2c.type2.unk_6 = params[0].ToInt();
            ENTRY->unk_2c.type2.unk_8 = params[1].ToInt();

            int vector[3];
            Script::Parameter* param = params[2].ToVec3fix((Vector3i*)vector);
            ENTRY->unk_2c.type2.vectors_c[0] = *(Vector3i const*)vector;
            int unk3c = (int)(4096.0f * param[0].ToFloat());
            params = param + 2;
            ENTRY->unk_2c.type2.unk_3c = unk3c;
            int unk3e = (int)(4096.0f * param[1].ToFloat());
            ENTRY->unk_2c.type2.unk_3e = unk3e;
            numParamsRead += 7;

            int i;
            for (i = 1; i < 4; i++) {
                param = params->ToVec3fix((Vector3i*)vector);
                params = param;
                numParamsRead += 3;
                ENTRY->unk_2c.type2.vectors_c[i] = *(Vector3i const*)vector;
            }
        }

        if (numParamsRead < numParams) {
            params->ToFloat();
            params += 1;
            numParamsRead += 1;
        }
        if (numParamsRead < numParams) {
            params->ToInt();
            params += 1;
        }
        if (ENTRY->unk_2c.type2.flags & DoorFlag_Slides) {
            ENTRY->unk_2c.type2.slideDistance = (int)(4096.0f * params->ToFloat());
        }
        goto ret1;
    }

    case 3:
        ENTRY->unk_2c.type3.unk_0 = params[0].ToInt();
        goto ret1;

    case 4: {
        unsigned char unk0 = params[0].ToInt();
        ENTRY->unk_2c.type4.unk_0 = unk0;
        ENTRY->unk_2c.type4.unk_1 = params[1].ToInt();
        unsigned char unk0High = params[2].ToInt();
        ENTRY->unk_2c.type4.unk_0_high = unk0High;

        int start[3], end[3];
        Script::Parameter* param = params[3].ToVec3fix((Vector3i*)start);
        param = param->ToVec3fix((Vector3i*)end);
        params = param;

        MaybeVector4fix direction;
        Vector3fix_Subtract((const Vector3fix*)end, (const Vector3fix*)start, &direction.vec3.vec);
        int length = Vector3fix_Length(&direction.vec3.vec);
        Vector3fix_Normalize(&direction.vec3.vec, &direction.vec3.vec);
        direction.w = Vector3fix_InnerProduct(&direction.vec3.vec, (const Vector3fix*)start);

        int vector18[3];
        __clear(vector18, 0xc);
        if (ENTRY->unk_2c.type4.unk_0 == 4) {
            param = params->ToVec3fix((Vector3i*)vector18);
            params = param;
        } else {
            vector18[1] = (int)(4096.0f * params->ToFloat());
            Script::Parameter* next = params + 1;
            params += 2;
            vector18[2] = (int)(4096.0f * next->ToFloat());
        }

        int vector24[3];
        param = params->ToVec3fix((Vector3i*)vector24);

        ENTRY->unk_2c.type4.vector_4.CopyFrom(direction);
        ENTRY->unk_2c.type4.distance_14 = length;
        ENTRY->unk_2c.type4.vector_18 = *(Vector3i const*)vector18;
        ENTRY->unk_2c.type4.vector_24 = *(Vector3i const*)vector24;
        goto ret1;
    }

    case 5:
        ENTRY->unk_2c.type5.unk_0 = params[0].ToInt();
        ENTRY->unk_2c.type5.unk_2 = params[1].ToInt();
        if (numParams <= 2) goto ret1;
        ENTRY->unk_0 = params[2].ToInt();
        goto ret1;

    case 8:
        if (numParams != 0) {
            ENTRY->unk_0 = params[0].ToInt();
        }
        goto ret1;

    case 9: {
        ENTRY->unk_2c.type9.unk_0 = params[0].ToInt();
        ENTRY->unk_2c.type9.unk_2 = params[1].ToInt();
        ENTRY->unk_2c.type9.unk_4 = params[2].ToInt();
        ENTRY->unk_2c.type9.unk_5 = params[3].ToInt();
        if ((ENTRY->unk_2c.type9.unk_5 & 2) == 0) goto ret1;

        if (params[4].type == 0) {
            Script::Parameter* zoneParam = params + 4;
            params += 5;
            const char* zoneName = zoneParam->ToString();
            struct Elem0209998c* zoneEntry = ZoneTable_FindEntryByMapCode((struct List0209998c*)zoneTable, zoneName);
            if (zoneEntry == 0) return 0;
            ENTRY->unk_2c.type9.maybeZone = zoneEntry->f0;
        } else {
            Script::Parameter* zoneParam = params + 4;
            params += 5;
            ENTRY->unk_2c.type9.maybeZone = zoneParam->ToInt();
        }

        ENTRY->unk_2c.type9.unk_8 = params[0].ToInt();
        ENTRY->unk_2c.type9.unk_a = params[1].ToInt();

        Script::Parameter* param = params[2].ToVec3fix(&ENTRY->unk_2c.type9.vector_c);
        ENTRY->unk_2c.type9.unk_3c = (int)(4096.0f * param[0].ToFloat());
        ENTRY->unk_2c.type9.unk_3e = (int)(4096.0f * param[1].ToFloat());
        param = param[2].ToVec3fix(&ENTRY->unk_2c.type9.vector_18);
        param = param->ToVec3fix(&ENTRY->unk_2c.type9.vector_24);
        param = param->ToVec3fix(&ENTRY->unk_2c.type9.vector_30);
        ENTRY->unk_2c.type9.unk_40 = (int)(4096.0f * param[0].ToFloat());
        ENTRY->unk_2c.type9.unk_42 = param[1].ToInt();
        goto ret1;
    }

    case 10: {
        ENTRY->unk_2c.type10.unk_0 = params[0].ToInt();
        Script::Parameter* param = params[1].ToVec3fix(&ENTRY->unk_2c.type10.vector_4);
        ENTRY->unk_2c.type10.unk_2 = (int)(4096.0f * param[0].ToFloat());
        ENTRY->unk_2c.type10.unk_10 = (int)(4096.0f * param[1].ToFloat());
        if (numParams <= 6) goto ret1;
        param = param[2].ToVec3fix(&ENTRY->unk_2c.type10.vector_14);
        ENTRY->unk_2c.type10.unk_20 = (int)(4096.0f * param[0].ToFloat());
        goto ret1;
    }

    case 12: {
        VectorizedMemset(&ENTRY->unk_2c.type12, 0, sizeof(ENTRY->unk_2c.type12));
        ENTRY->unk_2c.type12.subtype = params[0].ToInt();
        ENTRY->unk_2c.type12.unk_1 = params[1].ToInt();
        ENTRY->unk_2c.type12.unk_2 = params[2].ToInt();

        ZoneFeatures::Opcode6aEntry* entry = ENTRY;
        switch (entry->unk_2c.type12.subtype) {
        case 1:
            entry->unk_2c.type12.subtype1.unk_0 = 0;
            entry->unk_2c.type12.subtype1.unk_1 = 0;
            entry->unk_2c.type12.subtype1.unk_3 = 0;
            entry->unk_2c.type12.subtype1.unk_4 = params[3].ToInt();
            entry->unk_2c.type12.subtype1.unk_5 = params[4].ToInt();
            entry->unk_2c.type12.subtype1.unk_2 = params[5].ToInt();
            goto ret1;

        case 2:
            entry->unk_2c.type12.subtype2.unk_0 = 0;
            entry->unk_2c.type12.subtype2.unk_4 = 0;
            entry->unk_2c.type12.subtype2.unk_8 = (int)(4096.0f * params[3].ToFloat());
            entry->unk_2c.type12.subtype2.unk_c = (int)(4096.0f * params[4].ToFloat());
            entry->unk_2c.type12.subtype2.unk_10 = 0x19;
            goto ret1;

        case 3:
            entry->unk_2c.type12.subtype3.unk_0 = 0;
            entry->unk_2c.type12.subtype3.unk_1 = 0;
            entry->unk_2c.type12.subtype3.unk_4 = 0x733;
            entry->unk_2c.type12.subtype3.unk_8 = (int)(4096.0f * params[3].ToFloat());
            entry->unk_2c.type12.subtype3.unk_c = (int)(4096.0f * params[4].ToFloat());
            entry->unk_2c.type12.subtype3.unk_10 = (int)(4096.0f * params[5].ToFloat());
            entry->unk_2c.type12.subtype3.unk_8 = 0x733;
            entry->unk_2c.type12.subtype3.unk_10 = ~0x198;
            goto ret1;
        }
        goto ret1;
    }
    }

    goto ret1;
ret1:
    return 1;
}
