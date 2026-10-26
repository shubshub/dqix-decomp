#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021d0f94_1788 = 0x4ec, Enum_ov017_021d0f94_2880 = 0x920, Enum_ov017_021d0f94_2016 = 0x768 };
#else
enum { Enum_ov017_021d0f94_1788 = 0x6fc, Enum_ov017_021d0f94_2880 = 0xb40, Enum_ov017_021d0f94_2016 = 0x7e0 };
#endif

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
extern "C" int func_ov003_0217f278(int* obj);

extern "C" void func_ov003_02171fe8(void* base, void* a, void* p, int c, unsigned char arg4);

struct Struct_ov017_021d0f94 {
    unsigned char pad4[0x4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_0_ : 7;
    unsigned char byte7;
};

// USA: func_ov017_021d0f94
extern "C" ARM void func_ov017_021d0f94(void* a, struct Struct_ov017_021d0f94* b, int unused, char* c, struct SearchStruct0202c1a4* d) {
    signed char cur = LinkSession_GetOwnSlot(d);
    if (b->unknown_4_ != cur) return;

    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)(c + 0x3000 + Enum_ov017_021d0f94_1788);
    if (FieldTaskQueue_GetCurrentKind(list) != 0x2a) return;

    int* field = *(int**)(c + 0x3000 + Enum_ov017_021d0f94_2880);
    int val = func_ov003_0217f278(field);
    if (val == 0) return;

    func_ov003_02171fe8((char*)val + Enum_ov017_021d0f94_2016, a, &b->byte7, b->unknown_6_0_, b->unknown_5_);
}
