#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Timing.h"

extern int data_ov031_0224e53c;
extern "C" int func_ov031_0220db28(void);

struct Struct_ov031_0220da1c {
	char pad[0x260];
	int state;
};

struct Struct_ov031_0220da1c_2 {
	char pad[0x2000];
	Struct_ov031_0220da1c sub;
};

// USA: func_ov031_0220da1c
extern "C" ARM void func_ov031_0220da1c(int arg0) {
	int state = DisableIRQInterrupts();
	if (*(int*)((char*)data_ov031_0224e53c + 0x2260) == 9 && arg0 != 9) {
		CancelAlarm((Alarm*)((char*)data_ov031_0224e53c + 0x22cc));
	}
	Struct_ov031_0220da1c_2* ctx = (Struct_ov031_0220da1c_2*)data_ov031_0224e53c;
	if (ctx->sub.state != 0xb) {
		ctx->sub.state = arg0;
	}
	if (arg0 == 9) {
		SetTimeout((Alarm*)((char*)data_ov031_0224e53c + 0x22cc), 0x22f5341, (Alarm::PFNCompletion)&func_ov031_0220db28, NULL);
	}
	SetIRQInterruptState(state);
}
