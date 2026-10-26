#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"

struct Struct_ov031_02202b78 {
    unsigned char header;
    unsigned char unknown_1_;
    unsigned short length;
    unsigned short unknown_4_;
    unsigned short fragment;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
};
struct Struct_ov031_0224cca8_2 {
    unsigned long source;
    unsigned short count;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_[8];
    unsigned short unknown_1c_[8];
    unsigned long unknown_2c_;
    unsigned char* payload;
    unsigned char* allocation;
};
struct ProcessorContext;
struct Struct_ov031_0224c980_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned char unknown_a_[2];
    int status;
    unsigned long unknown_10_;
    void* (*unknown_14_)(unsigned long);
    void (*unknown_18_)();
    unsigned long unknown_1c_;
    unsigned long unknown_20_;
    unsigned long unknown_24_;
    unsigned long unknown_28_;
    unsigned long unknown_2c_;
    unsigned long unknown_30_;
    unsigned long unknown_34_;
    unsigned long unknown_38_;
    void (*unknown_3c_)();
    void (*unknown_40_)(void*);
    unsigned long unknown_44_;
    int (*unknown_48_)();
    unsigned long unknown_4c_;
    unsigned long unknown_50_;
    ProcessorContext* unknown_54_;
    unsigned char* unknown_58_;
    unsigned long unknown_5c_;
    unsigned long unknown_60_[2];
    unsigned long long unknown_68_;
    unsigned long long unknown_70_;
    unsigned long long unknown_78_;
};
extern Struct_ov031_0224cca8_2 data_ov031_0224cca8[8];
extern const Struct_ov031_0224c980_3 data_ov031_0224c980[];

static inline unsigned short inline_ov031_02202b78(unsigned short value) {
    return (value >> 8) | (value << 8);
}

// USA: func_ov031_02202b78
extern "C" ARM Struct_ov031_02202b78* func_ov031_02202b78(Struct_ov031_02202b78* packet, int* arg1) {
    unsigned short var0;
    unsigned long headerLength;
    Struct_ov031_0224cca8_2* available = NULL;
    Struct_ov031_0224cca8_2* var3;
    unsigned long offset;
    unsigned long flags, var6, end, source, var9, index;
    unsigned long count;
    unsigned long total;
    unsigned long var13;
    unsigned long var14;
    *arg1 = 0;
    flags = inline_ov031_02202b78(packet->fragment);
    if (!(flags & 0x3fff)) return packet;
    var0 = packet->header;
    unsigned short var15 = packet->unknown_e_;
    unsigned short var16 = packet->unknown_c_;
    headerLength = (var0 & 15) * 4;
    source = ((unsigned long)inline_ov031_02202b78(var16) << 16) | inline_ov031_02202b78(var15);
    var0 = packet->unknown_4_;
    index = 0;
    var3 = data_ov031_0224cca8;
    do {
        if (var3->count && var3->source == source && var3->unknown_6_ == var0) break;
        ++index;
        if (!var3->count && !available) available = var3;
        ++var3;
    } while (index < 8);
    var6 = inline_ov031_02202b78(packet->length) - headerLength;
    offset = flags & 0x1fff;
    end = var6 + (offset << 3);
    if (index == 8) {
        if (!available || end > 4096) return NULL;
        var3 = available;
        var3->allocation = static_cast<unsigned char*>(data_ov031_0224c980[0].unknown_14_(headerLength + 14 + 4096));
        if (!var3->allocation) return NULL;
        var3->source = source;
        var3->unknown_6_ = var0;
        var3->unknown_8_ = 0;
        var3->unknown_2c_ = GetCurrentTimestamp() >> 16;
        var3->payload = var3->allocation + 14 + headerLength;
        VectorizedInvertedMemcpy(packet, var3->allocation + 14, headerLength);
    }
    if (var3->count == 8 || end > 4096) {
        var3->count = 0;
        data_ov031_0224c980[0].unknown_40_(var3->allocation);
        return NULL;
    }
    var9 = offset + ((var6 + 7) >> 3);
    if (!(flags & 0x2000)) {
        var3->unknown_a_ = end;
        var3->unknown_8_ = var9;
    }
    var3->unknown_c_[var3->count] = offset;
    var3->unknown_1c_[var3->count] = var9;
    var3->count++;
    VectorizedInvertedMemcpy((unsigned char*)packet + headerLength, var3->payload + (offset << 3), var6);
    total = var3->unknown_8_;
    if (!total) return NULL;
    count = var3->count;
    var14 = 0;
    var13 = 0;
    if (var13 < count) do {
        if (var3->unknown_c_[var13] <= var14 && var14 < var3->unknown_1c_[var13]) {
            var14 = var3->unknown_1c_[var13];
            var13 = 0;
        } else {
            var13++;
        }
    } while (var13 < count);
    if (var14 < total) return NULL;
    unsigned char* allocation = var3->allocation;
    Struct_ov031_02202b78* result = (Struct_ov031_02202b78*)(allocation + 14);
    unsigned short length = var3->unknown_a_ + ((result->header & 15) * 4);
    result->length = (length >> 8) | (length << 8);
    var3->count = 0;
    *arg1 = 1;
    return result;
}
