#include <globaldefs.h>

extern "C" void* func_0207c60c(void* base, unsigned int index);
extern "C" signed short func_0207c620(unsigned char* base, unsigned int index);

// USA: func_0207c72c
extern "C" ARM short func_0207c72c(void* base, unsigned int index, short target) {
    signed char* arr = (signed char*)func_0207c60c(base, index);
    if (arr == NULL) return 0;
    short count = 0;
    short var2 = func_0207c620((unsigned char*)base, index);
    unsigned int i;
    for (i = 0; i < var2; i++) {
        if (*arr > 0) {
            if (target == count) return *arr;
            count++;
        }
        arr++;
    }
    return 0;
}
