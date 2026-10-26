#include <globaldefs.h>

struct Struct_ov000_02184288_5 { int f0; int limit; };
extern struct Struct_ov000_02184288_5 data_ov000_02184288;

#if defined(jpn)
enum { Enum_ov000_0217538c_7452 = 0x1f54 };
#else
enum { Enum_ov000_0217538c_7452 = 0x1d1c };
#endif

// USA: func_ov000_0217538c
extern "C" ARM int func_ov000_0217538c(void* objRaw) {
    char* obj = (char*)objRaw;
    int var1 = -1;
    int count = 0;
    for (int i = 0; i < data_ov000_02184288.limit; i++) {
        int v = *(int*)(obj + i * 4 + Enum_ov000_0217538c_7452);
        if (var1 != v) {
            var1 = v;
            count++;
        }
    }
    return count;
}
