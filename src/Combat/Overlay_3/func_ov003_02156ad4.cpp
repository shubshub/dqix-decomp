#include <globaldefs.h>

extern "C" {
void* _ZN9GameState11GetInstanceEv(void);
extern "C" int func_02080468(void*, int);
void func_020813ec(void*, int);
extern "C" void func_0208203c(void*);
int func_ov003_021550dc(void*);
extern "C" void SePlayer_Play(void*, int, int);
extern "C" int GameState_GetProtagonistIndex(void*);
extern "C" int func_ov003_02155f88(void*, int);
extern "C" void func_0207fe44(void*);
extern "C" void* GameState_GetParty(void*);
void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" int GameObject_GetPartyMemberLevel(void*);
int func_ov003_02155208(void*);
}

extern char g_sePlayer[];

struct Struct_ov003_02156ad4_3 {
    short cmd;
    short arg;
};

struct Struct_ov003_02156ad4_4 {
    char unknown_0_[8];
    void* f08;
    char unknown_c_[0xc];
    void* f18;
    char unknown_1c_[0x80 - 0x1c];
    char unknown_80_[0x80];
#if defined(jpn)
    char unknown_100_[0x1dc - 0x100];
#else
    char unknown1_100_[0x1e0 - 0x100];
#endif
    short unknown_1e0_;
    char unknown_1e2_[4];
    short unknown_1e6_;
    char unknown_1e8_[0x1ec - 0x1e8];
    struct Struct_ov003_02156ad4_3 unknown_1ec_;
    char unknown_1f0_[2];
    unsigned char unknown_1f2_;
    char unknown_1f3_[4];
    char f1f7;
    unsigned char mode;
    unsigned char state;
    char unknown_1fa_;
    unsigned char unknown_1fb_;
    unsigned int flags;
};

struct Struct_ov003_02156ad4 {
#if defined(jpn)
    char pad0[0x2a];
#else
    char pad0[0x36];
#endif
    short unknown_36_;
};

struct Q02156ad4 {
    char pad0[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char f7c;
};

// USA: func_ov003_02156ad4
extern "C" ARM void func_ov003_02156ad4(struct Struct_ov003_02156ad4_4* self) {
    struct Struct_ov003_02156ad4* p = (struct Struct_ov003_02156ad4*)self->f18;
    struct Struct_ov003_02156ad4_3* var1 = &self->unknown_1ec_;
    int i;
    if (self->state == 0) {
        self->unknown_1e6_ = 2;
        if (self->unknown_1e0_ < 0) {
            self->unknown_1e0_ = func_02080468(p, self->unknown_1e6_);
        }
        p->unknown_36_ = self->unknown_1e0_;
        func_020813ec(p, self->unknown_1e6_);
        func_0208203c(self->unknown_80_);
        self->f08 = 0;
        self->state = self->state + 1;
        return;
    }
    if (self->state != 1) {
        return;
    }
    self->f08 = &self->unknown_1e0_;
    if (func_ov003_021550dc(self) != 0) {
        SePlayer_Play(g_sePlayer, 1, 0);
        func_0208203c(self->unknown_80_);
        self->f08 = 0;
        void* gs = _ZN9GameState11GetInstanceEv();
        switch (self->unknown_1e0_) {
        case 8:
            if (self->unknown_1fb_ == 0) {
                self->f1f7 = GameState_GetProtagonistIndex(gs);
                self->state = 0;
                if (func_ov003_02155f88(self, self->f1f7)) {
                    var1->cmd = 8;
                    self->mode = 7;
                    func_0207fe44(p);
                    return;
                }
                self->flags = self->flags | 2;
                var1->cmd = 9;
                self->mode = 3;
                self->state = 0;
            } else {
                self->f1f7 = self->unknown_1f2_;
                var1->cmd = 6;
                self->mode = 2;
                self->state = 2;
            }
            break;
        case 9: {
            unsigned char st;
            if (self->unknown_1fb_ == 0) {
                self->f1f7 = GameState_GetProtagonistIndex(gs);
                var1->cmd = 0xe;
                self->mode = 4;
                st = 2;
            } else {
                var1->cmd = 0xe;
                var1->arg = 0xf;
                self->mode = 4;
                st = 0;
            }
            self->state = st;
            unsigned char count;
            struct Q02156ad4* q;
            void* gs2 = _ZN9GameState11GetInstanceEv();
            q = (struct Q02156ad4*)GameState_GetParty(gs2);
            count = q->f7c;
            int found;
            for (i = 0; i < count; i++) {
                void* m = _ZN9GameState21GetPartyMemberByIndexEi(gs2, q->unknown_f78_[i]);
                if (m != 0 && GameObject_GetPartyMemberLevel(m) == 0x63) {
                    found = 1;
                    goto found_done;
                }
            }
            found = 0;
        found_done:
            if (found == 0) {
                var1->arg = 0x42;
                self->mode = 7;
            }
            break;
        }
        default:
            break;
        }
        func_0207fe44(p);
    } else {
        if (func_ov003_02155208(self) != 0) {
            self->f08 = 0;
            func_0207fe44(p);
            var1->cmd = 5;
            self->mode = 7;
        }
    }
}
