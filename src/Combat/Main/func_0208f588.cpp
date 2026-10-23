#include <globaldefs.h>
#include "World/Object3D.h"
#include "Filesystem/FileIO.h"
#if defined(jpn)
#define data_020e8d54 data_020e8e70
#endif

struct Struct_02000c9c_26 {
    unsigned char unknown_0_[0xac];
};

struct Struct_0208f588 {
    int unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    void* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};

struct Struct_0208f588_2 {
    unsigned char unknown_0_[0xc];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 4;
};

struct Struct_0208f588_3 {
    unsigned char unknown_0_[8];
    struct Struct_0208f588_2* unknown_8_;
};

struct Struct_0208f588_4 {
    void* unknown_0_;
    unsigned int unknown_4_;
    struct Struct_02000c9c_26 unknown_8_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
};

struct Struct_020e8d54 {
    char unknown_0_[0x28];
};

extern const struct Struct_020e8d54 data_020e8d54;

extern "C" struct Struct_0208f588_3* func_02012fe4(void);
struct ObjectArchiveLoadInfo;

void VramState_Restore(char* obj);
void VramState_Save(char* obj);

// USA: func_0208f588
extern "C" ARM int func_0208f588(struct Struct_0208f588_4* arg0, SafeAllocator* arg1, char* arg2) {
    unsigned int var0;
    struct Struct_020e8d54 var1;
    struct Struct_0208f588 var2;
    void* var3;

    arg0->unknown_b4_ = 0;
    ((Object3D*)&arg0->unknown_8_)->Destroy();
    ((Object3D*)&arg0->unknown_8_)->Initialize();
    if (func_02012fe4()->unknown_8_->unknown_c_0_ != 0) {
        return 0;
    }

    var1 = data_020e8d54;
    var3 = LoadFileIntoNewAllocation(var1.unknown_0_, *arg1, &var0);
    if (var3 == 0) {
        return 0;
    }
    unsigned int var4 = var0;
    arg0->unknown_0_ = var3;
    arg0->unknown_4_ = var4;
    arg0->unknown_b4_ = 1;
    arg0->unknown_b5_ = 1;

    var2.unknown_0_ = 0;
    var2.unknown_4_ = 0;
    var2.unknown_8_ = 0;
    var2.unknown_10_ = 0;
    var2.unknown_14_ = 0;
    var2.unknown_18_ = 0;
    var2.unknown_1c_ = 0;
    var2.unknown_c_ = arg1;
    var2.unknown_4_ = arg0->unknown_0_;
    var2.unknown_8_ = arg0->unknown_4_;

    VramState_Restore(pairObj);
    ((Object3D*)&self->object)->Initialize();
    ((Object3D*)&self->object)->LoadFromCHRArchive((ObjectArchiveLoadInfo*)&info);
    ((Object3D*)&self->object)->MakeHidden();
    VramState_Save(pairObj);
    return 1;
}
