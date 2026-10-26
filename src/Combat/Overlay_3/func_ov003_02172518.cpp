#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_02172518 func_ov003_021714f0
#endif

extern "C" void func_ov017_021d0ef8(int arg0, unsigned char* payload, int size, int offset, int* arg4);

struct Struct_ov003_021714f0 {
    char pad0[0x199];
    unsigned char unknown_199_;
#if defined(jpn)
    char unknown_19a_[0x19c - 0x19a];
    unsigned char unknown_1c0_[0xe0];
#else
    char unknown1_19a_[0x1c0 - 0x19a];
    unsigned char unknown_1c0_[0xe0];
    char unknown_2a0_[0x380 - 0x2a0];
    unsigned char unknown_380_[0xe0];
#endif
};

// USA: func_ov003_02172518
#if defined(jpn)
extern "C"
ARM void func_ov003_02172518(struct Struct_ov003_021714f0* obj) {
#else
extern "C" ARM void func_ov003_02172518(struct Struct_ov003_021714f0* obj, int flag) {
#endif
    unsigned int var0 = 0;
#if defined(jpn)
    unsigned char* payload = obj->unknown_1c0_;
#else
    unsigned char* payload = flag != 0 ? obj->unknown_1c0_ : obj->unknown_380_;
#endif
    int var2;

    while (var0 < sizeof(obj->unknown_1c0_)) {
        func_ov017_021d0ef8(obj->unknown_199_, payload, sizeof(obj->unknown_1c0_), var0, &var2);
        var0 += var2;
    }
}
