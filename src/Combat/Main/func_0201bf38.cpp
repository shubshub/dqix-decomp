#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0201bf38_10053 = 0x2785, Enum_0201bf38_10054 = 0x2786, Enum_0201bf38_10056 = 0x2788 };
#else
enum { Enum_0201bf38_10053 = 0x2745, Enum_0201bf38_10054 = 0x2746, Enum_0201bf38_10056 = 0x2748 };
#endif

extern "C" ARM void func_0201bf98(unsigned char* obj, int bit, int set);

// USA: func_0201bf38
extern "C" ARM void func_0201bf38(unsigned char* obj, int set, int a, int b, unsigned short c) {
    func_0201bf98(obj, 0, set);
    obj[Enum_0201bf38_10053] = a;
    obj[Enum_0201bf38_10054] = b;
    *(unsigned short*)(obj + Enum_0201bf38_10056) = c;
}
