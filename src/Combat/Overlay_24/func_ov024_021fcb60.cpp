#include <globaldefs.h>

struct Struct_ov024_021fc37c;
extern "C" int func_ov024_021fc498(struct Struct_ov024_021fc37c* obj);

extern "C" void func_ov024_021fb91c(void* obj);

struct Struct_021fcb60 {
    char unk0[0x6];
    unsigned char type;
    char unknown_7_;
    struct Struct_ov024_021fc37c* field8;
    int unknown_c_;
    char unk10[0x124 - 0x10];
    float unknown_124_;
};

// USA: func_ov024_021fcb60
extern "C" ARM void func_ov024_021fcb60(struct Struct_021fcb60* obj) {
    float saved = obj->unknown_124_;
    obj->unknown_124_ = 0.6f;
    if (obj->type == 3) {
        obj->unknown_124_ = 0.65f;
    }
    if (!(func_ov024_021fc498(obj->field8) > 2 && obj->unknown_c_ > 2)) {
        obj->unknown_124_ += 0.2f;
    }
    func_ov024_021fb91c(obj);
    obj->unknown_124_ = saved;
}
