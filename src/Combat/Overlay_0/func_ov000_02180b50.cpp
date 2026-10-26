#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x84
#define REGION_OFFSET_1 0x85
#else
#define REGION_OFFSET_0 0x80
#define REGION_OFFSET_1 0x81
#endif


struct S02180b50 {
    char pad0[0x930];
    int unknown_930_;
    int unknown_934_;
    int unknown_938_;
    char pad1[0x94c - 0x93c];
    int unknown_94c_;
};

// USA: func_ov000_02180b50
extern "C" ARM void func_ov000_02180b50(struct S02180b50* obj) {
    if (obj->unknown_934_ == 0) {
        obj->unknown_930_ = 0x180;
        obj->unknown_938_ = 0;
        obj->unknown_934_ = 1;
        return;
    }
    if (obj->unknown_934_ != 1) return;
    int v = obj->unknown_930_ - obj->unknown_94c_ * 3;
    obj->unknown_930_ = v;
    if (v <= REGION_OFFSET_0) {
        v = REGION_OFFSET_0;
        obj->unknown_930_ = v;
        obj->unknown_934_ = v - REGION_OFFSET_1;
    }
}
