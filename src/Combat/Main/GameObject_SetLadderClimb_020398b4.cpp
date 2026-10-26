#include <globaldefs.h>
#include "Combat/ActorAction.h"

#if defined(jpn)
enum { Enum_020398b4_620 = 0x260 };
#else
enum { Enum_020398b4_620 = 0x26c };
#endif

// Main, originally CopyBlockTo0x26c_020398b4 (USA 0x020398b4, EUR 0x020398c4, JPN 0x0203930c)
extern "C" ARM void GameObject_SetLadderClimb(GameObject* obj, SubBlock02038508* src) {
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->active = src->active;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->command = src->command;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown2 = src->unknown2;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->reversed = src->reversed;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown4 = src->unknown4;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->heading = src->heading;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->startHeading = src->startHeading;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->endHeading = src->endHeading;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->start = src->start;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->end = src->end;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown24 = src->unknown24;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->startControl = src->startControl;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->endControl = src->endControl;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown48 = src->unknown48;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown4c = src->unknown4c;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown50 = src->unknown50;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown52 = src->unknown52;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown53 = src->unknown53;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown54 = src->unknown54;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->startNode = src->startNode;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->endNode = src->endNode;
    ((SubBlock02038508*)((char*)obj + Enum_020398b4_620))->unknown60 = src->unknown60;
}
