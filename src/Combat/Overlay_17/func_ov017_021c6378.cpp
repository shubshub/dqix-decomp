#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void* memset(void* dst, int value, unsigned int size);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_ov017_021c6254(char* self, int index);

struct Struct_ov017_021c6378_2 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021c6378_3 {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov017_021c6378_4 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[8];
    Struct_ov017_021c6378_3 unknown_a_;
    unsigned char unknown_b_;
    unsigned char unknown_c_[0xc];
};

struct Struct_ov017_021c6378_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[2];
    Struct_ov017_021c6378_4 unknown_4_[3];
};

struct Struct_ov017_021c6378_6 {
    unsigned short unknown_0_;
    unsigned short unknown_2_[3];
    unsigned char unknown_8_[3];
    Struct_ov017_021c6378_3 unknown_b_;
    Struct_ov017_021c6378_3 unknown_c_;
    Struct_ov017_021c6378_3 unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
};

struct Struct_ov017_021c6378 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021c6378_6 unknown_4_;
};

// USA: func_ov017_021c6378
extern "C" ARM void func_ov017_021c6378(char* self) {
    void* data = LinkMessageQueue_GetInstance();
    Msg021c6378 msg;
    msg.tag = 0x40;
    Payload021c6378* p = &msg.payload;
    memset(p, 0, sizeof(Payload021c6378));
    p->val = (*(Sub8e18**)(self + 0x8e18))->val;
    Party021c6378* party = (Party021c6378*)(self + 0x1b0 + 0x8000);
    p->mode = party->mode;
    for (int i = 0; i < party->count; i++) {
        p->ids[i] = party->entries[i].id;
        p->values[i] = party->entries[i].value;
        if (i == 0) {
            p->nibbles0.lo = party->entries[i].nibbles.lo;
            p->nibbles0.hi = party->entries[i].nibbles.hi;
        } else if (i == 1) {
            p->nibbles1.lo = party->entries[i].nibbles.lo;
            p->nibbles1.hi = party->entries[i].nibbles.hi;
        } else if (i == 2) {
            p->nibbles2.lo = party->entries[i].nibbles.lo;
            p->nibbles2.hi = party->entries[i].nibbles.hi;
        }
    }
    func_0205e330(var0, &var1, 0);
    for (int var5 = 0; var5 < var3->unknown_1_4_; var5++) {
        func_ov017_021c6254(arg0, var5);
    }
}
