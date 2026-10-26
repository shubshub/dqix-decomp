#include <globaldefs.h>

struct Struct_0209b944 {
    char data[8];
};
struct Struct_0209b448_5 {
    unsigned short id;
    char pad[2];
    struct Struct_0209b944 arr[9];
};

// USA: func_0209b944
extern "C" ARM struct Struct_0209b944* func_0209b944(struct Struct_0209b448_5* entries, int index, int key, int* arg3) {
    int i;
    for (i = 0; i < 6; i++) {
        if (key == entries[i].id) {
            *arg3 = i;
            return &entries[i].arr[index];
        }
    }
    return NULL;
}
