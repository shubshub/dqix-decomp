#include <globaldefs.h>

extern "C" int func_ov004_021666bc(void* a1, int* out);
#if defined(jpn)
struct Struct_ov004_0217101c { unsigned int reserved; char* value; };
extern Struct_ov004_0217101c data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c.value
#else
extern char* data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c
#endif
extern "C" void func_ov004_02166608(void* a);
extern "C" void func_ov004_021660f4(void);
extern "C" void func_ov004_02165f2c(void);
extern "C" void func_ov004_02166730(void* a1, int a2);
extern "C" void func_ov004_02166bd8(void* a1);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

struct Struct_ov004_02166fe4 {
    char pad[0x50];
    unsigned char unknown_50_0_ : 7;
    unsigned char unknown_50_7_ : 1;
};

// USA: func_ov004_02166fe4
extern "C" ARM int func_ov004_02166fe4(void* a1) {
    int local;
    int r4 = func_ov004_021666bc(a1, &local);

    struct Struct_ov004_02166fe4* r3 = (struct Struct_ov004_02166fe4*)CONTEXT_VALUE;
    r3->unknown_50_7_ = r3->unknown_50_7_ + 1;

    func_ov004_02166608(a1);
    func_ov004_021660f4();
    func_ov004_02165f2c();
    func_ov004_02166730(a1, r4);
    func_ov004_02166bd8(a1);
    SePlayer_Play(&g_sePlayer, 1, 0);
    return 0;
}
