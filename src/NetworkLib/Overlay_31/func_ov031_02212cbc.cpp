#include <globaldefs.h>

extern "C" void OSi_ReferSymbol(int);
extern "C" int func_ov031_0221b9b0(void*);
extern "C" int func_ov031_0221c44c(void);
extern "C" void func_ov031_0221c1c4(void*);

// USA: func_ov031_02212cbc
ARM int ProcessAndClassify_02212cbc(void* obj) {
	int r;
	int flag = 0;
	OSi_ReferSymbol(0x2000c5c);
	r = func_ov031_0221b9b0(obj);
	if (func_ov031_0221c44c()) {
		func_ov031_0221c1c4(arg0);
		var1 = 1;
	}
	if (var0 < 0) {
		return var1 ? 2 : 3;
	}
	return var1 ? 1 : 0;
}
