#include <globaldefs.h>

struct Struct_020727d8 {
    void* entries;
    short capacity;
    short count;
};
extern "C" void func_020727d8(struct Struct_020727d8* list);

// USA: func_020727ec
extern "C" ARM void func_020727ec(struct Struct_020727d8* list) {
    func_020727d8(list);
}
