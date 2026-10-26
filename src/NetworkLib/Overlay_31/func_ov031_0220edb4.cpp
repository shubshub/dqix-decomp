#include <globaldefs.h>

extern "C" int func_ov031_0220d60c(void);

// USA: func_ov031_0220edb4
extern "C" ARM int func_ov031_0220edb4(void) {
    char* base = (char*)func_ov031_0220d60c() + 0x2000;
    int* p = *(int**)(base + 0x270);
    int result = 0;
    if (p != NULL) {
        unsigned int cnt = *(unsigned int*)(base + 0x274);
        if (cnt > 0xc) {
            return *(int*)((char*)p + 4);
        }
    }
    return result;
}
