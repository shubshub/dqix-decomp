#include <globaldefs.h>

union ZoneTransitionVector { int words[3]; };
union ZoneTransitionVectors { int words[12]; };

struct ZoneTransitionSettings {
    unsigned short zoneId;
    unsigned char unknown2, unknown3, unknown4, unknown5, unknown6;
    unsigned char applyPosition;
    unsigned char unknown8, unknown9, unknownA;
    signed char unknownB;
    unsigned char unknownC, unknownD, unknownE;
    unsigned char paddingF;
    ZoneTransitionVector position;
    short heading, unknown1E;
    int unknown20, unknown24, unknown28, unknown2C;
    ZoneTransitionVectors unknown30;
    unsigned char unknown60, unknown61, unknown62, unknown63, unknown64;
    unsigned char unknown65, unknown66, unknown67, unknown68, unknown69;
    short unknown6A, nodeId;
    unsigned char unknown6E;
};

// Main, originally func_0200fbb4 (USA 0x0200fbb4, EUR 0x0200fbc4, JPN 0x0200fa10)
extern "C" ARM ZoneTransitionSettings* ZoneTransitionSettings_Copy(ZoneTransitionSettings* dst, const ZoneTransitionSettings* src) {
    dst->zoneId = src->zoneId;
    dst->unknown2 = src->unknown2;
    dst->unknown3 = src->unknown3;
    dst->unknown4 = src->unknown4;
    dst->unknown5 = src->unknown5;
    dst->unknown6 = src->unknown6;
    dst->applyPosition = src->applyPosition;
    dst->unknown8 = src->unknown8;
    dst->unknown9 = src->unknown9;
    dst->unknownA = src->unknownA;
    dst->unknownB = src->unknownB;
    dst->unknownC = src->unknownC;
    dst->unknownD = src->unknownD;
    dst->unknownE = src->unknownE;
    dst->position = src->position;
    dst->heading = src->heading;
    dst->unknown1E = src->unknown1E;
    dst->unknown20 = src->unknown20;
    dst->unknown24 = src->unknown24;
    dst->unknown28 = src->unknown28;
    dst->unknown2C = src->unknown2C;
    dst->unknown30 = src->unknown30;
    dst->unknown60 = src->unknown60;
    dst->unknown61 = src->unknown61;
    dst->unknown62 = src->unknown62;
    dst->unknown63 = src->unknown63;
    dst->unknown64 = src->unknown64;
    dst->unknown65 = src->unknown65;
    dst->unknown66 = src->unknown66;
    dst->unknown67 = src->unknown67;
    dst->unknown68 = src->unknown68;
    dst->unknown69 = src->unknown69;
    dst->unknown6A = src->unknown6A;
    dst->nodeId = src->nodeId;
    dst->unknown6E = src->unknown6E;
    return dst;
}
