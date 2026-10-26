#include <globaldefs.h>

struct Struct_0206f7f4 {
    int field0;
    int count;
    short values[1];
};

// USA: func_0206f7f4
extern "C" ARM int func_0206f7f4(struct Struct_0206f7f4 *list, int index) {
    if (index < 0 || list->count <= index) {
        return -1;
    }
    return list->values[index];
}
