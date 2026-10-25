#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" double func_020055d4(char* str);
int MessageSystem_GetInstance(void);

// USA: func_02069c1c
extern "C" ARM int func_02069c1c(char** arg0, char* arg1) {
    float var0[1];
    for (int var1 = 0; var1 < 1; var1++) {
        signed char var2 = *arg1;
        if (var2 != 0 && var2 >= '0' && var2 <= '9') {
            float var3 = (float)func_020055d4(arg1);
            var0[var1] = var3;
            while (1) {
                var2 = *arg1;
                if (var2 == 0) break;
                if (var2 == ',' || var2 == '>') {
                    arg1++;
                    break;
                }
                arg1++;
            }
        }
    }
    char* g = (char*)MessageSystem_GetInstance();
    *(int*)(g + 0x1000 + 0x840) = (int)(localArr[0] * 4096.0f);
    void* dst = *obj;
    unsigned short marker = 0xff2a;
    memcpy(dst, &marker, 2);
    return 2;
}
