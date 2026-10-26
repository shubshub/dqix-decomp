#include <globaldefs.h>

struct Struct_ov031_0224f9c4 {
    unsigned int words[8];
};
struct Struct_ov031_0224fac0 {
    char text[0x40];
    int length;
    int unknown_44_;
};
struct Struct_ov031_0224f9f0 {
    int type;
    int unknown_4_;
    unsigned char unknown_8_[0x28];
    int unknown_30_;
    int unknown_34_;
};
extern unsigned char data_ov031_0224f8c4[];
extern Struct_ov031_0224f9c4 data_ov031_0224f9c4;
extern Struct_ov031_0224f9f0 data_ov031_0224f9f0;
extern char data_ov031_0224fa28[4][0x28];
extern Struct_ov031_0224fac0 data_ov031_0224fac0;
extern "C" unsigned char* func_ov031_02220248(unsigned char** cursor, unsigned char* end, int* arg2, int* arg3);
extern "C" void* memcpy(void* destination, const void* source, unsigned int size);
extern "C" void* memset(void* destination, int value, unsigned int size);
extern "C" int func_ov031_022228c0(char* output, int input);

#define SWAP16(v) ((unsigned short)((unsigned char)((v) >> 8) | (((v) << 8) & 0xff00)))

// USA: func_ov031_022206e0
extern "C" THUMB int func_ov031_022206e0(unsigned char* message) {
    unsigned short* header;
    int result;
    unsigned int total;
    unsigned char* cursor;
    int type;
    int len;
    unsigned char* data;
    header = (unsigned short*)message;
    message += 8;
    cursor = message;
    result = 0;
    total = SWAP16(*header);
    data = func_ov031_02220248(&cursor, message + total, &type, &len);
    if (data != 0) {
        do {
            switch (type) {
            case 0x201:
                __builtin__clear(&data_ov031_0224f9c4, sizeof(data_ov031_0224f9c4));
                memcpy(&data_ov031_0224f9c4, data, len);
                result = 1;
                break;
            case 0x202:
                data_ov031_0224f9f0.type = SWAP16(*(unsigned short*)data);
                break;
            case 0x203: {
                int i = 0;
                unsigned char* entry = data_ov031_0224f8c4;
                unsigned int format = SWAP16(*(unsigned short*)data);
                do {
                    *(unsigned int*)(entry + 0x15c) = format;
                    i++;
                    entry += 0x28;
                } while (i < 4);
                break;
            }
            case 0x204: {
                unsigned char* entry = data_ov031_0224f8c4;
                int i = 0;
                unsigned int length = SWAP16(*(unsigned short*)data);
                do {
                    *(unsigned int*)(entry + 0x160) = length;
                    i++;
                    entry += 0x28;
                } while (i < 4);
                break;
            }
            case 0x205:
                data_ov031_0224f9f0.unknown_4_ = SWAP16(*(unsigned short*)data);
                break;
            case 0x206:
            case 0x207:
            case 0x208:
            case 0x209:
                memset(data_ov031_0224fa28[type - 0x206], 0, 0x20);
                if (data_ov031_0224f9f0.unknown_30_ == 1) {
                    char* out = data_ov031_0224fa28[type - 0x206];
                    int i = 0;
                    if (i < len) {
                        do {
                            out += func_ov031_022228c0(out, *(char*)data++);
                            i++;
                        } while (i < len);
                    }
                } else {
                    memcpy(data_ov031_0224fa28[type - 0x206], data, len);
                }
                break;
            case 0x20a:
                __builtin__clear(&data_ov031_0224fac0, sizeof(data_ov031_0224fac0));
                memcpy(&data_ov031_0224fac0, data, len);
                break;
            }
            data = func_ov031_02220248(&cursor, message + total, &type, &len);
        } while (data != 0);
    }
    return result;
}
