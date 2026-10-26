#include <globaldefs.h>

struct Struct_ov031_0220357c_2 { unsigned char pad[8]; unsigned char type; unsigned char unknown_9_; };
struct Struct_ov031_0220357c { unsigned char pad[0xa4]; Struct_ov031_0220357c_2* node; };
struct Struct_02111304_4 { unsigned char pad[4]; Struct_ov031_0220357c* unknown_4_; };

extern Struct_02111304_4 data_02111304;
extern "C" ARM int func_ov031_022034ac(unsigned int* out, void* obj);
extern "C" int func_ov031_0220a594(unsigned int* out, void* obj);
extern "C" ARM int func_ov031_02203500(unsigned int* out, void* obj);

// USA: func_ov031_0220357c
extern "C" ARM int func_ov031_0220357c(unsigned int* out) {
    Struct_ov031_0220357c_2* node = data_02111304.unknown_4_->node;
    if (node) {
        if ((unsigned char)(node->type + 0xf6) <= 1) return func_ov031_022034ac(out, node);
        if (node->unknown_9_) return func_ov031_0220a594(out, node);
        return func_ov031_02203500(out, node);
    }
    *out = 0;
    return 0;
}
