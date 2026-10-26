#include <globaldefs.h>

struct Struct_ov031_0220a594_2 {
	unsigned char pad0[0x456];
	unsigned char unknown_456_;
	unsigned char pad1[0x824 - 0x456 - 1];
	void* unknown_824_;
	int unknown_828_;
	int unknown_82c_;
};
struct Struct_ov031_0220a594 { unsigned char pad[0xc]; Struct_ov031_0220a594_2* ctx; };

extern "C" ARM int func_ov031_02209840(void* dst, int remaining, void* session);
extern "C" void func_ov031_022098d8(Struct_ov031_0220a594_2* ctx, void* p);
extern "C" int func_ov031_02209b58(Struct_ov031_0220a594* session);
extern void* data_ov031_0224c9c0;

// USA: func_ov031_0220a594
extern "C" ARM void* func_ov031_0220a594(int* out, Struct_ov031_0220a594* session) {
	Struct_ov031_0220a594_2* ctx = session->ctx;
	if (ctx->unknown_824_ != NULL && ctx->unknown_456_ == 0) {
		int var1 = ctx->unknown_82c_;
		int total = ctx->unknown_828_;
		int r = func_ov031_02209840((char*)ctx->unknown_824_ + var1, total - var1, session);
		if (r != 0) {
			void (*cb)(void*) = *(void (**)(void*))&data_ov031_0224c9c0;
			cb(ctx->unknown_824_);
			ctx->unknown_824_ = NULL;
			*out = 0;
			return NULL;
		}
		func_ov031_022098d8(ctx, ctx->unknown_824_);
		if (ctx->unknown_456_ == 0) {
			ctx->unknown_824_ = NULL;
		}
	}
	if (ctx->unknown_824_ == NULL) {
		while (1) {
			int st = func_ov031_02209b58(session);
			if (st == 9) {
				*out = 0;
				return NULL;
			}
			if (ctx->unknown_824_ != NULL) break;
		}
	}
	*out = ctx->unknown_828_ - ctx->unknown_82c_;
	return (char*)ctx->unknown_824_ + ctx->unknown_82c_;
}
