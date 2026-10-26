#include <globaldefs.h>

typedef void (*Type_020bd444_3)(int, int, int, int);
extern "C" int func_020be09c(unsigned int index, Type_020bd444_3 callback, void* ctx, unsigned int arg3, int b);

extern "C" void func_020be4a4(int, int, int, int);
extern "C" void* func_020bd444(void);
extern "C" int func_020bd8ac(unsigned int index);
extern "C" void func_020bd8d4(unsigned int index, int value);

// USA: func_020be280
extern "C" ARM int func_020be280(unsigned int index, int b, int flag) {
    int result = func_020bd8ac(index);
    if (result == 0) {
        void* ctx = flag ? func_020bd444() : 0;
        result = func_020be09c(index, func_020be4a4, ctx, index, b);
        if (flag && result != 0) {
            func_020bd8d4(index, result);
        }
    }
    return result;
}
