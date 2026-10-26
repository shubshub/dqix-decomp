#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_0209dccc();

struct Struct_0209d744 {
    unsigned char pad[0x6c];
    int value; // 0x6c
};

// USA: func_0209d744
extern "C" ARM int func_0209d744(void* arg) {
    struct Struct_0209d744* mgr = (struct Struct_0209d744*)func_0209dccc();
    if (mgr == NULL) return 0;
    mgr->value = func_ov017_021d60f4(arg);
    return 1;
}
