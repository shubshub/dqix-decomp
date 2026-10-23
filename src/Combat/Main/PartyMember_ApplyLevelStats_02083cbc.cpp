#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"

struct Struct_02083cbc {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 10;
    unsigned int unknown_3_6_ : 2;
};

struct Struct_02083cbc_2 {
    unsigned char unknown_0_[8];
    Struct_02083cbc unknown_8_[3];
};

struct Struct_02083cbc_3 {
    unsigned char unknown_0_[IS_JPN ? 0x884 : 0x91c];
    Struct_02083cbc unknown_91c_[3];
    unsigned char unknown_928_[0xc];
    unsigned char unknown_934_[0x16];
};

// Main, originally func_02083cbc (USA 0x02083cbc, EUR 0x02083ccc, JPN 0x020845d4)
extern "C" ARM void PartyMember_ApplyLevelStats(void* dst, void* src, void* tail) {
    ((PackedDestination02083cbc*)dst)->triples[0].fieldA = ((PackedSource02083cbc*)src)->triples[0].fieldA;
    ((PackedDestination02083cbc*)dst)->triples[0].fieldB = ((PackedSource02083cbc*)src)->triples[0].fieldB;
    ((PackedDestination02083cbc*)dst)->triples[0].fieldC = ((PackedSource02083cbc*)src)->triples[0].fieldC;
    ((PackedDestination02083cbc*)dst)->triples[1].fieldA = ((PackedSource02083cbc*)src)->triples[1].fieldA;
    ((PackedDestination02083cbc*)dst)->triples[1].fieldB = ((PackedSource02083cbc*)src)->triples[1].fieldB;
    ((PackedDestination02083cbc*)dst)->triples[1].fieldC = ((PackedSource02083cbc*)src)->triples[1].fieldC;
    ((PackedDestination02083cbc*)dst)->triples[2].fieldA = ((PackedSource02083cbc*)src)->triples[2].fieldA;
    ((PackedDestination02083cbc*)dst)->triples[2].fieldB = ((PackedSource02083cbc*)src)->triples[2].fieldB;
    ((PackedDestination02083cbc*)dst)->triples[2].fieldC = ((PackedSource02083cbc*)src)->triples[2].fieldC;
    memset(((PackedDestination02083cbc*)dst)->tail, 100, 0x16);
    if (tail != NULL) {
        for (int i = 0; i < 0x16; i++) {
            ((PackedDestination02083cbc*)dst)->tail[i] = ((unsigned char*)tail)[i];
        }
    }
}
