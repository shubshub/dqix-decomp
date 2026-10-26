#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

struct Struct_ov031_0224e540_5 { char pad[0x24]; int field24; };
extern struct Struct_ov031_0224e540_5 data_ov031_0224e540;
extern struct BlockedContextList data_ov031_0224e544;
extern "C" void func_ov031_0220dab4(void);

struct Struct_ov031_0220f28c { unsigned short type; unsigned short value; };

// USA: func_ov031_0220f28c
extern "C" ARM void func_ov031_0220f28c(struct Struct_ov031_0220f28c* msg) {
	if (msg->type != 0x12) return;
	data_ov031_0224e540.field24 = msg->value;
	if (msg->value == 0) {
		func_ov031_0220dab4();
	}
	UnblockContexts(&data_ov031_0224e544);
}
