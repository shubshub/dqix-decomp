#include <globaldefs.h>

struct Struct_020dbdc0;
struct Struct_020dbd9c;
struct Struct_020dbebc;

extern "C" void func_020dbf70(struct Struct_020dbdc0* o);
extern "C" void func_020dbd9c(struct Struct_020dbd9c* p);
extern "C" void func_020dbedc(struct Struct_020dbebc* a);

// USA: func_020dbebc
extern "C" ARM void func_020dbebc(void* a) {
    func_020dbf70((struct Struct_020dbdc0*)a);
    func_020dbedc((struct Struct_020dbebc*)a);
    func_020dbd9c((struct Struct_020dbd9c*)a);
}
