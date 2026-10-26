#include <globaldefs.h>
#include "Resource/Brightness.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_02160cf8_572 = 0x124 };
enum { Enum_ov003_02160cf8_792 = 0x200 };
enum { Enum_ov003_02160cf8_920 = 0x280 };
enum { Enum_ov003_02160cf8_796 = 0x204 };
enum { Enum_ov003_02160cf8_1124 = 0x28c };
enum { Enum_ov003_02160cf8_924 = 0x284 };
enum { Enum_ov003_02160cf8_1192 = 0x2d0 };
enum { Enum_ov003_02160cf8_1128 = 0x290 };
#else
enum { Enum_ov003_02160cf8_572 = 0x23c };
enum { Enum_ov003_02160cf8_792 = 0x318 };
enum { Enum_ov003_02160cf8_920 = 0x398 };
enum { Enum_ov003_02160cf8_796 = 0x31c };
enum { Enum_ov003_02160cf8_1124 = 0x464 };
enum { Enum_ov003_02160cf8_924 = 0x39c };
enum { Enum_ov003_02160cf8_1192 = 0x4a8 };
enum { Enum_ov003_02160cf8_1128 = 0x468 };
#endif

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int bits);
extern "C" void func_ov003_02161438(void* obj);

struct Struct_ov003_02160cf8_2 {
	void* field0;
};

extern "C" void func_ov003_021672e4(struct Struct_ov003_02160cf8_2* view, int a, int b);
extern "C" void func_ov003_0216724c(struct Struct_ov003_02160cf8_2* view, SafeAllocator* alloc);
extern "C" int func_ov003_0216759c(struct Struct_ov003_02160cf8_2* view);

struct Struct_ov003_02160cf8 {
	char pad0[Enum_ov003_02160cf8_572];
	SafeAllocator unknown_23c_;
	char unknown_250_[Enum_ov003_02160cf8_792 - Enum_ov003_02160cf8_572 - sizeof(SafeAllocator)];
	struct Struct_ov003_02160cf8_2* view;
	char unknown_31c_[Enum_ov003_02160cf8_920 - Enum_ov003_02160cf8_796];
	void* unknown_398_;
	char unknown_39c_[Enum_ov003_02160cf8_1124 - Enum_ov003_02160cf8_924];
	unsigned int unknown_464_;
	char unknown_468_[Enum_ov003_02160cf8_1192 - Enum_ov003_02160cf8_1128];
	unsigned char state;
};

// USA: func_ov003_02160cf8
extern "C" ARM int func_ov003_02160cf8(struct Struct_ov003_02160cf8* self) {
	GameResources* res = GetGameResources();
	void* dataPtr = GlobalFlags_GetInstance();
	int result = 0;

	if (self->state == 0) {
		SetSubBrightness(res, -16, 8);
		self->state++;
	} else if (self->state == 1) {
		if (IsSubBrightnessTransitionActive(res) == 0) {
			FlagWord_SetBits((unsigned int*)dataPtr, 1);
			self->unknown_23c_.Reset();
			func_ov003_021672e4(self->view, 0, -1);
			self->view->field0 = self->unknown_398_;
			func_ov003_0216724c(self->view, &self->unknown_23c_);
			self->state++;
		}
	} else if (self->state == 2) {
		if (func_ov003_0216759c(self->view) != 0) {
			func_ov003_02161438(self);
			self->state++;
		}
	} else if (self->state == 3) {
		SetSubBrightness(res, 0, 8);
		self->state++;
	} else if (self->state == 4) {
		if (IsSubBrightnessTransitionActive(res) == 0) {
			self->state = 0;
			result = 1;
			self->unknown_464_ &= ~0x400;
		}
	}
	return result;
}
