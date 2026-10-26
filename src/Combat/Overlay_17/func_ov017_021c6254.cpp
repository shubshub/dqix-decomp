#include <globaldefs.h>

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c6254 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
};

struct Struct_ov017_021c6254_2 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_[8];
    unsigned char unknown_a_0_ : 4;
    unsigned char unknown_a_4_ : 4;
    unsigned char unknown_b_[0xd];
};

struct Struct_ov017_021c6254_3 {
    unsigned char unknown_0_[4];
    Struct_ov017_021c6254_2 unknown_4_[1];
};

struct Struct_ov017_021c6254_4 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned char unknown_4_[8];
    unsigned char unknown_c_[4];
};

struct Struct_ov017_021c6254_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021c6254_4 unknown_4_;
};

// USA: func_ov017_021c6254
extern "C" ARM void func_ov017_021c6254(char* self, int slotIndex) {
    void* data = LinkMessageQueue_GetInstance();
    Evt021c6254 evt;
    Payload021c6254* p = &evt.payload;
    evt.tag = 0x62;
    p->id = (*(Sub8e18_021c6254**)(self + 0x8e18))->id;
    Slot021c6254* slot = &((Holder021c6254*)(self + 0x1b0 + 0x8000))->slots[slotIndex];
    p->slotIndex = slotIndex;
    for (int i = 0; i < slot->count; i++) {
        p->values[i] = 0;
        p->values[i] = slot->values[i];
    }
    func_0205e330(var0, &var1, 0);
}
