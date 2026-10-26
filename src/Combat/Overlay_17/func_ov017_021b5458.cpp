#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void __clear(void* buf, int size);
void Clear12Bytes020a8e88(void* p);
extern "C" void func_020a8fd0(void* obj, void* arg, void* file, unsigned int size, short* ids, int count);
extern "C" void func_ov017_021b5648(void* obj);

struct Struct_ov017_021b5458_2 {
    unsigned int unknown_0_0_ : 12;
    int unknown_4_;
};

struct Struct_ov017_021b5458_3 {
    unsigned int unknown_0_0_ : 12;
};

struct Struct_0209ad40_3 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    struct Struct_ov017_021b5458_2 unknown_4_[6];
    struct Struct_ov017_021b5458_3 unknown_34_[6];
};

extern "C" struct Struct_0209ad40_3* func_0209b9c0(struct Struct_0209ad40_3* arg0, int arg1);

struct Struct_ov017_021b5458_4 {
    char unknown_0_[0x10];
    void* unknown_10_;
#if defined(jpn)
    char unknown_14_[0x120 - 0x14];
#else
    char unknown1_14_[0x124 - 0x14];
#endif

    struct Struct_0209ad40_3 unknown_124_[6];
    char unknown_2ec_[0x30c - 0x2ec];
    unsigned char unknown_30c_[0xc];
};

struct Struct_ov017_021b5458 {
    char unknown_0_[8];
    struct Struct_ov017_021b5458_4* unknown_8_;
    int unknown_c_;
};

// USA: func_ov017_021b5458
extern "C" ARM void func_ov017_021b5458(struct Struct_ov017_021b5458* arg0) {
    struct Struct_ov017_021b5458_4* var0;
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    LinkSession_GetInstance();
    if (!loader->GetTaskStatus(obj->key)) {
        return;
    }

    if (var1->GetDetailedTaskStatus(arg0->unknown_c_) == 2) {
        unsigned int var2;
        void* var3;
        var1->GetLoadedFileByID(arg0->unknown_c_, &var3, &var2);
        if (var3 != 0) {
            short var4[64];
            __clear(var4, 0x80);
            short var5 = 0;
            var0 = arg0->unknown_8_;
            for (int var6 = 0; var6 < 6; var6++) {
                struct Struct_0209ad40_3* var7 = func_0209b9c0(var0->unknown_124_, var6);
                if (var7 == 0) {
                    continue;
                }
                for (int var8 = 0; var8 < var7->unknown_2_; var8++) {
                    unsigned int var9 = var7->unknown_4_[var8].unknown_0_0_;
                    int var10 = 1;
                    for (int var11 = 0; var11 < var5; var11++) {
                        if (var9 == var4[var11]) {
                            var10 = 0;
                            break;
                        }
                    }
                    if (var10) {
                        var4[var5++] = var9;
                    }
                }
                for (int var12 = 0; var12 < var7->unknown_3_; var12++) {
                    unsigned int var13 = var7->unknown_34_[var12].unknown_0_0_;
                    int var14 = 1;
                    for (int var15 = 0; var15 < var5; var15++) {
                        if (var13 == var4[var15]) {
                            var14 = 0;
                            break;
                        }
                    }
                    if (var14) {
                        var4[var5++] = var13;
                    }
                }
            }
            var0 = arg0->unknown_8_;
            func_020a8e88(var0->unknown_30c_);
            func_020a8fd0(var0->unknown_30c_, arg0->unknown_8_->unknown_10_, var3, var2, var4, var5);
        }
    }

    var1->RemoveTask(arg0->unknown_c_);
    arg0->unknown_c_ = -1;
    func_ov017_021b5648(arg0);
}
