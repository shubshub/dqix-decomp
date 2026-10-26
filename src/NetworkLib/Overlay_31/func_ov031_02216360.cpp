#include <globaldefs.h>
#include <NitroSDK/Timing.h>
#include <NitroSDK/Memory.h>

struct Struct_ov031_02216360_3 {
    int unknown_0_;
    unsigned short strength;
    unsigned char unknown_6_[0x20];
    unsigned char name[10];
    char unknown_30_[0x1a];
    unsigned char unknown_4a_[0x20];
    unsigned char unknown_6a_;
    unsigned char unknown_6b_;
    unsigned char flags;
    char unknown_6d_[11];
};
struct Struct_ov031_02216360 {
    unsigned char unknown_0_[0x20];
    unsigned char unknown_20_[0x20];
    int unknown_40_;
    unsigned char name[10];
};
struct Struct_ov031_02216360_2 {
    Struct_ov031_02216360* output;
    unsigned long long started;
    Struct_ov031_02216360_3 entries[16];
    int selected;
    int unknown_794_;
};
struct Struct_ov031_0224e5dc_2 {
    Struct_ov031_02216360_2* unknown_0_;
    void* unknown_4_;
    int phase;
};
extern Struct_ov031_0224e5dc_2 data_ov031_0224e5dc;
extern "C" int func_ov031_02215fd8(void*, int, int, int);
extern "C" int func_ov031_022160b0(int);
extern "C" int func_ov031_02216178(int);
extern "C" int func_ov031_0221624c(char*);
extern "C" int func_ov031_02216070(int);
extern "C" int func_ov031_02216710(unsigned char*);
extern "C" void func_ov031_02216744();
extern "C" void func_ov031_02216758();
extern "C" void func_ov031_0221676c();
extern "C" void func_ov031_02216780();
extern "C" void func_ov031_02216794();

// USA: func_ov031_02216360
extern "C" ARM int func_ov031_02216360() {
    if (data_ov031_0224e5dc.unknown_4_ == 0 || data_ov031_0224e5dc.unknown_0_ == 0) return 3;
    int index;
    unsigned int strength;
    int result = 1;
    switch (data_ov031_0224e5dc.phase) {
    case 0:
        data_ov031_0224e5dc.phase = 1;
        if (func_ov031_02215fd8(data_ov031_0224e5dc.unknown_4_, (int)func_ov031_02216744, 0, data_ov031_0224e5dc.unknown_0_->unknown_794_))
            data_ov031_0224e5dc.phase = 11;
        break;
    case 2:
        data_ov031_0224e5dc.phase = 3;
        if (func_ov031_022160b0((int)func_ov031_02216758) == 0) {
            if (data_ov031_0224e5dc.unknown_0_->started == 0) {
                data_ov031_0224e5dc.unknown_0_->started = GetCurrentTimestamp();
            }
        } else {
            data_ov031_0224e5dc.phase = 10;
        }
        break;
    case 4: {
        unsigned long long now = GetCurrentTimestamp();
        unsigned long long started = data_ov031_0224e5dc.unknown_0_->started;
        unsigned long long elapsed = now - started;
        if (elapsed * 64 / 0x82ea < 3000) data_ov031_0224e5dc.phase = 2;
        else data_ov031_0224e5dc.phase = 5;
        break;
    }
    case 5:
        data_ov031_0224e5dc.phase = 6;
        if (func_ov031_02216178((int)func_ov031_0221676c)) data_ov031_0224e5dc.phase = 10;
        break;
    case 7: {
        if (func_ov031_0221624c((char*)data_ov031_0224e5dc.unknown_0_->entries)) data_ov031_0224e5dc.phase = 10;
        index = 0;
        data_ov031_0224e5dc.unknown_0_->selected = -1;
        strength = 0;
        do {
            if (data_ov031_0224e5dc.unknown_0_->entries[index].unknown_0_ && (data_ov031_0224e5dc.unknown_0_->entries[index].flags & 2) && data_ov031_0224e5dc.unknown_0_->entries[index].unknown_6b_ <= 3 && func_ov031_02216710(data_ov031_0224e5dc.unknown_0_->entries[index].name)) {
                if (data_ov031_0224e5dc.unknown_0_->entries[index].strength >= strength) {
                    data_ov031_0224e5dc.unknown_0_->selected = index;
                    strength = data_ov031_0224e5dc.unknown_0_->entries[index].strength;
                }
            }
            index++;
        } while (index < 16);
        data_ov031_0224e5dc.phase = 8;
        if (func_ov031_02216070((int)func_ov031_02216780)) data_ov031_0224e5dc.phase = 11;
        break;
    }
    case 9: {
        int selected = data_ov031_0224e5dc.unknown_0_->selected;
        if (selected < 0) {
            data_ov031_0224e5dc.phase = 11;
            break;
        }
        VectorizedInvertedMemcpy(data_ov031_0224e5dc.unknown_0_->entries[selected].unknown_6_, data_ov031_0224e5dc.unknown_0_->output->unknown_0_, 0x20);
        VectorizedInvertedMemcpy(data_ov031_0224e5dc.unknown_0_->entries[data_ov031_0224e5dc.unknown_0_->selected].unknown_4a_, data_ov031_0224e5dc.unknown_0_->output->unknown_20_, 0x20);
        data_ov031_0224e5dc.unknown_0_->output->unknown_40_ = data_ov031_0224e5dc.unknown_0_->entries[data_ov031_0224e5dc.unknown_0_->selected].unknown_6b_;
        VectorizedInvertedMemcpy(data_ov031_0224e5dc.unknown_0_->entries[data_ov031_0224e5dc.unknown_0_->selected].name, data_ov031_0224e5dc.unknown_0_->output->name, 10);
        result = 2;
        break;
    }
    case 10:
        data_ov031_0224e5dc.phase = 8;
        if (func_ov031_02216070((int)func_ov031_02216794)) data_ov031_0224e5dc.phase = 11;
        break;
    case 11: result = 3; break;
    }
    return result;
}
