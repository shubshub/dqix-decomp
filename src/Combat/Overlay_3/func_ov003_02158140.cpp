#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int STD_GetStringLength(const char* s);
extern char data_ov003_0217fce0;

struct Struct_ov003_021575dc_2 {
    char pad[0xc];
    char buf[0x38];
};

// USA: func_ov003_02158140
extern "C" ARM void func_ov003_02158140(struct Struct_ov003_021575dc_2* obj, int param1) {
    if (param1 == 0) return;
    memset(obj->buf, 0, 0x38);
    sprintf(obj->buf + STD_GetStringLength(obj->buf), &data_ov003_0217fce0, param1);
}
