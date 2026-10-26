#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov000_02171674_156 = 0xdc };
#else
enum { Enum_ov000_02171674_156 = 0x9c };
#endif

// USA: func_ov000_02171674
extern "C" ARM int func_ov000_02171674(void* obj, int index) {
    if (index < 0 || index >= 0x42) return 0;
    return *(int*)((char*)obj + Enum_ov000_02171674_156 + (index << 2));
}
