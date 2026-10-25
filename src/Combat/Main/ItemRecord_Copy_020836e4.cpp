#include <globaldefs.h>
struct Record020836e4 {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    unsigned short field_14;
    unsigned short field_16;
    short field_18;
    unsigned short field_1a;
    unsigned short field_1c;
};
// Main, originally CopyStruct020836e4 (USA 0x020836e4, EUR 0x020836f4, JPN 0x02083fdc)
ARM void ItemRecord_Copy(struct Record020836e4* dst, struct Record020836e4* src) {
    dst->field_0 = src->field_0;
    dst->field_4 = src->field_4;
    dst->field_8 = src->field_8;
    dst->field_c = src->field_c;
    dst->field_10 = src->field_10;
    dst->field_14 = src->field_14;
    dst->field_16 = src->field_16;
    dst->field_18 = src->field_18;
    dst->field_1a = src->field_1a;
    dst->field_1c = src->field_1c;
}
