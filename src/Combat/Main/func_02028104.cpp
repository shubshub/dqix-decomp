#include <globaldefs.h>
extern "C" void func_02028048(int, int, struct StreamHeader*, int);

struct Struct_02028104;
extern "C" void func_0202811c(struct Struct_02028104* s);

// USA: func_02028104
extern "C" ARM void func_02028104(struct Struct_02028104* s, int b, int c, int d) {
    func_02028048((int)(s), (int)(b), (struct StreamHeader*)(c), (int)(d));
    func_0202811c(s);
}
