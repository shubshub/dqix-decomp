#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xe20
#else
#define REGION_OFFSET_0 0xea4
#endif


struct Struct_020d7638;
extern "C" void func_020d7638(struct Struct_020d7638* obj);
extern "C" void func_020d7534(void* p);

// USA: func_ov000_02160c60
extern "C" ARM void func_ov000_02160c60(void* work) {
    void* p = *(void**)((char*)work + REGION_OFFSET_0);
    if (p) {
        func_020d7534(p);
        func_020d7638((struct Struct_020d7638*)*(void**)((char*)work + REGION_OFFSET_0));
    }
}
