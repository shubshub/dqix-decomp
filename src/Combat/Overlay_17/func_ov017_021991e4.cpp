#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021991e4_14012 = 0x34ac };
#else
enum { Enum_ov017_021991e4_14012 = 0x36bc };
#endif

extern "C" void func_ov017_021bf410(void* self);
extern "C" int func_ov017_021bf5f4(void* self);

struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_021991e4 {
    char pad0[Enum_ov017_021991e4_14012];
    int unknown_36bc_;
    char pad1[0x3c];
    struct TailList020469b4* unknown_36fc_;
    char pad2[0x20];
    void* unknown_3720_;
};

// USA: func_ov017_021991e4
extern "C" ARM void func_ov017_021991e4(struct Struct_ov017_021991e4* obj) {
    func_ov017_021bf410(obj->unknown_3720_);

    *(int*)((char*)obj->unknown_3720_ + 0xc) = obj->unknown_36bc_;

    if (!func_ov017_021bf5f4(obj->unknown_3720_)) {
        return;
    }

    func_020469b4(obj->unknown_36fc_, (struct TailNode020469b4*)obj->unknown_3720_);
}
