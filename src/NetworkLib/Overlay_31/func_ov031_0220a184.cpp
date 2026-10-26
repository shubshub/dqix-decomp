#include <globaldefs.h>
#include <NitroSDK/Memory.h>

struct Struct_ov031_0220a184_2 {
    unsigned char state;
    unsigned char field_0x1;
    unsigned char record[0x2e];
    unsigned char unknown_30_[0x425];
    unsigned char status;
    unsigned char unknown_456_[0x3e];
    unsigned char unknown_494_[0x100];
    int unknown_594_;
    unsigned char unknown_598_[8];
    int unknown_5a0_;
    unsigned char unknown_5a4_[8];
    unsigned char unknown_5ac_;
};

struct Struct_ov031_0220a184 {
    unsigned char field_0x0[0xc];
    Struct_ov031_0220a184_2* unknown_c_;
};

extern "C" void func_ov031_022037a8(const void*, int, int, int, Struct_ov031_0220a184*);
extern "C" void func_ov031_02209cf8(void*, int);
extern "C" void func_ov031_0220c8d0(unsigned short*, unsigned char*, int, int);
extern "C" unsigned int func_ov031_02207cf0();
extern "C" void func_ov031_0220c2bc(unsigned short*, unsigned short*, unsigned short*, int, unsigned short*);
extern "C" void func_ov031_02207d3c(unsigned int);
extern "C" void func_ov031_022098ac(void*, int, int);
extern unsigned char data_ov031_02245fa8[8];
extern void* (*data_ov031_0224c994)(unsigned int);
extern int (*data_ov031_0224c9c0)(void*);

// USA: func_ov031_0220a184
extern "C" ARM int func_ov031_0220a184(Struct_ov031_0220a184* arg0) {
    Struct_ov031_0220a184_2* var0 = arg0->unknown_c_;
    unsigned short* var1;
    unsigned short* var2;
    int words;
    unsigned char* padding;
    int length;
    if (var0->unknown_5ac_)
        func_ov031_022037a8(data_ov031_02245fa8, 7, 0, 0, arg0);
    var0->state = 3;
    var0->field_0x1 = 0;
    func_ov031_02209cf8(var0->record, 0x2e);
    length = var0->unknown_594_;
    words = (length * 2) / 2;
    padding = (unsigned char*)data_ov031_0224c994(length);
    if (padding == 0) {
        var0->status = 9;
        return 9;
    }
    padding[0] = 0;
    padding[1] = 2;
    func_ov031_02209cf8(padding + 2, length - 0x33);
    padding[length - 0x31] = 0;
    VectorizedInvertedMemcpy(var0, padding + length - 0x30, 0x30);
    var1 = (unsigned short*)data_ov031_0224c994(words * 8);
    if (var1 == 0) {
        data_ov031_0224c9c0(padding);
        var0->status = 9;
        return 9;
    }
    unsigned short* message = var1 + words;
    unsigned short* var7 = message + words;
    var2 = var7 + words;
    func_ov031_0220c8d0(message, padding, length, words);
    func_ov031_0220c8d0(var7, var0->unknown_598_, var0->unknown_5a0_, words);
    func_ov031_0220c8d0(var2, var0->unknown_494_, length, words);
    unsigned int priority = func_ov031_02207cf0();
    func_ov031_0220c2bc(var1, message, var7, words, var2);
    func_ov031_02207d3c(priority);
    unsigned char* packet = (unsigned char*)data_ov031_0224c994(length + 0x49);
    if (packet == 0) {
        data_ov031_0224c9c0(padding);
        data_ov031_0224c9c0(var1);
        var0->status = 9;
        return 9;
    }
    packet[0] = 0x16;
    packet[1] = 3;
    packet[2] = 0;
    packet[3] = (length + 4) >> 8;
    packet[4] = length + 4;
    packet[5] = 0x10;
    packet[6] = length >> 16;
    packet[7] = length >> 8;
    packet[8] = length;
    unsigned char* cursor = packet + 9;
    if (length & 1)
        *cursor++ = var1[length / 2];
    int index = length / 2 - 1;
    if (index >= 0) {
        do {
            *cursor = var1[index] >> 8;
            cursor[1] = var1[index];
            --index;
            cursor += 2;
        } while (index >= 0);
    }
    func_ov031_022037a8(packet, length + 9, 0, 0, arg0);
    func_ov031_022098ac(var0, (int)(packet + 5), length + 4);
    data_ov031_0224c9c0(packet);
    data_ov031_0224c9c0(var1);
    return data_ov031_0224c9c0(padding);
}
