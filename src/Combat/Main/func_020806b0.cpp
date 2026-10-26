#include <globaldefs.h>

struct Struct_0207f6ac;
struct Struct_0207f524 { Struct_0207f6ac* entries; short count; };
struct Struct_020806b0 {
    void* table;
    Struct_0207f524 items;
};
extern "C" void func_0207f7ac(struct Struct_0207f524* list, int id, int mask);

// USA: func_020806b0
extern "C" ARM void func_020806b0(void* obj, int id) {
    Struct_020806b0* menu = (Struct_020806b0*)obj;
    func_0207f7ac(&menu->items, id, 2);
}
