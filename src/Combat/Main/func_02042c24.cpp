#include <globaldefs.h>

struct Struct_02042c24 {
    unsigned short x;
    unsigned short y;
};

struct Struct_02042b98_3 {
    char unk[0x440];
    struct Struct_02042c24* unknown_440_;
};

// USA: func_02042c24
extern "C" ARM void func_02042c24(struct Struct_02042b98_3* holder, int x, int y) {
    if (holder->unknown_440_ != 0) {
        holder->unknown_440_->x = x;
        holder->unknown_440_->y = y;
    }
}
