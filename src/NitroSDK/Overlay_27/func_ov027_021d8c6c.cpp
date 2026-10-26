#include <globaldefs.h>

typedef void (*Type_ov027_021d8c6c)(int, int, int);

struct Struct_ov027_021e33ec_2 { void* field0; };
extern Struct_ov027_021e33ec_2 data_ov027_021e33ec;

// USA: func_ov027_021d8c6c
extern "C" ARM void func_ov027_021d8c6c(int a, int b, int c) {
    Type_ov027_021d8c6c cb = *(Type_ov027_021d8c6c*)((char*)data_ov027_021e33ec.field0 + 0x14e4);
    if (cb) cb(a, b, c);
}
