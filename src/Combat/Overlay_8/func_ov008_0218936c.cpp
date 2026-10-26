#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void Window_Update(void* obj);
extern "C" void func_ov008_021895a8(void* obj);
extern "C" void func_ov008_02189c70(void* obj);
extern "C" void func_ov008_0218af80(void* obj);
extern "C" void func_ov008_02184754(void* obj);
extern "C" void func_ov008_0218b084(void* obj);

struct Struct_ov008_0218936c {
    char pad[R(0xe95, 0xe99)];
    signed char unknown_e99_;
    signed char unknown_e9a_;
    signed char unknown_e9b_;
    char pad2[R(0xeb0 - 0xe98, 0xeb8 - 0xe9c)];
    unsigned char unknown_eb8_;
};

// USA: func_ov008_0218936c
extern "C" ARM unsigned char func_ov008_0218936c(Struct_ov008_0218936c* obj, unsigned int ticks) {
    Window_Update((char*)obj + 0x18);
    switch (obj->unknown_e99_) {
    case 0:
        func_ov008_021895a8(obj);
        break;
    case 1:
        func_ov008_02189c70(obj);
        break;
    case 2:
        obj->unknown_e9a_ = 0;
        break;
    }
    switch (obj->unknown_e9b_) {
    case 0:
        func_ov008_0218af80(obj);
        break;
    case 1:
        func_ov008_02184754((char*)obj + 0x2a8);
        break;
    case 2:
        func_ov008_0218b084(obj);
        break;
    }
    return obj->unknown_eb8_;
}
