#include <globaldefs.h>
#include "std_library_functions.h"

int STD_GetStringLength(const char* s);
extern "C" int memcmp(void* a, void* b, int n);

extern char data_020f2dc8;
extern char data_020f2dcb;
extern char data_020f2dcf;

// USA: func_020e462c
extern "C" ARM char* func_020e462c(char* arg0, char* arg1, char* arg2) {
    if (arg1 != 0 && *arg1 != 0) {
        arg0 += sprintf(arg0, &data_020f2dc8, arg1);
        int var0;
        if (arg1 == 0) goto setFlag1;
        {
            int len = STD_GetStringLength(str);
            if (len <= 3) goto setFlag1;
            flag = memcmp(str + (len - 3), &data_020f2dcb, 3);
            goto flagDone;
        }
    setFlag1:
        var0 = 1;
    flagDone:
        if (var0 != 0) {
            arg0 += sprintf(arg0, &data_020f2dcf);
        }
    }
    arg0 += sprintf(arg0, arg2);
    return arg0;
}
