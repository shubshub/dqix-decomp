#ifndef SYSTEM_OVERLAY_MD5_H
#define SYSTEM_OVERLAY_MD5_H

#include <globaldefs.h>

struct Struct_ov031_02221e84 {
    unsigned int state[4];
    unsigned int unknown_10_[2];
    unsigned char buffer[64];
};

#if defined(jpn)
#define data_ov031_0224b194 data_ov031_0224bd94
#endif

extern "C" {
void func_ov031_02221e84(Struct_ov031_02221e84*);
void func_ov031_02221eac(Struct_ov031_02221e84*, const void*, unsigned int);
void func_ov031_02221f24(unsigned char*, Struct_ov031_02221e84*);
void func_ov031_022227c0(unsigned char*, const unsigned int*, unsigned int);
void func_ov031_02222830(void*, int, unsigned int);
}

#endif
