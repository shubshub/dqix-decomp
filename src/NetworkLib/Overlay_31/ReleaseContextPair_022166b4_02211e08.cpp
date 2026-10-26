#include <globaldefs.h>

extern "C" ARM void func_ov031_022166b4(void);
extern "C" int func_ov031_02216360(void);
extern "C" ARM void func_ov031_02211d54(int, int, int, int, int);
extern "C" int func_ov031_02212ee8(void);
extern "C" int func_ov031_0220d540(void);

struct Struct_ov031_02211e08 {
    int field0;
    unsigned short field4;
    unsigned short field6;
    unsigned char pad1[4];
    unsigned char fieldc;
    unsigned char pad2[3];
    int field10;
};
struct Struct_ov031_0224e5b4 { void* pad0; Struct_ov031_02211e08* unknown_4_; };
extern Struct_ov031_0224e5b4 data_ov031_0224e5b4;

// USA: func_ov031_02211e08
extern "C" ARM void func_ov031_02211e08(void) {
    if (data_ov031_0224e5b4.unknown_4_ == 0) return;
    switch (data_ov031_0224e5b4.unknown_4_->field10) {
    case 1:
        data_ov031_0224e5b4.unknown_4_->field0 = 0;
        data_ov031_0224e5b4.unknown_4_->field10 = func_ov031_02216360();
        return;
    case 2: {
        func_ov031_022166b4();
        char* c = (char*)data_ov031_0224e5b4.unknown_4_;
        func_ov031_02211d54((int)(c + 0x14), (int)(c + 0x34), *(int*)(c + 0x54), (int)(c + 0x58), 8);
        data_ov031_0224e5b4.unknown_4_->field10 = 0;
        return;
    }
    case 3:
        func_ov031_022166b4();
        data_ov031_0224e5b4.unknown_4_->field0 = -1;
        data_ov031_0224e5b4.unknown_4_->fieldc = 1;
        return;
    case 4:
    case 5:
        return;
    default:
        break;
    }
    unsigned short f4 = data_ov031_0224e5b4.unknown_4_->field4;
    if (f4 == 2) {
        data_ov031_0224e5b4.unknown_4_->field0 = func_ov031_02212ee8();
        return;
    }
    if (f4 != 4) return;
    if (data_ov031_0224e5b4.unknown_4_->field6 == 0) return;
    if (func_ov031_0220d540() == 9) return;
    data_ov031_0224e5b4.unknown_4_->field6 = 0;
    data_ov031_0224e5b4.unknown_4_->field4 = 6;
}
