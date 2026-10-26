#include <globaldefs.h>

struct Struct_ov025_021e3048_2 {
    short* entryList;
    char unknown4[0x3c - 4];
};
struct Struct_ov025_021e3048 {
    char unknown0[0x540];
    Struct_ov025_021e3048_2 event;
};
struct Struct_ov025_021ef988_6 {
#if defined(jpn)
    char unknown0[4];
#else
    char unknown0[0xc];
#endif
    Struct_ov025_021e3048* context;
};
extern Struct_ov025_021ef988_6 data_ov025_021ef988;
extern "C" void func_ov025_021e2f54(Struct_ov025_021e3048_2*, short*, char*);
extern "C" void func_ov025_021e3084(Struct_ov025_021e3048_2*);

// USA: func_ov025_021e3048
extern "C" ARM int func_ov025_021e3048(void*, short* entryList, void*, char* world) {
    Struct_ov025_021e3048* context = data_ov025_021ef988.context;
    func_ov025_021e3084(&context->event);
    context->event.entryList = entryList;
    func_ov025_021e2f54(&context->event, entryList, world);
    return 1;
}
