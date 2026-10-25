#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Zone3D.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

typedef Struct_020134e0::Struct_02018300 Struct_02018300;

struct Struct_0203402c;
struct Struct_02038598_5;

extern "C" void* Zone3D_GetInstance(void);
unsigned int* GlobalFlags_GetInstance();
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
int CheckField0xc4Low15BitsNonZero(BitField0203402c* obj);
int ListContainsId(ListHead02046b60* list, int id);
void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(PathNode_021975e4* node, Vector3i* point);
void FlagWord_SetBits(unsigned int* field, unsigned int bits);

// USA: func_ov017_021975e4
extern "C" ARM void func_ov017_021975e4(GameResources* state) {
    GameState* game = GameState::GetInstance();
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    unsigned int* flags = GlobalFlags_GetInstance();
    GameObject* player = game->GetUnknownGameObject();
    Vector3i anchor = player->obj3D_.position_;
    SubBlock02038508* current = GetFieldPtrAt0x26c_020399a8(player);
    GameResources* res = GetGameResources();
    ListHead02046b60* list = (ListHead02046b60*)res->fieldTaskQueue_;

    if (g_keyManager.TestKeysHeld(0x402)) return;
    if (func_020535c8((signed char*)var3) || var5->unknown_0_) return;
    if (func_0203402c((Struct_0203402c*)var3)) return;
    if (func_02046b60(var7, 0xc)) return;
    if (func_02046b60(var7, 0x2d)) return;
    if (func_02046b60(var7, 0x26)) return;
    if (func_02046b60(var7, 0x35)) return;
    int var8 = ((unsigned char*)var3)[0xbe] == 0 ? 1 : 0;
    if (var8 == 1) return;

    PathNode_021975e4* node = (PathNode_021975e4*)ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, 9);
    while (node != 0) {
        SubBlock02038508 block;
        InitBlock02038508(&block);
        if (func_02094b9c(node, &anchor)) {
            Vector3i nodeDir;
            int cosine = fix32cos(node->angle);
            nodeDir.x = fix32sin(node->angle);
            nodeDir.y = 0;
            nodeDir.z = cosine;
            Vector3fix_Normalize(&nodeDir, &nodeDir);

            short var13 = *(short*)((char*)var3 + 0xae);
            Vector3i var14;
            var12 = fix32cos(var13);
            var14.x = fix32sin(var13);
            var14.y = 0;
            var14.z = var12;
            Vector3fix_Normalize(&var14, &var14);

            Vector3i var15 = *(Vector3i*)(var6->unknown_4420_ + 0x18);
            int var16 = Vector3fix_InnerProduct(&var11, &var14);
            int var17 = Vector3fix_InnerProduct(&var11, &var15);
            Vector3i var18;
            Vector3fix_Subtract(&var4, &var9->unknown_8_.unknown1_0_, &var18);

            if (var9->unknown_2c_.unknown5_0_.unknown_5_ & 1) {
                if (var16 >= 0) {
                    var9 = var9->unknown_70_;
                    continue;
                }
            } else {
                if (var16 <= 0) {
                    var9 = var9->unknown_70_;
                    continue;
                }
            }

            int var19 = 0;
            if ((*(short*)(arg0->unknown_42e3_ + 0xb)) <= 1) {
                if (((unsigned char*)var3)[0xbe] == 1 && (var17 < -0xccc || var17 > 0xccc || var16 < -0xccc || var16 > 0xccc)) {
                    (*(short*)(arg0->unknown_42e3_ + 0xb))++;
                } else {
                    (*(short*)(arg0->unknown_42e3_ + 0xb)) = 0;
                }
            } else if ((*(short*)(arg0->unknown_42e3_ + 0xb)) > 1) {
                (*(short*)(arg0->unknown_42e3_ + 0xb)) = 0;
                var19 = 1;
            }
            if (!var19) {
                var9 = var9->unknown_70_;
                continue;
            }

            Struct_02018300* var20 = func_0201e6d4(&var1->substruct_6c_, var9->unknown_2c_.unknown5_0_.unknown_2_);
            if (!var20) return;

            block.active = 1;
            block.heading = node->angle;
            if (node->unk_2c.type9.unk_5 & 1) {
                block.endNode = node;
                block.startNode = partner;
                block.start.vec = partner->unk_8.vec;
                block.end.vec = node->unk_8.vec;
                block.startControl.vec = partner->unk_8.vec;
                block.endControl.vec = node->unk_8.vec;
                block.startHeading = partner->angle;
                block.endHeading = node->angle;
                block.reversed = 1;
                block.endControl.vec.x += nodeDir.x;
                block.endControl.vec.z += nodeDir.z;
                block.startControl.vec.x += -nodeDir.x >> 2;
                block.startControl.vec.z += -nodeDir.z >> 2;
                block.end.vec.y -= 0x1000;
                block.startHeading -= 0x3243;
                if (block.startHeading < 0) block.startHeading += 0x6487;
            } else {
                block.endNode = partner;
                block.startNode = node;
                block.start.vec = node->unk_8.vec;
                block.end.vec = partner->unk_8.vec;
                block.startControl.vec = node->unk_8.vec;
                block.endControl.vec = partner->unk_8.vec;
                block.startHeading = node->angle;
                block.endHeading = partner->angle;
                block.reversed = 0;
                block.endControl.vec.x += nodeDir.x;
                block.endControl.vec.z += nodeDir.z;
                block.startControl.vec.x += -nodeDir.x >> 2;
                block.startControl.vec.z += -nodeDir.z >> 2;
                block.end.vec.y -= 0x1000;
                block.startHeading -= 0x3243;
                if (block.startHeading < 0) block.startHeading += 0x6487;
            }
            CopyBlockTo0x26c_020398b4(player, &block);
            FlagWord_SetBits(flags, 0x400);
        }
        var9 = var9->unknown_70_;
    }
}
