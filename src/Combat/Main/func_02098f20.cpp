#include <globaldefs.h>
extern "C" void func_020cf0fc(int);

struct Struct_02098f20 { int year; int month; int day; int pad; };

// USA: func_02098f20
extern "C" ARM int func_02098f20(int arg0, int arg1, int arg2) {
    struct Struct_02098f20 now;
    int age;
    func_020cf0fc((int)(&now));
    now.year += 0x7d0;
    age = now.year - arg0;
    if (arg1 * 100 + arg2 > now.month * 100 + now.day) age -= 1;
    return age;
}
