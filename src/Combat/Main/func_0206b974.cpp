#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0206b974_2
{
    struct Struct_0206b974_3
    {
        const char* unknown_0_;
        int8_t unknown_4_;
        int8_t unknown_5_0_ : 6;
        int8_t unknown_5_6_ : 1;
        int8_t unknown_5_7_ : 1;
        char unknown_6_[2];
    };
};

enum Enum_0206b974
{
    Enum_0206b974_65304 = 0xff18,
    Enum_0206b974_65305 = 0xff19,
};

class Struct_0206b974
{
public:
    char unknown_0_[0x70];
    unsigned int unknown_70_;
};

extern "C" int memcmp(const void* lhs, const void* rhs, unsigned int length);
int Font_FindCharacterIndex(int, int);

char* FindUnescapedAngleBracket_020424ac(char*);
FontIndexFile::Glyph* Font_GetCharacter(int glyph, int fontType);
int LookupKeyValue020425e4(int leftGlyph, int rightGlyph, int fontType);
int GetWordFromTable02042648(int fontType);
int Dispatch02044420(void*, void*);
bool IsHighByteFF02044494(void*, void*);
int STD_GetStringLength(const char*);
bool StringStartsWithCI020d85dc(const char* str, const char* initial);

struct Struct_020e7e04
{
    char unknown_0_[2];
    unsigned short unknown_2_;
    char unknown_4_[0x20];
    short unknown_24_[2];
} extern const data_020e7e04;

extern char data_020f08dc[];
extern char data_020f0979[];
extern char data_020f097c[];
extern char data_020f0981[];
extern char data_020f0988[];
extern char data_020f098c[];
extern char data_020f0990[];
extern char data_020f0992[];

struct Struct_020e7ec4
{
    char* unknown_0_;
    int (*unknown_4_)(char* input, int* pX, int fontIndex, int margin);
};

extern const Struct_020e7ec4 data_020e7ec4[];

// USA: func_0206b974
extern "C" ARM void func_0206b974(Struct_0206b974* arg0, bool arg1, char *arg2, char *arg3,
    int arg4, int arg5, bool arg6, unsigned char arg7)
{
    int var0;
    char* var1 = NULL;
    char* var2 = NULL;
    int var3 = 0;
    int var4 = 0;

    char* var5 = strstr(arg2, data_020f0979);
    char* var6 = strstr(arg2, data_020f097c);

    if (var5 != NULL || var6 != NULL)
        var4 = 2;

    var0 = arg5;
    unsigned char var7 = 0xff;
    bool var8 = true;
    bool var9 = 0;

    unsigned char var10 = func_02042648(arg7);

    while (true)
    {
        char var11 = *arg2;
        if (var11 == 0)
            break;
        unsigned short var12;
        memcpy(&var12, arg2, 2);
        if (func_02044494(arg0, &var12) && var12 != Enum_0206b974_65305)
        {
            int var13 = (func_02044420(arg0, &var12) + 1) * 2;
            memcpy(arg3, arg2, var13);
            arg2 += var13;
            arg3 += var13;
            if (var12 == Enum_0206b974_65304)
            {
                var4 = 0;
                var0 = arg5;
                var1 = arg2;
                var2 = arg3;
                var3 = arg5;
                var7 = 0xff;
                var9 = 0;
            }
            continue;
        }

        if (var11 == '\\' && arg2[1] == 'n')
        {

            var4 = 0;
            var0 = arg5;
            var7 = 0xff;

            memcpy(arg3, arg2, 2);
            arg2 += 2;
            arg3 += 2;
            var1 = arg2;
            var2 = arg3;
            var3 = var0;
            var9 = 0;
            continue;
        }

        if (var11 == '\n')
        {
            var4 = 0;
            var0 = arg5;
            var7 = 0xff;
            memcpy(arg3, arg2, 1);
            arg2 += 1;
            arg3 += 1;
            var1 = arg2;
            var2 = arg3;
            var3 = var0;
            var9 = 0;
            continue;
        }

        if (memcmp(input, data_020f0981, 6) == 0)
        {
            var4 = 0;
            var0 = arg5;
            var7 = 0xff;
            memcpy(arg3, arg2, 6);
            arg2 += 6;
            arg3 += 6;
            var1 = arg2;
            var2 = arg3;
            var3 = var0;
            var9 = 0;
            continue;
        }

        if (memcmp(input, data_020f08dc, 2) == 0)
        {
            char* var14 = strstr(arg2, data_020f0988);
            if (var14 != NULL)
            {
                var0 = NULL;
                int var15 = var14 - arg2;
                memcpy(arg3, arg2, var15 + 3);
                arg2 += var15 + 3;
                arg3 += var15 + 3;
                continue;
            }
        }

        int nextGlyphIndex = Font_FindCharacterIndex((int)input, fontType);
        if (control == ControlWord_Unknown_ff19)
            nextGlyphIndex = -1;
        if (nextChar == '<' && nextGlyphIndex < 0)
        {
            char* var17 = func_020424ac(arg2);
            if (var17 != NULL)
            {
                char* var18 = arg2 + 1;
                for (const Struct_020e7ec4* var19 = data_020e7ec4;
                    var19->unknown_0_ != NULL && var19->unknown_4_ != NULL; var19++)
                {
                    if (!func_020d85dc(var18, var19->unknown_0_))
                        continue;

                    int procRet = candidate->proc(tagInner + STD_GetStringLength(candidate->tag), &local_2c, fontType, margin);
                    if (procRet != 1)
                    {
                        if (var20 == 2)
                        {
                            var8 = true;
                        }
                        break;
                    }
                    else
                    {
                        var8 = false;
                        break;
                    }
                }
                int var21 = (var17 - arg2);
                memcpy(arg3, arg2, var21 + 1);
                arg2 += var21 + 1;
                arg3 += var21 + 1;
                continue;
            }
        }

        bool var22 = false;
        int var23 = var10 + 1;
        int var24 = 1;
        if (var12 == Enum_0206b974_65305)
        {
            var9 = 1;
            var24 = 2;
        }
        if (var11 == ' ')
        {
            var9 = 0;
        }
        if (memcmp(input, data_020f098c, 3) == 0)
        {
            var16 = -1;
            arg2 += 3;
            var23 = 0;
            var24 = 0;
            var9 = 1;
        }
        if (var16 >= 0)
        {
            FontIndexFile::Glyph* glyph = Font_GetCharacter(nextGlyphIndex, fontType);
            ioCopyLength = glyph->tagLength;
            unsigned char nextGlyphUC = nextGlyphIndex;
            int kerning = LookupKeyValue020425e4(lastGlyphIndex, nextGlyphUC, fontType);
            lastGlyphIndex = nextGlyphUC;
            glyphSpacing = kerning + glyph->width;

            var22 = (var25->unknown_0_[0] == '-');
            if (var22)
                var9 = 0;

            if (var1 != NULL && var2 != NULL && var8 &&
                (arg4 + var4 < var0 + var23))
            {
                var0 -= var3;
                var0 += arg5;
                var4 = 0;
                int var28 = arg2 - var1;
                int var29 = arg3 - var2;
                arg3 = var2;
                memset(var2, 0, var29);
                if (var9 != 0)
                {
                    memcpy(arg3, data_020f0990, 1);
                    arg3 += 1;
                }
                if (arg6)
                {
                    memcpy(arg3, &data_020e7e04.unknown_2_, 2);
                    arg3 += 2;
                }
                else
                {
                    memcpy(arg3, data_020f0992, 1);
                    arg3 += 1;
                }
                memcpy(arg3, var1, var28);
                arg3 += var28;
                var9 = 0;
                if (arg1)
                {
                    arg0->unknown_70_++;
                }
            }
            var23++;
        }
        if (var8)
            var0 += var23;

        memcpy(arg3, arg2, var24);
        arg2 += var24;
        arg3 += var24;
        if (var16 < 0 || var22)
        {
            var1 = arg2;
            var2 = arg3;
            var3 = var0;
        }
    }

    *arg3 = *arg2;
}
