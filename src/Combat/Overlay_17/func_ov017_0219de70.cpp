#include <globaldefs.h>

extern "C" void func_ov017_021a0790(char* obj);
extern "C" void func_ov017_021a0964(char* obj);
extern "C" void func_ov017_021a0ba8(char* obj);
extern "C" void func_ov017_021a0f40(char* obj);
extern "C" void func_ov017_021a1114(char* obj);
extern "C" void func_ov017_021a0d6c(char* obj);

extern "C" void func_ov017_021a0630(char* obj);
extern "C" void func_ov017_021a07f4(char* obj);
extern "C" void func_ov017_021a09c8(char* obj);
extern "C" void func_ov017_021a0c0c(char* obj);
extern "C" void func_ov017_021a0dd0(char* obj);
extern "C" void func_ov017_021a0fa4(char* obj);

extern "C" void func_020a1de4();
extern "C" void func_020a1edc();
extern "C" void func_020a1df8(int id);
extern "C" void func_020a1ef0(int id);

struct Struct_ov017_0219de70 {
	char pad[0xc];
	unsigned char val:4;
	unsigned char rest:4;
};

// USA: func_ov017_0219de70
extern "C" ARM void func_ov017_0219de70(char* obj, void* unused, Struct_ov017_0219de70* src) {
	int val = src->val;
	int var1;
	if ((unsigned int)(val - 2) <= 1) var1 = 0;
	else if (val == 5) var1 = 2;
	else if (val == 6) var1 = 3;
	else if (val == 7) var1 = 4;
	else if (val == 8) var1 = 5;
	else var1 = 1;

#if defined(jpn)
	if (*(int*)(obj + 0x2000 + 0x8f8) == var1) return;
#else
	if (*(int*)(obj + 0x2000 + 0xb08) == var1) return;
#endif

#if defined(jpn)
	switch (*(int*)(obj + 0x2000 + 0x8f8)) {
#else
	switch (*(int*)(obj + 0x2000 + 0xb08)) {
#endif
	case 0: func_ov017_021a0790(obj); break;
	case 1: func_ov017_021a0964(obj); break;
	case 3: func_ov017_021a0f40(obj); break;
	case 4: func_ov017_021a1114(obj); break;
	case 2: func_ov017_021a0ba8(obj); break;
	case 5: func_ov017_021a0d6c(obj); break;
	}

#if defined(jpn)
	*(int*)(obj + 0x2000 + 0x8f8) = var1;
#else
	*(int*)(obj + 0x2000 + 0xb08) = var1;
#endif

	switch (var1) {
	case 0: func_ov017_021a0630(obj); break;
	case 1: func_ov017_021a07f4(obj); break;
	case 3: func_ov017_021a0dd0(obj); break;
	case 4: func_ov017_021a0fa4(obj); break;
	case 2: func_ov017_021a09c8(obj); break;
	case 5: func_ov017_021a0c0c(obj); break;
	}

	func_020a1de4();
	func_020a1edc();

#if defined(jpn)
	int s = *(int*)(obj + 0x2000 + 0x8f8);
#else
	int s = *(int*)(obj + 0x2000 + 0xb08);
#endif
	if (s == 0 || s == 2 || s == 5) {
		func_020a1df8(3);
		func_020a1ef0(1);
	} else if (s == 1) {
		func_020a1df8(0);
		func_020a1ef0(1);
	}
}
