#include <globaldefs.h>

extern "C" void func_0200961c(void* obj, unsigned char count);

struct Struct_020098fc {
    unsigned char unknown_0_;
    char pad1;
    unsigned short param2;
    unsigned char count;
    unsigned char digits[0x20];
};

// USA: func_020098fc
extern "C" ARM void func_020098fc(Struct_020098fc* obj, char* str, unsigned short val) {
    obj->param2 = val;
    obj->unknown_0_ = 0;
    int i = 0;
    while (i < 0x20 && *str != 0) {
        obj->digits[i] = *str++ - 0x30;
        i++;
    }
    obj->count = i;
    char c = *str;
    if (c == 0) return;
    if (c < 5) return;
    if (c > 5) goto callOther;
    {
        char next = str[1];
        str += 1;
        if (next != 0) {
            do {
                if (next != 0x30) goto callOther;
                next = *++str;
            } while (next != 0);
        }
    }
    if ((obj->digits[i - 1] & 1) == 0) return;
callOther:
    func_0200961c(obj, obj->count);
}
