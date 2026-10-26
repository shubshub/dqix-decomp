#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0202c1a4;
struct Struct_ov017_021d1118_8 { unsigned char unknown_0_[6]; };
struct Struct_ov017_021d15b0 {
    Struct_ov017_021d1118_8 unknown_0_;
    signed char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    signed char unknown_9_;
};
struct Struct_ov017_021d15b0_2 {
    Struct_ov017_021d1118_8 unknown_0_;
    char unknown_6_[0xc];
    unsigned short unknown_12_0_ : 14;
    unsigned short unknown_13_6_ : 1;
    unsigned short unknown_13_7_ : 1;
    unsigned char unknown_14_[24];
};
struct Struct_ov017_021d15b0_3 {
#if defined(jpn)
    char unknown_0_[0x6fc0];
#else
    char unknown1_0_[0x7200];
#endif
    Struct_ov017_021d15b0_2 unknown_7200_[16];
    Struct_ov017_021d15b0 unknown_74c0_[3];
};
#if defined(jpn)
struct Struct_ov017_021d15b0_4 { char unknown_0_[0x3964]; void* unknown_3b84_; };
#else
struct Struct_ov017_021d15b0_4 { char unknown_0_[0x3b84]; void* unknown_3b84_; };
#endif
struct Struct_ov017_021d1118 {
    char unknown_0_[4];
    unsigned char unknown_4_[14];
    unsigned char unknown_12_0_ : 2;
    unsigned char unknown_12_2_ : 2;
    unsigned char unknown_12_4_ : 4;
    unsigned char unknown_13_0_ : 2;
    unsigned char unknown_13_2_ : 4;
    unsigned char unknown_13_6_ : 1;
    unsigned char unknown_13_7_ : 1;
};
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_021a99dc(void*, void*, int, int, int);

// USA: func_ov017_021d15b0
extern "C" ARM void func_ov017_021d15b0(int sender, Packet* packet, PacketStore* store, PacketContext* context, SearchStruct0202c1a4* search) {
    void* handler = context->handler;
    int recipient = LinkSession_GetOwnSlot(search);
    if (!packet->segmented) {
        if (recipient == packet->recipient) func_ov017_021a99dc(handler, packet->payload, packet->type, packet->length, packet->final);
        return;
    }
    if (arg1->unknown_13_0_ == 2) {
        if (arg1->unknown_12_2_ != 1) return;
        Struct_ov017_021d15b0* var2 = arg2->unknown_74c0_;
        for (int var3 = 0; var3 < 3; var3++, var2++) {
            if (var2->unknown_6_ == arg0) return;
            if (var2->unknown_6_ < 0) {
                memcpy(var2, arg1->unknown_4_, arg1->unknown_13_2_);
                var2->unknown_6_ = arg0;
                return;
            }
        }
        return;
    }
    if (arg1->unknown_13_0_ != 0) return;
    if (arg1->unknown_12_2_ == 0 && var1 != arg1->unknown_12_0_) return;
    Struct_ov017_021d15b0* var4 = arg2->unknown_74c0_;
    for (int var5 = 0; var5 < 3; var5++, var4++) {
        if (var4->unknown_6_ != arg0) continue;
        if (var4->unknown_9_ < 0) {
            Struct_ov017_021d15b0_2* var6 = arg2->unknown_7200_;
            int var7;
            for (var7 = 0; var7 < 16; var7++, var6++) {
                if (var6->unknown_13_6_) {
                    Struct_ov017_021d1118_8 var8 = var4->unknown_0_;
                    int var9;
                    for (int var10 = 0; var10 < 6; var10++) {
                        if (var8.unknown_0_[var10] != var6->unknown_0_.unknown_0_[var10]) {
                            var9 = 0;
                            goto compared;
                        }
                    }
                    var9 = 1;
compared:
                    if (var9) {
                        var4->unknown_9_ = var7;
                        var4->unknown_7_ = 1;
                        break;
                    }
                }
            }
            if (var7 == 16) return;
        }
        Struct_ov017_021d15b0_2* var11 = &arg2->unknown_7200_[var4->unknown_9_];
        memcpy(var11->unknown_14_ + var4->unknown_8_, arg1->unknown_4_, arg1->unknown_13_2_);
        var4->unknown_8_ += arg1->unknown_13_2_;
        if (!arg1->unknown_13_6_) return;
        var4->unknown_7_ = 0;
        var4->unknown_8_ = 0;
        var4->unknown_9_ = -1;
        return;
    }
}
