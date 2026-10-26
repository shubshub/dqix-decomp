#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c95ec {
    int x;
    int y;
    int z;
};

struct Struct_ov017_021c95ec_2 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned short id;
    unsigned char kind : 6;
    unsigned char unknown_6_6_ : 1;
    unsigned char flag7 : 1;
    unsigned char unknown_7_0_ : 4;
    signed char unknown_7_4_ : 4;
    short field8;
    short field_a;
    int unknown_c_;
    int unknown_10_;
};

// USA: func_ov017_021c95ec
extern "C" ARM void func_ov017_021c95ec(int id, int arg1, int unused, int kind, int arg4,
                                        struct Struct_ov017_021c95ec v, int field8, unsigned char arg7, unsigned char flag7) {
    void* data = LinkMessageQueue_GetInstance();
    struct Struct_ov017_021c95ec_2 evt;
    evt.unknown_7_0_ = arg1;
    evt.unknown_7_4_ = arg4;
    evt.unknown_c_ = v.x;
    evt.kind = kind;
    evt.unknown_6_6_ = arg7;
    evt.flag7 = flag7;
    evt.id = id;
    evt.tag = 0x87;
    evt.field_a = v.y >> 4;
    evt.unknown_10_ = v.z;
    evt.field8 = field8;
    func_0205e330(data, &evt, 0);
}
