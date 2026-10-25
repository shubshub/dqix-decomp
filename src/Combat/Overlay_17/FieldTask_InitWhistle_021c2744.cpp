#include <globaldefs.h>
#include "World/FieldTask.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

// Overlay 17, originally InitState69_021c2744 (USA/EUR 0x021c2744, JPN 0x021c2cb0)
ARM void FieldTask_InitWhistle(WhistleTask* p) {
	ResetByteHeader((ByteHeader0204693c*)p);
	p->kind = FieldTaskKind_Whistle;
	p->step = 0;
	p->timer = 0x7d0;
	p->silent = 0;
	p->partyMember = 0;
	p->monsterId = -1;
	p->summonedId = 0;
	p->summonedIndex = 0;
}
