#include <globaldefs.h>

struct Struct_0207fdcc_2;

extern "C" unsigned char* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" int WindowPane_IsOpen(unsigned char* obj);

// USA: func_020811e8
extern "C" ARM int func_020811e8(struct Struct_0207fdcc_2* obj, int key) {
    unsigned char* elem = func_02081da8(obj, key);
    if (elem != NULL) {
        return WindowPane_IsOpen(elem) != 0;
    }
    return 0;
}
