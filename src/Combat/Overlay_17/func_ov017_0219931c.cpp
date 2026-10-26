#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_0219931c_1720 = 0x4a8, Enum_ov017_0219931c_2840 = 0x8f8, Enum_ov017_0219931c_1724 = 0x4ac, Enum_ov017_0219931c_1788 = 0x4ec };
#else
enum { Enum_ov017_0219931c_1720 = 0x6b8, Enum_ov017_0219931c_2840 = 0xb18, Enum_ov017_0219931c_1724 = 0x6bc, Enum_ov017_0219931c_1788 = 0x6fc };
#endif

struct TailList020469b4;
struct TailNode020469b4;
struct Struct_ov017_0219931c;
struct Struct_ov017_0219931c_2;

extern "C" void func_ov017_021ac2ec(Struct_ov017_0219931c* p);
extern "C" void func_ov017_021aca14(Struct_ov017_0219931c_2* obj, int val);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_0219931c
extern "C" ARM void func_ov017_0219931c(char* obj) {
	if (*(unsigned char*)(obj + 0x3000 + Enum_ov017_0219931c_1720) == 0) {
		return;
	}
	char* base = obj + 0x3000;
	Struct_ov017_0219931c* node = *(Struct_ov017_0219931c**)(base + Enum_ov017_0219931c_2840);
	func_ov017_021ac2ec(node);
	func_ov017_021aca14(*(Struct_ov017_0219931c_2**)(obj + 0x3000 + Enum_ov017_0219931c_2840), *(int*)(obj + 0x3000 + Enum_ov017_0219931c_1724));
	func_020469b4(*(TailList020469b4**)(obj + 0x3000 + Enum_ov017_0219931c_1788), *(TailNode020469b4**)(obj + 0x3000 + Enum_ov017_0219931c_2840));
}
