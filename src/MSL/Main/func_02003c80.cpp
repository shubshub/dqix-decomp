#include <globaldefs.h>

extern "C" unsigned int func_02003418(void* callback, void* state, const char* fmt, void* args);
extern "C" void func_02003c3c(void);

struct Struct_02003c80 {
    char* buf;
    unsigned int unknown_4_;
    int count;
};

// USA: func_02003c80
extern "C" ARM unsigned int func_02003c80(char* buf, unsigned int arg1, const char* fmt, void* args) {
    struct Struct_02003c80 local;
    local.buf = buf;
    local.unknown_4_ = arg1;
    local.count = 0;
    unsigned int result = func_02003418((void*)func_02003c3c, &local, fmt, args);
    if (buf == 0) {
        return result;
    }
    if (result < arg1) {
        buf[result] = 0;
        return result;
    }
    if (arg1 != 0) {
        *(buf + arg1 - 1) = 0;
    }
    return result;
}
