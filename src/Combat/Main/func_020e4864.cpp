#include <globaldefs.h>
#include <std_library_functions.h>
int STD_GetStringLength(const char*);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern char data_020f2d2c[][11];
extern signed char data_020eeab0[][8];
extern char data_020ee9d8[][3];
// USA: func_020e4864
extern "C" ARM void func_020e4864(const char* arg0, char* arg1, int arg2, int, int, int arg5) {
    int var0;
    for (;;) {
        if (!*arg0) break;
        if (*arg0 == '[') {
            int var1 = 0;
            int var2 = 0;
            for (;;) {
                if (!data_020f2d2c[index][0]) break;
                int length = STD_GetStringLength(data_020f2d2c[index]);
                if (memcmp(source + 1, data_020f2d2c[index], length) == 0) {
                    if (column >= 0 && row >= 0) {
                        int replacementIndex = data_020eeab0[index][column + row * 2] * 3;
                        const char* replacementBase = (const char*)data_020ee9d8;
                        replacementLength = STD_GetStringLength(replacementBase + replacementIndex);
                        memcpy(destination, replacementBase + replacementIndex, replacementLength);
                        destination += replacementLength;
                    }
                    arg0 += var3 + 1;
                    var1 = true;
                    break;
                }
                var2++;
            }
            if (var1) continue;
        }
        *arg1++ = *arg0++;
    }
    *arg1 = *arg0;
}
