#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Timing.h"
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Mutex.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_ov031_022075a4;
struct Struct_ov031_02207230 {
    unsigned char kind;
    unsigned char unknown_1_;
    unsigned short length;
    unsigned char data[4];
};
struct Struct_ov031_02244e44_5 { unsigned long long ticks; };
struct Struct_02245528 {
    unsigned char unknown_0_[0x2d];
    signed char unknown_2d_;
    unsigned char repeat;
    unsigned char unknown_2f_[6];
    unsigned char phase;
    unsigned char unknown_36_[0x390 - 0x36];
    unsigned char result;
    unsigned char done;
    unsigned char unknown_392_[0x16];
    Struct_ov031_02244e44_5 unknown_3a8_;
    unsigned char unknown_3b0_[8];
    Struct_ov031_02244e44_5 started;
    Struct_ov031_02244e44_5 unknown_3c0_;
    Struct_ov031_02244e44_5 unknown_3c8_;
    unsigned char unknown_3d0_[0x5c];
    Struct_ov031_022075a4* handle;
};
struct Struct_ov031_02244e44 {
    unsigned char unknown_0_[2];
    unsigned char present;
    unsigned char unknown_3_;
    unsigned char address[6];
    signed short unknown_a_;
    void** data;
};
struct Struct_ov031_02291e04_4 {
    unsigned char unknown_0_[2];
    unsigned char present;
    unsigned char unknown_3_[5];
    unsigned short unknown_8_;
#if defined(jpn)
    unsigned char unknown_a_[6];
    Struct_ov031_022075a4* unknown_34_;
    unsigned char unknown_14_[4];
    Struct_ov031_02244e44* peer;
#else
    unsigned char unknown1_a_[0xe];
    Struct_ov031_02244e44* peer;
    unsigned char unknown_1c_[0x18];
    Struct_ov031_022075a4* unknown_34_;
#endif
};
struct Struct_ov031_02244e44_2 {
    unsigned char address[6];
    unsigned char status;
    unsigned char unknown_7_;
};
struct Struct_ov031_02244e44_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x7cdc];
#else
    unsigned char unknown1_0_[0x7fb0];
#endif
    Struct_ov031_02244e44_2 unknown_7fb0_[8];
    Struct_ov031_02244e44_2* inline_ov031_02244e44() { return unknown_7fb0_; }
};
struct Struct_ov031_02249594 { int unknown_0_; int unknown_4_; };
struct Struct_ov031_02244e44_4 { unsigned char bytes[0x14]; };
extern Struct_ov031_02249594 data_ov031_02249594[4];
extern int data_ov031_0224c8a4;
extern Mutex data_ov031_02291e50;
extern Struct_ov031_02291e04_4 data_ov031_02291e04;
extern "C" Struct_ov031_022075a4* func_ov031_022071d8(int, int, int);
extern "C" int func_ov031_022075a4(Struct_ov031_022075a4*, int, int);
extern "C" Struct_ov031_02244e44* func_ov031_02207440(Struct_ov031_022075a4*);
extern "C" int func_ov031_02207230(void*, Struct_ov031_02207230*);
extern "C" int func_ov031_0220783c(int*, int, int, int);
extern "C" int func_ov031_0220728c(int, int, int);
extern "C" int memcmp(const void*, const void*, int);
extern "C" int func_ov031_02245750(Struct_02245528*, Struct_ov031_02244e44_4*);
extern "C" int func_ov031_02207434(Struct_ov031_022075a4*);
extern "C" void func_ov031_022077c0();
extern "C" void func_ov031_02245938();
extern "C" int func_ov031_0220d540();
extern "C" void func_ov031_02245528(Struct_02245528*, int);

// USA: func_ov031_02244e44
extern "C" ARM void func_ov031_02244e44(Struct_02245528* session) {
    switch (session->phase) {
    case 0:
        session->handle = func_ov031_022071d8(2, 1, 0);
        if ((int)session->handle < 0) { session->phase = 5; break; }
        func_ov031_022075a4(session->handle, 4, func_ov031_022075a4(session->handle, 3, 0) & ~4);
        session->phase = 1;
        session->unknown_2d_ = -1;
        session->repeat = 0;
    case 2: {
        int var0 = session->unknown_2d_;
        if (var0 >= 0 || session->repeat) {
            if (var0 < 0) var0 = 0;
            else if (var0 >= 4) var0 = 3;
            signed char index = var0;
            int wait = session->repeat ? 0 : data_ov031_02249594[index].unknown_0_;
            unsigned long long now = GetCurrentTimestamp();
            unsigned long long previous = session->unknown_3c8_.ticks;
            if (((now - previous) << 6) / 0x82ea >= (unsigned long long)wait || now < previous) {
                session->phase = 1;
                if (session->repeat) session->repeat = 0;
                else {
                    session->unknown_2d_++;
                    session->unknown_3c0_.ticks = GetCurrentTimestamp();
                }
            } else {
                SleepCurrentContext(5);
                break;
            }
        } else {
            session->phase = 1;
            session->unknown_2d_ = 0;
            session->repeat = 0;
            session->started.ticks = GetCurrentTimestamp();
            session->unknown_3c0_ = session->started;
        }
    }
    case 1: {
        if (data_ov031_0224c8a4) {
            ZeroInitializeMutex(&data_ov031_02291e50);
            data_ov031_0224c8a4 = 0;
        }
        LockMutex(&data_ov031_02291e50);
        Struct_ov031_02244e44* info = func_ov031_02207440(data_ov031_02291e04.unknown_34_);
        UnlockMutex(&data_ov031_02291e50);
        if (!info) { session->phase = 5; break; }
        Struct_ov031_02207230 packet;
        memset(&packet, 0, 8);
        unsigned short length = data_ov031_02291e04.unknown_8_;
        packet.kind = 8;
        packet.unknown_1_ = 2;
        packet.length = ((length >> 8) & 0xff) | ((length << 8) & 0xff00);
        VectorizedInvertedMemcpy(*info->data, packet.data, info->unknown_a_);
        GetCurrentTimestamp();
        func_ov031_022075a4(session->handle, 4, func_ov031_022075a4(session->handle, 3, 0) | 4);
        int status = func_ov031_02207230(session->handle, &packet);
        if (status == -26) {
            unsigned long long elapsed = ((GetCurrentTimestamp() - session->unknown_3c0_.ticks) << 6) / 0x82ea;
            if (elapsed >= 0x3a98) status = -76;
        }
        if (status == -26) {
            session->unknown_3c8_.ticks = GetCurrentTimestamp();
            session->repeat = 1;
            session->phase = 2;
            SleepCurrentContext(5);
            break;
        }
        if (status >= 0 || status == -30) {
            session->phase = 4;
            break;
        }
        if (status != -76) goto Failed;
        session->unknown_2d_ = 5;
        session->repeat = 0;
        unsigned long long elapsed = ((GetCurrentTimestamp() - session->started.ticks) << 6) / 0x82ea;
        if (elapsed >= 0xafc8) {
            session->unknown_2d_ = 5;
            session->repeat = 0;
        }
        if (session->unknown_2d_ < 5) {
            session->unknown_3c8_.ticks = GetCurrentTimestamp();
            session->phase = 2;
            SleepCurrentContext(5);
        } else {
        Failed:
            session->phase = 5;
        }
        break;
    }
    case 4: {
        GetCurrentTimestamp();
        func_ov031_022075a4(session->handle, 4, func_ov031_022075a4(session->handle, 3, 0) | 4);
        int descriptor[2];
        if (func_ov031_0220783c(descriptor, 1, 0x7fd88, 0) > 0) {
            Struct_ov031_02244e44_4 var12;
            memset(&var12, 0, 0x14);
            if (func_ov031_0220728c((int)session->handle, (int)&var12, 0x14) < 0) {
                GetCurrentTimestamp();
                if (data_ov031_02291e04.peer) {
                    Struct_ov031_02244e44_2* peer = ((Struct_ov031_02244e44_3*)GameState::GetInstance())->inline_ov031_02244e44();
                    for (int index = 0; index < 8; index++, peer++) {
                        if (!memcmp(peer, data_ov031_02291e04.peer->address, 6)) {
                            if (!data_ov031_02291e04.present) peer->status = 0xff;
                            else memset(peer, 0, 8);
                            break;
                        }
                    }
                }
                session->phase = 5;
            } else {
                GetCurrentTimestamp();
                Struct_ov031_02244e44_4 copy;
                memcpy(&copy, &var12, 0x14);
                session->result = func_ov031_02245750(session, &copy);
                session->phase = 5;
            }
        } else {
            session->phase = 5;
            func_ov031_022075a4(session->handle, 4, func_ov031_022075a4(session->handle, 3, 0) & ~4);
        }
        break;
    }
    case 5:
        GetCurrentTimestamp();
        func_ov031_022075a4(session->handle, 4, func_ov031_022075a4(session->handle, 3, 0) | 4);
        func_ov031_022075a4(session->handle, 4, func_ov031_022075a4(session->handle, 3, 0) | 4);
        if (func_ov031_02207434(session->handle) == 0) {
            SleepCurrentContext(1);
            for (int index = 0; index < 0x7530; index++) {
                if (func_ov031_02207434(session->handle) != -26) break;
                SleepCurrentContext(1);
            }
        }
        session->handle = (Struct_ov031_022075a4*)-1;
        func_ov031_022077c0();
        func_ov031_02245938();
        session->unknown_3a8_.ticks = GetCurrentTimestamp() + 0xefb5f7;
        session->phase = 6;
        break;
    case 6:
        if (!func_ov031_0220d540()) {
            GetCurrentTimestamp();
            func_ov031_02245528(session, 0);
            session->done = 1;
        }
        break;
    }
}
