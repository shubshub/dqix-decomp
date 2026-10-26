#include <globaldefs.h>

struct Struct_02048228_3 {
    unsigned short pad0;
    unsigned short pad2;
    unsigned short value;
};

struct Struct_02048228_2 {
    char pad[0x30];
    unsigned short cap;
};

struct Struct_02048228 {
    char pad[0x130];
    struct Struct_02048228_3* current;
    struct Struct_02048228_2* base;
};

// USA: func_02048228
extern "C" ARM int func_02048228(struct Struct_02048228* c, int amount) {
    struct Struct_02048228_3* current = c->current;
    struct Struct_02048228_2* base = c->base;
    int diff = base->cap - current->value;
    if (diff <= 0) {
        return 0;
    }
    if (diff <= amount) {
        current->value = base->cap;
        return diff;
    }
    current->value = current->value + amount;
    return amount;
}
