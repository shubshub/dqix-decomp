#include <globaldefs.h>
struct Struct_ov031_0220e7b0_2 { unsigned short type; unsigned short result; };
struct Struct_020d54d0 { unsigned short len; };
struct Struct_ov031_0220e7b0 {
    unsigned char unknown0[0x2140];
    Struct_020d54d0 header;
    unsigned char unknown_2142_[0x2170 - 0x2142];
    unsigned short unknown_2170_;
    unsigned char unknown_2172_[0x2260 - 0x2172];
    int state;
    unsigned int flags;
    unsigned char unknown_2268_[3];
    unsigned char pending;
    unsigned char unknown_226c_[0x2282 - 0x226c];
    unsigned short counter;
    unsigned char unknown_2284_[0x22f8 - 0x2284];
    unsigned short unknown_22f8_;
};
extern Struct_ov031_0220e7b0 *data_ov031_0224e53c;
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220d984(short, int, int, int);
extern "C" int func_020d54d0(int, Struct_020d54d0 *, const void *, int, unsigned short);
extern "C" int func_020d4f3c(int);
extern "C" void func_ov031_0220e258();
extern "C" void func_ov031_0220dc40();

// USA: func_ov031_0220e7b0
extern "C" ARM void func_ov031_0220e7b0(Struct_ov031_0220e7b0_2 *event) {
    if (event->result == 0) {
        int mode = 0;
        data_ov031_0224e53c->pending = 0;
        data_ov031_0224e53c->counter = 0;
        switch (data_ov031_0224e53c->state) {
        case 5:
        case 6:
            func_ov031_0220da1c(3);
            func_ov031_0220d984(1, 0, 0, 0x8f5);
            return;
        case 7:
            func_ov031_0220da1c(3);
            func_ov031_0220d984(0, 0, 0, 0x8fb);
            return;
        case 8: {
            unsigned short type = data_ov031_0224e53c->unknown_22f8_;
            data_ov031_0224e53c->unknown_22f8_ = 0;
            if (type == 0x12) {
                Struct_ov031_0220e7b0* context = data_ov031_0224e53c;
                if ((context->unknown_2170_ & 0x24) != 0x24) {
                    context->unknown_2170_ |= 0x24;
                    unsigned int flags = data_ov031_0224e53c->flags;
                    if ((flags & 0xc0000) == 0xc0000) mode = 1;
                    int status = func_020d54d0((int)func_ov031_0220e258, &data_ov031_0224e53c->header, 0,
                                             (flags & 0x30000) != 0x30000, mode);
                    if (status == 2) return;
                    if (status == 3) goto failCompletion;
                    if (status != 8) goto failCompletion;
                    func_ov031_0220da1c(12);
                    func_ov031_0220d984(1, (int)&data_ov031_0224e53c->header, type, 0x91c);
                    return;
                failCompletion:
                    func_ov031_0220da1c(11);
                    func_ov031_0220d984(7, (int)&data_ov031_0224e53c->header, type, 0x925);
                    return;
                }
            }
            func_ov031_0220da1c(3);
            func_ov031_0220d984(1, (int)&data_ov031_0224e53c->header, type, 0x92d);
            return;
        }
        case 9:
        case 12:
            func_ov031_0220da1c(3);
            func_ov031_0220d984(0, (int)&data_ov031_0224e53c->header, 1, 0x935);
            return;
        case 10:
            func_ov031_0220da1c(3);
            func_ov031_0220d984(0, (int)&data_ov031_0224e53c->header, 0, 0x93c);
            return;
        case 13: {
            int status = func_020d4f3c((int)func_ov031_0220dc40);
            if (status == 2) return;
            if (status == 3) goto failCommand;
            if (status != 8) goto failCommand;
            func_ov031_0220da1c(12);
            func_ov031_0220d984(1, 0, 0, 0x94a);
            return;
        failCommand:
            func_ov031_0220da1c(11);
            func_ov031_0220d984(7, 0, 0, 0x953);
            return;
        }
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 11:
        default:
            func_ov031_0220da1c(11);
            func_ov031_0220d984(7, 0, data_ov031_0224e53c->state, 0x959);
            return;
        }
    }
    func_ov031_0220da1c(11);
    func_ov031_0220d984(7, 0, 0, 0x960);
}
