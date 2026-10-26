#if defined(jpn)
#define func_0204f7e8 func_02050cc0
#endif
#include <globaldefs.h>

struct Struct_ov023_021f8240_8
{
    int x;
    int y;
    int z;
};

class Struct_ov023_021f8240
{
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short unknown_8_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    Struct_ov023_021f8240* unknown_14_;
    Struct_ov023_021f8240* unknown_18_;
    int state_;

    virtual void inline_ov023_021f8240_38();
    virtual void inline_ov023_021f8240_39();
    virtual void inline_ov023_021f8240_40();
    virtual void inline_ov023_021f8240_41();
    virtual void inline_ov023_021f8240_42();
    virtual void inline_ov023_021f8240_43();
    virtual void inline_ov023_021f8240_44();
    virtual void inline_ov023_021f8240_45();
    virtual Struct_ov023_021f8240_8 inline_ov023_021f8240_46();
    virtual void inline_ov023_021f8240_47();
    virtual void inline_ov023_021f8240_48();
    virtual void inline_ov023_021f8240_49();
    virtual void inline_ov023_021f8240_50();
    virtual void inline_ov023_021f8240_51();
    virtual void inline_ov023_021f8240_52();
    virtual void inline_ov023_021f8240_53();
    virtual void inline_ov023_021f8240_54();
    virtual void inline_ov023_021f8240_55();
    virtual void inline_ov023_021f8240_56();
    virtual void inline_ov023_021f8240_57();
    virtual void inline_ov023_021f8240_58();
    virtual void inline_ov023_021f8240();
    virtual void inline_ov023_021f8240_2();
    virtual void inline_ov023_021f8240_3();
    virtual void inline_ov023_021f8240_4();
    virtual void inline_ov023_021f8240_5();
    virtual void inline_ov023_021f8240_6();
    virtual void inline_ov023_021f8240_7();
    virtual void inline_ov023_021f8240_8();
    virtual void inline_ov023_021f8240_9();
    virtual void inline_ov023_021f8240_10();
    virtual void inline_ov023_021f8240_11();
    virtual void inline_ov023_021f8240_12();
    virtual void inline_ov023_021f8240_13();
    virtual void inline_ov023_021f8240_14();
    virtual void inline_ov023_021f8240_15();
    virtual void inline_ov023_021f8240_16();
    virtual void inline_ov023_021f8240_17();
    virtual void inline_ov023_021f8240_18();
    virtual void inline_ov023_021f8240_19();
    virtual void inline_ov023_021f8240_20();
    virtual void inline_ov023_021f8240_21();
    virtual void inline_ov023_021f8240_22();
    virtual void inline_ov023_021f8240_23();
    virtual void inline_ov023_021f8240_24();
    virtual void inline_ov023_021f8240_25();
    virtual void inline_ov023_021f8240_26();
    virtual void inline_ov023_021f8240_27();
    virtual void inline_ov023_021f8240_28();
    virtual void inline_ov023_021f8240_29();
    virtual void inline_ov023_021f8240_30();
    virtual void inline_ov023_021f8240_31();
    virtual void inline_ov023_021f8240_32();
    virtual void inline_ov023_021f8240_33();
    virtual void inline_ov023_021f8240_34();
    virtual unsigned char inline_ov023_021f8240_35();
    virtual void inline_ov023_021f8240_36(int);
    virtual int inline_ov023_021f8240_37();
};

class Struct_ov023_021f8240_2 : public Struct_ov023_021f8240
{
public:
    const char* text_;
    Struct_ov023_021f8240_8 unk_24;
    short unknown_30_;
    short unknown_32_;
    unsigned short canvas_;
    unsigned short texts_;
    short unknown_38_;
    unsigned short x_;
    unsigned short y_;
    unsigned short width_;
    unsigned short height_;
    short unk_42;
    unsigned char font_ : 4;
    unsigned char unknown_44_4_ : 4;
    unsigned char unknown_45_0_ : 1;
#if defined(jpn)
    unsigned char unknown_45_1_ : 7;
#else
    unsigned char unknown1_45_1_ : 6;
    unsigned char unknown_45_7_ : 1;
#endif
};

class Struct_ov023_021f8240_3 : public Struct_ov023_021f8240
{
public:
    Struct_ov023_021f8240_8 unk_20;
    int unknown_2c_;
    unsigned short canvas_;
    unsigned short x_;
    unsigned short y_;
    unsigned short width_;
    unsigned short height_;
    unsigned char font_ : 4;
    unsigned char unknown_3a_4_ : 4;
    unsigned char unknown_3b_;
    unsigned char unk_3c;
    unsigned char unknown_3d_;
};

class Struct_ov023_021f8240_4 : public Struct_ov023_021f8240
{
public:
    char unk_20[4];
    unsigned short canvas_;
    unsigned short x_;
    unsigned short y_;
    unsigned short width_;
    unsigned short height_;
    unsigned char unknown_2e_;
};

struct Struct_ov023_021f8240_5
{
    char unk_0[0xb4];
    short unknown_b4_;
    short unknown_b6_;
    char unk_b8[0xe0 - 0xb8];
};

class Struct_ov023_021f8240_6 : public Struct_ov023_021f8240
{
public:
    Struct_ov023_021f8240_5 canvas_;
    unsigned short x_;
    unsigned short y_;
    short page_;
    short pages_;
    unsigned char frame_;
    char unknown_109_;
    unsigned char unknown_10a_;
    char unknown_10b_;
    unsigned short unknown_10c_;
    unsigned short unknown_10e_;
};

struct Struct_ov023_021f68b8;
struct TableA68;
struct Struct_ov023_021f8240_7;

extern "C" Struct_ov023_021f68b8* func_ov011_021849c8(void* script);
extern "C" Struct_ov023_021f8240* func_ov023_021f68b8(Struct_ov023_021f68b8* list, int index);
extern "C" unsigned short func_ov023_021f6f10(Struct_ov023_021f8240* object);
extern "C" Struct_ov023_021f8240* func_ov023_021f6880(Struct_ov023_021f68b8* list, int id);
extern "C" TableA68* func_ov023_021fa598(Struct_ov023_021f8240* texts);
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" int func_02042190(int font);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_0206819c(const char* text, char* output, int font);
extern "C" void* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void* messages, int, const char* input, char* output, int, int, int);
extern "C" int Font_GetTextWidth(const char* text, int font);
extern "C" void func_0204f41c(Struct_ov023_021f8240_5* canvas, short x, short y, const char* text, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int);
extern "C" void func_ov023_021f8c48(unsigned char*, unsigned short);
extern "C" void func_ov023_021f8c58(unsigned char*, unsigned short);
extern "C" void func_0204f7e8(Struct_ov023_021f8240_5* canvas, short x, short y, int value, unsigned char font,
                              unsigned char color, unsigned short* width, unsigned short* height, int, int, int, int);
extern "C" void func_ov023_021fbcb0(Struct_ov023_021f8240_3* number, unsigned short width);
extern "C" void func_ov023_021fbcb8(void* number, unsigned short height);
extern "C" unsigned short func_ov023_021fc4fc(Struct_ov023_021f8240_4* box);
extern "C" unsigned short func_ov023_021fc504(Struct_ov023_021f8240_7* box);
extern "C" void func_0204f914(Struct_ov023_021f8240_5* canvas, unsigned char color, short x, short y, short right,
                              short bottom);
extern "C" Struct_ov023_021f8240* func_ov023_021f6f18(void* object);

#if defined(jpn)
extern "C" int STD_GetStringLength(const char*);
extern "C" void func_02050678(Struct_ov023_021f8240_5*, short, short, const char*, int, unsigned char, unsigned short*, unsigned short*);
#endif

// USA: func_ov023_021f8240
extern "C" ARM void func_ov023_021f8240(Struct_ov023_021f8240_6* self, void* script)
{
#if defined(jpn)
    short var0 = *(short*)((char*)self + 0xc8) * 8;
#endif
    Struct_ov023_021f68b8* objects = func_ov011_021849c8(script);
    for (Struct_ov023_021f8240* object = func_ov023_021f68b8(objects, 0); object != NULL;
         object = func_ov023_021f6f18(object))
    {
        int kind = 0;
        if (!(object->flags_ & 8))
        {
            switch (func_ov023_021f6f10(object))
            {
            case 8:
                kind = 1;
                break;
            case 15:
                kind = 2;
                break;
            case 19:
                kind = 3;
                break;
            }
        }
        if (kind == 1)
        {
            Struct_ov023_021f8240_2* text = (Struct_ov023_021f8240_2*)object;
            int size;
#if !defined(jpn)
            const char* string;
#endif
            int formatted;
#if defined(jpn)
            unsigned char font;
#else
            unsigned char font;
#endif
            if (text->canvas_ != self->id_)
                continue;
#if defined(jpn)
            const char* string = text->text_;
#else
            string = text->text_;
#endif
            if (string == NULL)
            {
                Struct_ov023_021f8240* texts = func_ov023_021f6880(objects, text->texts_);
                if (texts != NULL && func_ov023_021f6f10(texts) == 4)
                    string = func_02072a68(func_ov023_021fa598(texts), text->unknown_38_);
            }
            if (string == NULL)
                continue;
            Struct_ov023_021f8240_8 position = text->inline_ov023_021f8240_46();
            font = text->font_;
            unsigned char color = text->inline_ov023_021f8240_35();
            short left = self->unknown_10c_ + font;
            short right = self->unknown_10e_ + font;
            self->canvas_.unknown_b4_ = left;
            self->canvas_.unknown_b6_ = right;
#if defined(jpn)
            short var14 = text->unk_42;
            int length = STD_GetStringLength(string);
            int width = (length * font) >> 1;
            switch (text->unknown_45_1_)
            {
            case 1: position.x = var14 * 4096; break;
            case 3: position.x = ((var0 - width) >> 1) * 4096; break;
            case 2: position.x = (var14 + (var0 - width)) * 4096; break;
            }
            int x = position.x / 4096.0f;
            int y = position.y / 4096.0f;
#else
            formatted = text->unknown_45_7_;
            size = func_02042190(text->font_);
            char codes[0x100] = {0};
            char formattedText[0x100] = {0};
            if (formatted)
            {
                func_0206819c(string, codes, size);
                MessageSystem_FormatText(MessageSystem_GetInstance(), 10, codes, formattedText, 0x400, 0, 0);
                string = formattedText;
            }
            int width = Font_GetTextWidth(string, size);
            int x = position.x / 4096.0f;
            int y = position.y / 4096.0f;
            switch (text->unknown1_45_1_)
            {
            case 1:
                break;
            case 3:
                x -= width >> 1;
                break;
            case 2:
                x -= width;
                break;
            }
#endif
            unsigned short textWidth;
            unsigned short var25;
#if defined(jpn)
            func_02050678(&self->canvas_, x, y, string, font, color, &textWidth, &var25);
#else
            func_0204f41c(&self->canvas_, x, y, string, font, color, &textWidth, &var25, 0);
#endif
            func_ov023_021f8c48((unsigned char*)text, textWidth);
            func_ov023_021f8c58((unsigned char*)text, var25);
        }
        else if (kind == 2)
        {
            Struct_ov023_021f8240_3* number = (Struct_ov023_021f8240_3*)object;
            if (number->canvas_ != self->id_)
                continue;
            unsigned char font = number->font_;
            int value = number->inline_ov023_021f8240_37();
            unsigned char var29 = number->unknown_3b_;
            unsigned char unk3c = number->unk_3c;
            unsigned char color = number->inline_ov023_021f8240_35();
            Struct_ov023_021f8240_8 position = number->inline_ov023_021f8240_46();
            unsigned char var33 = number->unknown_3d_;
            self->canvas_.unknown_b4_ = font;
            self->canvas_.unknown_b6_ = font + 1;
            int x = position.x / 4096.0f;
            int y = position.y / 4096.0f;
            unsigned short textWidth;
            unsigned short var37;
            func_0204f7e8(&self->canvas_, x, y, value, font, color, &textWidth, &var37, var29, unk3c, 0, var33);
            func_ov023_021fbcb0(number, textWidth);
            func_ov023_021fbcb8(number, var37);
        }
        else if (kind == 3)
        {
            Struct_ov023_021f8240_4* box = (Struct_ov023_021f8240_4*)object;
            if (box->canvas_ != self->id_)
                continue;
            unsigned char color = box->inline_ov023_021f8240_35();
            Struct_ov023_021f8240_8 position = box->inline_ov023_021f8240_46();
            unsigned short x = position.x / 4096.0f;
            unsigned short y = position.y / 4096.0f;
            unsigned short right = func_ov023_021fc4fc(box) + x;
            unsigned short bottom = func_ov023_021fc504((Struct_ov023_021f8240_7*)box) + y;
            func_0204f914(&self->canvas_, color, x, y, right, bottom);
        }
    }
}
