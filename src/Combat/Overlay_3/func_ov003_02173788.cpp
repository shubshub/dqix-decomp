#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02173788_216 = 0xd4 };
enum { Enum_ov003_02173788_239 = 0xeb };
enum { Enum_ov003_02173788_203 = 0xc9 };
enum { Enum_ov003_02173788_237 = 0xe9 };
enum { Enum_ov003_02173788_202 = 0xc8 };
#else
enum { Enum_ov003_02173788_216 = 0xd8 };
enum { Enum_ov003_02173788_239 = 0xef };
enum { Enum_ov003_02173788_203 = 0xcb };
enum { Enum_ov003_02173788_237 = 0xed };
enum { Enum_ov003_02173788_202 = 0xca };
#endif


extern "C" void func_020a620c(void* obj);

// USA: func_ov003_02173788
extern "C" ARM void func_ov003_02173788(unsigned char* obj) {
    func_020a620c(obj + Enum_ov003_02173788_216);
    if (obj[Enum_ov003_02173788_239] != 0) {
        return;
    }
    if (obj[Enum_ov003_02173788_203] != 0) {
        obj[Enum_ov003_02173788_203] = 0;
        obj[Enum_ov003_02173788_237] = 3;
        obj[Enum_ov003_02173788_239] = 0;
    } else if (obj[Enum_ov003_02173788_202] != 0) {
        obj[Enum_ov003_02173788_237] = 4;
        obj[Enum_ov003_02173788_239] = 0;
    }
}
