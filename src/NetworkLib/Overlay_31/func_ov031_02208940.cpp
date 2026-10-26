#include <globaldefs.h>

extern "C" void* VectorizedInvertedMemcpy(void* src, void* dst, int n);
extern "C" int memcmp(void* a, void* b, int n);
extern "C" void func_ov031_02207c30(void* obj);

// USA: func_ov031_02208940
extern "C" ARM void func_ov031_02208940(unsigned char* work, unsigned char* packet) {
	VectorizedInvertedMemcpy(packet + 2, work + 0x54, 0x20);
	int resumed = work[0x30];
	int idLen = packet[0x22];
	packet += 0x23;
	if (resumed != 0 && idLen == 0x20 && memcmp(work + 0x74, packet, 0x20) == 0) {
		work[0x31] = 1;
	} else {
		if (resumed != 0) {
			func_ov031_02207c30(work);
		}
		if (idLen != 0) {
			VectorizedInvertedMemcpy(packet, work + 0x74, 0x20);
			work[0x30] = 1;
		} else {
			work[0x30] = 0;
		}
		work[0x31] = 0;
	}
	packet += idLen;
	*(unsigned short*)(work + 0x32) = (packet[0] << 8) + packet[1];
	work[0x455] = 2;
}
