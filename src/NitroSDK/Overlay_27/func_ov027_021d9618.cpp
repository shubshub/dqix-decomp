#include <globaldefs.h>

extern "C" void* func_020d49c4(int, int);
extern "C" void func_ov027_021d9134(void*, int);

extern void* data_ov027_021e33ec;
extern int data_ov027_021dd920;

#pragma optimize_for_size off

// USA: func_ov027_021d9618
extern "C" ARM void func_ov027_021d9618(int p)
{
    unsigned short i = 0;
    do
    {
        char* entry = (char*)data_ov027_021e33ec + i * 0x5d4;
        if (*(unsigned char*)(entry + 0x1d52) != 0)
            *(unsigned short*)(entry + 0x1d4a) = 0;
        i++;
    } while (i < 16);

    data_ov027_021dd920 = 0;

    unsigned short j = 1;
    do
    {
        void* h = func_020d49c4(p, j);
        if (h != NULL)
        {
            unsigned short v = *(unsigned short*)h;
            if (v != 0xffff && v != 0)
                func_ov027_021d9134(h, j);
        }
        j++;
    } while (j <= 15);
}
