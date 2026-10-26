#include <globaldefs.h>

extern "C" unsigned char* LootPointList_GetInstance(unsigned char* obj);

#if defined(jpn)
enum { FIELD_BYTE_OFFSET = 0xa7a };
#else
enum { FIELD_BYTE_OFFSET = 0xcda };
#endif

// USA: func_020120d4
extern "C" ARM void func_020120d4(unsigned char* gameState, unsigned char value) {
    unsigned char* bytes = gameState + 0x5000;
    bytes[FIELD_BYTE_OFFSET] = value;
    unsigned char* lootPoints = LootPointList_GetInstance(bytes);
    lootPoints[0xa] = 0;
}
