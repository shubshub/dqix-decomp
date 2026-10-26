#include <globaldefs.h>

struct Struct_ov023_021f6c90
{
    void* unknown_0_;
    int task_;
    unsigned int slots_[2][4];
};

// USA: func_ov023_021f6c90
extern "C" ARM int func_ov023_021f6c90(Struct_ov023_021f6c90* self, int set, unsigned int count)
{
    for (int start = 0; start < 0x80; start++)
    {
        int var1 = 1;
        unsigned int slot = start;
        for (unsigned short i = 0; i < count; i++)
        {
            int index = slot >> 2;
            int bit = slot & 3;
            if (self->slots_[set][index] & (1 << bit))
            {
                var1 = 0;
                break;
            }
            slot++;
        }
        if (var1)
            return start;
    }
    return -1;
}
