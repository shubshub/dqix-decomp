#include <globaldefs.h>

struct Struct_ov000_0217a8f4_2 {
    char pad0[0xac];
    short x;
    short y;
    char unknown_b0_[0xc4 - 0xb0];
    unsigned char key;
    char unknown_c5_[0xe0 - 0xc5];
};

struct Struct_0205d81c {
    char pad0[0xfc];
    Struct_ov000_0217a8f4_2 slots[7];
};

struct Struct_ov000_0217a8f4 {
    char pad0[0x44];
    int posX;
    int unknown_48_;
};

struct Struct_ov000_0217a8f4_3 {
    char pad0[0x17c];
    int elementId;
    char unknown_180_[0x188 - 0x180];
    Struct_0205d81c elems;
};

struct Struct_ov000_02183548 {
    short key;
    short x;
    short y;
};

struct Struct_ov000_021834d4 {
    unsigned char a;
    unsigned char b;
};

extern Struct_ov000_02183548 data_ov000_02183548[];
extern Struct_ov000_021834d4 data_ov000_021834d4[];

extern "C" Struct_ov000_0217a8f4* func_ov000_02161318(Struct_ov000_0217a8f4_3* obj, int id);
extern "C" void func_ov000_02176210(Struct_0205d81c* elems, int keyA, int arg2);
extern "C" void func_0205d904(unsigned char* obj);

// USA: func_ov000_0217a8f4
extern "C" ARM void func_ov000_0217a8f4(Struct_ov000_0217a8f4_3* obj) {
    Struct_ov000_0217a8f4* e = func_ov000_02161318(obj, obj->elementId);
    if (e == 0) {
        return;
    }
    int posX = e->posX;
    int var2 = e->unknown_48_;
    Struct_ov000_0217a8f4_2* slot;
    int i;
    for (i = 0; i < 7; i++) {
        slot = &obj->elems.slots[i];
        int key = slot->key;
        int j;
        for (j = 0; data_ov000_02183548[j].key > 0; j++) {
            if (key == data_ov000_02183548[j].key) {
                slot->x = data_ov000_02183548[j].x + (posX >> 3);
                slot->y = data_ov000_02183548[j].y + (var2 >> 3);
                break;
            }
        }
    }
#if defined(jpn)
    func_ov000_02176210(&obj->elems, 7, 33);
    func_ov000_02176210(&obj->elems, 15, 34);
    func_ov000_02176210(&obj->elems, 16, 35);
    func_ov000_02176210(&obj->elems, 17, 36);
    func_ov000_02176210(&obj->elems, 21, 22);

#else
    Struct_ov000_021834d4* link = data_ov000_021834d4;
    while (true) {
        if (link->a == 0xff) {
            break;
        }
        func_ov000_02176210(&obj->elems, link->a, link->b);
        link++;
    }

#endif
    func_0205d904((unsigned char*)&obj->elems);
}
