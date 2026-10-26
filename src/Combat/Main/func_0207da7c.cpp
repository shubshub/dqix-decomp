#include <globaldefs.h>

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
struct Struct_0207d798;
extern "C" struct Entry0207d9bc* func_0207d9bc(struct Entry0207d9bc* arr, unsigned short key);
extern "C" void func_0207d7c0(struct Struct_0207d798* o);

// USA: func_0207da7c
extern "C" ARM void func_0207da7c(struct Entry0207d9bc* arr, unsigned short key) {
    struct Entry0207d9bc* e = func_0207d9bc(arr, key);
    if (e != NULL) {
        func_0207d7c0((struct Struct_0207d798*)e);
    }
}
