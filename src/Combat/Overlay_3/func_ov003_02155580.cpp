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
    char pad0[Enum_ov003_02155580_48];
    struct Struct_0207fdcc* elems;
    short field34;
    short selected;
};

struct Struct_02081f20_2;
struct SePlayer;
struct Struct_020e29a8;
struct Struct_020e280c;

extern "C" void func_020813ec(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_02080c04(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_020e29a8(struct Struct_020e29a8* p, int v);
extern "C" void func_020e280c(struct Struct_020e280c* self, void* b);

extern struct SePlayer g_sePlayer;

struct Struct_ov003_02155580 {
    char pad0[0x8];
    void* field8;
    char pad1[0x18 - 0xc];
    struct Struct_0207fdcc_2* menu;
    void* cursor;
    char pad2[0x80 - 0x20];
    char unknown_80_[Enum_ov003_02155580_486 - 0x80];
    short unknown_1e6_;
    short unknown_1e8_;
    short unknown_1ea_;
};

// USA: func_ov003_02155580
extern "C" ARM void func_ov003_02155580(struct Struct_ov003_02155580* self, int arg) {
    self->unknown_1e6_ = 1;
    self->unknown_1e8_ = self->unknown_1ea_ = 6;
    self->menu->selected = self->unknown_1ea_;
    func_020813ec(self->menu, self->unknown_1e6_);
    func_0208203c((struct Struct_02081f20_2*)self->unknown_80_);
    self->field8 = 0;
    SePlayer_Play(&g_sePlayer, 5, 0);
    if (self->cursor != 0) {
        func_02080c04(self->menu, self->unknown_1e6_);
        func_020e29a8((struct Struct_020e29a8*)self->cursor, (signed char)arg);
        func_020e280c((struct Struct_020e280c*)self->cursor, (void*)-1);
    }
}
