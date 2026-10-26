#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0203e2c4_32376 = 0x7c38 };
#else
enum { Enum_0203e2c4_32376 = 0x7e78 };
#endif

#include "Combat/EntryGetterTypes.h"
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_0203e0a0_2 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    unsigned short unknown_8_0_ : 9;
    unsigned short unknown_9_1_ : 1;
    unsigned short unknown_9_2_ : 5;
    unsigned short unknown_9_7_ : 1;
};

struct Struct_0203e0a0_3 {
    unsigned char unknown_0_[0xc];
    Struct_0203dce4 *unknown_c_[32];
    unsigned int unknown_8c_;
    unsigned char unknown_90_[0xe];
    Struct_0203e0a0_2 unknown_9e_[32];
    unsigned short unknown_1de_;
    unsigned short unknown_1e0_;
    unsigned short unknown_1e2_;
    unsigned int unknown_1e4_;
};

struct Struct_0203e0a0_4 {
    unsigned char unknown_0_[0xc];
    unsigned int unknown_c_;
    Struct_0203e0a0_4 *unknown_10_;
};

struct Struct_0203e0a0_5 {
    unsigned char unknown_0_[0xa];
    unsigned char unknown_a_0_ : 3;
    unsigned char unknown_a_3_ : 3;
    unsigned char unknown_a_6_ : 2;
    unsigned char unknown_b_[0x29];
    Struct_0203e0a0_4 *unknown_34_;
};

struct Struct_0203e2c4 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    unsigned char unknown_6_;
};

struct Struct_02033834;
struct Struct_0203e2c4_2;
struct Struct_0203d028_15;

void *FindEntryPointerByKey0203df78(void *receiver, int key);
void GameObject_SnapFacing(struct Obj02033874 *obj, int value);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c *obj, int value);
void SetActiveChildFields02040774(struct Node02040774 *node, int x, int y, int z);

// USA: func_0203e2c4
extern "C" ARM void func_0203e2c4(void *arg0, unsigned short arg1) {
    Struct_0203e0a0_3 *var0 = static_cast<Struct_0203e0a0_3 *>(arg0);
    if (var0->unknown_1de_ == arg1) {
        Struct_0203e0a0_2 *var1 = var0->unknown_9e_;
        for (int var2 = 0; var2 < var0->unknown_1e0_; ++var1, ++var2) {
            Struct_0203dce4 **var3 = var0->unknown_c_;
            for (unsigned int var4 = 0; var4 < var0->unknown_8c_; ++var3, ++var4) {
                Struct_0203dce4 *var5 = *var3;
                unsigned short *var6 = (unsigned short *) func_02040528(&var5->unknown_0_);
                void *var7 = func_02040538((Struct_0203e0a0 *) var5);
                if (var6 == NULL || var7 == NULL) {
                    continue;
                }
                if (*var6 != var1->unknown_8_0_) {
                    continue;
                }
                Vector3i position;
                position.x = snapshot->x << 4;
                position.y = snapshot->y << 4;
                position.z = snapshot->z << 4;
                short value = snapshot->value;
                if (entry->child14 != NULL) {
                    *(Vector3i *) ((char*)entry->child14 + 4) = position;
                } else if (entry->child18 != NULL) {
                    *(Vector3i *) ((char*)entry->child18 + 0x44) = position;
                } else if (entry->child1c != NULL) {
                    *(Vector3i *) ((char*)entry->child1c + 0x44) = position;
                    GameObject_SnapFacing((struct Obj02033874 *) entry->child1c, value);
                }
                func_02040b2c((struct Struct_0203e2c4_2 *) var5, var9);
                func_02040af0(var5, var9);
                if (var1->unknown_9_1_) {
                    var5->unknown_0_ |= 0x8000;
                }
                Struct_0203e0a0_5 *var10 = (Struct_0203e0a0_5 *) func_02040538((Struct_0203e0a0 *) var5);
                if (var10 != NULL) {
                    Struct_0203e0a0_4 *var11 = var10->unknown_34_;
                    while (var11 != NULL) {
                        if (var1->unknown_9_2_ == 0) {
                            var11->unknown_c_ = 1;
                        } else {
                            var11->unknown_c_ = 0;
                        }
                        var1->unknown_9_2_--;
                        var11 = var11->unknown_10_;
                        if (var11 == var10->unknown_34_) {
                            break;
                        }
                    }
                }
                if (var1->unknown_9_7_) {
                    var10->unknown_a_3_ = 3;
                }
                if (var0->unknown_1e4_ & (1U << var4)) {
                    var5->unknown_0_ |= 0x40000;
                }
                break;
            }
        }
    }
    var0->unknown_1de_ = 0;
    var0->unknown_1e4_ = 0;
    GameState *var12 = GameState::GetInstance();
    Struct_0203e2c4 *var13 = (Struct_0203e2c4 *) ((char *) var12 + Enum_0203e2c4_32376);
    if (var13->unknown_6_ != 0xff) {
        struct Struct_0203d028_15 *var14 = (struct Struct_0203d028_15 *) func_0203df78(var0, var13->unknown_6_);
        if (var14 != NULL) {
            func_02040774(var14, var13->unknown_0_ << 4, var13->unknown_2_ << 4, var13->unknown_4_ << 4);
        }
        var13->unknown_6_ = 0xff;
    }
}
