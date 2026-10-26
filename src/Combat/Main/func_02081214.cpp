#include <globaldefs.h>

struct TableA68;

extern "C" void* func_02072a68(struct TableA68* table, int key);

struct Struct_02081214 {
    struct TableA68* table;
};

// USA: func_02081214
extern "C" ARM void* func_02081214(struct Struct_02081214* arg0, int key) {
    return func_02072a68(arg0->table, key);
}
