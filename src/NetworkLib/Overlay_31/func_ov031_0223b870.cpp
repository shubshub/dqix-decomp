#include <globaldefs.h>

struct Struct_ov031_0223d884 { int a, b, c, d; };
struct Struct_ov031_0223bf2c { int a, b, c, d; };
extern "C" void func_ov031_0223d884(Struct_ov031_0223d884);
extern "C" void func_ov031_0223bf2c(Struct_ov031_0223bf2c);
extern "C" unsigned int func_ov031_0223cf70(void**);
struct Struct_ov031_0223b870 {
    char unknown_0_[0x220];
    void* first;
    void* second;
};
extern Struct_ov031_0223b870* data_ov031_02290d28;
extern Struct_ov031_0223b870* data_ov031_02290d28_arg;

static inline void inline_ov031_0223b870(void* resource) {
    typedef void (*Type_ov031_02222bdc)(void*);
    Type_ov031_02222bdc var0 = (Type_ov031_02222bdc)func_ov031_0223d884;
    var0(resource);
}
static inline void inline_ov031_0223b870_2(void* resource) {
    typedef void (*Type_ov031_02222bdc)(void*);
    Type_ov031_02222bdc var0 = (Type_ov031_02222bdc)func_ov031_0223bf2c;
    var0(resource);
}

// USA: func_ov031_0223b870
extern "C" ARM void func_ov031_0223b870() {
    int i = 0;
    unsigned int offset = 0;
    do {
        inline_ov031_0223b870(((Struct_ov031_0223b870*)((char*)data_ov031_02290d28 + offset))->first);
        inline_ov031_0223b870_2(((Struct_ov031_0223b870*)((char*)data_ov031_02290d28 + offset))->second);
        i++;
        offset += sizeof(Struct_ov031_0223b870);
    } while (i < 2);
    func_ov031_0223cf70((void**)&data_ov031_02290d28_arg);
}
