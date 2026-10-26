#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/SpriteAffineTransform.h"

struct OAM0205ac40 {
    unsigned int attributes;
    unsigned short tile;
    short matrix;
};

extern "C" void* OamManager_GetInstance();
extern "C" OAM0205ac40* OamManager_GetSubOamBuffer(void*);
extern "C" OAM0205ac40* OamManager_GetMainOamBuffer(void*);
extern "C" void func_020b0a1c(OAM0205ac40*, unsigned short, B174Outer*, Struct_0205ac40_3*, int*, unsigned short, int);

// Main, originally func_0205ac40 (USA 0x0205ac40, EUR 0x0205ac50, JPN 0x0205bfdc)
extern "C" ARM void SpriteContext_DrawSprite(SpriteContext0205ac40* context, B174Outer* sprite) {
    int palette;
    unsigned short count;
    int priority;
    void* manager;
    OAM0205ac40* objects;
    Struct_0205ac40_3* matrix;
    bool var6;
    OAM0205ac40* target;
    Struct_0205ac40_3 transform;
    Struct_0205ac40_3 var9;
    int position[2];
    if (sprite != NULL) {
        manager = OamManager_GetInstance();
        matrix = NULL;
        objects = OamManager_GetSubOamBuffer(manager);
        if (context->subScreen == 0) objects = OamManager_GetMainOamBuffer(manager);
        var6 = false;
        if (sprite->transformed) {
            func_0205b0d8(context, &transform, &var9, sprite);
            matrix = &transform;
            if (sprite->unknown_24_) var6 = true;
        }
        unsigned short first = sprite->firstObject & 0x7f;
        unsigned short available = 128 - first;
        if (matrix != NULL) {
            OAM0205ac40* target = objects + sprite->matrixIndex * 4;
            target[0].matrix = var9.values[0] >> 4;
            target[1].matrix = var9.values[1] >> 4;
            target[2].matrix = var9.values[2] >> 4;
            target[3].matrix = var9.values[3] >> 4;
        }
        COPY_ARRAY(position, sprite->position);
        if (position[1] < -0x40000 || position[1] >= 0xc0000) return;
        target = objects + first;
        func_020b0a1c(target, available, sprite, matrix, sprite->position, sprite->matrixIndex, var6);
        palette = sprite->palette;
        priority = sprite->priority;
        if (palette < 0 && priority < 0) return;
        int mode = func_0205b174(context, sprite);
        count = sprite->count;
        while (count != 0) {
            if (palette >= 0) {
                target->attributes = (target->attributes & ~0xc00) | (mode << 10);
                target->tile = (target->tile & ~0xf000) | (palette << 12);
            }
            if (priority >= 0)
                target->tile = (target->tile & ~0xc00) | (priority << 10);
            ++target;
            --count;
        }
    }
}
