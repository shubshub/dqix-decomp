#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov017_0218d7fc(unsigned char* obj);
extern "C" void* func_020e2ff8(void);
extern "C" void func_020e3368(unsigned char* base, unsigned char val);

#if defined(jpn)
static const int kName=0x4136, kFlag=0x413b;
#else
static const int kName=0x4356, kFlag=0x435b;
#endif

// USA: func_ov017_0218d7b0
extern "C" ARM void func_ov017_0218d7b0(unsigned char* obj, char* name) {
	if (!name) return;
	func_ov017_0218d7fc(obj + kName);
	memcpy(obj + kName, name, 6);
	obj[kFlag] = 1;
	func_020e3368((unsigned char*)func_020e2ff8(), 1);
}
