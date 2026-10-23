#include <globaldefs.h>

extern "C" void func_020bb700(int* arg0);
extern "C" void func_020bb910(int* arg0);
extern "C" int func_020bb588(unsigned int arg0, int arg1, int arg2);
extern "C" int func_020bb7cc(unsigned int arg0, int arg1, int arg2);

struct Struct_0207de48 { unsigned int unknown_0_[10]; };
struct Struct_0207de48_2 { int unknown_0_[2]; };
struct Struct_0207de48_3 {
    Struct_0207de48 unknown_0_;
    Struct_0207de48 unknown_28_;
    int unknown_50_;
    int unknown_54_;
    Struct_0207de48_2 unknown_58_;
    Struct_0207de48_2 unknown_60_;
    int unknown_68_;
    int unknown_6c_;
};

// Main, originally func_0207de48 (USA 0x0207de48, EUR 0x0207de58, JPN 0x0207ebc8)
extern "C" ARM void VramState_Reserve(void* pObj, int a, int b) {
    struct PairBackupCtx0207de48* obj = (struct PairBackupCtx0207de48*)pObj;
    BackupPairTableToBuffer_020bb700((int*)&obj->bufA);
    obj->bufB = obj->bufA;
    ReadGlobalPair020bb910(obj->globalPair.v);
    int remaining = a;
    obj->globalPairCopy = obj->globalPair;
    obj->checksumA = 0;

    while (var1 > 0) {
        if (var1 > 0x20000) {
            var0->unknown_50_ = func_020bb588(0x20000, 0, 0);
            var1 -= 0x20000;
        } else {
            var0->unknown_50_ = func_020bb588(var1, 0, 0);
            var1 = 0;
        }
    }
    if (arg1 != 0 && var0->unknown_50_ == 0) arg1 = 0;

    var0->unknown_68_ = 0;
    if (arg2 != 0) {
        var0->unknown_68_ = func_020bb7cc(arg2, 0, 0);
    }
    if (arg2 != 0 && var0->unknown_68_ == 0) arg2 = 0;

    var0->unknown_54_ = arg1;
    var0->unknown_6c_ = arg2;
}
