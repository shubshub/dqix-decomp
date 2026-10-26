#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x104
#else
#define REGION_FIELD 0x108
#endif

// USA: func_ov017_021bd398
extern "C" ARM void func_ov017_021bd398(void* obj) {
    *(unsigned char*)((char*)obj + REGION_FIELD) = 1;
}
