#include <globaldefs.h>

extern "C" int func_ov031_02207180(void* v);
extern "C" int func_ov031_02205814(void* obj);
extern int data_ov031_022496a8;

// USA: func_ov031_0220572c
extern "C" ARM int func_ov031_0220572c(void* obj, short arg1, int arg2) {
	if (func_ov031_02207180(obj) != 0) {
		goto errorNeg28;
	}
	if ((*(volatile short*)((char*)obj + 0x70) & 8) == 0) {
		goto continueBody;
	}
errorNeg28:
	return -28;
continueBody:
	;
	int flag1 = 0;
	if (obj == 0) goto checkFlag1;
	if (!(*(volatile short*)((char*)obj + 0x70) & 1)) goto checkFlag1;
	flag1 = 1;
checkFlag1:
	if (!flag1) {
		return -39;
	}
	signed char val = *(signed char*)((char*)obj + 0x73);
	int cond = 1;
	if (val != 0 && val != 4) cond = 0;
	if (!cond) goto storeAndReturn0;
	if ((*(volatile short*)((char*)obj + 0x70) & 4) != 0) {
		return (*(signed char*)((char*)obj + 0x72) == 1) ? -30 : 0;
	}
	if ((*(volatile short*)((char*)obj + 0x70) & 2) != 0) {
		if ((*(volatile short*)((char*)obj + 0x70) & 0x40) != 0) {
			return *(int*)((char*)obj + 0x6c);
		}
		return data_ov031_022496a8;
	}
	*(short*)((char*)obj + 0x76) = arg1;
	*(int*)((char*)obj + 0x78) = arg2;
	int result = func_ov031_02205814(obj);
	if (*(signed char*)((char*)obj + 0x72) != 1) {
		result = -26;
	}
	return result;

storeAndReturn0:
	*(short*)((char*)obj + 0x76) = arg1;
	*(int*)((char*)obj + 0x78) = arg2;
	return 0;
}
