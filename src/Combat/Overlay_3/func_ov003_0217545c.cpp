#include <globaldefs.h>

struct Struct_0207fdcc_2;
struct Struct_0207fdcc;
extern "C" Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" int WindowPane_IsReady(unsigned char* obj);
extern "C" void func_ov003_02173f08(char* out1, char* out2, char* out3, char* arg3);
extern "C" void func_ov003_0217585c(void* obj, int a, int b, int idx, unsigned char c);

// USA: func_ov003_0217545c
extern "C" ARM void func_ov003_0217545c(void* obj) {
	struct Struct_0207fdcc_2* o;
	struct Struct_0207fdcc* elem;
	short var2;
	short var3;
	char out1, out2, out3, var7;
	short var8;

#if defined(jpn)
    enum { entriesOffset = 0x818 };
#else
    enum { entriesOffset = 0x89c };
#endif
	o = *(struct Struct_0207fdcc_2**)((char*)obj + entriesOffset);
	elem = func_02081da8(o, 10);
	if (elem == NULL) return;
	if (!WindowPane_IsReady((unsigned char*)elem)) return;

	var2 = *(short*)((char*)elem + 0xae);
	var3 = *(short*)((char*)elem + 0xac);

#if defined(jpn)
    out1 = 8;
    out2 = 0x41;
#else
	func_ov003_02173f08(&out1, &out2, &out3, &var7);
#endif

	{
		short var9 = var2 << 3;
		var8 = (short)(var9 + 0x22);
		short var10 = var3 << 3;
		func_ov003_0217585c(obj, out1 + var10, var8, 0x1a, 0x78);
		func_ov003_0217585c(obj, out2 + var10, var8, 0x1b, 0x7a);
	}
}
