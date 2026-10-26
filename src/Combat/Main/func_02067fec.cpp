#include <globaldefs.h>

struct Entry0204254c
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
    unsigned int active_ : 1;
    unsigned int unknown_3_7_ : 1;
};
struct Struct_02067fec_2
{
    char unknown_0_[8];
    Struct_02067fec flags_;
};
extern "C" Entry0204254c* Font_FindCharacter(int, int);
extern "C" int func_02067f9c(Struct_02067fec_2*, int, int);

// USA: func_02067fec
extern "C" ARM int func_02067fec(Struct_02067fec_2* state, signed char* address, int table)
{
    if (state && !state->flags_.active_)
        return state->flags_.unknown_3_4_;
    signed char* key = address;
    Entry0204254c* entry = Font_FindCharacter((int)key, table);
    if (entry)
    {
        if (entry->unknown_5_6_)
            return 1;
        int type = *key;
        key += entry->unknown_5_0_;
        if (type == 'h')
        {
            entry = Font_FindCharacter((int)key, table);
            if (entry && entry->unknown_5_6_)
                return !func_02067f9c(state, (int)(key + entry->unknown_5_0_), table);
        }
        else if (type == 'y')
            return !func_02067f9c(state, (int)key, table);
    }
    return 0;
}
