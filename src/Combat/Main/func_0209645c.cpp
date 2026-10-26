#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_020960cc(int unused, unsigned char* arr, int index);

struct Struct_0209645c {
    unsigned int id : 9;
    unsigned char pad[12];
};

struct Struct_0209645c_2 {
    unsigned char count;
    unsigned char pad[3];
    Struct_0209645c entries[9];
};

// USA: func_0209645c
extern "C" ARM int func_0209645c(Struct_0209645c_2* list, int value) {
    if (value < 0 || list->count == 0) return 0;
    int i;
    for (i = 0; i < list->count; i++) {
        if (value == (int)list->entries[i].id) break;
    }
    if (i == list->count) return 0;
    func_020960cc((int)list, (unsigned char*)list + 0x4a8, value);
    Struct_0209645c var1[9];
    memset(var1, 0, sizeof(var1));
    memcpy(var1, list->entries, 0x80);
    memcpy(&list->entries[i], &var1[i + 1], (list->count - i) * 16);
    list->count = list->count - 1;
    return 1;
}
