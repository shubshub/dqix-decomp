#if defined(jpn)
#define R(j,u) (j)
#define func_ov015_0218e670 func_ov015_0218f290
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov015_0218e498;
extern "C" ARM void func_ov015_0218e498(struct Struct_ov015_0218e498* obj);
extern "C" ARM void func_ov015_0218e4f8(void* obj);
struct Struct_ov015_0218e574;
extern "C" ARM void func_ov015_0218e574(struct Struct_ov015_0218e574* obj);
struct Struct_ov015_0218e5c0;
extern "C" ARM void func_ov015_0218e5c0(struct Struct_ov015_0218e5c0* obj);
struct Struct_ov015_0218e60c_2;
extern "C" void func_ov015_0218e60c(struct Struct_ov015_0218e60c_2* obj);
extern "C" ARM void func_ov015_0218e670(void* obj);

struct Struct_ov015_0218f1c4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_;
};

// USA: func_ov015_0218f1c4
extern "C" ARM void func_ov015_0218f1c4(struct Struct_ov015_0218f1c4* obj) {
    switch (obj->unknown_1c_) {
    case 0:
        func_ov015_0218e498((struct Struct_ov015_0218e498*)obj);
        break;
    case 1:
        func_ov015_0218e4f8(obj);
        break;
    case 3:
        func_ov015_0218e574((struct Struct_ov015_0218e574*)obj);
        break;
    case 2:
        func_ov015_0218e5c0((struct Struct_ov015_0218e5c0*)obj);
        break;
    case 4:
        func_ov015_0218e60c((struct Struct_ov015_0218e60c_2*)obj);
        break;
    case 5:
        func_ov015_0218e670(obj);
        break;
    case 6:
        func_ov015_0218e670(obj);
        break;
    }
}
