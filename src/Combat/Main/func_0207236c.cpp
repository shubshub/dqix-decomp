#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

extern "C" void func_020724f4(int a, int b, int c);

struct Struct_02108da8 {
    int f0;
    int f4;
};

extern struct Struct_02108da8 data_02108da8;

// USA: func_0207236c
extern "C" ARM int func_0207236c(Script::Parameter* p) {
    const Script::Parameter* parameters = p;
    func_020724f4(data_02108da8.f4, data_02108da8.f0, (unsigned short)parameters[0].ToInt());
    return 1;
}
