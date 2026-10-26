#if defined(jpn)
enum {regionalOffset0=0x8c, regionalOffset1=0xc4, regionalOffset2=0xc6};
#else
enum {regionalOffset0=0x6c, regionalOffset1=0x84, regionalOffset2=0x86};
#endif
#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct BitField0203402c {
    char pad[0xc4];
    unsigned short unknown_c4_0_ : 15;
    unsigned short unknown_c5_7_ : 1;
};

extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int GameObject_IsSinking(struct BitField0203402c* p);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(void* self, void* data);
extern "C" void func_ov017_0219a674(unsigned char* self);
extern "C" void func_ov017_0219b33c(void* a, void* buf, int b, int tag);

struct Struct_ov017_02198618 { unsigned int unknown_0_, w1, w2; };

struct Struct_ov017_02198618_2 {
    unsigned char tag;
    unsigned char field1;
    unsigned short field2;
    unsigned char field4;
    unsigned char pad5[3];
    void* unknown_8_;
    unsigned char pad12[4];
    unsigned short field10;
    unsigned char pad18[2];
};

// USA: func_ov017_02198618
extern "C" ARM void func_ov017_02198618(void* p0) {
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetLeader();
    if (c == NULL) return;
    if (GameObject_IsGesturing((signed char*)c) != 0) return;
    if (GameObject_IsSinking((struct BitField0203402c*)c) != 0) return;

    unsigned char* misc = (unsigned char*)Zone3D_GetInstance();
    battle->GetCamera();
    unsigned char* arr = (unsigned char*)ZoneFeatures_GetFirstOfType(misc + regionalOffset0, 10);
    struct Struct_ov017_02198618 buf3 = *(struct Struct_ov017_02198618*)((char*)c + 0x44);

    while (arr != NULL) {
        if (func_02094b9c(arr, &buf3) != 0) {
            unsigned short field2c = *(unsigned short*)(arr + 0x2c);
            short var6 = *(short*)(misc + 0x2700 + regionalOffset1);
            if (field2c == var6) {
                unsigned short var7 = *(unsigned short*)misc;
                unsigned short var8 = *(unsigned short*)(misc + 0x2700 + regionalOffset2);
                if (var7 == var8) {
                    struct Struct_ov017_02198618_2 var9;
                    func_ov017_0219a674((unsigned char*)&var9);
                    var9.tag = 0xb;
                    var9.unknown_8_ = arr;
                    var9.field4 = 1;
                    func_ov017_0219b33c(p0, &var9, 1, 0xb);
                    return;
                }
            }
        }
        arr = *(unsigned char**)(arr + 0x70);
    }
}
