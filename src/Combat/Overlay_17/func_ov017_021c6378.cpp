#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* memset(void* dst, int value, unsigned int size);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_ov017_021c6254(char* self, int index);

struct Struct_ov017_021c6378_2 {
    unsigned char pad[8];
    unsigned short val;
};

struct Struct_ov017_021c6378_3 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Struct_ov017_021c6378_4 {
    unsigned short id;
    unsigned char pad2[8];
    Struct_ov017_021c6378_3 nibbles;
    unsigned char value;
    unsigned char unknown_c_[0xc];
};

struct Struct_ov017_021c6378_5 {
    unsigned char field0;
    unsigned char unknown_1_0_ : 4;
    unsigned char count : 2;
    unsigned char mode : 2;
    unsigned char pad2[2];
    Struct_ov017_021c6378_4 entries[3];
};

struct Struct_ov017_021c6378_6 {
    unsigned short val;
    unsigned short ids[3];
    unsigned char values[3];
    Struct_ov017_021c6378_3 unknown_b_;
    Struct_ov017_021c6378_3 unknown_c_;
    Struct_ov017_021c6378_3 unknown_d_;
    unsigned char mode;
    unsigned char unknown_f_;
};

struct Struct_ov017_021c6378 {
    unsigned char tag;
    unsigned char pad1[3];
    Struct_ov017_021c6378_6 payload;
};

// USA: func_ov017_021c6378
extern "C" ARM void func_ov017_021c6378(char* self) {
    void* data = LinkMessageQueue_GetInstance();
    Struct_ov017_021c6378 msg;
    msg.tag = 0x40;
    Struct_ov017_021c6378_6* p = &msg.payload;
    memset(p, 0, sizeof(Struct_ov017_021c6378_6));
    p->val = (*(Struct_ov017_021c6378_2**)(self + 0x8e18))->val;
    Struct_ov017_021c6378_5* party = (Struct_ov017_021c6378_5*)(self + 0x1b0 + 0x8000);
    p->mode = party->mode;
    for (int i = 0; i < party->count; i++) {
        p->ids[i] = party->entries[i].id;
        p->values[i] = party->entries[i].value;
        if (i == 0) {
            p->unknown_b_.lo = party->entries[i].nibbles.lo;
            p->unknown_b_.hi = party->entries[i].nibbles.hi;
        } else if (i == 1) {
            p->unknown_c_.lo = party->entries[i].nibbles.lo;
            p->unknown_c_.hi = party->entries[i].nibbles.hi;
        } else if (i == 2) {
            p->unknown_d_.lo = party->entries[i].nibbles.lo;
            p->unknown_d_.hi = party->entries[i].nibbles.hi;
        }
    }
    func_0205e330(data, &msg, 0);
    for (int j = 0; j < party->count; j++) {
        func_ov017_021c6254(self, j);
    }
}
