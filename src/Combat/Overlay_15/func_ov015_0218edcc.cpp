#include <globaldefs.h>
#include "World/Object3D.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/Graphics.h"

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x24];
    Object3D* objects_;
    char unk_28[0x34 - 0x28];
    unsigned short unknown_34_;
    unsigned short unknown_36_;
};

// USA: func_ov015_0218edcc
extern "C" ARM void func_ov015_0218edcc(Struct_ov015_0218c03c_2* self)
{
    GXFIFO_MATRIX_PUSH = 0;
    self->objects_->Draw(false);
    RenderConfig::SubmitToFifo();
    GXFIFO_MATRIX_POP = 1;
    self->unknown_34_ = self->unknown_36_ = 0;
    self->unknown_34_ = self->objects_->pModel_->rawInternalModel_->numTriangles_;
    self->unknown_36_ = self->objects_->pModel_->rawInternalModel_->numQuads_;
}
