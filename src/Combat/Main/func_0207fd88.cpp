#include <globaldefs.h>

extern "C" void Background_TransferMap(void* p, int flag);

struct Struct_0207fd88_2 { char b[0x20]; };

struct Struct_0207fd88 {
    #if defined(jpn)
    char pad0[0x20];
#else
    char pad0[0x2c];
#endif
    Struct_0207fd88_2* unknown_2c_;
    char unknown_30_[0x38 - 0x30];
    unsigned char unknown_38_;
};

// USA: func_0207fd88
extern "C" ARM void func_0207fd88(Struct_0207fd88* obj) {
    unsigned char count;
    Struct_0207fd88_2* p = obj->unknown_2c_;
    unsigned char i;
    if (p == NULL) return;
    count = obj->unknown_38_;
    for (i = 0; i < count; i++) {
        Background_TransferMap(p, 0);
        p++;
    }
}
