#include <globaldefs.h>

union Struct_02086868_5 { unsigned char bytes[13]; };
union Struct_02086868_11 { int words[13]; };
union Struct_02086868 { int words[39]; };
union Struct_02086868_2 { unsigned char bytes[27]; };
union Struct_02086868_3 { unsigned char bytes[9]; };
union Struct_02086868_4 { unsigned char bytes[36]; };
union Struct_02086868_6 { unsigned char bytes[12]; };
union Struct_02086868_7 { int words[5]; };
union Struct_02086868_8 { unsigned short halfwords[14]; };
union Struct_02086868_9 { unsigned short halfwords[96]; };

struct Struct_02086868_10 {
    signed char unknown_0_;
    unsigned char unknown_1_;
    Struct_02086868_5 unknown_2_;
    Struct_02086868_5 unknown_f_;
    Struct_02086868_11 field1c;
    int unknown_50_;
    unsigned short field54;
    unsigned char unknown_56_[2];
    Struct_02086868 unknown_58_;
    unsigned short unknown_f4_;
    Struct_02086868_2 unknown_f6_;
    Struct_02086868_3 unknown_111_;
    Struct_02086868_4 unknown_11a_;
    unsigned char unknown_13e_;
    unsigned char unknown_13f_;
    Struct_02086868_6 unknown_140_;
    Struct_02086868_7 unknown_14c_;
    Struct_02086868_8 unknown_160_;
    Struct_02086868_9 unknown_17c_;
};

// USA: func_02086868
extern "C" ARM void* func_02086868(void* destination, void* source) {
    Struct_02086868_10* dst = (Struct_02086868_10*)destination;
    Struct_02086868_10* src = (Struct_02086868_10*)source;
    dst->unknown_0_ = src->unknown_0_;
    dst->unknown_1_ = src->unknown_1_;
    dst->unknown_2_ = src->unknown_2_;
    dst->unknown_f_ = src->unknown_f_;
    dst->field1c = src->field1c;
    dst->unknown_50_ = src->unknown_50_;
    dst->field54 = src->field54;
    dst->unknown_58_ = src->unknown_58_;
    dst->unknown_f4_ = src->unknown_f4_;
    dst->unknown_f6_ = src->unknown_f6_;
    dst->unknown_111_ = src->unknown_111_;
    dst->unknown_11a_ = src->unknown_11a_;
    dst->unknown_13e_ = src->unknown_13e_;
    dst->unknown_13f_ = src->unknown_13f_;
    dst->unknown_140_ = src->unknown_140_;
    dst->unknown_14c_ = src->unknown_14c_;
    dst->unknown_160_ = src->unknown_160_;
    dst->unknown_17c_ = src->unknown_17c_;
    return destination;
}
