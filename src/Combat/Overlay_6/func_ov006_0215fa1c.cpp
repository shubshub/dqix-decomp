#include <globaldefs.h>

#if defined(jpn)
enum { kEntries = 0xc, Enum_ov006_0215fa1c_116 = 0x6c, Enum_ov006_0215fa1c_4 = 2 };
#else
enum { kEntries = 0x14, Enum_ov006_0215fa1c_116 = 0x74, Enum_ov006_0215fa1c_4 = 4 };
#endif

struct Struct_02080fa8;
struct Struct_02081164;
struct Struct_ov006_0215fa1c {
    char pad0[kEntries];
    Struct_02080fa8* entries;
    char pad18[Enum_ov006_0215fa1c_116-kEntries-4];
    int unknown_74_;
    char unknown_78_[0x366-Enum_ov006_0215fa1c_116-4];
    short command;
    char unknown_368_[0x38f-0x368];
    unsigned char mode;
};
extern "C" void func_02080b54(void*, int);
extern "C" void func_02080b40(void*, int);
extern "C" void func_0208103c(void*, int, int);
extern "C" void func_02080fa8(Struct_02080fa8*, int, int);
extern "C" void func_02081164(Struct_02081164*, int, int);
extern "C" void func_020806d8(void*, int, int, int, int);
extern "C" int func_ov006_02154138(int*);
extern "C" void func_020813ec(void*, int);

// USA: func_ov006_0215fa1c
extern "C" ARM void func_ov006_0215fa1c(Struct_ov006_0215fa1c* self, int arg1) {
    Struct_02080fa8* entries = self->entries;
    func_02080b54(entries, 0xd);
    func_02080b40(entries, 0x56);
    func_0208103c(self->entries, 0x56, 0x2b);
    if (self->mode != 10 && self->mode != 3) {
        int text = 0x2c;
        if (!arg1) {
            switch (self->command) {
            case 0x25: text = 0x12; break;
            case 0x26: text = 0x13; break;
            }
        }
        func_0208103c(entries, 0x57, text);
        func_02080b40(entries, 0x57);
        func_020806d8(entries, 0xd, 0x57, 1, Enum_ov006_0215fa1c_4);
        if (arg1) {
            unsigned int var2 = (unsigned short)func_ov006_02154138(&self->unknown_74_);
            float fraction = (float)var2 / 448.0f;
            fraction *= 10000.0f;
            int var4 = (int)fraction;
            int value = (var4 - var4 % 100) / 100;
            if (var2 && value <= 0) value = 1;
            if (value > 100) value = 100;
            func_02080fa8(entries, 0x58, value);
            func_02080b40(entries, 0x58);
            func_0208103c(self->entries, 0x56, 0x2e);
        }
    }
    func_02081164((Struct_02081164*)entries, 0xd, 1);
    func_020813ec(entries, 0xd);
}
