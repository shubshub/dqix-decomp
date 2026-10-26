#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov005_02159b74_3684 = 0xe60 };
#else
enum { Enum_ov005_02159b74_3684 = 0xe64 };
#endif

#include <GameState/GameState.h>

struct SePlayer;

struct Struct_ov005_02159b74 {
    char unk_0[0x38];
    unsigned char unknown_38_;
    unsigned char palette_;
};

struct Struct_ov005_02159b74_2 {
    char unk_0[0xc];
    Struct_ov005_02159b74* unknown_c_;
    unsigned char* unknown_10_;

    Struct_ov005_02159b74* inline_ov005_02159b74() { return unknown_c_; }
};

struct EquipmentMenu {
    char unk_0[Enum_ov005_02159b74_3684];
    Struct_ov005_02159b74_2* unknown_e64_;
};

extern int g_sePlayer;

struct Struct_020e280c;
extern "C" void func_020e280c(Struct_020e280c*, void*);
extern "C" void func_020e16dc(unsigned char* panel, int idx, short val);
struct Struct_020e1674_2;
extern "C" void func_020e1674(Struct_020e1674_2*, int, int);
struct Struct_020e1e24;
extern "C" void func_020e1e24(Struct_020e1e24*, unsigned short*, unsigned short*, int);
struct Struct_020e28f0;
extern "C" void func_020e28f0(Struct_020e28f0*, short, short);
struct Struct_020e263c_2;
extern "C" void func_020e263c(Struct_020e263c_2*, int);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);

// USA: func_ov005_02159b74
extern "C" ARM void func_ov005_02159b74(EquipmentMenu* self) {
    short x;
    short y;
    func_020e280c((Struct_020e280c*)self->unknown_e64_, (void*)-1);
#if defined(jpn)
    Struct_ov005_02159b74* label = self->unknown_e64_->inline_ov005_02159b74();
    label->unknown_38_ = 0xc2;
    label->palette_ = 0x4c;
#else
    self->unknown_e64_->inline_ov005_02159b74()->palette_ = 0x4c;
#endif
    unsigned char* panel = self->unknown_e64_->unknown_10_;
    func_020e16dc(panel, 0, 0x18c6);
    func_020e1674((Struct_020e1674_2*)panel, 1, 0);
    func_020e1e24((Struct_020e1e24*)panel, (unsigned short*)&x, (unsigned short*)&y, 0);
    func_020e28f0((Struct_020e28f0*)self->unknown_e64_, x, y + 4);
    int tick = GameState::GetInstance()->GetTickCount();
    if (tick == 0)
        tick = 1;
    func_020e263c((Struct_020e263c_2*)self->unknown_e64_, tick);
    SePlayer_Play((SePlayer*)&g_sePlayer, 5, 0);
}
