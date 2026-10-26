#include <globaldefs.h>


// USA: func_ov023_021df218

struct Struct_ov023_021db45c;

extern "C" void WindowPane_Init(void* buf);
extern "C" int func_ov023_021ddc34(void* obj, short a, short b, short c, short d);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int flags, unsigned char* flags2, int id);
extern "C" int func_020dd19c(unsigned int a, int b);
extern "C" void func_ov023_021e29b8(void* a, int b, unsigned char v);
extern "C" void* func_ov023_021e2550(void* obj, int unused, int index);
extern "C" void func_ov023_021db45c(void* obj, struct Struct_ov023_021db45c* p1, int p2, short* p3, short* p4);
extern "C" void func_ov023_021e257c(void* obj);
extern "C" void* func_ov023_021db544(void* a, void* b, int c, int d);
extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern "C" unsigned short* func_ov023_021db2b8(signed char screen, int arg1);
void CleanInvalidateCacheRange(void const*, unsigned int);
extern "C" void func_ov023_021e2bdc(void* a, int unused, short* out1, short* out2);

struct Struct_ov023_021ff9e0_12 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    void* f20;
};

extern "C" Struct_ov023_021ff9e0_12 data_ov023_021ff9e0;
extern "C" const unsigned char data_ov023_021fd626[];
extern "C" const short data_ov023_021fd64c[];
extern "C" const short data_ov023_021fd634[];

struct Struct_ov023_021df218 {
    unsigned int f0 : 7;
    unsigned int sel : 4;
    unsigned int f1 : 21;
    unsigned int flags : 12;
    unsigned int f2 : 20;
};

struct Struct_ov023_021df218_2 {
    int unk_0;
    void* canvas_;
    char pad8[0x12 - 8];
    short unk_12;
};

struct Struct_ov023_021df218_3 {
    char pad[0x16];
    unsigned char flags;
};

struct Struct_ov023_021df218_4 {
    char pad0[0x4c];
    int* node;
    char unknown_50_[0xcc - 0x50];
    Struct_ov023_021df218_2 list;
    char unknown_e0_[0x75c - 0xe0];
    int pos;
};

extern "C" ARM void func_ov023_021df218(Struct_ov023_021df218_4* self)
{
    char buf[0xe0];
    unsigned char flags[14];
    short y;
    short x;
    unsigned short t;
    short p1;
    short p0;
    int len;
    int mask;
    short a0;
    unsigned short* base;

    WindowPane_Init(buf);
    if (!func_ov023_021ddc34(buf, 0, 0, 7, 0x10))
        return;

    mask = 0;
    {
        unsigned char i;
        unsigned char j;
        int cur;
        unsigned int one = 1;
        struct Struct_ov023_021df218* var15 = (struct Struct_ov023_021df218*)self->node[0];

        if (var15 != NULL)
        {
            Struct_ov023_021df218_3* e = (Struct_ov023_021df218_3*)func_ov023_021db4e4(&self->list, 0x1b);
            if (e)
                e->flags |= 1;

            memcpy(flags, data_ov023_021fd626, 0xd);

            {
                void* f = Scenario_GetInstance();
                for (j = 7; j < 0xd; j++)
                {
                    if (Scenario_TestFlag((int)f, (unsigned char*)f + 0x8c, 0x113f + j))
                        flags[j] = 1;
                }
            }

            i = 1;
            j = 0;
            for (; i < 0xd; j++, i++)
            {
                if (flags[i] != 0)
                {
                    cur = 0xe;
                    if (var15->sel != 0)
                    {
                        if (func_020dd19c(i, var15->sel & 0xff) != 0)
                            cur = 0xf;
                    }
                    else
                    {
                        if (var15->flags & ((unsigned short)(one << j)))
                            cur = 0xf;
                    }
                    if (cur == 0xe)
                        mask |= 1 << j;
                    {
                        short v = data_ov023_021fd64c[j];
                        func_ov023_021e29b8(&self->list, v, 3);
                        func_ov023_021e2550(&self->list, v, i);
                    }
                }
            }

            func_ov023_021db45c(&self->list, (struct Struct_ov023_021db45c*)buf, 0x1b, &x, &y);
            if (data_ov023_021ff9e0.f4 != 0)
            {
                self->list.canvas_ = buf;
                self->list.unk_12 = 1;
                func_ov023_021e257c(&self->list);
            }
            func_ov023_021db544(&self->list, (void*)0x1b, x, y);
            e = (Struct_ov023_021df218_3*)func_ov023_021db4e4(&self->list, 0x1b);
            if (e)
                e->flags &= ~1;
        }
    }

    len = func_ov023_021ddc98(buf, self->pos, (unsigned short)data_ov023_021ff9e0.f10, 0);

    if (&self->list != (Struct_ov023_021df218_2*)0)
    {
        base = func_ov023_021db2b8(*(signed char*)((char*)data_ov023_021ff9e0.f20 + 0x77c), 0);
        if (base != NULL)
        {
            int b;
            int var20;
            int a;
            int var22;
            int k;
            for (k = 0; k < 0xc; k++)
            {
                if (mask & (1 << k))
                {
                    int off;

                    p0 = 0;
                    p1 = 0;
                    func_ov023_021e2bdc(&self->list, data_ov023_021fd634[k], &p0, &p1);
                    a0 = p0 >> 3;
                    b = p1 >> 3;
                    p0 = (short)a0;
                    p1 = (short)b;

                    for (var20 = 0; var20 < 2; var20++)
                    {
                        unsigned short* row = (unsigned short*)((char *)base + (b << 6));
                        a = a0;
                        for (var22 = 0; var22 < 2; var22++)
                        {
                            off = a << 1;
                            t = (short)(*(unsigned short*)((char*)row + off) & 0xfff);
                            t |= 0x1000;
                            CleanInvalidateCacheRange(&t, 2);
                            *(unsigned short*)((char*)row + off) = t;
                            a = a + 1;
                        }
                        b = b + 1;
                    }
                }
            }
        }
    }

    self->pos = self->pos + len;
}
