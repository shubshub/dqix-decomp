#include <globaldefs.h>

struct Struct_020d4c7c
{
    unsigned char count;
    unsigned char padding[3];
    struct
    {
        unsigned char id;
        unsigned char length;
        unsigned char unknown_2_[2];
        unsigned char* body;
    } element[16];
};

struct Struct_020d4c7c_2
{
    unsigned short length;
    char unk_2[0x3c - 0x2];
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    unsigned char elements[1];
};

// USA: func_020d4c7c
extern "C" ARM Struct_020d4c7c func_020d4c7c(const Struct_020d4c7c_2* arg0)
{
    Struct_020d4c7c elements;
    const unsigned char* element;
    int i;
    unsigned char length;
    unsigned char maxLength;
    if (arg0->unknown_3c_ != 0)
    {
        elements.count = 0;
        return elements;
    }
    elements.count = arg0->unknown_3e_;
    if (elements.count == 0)
        return elements;
    if (elements.count > 16)
        elements.count = 16;
    element = arg0->elements;
    maxLength = arg0->length * 2 - 64;
    length = 0;
    for (i = 0; i < elements.count; i++)
    {
        unsigned char var5;
        elements.element[i].id = element[0];
        elements.element[i].length = element[1];
        elements.element[i].body = (unsigned char*)&element[2];
        var5 = elements.element[i].length + 2;
        length += var5;
        if (length > maxLength)
        {
            elements.count = 0;
            return elements;
        }
        element += var5;
    }
    return elements;
}
