#include <globaldefs.h>

typedef void (*Type_020c94e4)(void* arg);

struct Struct_020c94e4_2
{
    Type_020c94e4 handler;
    void* arg;
    unsigned long tag;
    unsigned long frame;
    short line;
    short delay;
    Struct_020c94e4_2* prev;
    Struct_020c94e4_2* next;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
};

struct Struct_02111654_5
{
    unsigned short unknown_0_;
    long unknown_4_;
    long unknown_8_;
    Struct_020c94e4_2* head;
    Struct_020c94e4_2* tail;
};

extern Struct_02111654_5 data_02111654;
extern "C" char data_027e0000[];

struct Struct_020c94e4;
struct Struct_020c9384;
struct Struct_020c92d0;

unsigned int DisableSpecificInterrupts(unsigned int flagMask);
unsigned int AcknowledgeSpecificInterrupts(unsigned int flagMask);
extern "C" long func_020c96a8(int line);
extern "C" int func_020c965c(Struct_020c94e4* arg0, int arg1, int arg2);
extern "C" void func_020c9384(Struct_020c9384* arg0);
extern "C" void func_020c92d0(Struct_020c92d0* arg0);
extern "C" void func_020c945c(Struct_020c94e4_2* arg0);

#define DISPSTAT (*(volatile unsigned short*)0x04000004)
#define VCOUNT (*(volatile unsigned short*)0x04000006)

static inline long inline_020c94e4()
{
    return VCOUNT;
}

// USA: func_020c94e4
extern "C" ARM void func_020c94e4()
{
    Struct_020c94e4_2* var0;
    Type_020c94e4 handler;
    long check;
    long var3;
    long var4;

    DisableSpecificInterrupts(4);
    DISPSTAT &= ~0x20;
    *(unsigned int*)((unsigned int)data_027e0000 + 0x3ff8) |= 4;
    unsigned short status = DISPSTAT;
    var3 = ((status >> 8) & 0xff) | ((status << 1) & 0x100);
    var4 = func_020c96a8(var3 - 1);

    if (NULL == (var0 = data_02111654.head))
    {
        return;
    }
    do
    {
        var3 = inline_020c94e4();
        var4 = func_020c96a8(var3);
        check = func_020c965c((Struct_020c94e4*)var0, var4, var3);
        switch (check)
        {
        case 0:
            func_020c945c(var0);
            if (var0->line != inline_020c94e4() || var0->frame != var4)
            {
                return;
            }
            DisableSpecificInterrupts(4);
            DISPSTAT &= ~0x20;
            AcknowledgeSpecificInterrupts(4);
        case 1:
            handler = var0->handler;
            func_020c9384((Struct_020c9384*)var0);
            var0->handler = NULL;
            if (handler)
            {
                handler(var0->arg);
            }
            if (var0->unknown_1c_ && !var0->unknown_24_)
            {
                var0->handler = handler;
                var0->frame = data_02111654.unknown_8_ + 1;
                func_020c92d0((Struct_020c92d0*)var0);
            }
            break;
        case 2:
            func_020c9384((Struct_020c9384*)var0);
            var0->frame = data_02111654.unknown_8_ + 1;
            func_020c92d0((Struct_020c92d0*)var0);
            break;
        }
    } while (NULL != (var0 = data_02111654.head));
}
