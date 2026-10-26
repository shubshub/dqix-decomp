#include <globaldefs.h>

struct Struct_0205d67c;
extern "C" int func_0205d67c(struct Struct_0205d67c* p);
extern "C" void func_ov002_02156e90(void* obj);

#if defined(jpn)
#define LIST_02156ff0 0xe20
#define KEY_02156ff0 0xa80
#else
#define LIST_02156ff0 0x2c8 + 0xc00
#define KEY_02156ff0 0xbb8
#endif

// USA: func_ov002_02156ff0
extern "C" ARM void func_ov002_02156ff0(unsigned char* obj, int key) {
    while (func_0205d67c((struct Struct_0205d67c*)(obj + LIST_02156ff0))) {
        if (*(int*)(obj + 0x1000 + KEY_02156ff0) == key) {
            return;
        }
        func_ov002_02156e90(obj);
    }
}
