#include <globaldefs.h>

extern "C" void func_02098364(void* entry);

struct Struct_02098970_2 { unsigned char b[0xe8]; };
struct Struct_02098970 {
    struct Struct_02098970_2 entries[0x1e];
};

// USA: func_02098970
extern "C" ARM int func_02098970(struct Struct_02098970* pool, struct Struct_02098970_2* target) {
    int i;
    int found = 0;
    struct Struct_02098970_2* e;
    for (i = 0; i < 0x1e; i++) {
        e = &pool->entries[i];
        if (target == e) {
            found = 1;
            break;
        }
    }
    if (found == 0) return 0;
    *(int*)((char*)pool + 0x1b38) -= 1;
    func_02098364(e);
    return 1;
}
