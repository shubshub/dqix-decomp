#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int* func_020936f8(void);
struct Struct_0209494c;
extern "C" int func_0209494c(struct Struct_0209494c* obj);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void LinkSession_End(void* obj);
extern "C" void func_ov017_02195748(unsigned char* base);
extern "C" void func_ov017_02192594(unsigned char* base);
extern "C" void func_020939fc(unsigned char* obj);
struct BitArrayObj0205e854;
extern "C" void* func_0205e854(struct BitArrayObj0205e854* obj);

struct Struct_ov017_021af4ec {
	unsigned char pad0;
	unsigned char field1;
	unsigned char pad2[6];
	unsigned char field8;
	unsigned char pad3[6];
	unsigned char unknown_f_;
};

// USA: func_ov017_021af4ec
extern "C" ARM unsigned char func_ov017_021af4ec(Struct_ov017_021af4ec* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x40c3, regionalOffset1=0x40c2};
#else
 enum {regionalOffset0=0x42e3, regionalOffset1=0x42e2};
#endif
	unsigned int* p = (unsigned int*)GlobalFlags_GetInstance();
	struct Struct_0209494c* g = (struct Struct_0209494c*)func_020936f8();
	if (func_0209494c(g)) {
		FlagWord_SetBits(p, 0x20);
		int f = (int)GetGameResources();
		void* a = LinkSession_GetInstance();
		struct BitArrayObj0205e854* d = (struct BitArrayObj0205e854*)LinkMessageQueue_GetInstance();
		obj->unknown_f_ = 0;
		SetFlags00((GameResources*)f, 2);
		LinkSession_End(a);
		func_ov017_02195748((unsigned char*)f);
		func_ov017_02192594((unsigned char*)f);
		func_020939fc((unsigned char*)g);
		func_0205e854(d);
		ClearFlags00((GameResources*)f, 0x40);
		((unsigned char*)f)[regionalOffset0] = 0;
		((unsigned char*)f)[regionalOffset1] = 0;
		obj->field1 = 1;
	}
	return obj->field8;
}
