#include <globaldefs.h>
#include "std_library_functions.h"

extern int data_ov012_0218b312;
extern "C" int func_02099304(const char* name, int a1, int a2, int a3, void* buf, int arg5, int flag, void* p1, void* p2);

// USA: func_ov012_0218ae74
extern "C" ARM int func_ov012_0218ae74(unsigned char* self, const char* name) {
    self[0x1335] = 1;
    int result = 1;

    memset(*(void**)(self + 0x1374), 0, 0x960);

    func_02099304(name, *(int*)(self + 0x13b0), *(int*)(self + 0x13b4), *(int*)(self + 0x13b8),
                  *(void**)(self + 0x1374), 0x960, 0, self + 0x1440, self + 0x1400);

    char* s = (char*)*(void**)(self + 0x1374);
    char* found = strstr(s, (const char*)&data_ov012_0218b312);

    if (found == 0) {
        result = 0;
        self[0x14bd] = 0;
        self[0x1334] = 0;
        self[0x1335] = 0;
    } else if (self[0x14bd] == 0) {
        *found = 0;
    } else {
        s = found + strlen(*(char**)(self + 0x13b0)) + 0xb;
    }

    memset(*(void**)(self + 0x13bc), 0, 0xf2);
    unsigned int len = strlen(s);
    memcpy(*(void**)(self + 0x13bc), s, len);

    return result;
}
