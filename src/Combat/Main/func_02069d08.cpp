#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define func_020965c0 func_jpn_02098210
#endif

struct Struct_02069d08 { void* dest; };

extern "C" void func_020696bc(int value, int *out, int flag);
extern "C" int* func_02094d6c(void);
struct Struct_02069d08_2;
extern "C" unsigned char func_020965c0(struct Struct_02069d08_2 *s, unsigned int val);
extern "C" int MessageSystem_GetInstance(void);

// USA: func_02069d08
extern "C" ARM int func_02069d08(struct Struct_02069d08 *obj, int value) {
    int local;
    func_020696bc(value, &local, 1);
    unsigned char idx = func_020965c0((struct Struct_02069d08_2*)func_02094d6c(), local & 0xff);
    *(unsigned short*)(MessageSystem_GetInstance() + 0x1948) = idx;
    void* d = obj->dest;
    unsigned short v = 0xff10;
    memcpy(d, &v, 2);
    return 2;
}
