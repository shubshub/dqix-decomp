#include <globaldefs.h>

// USA: func_ov001_02159804
extern "C" ARM int func_ov001_02159804(void* src, void* dst) {
    *(float*)((char*)dst + 0x8c) = (float)(*(int*)((char*)src + 0x10));
    return 0;
}
