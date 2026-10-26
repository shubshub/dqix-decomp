#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021972f8_17592 = 0x4208 };
#else
enum { Enum_ov017_021972f8_17592 = 0x44b8 };
#endif

struct Struct_ov017_021972f8 {
    unsigned short entries[4];
    unsigned char unknown_8_;
};

struct Struct_ov017_021972f8_2 {
    unsigned char unknown0[Enum_ov017_021972f8_17592];
    Struct_ov017_021972f8 buffer;
};

// USA: func_ov017_021972f8
extern "C" ARM void func_ov017_021972f8(void *obj, unsigned short val) {
	Struct_ov017_021972f8_2* owner = (Struct_ov017_021972f8_2*)obj;
	unsigned char slot = owner->buffer.unknown_8_++;
	owner->buffer.entries[slot] = val;
	owner->buffer.unknown_8_ &= 3;
}
