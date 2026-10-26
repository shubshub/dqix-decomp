#define reg_CARD_MASTERCNT (*(volatile unsigned char*)0x040001a1)
#define reg_CARD_CMD (*(volatile unsigned char*)0x040001a8)
#define reg_CARD_CNT (*(volatile unsigned int*)0x040001a4)
#define reg_CARD_DATA (*(volatile unsigned int*)0x04100010)

#define HW_ROM_HEADER_BUF 0x027ffe00

enum
{
    Enum_01ff83a8_0 = 0x00,
    Enum_01ff83a8_128 = 0x80,
    Enum_01ff83a8_183 = 0xb7,
    Enum_01ff83a8_117440512 = 0x07000000,
    Enum_01ff83a8_16777216 = 0x01000000,
    Enum_01ff83a8_0_2 = 0x00000000,
    Enum_01ff83a8_536870912 = 0x20000000,
    Enum_01ff83a8_2147483648 = 0x80000000,
    Enum_01ff83a8_8388608 = 0x00800000
};

// USA: func_01ff83a8
extern "C" void func_01ff83a8(unsigned int src, void* dst, int len)
{
    unsigned int* const var0 = (unsigned int*)(HW_ROM_HEADER_BUF + 0x60);

    const unsigned int var1 = (unsigned int)((*var0 & ~Enum_01ff83a8_117440512)
        | (Enum_01ff83a8_16777216 | Enum_01ff83a8_0_2 | Enum_01ff83a8_2147483648 | Enum_01ff83a8_536870912));

    int pos = -(int)(src & 511);

    while (reg_CARD_CNT & Enum_01ff83a8_2147483648)
    {
    }
    reg_CARD_MASTERCNT = (unsigned int)(Enum_01ff83a8_0 | Enum_01ff83a8_128);

    for (src = (unsigned int)(src + pos); pos < len; src += 512)
    {
        (&reg_CARD_CMD)[0] = (unsigned char)(Enum_01ff83a8_183);
        (&reg_CARD_CMD)[1] = (unsigned char)(src >> 24);
        (&reg_CARD_CMD)[2] = (unsigned char)(src >> 16);
        (&reg_CARD_CMD)[3] = (unsigned char)(src >> 8);
        (&reg_CARD_CMD)[4] = (unsigned char)(src >> 0);
        (&reg_CARD_CMD)[5] = 0;
        (&reg_CARD_CMD)[6] = 0;
        (&reg_CARD_CMD)[7] = 0;

        reg_CARD_CNT = var1;
        for (;;)
        {
            unsigned int ctrl = reg_CARD_CNT;

            if ((ctrl & Enum_01ff83a8_8388608))
            {
                const unsigned int data = reg_CARD_DATA;

                if ((pos >= 0) && (pos < len))
                {
                    *(unsigned int*)((unsigned int)dst + pos) = data;
                }

                pos += sizeof(unsigned int);
            }

            if (!(ctrl & Enum_01ff83a8_2147483648))
            {
                break;
            }
        }
    }
}
