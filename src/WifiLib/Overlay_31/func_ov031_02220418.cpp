#include <globaldefs.h>
struct Struct_ov031_02220418 { unsigned short value; };
struct Struct_ov031_02220418_2 { unsigned char header[8]; unsigned char records[1]; };
extern "C" Struct_ov031_02220418_2* func_ov031_022201d8(void*, unsigned int*, unsigned int*);
extern "C" Struct_ov031_02220418* func_ov031_02220248(unsigned char**, const void*, unsigned int*, unsigned int*);
// USA: func_ov031_02220418
extern "C" THUMB int func_ov031_02220418(void* packet, int* enabled) {
    unsigned int type, length, var2, recordLength;
    unsigned char* cursor;
    int first;
    int second;
    int var7;
    Struct_ov031_02220418_2* body = func_ov031_022201d8(packet, &type, &length);
    first = 0;
    cursor = (unsigned char*)body;
    second = 0;
    var7 = 0;
    if (!body) return first;
    if (type != 1) return first;
    unsigned char* end = (unsigned char*)body + length;
    cursor += sizeof(body->header);
    Struct_ov031_02220418* record;
    while ((record = func_ov031_02220248(&cursor, end, &var2, &recordLength)) != 0) {
        switch (var2) {
        case 1: {
            unsigned short value = record->value;
            first = (unsigned short)((unsigned char)(value >> 8) | ((value << 8) & 0xff00));
            break;
        }
        case 2: {
            unsigned short value = record->value;
            second = (unsigned short)((unsigned char)(value >> 8) | ((value << 8) & 0xff00));
            break;
        }
        case 5: {
            unsigned short value = record->value;
            var7 = (unsigned short)((unsigned char)(value >> 8) | ((value << 8) & 0xff00));
            break;
        }
        }
    }
    if (first != 1 || second != 1) return 0;
    if (var7 >= 1) *enabled = 1;
    else *enabled = 0;
    return 1;
}
