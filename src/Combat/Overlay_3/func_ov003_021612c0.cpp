#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_021612c0_54 = 0x2a };
enum { Enum_ov003_021612c0_776 = 0x1f0 };
enum { Enum_ov003_021612c0_804 = 0x20c };
enum { Enum_ov003_021612c0_912 = 0x278 };
enum { Enum_ov003_021612c0_808 = 0x210 };
enum { Enum_ov003_021612c0_1136 = 0x298 };
enum { Enum_ov003_021612c0_916 = 0x27c };
enum { Enum_ov003_021612c0_1160 = 0x2b0 };
enum { Enum_ov003_021612c0_1142 = 0x29e };
enum { Enum_ov003_021612c0_1180 = 0x2c4 };
enum { Enum_ov003_021612c0_1162 = 0x2b2 };
#else
enum { Enum_ov003_021612c0_54 = 0x36 };
enum { Enum_ov003_021612c0_776 = 0x308 };
enum { Enum_ov003_021612c0_804 = 0x324 };
enum { Enum_ov003_021612c0_912 = 0x390 };
enum { Enum_ov003_021612c0_808 = 0x328 };
enum { Enum_ov003_021612c0_1136 = 0x470 };
enum { Enum_ov003_021612c0_916 = 0x394 };
enum { Enum_ov003_021612c0_1160 = 0x488 };
enum { Enum_ov003_021612c0_1142 = 0x476 };
enum { Enum_ov003_021612c0_1180 = 0x49c };
enum { Enum_ov003_021612c0_1162 = 0x48a };
#endif

struct Struct_0207fdcc_2 {
    char pad[Enum_ov003_021612c0_54];
    unsigned short unknown_36_;
};

struct Struct_02081f20_2;
struct Struct_020e280c;
struct SePlayer;

extern "C" int func_020813ec(void *obj, int id);
extern "C" void func_0208203c(struct Struct_02081f20_2 *obj);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_02080c04(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_020e280c(struct Struct_020e280c* self, void* b);

extern struct SePlayer g_sePlayer;

struct Struct_ov003_021612c0 {
    char pad0[Enum_ov003_021612c0_776];
    char unknown_308_[Enum_ov003_021612c0_804 - Enum_ov003_021612c0_776];
    struct Struct_0207fdcc_2* unknown_324_;
    char pad1[Enum_ov003_021612c0_912 - Enum_ov003_021612c0_808];
    struct Struct_020e280c* unknown_390_;
    char pad2[Enum_ov003_021612c0_1136 - Enum_ov003_021612c0_916];
    int unknown_470_;
    short unknown_474_;
    char pad3[Enum_ov003_021612c0_1160 - Enum_ov003_021612c0_1142];
    short unknown_488_;
    char pad4[Enum_ov003_021612c0_1180 - Enum_ov003_021612c0_1162];
    short unknown_49c_;
};

// USA: func_ov003_021612c0
extern "C" ARM void func_ov003_021612c0(struct Struct_ov003_021612c0* self) {
    self->unknown_488_ = 9;
    self->unknown_474_ = self->unknown_49c_ = 0x2c;
    self->unknown_324_->unknown_36_ = self->unknown_49c_;
    func_020813ec(self->unknown_324_, self->unknown_488_);
    func_0208203c((struct Struct_02081f20_2*)self->unknown_308_);
    self->unknown_470_ = 0;
    SePlayer_Play(&g_sePlayer, 5, 0);
    if (self->unknown_390_ == NULL) {
        return;
    }
    func_02080c04(self->unknown_324_, self->unknown_488_);
    func_020e280c(self->unknown_390_, (void*)-1);
}
