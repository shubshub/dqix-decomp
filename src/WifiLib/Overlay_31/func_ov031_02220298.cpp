#include <globaldefs.h>

struct Struct_ov031_02220298 {
    unsigned short length;
    unsigned char unknown_2_[6];
};
extern "C" int func_ov031_02220248(unsigned char**, unsigned char*, void*, int);

// USA: func_ov031_02220298
extern "C" THUMB int func_ov031_02220298(Struct_ov031_02220298* packet, void* output, int count) {
    unsigned char* cursor = (unsigned char*)(packet + 1);
    unsigned short length = packet->length;
    unsigned short swapped = (unsigned char)(length >> 8) | ((length << 8) & 0xff00);
    return func_ov031_02220248(&cursor, cursor + swapped, output, count);
}
