#include <globaldefs.h>

struct Entry_02028bd0;
extern struct Entry_02028bd0 data_020fdd44;
extern "C" struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

// USA: func_02027ccc
extern "C" ARM struct Entry_02028bd0* func_02027ccc(int key) {
    return ZoneRecords_Find(&data_020fdd44, key);
}
