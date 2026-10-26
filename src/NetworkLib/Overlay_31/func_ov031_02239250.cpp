#include <globaldefs.h>

struct Struct_ov031_02239250 { unsigned short h0; unsigned short flags2; unsigned char pad[8]; unsigned short hc; };
extern struct Struct_ov031_02239250* data_ov031_02290d14;

// USA: func_ov031_02239250
extern "C" ARM void* func_ov031_02239250(int bit) {
	struct Struct_ov031_02239250* hdr = data_ov031_02290d14;
	if (!(hdr->flags2 & (1 << bit))) return NULL;
	return (char*)hdr + 0xe + (bit - 1) * 0x1e;
}
