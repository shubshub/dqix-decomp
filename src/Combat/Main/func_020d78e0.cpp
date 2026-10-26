#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_0214e33c {
    short field0;
    short pad2;
    void* field4;
    void* field8;
    void* fieldC;
};
extern struct Struct_0214e33c data_0214e33c;

struct Struct_020d78e0 {
    short field0;
    short field2;
    int field4;
    void* next;
};

// USA: func_020d78e0
extern "C" ARM void func_020d78e0(void** arg0, void* arg1) {
    void** slot = arg0;
    while (*slot != NULL) {
        slot = (void**)((char*)*slot + 8);
    }
    struct Struct_020d78e0* node = (struct Struct_020d78e0*)((SafeAllocator*)data_0214e33c.field8)->Allocate(0xc);
    *slot = node;
    if (node == NULL) return;
    node->field0 = -1;
    node->field2 = -1;
    node->field4 = 0;
    node->next = NULL;
    memcpy(*slot, arg1, 8);
}
