#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Memory.h"

struct Struct_ov031_02205b48_2 {
	unsigned char unknown_0_[0xf8];
	int unknown_f8_;
	unsigned char unknown_fc_[2];
	signed char unknown_fe_;
};

struct Struct_ov031_02205b48 {
	unsigned char unknown_0_[0x64];
	struct Struct_ov031_02205b48_2* counter;
	unsigned char pad68[8];
	short flags;
	unsigned char unknown_72_;
	signed char unknown_73_;
	unsigned short unknown_74_;
};

extern "C" void* func_ov031_02205c50(struct Struct_ov031_02205b48* ctx, int* available,
	unsigned short* tag, unsigned short* count, unsigned int* value);

// USA: func_ov031_02205b48
extern "C" ARM int func_ov031_02205b48(struct Struct_ov031_02205b48* ctx, void* dst,
	int length, unsigned short* outCount, unsigned int* arg4) {
	unsigned short tag;
	unsigned short count;
	int available;
	unsigned int value;
	int result;
	int var5 = DisableIRQInterrupts();
	void* src = func_ov031_02205c50(ctx, &available, &tag, &count, &value);

	if (src != NULL) {
		int size = available;
		if (size == 0) {
			result = -6;
		} else {
			signed char var8 = ctx->unknown_73_;
			int var9 = 1;
			if (length > size) {
				length = size;
			}
			if (var8 != 0 && var8 != 4) {
				var9 = 0;
			}
			if (var9) {
				size = length;
			}
			VectorizedInvertedMemcpy(src, dst, length);
			struct Struct_ov031_02205b48_2* counter = ctx->counter;
			if (counter->unknown_fe_ == 0) {
				counter->unknown_f8_ = counter->unknown_f8_ + size;
			}
			result = size;
		}
	} else {
		result = (available == 0) ? 0 : -28;
		ctx->flags = ctx->flags & ~6;
	}

	if (result >= 0) {
		if (outCount != NULL && arg4 != NULL) {
			*outCount = count;
			*arg4 = value;
		}
		if (ctx->unknown_74_ == 0) {
			ctx->unknown_74_ = tag;
		}
	}
	SetIRQInterruptState(var5);
	return result;
}
