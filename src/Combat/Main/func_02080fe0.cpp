#include <globaldefs.h>

struct Struct_0207f524;
struct TableA68;

struct Struct_02080fe0 {
    void* result;
};

extern "C" struct Struct_02080fe0* func_0207f6ac(struct Struct_0207f524* list, int id);
extern "C" void* func_02072a68(struct TableA68* table, int key);

// USA: func_02080fe0
extern "C" ARM void func_02080fe0(void* obj, int id, int key) {
    struct Struct_02080fe0* e = func_0207f6ac((struct Struct_0207f524*)((char*)obj + 0x4), id);
    if (e == NULL) {
        return;
    }
    e->result = func_02072a68(*(struct TableA68**)obj, key);
}
