#include <globaldefs.h>
extern "C" void WindowPane_Draw(struct Struct0204c8f0*);


struct Struct_0207fd00 {
    #if defined(jpn)
    char pad0[0x20];
#else
    char pad0[0x2c];
#endif
    void* unknown_2c_;
    char* entries;
    char unknown_34_[5];
    unsigned char count;
};

// USA: func_0207fd00
extern "C" ARM void func_0207fd00(struct Struct_0207fd00* obj) {
    unsigned char count;
    char* e;
    unsigned char i;
    if (obj->unknown_2c_ != NULL && obj->entries != NULL) {
        e = obj->entries;
        count = obj->count;
        for (i = 0; i < count; i++) {
            WindowPane_Draw((struct Struct0204c8f0*)(e));
            e += 0xe0;
        }
    }
}
