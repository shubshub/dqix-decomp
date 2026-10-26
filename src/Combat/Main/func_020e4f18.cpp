#include <globaldefs.h>
#include "std_library_functions.h"
struct Struct_020e4f18_2 { unsigned int unknown_0_0_:6, unknown_0_6_:6, unknown_1_4_:6, unknown_2_2_:6, unknown_3_0_:2, unknown_3_2_:1, unknown_3_3_:1, unknown_3_4_:1, pad:2, flag:1; };
struct Struct_020e4f18 { char* name; char* text; Struct_020e4f18_2 bits; };
// USA: func_020e4f18
extern "C" ARM void func_020e4f18(Struct_020e4f18* src, Struct_020e4f18* dest, int flags) {
    if (!src || !dest) return;
    if (flags & 1) {
        char* text = dest->text;
        sprintf(dest->name, src->name);
        sprintf(text, src->text);
    }
    if (flags & 2) {
        dest->bits.unknown_0_0_ = src->bits.unknown_0_0_;
        dest->bits.unknown_0_6_ = src->bits.unknown_0_6_;
        dest->bits.unknown_1_4_ = src->bits.unknown_1_4_;
        dest->bits.unknown_2_2_ = src->bits.unknown_2_2_;
    }
    dest->bits.unknown_3_0_ = src->bits.unknown_3_0_;
    dest->bits.unknown_3_2_ = src->bits.unknown_3_2_;
    dest->bits.unknown_3_3_ = src->bits.unknown_3_3_;
    dest->bits.unknown_3_4_ = src->bits.unknown_3_4_;
    dest->bits.flag = src->bits.flag;
}
