#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_02159c64_20 = 0xc, Enum_ov006_02159c64_332 = 0x140 };
#else
enum { Enum_ov006_02159c64_20 = 0x14, Enum_ov006_02159c64_332 = 0x14c };
#endif

struct Struct_ov006_02158cfc {
    char unknown_0_[0x10];
    unsigned int unknown_10_0_:22;
    unsigned int unknown_12_6_:1;
    unsigned int unknown_12_7_:9;
    char unknown_14_[8];
    Struct_ov006_02158cfc* unknown_1c_;
};
struct Struct_02071ffc_4 { Struct_ov006_02158cfc* unknown_0_; };
struct Struct_ov006_02158cfc_2 {
    char unknown_0_[Enum_ov006_02159c64_20];
    void* unknown_14_;
    char unknown_18_[0x14];
    Struct_ov006_02158cfc* unknown_2c_;
    Struct_ov006_02158cfc* unknown_30_;
    char unknown_34_[Enum_ov006_02159c64_332 - Enum_ov006_02159c64_20 - 0x20];
    Struct_02071ffc_4 unknown_14c_;
    char unknown_150_[0x35e - Enum_ov006_02159c64_332 - 4];
    short unknown_35e_;
    char unknown_360_[0xa];
    short unknown_36a_;
    char unknown_36c_[0x18];
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    char unknown_387_;
    unsigned char unknown_388_;
};
Node02158cfc* FindNodeOrMark_02158d8c(void*, short);
void FilterAndSortEntries02071ffc(Container02071ffc*, int, int, int, short, short*);
void ComputeField_02158cac_02158cac(void*);
struct SePlayer;
extern SePlayer g_sePlayer __attribute__((aligned(4)));
void SePlayer_Play(SePlayer*, int, int);
void Checkpoint02158cfc(Cont02158cfc*, Node02158cfc*);
void ClearSublistEntriesFlag4_020804fc(void*, int);
extern "C" void func_ov006_0215f7e8(Cont02158cfc*);
extern "C" void func_ov006_0215fcf0(Cont02158cfc*);

// USA: func_ov006_02159c64
extern "C" ARM void func_ov006_02159c64(Struct_ov006_02158cfc_2* arg0) {
    Struct_ov006_02158cfc* var0 = func_ov006_02158d8c(arg0, arg0->unknown_36a_ - 0x29);
    if (!var0) return;
    if (!var0->unknown_12_6_) {
        arg0->unknown_36a_ = -1;
        arg0->unknown_35e_ = -1;
        var0 = 0;
    }
    self->reverse = !self->reverse;
    short count = 0;
    FilterAndSortEntries02071ffc(&self->filtered, self->filter, self->category, self->reverse, 16, &count);
    self->checkpoint = self->head = self->filtered.head;
    if (!selected) selected = self->checkpoint;
    ComputeField_02158cac_02158cac(self);
    SePlayer_Play(&g_sePlayer, 1, 0);
    short index = 0;
    for (Node02158cfc* node = self->checkpoint; node; node = node->next) {
        if (node == selected) break;
        ++index;
    }
    short var4 = var2 % 16;
    arg0->unknown_388_ = var2 / 16;
    func_ov006_02158cfc(arg0, var0);
    arg0->unknown_36a_ = var4 + 0x29;
    func_020804fc(arg0->unknown_14_, 9);
    func_ov006_0215f7e8(arg0);
    func_ov006_0215fcf0(arg0);
}
