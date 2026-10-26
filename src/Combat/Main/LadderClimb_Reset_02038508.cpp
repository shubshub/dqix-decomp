#include <globaldefs.h>
#include "Combat/ActorAction.h"

// Main, originally InitBlock02038508 (USA 0x02038508, EUR 0x02038518, JPN 0x02037f60)
ARM void LadderClimb_Reset(struct SubBlock02038508* ladderClimb) {
    ladderClimb->active = 0;
    ladderClimb->command = 0;
    ladderClimb->unknown2 = 0;
    ladderClimb->reversed = 0;
    ladderClimb->unknown4 = 0;
    ladderClimb->heading = 0;
    ladderClimb->startHeading = 0;
    ladderClimb->endHeading = 0;
    ladderClimb->unknown48 = 0;
    ladderClimb->unknown4c = 0;
    ladderClimb->unknown50 = 0;
    ladderClimb->unknown52 = 0;
    ladderClimb->unknown53 = 1;
    ladderClimb->unknown54 = 0x64;
    ladderClimb->startNode = 0;
    ladderClimb->endNode = 0;
    ladderClimb->unknown60 = 0;
    ladderClimb->start.entries[0] = 0; ladderClimb->start.entries[1] = 0; ladderClimb->start.entries[2] = 0;
    ladderClimb->end.entries[0] = 0; ladderClimb->end.entries[1] = 0; ladderClimb->end.entries[2] = 0;
    ladderClimb->unknown24.entries[0] = 0; ladderClimb->unknown24.entries[1] = 0; ladderClimb->unknown24.entries[2] = 0;
    ladderClimb->startControl.entries[0] = 0; ladderClimb->startControl.entries[1] = 0; ladderClimb->startControl.entries[2] = 0;
    ladderClimb->endControl.entries[0] = 0; ladderClimb->endControl.entries[1] = 0; ladderClimb->endControl.entries[2] = 0;
}
