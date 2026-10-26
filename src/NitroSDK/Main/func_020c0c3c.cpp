#include <globaldefs.h>
#if defined(jpn)
#define data_020e93fc data_020e9508
#endif

#if defined(jpn)
#define func_020c0c3c func_020c2708
#endif

struct Struct_020e93fc {
    unsigned int words[7];
};
extern Struct_020e93fc data_020e93fc;

struct Struct_020c089c;
extern "C" void func_020c089c(struct Struct_020c089c* ctx);
struct Struct_020c08ec;
extern "C" void func_020c08ec(struct Struct_020c08ec* ctx, const unsigned char* src, unsigned int len);
extern "C" void func_020c0a40(void);
extern "C" void func_020c0cd0(void* a, void* b, void* c, void* d, void* e, Struct_020e93fc* desc);

// USA: func_020c0c3c
extern "C" ARM void func_020c0c3c(void* a, void* b, void* c, void* d, void* e) {
    unsigned char var0[0x14];
    Struct_020e93fc desc = data_020e93fc;
    unsigned char var2[0x68];
    desc.words[2] = (unsigned int)var2;
    desc.words[3] = (unsigned int)var0;
    desc.words[4] = (unsigned int)func_020c089c;
    desc.words[5] = (unsigned int)func_020c08ec;
    desc.words[6] = (unsigned int)func_020c0a40;
    func_020c0cd0(a, b, c, d, e, &desc);
}
