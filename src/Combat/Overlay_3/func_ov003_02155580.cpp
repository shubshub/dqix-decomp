#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02155580_48 = 0x24 };
enum { Enum_ov003_02155580_486 = 0x1e2 };
#else
enum { Enum_ov003_02155580_48 = 0x30 };
enum { Enum_ov003_02155580_486 = 0x1e6 };
#endif

struct Struct_0207fdcc;

struct Struct_0207fdcc_2 {
    char unknown_0_[Enum_ov003_02155580_48];
    struct Struct_0207fdcc* unknown_30_;
    short unknown_34_;
    short unknown_36_;
};

struct Obj0208203c;
struct SePlayer;
struct Clamp020e29a8;
struct Obj020e280c;

extern "C" void func_020813ec(struct Obj2081* obj, int key);
void ResetWithSub0208203c(struct Obj0208203c* obj);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void SetElementFlag0x20_02080c04(struct Obj2081* obj, int key);
void ClampFieldTo2At0x16(struct Clamp020e29a8* p, int v);
void ResetAndReposition020e280c(struct Obj020e280c* self, void* b);

extern struct SePlayer g_sePlayer;

struct Struct_ov003_02155580 {
    char unknown_0_[0x8];
    void* unknown_8_;
    char unknown_c_[0x18 - 0xc];
    struct Struct_0207fdcc_2* unknown_18_;
    void* unknown_1c_;
    char unknown_20_[0x80 - 0x20];
    char unknown_80_[Enum_ov003_02155580_486 - 0x80];
    short unknown_1e6_;
    short unknown_1e8_;
    short unknown_1ea_;
};

// USA: func_ov003_02155580
extern "C" ARM void func_ov003_02155580(struct Ctx02155580* self, int arg) {
    self->key1e6 = 1;
    self->field1e8 = self->field1ea = 6;
    self->menu->selected = self->field1ea;
    func_020813ec(self->menu, self->key1e6);
    ResetWithSub0208203c((struct Obj0208203c*)self->field80);
    self->field8 = 0;
    SePlayer_Play(&g_sePlayer, 5, 0);
    if (self->cursor != 0) {
        SetElementFlag0x20_02080c04(self->menu, self->key1e6);
        ClampFieldTo2At0x16((struct Clamp020e29a8*)self->cursor, (signed char)arg);
        ResetAndReposition020e280c((struct Obj020e280c*)self->cursor, (void*)-1);
    }
}
