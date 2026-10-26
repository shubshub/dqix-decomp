#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0xc };
#else
enum { kRegionalFieldOffset = 0x26c };
#endif

extern "C" int LinkSession_IsHostOrSolo(void* obj);
struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021d3bbc(int a, int b, int c, int d);

struct Struct_ov017_021d3c08 {
    unsigned char pad0[4];
    unsigned char mode;
    signed char idx;
    unsigned char field6;
    unsigned char unknown_7_;
};

struct Struct_ov017_021d3c08_2 {
    unsigned char pad0[8];
    unsigned int counter:7;
    unsigned int rest:25;
    unsigned char pad1[0x1c];
};

struct Struct_ov017_021d3c08_3 {
    unsigned int counter:7;
    unsigned int rest:25;
    unsigned char pad0[0x24];
};

// USA: func_ov017_021d3c08
extern "C" ARM void func_ov017_021d3c08(int p0, struct Struct_ov017_021d3c08* evt, int table, int unused, struct SearchStruct0202c1a4* search) {
    struct Struct_ov017_021d3c08_2* arr = (struct Struct_ov017_021d3c08_2*)((char*)table + kRegionalFieldOffset + 0x5c00);
    if (evt->mode == 3 && LinkSession_IsHostOrSolo(search)) {
        if (evt->field6 <= arr[evt->unknown_7_].counter) {
            func_ov017_021d3bbc(evt->unknown_7_, evt->field6, 1, p0);
            struct Struct_ov017_021d3c08_3* arr8 = (struct Struct_ov017_021d3c08_3*)((char*)arr + 8);
            arr8[evt->unknown_7_].counter = arr8[evt->unknown_7_].counter - evt->field6;
            return;
        }
        func_ov017_021d3bbc(evt->unknown_7_, evt->field6, 2, p0);
        return;
    }
    if (evt->mode == 1) {
        if (evt->idx == LinkSession_GetOwnSlot(search)) {
            unsigned short* var2 = (unsigned short*)((char*)arr + 0x100 + 0xc);
            *var2 = (*var2 & ~0xe000) | 0x2000;
            return;
        }
        struct Struct_ov017_021d3c08_3* arr8 = (struct Struct_ov017_021d3c08_3*)((char*)arr + 8);
        arr8[evt->unknown_7_].counter = arr8[evt->unknown_7_].counter - evt->field6;
        return;
    }
    if (evt->mode == 2) {
        if (evt->idx == LinkSession_GetOwnSlot(search)) {
            unsigned short* var4 = (unsigned short*)((char*)arr + 0x100 + 0xc);
            *var4 = (*var4 & ~0xe000) | 0x4000;
        }
    }
}
