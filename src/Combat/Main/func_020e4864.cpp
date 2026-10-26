#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" int STD_GetStringLength(const char*);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern char data_020f2d2c[][11];
extern signed char data_020eeab0[][8];
extern char data_020ee9d8[][3];
// USA: func_020e4864
extern "C" ARM void func_020e4864(const char* source, char* destination, int column, int, int, int row) {
    int replacementLength;
    for (;;) {
        if (!*source) break;
        if (*source == '[') {
            int var1 = 0;
            int index = 0;
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
                    source += length + 1;
                    var1 = true;
                    break;
                }
                index++;
            }
            if (var1) continue;
        }
        *destination++ = *source++;
    }
    *destination = *source;
}
