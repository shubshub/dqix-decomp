#include <globaldefs.h>

struct Struct_0203dce4_2;
struct Struct_0203dce4;
extern "C" void* func_0203cf4c(void);
extern "C" Struct_0203dce4* func_0203dce4(Struct_0203dce4_2* list, int id);

struct Struct_02065758 {
    #if defined(jpn)
    unsigned char pad0[0x1708];
#else
    unsigned char pad0[0x1838];
#endif
    int id;
    #if defined(jpn)
    unsigned char pad1[0x1787 - 0x1708 - 4];
#else
    unsigned char pad1[0x1959 - 0x1838 - 4];
#endif
    unsigned char counter;
    #if defined(jpn)
    unsigned char pad2[0x17e7 - 0x1787 - 1];
#else
    unsigned char pad2[0x19b7 - 0x1959 - 1];
#endif
    unsigned char unknown_19b7_;
};

// USA: func_02065758
extern "C" ARM int func_02065758(Struct_02065758* a, int b) {
    Struct_0203dce4* entry;
    int result;
    unsigned char var2;

    entry = func_0203dce4((Struct_0203dce4_2*)func_0203cf4c(), a->id);
    if (entry == NULL) {
        return 0;
    }
    if (a->unknown_19b7_ == 0) {
        return 0;
    }
    var2 = (unsigned char)b;
    result = 1;
    if (a->counter < var2) {
        a->counter = 0;
    } else {
        a->counter = a->counter - var2;
    }
    if (a->counter == 0) {
        result = 0;
        a->unknown_19b7_ = 0;
    }
    return result;
}
