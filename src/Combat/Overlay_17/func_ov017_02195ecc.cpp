#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "Resource/Brightness.h"


struct Struct_02057a6c;

extern "C" void __clear(void* ptr, int size);
extern "C" void func_ov017_02196048(int*, int*, int*);
extern "C" Struct_02057a6c* func_02057924(void);
extern "C" int func_020ca4b4(const void* src, void* dst, int size);
extern "C" void func_02057a6c(Struct_02057a6c* c);
extern "C" void func_ov017_021a3af0(int obj);

extern const Vector3fix data_ov017_021d6420;
extern const Vector3fix data_ov017_021d642c;

struct Struct_ov017_02195ecc {
    unsigned int flags[2];
#if defined(jpn)
    char pad8[0x34ec - 0x8];
#else
    char pad8[0x36fc - 0x8];
#endif
    int nodeList;
};

// USA: func_ov017_02195ecc
extern "C" ARM void func_ov017_02195ecc(Struct_ov017_02195ecc* self, unsigned int mode) {
    if (mode == 0) {
        return;
    }

    Vector3fix var0 = data_0210a010.eyeVector;
    Vector3fix var1 = data_0210a010.upVector;
    Vector3fix var2 = data_0210a010.targetVector;
    Matrix4x4 var3 = data_0210a010.projectionMatrix;
    Vector3fix eye = data_ov017_021d6420;
    Vector3fix target;
    __clear(&target, sizeof(target));
    Vector3fix up = data_ov017_021d642c;

    Mat4x4_WriteProjectionUnknown(0xe000, -0x22000, -0x20000, 0x20000, 0x1000, 0x190000, 0x1000,
                                  &data_0210a010.projectionMatrix);
    data_0210a010.flags &= ~((1 << RENDER_CONFIG_FLAG_4) | (1 << RENDER_CONFIG_FLAG_6));
    func_ov017_02196048((int*)&eye, (int*)&up, (int*)&target);
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();

    if (mode & 1) {
        Struct_02057a6c* entries = func_02057924();
        if (TestFlags04((GameResources*)(self->flags), 0x20) == 0) {
            func_02057a6c(entries);
        }
    }
    if (mode & 2) {
        func_ov017_021a3af0(self->nodeList);
    }

    func_ov017_02196048((int*)&var0, (int*)&var1, (int*)&var2);
    func_020ca4b4(&var3, &data_0210a010.projectionMatrix, sizeof(Matrix4x4));
    data_0210a010.flags &= ~((1 << RENDER_CONFIG_FLAG_4) | (1 << RENDER_CONFIG_FLAG_6));
    RenderConfig::SubmitToFifo();
    SendQueuedDataToGeometryFifo();
}
