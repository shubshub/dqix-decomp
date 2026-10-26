#include <globaldefs.h>

extern "C" int func_ov031_0220868c(const char*);

// USA: func_ov031_022086b0
extern "C" ARM int func_ov031_022086b0(const char* text, const char* pattern) {
    for (;;) {
        char var0;
        char var1;
        while ((var0 = *text++) == (var1 = *pattern++)) {
            if (var0 == 0) return 0;
        }
        if (var1 != '*') return 1;
        text--;
        int textLength = func_ov031_0220868c(text);
        int var3 = func_ov031_0220868c(pattern);
        if (var3 > textLength) return 1;
        text += textLength - var3;
    }
}
