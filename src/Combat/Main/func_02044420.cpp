#include <globaldefs.h>
#include "Resource/MessageUpdate.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_02044420_65312 = 0xff22 };
#else
enum { Enum_02044420_65312 = 0xff20 };
#endif

#if defined(jpn)
extern "C" ARM int func_02069444(void* obj, unsigned short buf) {
    int result = 0;
    if (!func_02069430(obj, buf)) return 0;
#else
// USA: func_02044420
extern "C" ARM int func_02044420(void* obj, void* src) {
    unsigned short buf;
    int result = 0;
    memcpy(&buf, src, 2);
    if (!func_02044494(obj, &buf)) {
        return 0;
    }
#endif
    switch (buf) {
    case Enum_02044420_65312 + 0:
    case Enum_02044420_65312 + 1:
    case Enum_02044420_65312 + 3:
    case Enum_02044420_65312 + 4:
        result = 1;
        break;
    case Enum_02044420_65312 + 2:
    case Enum_02044420_65312 + 5:
        result = 2;
        break;
    }
    return result;
}
