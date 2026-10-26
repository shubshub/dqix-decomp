#include <globaldefs.h>

// USA: func_ov031_02204b50
extern "C" ARM int func_ov031_02204b50(char* str, char** arg1) {
    *arg1 = str;
    unsigned int result = 0;
    unsigned int digit;
    do {
        digit = ((unsigned char)*str - 0x30) & 0xff;
        if (digit > 9) break;
        result = result * 10 + digit;
        str++;
        *arg1 = str;
    } while (1);
    return result;
}
