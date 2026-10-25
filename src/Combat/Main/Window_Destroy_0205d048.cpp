#include <globaldefs.h>

struct Struct_0205c53c;
void ForwardInitChannelPair0205c564(struct Struct_0205c53c* s);
struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);
struct BackgroundGraphics;
void Background_Destroy(struct BackgroundGraphics* obj);

struct Struct_0205d048 {
    char unknown_0_[0x98];
    char* unknown_98_;
    char* unknown_9c_;
    char unknown_a0_[0xb2 - 0xa0];
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
};

// Main, originally func_0205d048 (USA 0x0205d048, EUR 0x0205d058, JPN 0x0205e378)
extern "C" ARM void Window_Destroy(struct Obj0205d048* obj) {
    ForwardInitChannelPair0205c564((struct Struct_0205c53c*)obj);
    if (obj->field9c != 0 && obj->fieldb3 != 0) {
        unsigned char i;
        for (i = 0; i < obj->fieldb3; i++) {
            ResetObject0204c754((struct Obj0204c754*)(obj->field9c + i * 0xe0));
        }
    }
    if (obj->field98 != 0) {
        unsigned char i;
        for (i = 0; i < obj->fieldb2; i++) {
            Background_Destroy((struct BackgroundGraphics*)(obj->field98 + i * 0x20));
        }
    }
    arg0->unknown_98_ = 0;
    arg0->unknown_9c_ = 0;
    arg0->unknown_b3_ = 0;
    arg0->unknown_b4_ = 0;
}
