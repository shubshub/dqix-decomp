#include <globaldefs.h>

extern "C" void func_020d2018(int, int);

struct Struct_020bcc4c {
    char pad[0x48];
    int count;
    unsigned char table[1];
};

// USA: func_020bcc4c
extern "C" ARM void func_020bcc4c(struct Struct_020bcc4c* obj, int i, int arg) {
    if (i > obj->count - 1) return;
    func_020d2018(1 << obj->table[i], arg);
}
