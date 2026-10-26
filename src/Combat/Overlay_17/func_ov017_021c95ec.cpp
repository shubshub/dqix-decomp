#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c95ec {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov017_021c95ec_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_;
    unsigned char unknown_6_0_ : 6;
    unsigned char unknown_6_6_ : 1;
    unsigned char unknown_6_7_ : 1;
    unsigned char unknown_7_0_ : 4;
    signed char unknown_7_4_ : 4;
    short unknown_8_;
    short unknown_a_;
    int unknown_c_;
    int unknown_10_;
};

// USA: func_ov017_021c95ec
extern "C" ARM void func_ov017_021c95ec(int id, int lowNibble, int unused, int kind, int highNibble,
                                        struct Vec3i021c95ec v, int field8, unsigned char flag6, unsigned char flag7) {
    void* data = LinkMessageQueue_GetInstance();
    struct Evt021c95ec evt;
    evt.lowNibble = lowNibble;
    evt.highNibble = highNibble;
    evt.field_c = v.x;
    evt.kind = kind;
    evt.flag6 = flag6;
    evt.flag7 = flag7;
    evt.id = id;
    evt.tag = 0x87;
    evt.field_a = v.y >> 4;
    evt.field_10 = v.z;
    evt.field8 = field8;
    func_0205e330(data, &evt, 0);
}
