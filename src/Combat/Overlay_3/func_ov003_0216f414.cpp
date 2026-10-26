#include <globaldefs.h>

struct Struct_ov003_0216f414 {
    short id;
    char pad[0x18 - 2];
};

struct Struct_ov003_0216efdc_2 {
    char pad0[8];
    struct Struct_ov003_0216f414* arr;
    char pad1[0x14 - 0xc];
    unsigned short count;
};

// USA: func_ov003_0216f414
extern "C" ARM void* func_ov003_0216f414(struct Struct_ov003_0216efdc_2* obj, int key) {
    struct Struct_ov003_0216f414* arr = obj->arr;
    unsigned short count;
    unsigned short i;
    if (arr == NULL) {
        return 0;
    }
    count = obj->count;
    if (count == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        short id = arr[i].id;
        if (id == key) {
            return &arr[i];
        }
    }
    return 0;
}
