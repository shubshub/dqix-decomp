#if defined(jpn)
enum { Enum_ov017_021d3aa4_2856 = 0x908 };
#else
enum { Enum_ov017_021d3aa4_2856 = 0xb28 };
#endif

#include <globaldefs.h>
#include "Combat/LootPointEvent.h"

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void LootPointList_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" ARM int* func_020120b8(char* obj, int index);
extern "C" int func_ov017_021d3950(void* p);

struct Struct_ov017_021d3aa4 {
    unsigned char pad0[4];
    unsigned char mode;
    signed char idx;
    unsigned char field6;
    unsigned char unknown_7_;
    Struct_0208ec78 state;
};

// USA: func_ov017_021d3aa4
extern "C" ARM void func_ov017_021d3aa4(int p0, struct Struct_ov017_021d3aa4* evt, char* buf, int table, struct SearchStruct0202c1a4* search) {
    LootPointList_GetInstance();
    unsigned char* var0 = *(unsigned char**)((char*)table + 0x3000 + Enum_ov017_021d3aa4_2856);

    if (LinkSession_IsHostOrSolo(search)) {
        if (evt->mode != 1) return;

        if (func_ov017_021d3950(&evt->mode) != 0) {
            func_ov017_021d38f8(1, p0, evt->field6, evt->unknown_7_, &evt->state);
        } else {
            func_ov017_021d38f8(2, p0, evt->field6, evt->unknown_7_, &evt->state);
        }
        return;
    }

    if (p0 != 0) return;

    if (evt->mode == 0) {
        int* e = func_020120b8(buf, evt->unknown_7_);
        if (e) *e = evt->state.word;
    } else if (evt->mode == 1) {
        signed char cur = LinkSession_GetOwnSlot(search);
        if (evt->idx == cur) {
            if (var0[2] != 0) var0[9] = 1;
        }
        func_ov017_021d3950(&evt->mode);
    } else if (evt->mode == 2) {
        signed char cur = LinkSession_GetOwnSlot(search);
        if (evt->idx == cur) {
            var0[9] = 2;
        }
    }
}
