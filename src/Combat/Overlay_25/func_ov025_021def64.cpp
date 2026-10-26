#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02049c08_2;
struct Obj02033874;
struct Struct_ov025_021def64;

struct Struct_ov025_021def64_2 {
    int key;
    struct Struct_ov025_021def64_2* prev;
    struct Struct_ov025_021def64_2* next;
    GameObject* obj;
};

extern "C" int func_ov000_021820bc(void* obj, int unused, int index, int arg);
extern "C" Vector3fix func_02049c08(struct Struct_02049c08_2* obj);
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
extern "C" void func_ov025_021df554(void* obj);
extern "C" struct Struct_ov025_021def64_2* func_ov025_021df568(struct Struct_ov025_021def64_2* head, struct Struct_ov025_021def64_2* arg1);
extern "C" struct Struct_ov025_021def64* func_ov025_021df5cc(struct Struct_ov025_021def64* node);
extern "C" fix32_t fix32_Divide(fix32_t a, fix32_t b);

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

struct Struct_ov025_021def64_3 {
#if defined(jpn)
    char pad[0x218];
#else
    char pad[0x29c];
#endif
    void* list;
};

// USA: func_ov025_021def64
extern "C" ARM void func_ov025_021def64(struct Struct_ov025_021def64_3* self, int slot, int index) {
    struct Struct_ov025_021def64_2 var0[16];
    struct Struct_ov025_021def64_2 var1[16];
    int ids[16];
    GameObject* objs[16];
    GameState* gs = GameState::GetInstance();
    int count = func_ov000_021820bc(self->list, slot, index, (int)ids);
    if (count == 0) return;

    int n = 0;
    int i;
    for (i = 0; i < count; i++) {
        objs[n] = gs->GetCombatantByIndex(ids[i]);
        if (objs[n] == NULL) continue;
        GameObject* o = objs[i];
        o->obj3D_.position_ = func_02049c08((struct Struct_02049c08_2*)o);
        GameObject_SnapFacing((struct Obj02033874*)o, 0);
        n++;
    }
    count = n;

    {
        int k;
        int var10;
        int var11;
        struct Struct_ov025_021def64_2* head;
        struct Struct_ov025_021def64_2* next;
        fix32_t scale;
        int pos;
        int r;
        int var17;
        struct Struct_ov025_021def64_2* cur;
        struct Struct_ov025_021def64_2* last;
        int span;
        int i2;
        for (i = 0; i < count; i++) {
            func_ov025_021df554(&var0[i]);
            GameObject* o = objs[i];
            var0[i].key = func_02049c08((struct Struct_02049c08_2*)o).x;
            var0[i].obj = o;
        }
        head = &var0[0];
        for (i2 = 1; i2 < count; i2++) {
            head = func_ov025_021df568(head, &var0[i2]);
        }
        last = (struct Struct_ov025_021def64_2*)func_ov025_021df5cc((struct Struct_ov025_021def64*)head);
        span = (last->key + last->obj->obj3D_.GetRadius() / 2) - (head->key - head->obj->obj3D_.GetRadius() / 2);
        if (span > 0x4000 && n > 1) {
            int var23[16];
            var10 = 0;
            var11 = 0;
            cur = head;
            k = 0;
            for (; (next = cur->next) != NULL; cur = cur->next) {
                r = cur->obj->obj3D_.GetRadius();
                var17 = (next->key - cur->key) - (next->obj->obj3D_.GetRadius() / 2 + r / 2);
                var23[k] = var17;
                var10 += var17;
                k++;
            }
            for (cur = head; cur != NULL; cur = cur->next) {
                var11 += cur->obj->obj3D_.GetRadius();
            }
            scale = 0;
            if (var11 < 0x4000 && var10 != 0) {
                scale = fix32_Divide(0x4000 - var11, var10);
            }
            k = 0;
            cur = head;
            var10 = 0;
            while ((cur = cur->next) != NULL) {
                var23[k] = FxMul(var23[k], scale);
                var10 += var23[k];
                k++;
            }
            pos = -((var11 + var10) / 2);
            k = 0;
            for (cur = head; cur != NULL; cur = cur->next, k++) {
                pos += cur->obj->obj3D_.GetRadius() / 2;
                Vector3fix p = cur->obj->obj3D_.position_;
                p.x = pos;
                cur->key = pos;
                cur->obj->obj3D_.position_ = p;
                pos += cur->obj->obj3D_.GetRadius() / 2;
                pos += var23[k];
            }
        } else {
            int off = -((head->key - head->obj->obj3D_.GetRadius() / 2) + span / 2);
            for (; head != NULL; head = head->next) {
                Vector3fix p = head->obj->obj3D_.position_;
                p.x += off;
                head->obj->obj3D_.position_ = p;
            }
        }
    }

    {
        int k;
        int var28;
        int var29;
        struct Struct_ov025_021def64_2* head;
        struct Struct_ov025_021def64_2* last;
        int span;
        struct Struct_ov025_021def64_2* next;
        fix32_t scale;
        int pos;
        int r;
        int var37;
        struct Struct_ov025_021def64_2* cur;
        int i2;
        for (i = 0; i < count; i++) {
            func_ov025_021df554(&var1[i]);
            GameObject* o = objs[i];
            var1[i].key = func_02049c08((struct Struct_02049c08_2*)o).z;
            var1[i].obj = o;
        }
        head = &var1[0];
        for (i2 = 1; i2 < count; i2++) {
            head = func_ov025_021df568(head, &var1[i2]);
            for (struct Struct_ov025_021def64_2* p = head; p != NULL; p = p->next) {
            }
        }
        last = (struct Struct_ov025_021def64_2*)func_ov025_021df5cc((struct Struct_ov025_021def64*)head);
        span = (last->key + last->obj->obj3D_.GetRadius() / 2) - (head->key - head->obj->obj3D_.GetRadius() / 2);
        if (span > 0x4000 && n > 1) {
            int var42[16];
            var28 = 0;
            var29 = 0;
            cur = head;
            k = 0;
            for (; (next = cur->next) != NULL; cur = cur->next) {
                r = cur->obj->obj3D_.GetRadius();
                var37 = (next->key - cur->key) - (next->obj->obj3D_.GetRadius() / 2 + r / 2);
                var42[k] = var37;
                var28 += var37;
                k++;
            }
            for (cur = head; cur != NULL; cur = cur->next) {
                var29 += cur->obj->obj3D_.GetRadius();
            }
            scale = 0;
            if (var29 < 0x4000 && var28 != 0) {
                scale = fix32_Divide(0x4000 - var29, var28);
            }
            k = 0;
            cur = head;
            var28 = 0;
            while ((cur = cur->next) != NULL) {
                var42[k] = FxMul(var42[k], scale);
                var28 += var42[k];
                k++;
            }
            pos = -((var29 + var28) / 2);
            k = 0;
            for (cur = head; cur != NULL; cur = cur->next) {
                pos += cur->obj->obj3D_.GetRadius() / 2;
                Vector3fix p = cur->obj->obj3D_.position_;
                p.z = pos;
                cur->key = pos;
                cur->obj->obj3D_.position_ = p;
                pos += cur->obj->obj3D_.GetRadius() / 2;
                pos += var42[k];
                k++;
            }
        } else {
            int off = -((head->key - head->obj->obj3D_.GetRadius() / 2) + span / 2);
            for (; head != NULL; head = head->next) {
                Vector3fix p = head->obj->obj3D_.position_;
                p.z += off;
                head->obj->obj3D_.position_ = p;
            }
        }
    }
}
