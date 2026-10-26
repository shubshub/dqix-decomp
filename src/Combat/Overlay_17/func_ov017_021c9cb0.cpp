#include <globaldefs.h>

extern "C" void func_ov017_021c9954(int a, int b, int c, void* d);

struct Struct_ov017_021c9cb0 {
    char pad[4];
    unsigned short h4;
    unsigned char unknown_6_;
};

// USA: func_ov017_021c9cb0
extern "C" ARM void func_ov017_021c9cb0(void* self, Struct_ov017_021c9cb0* s) {
    func_ov017_021c9954(s->h4, 1, s->unknown_6_ != 0, self);
}
