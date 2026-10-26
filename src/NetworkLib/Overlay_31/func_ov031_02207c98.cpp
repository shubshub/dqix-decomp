#include <globaldefs.h>

extern "C" int func_020cf0fc(int a);
extern "C" int RTC_GetTime(int a);
extern "C" long long func_020cf990(int arg0, unsigned char* arg1);

// USA: func_ov031_02207c98
extern "C" ARM int func_ov031_02207c98(void) {
	char buf[0x1c];
	func_020cf0fc((int)(buf + 0xc));
	RTC_GetTime((int)buf);
	return (int)func_020cf990((int)(buf + sizeof(buf) - 0x10), (unsigned char*)buf) + 0x386d4380;
}
