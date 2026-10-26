#include <globaldefs.h>

struct Struct_ov001_021658b8_10 { char pad[0x88]; int unknown_88_; };
extern Struct_ov001_021658b8_10 data_ov001_021658b8;
extern "C" void* func_ov017_021d612c(void*);
extern "C" void func_ov001_0215ec94(void*, int);

// USA: func_ov001_0215ed74
extern "C" ARM int func_ov001_0215ed74(void* arr, int end) {
    int i;
    for (i = data_ov001_021658b8.unknown_88_; i < end; i++) {
        void* r = func_ov017_021d612c(arr);
        arr = (char*)arr + 0x8;
        func_ov001_0215ec94(r, i);
    }
    return 1;
}
