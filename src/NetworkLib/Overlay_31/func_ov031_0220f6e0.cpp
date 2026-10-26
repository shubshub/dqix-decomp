#include <globaldefs.h>

extern void* data_ov031_0224e580;
extern "C" int func_020c7ea0(void* obj, unsigned int* out, int arg2);


// USA: func_ov031_0220f6e0
extern "C" ARM void func_ov031_0220f6e0(void) {
    unsigned int buf;
    func_020c7ea0(data_ov031_0224e580, &buf, 0);
    void* entry = *(void**)((char*)data_ov031_0224e580 + 0x24);
    if (entry == NULL) return;
    *(int*)((char*)entry + 0x1c) = 1;
    *(int*)((char*)data_ov031_0224e580 + 0x24) = 0;
}
