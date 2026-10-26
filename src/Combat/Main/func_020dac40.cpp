#include <globaldefs.h>

struct Struct_020dac40_2;
struct TailList020469b4;
struct TailNode020469b4;

extern "C" void func_020dac68(Struct_020dac40_2*);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);

struct Struct_020dac40 {
#if defined(jpn)
    unsigned char pad[0x34ec];
#else
    unsigned char pad[0x36fc];
#endif
    TailList020469b4* list;
#if defined(jpn)
    unsigned char pad2[0x9a4 - 0x4ec - 4];
#else
    unsigned char pad2[0xbc4 - 0x6fc - 4];
#endif
    void* unknown_3bc4_;
};

// USA: func_020dac40
extern "C" ARM void func_020dac40(Struct_020dac40* root) {
    func_020dac68((Struct_020dac40_2*)root->unknown_3bc4_);
    func_020469b4(root->list, (TailNode020469b4*)root->unknown_3bc4_);
}
