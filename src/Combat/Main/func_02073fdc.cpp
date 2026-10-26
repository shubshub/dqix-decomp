#include <globaldefs.h>

extern "C" int RandomIntBelow(int upperBound);

struct Struct_02073fdc_2 {
    unsigned short id : 12;
    unsigned short weight : 3;
    unsigned short flag : 1;
    unsigned short field2;
};
struct Struct_02073fdc {
    unsigned short field0;
    unsigned short count;
    unsigned int field4;
    Struct_02073fdc_2 entries[];
};
// USA: func_02073fdc
extern "C" ARM int func_02073fdc(void* data) {
    Struct_02073fdc* table = (Struct_02073fdc*)data;
    int total = 0;
    for (int i = 0; i < table->count; ++i) {
        total += table->entries[i].weight;
    }
    int selected = RandomIntBelow(total);
    int result = -1;
    int var5 = 0;
    for (int j = 0; j < table->count; ++j) {
        var5 += table->entries[j].weight;
        if (selected < var5) {
            result = table->entries[j].id;
            break;
        }
    }
    return result;
}
