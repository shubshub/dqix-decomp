#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_0219735c_17592 = 0x4208 };
#else
enum { Enum_ov017_0219735c_17592 = 0x44b8 };
#endif

struct Struct_ov017_021972f8 {
    unsigned short entries[4];
    unsigned char unknown_8_;
};

// USA: func_ov017_0219735c
extern "C" ARM int func_ov017_0219735c(unsigned char* obj, unsigned short key) {
	Struct_ov017_021972f8* buffer = (Struct_ov017_021972f8*)(obj + Enum_ov017_0219735c_17592);
	unsigned short* entry = buffer->entries;
	for (int i = 0; i < 4; i++, entry++) {
		if (*entry == key) {
			return 1;
		}
	}
	return 0;
}
