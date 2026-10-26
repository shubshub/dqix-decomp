#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_02049ee8(unsigned char* obj);
extern "C" int func_ov000_021681f8(int id, int count);
extern "C" int func_ov000_02167b5c(int a, int b);
extern "C" void func_ov000_02167b54(int* obj, int a, int b, int c);
extern "C" void func_02049b20(unsigned char* obj, int* src);
extern "C" void func_02049bac(unsigned char* obj, int* src);
extern "C" void func_ov000_0216f718(void* obj, int val);
extern "C" void func_ov000_0216f720(void* obj, int val);

struct Struct_ov000_021677fc_2 {
    unsigned char field_0x0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
    unsigned char hi : 2;
    char unknown_2_[2];
    unsigned short kind;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char rest : 4;
    char unknown_f_[0x18 - 0xf];
};

struct Struct_ov000_021677fc_3 {
    struct Struct_ov000_021677fc_2 groups[3];
};

struct Struct_ov000_021677fc_4 {
    char unknown_0_[0x81b0];
    struct Struct_ov000_021677fc_3 formation;
    char unknown_81f8_[0x8de0 - 0x81b0 - sizeof(struct Struct_ov000_021677fc_3)];
    int slots[8];
};

struct Struct_ov000_021677fc {
#if defined(jpn)
    char unknown_0_[0x218];
    struct Struct_ov000_021677fc_4* data;
    char unknown_21c_[0x394 - 0x21c];
    char sub[0x57cc - 0x394];
#else
    char unknown1_0_[0x18];
    char sub[0x284];
    struct Struct_ov000_021677fc_4* data;
    char unknown_2a0_[0x55dc - 0x2a0];
#endif
    int unknown_55dc_;
    int unknown_55e0_;
};

static inline int inline_ov000_021677fc(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

// USA: func_ov000_021677fc
extern "C" ARM void func_ov000_021677fc(Struct_ov000_021677fc* obj) {
    struct Struct_ov000_021677fc_2* group;
    struct Struct_ov000_021677fc_3* formation;
    int g;
    char* sub;
    GameState* battle = GameState::GetInstance();
    GetGameResources();
    struct Struct_ov000_021677fc_4* data = obj->data;
    obj->unknown_55dc_ = 0;
    obj->unknown_55e0_ = 0;
#if defined(jpn)
    sub = obj->sub + 0x800;
#else
    sub = obj->sub + 0xc00;
#endif
    formation = &data->formation;
    for (g = 0; g < formation->groups[0].groupCount; g++) {
        group = &formation->groups[g];
        for (int j = 0; j < group->count; j++) {
            int id = group->ids[j] + 0xc0;
            GameObject* c = battle->GetCombatantByIndex(id);
            if (c != 0 && func_02049ee8((unsigned char*)c) != 0) {
                int found;
                struct Struct_ov000_021677fc_4* d = obj->data;
                int i = 0;
                for (; i < 8; i++) {
                    if (id == (d->slots[i] & 0xff)) {
                        found = 1;
                        goto done;
                    }
                }
                found = 0;
done:
                if (!found) {
                    int var12 = -1;
                    for (int i = 0; i < 8; i++) {
                        GameObject* o = battle->GetCombatantByIndex(obj->data->slots[i] & 0xff);
                        if (o == 0 || func_02049ee8((unsigned char*)o) == 0) {
                            var12 = i;
                            break;
                        }
                    }
                    if (var12 != -1) {
                        obj->data->slots[var12] = id;
                    }
                }
            }
        }
    }
    int n = 0;
    for (int i = 0; i < 8; i++) {
        if (battle->GetCombatantByIndex(obj->data->slots[i] & 0xff) != 0) {
            n++;
        }
    }
    for (int i = 0; i < 8; i++) {
        GameObject* c = battle->GetCombatantByIndex(obj->data->slots[i] & 0xff);
        if (c != 0) {
            int radius = c->obj3D_.GetRadius();
            int height = c->obj3D_.GetHeight();
            int var21 = func_ov000_021681f8(c->obj3D_.unknown_2_, n);
            obj->unknown_55dc_ += inline_ov000_021677fc(radius, var21);
            if (obj->unknown_55e0_ < height) {
                obj->unknown_55e0_ = height;
            }
        }
    }
    obj->unknown_55e0_ += 0x800;
    int ratio = func_ov000_02167b5c(obj->unknown_55dc_, n & 0xff);
    obj->unknown_55dc_ += ratio * (n - 1);
    int x = -(obj->unknown_55dc_ / 2);
    for (int i = 0; i < 8; i++) {
        GameObject* c = battle->GetCombatantByIndex(obj->data->slots[i] & 0xff);
        if (c != 0) {
            int radius = c->obj3D_.GetRadius();
            int var27 = func_ov000_021681f8(c->obj3D_.unknown_2_, n);
            int w = inline_ov000_021677fc(radius, var27);
            int half = w / 2;
            int a[3];
            int b[3];
            x += half;
            func_ov000_02167b54(a, x, 0xcc, -0x2800);
            func_02049b20((unsigned char*)c, a);
            func_ov000_02167b54(b, 0, 0, 0);
            func_02049bac((unsigned char*)c, b);
            x += half;
            x += ratio;
        }
    }
    func_ov000_0216f718(sub, obj->unknown_55dc_);
    func_ov000_0216f720(sub, obj->unknown_55e0_);
}
