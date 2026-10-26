#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_0209dccc();

struct Struct_0209d770 {
    unsigned char pad[0x70];
    int entries[1];
};

// USA: func_0209d770
extern "C" ARM int func_0209d770(void* arg) {
    struct Struct_0209d770* mgr = (struct Struct_0209d770*)func_0209dccc();
    if (mgr == NULL) return 0;
    int index = func_ov017_021d60f4(arg);
    int value = func_ov017_021d60f4((char*)arg + 8);
    mgr->entries[index] = value;
    return 1;
}
