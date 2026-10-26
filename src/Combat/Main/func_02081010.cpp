#include <globaldefs.h>

struct Struct_0207f524;
struct TableA68;

struct Struct_02081010 {
    char pad[0xe];
    short key;
};

extern "C" struct Struct_02081010* func_0207f6ac(struct Struct_0207f524* list, int id);
extern "C" void* func_02072a68(struct TableA68* table, int key);

// USA: func_02081010
extern "C" ARM void* func_02081010(void* obj, int id) {
    struct Struct_02081010* e = func_0207f6ac((struct Struct_0207f524*)((char*)obj + 0x4), id);
    if (e == NULL) {
        return NULL;
    }
    return func_02072a68(*(struct TableA68**)obj, e->key);
}
