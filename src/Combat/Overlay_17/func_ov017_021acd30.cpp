#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

extern "C" void func_ov017_021acd7c(void* p);
struct List02046a3c;
struct Node02046a3c;
extern "C" void func_02046a3c(List02046a3c*, Node02046a3c*);

// USA: func_ov017_021acd30
extern "C" ARM void func_ov017_021acd30(char* self, unsigned char a, unsigned char b, unsigned char c) {
	func_ov017_021acd7c(*(void**)(self + 0x3000 + RG(0xb20, 0x900)));
	((unsigned char*)(*(void**)(self + 0x3000 + RG(0xb20, 0x900))))[RG(0x27c, 0x20c)] = a;
	((unsigned char*)(*(void**)(self + 0x3000 + RG(0xb20, 0x900))))[RG(0x27d, 0x20d)] = b;
	((unsigned char*)(*(void**)(self + 0x3000 + RG(0xb20, 0x900))))[RG(0x27e, 0x20e)] = c;
	void* list = *(void**)(self + 0x3000 + RG(0x6fc, 0x4ec));
	func_02046a3c((List02046a3c*)list, (Node02046a3c*)(*(void**)(self + 0x3000 + RG(0xb20, 0x900))));
}
