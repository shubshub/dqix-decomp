#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "World/Zone3D.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

typedef ZoneFeatures::Opcode6aEntry PathNode_021975e4;

struct BitField0203402c;
struct ListHead02046b60;

extern "C" void* Zone3D_GetInstance(void);
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int GameObject_IsSinking(BitField0203402c* obj);
extern "C" int func_02046b60(ListHead02046b60* list, int id);
extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int func_02094b9c(PathNode_021975e4* node, Vector3i* point);
extern "C" void FlagWord_SetBits(unsigned int* field, unsigned int bits);

// USA: func_ov017_021975e4
extern "C" ARM void func_ov017_021975e4(GameResources* state) {
    GameState* game = GameState::GetInstance();
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    unsigned int* flags = GlobalFlags_GetInstance();
    GameObject* player = game->GetLeader();
    Vector3i anchor = player->obj3D_.position_;
    SubBlock02038508* current = GameObject_GetLadderClimb(player);
    GameResources* res = GetGameResources();
    ListHead02046b60* list = (ListHead02046b60*)res->fieldTaskQueue_;

    if (g_keyManager.TestKeysHeld(0x402)) return;
    if (GameObject_IsGesturing((signed char*)player) || current->active) return;
    if (GameObject_IsSinking((BitField0203402c*)player)) return;
    if (func_02046b60(list, 0xc)) return;
    if (func_02046b60(list, 0x2d)) return;
    if (func_02046b60(list, 0x26)) return;
    if (func_02046b60(list, 0x35)) return;
    int idle = ((unsigned char*)player)[0xbe] == 0 ? 1 : 0;
    if (idle == 1) return;

    PathNode_021975e4* node = (PathNode_021975e4*)ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, 9);
    while (node != 0) {
        SubBlock02038508 block;
        LadderClimb_Reset(&block);
        if (func_02094b9c(node, &anchor)) {
            Vector3i nodeDir;
            int cosine = fix32cos(node->angle);
            nodeDir.x = fix32sin(node->angle);
            nodeDir.y = 0;
            nodeDir.z = cosine;
            Vector3fix_Normalize(&nodeDir, &nodeDir);

            short heading = *(short*)((char*)player + 0xae);
            Vector3i var14;
            cosine = fix32cos(heading);
            var14.x = fix32sin(heading);
            var14.y = 0;
            var14.z = cosine;
            Vector3fix_Normalize(&var14, &var14);

            Vector3i facing = *(Vector3i*)(res->unknown_4420_ + 0x18);
            int alignment = Vector3fix_InnerProduct(&nodeDir, &var14);
            int var17 = Vector3fix_InnerProduct(&nodeDir, &facing);
            Vector3i offset;
            Vector3fix_Subtract(&anchor, &node->unk_8.vec, &offset);

            if (node->unk_2c.type9.unk_5 & 1) {
                if (alignment >= 0) {
                    node = node->pNext;
                    continue;
                }
            } else {
                if (alignment <= 0) {
                    node = node->pNext;
                    continue;
                }
            }

            int var19 = 0;
            if ((*(short*)(state->unknown_42e3 + 0xb)) <= 1) {
                if (((unsigned char*)player)[0xbe] == 1 && (var17 < -0xccc || var17 > 0xccc || alignment < -0xccc || alignment > 0xccc)) {
                    (*(short*)(state->unknown_42e3 + 0xb))++;
                } else {
                    (*(short*)(state->unknown_42e3 + 0xb)) = 0;
                }
            } else if ((*(short*)(state->unknown_42e3 + 0xb)) > 1) {
                (*(short*)(state->unknown_42e3 + 0xb)) = 0;
                var19 = 1;
            }
            if (!var19) {
                node = node->pNext;
                continue;
            }

            PathNode_021975e4* partner = ZoneFeatures_FindLadderNode(&zone->substruct_6c_, node->unk_2c.type9.unk_2);
            if (!partner) return;

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
            GameObject_SetLadderClimb(player, &block);
            FlagWord_SetBits(flags, 0x400);
        }
        node = node->pNext;
    }
}
