#include <globaldefs.h>
#include "GameState/GameState.h"

struct Element020dedd0 {
    int unk_0;
    int unk_4;
    unsigned int unknown_8_0_ : 20;
    unsigned int keep : 1;
    unsigned int unknown_a_5_ : 11;
};
struct ItemTable;
struct Struct_02083994;
struct KeyMap020a095c;

extern "C" struct Element020dedd0* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_02083994(struct Struct_02083994* s, int value);
extern "C" int func_020a095c(struct KeyMap020a095c* map, int key, int amount);
extern "C" void func_ov017_021c9e00(int id, int flagA, int arg2, int flagC);
extern "C" void func_ov002_0215b2c8(char* self);

// USA: func_ov002_0215a658
#if defined(jpn)
extern "C" ARM void func_ov002_0215a658(char* self, int val) {
    int off;
    char* slots;
    GameState* battle = GameState::GetInstance();
    void* keymap = GameState_GetParty(battle);
    for (int i = 0; i < *(int*)(self + 0x1afc); i++) {
        int id = *(int*)(self + i * 4 + 0x1b00);
        if (val == id || val == 4) {
            GameObject* c = func_0200ff1c(battle, id);
            if (c != NULL) {
                char* f = (char*)func_02053c6c((unsigned char*)c);
                int j;
                unsigned char n = 0;
                for (j = 0; j < 8; j++) {
                    off = j * 2;
                    slots = f + 0x454;
                    if (*(short*)(slots + off) > 0) {
                        struct Element020dedd0* e = ItemTable_Find((struct ItemTable*)(self + 0x750), *(short*)(slots + off));
                        if (e->keep) {
                            short key = *(short*)(slots + off);
                            *(short*)(slots + off) = -1;
                            *(short*)(f + n++ * 2 + 0x454) = key;
                        } else {
                            if (*(short*)(slots + off) == 0x570a) {
                                if (func_02083994((struct Struct_02083994*)f, 0x570a) == 1) {
                                    *(char*)(*(char**)((char*)c + 0x130) + 8) = 0;
                                    func_ov017_021c9e00(c->obj3D_.actorIndex_, 0, 0, 1);
                                }
                            }
                            func_020a095c((struct KeyMap020a095c*)keymap, *(short*)(slots + off), 1);
                            *(short*)(slots + off) = -1;
                        }
                    }
                }
            }
        }
    }
}
#else
extern "C" ARM void func_ov002_0215a658(char* self, int val) {
    int off;
    char* slots;
    GameState* battle = GameState::GetInstance();
    void* keymap = GameState_GetParty(battle);
    for (int i = 0; i < *(int*)(self + 0x1c38); i++) {
        int id = *(int*)(self + i * 4 + 0x1c3c);
        if (val == id || val == 4) {
            GameObject* c = func_0200ff1c(battle, id);
            if (c != NULL) {
                char* f = (char*)func_02053c6c((unsigned char*)c);
                int j;
                unsigned char n = 0;
                for (j = 0; j < 8; j++) {
                    off = j * 2;
                    slots = f + 0x454;
                    if (*(short*)(slots + off) > 0) {
                        struct Element020dedd0* e = ItemTable_Find((struct ItemTable*)(self + 0x7ec), *(short*)(slots + off));
                        if (e->keep) {
                            short key = *(short*)(slots + off);
                            *(short*)(slots + off) = -1;
                            *(short*)(f + n++ * 2 + 0x454) = key;
                        } else {
                            if (*(short*)(slots + off) == 0x570a) {
                                if (func_02083994((struct Struct_02083994*)f, 0x570a) == 1) {
                                    *(char*)(*(char**)((char*)c + 0x130) + 8) = 0;
                                    func_ov017_021c9e00(c->obj3D_.actorIndex_, 0, 0, 1);
                                }
                            }
                            func_020a095c((struct KeyMap020a095c*)keymap, *(short*)(slots + off), 1);
                            *(short*)(slots + off) = -1;
                        }
                    }
                }
            }
        }
    }
    func_ov002_0215b2c8(self);
}
#endif
