#include <globaldefs.h>
extern "C" void* func_020bd454(int);

extern "C" int func_020be828(void* a, unsigned char b, unsigned short c, unsigned char d, void* e, void* f);

struct Struct_020be760 {
    char pad0[4];
    unsigned short field4;
    char pad6[2];
    unsigned char field8;
    unsigned char field9;
};

// Main, originally LookupRecordAndDispatch020be760 (USA 0x020be760, EUR 0x020be770, JPN 0x020c022c)
extern "C" ARM int NNS_SndArcPlayerStartSeq(void* a, void* key) {
    struct Struct_020be760* rec = (struct Struct_020be760*)func_020bd454((int)(key));
    if (rec == NULL) return 0;
    return func_020be828(a, rec->field9, rec->field4, rec->field8, rec, key);
}
