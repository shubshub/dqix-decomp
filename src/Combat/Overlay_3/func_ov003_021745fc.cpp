#include <globaldefs.h>

#if defined(jpn)
#define data_ov003_02180cc8 data_ov003_0217ef40
#define data_ov003_02180aa4 data_ov003_0217ed08
#endif

struct Struct_020e28dc;
struct Struct_020e263c_2;
struct Struct_0207fc6c;

struct Struct_ov003_021745fc {
#if defined(jpn)
    char unk_0[0x2a];
#else
    char unk_0[0x36];
#endif
    short cursor_;
};

class Struct_ov003_021745fc_2 {
public:
    Struct_020e28dc* unknown_0_;
#if defined(jpn)
    char unk_4[0x808 - 0x4];
#else
    char unk_4[0x88c - 0x4];
#endif
    char unknown_88c_[0xc];
    unsigned short unknown_898_;
    unsigned char unknown_89a_;
    char unknown_89b_;
    Struct_ov003_021745fc* menu_;
    char unknown_8a0_[0xfe0 - 0x8a0];
    int ticks_;
    int unknown_fe4_;
    char unknown_fe8_[0xff8 - 0xfe8];
    short* cursor_;
    short unknown_ffc_;
    short unknown_ffe_;
    short unknown_1000_;
    char unknown_1002_[0x1036 - 0x1002];
    short unknown_1036_;
    char unknown_1038_[0x103e - 0x1038];
    unsigned char state_;
    char unknown_103f_[0x1046 - 0x103f];
    unsigned short flags_;
};

typedef void (Struct_ov003_021745fc_2::*Type_020200c0)();

extern "C" {
bool func_ov017_021959b4();
void func_ov003_02174550(Struct_ov003_021745fc_2* self);
void func_ov003_021749f0(Struct_ov003_021745fc_2* self);
void func_ov003_021760cc(Struct_ov003_021745fc_2* self);
void func_02081f20(void* repeat, int ticks);
int func_020800fc(Struct_ov003_021745fc* menu, short* cursor, short arg2, unsigned short arg3, unsigned char, bool);
void func_020813ec(Struct_ov003_021745fc* menu, short group);
}

extern "C" void func_ov003_02174988(char* self);
extern "C" void func_ov003_0217451c(char* self);
extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_0207fc6c(Struct_0207fc6c* obj, int ticks);
extern "C" void func_020804fc(void* menu, int group);
extern "C" int func_020e28dc(Struct_020e28dc* o);
extern "C" void func_020e263c(Struct_020e263c_2* ctx, int ticks);

extern unsigned int data_ov003_02180cc8[2];
extern Type_020200c0 __ptmf_null;
extern Type_020200c0 data_ov003_02180aa4[10];

// USA: func_ov003_021745fc
extern "C" ARM bool func_ov003_021745fc(Struct_ov003_021745fc_2* self, int ticks) {
    self->ticks_ = ticks;
    if (func_ov017_021959b4())
        func_ov003_02174550(self);
    func_ov003_021749f0(self);
    func_ov003_02174988((char*)self);
    func_ov003_0217451c((char*)self);

    if (self->state_ != 0) {
        if (self->unknown_1036_ >= 0) {
            func_ov003_021760cc(self);
            return false;
        }
#if defined(jpn)
        ((unsigned char*)MessageSystem_GetInstance())[0x17de] = 0;
#else
        ((unsigned char*)MessageSystem_GetInstance())[0x19ae] = 0;
#endif
        Struct_ov003_021745fc* menu = self->menu_;
        if (menu != NULL)
            func_0207fc6c((Struct_0207fc6c*)menu, ticks);
        if (self->cursor_ != NULL) {
            func_02081f20(self->unknown_88c_, ticks);
            self->unknown_1000_ = *self->cursor_;
            self->unknown_fe4_ = func_020800fc(menu, self->cursor_, self->unknown_1000_, self->unknown_898_, self->unknown_89a_, (self->flags_ & 0x400) != 0);
            menu->cursor_ = *self->cursor_;
            if (self->unknown_fe4_ != 0)
                func_020804fc(menu, self->unknown_ffe_);
            if (self->unknown_1000_ != *self->cursor_)
                func_020813ec(menu, self->unknown_ffe_);
        }
    }

    if (self->unknown_0_ != NULL && func_020e28dc(self->unknown_0_))
        func_020e263c((Struct_020e263c_2*)self->unknown_0_, self->ticks_);

    if (!(data_ov003_02180cc8[0] & 1)) {
        data_ov003_02180aa4[9] = __ptmf_null;
        data_ov003_02180cc8[0] |= 1;
    }
    if (data_ov003_02180aa4[self->state_] == NULL) {
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        return !(self->flags_ & 0x80);
    }
    (self->*data_ov003_02180aa4[self->state_])();
    return false;
}
