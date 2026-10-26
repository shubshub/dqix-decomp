#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_0215b6c0 func_ov002_0215c914
#endif

struct Struct_ov002_0215b6c0 {
#if defined(jpn)
    char unknown0[0x1a94];
#else
    char unknown0[0x1bcc];
#endif
    int unknown_1bcc_;
};

extern "C" void func_ov002_0215b9a4(Struct_ov002_0215b6c0* menu, unsigned char key, int flag);

// USA: func_ov002_0215b6c0
extern "C" ARM void func_ov002_0215b6c0(Struct_ov002_0215b6c0* obj) {
    obj->unknown_1bcc_ = 1;
#if defined(jpn)
    func_ov002_0215b9a4(obj, 0x11, 1);
    func_ov002_0215b9a4(obj, 0x14, 0);
    func_ov002_0215b9a4(obj, 8, 1);
    func_ov002_0215b9a4(obj, 9, 0);
#else
    func_ov002_0215b9a4(obj, 0x10, 1);
    func_ov002_0215b9a4(obj, 0x13, 0);
    func_ov002_0215b9a4(obj, 7, 1);
    func_ov002_0215b9a4(obj, 8, 0);
#endif
    func_ov002_0215b9a4(obj, 4, 1);
}
