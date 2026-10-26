#include <globaldefs.h>

struct Struct_020bc210 {
    char unk[0x34];
    unsigned short type;
    unsigned short pad;
    unsigned short param1;
    unsigned short param2;
};

struct Struct_02061c04_19 {
    struct Struct_020bc210* ptr;
};

// USA: func_020bc210
extern "C" ARM void func_020bc210(struct Struct_02061c04_19* obj, int param1, int param2) {
    if (*(int*)obj == 0) {
        return;
    }
    obj->ptr->type = 2;
    obj->ptr->param1 = param1;
    obj->ptr->param2 = param2;
}
