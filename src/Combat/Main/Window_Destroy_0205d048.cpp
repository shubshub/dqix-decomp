#include <globaldefs.h>

struct Struct_0205c53c;
extern "C" void func_0205c564(struct Struct_0205c53c* s);
struct Struct_0204c754;
extern "C" void func_0204c754(struct Struct_0204c754* obj);
struct BackgroundGraphics;
extern "C" void Background_Destroy(struct BackgroundGraphics* obj);

struct Obj0205d048 {
    char pad0[0x98];
    char* field98;
    char* unknown_9c_;
    char pad1[0xb2 - 0xa0];
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
};

// Main, originally func_0205d048 (USA 0x0205d048, EUR 0x0205d058, JPN 0x0205e378)
extern "C" ARM void Window_Destroy(struct Obj0205d048* obj) {
    func_0205c564((struct Struct_0205c53c*)obj);
    if (obj->unknown_9c_ != 0 && obj->unknown_b3_ != 0) {
        unsigned char i;
        for (i = 0; i < obj->unknown_b3_; i++) {
            func_0204c754((struct Struct_0204c754*)(obj->unknown_9c_ + i * 0xe0));
        }
    }
    if (obj->field98 != 0) {
        unsigned char i;
        for (i = 0; i < obj->unknown_b2_; i++) {
            Background_Destroy((struct BackgroundGraphics*)(obj->field98 + i * 0x20));
        }
    }
    obj->field98 = 0;
    obj->unknown_9c_ = 0;
    obj->unknown_b3_ = 0;
    obj->unknown_b4_ = 0;
}
