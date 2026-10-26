#include <globaldefs.h>

struct Struct_0207f6ac {
    unsigned char unknown0[0x2a];
    unsigned char flags;
    unsigned char unknown_2b_[5];
};
struct Struct_0207f524 {
    Struct_0207f6ac* entries;
    short count;
};
struct Struct_02080dd4 {
    void* unknown_0_;
    Struct_0207f524 items;
};

extern "C" int func_02080e40(void* menu, int arg1, int x, int y);
extern "C" struct Struct_0207f6ac* func_0207f6ac(struct Struct_0207f524* list, int id);

extern "C" void func_02080558(void* obj, int p1, int result, int flag, unsigned char extra);

// USA: func_02080dd4
extern "C" ARM int func_02080dd4(void* arg0, int arg1, int arg2, int arg3,
                                  unsigned char* arg4, unsigned char arg5) {
    Struct_02080dd4* menu = static_cast<Struct_02080dd4*>(arg0);
    int result;
    struct Struct_0207f6ac* entry;
    result = func_02080e40(menu, arg1, arg2, arg3);
    if (result == -1) {
        return -1;
    }
    *arg4 = 0;
    entry = func_0207f6ac(&menu->items, result);
    if (entry->flags & 4) {
        *arg4 = 1;
    }
    func_02080558(menu, arg1, result, 1, arg5);
    return result;
}
