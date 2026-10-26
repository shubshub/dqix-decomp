#include <globaldefs.h>

extern "C" void func_0202c848(int slot);
extern "C" void WH_Reset(void);
extern "C" int func_020d5214(int callback);
extern "C" int func_0202cd28(unsigned short*);

struct Struct_0202ccdc {
    char pad0[2];
    unsigned short f2;
};

// USA: func_0202ccdc
extern "C" ARM void func_0202ccdc(struct Struct_0202ccdc* obj) {
    if (obj->f2 != 0) {
        func_0202c848(obj->f2);
        WH_Reset();
        return;
    }
    int result = func_020d5214((int)func_0202cd28);
    int done;
    if (result == 2) {
        done = 1;
    } else {
        func_0202c848(result);
        done = 0;
    }
    if (done) return;
    WH_Reset();
}
