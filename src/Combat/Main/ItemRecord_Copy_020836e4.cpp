#include <globaldefs.h>
struct Record020836e4 {
    int field_0;
    int unknown_4_;
    int field_8;
    int unknown_c_;
    int unknown_10_;
    unsigned short unknown_14_;
    unsigned short unknown_16_;
    short field_18;
    unsigned short field_1a;
    unsigned short field_1c;
};
// Main, originally CopyStruct020836e4 (USA 0x020836e4, EUR 0x020836f4, JPN 0x02083fdc)
extern "C" ARM void ItemRecord_Copy(struct Record020836e4* dst, struct Record020836e4* src) {
    dst->field_0 = src->field_0;
    dst->unknown_4_ = src->unknown_4_;
    dst->field_8 = src->field_8;
    dst->unknown_c_ = src->unknown_c_;
    dst->unknown_10_ = src->unknown_10_;
    dst->unknown_14_ = src->unknown_14_;
    dst->unknown_16_ = src->unknown_16_;
    dst->field_18 = src->field_18;
    dst->field_1a = src->field_1a;
    dst->field_1c = src->field_1c;
}
