#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern int data_ov003_02180cb8;
extern int data_ov003_0217ff40;

// Overlay 3, originally func_ov003_0215e6f8 (USA/EUR 0x0215e6f8; JPN not identified)
extern "C" ARM void KeyboardLayout_Load(int handler0, int handler1, struct StreamHeader* buffer, int length) {
    char local[0x430];
    *(int*)((char*)&data_ov003_02180cb8 + 4) = handler0;
    *(int*)&data_ov003_02180cb8 = handler1;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov003_0217ff40);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();
}
