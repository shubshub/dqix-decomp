#include <globaldefs.h>
#include <GameState/GameState.h>
#include <NitroSDK/NSBXX/RenderConfig.h>

struct Struct_02059720;
struct Struct_020546c8;
struct Struct_02059a54 {
    char unknown_0_[5];
    unsigned char unknown_5_;
};
struct Struct_02059a54_2 {
    int unknown_0_;
    unsigned int unknown_4_;
    char unknown_8_[8];
    Vector3fix unknown_10_;
    char unknown_1c_[0xc];
    Struct_020546c8* unknown_28_;
    unsigned char unknown_2c_;
    char unknown_2d_[0x23];
    float unknown_50_, unknown_54_;
    char unknown_58_[0x14];
    float unknown_6c_, unknown_70_, unknown_74_, unknown_78_;
    Object3D unknown_7c_;
    int unknown_128_;
    float unknown_12c_, unknown_130_, unknown_134_, unknown_138_, unknown_13c_, unknown_140_;
};
int CheckByte0xcZeroAndField8LeField4(State02059a2c*);
EffectModelInfo02059a54* GetSubField0x14_02055108(S02055080*);
void* GetPtrField0x144_0202ed74(void*);
extern "C" void func_020ca528(void*, const void*);
extern "C" void NSBXX_Model_SetPolygonID(void*, int);
extern int data_0210a0cc;
extern Vector3fix data_020e7da4;
static inline NSBXXInternalModel* inline_02059a54(Struct_02059a54_2* arg0) { return arg0->unknown_7c_.pModel_->rawInternalModel_; }

// USA: func_02059a54
extern "C" ARM void func_02059a54(Effect02059a54* self) {
    if (self->active && !CheckByte0xcZeroAndField8LeField4((State02059a2c*)self)) {
        EffectModelInfo02059a54* info = GetSubField0x14_02055108(self->resource);
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
        if (!info->complex) {
            NSBXXInternalModel* model = GetEffectModel(self);
            int blue = (int)self->blue;
            int red = (int)self->red;
            int green = (int)self->green;
            NSBXX_Model_SetDiffuseReflectionColor(model, (unsigned short)(red | (green << 5) | (blue << 10)));
            NSBXX_Model_SetPolygonID(self->object.pModel_->rawInternalModel_, self->polygonId);
            Vector3fix position = self->object.position_;
            RenderConfig::SetObjectPosition(&position);
            void* camera = GameState::GetInstance()->GetCamera();
            if (camera) {
                func_020ca528(GetPtrField0x144_0202ed74(camera), &data_0210a0cc);
                data_0210a010.flags &= ~0xa4;
            }
            Vector3fix var11 = data_020e7da4;
            var11.x = (int)((float)(int)(4096.0f * arg0->unknown_13c_) * arg0->unknown_50_);
            var11.y = (int)((float)(int)(4096.0f * arg0->unknown_140_) * arg0->unknown_54_);
            RenderConfig::SetObjectScale(&var11);
            arg0->unknown_7c_.SetInheritedAlpha((int)arg0->unknown_138_);
            arg0->unknown_7c_.DrawSimple(true);
        } else {
            arg0->unknown_7c_.Draw(true);
        }
    }
}
