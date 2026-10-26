#include <globaldefs.h>

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
extern "C" struct Entry0207d9bc* func_0207d9bc(struct Entry0207d9bc* arr, unsigned short key);

// USA: func_0207d978
extern "C" ARM int func_0207d978(struct Entry0207d9bc* arr, unsigned short key) {
    struct Entry0207d9bc* e = func_0207d9bc(arr, key);
    int i;
    if (e == NULL) return 0;
    for (i = 0; i < 4; i++) {
        signed char* p = (signed char*)e + i;
        if (p[8] < 0) return 0;
    }
    return 1;
}
