// USA: func_0205aed0
extern "C" void func_0205aed0(void* a, char* b, unsigned int c, int d)
{
    if (b != 0) {
        unsigned short i = 0;
        while (i < c) {
            unsigned char* q = (unsigned char*)(b + i * 0x28);
            q[0x22] = (unsigned char)(q[0x22] + d);
            q[0x22] &= 0x7f;
            i = i + 1;
        }
    }
}
