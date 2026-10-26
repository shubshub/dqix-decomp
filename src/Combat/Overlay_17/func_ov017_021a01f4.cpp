#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

extern int data_ov017_021d65f4[];
extern signed char data_ov017_021d65ec[];
extern short data_ov017_021d6618[];

extern Vector3i data_ov017_021d6600[];

extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);
extern "C" int func_02040528(int* obj);
extern "C" int func_ov017_0218dd18(void* arg0, void* entry, int flag);

// USA: func_ov017_021a01f4
extern "C" ARM int func_ov017_021a01f4(void* unused0, int id, int category, void* arg3, int* arg4) {
	int* p = data_ov017_021d65f4;
	for (int i = 0; *p != -1; p++, i++) {
		if (*p != id) continue;

		signed char var2 = data_ov017_021d65ec[i];
		if (var2 != category && var2 != 4) continue;

		void* globalPtr = func_0203cf4c();
		short* row = data_ov017_021d6618 + i * 8;

		while (*row != -1) {
			void* entryPtr = func_0203df78(globalPtr, *row);
			if (!entryPtr) { row++; continue; }

			int fieldVal = func_02040528((int*)entryPtr);
			if (!fieldVal) { row++; continue; }

			if (*((unsigned char*)fieldVal + 2) == 1) { row++; continue; }

			if (func_ov017_0218dd18(arg3, entryPtr, 0)) {
				*(Vector3i*)arg4 = data_ov017_021d6600[i];
				return 1;
			}

			row++;
		}
	}

	return 0;
}
