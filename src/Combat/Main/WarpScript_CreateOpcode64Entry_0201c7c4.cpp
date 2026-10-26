#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// The instruction's parameters: node id, position (3), .bmdj name, then two optional strings
enum {
    kParamsWithString20 = 6,
    kParamsWithString30 = 7,
};

// Main, originally WarpScript_Opcode_65_0201c7c4 (USA 0x0201c7c4, EUR 0x0201c7d4, JPN 0x0201c550)
ARM int WarpScript_CreateOpcode64Entry(Script::Parameter *params, int numParams) {
    const char* string20;
    const char* string30;
    int nodeId;
    Vector3fix position;
    Script::Parameter *next;
    const char* bmdjName;

    nodeId = params->ToInt();
    next = params[1].ToVec3fix(&position);
    params = next + 1;
    bmdjName = next->ToString();
    string20 = NULL;
    string30 = NULL;
    if (numParams >= kParamsWithString20) {
        string20 = params->ToString();
        params++;
    }
    if (numParams >= kParamsWithString30) {
        string30 = params->ToString();
    }
    if (bmdjName == NULL) return 0;

    {
        ZoneFeatures::Opcode64Entry entry;
        entry.unk_0 = nodeId;
        entry.vector_4.vec = position;
        strcpy(entry.string_10, bmdjName);
        if (string20 == NULL) entry.string_20[0] = 0; else strcpy(entry.string_20, string20);
        if (string30 == NULL) entry.string_30[0] = 0; else strcpy(entry.string_30, string30);
        data_020fdc20.warp->CreateOpcode64Entry(entry);
    }
    return 1;
}
