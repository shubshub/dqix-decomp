#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02079b94_60 = 52 };
#else
enum { Enum_02079b94_60 = 60 };
#endif

struct Struct_02079a58_2 {
    unsigned int value : 12;
};

// USA: func_02079b94
extern "C" ARM int func_02079b94(struct Struct_02079a58_2* obj) {
    return obj->value * Enum_02079b94_60;
}
