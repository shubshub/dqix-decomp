#if defined(jpn)
enum { Enum_ov017_021d3aa4_2856 = 0x908 };
#else
enum { Enum_ov017_021d3aa4_2856 = 0xb28 };
#endif

#include <globaldefs.h>
#include "Combat/LootPointEvent.h"

struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" void LootPointList_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
ARM int* GetNegativeEntry_020120b8(char* obj, int index);
extern "C" int func_ov017_021d3950(void* p);

struct Struct_ov017_021d3aa4 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    signed char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    Struct_0208ec78 unknown_8_;
};

// USA: func_ov017_021d3aa4
extern "C" ARM void func_ov017_021d3aa4(int p0, struct Evt021d3aa4* evt, char* buf, int table, struct SearchStruct0202c1a4* search) {
    LootPointList_GetInstance();
    unsigned char* entryObj = *(unsigned char**)((char*)table + 0x3000 + RegionOffsetb28);

    if (LinkSession_IsHostOrSolo(search)) {
        if (evt->mode != 1) return;

        if (func_ov017_021d3950(&arg1->unknown_4_) != 0) {
            func_ov017_021d38f8(1, arg0, arg1->unknown_6_, arg1->unknown_7_, &arg1->unknown_8_);
        } else {
            func_ov017_021d38f8(2, arg0, arg1->unknown_6_, arg1->unknown_7_, &arg1->unknown_8_);
        }
        return;
    }

    if (arg0 != 0) return;

    if (evt->mode == 0) {
        int* e = GetNegativeEntry_020120b8(buf, evt->field7);
        if (e) *e = evt->state.word;
    } else if (evt->mode == 1) {
        signed char cur = LinkSession_GetOwnSlot(search);
        if (evt->idx == cur) {
            if (entryObj[2] != 0) entryObj[9] = 1;
        }
        func_ov017_021d3950(&evt->mode);
    } else if (evt->mode == 2) {
        signed char cur = LinkSession_GetOwnSlot(search);
        if (evt->idx == cur) {
            entryObj[9] = 2;
        }
    }
}
