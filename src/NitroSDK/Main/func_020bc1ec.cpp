#include <globaldefs.h>

struct Struct_020bc1ec_2 {
    char unk[0x34];
    unsigned short field34;
    char unknown_36_[0x2];
    unsigned short field38;
};

struct Holder {
    struct Struct_020bc1ec_2* volatile ptr;
};

// USA: func_020bc1ec
extern "C" ARM void func_020bc1ec(struct Holder* holder, int value) {
    if (holder->ptr != 0) {
        holder->ptr->field34 = 1;
        holder->ptr->field38 = value;
        return;
    }
}
