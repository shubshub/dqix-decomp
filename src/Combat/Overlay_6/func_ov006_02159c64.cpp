#include <globaldefs.h>

#if defined(jpn)
enum { kEntries = 0xc, Enum_ov006_02159c64_332 = 0x140 };
#else
enum { kEntries = 0x14, Enum_ov006_02159c64_332 = 0x14c };
#endif

struct Struct_ov006_02158cfc {
    char pad0[0x10];
    unsigned int unknown_10_0_:22;
    unsigned int enabled:1;
    unsigned int unknown_12_7_:9;
    char unknown_14_[8];
    Struct_ov006_02158cfc* next;
};
struct Struct_02071ffc_4 { Struct_ov006_02158cfc* head; };
struct Struct_ov006_02158cfc_2 {
    char pad0[kEntries];
    void* entries;
    char pad18[0x14];
    Struct_ov006_02158cfc* head;
    Struct_ov006_02158cfc* unknown_30_;
    char unknown_34_[Enum_ov006_02159c64_332 - kEntries - 0x20];
    Struct_02071ffc_4 unknown_14c_;
    char unknown_150_[0x35e - Enum_ov006_02159c64_332 - 4];
    short unknown_35e_;
    char unknown_360_[0xa];
    short selection;
    char unknown_36c_[0x18];
    signed char unknown_384_;
    signed char category;
    unsigned char unknown_386_;
    char unknown_387_;
    unsigned char page;
};
extern "C" Struct_ov006_02158cfc* func_ov006_02158d8c(void*, short);
extern "C" void func_02071ffc(Struct_02071ffc_4*, int, int, int, short, short*);
extern "C" void func_ov006_02158cac(void*);
struct SePlayer;
extern SePlayer g_sePlayer __attribute__((aligned(4)));
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov006_02158cfc(Struct_ov006_02158cfc_2*, Struct_ov006_02158cfc*);
extern "C" void func_020804fc(void*, int);
extern "C" void func_ov006_0215f7e8(Struct_ov006_02158cfc_2*);
extern "C" void func_ov006_0215fcf0(Struct_ov006_02158cfc_2*);

// USA: func_ov006_02159c64
extern "C" ARM void func_ov006_02159c64(Struct_ov006_02158cfc_2* self) {
    Struct_ov006_02158cfc* selected = func_ov006_02158d8c(self, self->selection - 0x29);
    if (!selected) return;
    if (!selected->enabled) {
        self->selection = -1;
        self->unknown_35e_ = -1;
        selected = 0;
    }
    self->unknown_386_ = !self->unknown_386_;
    short count = 0;
    func_02071ffc(&self->unknown_14c_, self->unknown_384_, self->category, self->unknown_386_, 16, &count);
    self->unknown_30_ = self->head = self->unknown_14c_.head;
    if (!selected) selected = self->unknown_30_;
    func_ov006_02158cac(self);
    SePlayer_Play(&g_sePlayer, 1, 0);
    short index = 0;
    for (Struct_ov006_02158cfc* node = self->unknown_30_; node; node = node->next) {
        if (node == selected) break;
        ++index;
    }
    short row = index % 16;
    self->page = index / 16;
    func_ov006_02158cfc(self, selected);
    self->selection = row + 0x29;
    func_020804fc(self->entries, 9);
    func_ov006_0215f7e8(self);
    func_ov006_0215fcf0(self);
}
