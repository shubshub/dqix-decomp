#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/SpriteAffineTransform.h"

struct Struct_0205ac40_4 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    short unknown_6_;
};

extern "C" void* OamManager_GetInstance();
extern "C" OAM0205ac40* OamManager_GetSubOamBuffer(void*);
extern "C" OAM0205ac40* OamManager_GetMainOamBuffer(void*);
extern "C" void func_020b0a1c(OAM0205ac40*, unsigned short, B174Outer*, Matrix2x2*, int*, unsigned short, int);

// Main, originally func_0205ac40 (USA 0x0205ac40, EUR 0x0205ac50, JPN 0x0205bfdc)
extern "C" ARM void SpriteContext_DrawSprite(SpriteContext0205ac40* context, B174Outer* sprite) {
    int palette;
    unsigned short count;
    int priority;
    void* manager;
    OAM0205ac40* objects;
    Matrix2x2* matrix;
    bool doubleSize;
    OAM0205ac40* target;
    Matrix2x2 transform;
    Matrix2x2 affine;
    int position[2];
    if (sprite != NULL) {
        manager = OamManager_GetInstance();
        matrix = NULL;
        objects = OamManager_GetSubOamBuffer(manager);
        if (context->subScreen == 0) objects = OamManager_GetMainOamBuffer(manager);
        doubleSize = false;
        if (sprite->transformed) {
            func_0205b0d8(context, &transform, &affine, sprite);
            matrix = &transform;
            if (sprite->doubleSize) doubleSize = true;
        }
        unsigned short var11 = arg1->unknown_22_ & 0x7f;
        unsigned short var12 = 128 - var11;
        if (var5 != NULL) {
            Struct_0205ac40_4* var13 = var4 + arg1->unknown_20_ * 4;
            var13[0].unknown_6_ = var9.unknown_0_[0] >> 4;
            var13[1].unknown_6_ = var9.unknown_0_[1] >> 4;
            var13[2].unknown_6_ = var9.unknown_0_[2] >> 4;
            var13[3].unknown_6_ = var9.unknown_0_[3] >> 4;
        }
        COPY_ARRAY(var10, arg1->unknown_14_);
        if (var10[1] < -0x40000 || var10[1] >= 0xc0000) return;
        var7 = var4 + var11;
        func_020b0a1c(var7, var12, arg1, var5, arg1->unknown_14_, arg1->unknown_20_, var6);
        var0 = arg1->unknown_25_;
        var2 = arg1->unknown_26_;
        if (var0 < 0 && var2 < 0) return;
        int var14 = func_0205b174(arg0, arg1);
        var1 = arg1->unknown_0_;
        while (var1 != 0) {
            if (var0 >= 0) {
                var7->unknown_0_ = (var7->unknown_0_ & ~0xc00) | (var14 << 10);
                var7->unknown_4_ = (var7->unknown_4_ & ~0xf000) | (var0 << 12);
            }
            if (var2 >= 0)
                var7->unknown_4_ = (var7->unknown_4_ & ~0xc00) | (var2 << 10);
            ++var7;
            --var1;
        }
    }
}
