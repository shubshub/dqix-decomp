#include <globaldefs.h>

extern "C" int GetInventoryItemByID(void* obj);

struct ItemTable;
struct Element020de650;
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);

#if defined(jpn)
#define CONTAINER_02157500 0x750
#else
#define CONTAINER_02157500 0x3ec + 0x400
#endif

// USA: func_ov002_02157500
extern "C" ARM int func_ov002_02157500(char* obj, int, int) {
    int invId = GetInventoryItemByID(obj);
    if (invId < 0) {
        return 0;
    }
    struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(obj + CONTAINER_02157500), invId);
    if (elem != NULL) {
        unsigned int v = *(unsigned int*)((char*)elem + 8);
        return (int)((v << 16) >> 30);
    }
    return 0;
}
