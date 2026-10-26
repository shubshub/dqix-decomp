#include <globaldefs.h>

struct Struct_0207fd88;
extern "C" void func_0207fd88(struct Struct_0207fd88* obj);

// USA: func_ov003_0216757c
extern "C" ARM void func_ov003_0216757c(char* obj) {
#if defined(jpn)
    enum { flagOffset = 0x44 };
#else
    enum { flagOffset = 0x74 };
#endif
	if (*(unsigned char*)(obj + flagOffset) != 0) {
		struct Struct_0207fd88* p = *(struct Struct_0207fd88**)(obj + 0x10);
		if (p != 0) func_0207fd88(p);
	}
}
