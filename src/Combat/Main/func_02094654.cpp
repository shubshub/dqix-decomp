#include <globaldefs.h>

#if defined(jpn)
enum { regionalState = 0x138 };
#else
enum { regionalState = 0x3c8 };
#endif

struct Struct_02094654 {
    char pad0[regionalState];
    unsigned char state : 7;
    unsigned char display : 1;
};
struct Struct_02094654_2 { unsigned int attributes01; unsigned short unknown_4_; };
extern "C" int func_0209378c(int);
extern "C" unsigned int func_020937f0(int);
extern "C" int func_020d4ac8(void);
extern "C" Struct_02094654_2* func_02093704(int);
extern "C" void func_020946f8(Struct_02094654_2*, int, int, int, int, int, int, int, int, int, int, int);

// USA: func_02094654
extern "C" ARM void func_02094654(Struct_02094654* obj) {
    int shift = func_0209378c(obj->display);
    unsigned int size = func_020937f0(obj->display);
    if (size) {
        unsigned int tile = (size - 0xa00) >> shift;
        int stride = 0x80 >> shift;
        int state = func_020d4ac8();
        Struct_02094654_2* entries = func_02093704(obj->display);
        tile += state * stride;
        func_020946f8(entries, 0, 0, 0, 0, 0, 0, 0x40000000, 0, tile, 15, 0);
    }
}
