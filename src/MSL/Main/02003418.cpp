#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_02003418 {
    unsigned char alignment;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char alternate;
    unsigned char length;
    unsigned char unknown_5_;
    unsigned char field6[2];
    int width;
    int unknown_c_;
};
typedef char* Type_02003418;
typedef __typeof__((char*)0 - (char*)0) Type_02003418_2;
#define FORMAT_FOURBYTE_ALIGN02003418(n) (((unsigned long)(n) + 3U) & ~3U)
#define FORMAT_ARGUMENT02003418(ap, type) (*(type*)((ap += FORMAT_FOURBYTE_ALIGN02003418(sizeof(type))) - FORMAT_FOURBYTE_ALIGN02003418(sizeof(type))))
typedef int (*Type_02003418_3)(void*, const char*, unsigned int);
extern "C" const char* func_02001bdc(const char*, Type_02003418*, Struct_02003418*);
extern "C" char* func_0200216c(int, char*, Struct_02003418);
extern "C" char* func_020023b8(long long, char*, Struct_02003418);
extern "C" char* func_02002cb4(double, char*, Struct_02003418);
extern "C" char* func_020026b4(double, char*, Struct_02003418);
extern "C" int func_020019c8(char*, const unsigned short*, unsigned int);
extern "C" char* func_02001ac0(const char*, int, unsigned int);
extern const unsigned short data_020eef28[];
extern const char data_020eef2c[];

// USA: func_02003418
extern "C" ARM int func_02003418(Type_02003418_3 arg0, void* state, const char* format, Type_02003418 args) {
    char padding[1];
    char var1;
    Struct_02003418 var2;
    char buffer[512];
    long long var4;
    const char* var5;
    const char* text;
    int width;
    int value;
    int length;
    int total = 0;
    padding[0] = ' ';
    if (*format) do {
        var5 = strchr(format, '%');
        if (var5 == 0) {
            unsigned int tail = strlen(format);
            total += tail;
            if (tail && !arg0(state, format, tail)) return -1;
            break;
        }
        unsigned int var12 = var5 - format;
        total += var12;
        if (var12 && !arg0(state, format, var12)) return -1;
        format = func_02001bdc(var5, &args, &var2);
        switch (var2.unknown_5_) {
        case 'd': case 'i':
            if (var2.length == 3) value = FORMAT_ARGUMENT02003418(args, long);
            else if (var2.length == 4) var4 = FORMAT_ARGUMENT02003418(args, long long);
            else if (var2.length == 6) var4 = FORMAT_ARGUMENT02003418(args, long long);
            else if (var2.length == 7) value = FORMAT_ARGUMENT02003418(args, size_t);
            else if (var2.length == 8) value = FORMAT_ARGUMENT02003418(args, Type_02003418_2);
            else {
                value = FORMAT_ARGUMENT02003418(args, int);
            }
            if (var2.length == 2) value = (short)value;
            if (var2.length == 1) value = (signed char)value;
            if (var2.length == 4 || var2.length == 6) {
                text = func_020023b8(var4, buffer + sizeof(buffer), var2);
                if (text == 0) goto invalid;
            } else {
                text = func_0200216c(value, buffer + sizeof(buffer), var2);
                if (text == 0) goto invalid;
            }
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        case 'o': case 'u': case 'x': case 'X':
            if (var2.length == 3) value = FORMAT_ARGUMENT02003418(args, unsigned long);
            else if (var2.length == 4) var4 = FORMAT_ARGUMENT02003418(args, unsigned long long);
            else if (var2.length == 6) var4 = FORMAT_ARGUMENT02003418(args, unsigned long long);
            else if (var2.length == 7) value = FORMAT_ARGUMENT02003418(args, size_t);
            else if (var2.length == 8) value = FORMAT_ARGUMENT02003418(args, Type_02003418_2);
            else {
                value = FORMAT_ARGUMENT02003418(args, unsigned int);
            }
            if (var2.length == 2) value = (unsigned short)value;
            if (var2.length == 1) value = (unsigned char)value;
            if (var2.length == 4 || var2.length == 6) {
                text = func_020023b8(var4, buffer + sizeof(buffer), var2);
                if (text == 0) goto invalid;
            } else {
                text = func_0200216c(value, buffer + sizeof(buffer), var2);
                if (text == 0) goto invalid;
            }
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        case 'e': case 'E': case 'f': case 'F': case 'g': case 'G': {
            long double var13;
            if (var2.length == 9) {
                var13 = FORMAT_ARGUMENT02003418(args, long double);
            } else {
                var13 = FORMAT_ARGUMENT02003418(args, double);
            }
            text = func_02002cb4(var13, buffer + sizeof(buffer), var2);
            if (text == 0) goto invalid;
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        }
        case 'a': case 'A': {
            long double var14;
            if (var2.length == 9) {
                var14 = FORMAT_ARGUMENT02003418(args, long double);
            } else {
                var14 = FORMAT_ARGUMENT02003418(args, double);
            }
            text = func_020026b4(var14, buffer + sizeof(buffer), var2);
            if (text == 0) goto invalid;
            length = buffer + sizeof(buffer) - 1 - text;
            break;
        }
        case 's':
            if (var2.length == 5) {
                const unsigned short* var15 = FORMAT_ARGUMENT02003418(args, const unsigned short*);
                if (var15 == 0) var15 = data_020eef28;
                if (func_020019c8(buffer, var15, sizeof(buffer)) < 0) goto invalid;
                text = buffer;
            } else text = FORMAT_ARGUMENT02003418(args, char*);
            if (text == 0) text = data_020eef2c;
            if (var2.alternate) {
                length = (unsigned char)*text++;
                if (var2.unknown_2_ && length > var2.unknown_c_) length = var2.unknown_c_;
            } else if (var2.unknown_2_) {
                length = var2.unknown_c_;
                const char* end = func_02001ac0(text, 0, length);
                if (end) length = end - text;
            } else length = strlen(text);
            break;
        case 'n': {
            void* destination = FORMAT_ARGUMENT02003418(args, void*);
            switch (var2.length) {
            case 0: *(int*)destination = total; break;
            case 2: *(short*)destination = total; break;
            case 3: *(long*)destination = total; break;
            case 6: *(long long*)destination = total; break;
            case 7: *(size_t*)destination = total; break;
            case 8: *(Type_02003418_2*)destination = total; break;
            case 4: *(long long*)destination = total; break;
            default: goto next;
            }
            goto next;
        }
        case 'c':
            buffer[0] = FORMAT_ARGUMENT02003418(args, int);
            text = buffer;
            length = 1;
            break;
        case '%':
            buffer[0] = '%';
            text = buffer;
            length = 1;
            break;
        case 255:
        default:
        invalid:
            {
                int var18 = strlen(var5);
                if (var18 && !arg0(state, var5, var18)) return -1;
                return total + var18;
            }
        }
        width = length;
        if (var2.alignment) {
            padding[0] = var2.alignment == 2 ? '0' : ' ';
            if ((*text == '+' || *text == '-' || *text == ' ') && padding[0] == '0') {
                if (!arg0(state, text, 1)) return -1;
                text++;
                length--;
            }
            if (width < var2.width) do {
                if (!arg0(state, padding, 1)) return -1;
                width++;
            } while (width < var2.width);
        }
        if (length && !arg0(state, text, length)) return -1;
        if (var2.alignment == 0 && width < var2.width) {
            do {
                var1 = ' ';
                if (!arg0(state, &var1, 1)) return -1;
                width++;
            } while (width < var2.width);
        }
        total += width;
    next:;
    } while (*format);
    return total;
}
