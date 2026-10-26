#include <globaldefs.h>

struct Struct_ov023_021f5534_2 {
    unsigned int val : 26;
    unsigned int rest : 6;
};

struct Struct_ov023_021f5534 {
    unsigned int count : 12;
    unsigned int pad0 : 20;
    struct Struct_ov023_021f5534_2* arr;
};

// USA: func_ov023_021f5534
extern "C" ARM struct Struct_ov023_021f5534_2* func_ov023_021f5534(struct Struct_ov023_021f5534* obj, int val) {
    struct Struct_ov023_021f5534_2* arr = obj->arr;
    while (obj->count != 0) {
        unsigned int e = arr->val;
        if (e == 0 || val <= (int)e) return arr;
        arr = arr + 1;
    }
    return 0;
}
