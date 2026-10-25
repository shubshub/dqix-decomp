#if defined(jpn)
enum { Enum_ov017_021983e0_14076 = 0x34ec, Enum_ov017_021983e0_108 = 0x8c };
#else
enum { Enum_ov017_021983e0_14076 = 0x36fc, Enum_ov017_021983e0_108 = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

int IsField0Null_02046b08(void** obj);
extern "C" void* Zone3D_GetInstance(void);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(void* a, void* b);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void func_ov017_0219a674(unsigned char* arg0);
extern "C" void func_ov017_0218da48(void* arg0, int arg1, int arg2, int arg3, unsigned char arg4);
struct Struct_ov009_0218aa28 { int unknown_0_, unknown_4_, unknown_8_; };
extern "C" short func_ov017_021a4700(struct Struct_ov009_0218aa28* arg0, int arg1, struct Struct_ov009_0218aa28* arg2);
extern "C" void func_ov017_0219b33c(void* arg0, void* arg1);

struct Struct_ov017_021983e0_2 {
    int unknown_0_, unknown_4_, unknown_8_;
};

struct Struct_ov017_021983e0_3 {
    unsigned char unknown_0_[0x20];
    short unknown_20_;
    unsigned char unknown_22_[0x70 - 0x22];
    struct Struct_ov017_021983e0_3* unknown_70_;
};

struct Struct_ov017_021983e0 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_[3];
    void* unknown_8_;
    int unknown_c_;
    short unknown_10_;
    unsigned short unknown_12_;
};

// USA: func_ov017_021983e0  (semantic: FindFirstTargetAndForward_021983e0)
extern "C" ARM void func_ov017_021983e0(unsigned char* obj) {
    if (IsField0Null_02046b08(*(void***)(obj + RegionOffset36fc))) {
        GameState* bs = GameState::GetInstance();
        void* cache = Zone3D_GetInstance();
        bs->GetCamera();
        GameObject* c = bs->GetUnknownGameObject();
        if (CheckSubstructByte0x7cPositive_020535c8((signed char*)c) == 0) {
            struct FilterData021983e0 filter = *(struct FilterData021983e0*)((char*)c + 0x44);
            struct TargetNode021983e0* node = (struct TargetNode021983e0*)ZoneFeatures_GetFirstOfType((unsigned char*)cache + RegionOffset6c, 5);
            while (node != NULL) {
                if (func_02094b9c(node, &filter) != 0) {
                    int angle = (short)fix32ReduceAngle0To2Pi(node->angle + 0x3244);
                    BuildAndForwardVec_0218da48(obj, angle, 0xccc, 0x800 - 0xccc, 0);
                    struct EventBuf021983e0 buf;
                    InitObj0219a674((unsigned char*)&buf);
                    buf.tag = 7;
                    buf.ptr = node;
                    buf.field10 = GetAngleDeltaBetween_021a4700((struct Vec3*)((char*)c + 0x44), (short)c->obj3D_.rotation_.y, (struct Vec3*)((char*)node + 8));
                    func_ov017_0219b33c(obj, &buf);
                    return;
                }
                var4 = var4->unknown_70_;
            }
        }
    }
}
