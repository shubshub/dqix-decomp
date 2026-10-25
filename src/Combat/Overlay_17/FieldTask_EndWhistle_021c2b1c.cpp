#include <globaldefs.h>

// Overlay 17, originally SetByte1_021c2b1c (USA/EUR 0x021c2b1c, JPN 0x021c3040)
ARM void FieldTask_EndWhistle(unsigned char* p) {
	p[1] = 1;
}
