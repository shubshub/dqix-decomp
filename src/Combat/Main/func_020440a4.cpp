#include <globaldefs.h>

#if defined(jpn)
enum { kSubobjectOffset = 0x1804 };
#else
enum { kSubobjectOffset = 0x19e0 };
#endif

extern "C" int WindowFrame_Load(void*);

// USA: func_020440a4
extern "C" ARM int func_020440a4(void* obj) {
    return WindowFrame_Load((char*)obj + kSubobjectOffset);
}
