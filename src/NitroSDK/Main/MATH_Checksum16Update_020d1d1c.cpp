#include <globaldefs.h>

// Main, originally func_020d1d1c (USA 0x020d1d1c, EUR 0x020d1d2c, JPN 0x020d37e8)
extern "C" ARM void MATH_Checksum16Update(unsigned short* context, const void* input, unsigned long length)
{
    int swapped = false;
    unsigned long sum = 0;
    const unsigned char* data = (const unsigned char*)input;
    unsigned long n;
    unsigned long blocks;

    if ((unsigned long)data & 1)
    {
        sum += *data++ << 8;
        length--;
        swapped = true;
    }

    blocks = length >> 17;
    if (blocks != 0)
    {
        do
        {
            n = 0x10000;
            blocks--;
            length -= 0x20000;
            do
            {
                sum += *(const unsigned short*)data;
                data += 2;
            } while (--n != 0);
            sum = (sum >> 16) + (sum & 0xffff);
            sum = (unsigned short)(sum + (sum >> 16));
        } while (blocks != 0);
    }

    n = length >> 1;
    if (n != 0)
    {
        do
        {
            sum += *(const unsigned short*)data;
            data += 2;
        } while (--n != 0);
    }
    if (length & 1)
    {
        sum += *data;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum = (sum >> 16) + (sum & 0xffff);
    if (swapped)
    {
        sum = ((sum << 24) | (sum << 8)) >> 16;
    }

    sum += *context;
    sum += sum >> 16;
    *context = (unsigned short)sum;
}
