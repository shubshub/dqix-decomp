#include <globaldefs.h>

struct Struct_020b0e6c;
struct Struct_020b0eb4;
struct Struct_020b1d70;

struct Struct_ov031_0223c8d4 { void* p0; unsigned short f2; unsigned short pad; };

extern char* data_ov031_02290d38;

extern "C" int func_020b0e6c(Struct_020b0e6c* obj, unsigned int key);
extern "C" void* func_020b0eb4(Struct_020b0eb4** slot, unsigned int key);
extern "C" int func_ov031_0223c898(Struct_020b1d70* arg0, int arg1, int arg2, int arg3, unsigned short arg4, int index);

// USA: func_ov031_0223c8d4
extern "C" ARM void func_ov031_0223c8d4(Struct_020b1d70* a, int b, int c, int d, int e, unsigned short* counts, int idx) {
	if (counts[0] == 0) return;
	do {
		Struct_ov031_0223c8d4* elem = (Struct_ov031_0223c8d4*)(data_ov031_02290d38 + idx * 8);
		unsigned int found = func_020b0e6c((Struct_020b0e6c*)elem, counts[0]);
		unsigned int val = found;
		if (found == 0xffff) {
			val = *(unsigned short*)((char*)elem->p0 + 2);
		}
		void* entry = func_020b0eb4((Struct_020b0eb4**)elem, val);
		unsigned short cnt = counts[0];
		signed char f2 = *((signed char*)entry + 2);
		int offset = b + ((e - f2) >> 1);
		func_ov031_0223c898(a, offset, c, d, cnt, idx);
		counts++;
		b += e;
	} while (*counts != 0);
}
