#include <globaldefs.h>

#if defined(jpn)
#define func_02046c78 func_02047a98
#endif

struct Struct_02046c78_2 {
    char pad[4];
    struct Struct_02046c78_2* next;
};

struct CountHead {
    struct Struct_02046c78_2* first;
};

// USA: func_02046c78
extern "C" ARM int func_02046c78(struct CountHead* head) {
    int count = 0;
    struct Struct_02046c78_2* n = head->first;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
