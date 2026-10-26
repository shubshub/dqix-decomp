#include <globaldefs.h>

extern "C" void func_020de3f4(int a, int b, int c, int d, char* outA, char* outB, char* arg6, void** arg7);

typedef int (*Type_020dec30)(void*, int, int, int);

struct Struct_020dec30 {
    unsigned short count;
    unsigned short pad2;
    unsigned int pad4;
    unsigned int pad8;
    void* base;
};

struct Struct_020dec30_2 {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int pad8;
    unsigned int fieldC;
};

// USA: func_020dec30
extern "C" ARM int func_020dec30(void* obj, int target, int arg2, int arg3, signed char arg4, signed char arg5) {
    char outA = -1;
    char outB = -1;
    char var2 = -1;
    void* fn = 0;
    func_020de3f4(arg2, arg3, arg4, arg5, &outA, &outB, &var2, &fn);
    if (fn == 0) {
        return 0;
    }
    Struct_020dec30* list = (Struct_020dec30*)obj;
    int count = list->count;
    short total = 0;
    char* elem = (char*)list->base;
    int i = total;
    for (; i < count; i++, elem += 0x20) {
        Struct_020dec30_2* e = (Struct_020dec30_2*)elem;
        int bits = (int)((e->fieldC << 9) >> 21);
        bits = (unsigned short)bits;
        if (bits != 0) {
            if (((Type_020dec30)fn)(elem, outA, outB, var2) != 0) {
                if (total == target) {
                    return (int)elem;
                }
                total = total + 1;
            }
        }
    }
    return 0;
}
