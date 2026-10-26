#include <globaldefs.h>

struct Struct_02012050 {
#if defined(jpn)
    char unk[0x6175];
#else
    char unk[0x63D5];
#endif
    unsigned char field;
};

// USA: func_02012050
extern "C" ARM void func_02012050(struct Struct_02012050* obj) {
    obj->field = 0;
}
