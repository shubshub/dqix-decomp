#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "NitroSDK/Memory.h"

struct Struct_02001aec {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned long unknown_4_;
    unsigned short unknown_8_;
    unsigned char unknown_a_;
    union {
        unsigned char unknown_b_;
        unsigned char unknown1_b_;
    };
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    union {
        unsigned short unknown_10_[56];
        struct {
            unsigned short unknown_0_[5];
            unsigned short unknown_a_[7];
            unsigned short unknown_18_[44];
        } unknown1_10_;
    };
};
struct Struct_ov031_0223778c_4 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned char unknown_4_[6];
    unsigned short unknown_a_;
    unsigned char unknown_c_[32];
    unsigned short unknown_2c_;
    struct {
        unsigned short unknown_0_;
        unsigned short unknown_2_;
    } unknown_2e_;
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    Struct_02001aec unknown_40_;
};
struct Struct_ov031_0223778c {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned char unknown_c_[2];
    unsigned short unknown_e_;
    Struct_ov031_0223778c_4* unknown_10_[16];
    unsigned short unknown_50_[16];
};

struct Struct_ov031_0223778c_2 { unsigned char unknown_0_[6]; unsigned char unknown_6_; };
struct Struct_ov031_0223778c_3 { unsigned char unknown_0_[0x1300]; Struct_ov031_0223778c_2 unknown_1300_[16]; void (*unknown_1370_)(int); };
extern Struct_ov031_0223778c_3* data_ov031_02290d0c;
extern unsigned char data_ov031_02249288[8];
extern unsigned char data_ov031_02249280[6];
extern "C" int memcmp(const void*, const void*, unsigned int);

// USA: func_ov031_0223778c
extern "C" ARM void func_ov031_0223778c(Struct_ov031_0223778c* arg0) {
    Struct_ov031_0223778c_4* var0;
    int var1;
    var1 = 0;
    if ((int)arg0->unknown_e_ <= 0) return;
    do {
        peer = list->bssDesc[peerIndex];
        InvalidateDataCacheRange(peer, 0xc0);
        if (memcmp(peer->ssid, data_ov031_02249288, 8) == 0) {
            int existingIndex = 0;
            PeerSlot3778c* existingSlot;
            PeerSlot3778c* emptySlot;
            PeerState3778c* const state = data_ov031_02290d0c;
            existingSlot = state->slots;
            do {
                if (memcmp(peer->bssid, existingSlot->name, 6) == 0) {
                    if (state->slots[existingIndex].active == 0 && (peer->ssid[9] & 1) != 0) {
                        if (state->notify) state->notify(1);
                        return;
                    }
                    goto nextPeer;
                }
                ++var2;
                ++var3;
            } while (var2 < 16);
            var4 = var5->unknown_1300_;
            int var6 = 0;
            do {
                if (memcmp(emptySlot->name, data_ov031_02249280, 6) == 0) {
                    VectorizedInvertedMemcpy(peer->bssid, state->slots[emptyIndex].name, 6);
                    data_ov031_02290d0c->slots[emptyIndex].active = (peer->ssid[9] & 1) != 0;
                    break;
                }
                ++var6;
                ++var4;
            } while (var6 < 16);
        }
    nextPeer:
        ++var1;
    } while (var1 < arg0->unknown_e_);
}
