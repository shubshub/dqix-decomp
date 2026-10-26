#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Timing.h"

struct Struct_ov031_022048a8_3 {
    unsigned short unknown_0_, flags, unknown_4_, unknown_6_, unknown_8_, unknown_a_;
    unsigned char data[48];
};
struct Struct_ov031_022048a8 {
    unsigned short unknown_0_;
    unsigned char flags, status;
    unsigned char unknown_4_[2];
    unsigned char counts[6];
};
struct Struct_ov031_022048a8_2 {
    unsigned char type[2], unknown_2_[2];
    unsigned char unknown_4_[4];
    unsigned char length[2];
};
struct Struct_ov031_0224c980_18 { unsigned char unknown0[0x48]; int (*cancelled)(); };
extern Struct_ov031_0224c980_18 data_ov031_0224c980;
extern "C" void func_ov031_02203a84(void*, int);
extern "C" int func_ov031_02203b1c();
extern "C" void func_ov031_02200264();
extern "C" Struct_ov031_022048a8* func_ov031_0220357c(unsigned int*);
extern "C" void func_ov031_02203670(unsigned int);
extern "C" char* func_ov031_02204878(char*);

#define CPS_GETUSHORT1(p) ((unsigned short)(((unsigned char*)(p))[0] << 8 | ((unsigned char*)(p))[1]))
#define CPS_GETULONG1(p) (((unsigned long)CPS_GETUSHORT1(p) << 16) | CPS_GETUSHORT1((p) + 2))

// USA: func_ov031_022048a8
extern "C" ARM int func_ov031_022048a8(const unsigned char* name, unsigned int type, int arg2, void* output, unsigned int capacity) {
    Struct_ov031_022048a8_3 packet;
    unsigned int length;
    packet.unknown_0_ = (arg2 >> 8) | (arg2 << 8);
    if (type != 32) packet.flags = 1;
    else packet.flags = 0x1001;
    packet.unknown_4_ = 0x100;
    packet.unknown_6_ = 0;
    packet.unknown_8_ = 0;
    packet.unknown_a_ = 0;
    length = 0;
    unsigned char character = *name++;
    unsigned char* label = packet.data;
    unsigned char* cursor = label + 1;
    int count = 0;
    if (character) do {
        if (character != '.') {
            count = cursor - (unsigned char*)&packet;
            if (count >= 60) return -1;
            count = ++length;
            *cursor++ = character;
        } else {
            *label = count;
            label = cursor;
            length = 0;
            count = 0;
            ++cursor;
        }
        character = *name++;
    } while (character);
    *label = length;
    cursor[0] = 0;
    cursor[1] = type >> 8;
    cursor[2] = type;
    cursor[3] = 0;
    cursor[4] = 1;
    func_ov031_02203a84(&packet, cursor + 5 - (unsigned char*)&packet);
    int result = 0;
    unsigned int start = GetCurrentTimestamp() >> 16;
    while (data_ov031_0224c980.cancelled() && !result &&
           (int)((unsigned int)(GetCurrentTimestamp() >> 16) - start) < 15) {
        if (!func_ov031_02203b1c()) func_ov031_02200264();
        else {
            Struct_ov031_022048a8* response = func_ov031_0220357c(&length);
            if (length > 12 && arg2 == (unsigned short)((response->unknown_0_ >> 8) | (response->unknown_0_ << 8))) {
                int status = response->status & 15;
                if (status == 3) result = -1;
                else if (status == 0) {
                    unsigned char* end = (unsigned char*)response + length;
                    char* position = (char*)(response + 1);
                    int remaining = (unsigned short)(response->unknown_4_[1] | (response->unknown_4_[0] << 8));
                    while (remaining--) {
                        position = func_ov031_02204878(position) + 4;
                    }
                    if ((unsigned char*)position < end) do {
                        Struct_ov031_022048a8_2* record = (Struct_ov031_022048a8_2*)func_ov031_02204878(position);
                        unsigned short var14 = CPS_GETUSHORT1(record->length);
                        if (type == CPS_GETUSHORT1(record->type)) {
                            if (type != 12) {
                                result = CPS_GETULONG1((unsigned char*)record + sizeof(*record) - 4 + var14);
                            } else if (var14 > capacity) result = 2;
                            else {
                                VectorizedInvertedMemcpy(record + 1, output, var14);
                                result = 1;
                            }
                            break;
                        }
                        position = (char*)record + (sizeof(*record) + var14);
                    } while ((unsigned char*)position < end);
                }
            }
            func_ov031_02203670(length);
        }
    }
    return result;
}
