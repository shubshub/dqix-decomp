#include <globaldefs.h>


extern "C" THUMB void func_ov031_02220190(int a, int b, int c);

// USA: func_ov031_022201cc
extern "C" THUMB void func_ov031_022201cc(int a, int unused, int b, int c) {
    func_ov031_02220190(a, b, c);
}
