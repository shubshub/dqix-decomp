#if defined(jpn)
enum { RegionOffset6c = 0x8c };
#else
enum { RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int func_02094b9c(void* a, void* b);
int fix32ReduceAngle0To2Pi(int angle);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
extern "C" void func_ov017_0219a674(unsigned char* self);
extern "C" void func_ov017_0218da48(void* obj, int angle, int c, int d, unsigned char e);
extern "C" void func_ov017_0219b33c(void* obj, void* eventBuf);

struct TargetNode021984f4 {
    unsigned char pad0[0x20];
    short angle;
    unsigned char pad1[0x70 - 0x22];
    struct TargetNode021984f4* next;
};

struct Struct_ov017_021984f4_2 {
    int a, b, c;
};

struct Struct_ov017_021984f4_3 {
    unsigned char tag;
    unsigned char pad1;
    unsigned short pad2;
    unsigned char flag;
    unsigned char pad3[3];
    void* ptr;
    int pad4;
    unsigned short pad5;
    unsigned short pad6;
};

// USA: func_ov017_021984f4
extern "C" ARM void func_ov017_021984f4(void* obj) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetLeader();
    if (c == NULL) {
        return;
    }
    if (GameObject_IsGesturing((signed char*)c) != 0) {
        return;
    }

    void* cache = Zone3D_GetInstance();
    bs->GetCamera();
    struct TargetNode021984f4* node = (struct TargetNode021984f4*)ZoneFeatures_GetFirstOfType((unsigned char*)cache + RegionOffset6c, 8);

    struct Struct_ov017_021984f4_2 var4 = *(struct Struct_ov017_021984f4_2*)((char*)c + 0x44);
    int best = 0x270f000;
    unsigned char flag = 1;
    unsigned char idx = 0;
    while (node != NULL) {
        if (func_02094b9c(node, &var4) != 0) {
            int angle = (short)fix32ReduceAngle0To2Pi(node->angle + 0x3244);
            func_ov017_0218da48(obj, angle, 0xccc, -819, idx);
            int delta = fix32abs(fix32SignedAngleDistance(c->obj3D_.rotation_.y, node->angle));
            if ((float)delta < 8364.19921875f) {
                if (delta < best) {
                    best = delta;
                    struct Struct_ov017_021984f4_3 buf;
                    func_ov017_0219a674((unsigned char*)&buf);
                    buf.tag = 6;
                    buf.flag = flag;
                    buf.ptr = node;
                    func_ov017_0219b33c(obj, &buf);
                }
            }
        }
        node = node->next;
    }
}
