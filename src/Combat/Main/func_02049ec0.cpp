#include <globaldefs.h>

struct Struct_02049ec0 {
    unsigned char lo : 4;
    unsigned char kind : 4;
};

// USA: func_02049ec0
extern "C" ARM int func_02049ec0(unsigned char* obj) {
    int k = ((struct Struct_02049ec0*)(obj + 0xc1))->kind;
    if (k != 2 && k != 3 && k != 4 && k != 5) {
    } else {
        return 0;
    }
    return 1;
}
