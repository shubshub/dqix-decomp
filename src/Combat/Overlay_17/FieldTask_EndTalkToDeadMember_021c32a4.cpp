#include <globaldefs.h>

// Overlay 17, originally SetByte1_021c32a4 (USA/EUR 0x021c32a4, JPN 0x021c3780)
ARM void FieldTask_EndTalkToDeadMember(unsigned char* p) {
	p[1] = 1;
}
