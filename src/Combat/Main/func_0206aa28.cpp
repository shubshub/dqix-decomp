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
void MessageSystem_Reset(char*);
extern "C" void MessageSystem_Stop(Object02043124*);

#if defined(jpn)
extern "C" int func_02069430(void*, unsigned short);
extern "C" int func_02069408(void*, unsigned short);
extern "C" unsigned short* func_0206c730(void*, unsigned short, unsigned short*);
extern "C" void func_0206c794(void*);
#else
struct Struct_0204254c {
    int unknown_0_;
    signed char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};
int IsHighByteFF0206ac6c(void*, void*);
int Func0206abf8(void*, void*);
bool IsCommandInRange02067a9c(void*, void*);
Entry0204254c* Font_FindCharacter(int, int);
extern "C" char* func_0206ac94(void*, unsigned short, char*);
extern "C" void func_0206ad74(void*);
#endif

// USA: func_0206aa28
extern "C" ARM void func_0206aa28(char* arg0) {
#if !defined(jpn)
    *(int*)(arg0 + 0x7c) = 0;
#endif
    (*(int*)(arg0 + Enum_0206aa28_108)) = 0;
    (*(int*)(arg0 + Enum_0206aa28_112)) = 0;
    (*(int*)(arg0 + Enum_0206aa28_116)) = 0;
    (*(int*)(arg0 + Enum_0206aa28_120)) = 0;
    Type_0206aa28* var0 = *(Type_0206aa28**)(arg0 + Enum_0206aa28_84);
    Type_0206aa28* var1 = *(Type_0206aa28**)(arg0 + Enum_0206aa28_80);
    bool var2 = false;
#if defined(jpn)
    while (var0 != 0) {
        *var1 = *var0;
        ++var1;
        (*(int*)(arg0 + Enum_0206aa28_112))++;
        if (*(unsigned int*)(arg0 + Enum_0206aa28_52) < (unsigned int)(var0 - *(Type_0206aa28**)(arg0 + Enum_0206aa28_20))) {
            *(int*)(arg0 + 0x868) = 0;
            break;
        }
        if (func_02069430(arg0, *var0)) {
            if (*var0 == 0xff1a || *var0 == 0xff1b) var2 = 1;
            if (func_02069408(arg0, *var0)) {
                if (!var2) {
                    (*(int*)(arg0 + Enum_0206aa28_112))--;
                    *(Type_0206aa28**)(arg0 + Enum_0206aa28_84) = ++var0;
                    --var1;
                    continue;
                }
                *(Type_0206aa28**)(arg0 + Enum_0206aa28_36) = var0;
                break;
            }
            unsigned short command = *cursor;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206c730(context, command, *(MessageCharacter**)(context + SourceField));
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
        ++var0;
    }
    func_0206c794(arg0);
#else
    for (;;) {
        if (!*var0) break;
        int var5 = 0;
        if (func_0206ac6c(arg0, var0)) {
            int var6 = func_0206abf8(arg0, var0) + 1;
            var5 = var6 * 2;
            memcpy(var1, var0, var5);
            var1 += var6 * 2;
            (*(int*)(arg0 + Enum_0206aa28_112)) += var6 * 2;
        }
        if (*(unsigned int*)(arg0 + Enum_0206aa28_104) < (unsigned int)(var0 - *(Type_0206aa28**)(arg0 + Enum_0206aa28_72))) {
            *(int*)(arg0 + 0x998) = 0;
            break;
        }
        if (func_0206ac6c(arg0, var0)) {
            if (func_02067a9c(arg0, var0)) {
                if (var2) {
                    *(Type_0206aa28**)(arg0 + Enum_0206aa28_88) = var0;
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
            cursor += commandBytes;
            if ((command & 0xffe0) == 0xffe0) {
                command = (unsigned short)(command ^ 0xffe0) + 0xffd0;
                cursor = func_0206ac94(context, command, *(MessageCharacter**)(context + SourceField));
                if (!cursor) {
                    unsigned char saved = *(unsigned char*)(context + 0x19cc);
                    MessageSystem_Reset(context);
                    MessageSystem_Stop((Object02043124*)(context));
                    context[0x19cc] = saved;
                    break;
                }
            }
        } else {
            seenGlyph = 1;
            int size = 1;
            Entry0204254c* entry = Font_FindCharacter((int)(cursor), (unsigned char)(context[0x19dc]));
            if (entry) size = entry->size;
            memcpy(output, cursor, size);
            output += size;
            (*(int*)(context + LengthField))++;
            cursor += size;
        }
    }
    func_0206ad74(arg0);
#endif
}
