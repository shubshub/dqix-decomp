#if defined(jpn)
#define data_ov026_021de7fa data_ov026_021ded16
#define data_ov026_021de802 data_ov026_021ded1e
#define data_ov026_021de812 data_ov026_021ded2e
#define data_ov026_021de822 data_ov026_021ded3e
#define data_ov026_021def00 data_ov026_021df660
#define func_ov000_02171ffc func_ov000_02173834
#endif
#include <globaldefs.h>

struct GameState;
struct Struct_ov000_02161e30;
struct Container_021dae60;
struct StructAt020473c8;

struct Pos3 {
    int v[3];
};

struct Struct_ov026_021de6cc {
    short v[4];
};

struct Struct_ov026_021de802 {
    short v[8];
};

struct Struct_ov026_021d8ba0_6 {
    char pad0[0x10];
    signed char unknown_10_[8];
    signed char cursor;
    char unknown_19_[0x3];
    signed char kind;
    signed char target;
    char pad1e[0x10];
    signed char owner;
};

struct Struct_ov000_0215ab88 {
    char pad0[0x4];
    short id;
    char pad6[0x3e];
    Pos3 pos;
};

struct Struct_ov026_021dddcc_2 {
    char pad0[0x80];
    unsigned short icon;
    char unknown_82_[0x6];
};

struct Struct_ov000_02160da0 {
    #if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    Struct_ov000_02161e30* battle;
    char unknown_2a0_[0xc08];
    int mode;
    int state;
    #if defined(jpn)
    char unknown_e2c_[0x28f0];
#else
    char unknown_eb0_[0x28b0];
#endif
    char list[0x17c];
    int unknown_38dc_;
    #if defined(jpn)
    char unknown_389c_[0x1f54];
#else
    char unknown_38e0_[0x1d20];
#endif
    Struct_ov026_021dddcc_2 icons[2];
    char unknown_5710_[0x2002];
    signed char phase;
};

struct Struct_ov026_021def00 {
    float value;
    float angle;
};

extern "C" {
GameState* _ZN9GameState11GetInstanceEv();
Struct_ov000_0215ab88* _ZN9GameState21GetPartyMemberByIndexEi(GameState* gs, int index);
extern "C" unsigned char* func_02053c6c(unsigned char* obj);
extern "C" char* func_020a6084();
extern "C" Struct_ov026_021d8ba0_6* func_ov026_021dae60(Container_021dae60* list, int id);
extern "C" int func_ov000_021719f8(int* obj);
extern "C" int func_ov000_021761c8(char* base, int index);
extern "C" int func_ov000_021761ec(char* base, int index);
extern "C" Struct_ov000_0215ab88* func_0200fea4(GameState* gs, int id);
void* _ZN9GameState9GetCameraEv(GameState* gs); // GameState::GetCamera()
int _ZNK8Object3D9GetHeightEv(Struct_ov000_0215ab88* obj);
extern "C" int Camera_WorldToScreen(void* obj, Pos3* src, int* out1, int* out2);
extern "C" void func_020473c8(Struct_ov026_021dddcc_2* obj, int param1);
void Vector3fix_Add(const Pos3* a, const Pos3* b, Pos3* out);
void Vector3fix_Normalize(const Pos3* in, Pos3* out);
int func_ov000_0217fd60(void* list, int id);
int func_ov000_0215e9fc(Struct_ov000_02161e30* battle, short* out, int max, int flag);
int func_ov000_0215eb1c(Struct_ov000_02161e30* battle, short* out, int max, int flag);
int func_ov000_02153e78(Struct_ov000_02161e30* battle, short* out, int max, int group, int flag);
int func_ov000_02171ffc(Struct_ov026_021d8ba0_6* slot);
double func_02009424(double x);
void __clear(void* dst, int size);
}

extern Struct_ov026_021de6cc data_ov026_021de7fa;
extern Struct_ov026_021de802 data_ov026_021de802;
extern Struct_ov026_021de802 data_ov026_021de812;
extern Struct_ov026_021de802 data_ov026_021de822;
extern Struct_ov026_021def00 data_ov026_021def00;

#define IN_RANGE(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

static inline void inline_ov026_021dddcc() {
    *(volatile int*)0x04000444 = 0;
}

static inline void inline_ov026_021dddcc_2(int n) {
    *(volatile int*)0x04000448 = n;
}

static inline void inline_ov026_021dddcc_3(int x, int y, int z) {
    *(volatile int*)0x04000470 = x;
    *(volatile int*)0x04000470 = y;
    *(volatile int*)0x04000470 = z;
}

// USA: func_ov026_021dddcc
extern "C" ARM void func_ov026_021dddcc(Struct_ov000_02160da0* self) {
    Struct_ov026_021de802 var0;
    short cnt[8];
    short var2[8];
    unsigned short icons[4];
    Struct_ov026_021de6cc ids;
    short counts[4];
    GameState* gs = _ZN9GameState11GetInstanceEv();
    Struct_ov000_02161e30* battle = self->battle;
    char* data;
    signed char m;
    int n;
    int var11;
    int i;
    int k;
    int t;

    if (self->mode != 7 || self->state != 4) {
        return;
    }
    if (func_ov000_0217fd60(self->list, -1) == 0) {
        return;
    }
    if (self->phase != 0) {
        return;
    }

    __clear(icons, sizeof(icons));
    data = func_020a6084();
    for (m = 0; m < 4; m++) {
        Struct_ov000_0215ab88* c = _ZN9GameState21GetPartyMemberByIndexEi(gs, m);
        if (c != 0) {
            unsigned char* f = func_02053c6c((unsigned char*)c);
            if (f != 0) {
                icons[m] = *(unsigned short*)(data + f[0x56a] * 0x20 + 0x1e);
            }
        }
    }

    ids = data_ov026_021de7fa;
    n = func_ov000_0215e9fc(battle, ids.v, 4, 0);
    var0 = data_ov026_021de802;
    var11 = func_ov000_0215eb1c(battle, var0.v, 8, 1);
    __clear(counts, sizeof(counts));
    __clear(cnt, sizeof(cnt));
    __clear(var2, sizeof(var2));

    for (i = 0; i < n; i++) {
        int id = ids.v[i];
        Struct_ov026_021d8ba0_6* slot = func_ov026_021dae60((Container_021dae60*)self->list, id);
        int owned;
        int group;
        int target;
        if (slot == 0) continue;
        if (func_ov000_021719f8((int*)slot) != 0) continue;
        if (slot->kind == 6) continue;
        owned = 0;
        if (slot->owner >= 0) {
            owned = slot->owner <= 3;
        }
        if (owned) continue;
        if (slot->unknown_10_[slot->cursor] != 0xe && slot->unknown_10_[slot->cursor] != 0x64) continue;
        target = slot->target;
        if (target < 0) continue;
        group = func_ov000_021761c8(self->list, target);
        target = func_ov000_021761ec(self->list, target);
        switch (func_ov000_02171ffc(slot)) {
        case 3:
            counts[i] = var11;
            if (id != self->unknown_38dc_) {
                int j;
                for (j = 0; j < var11; j++) {
                    int e = var0.v[j] - 0xc0;
                    if (e >= 0 && e < 8) {
                        cnt[e]++;
                    }
                }
            }
            break;
        case 4: {
            Struct_ov026_021de802 list;
            list = data_ov026_021de812;
            counts[i] = func_ov000_02153e78(battle, list.v, 8, group, 1);
            if (id != self->unknown_38dc_) {
                int j;
                for (j = 0; j < counts[i]; j++) {
                    int e = list.v[j] - 0xc0;
                    if (e >= 0 && e < 8) {
                        cnt[e]++;
                    }
                }
            }
            break;
        }
        case 2:
            if (IN_RANGE(target)) continue;
            counts[i] = 1;
            if (id != self->unknown_38dc_) {
                int e = target - 0xc0;
                if (e >= 0 && e < 8) {
                    cnt[e]++;
                }
            }
            break;
        }
    }

    for (k = 0; k < 8; k++) {
        var2[k] = cnt[k] * -5;
    }

    data_ov026_021def00.angle += 0.1f;
    if (6.28f < data_ov026_021def00.angle) {
        data_ov026_021def00.angle -= 6.28f;
    }
    {
        float angle = data_ov026_021def00.angle;
        if (6.28f < angle) {
            angle -= 6.28f;
        }
        data_ov026_021def00.value = func_02009424((double)(angle));
    }

    for (t = 0; t < n; t++) {
        unsigned char var29;
        int id = ids.v[t];
        var29 = 0;
        Struct_ov026_021d8ba0_6* slot = func_ov026_021dae60((Container_021dae60*)self->list, id);
        int owned;
        int target;
        int group;
        int mode;
        short count;
        int j;
        if (slot == 0) continue;
        if (func_ov000_021719f8((int*)slot) != 0) continue;
        if (slot->kind == 6) continue;
        owned = 0;
        if (slot->owner >= 0) {
            owned = slot->owner <= 3;
        }
        if (owned) continue;
        if (slot->unknown_10_[slot->cursor] != 0xe && slot->unknown_10_[slot->cursor] != 0x64) continue;
        target = slot->target;
        if (target < 0) continue;
        group = func_ov000_021761c8(self->list, target);
        target = func_ov000_021761ec(self->list, target);
        mode = func_ov000_02171ffc(slot);
        Struct_ov026_021de802 targets;
        targets = data_ov026_021de822;
        count = 0;
        switch (mode) {
        case 3:
            count = func_ov000_0215eb1c(battle, targets.v, 8, 1);
            if (count == 0) continue;
            break;
        case 4:
            var29 = 1;
            count = func_ov000_02153e78(battle, targets.v, 8, group, var29);
            if (count == 0) continue;
            break;
        case 2:
            if (IN_RANGE(target)) continue;
            targets.v[0] = target;
            count = 1;
            break;
        }
        for (j = 0; j < count; j++) {
            Struct_ov000_0215ab88* c = func_0200fea4(gs, targets.v[j]);
            int e;
            if (c == 0) continue;
            e = c->id - 0xc0;
            if (e < 0) continue;
            if (e >= 8) continue;
            if (id == self->unknown_38dc_) {
                Pos3 dir;
                Pos3 var42;
                Pos3 pos;
                int x, y;
                int dy;
                void* view;
                Struct_ov026_021dddcc_2* var48;
                dir.v[1] = 1;
                dir.v[0] = 1;
                dir.v[2] = 0;
                Vector3fix_Normalize(&dir, &var42);
                var42.v[0] = (float)var42.v[0] * (0.2f * data_ov026_021def00.value);
                var42.v[1] = (float)var42.v[1] * (0.2f * data_ov026_021def00.value);
                view = _ZN9GameState9GetCameraEv(gs);
                pos = c->pos;
                pos.v[1] += _ZNK8Object3D9GetHeightEv(c);
                Vector3fix_Add(&pos, &var42, &pos);
                Camera_WorldToScreen(view, &pos, &x, &y);
                dy = 0x18;
                if (var29 != 0) {
                    if (target == targets.v[j]) {
                        dy = 0x20;
                    }
                }
                var48 = &self->icons[0];
                var48->icon = icons[id];
                inline_ov026_021dddcc();
                inline_ov026_021dddcc_3((x + var2[e]) << 12, (y + 3 - dy) << 12, 0x1000);
                func_020473c8(var48, 1);
                inline_ov026_021dddcc_2(1);
            } else {
                Pos3 dir;
                Pos3 var50;
                Pos3 pos;
                int x, y;
                void* view;
                Struct_ov026_021dddcc_2* var55;
                dir.v[1] = 1;
                dir.v[2] = 0;
                dir.v[0] = 0;
                Vector3fix_Normalize(&dir, &var50);
                var50.v[0] = 0;
                var50.v[1] = 0;
                view = _ZN9GameState9GetCameraEv(gs);
                pos = c->pos;
                pos.v[1] += _ZNK8Object3D9GetHeightEv(c);
                Vector3fix_Add(&pos, &var50, &pos);
                Camera_WorldToScreen(view, &pos, &x, &y);
                var55 = &self->icons[1];
                var55->icon = icons[id];
                inline_ov026_021dddcc();
                inline_ov026_021dddcc_3((x + var2[e]) << 12, (y - 0x18) << 12, 0);
                func_020473c8(var55, 1);
                inline_ov026_021dddcc_2(1);
            }
            var2[e] += 10;
        }
    }
}
