#ifndef COMBAT_WORK_RECORD_H
#define COMBAT_WORK_RECORD_H

struct Struct_0206bf2c {
    unsigned char field0;
    unsigned char pad1;
    unsigned short field2;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
    unsigned char unknown_7_;
    unsigned char field8;
    unsigned char unknown_9_;
    unsigned char unknown_a_0_ : 2;
    unsigned char unknown_a_2_ : 1;
    unsigned char unknown_a_3_ : 3;
    unsigned char unknown_a_6_ : 1;
    unsigned char unknown_a_7_ : 1;
    unsigned char fieldB;
    unsigned int fieldC;
    union {
        unsigned char pad10[0xc];
        int vec[3];
    };
    unsigned short field1c;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned short field20;
    unsigned char unknown_22_[2];
    unsigned char pad24[0x10];
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned short field44;
    short unknown_46_;
    unsigned char unknown_48_[0xc];
    unsigned int field54;
    unsigned int unknown_58_;
    unsigned int unknown_5c_;
    unsigned int field60;
    Struct_0206bf2c *unknown_64_;
    Struct_0206bf2c *field68;
    Struct_0206bf2c *unknown_6c_;
    Struct_0206bf2c *unknown_70_;
};

extern "C" void func_0206bf2c(Struct_0206bf2c *obj);
extern "C" void func_0206db48(void *receiver, Struct_0206bf2c *record);

#endif
