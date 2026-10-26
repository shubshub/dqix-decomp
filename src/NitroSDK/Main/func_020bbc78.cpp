#include <globaldefs.h>

extern "C" int func_020bb984(unsigned short* obj);

struct Struct_020bb964 { int unk_0; unsigned int unknown_4_; };
extern "C" unsigned short func_020bb964(Struct_020bb964* ctx, unsigned int value);

struct Struct_020bbc78 {
    char pad[8];
    unsigned short head;
    unsigned short unknown_a_;
    unsigned short count;
};

// USA: func_020bbc78
extern "C" ARM int func_020bbc78(Struct_020bbc78* arg0) {
    if (func_020bb984((unsigned short*)arg0)) return 0;
    arg0->head = func_020bb964((Struct_020bb964*)arg0, arg0->head);
    arg0->count--;
    return 1;
}
