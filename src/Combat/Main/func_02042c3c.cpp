#include <globaldefs.h>

struct Struct_02042c3c {
    char unk[0x4];
    unsigned short width;
    unsigned short height;
};

struct Struct_02042b98 {
    char unk[0x440];
    struct Struct_02042c3c* unknown_440_;
};

// USA: func_02042c3c
extern "C" ARM void func_02042c3c(struct Struct_02042b98* holder, int width, int height) {
    if (holder->unknown_440_ != 0) {
        holder->unknown_440_->width = width;
        holder->unknown_440_->height = height;
    }
}
