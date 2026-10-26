#include <globaldefs.h>

struct Struct_ov031_022072d0 {
    unsigned char length;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned int address;
};

extern "C" int func_ov031_022058f0(int arg0, void* buffer, int length, unsigned short* arg3, unsigned int* address, int flags);

// USA: func_ov031_022072d0
extern "C" ARM int func_ov031_022072d0(int arg0, void* buffer, int length, int flags, void* from) {
    unsigned int address;
    unsigned short var1;
    int result = func_ov031_022058f0(arg0, buffer, length, &var1, &address, flags);
    if (result < 0) return result;
    if (from == NULL) return result;
    Struct_ov031_022072d0* output = static_cast<Struct_ov031_022072d0*>(from);
    unsigned int var4 = var1;
    output->unknown_2_ = ((int)var4 >> 8 & 0xff) | ((var4 << 8) & 0xff00);
    unsigned int var5 = address;
    output->address = ((var5 >> 24) & 0xff) | ((var5 >> 8) & 0xff00) | ((var5 << 8) & 0xff0000) | ((var5 << 24) & 0xff000000);
    return result;
}
