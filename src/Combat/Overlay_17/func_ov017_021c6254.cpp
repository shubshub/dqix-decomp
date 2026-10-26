#include <globaldefs.h>

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6254 {
    unsigned char pad0[8];
    unsigned short id;
};

struct Struct_ov017_021c6254_2 {
    unsigned char pad0[2];
    unsigned char values[8];
    unsigned char count : 4;
    unsigned char flags : 4;
    unsigned char unknown_b_[0xd];
};

struct Struct_ov017_021c6254_3 {
    unsigned char pad0[4];
    Struct_ov017_021c6254_2 slots[1];
};

struct Struct_ov017_021c6254_4 {
    unsigned short id;
    unsigned short slotIndex;
    unsigned char values[8];
    unsigned char unknown_c_[4];
};

struct Struct_ov017_021c6254_5 {
    unsigned char tag;
    unsigned char pad1[3];
    Struct_ov017_021c6254_4 payload;
};

// USA: func_ov017_021c6254
extern "C" ARM void func_ov017_021c6254(char* self, int slotIndex) {
    void* data = LinkMessageQueue_GetInstance();
    Struct_ov017_021c6254_5 evt;
    Struct_ov017_021c6254_4* p = &evt.payload;
    evt.tag = 0x62;
    p->id = (*(Struct_ov017_021c6254**)(self + 0x8e18))->id;
    Struct_ov017_021c6254_2* slot = &((Struct_ov017_021c6254_3*)(self + 0x1b0 + 0x8000))->slots[slotIndex];
    p->slotIndex = slotIndex;
    for (int i = 0; i < slot->count; i++) {
        p->values[i] = 0;
        p->values[i] = slot->values[i];
    }
    func_0205e330(data, &evt, 0);
}
