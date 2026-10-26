#include <globaldefs.h>

extern "C" void InitializeVCountAlarmList();

struct Struct_020c93bc;
extern "C" void func_020c93bc(struct Struct_020c93bc* p);

extern "C" void func_020dbc0c(void);
extern "C" void func_020c93d0(void*, int, int, void*, void*);

// USA: func_020db228
extern "C" ARM void func_020db228(void* obj) {
    InitializeVCountAlarmList();
    struct Struct_020c93bc* sub = (struct Struct_020c93bc*)((char*)obj + 0x14);
    func_020c93bc(sub);
    func_020c93d0(sub, 0xe1, 0x1e, (void*)func_020dbc0c, obj);
}
