#include <globaldefs.h>
#include <std_library_functions.h>

#if defined(jpn)
typedef unsigned short Type_0206aa28;
#else
typedef char Type_0206aa28;
#endif

#if defined(jpn)
enum { Enum_0206aa28_20 = 0x14, Enum_0206aa28_80 = 0x1c, Enum_0206aa28_84 = 0x20,
       Enum_0206aa28_36 = 0x24, Enum_0206aa28_52 = 0x34, Enum_0206aa28_108 = 0x38,
       Enum_0206aa28_112 = 0x3c, Enum_0206aa28_116 = 0x40, Enum_0206aa28_120 = 0x44 };
#else
enum { Enum_0206aa28_72 = 0x48, Enum_0206aa28_80 = 0x50, Enum_0206aa28_84 = 0x54,
       Enum_0206aa28_88 = 0x58, Enum_0206aa28_104 = 0x68, Enum_0206aa28_108 = 0x6c,
       Enum_0206aa28_112 = 0x70, Enum_0206aa28_116 = 0x74, Enum_0206aa28_120 = 0x78 };
#endif

struct Object02043124;
extern "C" void MessageSystem_Reset(char*);
extern "C" void MessageSystem_Stop(Object02043124*);

#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069408(void*, unsigned short);
extern "C" unsigned short* func_0206c730(void*, unsigned short, unsigned short*);
extern "C" void func_0206c794(void*);
#else
struct Entry0204254c {
    int key;
    signed char width;
    signed char size : 6;
    signed char flags : 2;
    char unknown6[2];
};
extern "C" int func_0206ac6c(void*, void*);
extern "C" int func_0206abf8(void*, void*);
extern "C" bool func_02067a9c(void*, void*);
extern "C" Entry0204254c* Font_FindCharacter(int, int);
extern "C" char* func_0206ac94(void*, unsigned short, char*);
extern "C" void func_0206ad74(void*);
#endif

// USA: func_0206aa28
extern "C" ARM void func_0206aa28(char* context) {
#if !defined(jpn)
    *(int*)(context + 0x7c) = 0;
#endif
    (*(int*)(context + Enum_0206aa28_108)) = 0;
    (*(int*)(context + Enum_0206aa28_112)) = 0;
    (*(int*)(context + Enum_0206aa28_116)) = 0;
    (*(int*)(context + Enum_0206aa28_120)) = 0;
    Type_0206aa28* cursor = *(Type_0206aa28**)(context + Enum_0206aa28_84);
    Type_0206aa28* output = *(Type_0206aa28**)(context + Enum_0206aa28_80);
    bool var2 = false;
#if defined(jpn)
    while (cursor != 0) {
        *output = *cursor;
        ++output;
        (*(int*)(context + Enum_0206aa28_112))++;
        if (*(unsigned int*)(context + Enum_0206aa28_52) < (unsigned int)(cursor - *(Type_0206aa28**)(context + Enum_0206aa28_20))) {
            *(int*)(context + 0x868) = 0;
            break;
        }
        if (func_02069430(context, *cursor)) {
            if (*cursor == 0xff1a || *cursor == 0xff1b) var2 = 1;
            if (func_02069408(context, *cursor)) {
                if (!var2) {
                    (*(int*)(context + Enum_0206aa28_112))--;
                    *(Type_0206aa28**)(context + Enum_0206aa28_84) = ++cursor;
                    --output;
                    continue;
                }
                *(Type_0206aa28**)(context + Enum_0206aa28_36) = cursor;
                break;
            }
            unsigned short command = *cursor;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206c730(context, command, *(Type_0206aa28**)(context + Enum_0206aa28_20));
                if (!cursor) {
                    unsigned char saved = *(unsigned char*)(context + 0x17fd);
                    MessageSystem_Reset(context);
                    MessageSystem_Stop((Object02043124*)(context));
                    context[0x17fd] = saved;
                    break;
                }
            }
        } else {
            var2 = 1;
        }
        ++cursor;
    }
    func_0206c794(context);
#else
    for (;;) {
        if (!*cursor) break;
        int var5 = 0;
        if (func_0206ac6c(context, cursor)) {
            int words = func_0206abf8(context, cursor) + 1;
            var5 = words * 2;
            memcpy(output, cursor, var5);
            output += words * 2;
            (*(int*)(context + Enum_0206aa28_112)) += words * 2;
        }
        if (*(unsigned int*)(context + Enum_0206aa28_104) < (unsigned int)(cursor - *(Type_0206aa28**)(context + Enum_0206aa28_72))) {
            *(int*)(context + 0x998) = 0;
            break;
        }
        if (func_0206ac6c(context, cursor)) {
            if (func_02067a9c(context, cursor)) {
                if (var2) {
                    *(Type_0206aa28**)(context + Enum_0206aa28_88) = cursor;
                    break;
                }
                unsigned char saved = *(unsigned char*)(context + 0x19cc);
                MessageSystem_Reset(context);
                MessageSystem_Stop((Object02043124*)(context));
                context[0x19cc] = saved;
                break;
            }
            unsigned short command;
            memcpy(&command, cursor, 2);
            cursor += var5;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206ac94(context, command, *(Type_0206aa28**)(context + Enum_0206aa28_72));
                if (!cursor) {
                    unsigned char saved = *(unsigned char*)(context + 0x19cc);
                    MessageSystem_Reset(context);
                    MessageSystem_Stop((Object02043124*)(context));
                    context[0x19cc] = saved;
                    break;
                }
            }
        } else {
            var2 = 1;
            int size = 1;
            Entry0204254c* entry = Font_FindCharacter((int)(cursor), (unsigned char)(context[0x19dc]));
            if (entry) size = entry->size;
            memcpy(output, cursor, size);
            output += size;
            (*(int*)(context + Enum_0206aa28_112))++;
            cursor += size;
        }
    }
    func_0206ad74(context);
#endif
}
