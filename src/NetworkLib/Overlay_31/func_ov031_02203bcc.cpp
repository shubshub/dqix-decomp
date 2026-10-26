#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

extern "C" unsigned long long GetCurrentTimestamp(void);
extern "C" void func_ov031_02200ccc(int a);
extern "C" int func_ov031_02200160(int a);

struct Struct_ov031_0224c980_11 {
	unsigned char field0;
	unsigned char field1;
	char pad18[0x18 - 2];
	void (*field18)(void);
	char unknown_1c_[0x48 - 0x1c];
	int (*field48)(void);
	char unknown_4c_[0x50 - 0x4c];
	int unknown_50_;
};

extern Struct_ov031_0224c980_11 data_ov031_0224c980;

// USA: func_ov031_02203bcc
extern "C" ARM int func_ov031_02203bcc(void) {
	data_ov031_0224c980.field18();
	int var0 = data_ov031_0224c980.unknown_50_;
	if (var0 == 0) {
		return var0;
	}
	func_ov031_02200ccc(data_ov031_0224c980.unknown_50_);
	SleepCurrentContext(0x64);
	func_ov031_02200ccc(data_ov031_0224c980.unknown_50_);
	unsigned int var1 = (unsigned int)(GetCurrentTimestamp() >> 16);
	goto checkExit;
retry:
	if (data_ov031_0224c980.field1 != 0) {
		return func_ov031_02200160(4);
	}
	SleepCurrentContext(0x64);
checkExit:
	{
		int r = data_ov031_0224c980.field48();
		if (r == 0) {
			return r;
		}
	}
	{
		unsigned int diff = (unsigned int)(GetCurrentTimestamp() >> 16) - var1;
		if ((int)diff < 0x17) {
			goto retry;
		}
		return diff;
	}
}
