#include <globaldefs.h>

// Overlay 17, originally SetByte1_021c1e34 (USA/EUR 0x021c1e34, JPN 0x021c23a8)
extern "C" ARM void FieldTask_EndBoardVehicle(unsigned char* p) {
	p[1] = 1;
}
