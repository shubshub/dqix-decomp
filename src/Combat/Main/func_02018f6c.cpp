#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02018f6c_1092 = 0x464 };
#else
enum { Enum_02018f6c_1092 = 0x444 };
#endif

struct Struct_02018f6c { unsigned int words[12]; };
struct Struct_02018f6c RotationMatrixY(int angle);

struct Struct_02018f6c_2 {
    char pad0[Enum_02018f6c_1092];
    unsigned int block[12];
    short flag;
};

// USA: func_02018f6c
extern "C" ARM void func_02018f6c(struct Struct_02018f6c_2* obj, short arg) {
    struct Struct_02018f6c buf;
    short flag;
    obj->flag = arg;
    flag = obj->flag;
    if (flag != 0) {
        buf = RotationMatrixY(flag);
        *(struct Struct_02018f6c*)obj->block = buf;
    }
}
