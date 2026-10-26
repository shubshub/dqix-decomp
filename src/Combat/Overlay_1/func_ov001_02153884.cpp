#include <globaldefs.h>

struct Struct_ov001_02153884 { int key; int val; };
struct Struct_ov001_021658d8 { struct Struct_ov001_02153884* pairs; int count; };

// USA: func_ov001_02153884
extern "C" ARM void* func_ov001_02153884(struct Struct_ov001_021658d8* t, int key) {
    for (int i = 0; i < t->count; i++) {
        if (t->pairs[i].key == key) {
            struct Struct_ov001_02153884* e = &t->pairs[i];
            if (e->val == 0) return NULL;
            return e;
        }
    }
    return NULL;
}
