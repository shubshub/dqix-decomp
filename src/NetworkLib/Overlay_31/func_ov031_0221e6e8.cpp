#include <globaldefs.h>

#if defined(jpn)
#define func_020ca3b8 func_020cbe84
#endif

struct Struct_ov031_0221e6e8_2 {
    unsigned int field_0;
    unsigned char unknown_4_[6];
    unsigned short unknown_a_;
    char name_[32];
    unsigned short mode_;
    unsigned short unknown_2e_;
    unsigned short unknown_30_;
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
};
struct Struct_ov031_0221e6e8 {
    unsigned int unknown_0_;
    char name_[32];
    unsigned int unknown_24_;
    char unknown_28_[8];
    unsigned char unknown_30_[6];
    char unknown_36_[2];
    int count_;
    unsigned char items_[16];
    unsigned int unknown_4c_;
    int mode_;
};
struct Struct_ov031_0224b0e4 { unsigned short unknown_0_; unsigned char unknown_2_; unsigned char unknown_; };
extern Struct_ov031_0224b0e4 data_ov031_0224b0e4[12] __attribute__((aligned(4)));
extern "C" void func_020ca3b8(const void*, void*, unsigned int);

// USA: func_ov031_0221e6e8
extern "C" THUMB void func_ov031_0221e6e8(Struct_ov031_0221e6e8_2* record, Struct_ov031_0221e6e8* arg1) {
    arg1->unknown_0_ = record->unknown_a_;
    func_020ca3b8(record->name_, arg1->name_, 32);
    arg1->unknown_24_ = record->unknown_36_;
    func_020ca3b8(record->unknown_4_, arg1->unknown_30_, 6);
    int i;
    int count = 0;
    Struct_ov031_0224b0e4* item = data_ov031_0224b0e4;
    i = 0;
    do {
        if (record->unknown_30_ & item->unknown_0_) {
            arg1->items_[count] = item->unknown_2_;
            if (record->unknown_2e_ & item->unknown_0_)
                arg1->items_[count] = arg1->items_[count] | 0x80;
            count++;
        }
        i++;
        item++;
    } while (i < 12);
    arg1->count_ = count;
    arg1->unknown_4c_ = record->unknown_32_;
    int mode = record->mode_ & 3;
    if (mode == 1) arg1->mode_ = 1;
    else if (mode == 2) arg1->mode_ = 2;
    else arg1->mode_ = 0;
}
