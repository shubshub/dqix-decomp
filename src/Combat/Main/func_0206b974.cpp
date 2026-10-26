#include <globaldefs.h>
#include "std_library_functions.h"

struct FontIndexFile
{
    struct Glyph
    {
        const char* tag;
        int8_t width;
        int8_t unknown_5_0_ : 6;
        int8_t unknown_5_6_ : 1;
        int8_t unknown_5_7_ : 1;
        char unk_6[2];
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
    char unk_0[0x70];
    unsigned int unknown_70_;
};

extern "C" int memcmp(const void* lhs, const void* rhs, unsigned int length);
extern "C" int Font_FindCharacterIndex(int, int);

extern "C" char* func_020424ac(char*);
extern "C" FontIndexFile::Glyph* Font_GetCharacter(int glyph, int fontType);
extern "C" int Font_GetKerning(int leftGlyph, int rightGlyph, int fontType);
extern "C" int Font_GetFallbackWidth(int fontType);
extern "C" int func_02044420(void*, void*);
extern "C" bool func_02044494(void*, void*);
extern "C" int STD_GetStringLength(const char*);
extern "C" bool func_020d85dc(const char* str, const char* initial);

struct Struct_020e7e04
{
    char unk_0[2];
    unsigned short unknown_2_;
    char unk_4[0x20];
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
    char* tag;
    int (*proc)(char* input, int* pX, int fontIndex, int margin);
};

extern const Struct_020e7ec4 data_020e7ec4[];

// USA: func_0206b974
extern "C" ARM void func_0206b974(Struct_0206b974* self, bool arg1, char *input, char *output,
    int arg4, int margin, bool arg6, unsigned char fontType)
{
    int local_2c;
    char* var1 = NULL;
    char* var2 = NULL;
    int var3 = 0;
    int var4 = 0;

    char* var5 = strstr(input, data_020f0979);
    char* var6 = strstr(input, data_020f097c);

    if (var5 != NULL || var6 != NULL)
        var4 = 2;

    local_2c = margin;
    unsigned char lastGlyphIndex = 0xff;
    bool var8 = true;
    bool var9 = 0;

    unsigned char defaultSpacing = Font_GetFallbackWidth(fontType);

    while (true)
    {
        char var11 = *input;
        if (var11 == 0)
            break;
        unsigned short control;
        memcpy(&control, input, 2);
        if (func_02044494(self, &control) && control != Enum_0206b974_65305)
        {
            int var13 = (func_02044420(self, &control) + 1) * 2;
            memcpy(output, input, var13);
            input += var13;
            output += var13;
            if (control == Enum_0206b974_65304)
            {
                var4 = 0;
                local_2c = margin;
                var1 = input;
                var2 = output;
                var3 = margin;
                lastGlyphIndex = 0xff;
                var9 = 0;
            }
            continue;
        }

        if (var11 == '\\' && input[1] == 'n')
        {

            var4 = 0;
            local_2c = margin;
            lastGlyphIndex = 0xff;

            memcpy(output, input, 2);
            input += 2;
            output += 2;
            var1 = input;
            var2 = output;
            var3 = local_2c;
            var9 = 0;
            continue;
        }

        if (var11 == '\n')
        {
            var4 = 0;
            local_2c = margin;
            lastGlyphIndex = 0xff;
            memcpy(output, input, 1);
            input += 1;
            output += 1;
            var1 = input;
            var2 = output;
            var3 = local_2c;
            var9 = 0;
            continue;
        }

        if (memcmp(input, data_020f0981, 6) == 0)
        {
            var4 = 0;
            local_2c = margin;
            lastGlyphIndex = 0xff;
            memcpy(output, input, 6);
            input += 6;
            output += 6;
            var1 = input;
            var2 = output;
            var3 = local_2c;
            var9 = 0;
            continue;
        }

        if (memcmp(input, data_020f08dc, 2) == 0)
        {
            char* var14 = strstr(input, data_020f0988);
            if (var14 != NULL)
            {
                local_2c = NULL;
                int var15 = var14 - input;
                memcpy(output, input, var15 + 3);
                input += var15 + 3;
                output += var15 + 3;
                continue;
            }
        }

        int nextGlyphIndex = Font_FindCharacterIndex((int)input, fontType);
        if (control == Enum_0206b974_65305)
            nextGlyphIndex = -1;
        if (var11 == '<' && nextGlyphIndex < 0)
        {
            char* var17 = func_020424ac(input);
            if (var17 != NULL)
            {
                char* tagInner = input + 1;
                for (const Struct_020e7ec4* candidate = data_020e7ec4;
                    candidate->tag != NULL && candidate->proc != NULL; candidate++)
                {
                    if (!func_020d85dc(tagInner, candidate->tag))
                        continue;

                    int procRet = candidate->proc(tagInner + STD_GetStringLength(candidate->tag), &local_2c, fontType, margin);
                    if (procRet != 1)
                    {
                        if (procRet == 2)
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
                int var21 = (var17 - input);
                memcpy(output, input, var21 + 1);
                input += var21 + 1;
                output += var21 + 1;
                continue;
            }
        }

        bool var22 = false;
        int var23 = defaultSpacing + 1;
        int var24 = 1;
        if (control == Enum_0206b974_65305)
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
            nextGlyphIndex = -1;
            input += 3;
            var23 = 0;
            var24 = 0;
            var9 = 1;
        }
        if (nextGlyphIndex >= 0)
        {
            FontIndexFile::Glyph* glyph = Font_GetCharacter(nextGlyphIndex, fontType);
            var24 = glyph->unknown_5_0_;
            unsigned char nextGlyphUC = nextGlyphIndex;
            int kerning = Font_GetKerning(lastGlyphIndex, nextGlyphUC, fontType);
            lastGlyphIndex = nextGlyphUC;
            var23 = kerning + glyph->width;

            var22 = (glyph->tag[0] == '-');
            if (var22)
                var9 = 0;

            if (var1 != NULL && var2 != NULL && var8 &&
                (arg4 + var4 < local_2c + var23))
            {
                local_2c -= var3;
                local_2c += margin;
                var4 = 0;
                int var28 = input - var1;
                int var29 = output - var2;
                output = var2;
                memset(var2, 0, var29);
                if (var9 != 0)
                {
                    memcpy(output, data_020f0990, 1);
                    output += 1;
                }
                if (arg6)
                {
                    memcpy(output, &data_020e7e04.unknown_2_, 2);
                    output += 2;
                }
                else
                {
                    memcpy(output, data_020f0992, 1);
                    output += 1;
                }
                memcpy(output, var1, var28);
                output += var28;
                var9 = 0;
                if (arg1)
                {
                    self->unknown_70_++;
                }
            }
            var23++;
        }
        if (var8)
            local_2c += var23;

        memcpy(output, input, var24);
        input += var24;
        output += var24;
        if (nextGlyphIndex < 0 || var22)
        {
            var1 = input;
            var2 = output;
            var3 = local_2c;
        }
    }

    *output = *input;
}
