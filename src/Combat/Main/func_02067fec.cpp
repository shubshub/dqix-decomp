#include <globaldefs.h>

struct Struct_0204254c
{
    char unknown_0_[5];
    signed char unknown_5_0_ : 6;
    signed char unknown_5_6_ : 1;
    signed char unknown_5_7_ : 1;
};
struct Struct_02067fec
{
    unsigned int unknown_0_0_ : 28;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 1;
    unsigned int unknown_3_6_ : 1;
    unsigned int unknown_3_7_ : 1;
};
struct Struct_02067fec_2
{
    char unknown_0_[8];
    Struct_02067fec unknown_8_;
};
Entry0204254c* Font_FindCharacter(int, int);
extern "C" int func_02067f9c(State02067fec*, int, int);

// USA: func_02067fec
extern "C" ARM int func_02067fec(Struct_02067fec_2* arg0, signed char* arg1, int arg2)
{
    if (state && !state->flags_.active_)
        return state->flags_.fallback_;
    signed char* key = address;
    Entry0204254c* entry = Font_FindCharacter((int)key, table);
    if (entry)
    {
        if (var1->unknown_5_6_)
            return 1;
        int var2 = *var0;
        var0 += var1->unknown_5_0_;
        if (var2 == 'h')
        {
            entry = Font_FindCharacter((int)key, table);
            if (entry && entry->terminal_)
                return !func_02067f9c(state, (int)(key + entry->offset_), table);
        }
        else if (var2 == 'y')
            return !func_02067f9c(arg0, (int)var0, arg2);
    }
    return 0;
}
