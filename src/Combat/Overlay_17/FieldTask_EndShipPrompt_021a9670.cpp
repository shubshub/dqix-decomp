#include <globaldefs.h>

// Overlay 17, originally SetByte1_021a9670 (USA/EUR 0x021a9670, JPN 0x021a9e44)
extern "C" ARM void FieldTask_EndShipPrompt(unsigned char* p) {
	p[1] = 1;
}
