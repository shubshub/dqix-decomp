#include <globaldefs.h>

struct Struct_0207f0ac_2 {
    short* entries;
    char unknown_4_[0xc];
    short width;
    unsigned char unknown_12_;
    unsigned char count;
    char unknown_14_[4];
};
struct Struct_0207f6ac {
    char unknown_0_[8];
    short x;
    short y;
    short width;
    char unknown_e_[0x22];
};
struct Struct_0207f0ac { Struct_0207f0ac_2* entries; short count; };
struct Struct_0207f524 { Struct_0207f6ac* entries; short count; };
struct Struct_0207fdcc_2 {
    void* table;
    Struct_0207f524 items;
    Struct_0207f0ac groups;
};
extern "C" Struct_0207f0ac_2* func_0207f0ac(Struct_0207f0ac*, int);
extern "C" Struct_0207f6ac* func_0207f6ac(Struct_0207f524*, int);
extern "C" int func_020813ec(void*, int);
extern "C" void func_0207fdcc(Struct_0207fdcc_2*, int);

// USA: func_02081224
extern "C" ARM void func_02081224(Struct_0207fdcc_2* object, int id) {
    int ids[8];
    int positions[8];
    int widths[8];
    Struct_0207f0ac_2* group = func_0207f0ac(&object->groups, id);
    if (!group) return;
    func_020813ec(object, id);
    int count = 0;
    int total = group->count;
    int i = 0;
    for (; i < total; i++) {
        int entryId = group->entries[i];
        Struct_0207f6ac* entry = func_0207f6ac(&object->items, entryId);
        if (entry) {
            ids[count] = entryId;
            positions[count] = entry->x;
            widths[count] = entry->width;
            count++;
        }
    }
    if (count <= 1) return;
    for (int first = 0; first < count - 1; first++) {
        for (int second = first + 1; second < count; second++) {
            if (positions[second] < positions[first]) {
                int position = positions[first];
                positions[first] = positions[second];
                int entryId = ids[first];
                int width = widths[first];
                ids[first] = ids[second];
                ids[second] = entryId;
                positions[second] = position;
                widths[first] = widths[second];
                widths[second] = width;
            }
        }
    }
    int var14 = 0;
    for (int index = 0; index < count; index++) var14 += widths[index];
    int var16 = group->width * 8;
    if (var16 <= var14) return;
    int var17 = var16 - var14;
    int spacing = var17 / (count - 1);
    int var19 = var17 % (count - 1);
    while (var19 < 12) {
        var19 += count - 1;
        spacing--;
    }
    int position = var19 >> 1;
    for (int index = 0; index < count; index++) {
        Struct_0207f6ac* entry = func_0207f6ac(&object->items, (short)ids[index]);
        if (entry) {
            entry->x = position;
            position += spacing + entry->width;
        }
    }
    func_0207fdcc(object, id);
}
