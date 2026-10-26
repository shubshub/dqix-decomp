#include <globaldefs.h>

struct Struct_02072a68 {
    short key;
    void* value;
};

struct TableA68 {
    struct Struct_02072a68* entries;
    short count;
};

// USA: func_02072a68
extern "C" ARM void* func_02072a68(struct TableA68* table, int key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->entries[i].key) {
            return table->entries[i].value;
        }
    }
    return 0;
}
