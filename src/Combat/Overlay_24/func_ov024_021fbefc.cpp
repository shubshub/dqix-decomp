#include <globaldefs.h>

struct Struct_ov024_021fbefc {
    char unk[0xc];
    int state;
};

extern "C" void func_ov024_021fd954(struct Struct_ov024_021fbefc* obj, int mode);

// USA: func_ov024_021fbefc
extern "C" ARM void func_ov024_021fbefc(struct Struct_ov024_021fbefc* obj) {
    if (obj->state >= 3) {
        func_ov024_021fd954(obj, 4);
    }
}
