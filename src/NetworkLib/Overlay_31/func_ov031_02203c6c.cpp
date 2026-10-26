#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Memory.h"

struct Struct_ov031_0224c980_12 {
    unsigned char padding0[0xc];
    int status;
    unsigned int flags;
    unsigned char unknown_14_[0x18];
    unsigned int unknown_2c_;
    unsigned char unknown_30_[0xc];
    void (*tick)();
    void (*unknown_40_)(void*);
    int unknown_44_;
    int (*connected)();
    unsigned char unknown_4c_[0xd0];
    int unknown_11c_;
    void* unknown_120_;
    unsigned char unknown_124_[4];
    int unknown_128_;
    void* unknown_12c_;
};
struct Struct_ov031_0224ca00_2 {
    int active;
    unsigned char padding4[6];
    unsigned short unknown_a_;
};
struct Struct_ov031_0224cca8_3 {
    int field0;
    unsigned short active;
    unsigned char unknown_6_[0x26];
    int unknown_2c_;
    int unknown_30_;
    void* allocation;
};
struct Struct_ov031_02203c6c {
    ProcessorContext* context;
    int pending;
    unsigned char state;
    unsigned char unknown_9_[7];
    int unknown_10_;
    int field14;
    unsigned short unknown_18_, unknown_1a_;
    unsigned int unknown_1c_, unknown_20_;
};
extern Struct_ov031_0224c980_12 data_ov031_0224c980;
extern unsigned char data_ov031_0224ca60[0x64];
extern unsigned char data_ov031_0224d02c[], data_ov031_0224ceac[];
extern Struct_ov031_0224ca00_2 data_ov031_0224ca00[8];
extern Struct_ov031_0224cca8_3 data_ov031_0224cca8[8];
extern "C" void func_ov031_02203164(int);
extern "C" void func_ov031_02203178();
extern "C" int func_ov031_02203bcc();
extern "C" int func_ov031_022046b8();
extern "C" int func_ov031_02204710(unsigned int*, int);
extern "C" int func_ov031_02200160(int);
extern "C" void func_ov031_02200ccc(unsigned int);
extern "C" void func_ov031_0220aa98(int);
extern "C" void func_ov031_0220480c();

// USA: func_ov031_02203c6c
extern "C" ARM void func_ov031_02203c6c() {
    int i;
    int stage;
    int var2;
    Struct_ov031_0224ca00_2* entry;
    int var4;
    int first;
    data_ov031_0224c980.unknown_44_ = 0;
    VectorizedMemset(data_ov031_0224ca60, 0, 0x64);
    data_ov031_0224c980.unknown_11c_ = 0x180;
    data_ov031_0224c980.unknown_120_ = data_ov031_0224d02c;
    data_ov031_0224c980.unknown_128_ = 0x180;
    data_ov031_0224c980.unknown_12c_ = data_ov031_0224ceac;
    func_ov031_02203164((int)data_ov031_0224ca60);
    var4 = 1;
    first = 1;
    unsigned int var6 = 1;
    data_ov031_0224c980.status = 1;
    stage = 0;
    while (1) {
        SleepCurrentContext(1000);
        if (data_ov031_0224c980.unknown_44_) break;
        var2 = (int)(GetCurrentTimestamp() >> 16);
        if (data_ov031_0224c980.connected()) {
            if (--var6 == 0) {
                if (data_ov031_0224c980.flags & 1) {
                    if (stage == 0) {
                        func_ov031_02203bcc();
                        stage = 1;
                    }
                } else {
                    switch (stage) {
                    case 0:
                        if (first) {
                            data_ov031_0224c980.status = 2;
                            first = 0;
                        }
                        if (!func_ov031_022046b8() || func_ov031_02204710(&var6, 0) == 0) {
                            func_ov031_02203bcc();
                            stage = 3;
                        } else {
                            stage = 1;
                        }
                        break;
                    case 1:
                        if (func_ov031_02204710(&var6, 1) == 0 && var6 < 60) stage = 2;
                        break;
                    case 2:
                        if (func_ov031_02204710(&var6, 2)) stage = 1;
                        else if (var6 < 60) {
                            func_ov031_02200160(3);
                            var4 = 1;
                            var6 = 1;
                            stage = 0;
                        }
                        break;
                    case 3:
                        break;
                    }
                }
            }
        } else {
            func_ov031_02200160(1);
            var4 = 1;
            var6 = 1;
            stage = 0;
        }
        entry = data_ov031_0224ca00;
        i = 0;
        do {
            if (entry->active && (short)(var2 - entry->unknown_a_) > 957) entry->active = 0;
            entry++;
        } while (++i < 8);
        if (data_ov031_0224c980.unknown_2c_ && --var4 == 0) {
            func_ov031_02200ccc(data_ov031_0224c980.unknown_2c_);
            var4 = 105;
        }
        ProcessorContext* context = data_02111304.firstContext;
        if (context) do {
            Struct_ov031_02203c6c* var8 = (Struct_ov031_02203c6c*)context->unknown_A4;
            if (var8 && var8->context) {
                int state = var8->state;
                if (state == 3 && var2 - var8->unknown_10_ > 39) {
                    var8->state = 1;
                    var8->unknown_18_ = var8->unknown_1a_;
                    var8->unknown_1c_ = var8->unknown_20_;
                } else if (state == 2 && var2 - var8->unknown_10_ > 39) {
                    if (var8->pending == 1) {
                        var8->state = 0;
                        var8->pending = 0;
                        MarkContextReadyAndSwitch(var8->context);
                    }
                } else if (state != 4 && var8->pending == 2) {
                    var8->pending = 0;
                    MarkContextReadyAndSwitch(var8->context);
                }
            }
            context = context->pNext;
        } while (context);
        Struct_ov031_0224cca8_3* allocation = data_ov031_0224cca8;
        int var11 = 0;
        do {
            if (allocation->active && var2 - allocation->unknown_2c_ > 239) {
                data_ov031_0224c980.unknown_40_(allocation->allocation);
                allocation->active = 0;
            }
            allocation++;
        } while (++var11 < 8);
        func_ov031_0220aa98(var2);
        if (data_ov031_0224c980.tick) data_ov031_0224c980.tick();
    }
    if (!(data_ov031_0224c980.flags & 1) && stage != 3) func_ov031_0220480c();
    func_ov031_02203178();
}
