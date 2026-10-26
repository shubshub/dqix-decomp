#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/NSBXX/RenderConfig.h>

struct Struct_02059720;
struct Struct_020546c8;
struct Struct_02059a54 {
    char pad0[5];
    unsigned char unknown_5_;
};
struct Struct_02059a54_2 {
    int field0;
    unsigned int time;
    char pad8[8];
    Vector3fix origin;
    char unknown_1c_[0xc];
    Struct_020546c8* resource;
    unsigned char active;
    char unknown_2d_[0x23];
    float scaleX, scaleY;
    char unknown_58_[0x14];
    float velocityX, velocityY, velocityZ, speed;
    Object3D object;
    int polygonId;
    float red, green, blue, alpha, width, height;
};
extern "C" int func_02059a2c(Struct_02059720*);
extern "C" Struct_02059a54* func_02055108(Struct_020546c8*);
extern "C" void* Camera_GetInverseRotation(void*);
extern "C" void MI_Copy36B(void*, const void*);
extern "C" void NSBXX_Model_SetPolygonID(void*, int);
extern int data_0210a0cc;
extern Vector3fix data_020e7da4;
static inline NSBXXInternalModel* inline_02059a54(Struct_02059a54_2* effect) { return effect->object.pModel_->rawInternalModel_; }

// USA: func_02059a54
extern "C" ARM void func_02059a54(Struct_02059a54_2* self) {
    if (self->active && !func_02059a2c((Struct_02059720*)self)) {
        Struct_02059a54* info = func_02055108(self->resource);
        int x;
        int y;
        unsigned int time;
        time = self->time;
        x = self->origin.x + (int)(4096.0f * ((float)time * (self->velocityX * self->speed)));
        y = self->origin.y + (int)(4096.0f * ((float)time * (self->velocityY * self->speed)));
        int z = self->origin.z + (int)(4096.0f * ((float)time * (self->velocityZ * self->speed)));
        self->object.position_.x = x;
        self->object.position_.y = y;
        self->object.position_.z = z;
        if (!info->unknown_5_) {
            NSBXXInternalModel* model = inline_02059a54(self);
            int blue = (int)self->blue;
            int red = (int)self->red;
            int green = (int)self->green;
            NSBXX_Model_SetDiffuseReflectionColor(model, (unsigned short)(red | (green << 5) | (blue << 10)));
            NSBXX_Model_SetPolygonID(self->object.pModel_->rawInternalModel_, self->polygonId);
            Vector3fix position = self->object.position_;
            RenderConfig::SetObjectPosition(&position);
            void* camera = GameState::GetInstance()->GetCamera();
            if (camera) {
                MI_Copy36B(Camera_GetInverseRotation(camera), &data_0210a0cc);
                data_0210a010.flags &= ~0xa4;
            }
            Vector3fix scale = data_020e7da4;
            scale.x = (int)((float)(int)(4096.0f * self->width) * self->scaleX);
            scale.y = (int)((float)(int)(4096.0f * self->height) * self->scaleY);
            RenderConfig::SetObjectScale(&scale);
            self->object.SetInheritedAlpha((int)self->alpha);
            self->object.DrawWithCurrentRenderConfig(true);
        } else {
            self->object.Draw(true);
        }
    }
}
