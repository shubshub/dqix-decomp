#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x8c };
#else
enum { kRegionalFieldOffset = 0x6c };
#endif
#include "GameState/GameState.h"

struct Struct_020a2908;
struct Struct_020a28e0;

extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" int func_020a2cc4(unsigned char* obj);
extern "C" void func_020a2cd8(unsigned char* obj, int flag);
extern "C" void func_020a2908(unsigned char* obj, struct Struct_020a2908* src);
extern "C" void func_020a296c(unsigned char* obj, struct Struct_020a2908* src);
extern "C" void func_020a28d0(unsigned char* obj);
extern "C" void func_020a28c4(unsigned char* obj);
extern "C" void func_020a28e0(struct Struct_020a28e0* p);
extern "C" void func_020a298c(unsigned char* obj);

extern "C" void* Zone3D_GetInstance(void);

struct PendingNode_021982ac {
    char unknown_0_[0x2c];
    unsigned char kind : 7;
    unsigned char unknown_2c_7_ : 1;
    char unknown_2d_[3];
    unsigned char unknown_30_[0x2c];
    unsigned char extra[0x14];
    struct PendingNode_021982ac* next;
};

struct Struct_ov017_021982ac {
    unsigned int w[3];
};

extern "C" int func_02094b9c(struct PendingNode_021982ac* node, struct Struct_ov017_021982ac* anchor);
extern "C" void func_020a28dc(void* obj, int kind, void* arg2, void* extra);

// USA: func_ov017_021982ac
extern "C" ARM void func_ov017_021982ac(void) {
    GameState* battle = GameState::GetInstance();
    void* ctx = Zone3D_GetInstance();
    GameObject* combatant = battle->GetLeader();
    struct Struct_ov017_021982ac anchor = *(struct Struct_ov017_021982ac*)((char*)combatant + 0x44);
    struct PendingNode_021982ac* node;
    unsigned char* state;
    int var6;

    node = (struct PendingNode_021982ac*)ZoneFeatures_GetFirstOfType((unsigned char*)ctx + kRegionalFieldOffset, 4);
    state = (unsigned char*)GameState_GetFollowCamera((char*)battle);
    if (state == 0) {
        return;
    }

    var6 = 0;
    while (node != 0) {
        if (func_02094b9c(node, &anchor)) {
            int kind = node->kind;
            if (kind == 4) {
                if (func_020a2cc4(state)) {
                    func_020a2cd8(state, 0);
                }
                func_020a2908(state, (struct Struct_020a2908*)node->unknown_30_);
                var6 = 1;
            } else if (kind == 5) {
                func_020a296c(state, (struct Struct_020a2908*)node->unknown_30_);
                var6 = 1;
            } else {
                func_020a28dc(state, kind, node->unknown_30_, node->extra);
            }
            if (!node->unknown_2c_7_) {
                func_020a28d0(state);
            }
            break;
        }
        node = node->next;
    }

    if (node == 0) {
        func_020a28c4(state);
        func_020a28e0((struct Struct_020a28e0*)state);
    }
    if (!var6) {
        func_020a298c(state);
    }
}
