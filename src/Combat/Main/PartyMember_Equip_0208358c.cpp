#include <globaldefs.h>
#include <std_library_functions.h>
#if defined(jpn)
extern "C" int STD_GetStringLength(const char*);
#endif
struct Struct_0208358c { int field_0x0, unknown_4_, unknown_8_, unknown_c_, field_0x10, unknown_14_, unknown_18_, field_0x1c; };
struct Record020836e4 { Struct_0208358c* block; char* text; unsigned int flags:4; unsigned int rest:28; char tail[20]; };
struct Object0208358c { char pad[0x194]; Record020836e4 records[11];
#if defined(jpn)
    char pad2[0x364];
#else
    char pad2[0x3fc];
#endif
    Struct_0208358c blocks[11]; };
struct StructDE1D4;
extern "C" void ItemRecord_Clear(StructDE1D4*);
extern "C" void ItemRecord_Copy(Record020836e4*, Record020836e4*);
extern "C" unsigned char* func_0208349c(unsigned char*, int);
// Main, originally func_0208358c (USA 0x0208358c, EUR 0x0208359c, JPN 0x02083e74)
extern "C" ARM void PartyMember_Equip(Object0208358c* obj, Record020836e4* src, int arg) {
    if (!src) return;
    int index = -1;
    switch (src->flags) {
    case 0: index = 8; break;
    case 1: index = 9; break;
    case 4: index = 7; break;
    case 2: index = 0; break;
    case 5: index = 5; break;
    case 3: index = 1; break;
    case 6: index = 6; break;
    case 7: index = 10; break;
    case 11: index = arg; break;
    }
    if (index < 0) return;
    Record020836e4* dst = &obj->records[index];
    Struct_0208358c* out = dst->block;
    char* text = dst->text;
    Struct_0208358c* in = src->block;
    out->field_0x0 = in->field_0x0; out->unknown_4_ = in->unknown_4_; out->unknown_8_ = in->unknown_8_; out->unknown_c_ = in->unknown_c_;
    out->field_0x10 = in->field_0x10; out->unknown_14_ = in->unknown_14_; out->unknown_18_ = in->unknown_18_; out->field_0x1c = in->field_0x1c;
#if defined(jpn)
    memset(text, 0, 0x14);
    if (src->text) { memcpy(text, src->text, STD_GetStringLength(src->text)); }
#else
    *text = 0;
    if (src->text) { memset(text, 0, 0x30); sprintf(text, src->text); }
#endif
    ItemRecord_Clear((StructDE1D4*)dst);
    ItemRecord_Copy(dst, src);
    dst->block = &obj->blocks[index];
#if defined(jpn)
    dst->text = (char*)obj + 0x56f + index * 0x15;
#else
    dst->text = (char*)func_0208349c((unsigned char*)obj, index);
#endif
}
