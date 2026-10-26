#include <globaldefs.h>

struct Struct_0207f524;
extern "C" void func_0207f7cc(struct Struct_0207f524* list, int id, int mask);

// USA: func_020806c4
extern "C" ARM void func_020806c4(void* obj, int id) {
    func_0207f7cc((struct Struct_0207f524*)((char*)obj + 4), id, 2);
}
