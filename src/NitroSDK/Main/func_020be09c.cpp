#include <globaldefs.h>

extern "C" int func_020bd79c(unsigned int index);
extern "C" int func_020bd7c4(unsigned int index, void* buf, int size, int flag);
struct Obj020bda58;
typedef void (*Type_020bbf84)(void* mem, unsigned int size, unsigned int data1, unsigned int data2);
extern "C" void* func_020bda58(struct Obj020bda58* obj, unsigned int size, Type_020bbf84 callback, int a3, int a4);
void CleanCacheRange(const void* addr, unsigned int size);

// USA: func_020be09c
extern "C" ARM void* func_020be09c(unsigned int index, Type_020bbf84 callback, int a3, int a4, struct Obj020bda58* obj) {
    unsigned int var0 = func_020bd79c(index);
    if (!var0) {
        return 0;
    }
    if (!obj) {
        return 0;
    }
    void* var1 = func_020bda58(obj, var0 + 0x20, callback, a3, a4);
    if (!var1) {
        return 0;
    }
    if (func_020bd7c4(index, var1, var0, 0) != (int)var0) {
        return 0;
    }
    CleanCacheRange(var1, var0);
    return var1;
}
