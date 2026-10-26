#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "NitroSDK/NSBXX/RenderCommandCallbacks.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderCommands_Common.h"

#if defined(jpn)
#define func_020ca430 func_020cbefc
#endif

#define REG_GXFIFO (*(volatile unsigned int*)0x04000400)
struct Struct_020e2d54 { unsigned short flags; char unknown_2_[0xa]; int scaleZ; };
struct Struct_020f2c14 {
    union {
        Vector4fix rows[3];
        struct { int unknown1_0_[6]; Vector3fix normal; Vector3fix unknown_24_; };
    };
    Vector3fix position;
    char unknown_3c_[0xc];
};
extern char data_020ee9b8[];
extern int data_020ef0e8;
extern "C" void func_020e2fa8(int*, int, int, int);
extern "C" void* func_020e2fb0(void*);
static inline int inline_020e2d54(Struct_020e2d54* bone) { SDK_NULL_ASSERT(bone); return bone->scaleZ; }
static inline int inline_020e2d54_2(Vector3fix* vector) { SDK_NULL_ASSERT(vector); return vector->z; }
static inline int inline_020e2d54_3(int a, int b) { int value = fix32_Divide(a, b); return value; }

// USA: func_020e2d54
extern "C" ARM void func_020e2d54(int mode, RenderCommandHandler* entry, Struct_020f2c14* output) {
    Matrix4x4 matrix;
    Vector3fix scale;
    Vector3fix offset;
    if (!(entry->flags_ & 0x100)) {
        SendQueuedDataToGeometryFifo();
        REG_GXFIFO = 0x151110;
        REG_GXFIFO = 0;
        while (func_020c54fc(&matrix)) {}
        func_020e2fa8(&scale.x, 0x1000, 0x1000, 0x1000);
        int correction = 0;
        if (mode == 1) {
            scale.x = Vector3fix_Length(&matrix.rows[0].xyz);
            scale.y = Vector3fix_Length(&matrix.rows[1].xyz);
            scale.z = Vector3fix_Length(&matrix.rows[2].xyz);
        }
        if (mode == 1) {
            func_020e2fa8(&offset.x, 0, 0, 0);
            NSBXXInternalModel* model = entry->modelContext_->internalModel_;
            NSBXXNameList* list = (NSBXXNameList*)func_020e2fb0(model);
            int index = list ? NSBXXNameList_SearchIndex(list, data_020ee9b8) : -1;
            if (index >= 0) {
                list = (NSBXXNameList*)func_020e2fb0(model);
                Struct_020e2d54* bone;
                if (!list) goto missingBone;
                {
                    unsigned int* var8;
                    if (list && (unsigned int)index < list->numEntries_) {
                        unsigned char* data = (unsigned char*)list + list->offsetToDataStart_;
                        unsigned short stride = *(unsigned short*)data;
                        var8 = (unsigned int*)(data + 4 + stride * index);
                    } else var8 = 0;
                    if (var8) {
                        bone = (Struct_020e2d54*)((char*)list + *var8);
                        goto foundBone;
                    }
                }
            missingBone:
                bone = 0;
            foundBone:
                if (!(bone->flags & 1)) {
                    offset.z = FIX32_MULTIPLY(inline_020e2d54_2(&scale), inline_020e2d54(bone));
                }
                if (fix32abs(matrix.rows[3].z) >= 4) {
                    correction = FIX32_MULTIPLY(inline_020e2d54_2(&offset), inline_020e2d54_3(matrix.rows[3].x, matrix.rows[3].z));
                }
            }
        }
        output->position.x = matrix.rows[3].x + correction;
        output->position.y = matrix.rows[3].y;
        output->position.z = matrix.rows[3].z;
        if (mode == 1) {
            output->rows[0].w = scale.x;
            output->rows[1].w = scale.y;
            output->rows[2].w = scale.z;
        }
        if (mode == 0 && (matrix.rows[1].y || matrix.rows[1].z) && data_020ef0e8) {
            Vector3fix_Normalize(&matrix.rows[1].xyz, &output->normal);
            output->unknown_24_.y = -output->normal.z;
            output->unknown_24_.z = output->normal.y;
            data_020ef0e8 = 0;
        }
        func_020ca430(output, (void*)0x04000400, 0x48);
    }
    entry->flags_ |= 0x40;
}
