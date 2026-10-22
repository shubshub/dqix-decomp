#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov005_02159b74_3684 = 0xe60 };
#else
enum { Enum_ov005_02159b74_3684 = 0xe64 };
#endif

#include <GameState/GameState.h>

struct SePlayer;

struct Struct_ov005_02159b74 {
    char unknown_0_[0x38];
    unsigned char unknown_38_;
    unsigned char unknown_39_;
};

struct Struct_ov005_02159b74_2 {
    char unknown_0_[0xc];
    Struct_ov005_02159b74* unknown_c_;
    unsigned char* unknown_10_;

    Struct_ov005_02159b74* inline_ov005_02159b74() { return unknown_c_; }
};

struct Struct_ov005_02153954 {
    char unknown_0_[Enum_ov005_02159b74_3684];
    Struct_ov005_02159b74_2* unknown_e64_;
};

extern int g_sePlayer;

struct Obj020e280c;
void ResetAndReposition020e280c(Obj020e280c*, void*);
void SetHalfwordAtIndex020e16dc(unsigned char* panel, int idx, short val);
struct Obj020e1674;
void TransferObjPaletteEntry020e1674(Obj020e1674*, int, int);
struct Wf11Outer;
void ComputeElementPositions_020e1e24(Wf11Outer*, unsigned short*, unsigned short*, int);
struct WinObj020e28f0;
void SetEntryPositionFromObject(WinObj020e28f0*, short, short);
struct Ctx020e263c;
void UpdateEntryStateAndPosition(Ctx020e263c*, int);
void SePlayer_Play(SePlayer* obj, int a, int b);

// USA: func_ov005_02159b74
extern "C" ARM void func_ov005_02159b74(Struct_ov005_02153954* arg0) {
    short var0;
    short var1;
    func_020e280c((Struct_020e280c*)arg0->unknown_e64_, (void*)-1);
#if defined(jpn)
    Struct_ov005_02159b74* var2 = arg0->unknown_e64_->inline_ov005_02159b74();
    var2->unknown_38_ = 0xc2;
    var2->unknown_39_ = 0x4c;
#else
    arg0->unknown_e64_->inline_ov005_02159b74()->unknown_39_ = 0x4c;
#endif
    unsigned char* panel = self->yesNo_->panel_;
    SetHalfwordAtIndex020e16dc(panel, 0, 0x18c6);
    TransferObjPaletteEntry020e1674((Obj020e1674*)panel, 1, 0);
    ComputeElementPositions_020e1e24((Wf11Outer*)panel, (unsigned short*)&x, (unsigned short*)&y, 0);
    SetEntryPositionFromObject((WinObj020e28f0*)self->yesNo_, x, y + 4);
    int tick = GameState::GetInstance()->GetTickCount();
    if (tick == 0)
        tick = 1;
    UpdateEntryStateAndPosition((Ctx020e263c*)self->yesNo_, tick);
    SePlayer_Play((SePlayer*)&g_sePlayer, 5, 0);
}
