#include <globaldefs.h>
#include "std_library_functions.h"

extern char data_ov025_021ef778[];
extern char data_ov025_021ef781[];
extern char data_ov025_021ef78a[];
extern char data_ov025_021ef791[];
extern char data_ov025_021ef7ac[];
extern char data_ov025_021ef7b5[];
extern char data_ov025_021ef7be[];

// USA: func_ov025_021e24d0
extern "C" ARM int func_ov025_021e24d0(char* s, char* out2, char* out1) {
    char* m = strstr(s, data_ov025_021ef778);
    if (!m) {
        strstr(s, data_ov025_021ef781);
    }
    if (m) {
        strcpy(out1, m + strlen(data_ov025_021ef78a));
        strcpy(out2, data_ov025_021ef791);
        return 1;
    }
    m = strstr(s, data_ov025_021ef7ac);
    if (!m) {
        strstr(s, data_ov025_021ef7b5);
    }
    if (!m) return 0;
    strcpy(out1, m + strlen(data_ov025_021ef78a));
    strcpy(out2, data_ov025_021ef7be);
    return 1;
}
