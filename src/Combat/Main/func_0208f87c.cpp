#include <globaldefs.h>

#include <World/Object3D.h>
#include <NitroSDK/NSBXX/RenderConfig.h>
#include "Resource/Brightness.h"

#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

extern "C" void MI_Copy36B(void* a, void* b);
extern int data_0210a0cc;

// USA: func_0208f87c
extern "C" ARM void func_0208f87c(const void* self, int b, int c, int d, int polygonId) {
    void* ov = GetGameResources();
    Object3D* r4 = *(Object3D**)((char*)ov + (IS_JPN ? 0x34bc : 0x36cc));
    if (TestFlags04((GameResources*)ov, 0x200400) != 0) {
        return;
    }
    if (r4->pModel_ == 0) {
        return;
    }
    r4->pModel_->SetMaterialDiffuseColor(b);
    RenderConfig::SetObjectPosition((Vector3i*)self);
    Vector3i vec = { c, c, c };
    RenderConfig::SetObjectScale(&vec);
    Matrix3x3 buf1;
    Mat3x3_WriteIdentity(&buf1);
    MI_Copy36B(&buf1, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
    r4->SetInheritedAlpha(d);
    RenderConfig::SubmitToFifo();
    r4->DrawMeshWithMaterialInCurrentMatrix(0, 0, 0, 1);
}
