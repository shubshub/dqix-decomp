#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0207fc6c_44 = 0x20 };
#else
enum { Enum_0207fc6c_44 = 0x2c };
#endif

extern "C" void WindowPane_Update(void* entry, int arg);

struct Struct_0207fc6c {
    char pad0[Enum_0207fc6c_44];
    void* unknown_2c_;
    char* entries;
    char unknown_34_[5];
    unsigned char count;
};

// USA: func_0207fc6c
extern "C" ARM void func_0207fc6c(struct Struct_0207fc6c* obj, int arg) {
    unsigned char count;
    char* e;
    unsigned char i;
    if (obj->unknown_2c_ != NULL && obj->entries != NULL) {
        e = obj->entries;
        count = obj->count;
        for (i = 0; i < count; i++) {
            WindowPane_Update(e, arg);
            e += 0xe0;
        }
    }
}
