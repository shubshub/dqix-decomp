#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0206b37c {
    char unknown_0_[0x19dc];
    unsigned char unknown_19dc_;
};

struct Struct_0204254c {
    int unknown_0_;
    signed char unknown_4_;
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 2;
    char unknown_6_[2];
};

int GetWordFromTable02042648(int);
bool IsHighByteFF02044494(void*, void*);
int Dispatch02044420(void*, void*);
int LookupKeyValue020425e4(int, int, int);
Entry0204254c* Font_FindCharacter(int, int);
int Font_FindCharacterIndex(int, int);
int IsHalfwordInRange02067ad8(int, void*);

// USA: func_0206b37c
extern "C" ARM int func_0206b37c(Struct_0206b37c* arg0, char* arg1) {
    if (!arg1) return 0;
    unsigned char var0 = func_02042648(arg0->unknown_19dc_);
    int var1 = 0xff;
    unsigned char var2 = var1;
    int var3;
    int var4;
    int var5 = 0;
    unsigned short var6;
    short var7;
    while (!func_02067ad8((int)arg0, arg1)) {
        memcpy(&var6, arg1, 2);
        if (func_02044494(arg0, &var6)) {
            var3 = func_02044420(arg0, &var6);
            switch (var6) {
            case 0xff19:
                var2 = 0xff;
                var5 += func_020425e4(var2, var1, arg0->unknown_19dc_);
                break;
            case 0xff20:
                var2 = 0xff;
                memcpy(&var7, arg1 + 2, 2);
                if (var5 < var7) var5 = var7;
                break;
            case 0xff23:
                var2 = 0xff;
                memcpy(&var7, arg1 + 2, 2);
                var5 += var7;
                break;
            }
            arg1 = arg1 + 2 + var3 * 2;
        } else {
            step = 1;
            int glyphWidth = defaultWidth;
            Entry0204254c* entry = Font_FindCharacter((int)text, context->fontTable);
            if (entry) {
                current = (unsigned char)Font_FindCharacterIndex((int)text, context->fontTable);
                width += LookupKeyValue020425e4(previous, current, context->fontTable);
                previous = current;
                current = 0xff;
                step = entry->size;
                glyphWidth = entry->width;
            }
            var5 += var8 + 1;
            arg1 += var4;
        }
    }
    return var5;
}
