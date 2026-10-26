#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020d805c_336 = 0xf0 };
#else
enum { Enum_020d805c_336 = 0x150 };
#endif

struct BitFlags020d805c {
    char pad[Enum_020d805c_336];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_150_4_ : 1;
    unsigned char unknown_150_5_ : 1;
    unsigned char unknown_150_6_ : 1;
};

// USA: func_020d805c
extern "C" ARM int func_020d805c(struct BitFlags020d805c* obj) {
    return obj->unknown_150_6_;
}
