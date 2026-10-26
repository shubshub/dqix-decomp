#include <globaldefs.h>
extern "C" void func_02070950(struct Struct_02070950_2*, struct Struct_02070950*, int, int, int);

extern "C" void* func_020704fc(void*);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

// USA: func_0208ad1c
extern "C" ARM void func_0208ad1c(void* obj) {
    void* handle = func_020704fc(obj);
    if (handle != NULL) {
        func_02070950((struct Struct_02070950_2*)handle, (struct Struct_02070950*)((char*)obj + 0xc), 0x14, 5, 0xf);
        SePlayer_Play(&g_sePlayer, 0x78, 0);
    }
}
