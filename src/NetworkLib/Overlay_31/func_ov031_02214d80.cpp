#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" unsigned long long _ll_udiv(unsigned long long arg0, unsigned int arg1, unsigned int flag);
extern "C" int func_ov031_02214fc8(void* obj, int mode);
extern "C" int func_ov031_022151b0(void*, void*, int, int);

struct Struct_ov031_02214d80 { unsigned char pad : 7; unsigned char active : 1; };

// USA: func_ov031_02214d80
extern "C" ARM int func_ov031_02214d80(char* obj) {
	unsigned long long diff = GetCurrentTimestamp() - *(unsigned long long*)(obj + 0xcb0);
	unsigned long long var1 = _ll_udiv(diff << 6, 0x82ea, 0);
	if (var1 < 150) {
		unsigned int idx = *(unsigned char*)(obj + 0xd0f);
		Struct_ov031_02214d80* f = (Struct_ov031_02214d80*)(obj + 0x447 + idx * 4);
		if (f->active != 1) goto ret4;
	}

	{
		unsigned int idx = *(unsigned char*)(obj + 0xd0f);
		unsigned char* p = (unsigned char*)(obj + 0x447 + idx * 4);
		*p = *p | 0x80;
	}

	{
		unsigned int idx;
		unsigned int limit;
		limit = *(unsigned char*)(obj + 0xd12);
		idx = *(unsigned char*)(obj + 0xd0f);
		if (idx < limit) {
			do {
				Struct_ov031_02214d80* f = (Struct_ov031_02214d80*)(obj + 0x447 + idx * 4);
				if (f->active == 0) break;
				idx = *(unsigned char*)(obj + 0xd0f) + 1;
				*(unsigned char*)(obj + 0xd0f) = idx;
				limit = *(unsigned char*)(obj + 0xd12);
				idx &= 0xff;
			} while (idx < limit);
		}
		if (limit <= idx) {
			obj[0xd0f] = 0;
			return func_ov031_02214fc8(obj, 4);
		}
	}

	*(unsigned long long*)(obj + 0xcb0) = GetCurrentTimestamp();
	{
		int idx = *(unsigned char*)(obj + 0xd0f);
		unsigned short duration = *(unsigned short*)(obj + 0x4a6 + idx * 0xc0);
		func_ov031_022151b0(obj + 0x474 + idx * 0xc0, obj + 0x47c + idx * 0xc0, duration - 1, 0x300000);
	}
ret4:
	return 4;
}
