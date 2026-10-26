#pragma once

#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/MessageGlyphSlot.h"

#if defined(jpn)

struct Struct_020439b0 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
};
struct Struct_0204500c {
    Struct_020439b0 prefix;
    unsigned char reserved[0x21];
};
struct Struct_020439b0_2 {
    unsigned char unknown_0_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char remaining : 2;
};
struct Foo0207df50;
struct Struct_0204394c;
struct MessageSystem0219050c;

struct MessageSystem {
    unsigned char pad0[4];
    void* frame;
    unsigned char pad8[4];
    int unknown_40_;
    int unknown_44_;
    void* textBuffer;
    unsigned short* unknown_4c_;
    void* unknown_1c_;
    unsigned short* unknown_20_;
    unsigned short* unknown_24_;
    unsigned char pad28[4];
    char* unknown_2c_;
    char* unknown_30_;
    unsigned int tokenLength;
    unsigned int unknown_6c_;
    unsigned char unknown_3c_[4];
    int unknown1_40_;
    unsigned int unknown_78_;
    unsigned char unknown_48_[4];
    unsigned char* child;
    unsigned char unknown_50_[0x21c - 0x50];
    unsigned char unknown_2cc_[4];
    unsigned char unknown_220_[0x7e2 - 0x220];
    unsigned char unknown_912_;
    unsigned char unknown_7e3_[0x81c - 0x7e3];
    int unknown_94c_[4];
    unsigned char unknown_82c_[0x20];
    unsigned char unknown_84c_[0x10];
    unsigned char unknown_85c_[4];
    int unknown_860_;
    int unknown_994_;
    int active;
    int state;
    int mode;
    int unknown_9a4_;
    unsigned char unknown_878_[8];
    int unknown_880_;
    int unknown_9b4_;
    Struct_0204166c glyphs[0x80];
    unsigned char unknown_17b8_[0x80];
    int selectedEntry;
    int unknown_183c_;
    int unknown_1710_;
    int unknown_1844_;
    unsigned char unknown_1718_[0x10];
    int unknown_1728_;
    int unknown_172c_;
    int unknown_1730_;
    int unknown_1864_;
    int unknown_1868_;
    unsigned char unknown_173c_[0x10];
    short unknown_174c_;
    short unknown_174e_;
    unsigned char unknown_1750_[2];
    unsigned short unknown_1752_[0x10];
    unsigned short unknown_1772_;
    short unknown_1774_;
    unsigned char unknown_1776_[2];
    signed char levels[4];
    signed char unknown_177c_[4];
    unsigned char unknown_1952_[4];
    unsigned char unknown_1784_;
    unsigned char unknown_1957_;
    unsigned char unknown_1958_;
    unsigned char unknown_1787_[1];
    unsigned char unknown_1788_;
    unsigned char unknown_195b_;
    unsigned char unknown_178a_[1];
    unsigned char unknown_195d_;
    unsigned char unknown_178c_[2];
    unsigned char unknown_1960_;
    unsigned char unknown_1961_;
    unsigned char unknown_1790_[4];
    Struct_0204500c entries[2];
    unsigned char unknown_19ac_;
    unsigned char unknown_17dd_;
    unsigned char unknown_19ae_;
    unsigned char unknown_19af_;
    unsigned char unknown_17e0_;
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
    unsigned char unknown_19b3_;
    unsigned char unknown_19b4_;
    unsigned char unknown_19b5_;
    unsigned char unknown_19b6_;
    unsigned char unknown_17e7_;
    unsigned char unknown_19b8_;
    unsigned char unknown_17e9_[2];
    unsigned char unknown_17eb_;
    unsigned char unknown_19bc_;
    unsigned char unknown_19bd_;
    unsigned char unknown_19be_;
    unsigned char unknown_19bf_;
    unsigned char unknown_19c0_;
    unsigned char b19c1;
    unsigned char unknown_17f2_;
    unsigned char unknown_17f3_;
    unsigned char unknown_19c3_;
    unsigned char unknown_19c4_;
    unsigned char unknown_19c5_;
    unsigned char unknown_19c6_;
    unsigned char unknown_19c7_;
    unsigned char unknown_19c8_;
    unsigned char unknown_19c9_;
    unsigned char b19ca;
    unsigned char unknown_17fc_[1];
    unsigned char unknown_19cc_;
    unsigned char unknown_19cd_;
    Struct_020439b0_2 flags17ff;
    unsigned char unknown_1800_[0x1c4c - 0x1800];
    Foo0207df50* encoder;
    int func_020656e4(int arg0);
    int func_02042a90(unsigned char* p, unsigned int count);
    void func_020444d4(int ticks);
    unsigned short func_020656d0();
    void func_02045740();
    void func_020455f8();
    void func_02045688();
    int func_020440cc();
};


#else

struct Struct_0204500c_2 {
    char* first;
    char* second;
    int flags;
};


struct Struct_02042c68 {
    unsigned char data[0x1c];
};

struct Struct_020439b0 {
    unsigned char data[0x24];
};

struct Foo0207df50;
struct Struct_0204394c;
struct Struct_0204500c_3;
struct Struct_0204500c_4;
struct Struct_02042c68_2;

struct MessageSystem {
    unsigned char pad0[0x18];
    Struct_0204500c_2* itemName;
    unsigned char unknown_1c_[0x14];
    signed char unknown_30_;
    signed char unknown_31_;
    unsigned char unknown_32_[0x6];
    void* frame;
    unsigned char unknown_3c_[0x4];
    int unknown_40_;
    int unknown_44_;
    void* textBuffer;
    unsigned short* unknown_4c_;
    void* unknown_50_;
    unsigned char unknown_54_[0xc];
    char* unknown_60_;
    char* unknown_64_;
    unsigned char pad68[4];
    unsigned int unknown_6c_;
    unsigned char unknown_70_[8];
    unsigned int unknown_78_;
    unsigned char unknown_7c_[0x10];
    unsigned char* child;
    unsigned char unknown_90_[0x23c];
    unsigned char unknown_2cc_[4];
    unsigned char unknown_2d0_[0x642];
    unsigned char unknown_912_;
    unsigned char unknown_913_[0x1d];
    Struct_02042c68 unknown_930_;
    int unknown_94c_[4];
    unsigned char unknown_95c_[0x20];
    unsigned char unknown_97c_[0x10];
    unsigned char unknown_98c_[0x4];
    int unknown_990_;
    int unknown_994_;
    int active;
    int state;
    int mode;
    int unknown_9a4_;
    unsigned char unknown_9a8_[0x8];
    int unknown_9b0_;
    int unknown_9b4_;
    Struct_0204166c glyphs[0x80];
    unsigned char unknown_17b8_[0x80];
    int selectedEntry;
    int unknown_183c_;
    int unknown_1840_;
    int unknown_1844_;
    unsigned char unknown_1848_[0x10];
    int unknown_1858_;
    int unknown_185c_;
    int unknown_1860_;
    int unknown_1864_;
    int unknown_1868_;
    unsigned char unknown_186c_[0x10];
    short unknown_187c_;
    short unknown_187e_;
    unsigned char unknown_1880_[0x2];
    unsigned short unknown_1882_[0x40];
    unsigned char slotData[0x40];
    unsigned short unknown_1942_;
    unsigned short unknown_1944_;
    unsigned short unknown_1946_;
    unsigned char unknown_1948_[0x2];
    signed char levels[4];
    signed char unknown_194e_[4];
    unsigned char unknown_1952_[4];
    unsigned char unknown_1956_;
    unsigned char unknown_1957_;
    unsigned char unknown_1958_;
    unsigned char unknown_1959_[0x1];
    unsigned char unknown_195a_;
    unsigned char unknown_195b_;
    unsigned char unknown_195c_[0x1];
    unsigned char unknown_195d_;
    unsigned char unknown_195e_[0x2];
    unsigned char unknown_1960_;
    unsigned char unknown_1961_;
    unsigned char unknown_1962_[2];
    Struct_020439b0 entries[2];
    unsigned char unknown_19ac_;
    unsigned char unknown_19ad_;
    unsigned char unknown_19ae_;
    unsigned char unknown_19af_;
    unsigned char unknown_19b0_;
    unsigned char unknown_19b1_;
    unsigned char unknown_19b2_;
    unsigned char unknown_19b3_;
    unsigned char unknown_19b4_;
    unsigned char unknown_19b5_;
    unsigned char unknown_19b6_;
    unsigned char unknown_19b7_;
    unsigned char unknown_19b8_;
    unsigned char unknown_19b9_[0x2];
    unsigned char unknown_19bb_;
    unsigned char unknown_19bc_;
    unsigned char unknown_19bd_;
    unsigned char unknown_19be_;
    unsigned char unknown_19bf_;
    unsigned char unknown_19c0_;
    unsigned char b19c1;
    unsigned char unknown_19c2_;
    unsigned char unknown_19c3_;
    unsigned char unknown_19c4_;
    unsigned char unknown_19c5_;
    unsigned char unknown_19c6_;
    unsigned char unknown_19c7_;
    unsigned char unknown_19c8_;
    unsigned char unknown_19c9_;
    unsigned char b19ca;
    unsigned char unknown_19cb_[0x1];
    unsigned char unknown_19cc_;
    unsigned char unknown_19cd_;
    unsigned char unknown_19ce_;
    unsigned char unknown_19cf_;
    unsigned char unknown_19d0_;
    unsigned char unknown_19d1_;
    unsigned char unknown_19d2_;
    unsigned char b19d3;
    unsigned char unknown_19d4_[0x8];
    unsigned char unknown_19dc_;
    unsigned char unknown_19dd_[0x44b];
    Foo0207df50* encoder;
    int func_020656e4(int arg0);
    int func_02042a90(unsigned char* p, unsigned int count);
    void func_020444d4(int ticks);
    unsigned short func_020656d0();
    void func_02045740();
    void func_020455f8();
    void func_02045688();
    int func_020440cc();
};

#endif

#if defined(jpn)
extern "C" void func_0204500c(MessageSystem* window, const char* text, int mode);
#else
extern "C" void func_0204500c(MessageSystem* window, const char* text, int mode, int arg3);
#endif
