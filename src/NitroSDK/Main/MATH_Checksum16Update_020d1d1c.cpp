#include <globaldefs.h>

// Main, originally func_020d1d1c (USA 0x020d1d1c, EUR 0x020d1d2c, JPN 0x020d37e8)
extern "C" ARM void MATH_Checksum16Update(unsigned short* context, const void* input, unsigned long length)
{
    int var0 = false;
    unsigned long var1 = 0;
    const unsigned char* var2 = (const unsigned char*)arg1;
    unsigned long var3;
    unsigned long var4;

    if ((unsigned long)var2 & 1)
    {
        var1 += *var2++ << 8;
        arg2--;
        var0 = true;
    }

    var4 = arg2 >> 17;
    if (var4 != 0)
    {
        do
        {
            var3 = 0x10000;
            var4--;
            arg2 -= 0x20000;
            do
            {
                var1 += *(const unsigned short*)var2;
                var2 += 2;
            } while (--var3 != 0);
            var1 = (var1 >> 16) + (var1 & 0xffff);
            var1 = (unsigned short)(var1 + (var1 >> 16));
        } while (var4 != 0);
    }

    var3 = arg2 >> 1;
    if (var3 != 0)
    {
        do
        {
            var1 += *(const unsigned short*)var2;
            var2 += 2;
        } while (--var3 != 0);
    }
    if (arg2 & 1)
    {
        var1 += *var2;
    }

    var1 = (var1 >> 16) + (var1 & 0xffff);
    var1 = (var1 >> 16) + (var1 & 0xffff);
    if (var0)
    {
        var1 = ((var1 << 24) | (var1 << 8)) >> 16;
    }

    var1 += *arg0;
    var1 += var1 >> 16;
    *arg0 = (unsigned short)var1;
}
