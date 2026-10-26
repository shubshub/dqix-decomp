#include <globaldefs.h>

// USA: func_ov000_02159c58
extern "C" ARM int func_ov000_02159c58(void* obj, int v) {
    switch (v) {
        case 0x205:
        case 0x20a:
        case 0x20b:
        case 0x20c:
        case 0x20d:
        case 0x212:
            return 1;
        default:
            return 0;
    }
}
