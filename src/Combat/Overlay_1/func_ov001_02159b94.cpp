#include <globaldefs.h>

struct Struct_ov001_02159b94 { int c, d, e; };
extern "C" int func_ov001_02164754(int, int, int, int, int);

// USA: func_ov001_02159b94
extern "C" ARM int func_ov001_02159b94(int a, int b, struct Struct_ov001_02159b94 t) {
    return func_ov001_02164754(a, b, t.c, t.d, t.e);
}
