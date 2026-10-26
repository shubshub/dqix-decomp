#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Input/Input.h"

extern "C" void FollowCamera_Update(void* actor);

struct Struct_ov015_02190d7c;
extern "C" void func_ov015_021931b4(struct Struct_ov015_02190d7c* s, int v);
struct Struct_ov015_02190d7c_2;
extern "C" int func_ov015_021931cc(struct Struct_ov015_02190d7c_2* o);
extern "C" void func_ov015_02192700(void* obj, int a1);
struct Struct_ov015_0218f1c4;
extern "C" ARM void func_ov015_0218f1c4(struct Struct_ov015_0218f1c4* obj);

struct Struct_ov015_02190d7c_3 {
    int value;
    struct Struct_ov015_02190d7c_3* next;
};

struct Struct_ov015_02190d7c_4 {
    char pad0[0x2c];
    struct Struct_ov015_02190d7c_3* list;
    char pad1[0x38 - 0x2c - 4];
    signed char field38;
    char pad2[0x194 - 0x38 - 1];
    int unknown_194_;
    int unknown_198_;
    char pad3[0x1a4 - 0x198 - 4];
    int field1a4;
};

// USA: func_ov015_02190d7c
extern "C" ARM void func_ov015_02190d7c(struct Struct_ov015_02190d7c_4* obj) {
    GameState* bs = GameState::GetInstance();
    if (bs == 0) {
        return;
    }
    void* f3b0 = bs->GetCamera();
    if (f3b0 != 0) {
        FollowCamera_Update(f3b0);
    }

    struct Struct_ov015_02190d7c_3* node = obj->list;
    while (node != 0) {
        func_ov015_0218f1c4((struct Struct_ov015_0218f1c4*)node->value);
        node = node->next;
    }

    if (!g_keyManager.TestKeysPressed(4)) {
        return;
    }

    int tmp = obj->unknown_194_;
    obj->unknown_194_ = obj->unknown_198_;
    obj->unknown_198_ = tmp;

    int v;
    if (obj->unknown_194_ == 2) {
        func_ov015_021931b4((struct Struct_ov015_02190d7c*)obj, obj->field1a4);
        obj->field1a4 = 0x23;
        goto cleanup;
    }

    do {
        v = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)obj);
    } while (v >= 0x23);

    signed char state = obj->field38;
    if (state >= 0) {
        switch (state) {
        case 0:
        case 1:
            while (v >= 0xf) {
                v = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)obj);
            }
            goto reset;
        case 2:
            while (v >= 0x21) {
                v = func_ov015_021931cc((struct Struct_ov015_02190d7c_2*)obj);
            }
            goto reset;
        default:
        reset:
            obj->field38 = -1;
            if (obj->unknown_194_ == 1) {
                obj->unknown_194_ = 0;
            }
            break;
        }
    }

    obj->field1a4 = v;
cleanup:
    func_ov015_02192700(obj, 0);
}
