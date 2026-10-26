#include <globaldefs.h>

extern const unsigned long data_020ee278[256];

extern "C"
{
    unsigned long func_01ff85f0(unsigned char arg0, unsigned long arg1);

    unsigned long func_01ff85b8(const unsigned char* data, unsigned long length)
    {
        unsigned long var0 = 0xffffffff;
        if (data != NULL)
        {
            for (; length != 0; length--)
                var0 = func_01ff85f0(*data++, var0);
        }
        return ~var0;
    }

    unsigned long func_01ff85f0(unsigned char arg0, unsigned long arg1)
    {
        return data_020ee278[(arg1 ^ arg0) & 0xff] ^ (arg1 >> 8);
    }

    unsigned long func_01ff860c(const unsigned char* string)
    {
        unsigned long var0 = 0xffffffff;
        if (string != NULL)
        {
            for (; *string != '\0'; string++)
                var0 = func_01ff85f0(*string, var0);
        }
        return ~var0;
    }
}
