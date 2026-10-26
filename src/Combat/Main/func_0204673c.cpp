#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0204673c
extern "C" char* func_0204673c(char* records, char* arg1) {
    if (records == NULL) {
        return NULL;
    }
    if (arg1 == NULL) {
        return NULL;
    }
    if (arg1[0] == 0) {
        return NULL;
    }

    char* s = arg1;
    char* name = arg1;
    while (*s != 0) {
        if (*s == '/') {
            name = s + 1;
        }
        s++;
    }

    while (records[0] != 0) {
        if (strcmp(records, name) == 0) {
            return records;
        }
        records += *(int*)(records + 0x48);
    }
    return NULL;
}
