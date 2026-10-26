#include <globaldefs.h>
#include "std_library_functions.h"

extern const char data_ov001_021656f4[];
extern const char data_ov001_021656fd[];
extern const char data_ov001_02165706[];
extern const char data_ov001_0216570d[];
extern const char data_ov001_02165728[];
extern const char data_ov001_0216572d[];

// USA: func_ov001_0215ad3c
extern "C" ARM int func_ov001_0215ad3c(char* path, char* arg1, char* arg2) {
    char* p = strstr(path, data_ov001_021656f4);
    if (p == NULL) {
        strstr(path, data_ov001_021656fd);
    }
    if (p != NULL) {
        strcpy(arg1, p + strlen(data_ov001_02165706));
        strcpy(arg2, data_ov001_0216570d);
        return 1;
    }
    if (strstr(path, data_ov001_02165728) != NULL) {
        char* var1 = strrchr(path, '/');
        if (!var1) {
            var1 = strrchr(path, '\\');
        }
        if (var1) {
            var1 = var1 + 1;
        } else {
            var1 = path;
        }
        strcpy(arg1, var1);
        strcpy(arg2, data_ov001_0216572d);
        return 1;
    }
    return 0;
}
