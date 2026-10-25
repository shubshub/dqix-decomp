#include <globaldefs.h>
#include <std_library_functions.h>
#if defined(jpn)
int STD_GetStringLength(const char*);
#endif
struct Struct_0208358c { int unknown_0_, unknown_4_, unknown_8_, unknown_c_, unknown_10_, unknown_14_, unknown_18_, unknown_1c_; };
struct Struct_0208358c_2 { Struct_0208358c* unknown_0_; char* unknown_4_; unsigned int unknown_8_0_:4; unsigned int unknown_8_4_:28; char unknown_c_[20]; };
struct Struct_0208358c_3 { char unknown_0_[0x194]; Struct_0208358c_2 unknown_194_[11];
#if defined(jpn)
    char unknown_2f4_[0x364];
#else
    char unknown1_2f4_[0x3fc];
#endif
    Block0208358c blocks[11]; };
struct StructDE1D4;
void ItemRecord_Clear(StructDE1D4*);
void ItemRecord_Copy(Record020836e4*, Record020836e4*);
unsigned char* GetIndexedBlockPointer0208349c(unsigned char*, int);
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
    if (var0 < 0) return;
    Struct_0208358c_2* var1 = &arg0->unknown_194_[var0];
    Struct_0208358c* var2 = var1->unknown_0_;
    char* var3 = var1->unknown_4_;
    Struct_0208358c* var4 = arg1->unknown_0_;
    var2->unknown_0_ = var4->unknown_0_; var2->unknown_4_ = var4->unknown_4_; var2->unknown_8_ = var4->unknown_8_; var2->unknown_c_ = var4->unknown_c_;
    var2->unknown_10_ = var4->unknown_10_; var2->unknown_14_ = var4->unknown_14_; var2->unknown_18_ = var4->unknown_18_; var2->unknown_1c_ = var4->unknown_1c_;
#if defined(jpn)
    memset(text, 0, 0x14);
    if (src->text) { memcpy(text, src->text, STD_GetStringLength(src->text)); }
#else
    *var3 = 0;
    if (arg1->unknown_4_) { memset(var3, 0, 0x30); sprintf(var3, arg1->unknown_4_); }
#endif
    ItemRecord_Clear((StructDE1D4*)dst);
    ItemRecord_Copy(dst, src);
    dst->block = &obj->blocks[index];
#if defined(jpn)
    var1->unknown_4_ = (char*)arg0 + 0x56f + var0 * 0x15;
#else
    var1->unknown_4_ = (char*)func_0208349c((unsigned char*)arg0, var0);
#endif
}
