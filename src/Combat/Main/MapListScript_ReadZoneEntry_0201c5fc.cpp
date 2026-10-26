#include <globaldefs.h>
#include "Resource/Script.h"

#include "std_library_functions.h"

int fix32ReduceAngle0To2Pi(int v);

// Zone3D::substruct_c_, which MapListScript_LookUpZone fills from maplist9.bin
struct MapListZoneInfo0201c5fc {
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
    unsigned short unknown_34_;
    char pad_36[2];
    int unknown_38_;
    int unknown_3c_;
};

struct MapListScriptState0201c5fc {
    int unknown0;
    struct MapListZoneInfo0201c5fc* output;
    int unknown8;
};

// The zone MapListScript_LookUpZone looks up, and where it writes what it finds
extern int data_020ef2bc;
extern struct MapListScriptState0201c5fc data_020fdc14;

// maplist9.bin's zone entry (opcode 0x67): its parameters
enum {
    kParam_ZoneId = 0,
    kParam_AreaName = 2,
    kParam_LightingName = 11,
    kParam_Angle = 13,
    kParam_OffsetX = 14,
    kParam_OffsetZ = 15,
};

// Main, originally InitFromVariantBlock0201c5fc (USA 0x0201c5fc, EUR 0x0201c60c, JPN 0x0201c374)
extern "C" ARM int MapListScript_ReadZoneEntry(void* params) {
    const Script::Parameter* parameters = static_cast<const Script::Parameter*>(params);

    if (data_020ef2bc != parameters[kParam_ZoneId].ToInt())
        return 1;

    parameters[1].ToInt();
#if defined(jpn)
    const char* areaName = parameters[kParam_AreaName].ToString();
    strcpy(data_020fdc14.output->jpbuffer, areaName);
#else
    parameters[kParam_AreaName].ToString();
#endif
    parameters[3].ToInt();
    parameters[4].ToString();
    parameters[5].ToString();
    parameters[6].ToInt();
    parameters[7].ToString();
    parameters[8].ToInt();
    parameters[9].ToInt();
    parameters[10].ToInt();

    const char* lightingName = parameters[kParam_LightingName].ToString();
    if (lightingName != NULL) {
        strcpy(data_020fdc14.output->buffer1, lightingName);
    }

    parameters[12].ToInt();

    data_020fdc14.output->unknown_34_ =
        (unsigned short)fix32ReduceAngle0To2Pi((int)(4096.0f * parameters[kParam_Angle].ToFloat()));

    data_020fdc14.output->unknown_38_ = (int)(4096.0f * parameters[kParam_OffsetX].ToFloat());

    data_020fdc14.output->unknown_3c_ = (int)(4096.0f * parameters[kParam_OffsetZ].ToFloat());

    return 1;
}
