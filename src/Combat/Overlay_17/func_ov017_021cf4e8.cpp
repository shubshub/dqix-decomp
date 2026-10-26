#include <globaldefs.h>

struct Entry_02028bd0;
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

struct Struct_ov017_021cf4e8 { unsigned short unknown_0_0_:4; unsigned short unknown_0_4_:12; };

// USA: func_ov017_021cf4e8
extern "C" ARM void func_ov017_021cf4e8(void* arg0, unsigned char* entry, unsigned char* table, unsigned char* ctx) {
#if defined(jpn)
 enum {regionalOffset0=0xca2, regionalOffset1=0xca6, regionalOffset2=0x204, regionalOffset3=0x4000};
#else
 enum {regionalOffset0=0xf76, regionalOffset1=0xf7a, regionalOffset2=0xb4, regionalOffset3=0x4400};
#endif
    int inRange = entry[4] <= 3;
    if (inRange) {
        unsigned char* p = table + entry[4] + 0x7000;
        p[regionalOffset0] = entry[5];
        if (entry[5] == 2) {
            unsigned char* dst = ctx + regionalOffset2 + regionalOffset3;
            unsigned short* zone = Zone3D_GetInstance();
            struct Entry_02028bd0* found = ZoneRecords_Find(ZoneRecords_GetInstance(), *zone);
            if (found != 0) {
                *(unsigned short*)dst = *zone;
                *(unsigned short*)(dst + 2) = ((struct Struct_ov017_021cf4e8*)((char*)found + 2))->unknown_0_4_;
            }
        }
    } else {
        unsigned char* p = table + entry[4] + 0x7000;
        p[regionalOffset0] = 5;
    }
    table[0x7000 + regionalOffset1] = table[0x7000 + regionalOffset1] | (1 << entry[4]);
}
