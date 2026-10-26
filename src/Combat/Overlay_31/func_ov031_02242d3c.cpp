#include <globaldefs.h>

// USA: func_ov031_02242d3c
extern "C" ARM int func_ov031_02242d3c(char* str, int maxLen) {
    if (maxLen > 10) {
        return -1;
    }
    int i = 0;
    int result = 0;
    int var2 = 0;
    if (maxLen > 0) {
        do {
            char c = str[i];
            if (var2 != 0 && (c == ' ' || c == 0)) {
                break;
            }
            if (var2 == 0 && c == ' ') {
                goto advance;
            }
            if (c < '0' || c > '9') {
                return -1;
            }
            var2 = 1;
            int old = result;
            result = result * 10 + c - '0';
            if (old > result) {
                return -1;
            }
advance:
            i++;
        } while (i < maxLen);
    }
    return result;
}
