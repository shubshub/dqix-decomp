#include <globaldefs.h>

// USA: func_ov001_02164194
extern "C" ARM int func_ov001_02164194(void* obj, int type, int val, int flag) {
    if (flag == 0) {
        return 0;
    }
    *(int*)obj = type;
    switch (type) {
        case 0:
        case 1:
        case 4:
        case 5:
            *(int*)((char*)obj + 0x4) = val;
            *(int*)((char*)obj + 0xc) = flag;
            return 1;
    }
    return 0;
}
