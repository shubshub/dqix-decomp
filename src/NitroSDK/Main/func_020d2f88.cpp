#include <globaldefs.h>

// USA: func_020d2f88
extern "C" ARM char* func_020d2f88(char* arg0, char* arg1) {
    int var0;
    char* cursor;
    char var2;
    int start;
    start = 0;
    if (arg0[start] != 0) {
        do {
            cursor = arg0 + start;
            var0 = 0;
            while ((var2 = arg1[var0]) != 0 && *cursor == var2) {
                cursor++;
                var0++;
            }
            if (var2 == 0) {
                return arg0 + start;
            }
            start++;
        } while (arg0[start] != 0);
    }
    return 0;
}
