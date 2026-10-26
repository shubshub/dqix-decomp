#include <globaldefs.h>

extern "C" void func_020d21f8(void);
extern "C" void func_020d220c(void);
void CleanCacheRange(const void* addr, unsigned int size);

struct Struct_020d2c98 {
    int field0;
    struct Struct_020d2c98* next;
};
struct Struct_020d2c98_2 {
    char pad[0x18];
    struct Struct_020d2c98* head;
};

// USA: func_020d2c98
extern "C" ARM void func_020d2c98(int a) {
    struct Struct_020d2c98_2* obj = (struct Struct_020d2c98_2*)a;
    struct Struct_020d2c98* node;
    func_020d21f8();
    node = obj->head;
    if (node != NULL) {
        do {
            struct Struct_020d2c98* next = node->next;
            node->field0 = 0;
            node->next = 0;
            CleanCacheRange((const void*)((int)node), 8);
            node = next;
        } while (node != NULL);
    }
    func_020d220c();
}
