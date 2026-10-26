#if defined(jpn)
enum { RegionOffset36fc = 0x34ec, RegionOffset6c = 0x8c };
#else
enum { RegionOffset36fc = 0x36fc, RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(void* a, void* b);
int fix32ReduceAngle0To2Pi(int angle);
extern "C" void func_ov017_0219a674(unsigned char* self);
extern "C" void func_ov017_0218da48(void* obj, int angle, int c, int d, unsigned char e);
struct Vec3 { int x, y, z; };
extern "C" short func_ov017_021a4700(struct Vec3* p0, int arg1, struct Vec3* p2);
extern "C" void func_ov017_0219b33c(void* obj, void* eventBuf);

struct Struct_ov017_021983e0_2 {
    int a, b, c;
};

struct TargetNode021983e0 {
    unsigned char pad0[0x20];
    short angle;
    unsigned char pad1[0x70 - 0x22];
    struct TargetNode021983e0* next;
};

struct Struct_ov017_021983e0 {
    unsigned char tag;
    unsigned char pad1;
    unsigned short pad2;
    unsigned char flag;
    unsigned char pad3[3];
    void* ptr;
    int pad4;
    short field10;
    unsigned short pad6;
};

// USA: func_ov017_021983e0
extern "C" ARM void func_ov017_021983e0(unsigned char* obj) {
    if (FieldTaskQueue_IsEmpty(*(void***)(obj + RegionOffset36fc))) {
        GameState* bs = GameState::GetInstance();
        void* cache = Zone3D_GetInstance();
        bs->GetCamera();
        GameObject* c = bs->GetLeader();
        if (GameObject_IsGesturing((signed char*)c) == 0) {
            struct Struct_ov017_021983e0_2 var3 = *(struct Struct_ov017_021983e0_2*)((char*)c + 0x44);
            struct TargetNode021983e0* node = (struct TargetNode021983e0*)ZoneFeatures_GetFirstOfType((unsigned char*)cache + RegionOffset6c, 5);
            while (node != NULL) {
                if (func_02094b9c(node, &var3) != 0) {
                    int angle = (short)fix32ReduceAngle0To2Pi(node->angle + 0x3244);
                    func_ov017_0218da48(obj, angle, 0xccc, 0x800 - 0xccc, 0);
                    struct Struct_ov017_021983e0 buf;
                    func_ov017_0219a674((unsigned char*)&buf);
                    buf.tag = 7;
                    buf.ptr = node;
                    buf.field10 = func_ov017_021a4700((struct Vec3*)((char*)c + 0x44), (short)c->obj3D_.rotation_.y, (struct Vec3*)((char*)node + 8));
                    func_ov017_0219b33c(obj, &buf);
                    return;
                }
                node = node->next;
            }
        }
    }
}
