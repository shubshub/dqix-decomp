#include <globaldefs.h>

// USA: func_ov024_021fe698
extern "C" ARM int func_ov024_021fe698(char* obj, int idx) {
    if (*(unsigned char*)(obj + idx + 0x10) == 0) {
        return 0;
    }
    *(int*)(obj + 0x38) = idx;
    return 1;
}
