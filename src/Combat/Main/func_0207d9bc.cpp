#include <globaldefs.h>
struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
// USA: func_0207d9bc
extern "C" ARM struct Entry0207d9bc* func_0207d9bc(struct Entry0207d9bc *arr, unsigned short key) {
    int i;
    for (i = 0; i < 4; i++) {
        if (arr[i].id == key) return &arr[i];
    }
    return NULL;
}
