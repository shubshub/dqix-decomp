#include <globaldefs.h>

struct TailList020469b4;
struct TailNode020469b4;
struct ByteHeader0204693c { signed char byte0, unknown_1_, unknown_2_, unknown_3_; };
struct Struct_ov017_021c12fc;

extern "C" void func_ov017_021c1350(struct Struct_ov017_021c12fc* obj, unsigned char a, unsigned char b);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_ov017_021c12b0(unsigned char param);

#if defined(jpn)
#define NODE_OFFSET 0x3930
#define LIST_OFFSET 0x34ec
#else
#define NODE_OFFSET 0x3b50
#define LIST_OFFSET 0x36fc
#endif

// USA: func_ov017_021c12fc
extern "C" ARM void func_ov017_021c12fc(char* self, unsigned char param2, unsigned char param3) {
    struct Struct_ov017_021c12fc* node = *(struct Struct_ov017_021c12fc**)(self + NODE_OFFSET);
    if (*((unsigned char*)node + 2) != 0) {
        return;
    }
    func_ov017_021c1350(node, param2, param3);
    func_020469b4(*(TailList020469b4**)(self + LIST_OFFSET), *(TailNode020469b4**)(self + NODE_OFFSET));
    if (param2 == 0) return;
    if (param3 != 0) return;
    func_ov017_021c12b0(1);
}
