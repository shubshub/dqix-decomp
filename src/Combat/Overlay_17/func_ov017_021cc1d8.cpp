#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov017_021cc1d8_2 { unsigned char pad0[4]; unsigned char unknown_4_; unsigned char pad1[3]; int val; };
struct Tgt_021cc1d8 { unsigned char pad[0xf]; unsigned char unknown_f_; signed char unknown_10_; };

// USA: func_ov017_021cc1d8
extern "C" ARM void func_ov017_021cc1d8(int unused0, Struct_ov017_021cc1d8_2* src, int arg2, GameResources* base) {
	Tgt_021cc1d8* tgt = (Tgt_021cc1d8*)base->fieldTasks_[12];
	if (tgt->unknown_10_ == src->unknown_4_) {
		tgt->unknown_f_ = (unsigned char)src->val;
	}
}
