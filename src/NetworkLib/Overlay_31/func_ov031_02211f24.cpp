#include <globaldefs.h>

struct Struct_ov031_02211f24
{
    int field0;
    unsigned short state;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    unsigned char unknown_c_;
    char unknown_d_[3];
    unsigned int phase;
    unsigned char payload[0x50];
};
struct Struct_ov031_0224e5b4_6
{
    int error;
    Struct_ov031_02211f24* entry;
};
extern Struct_ov031_0224e5b4_6 data_ov031_0224e5b4;
enum Enum_ov031_02211f24 { Enum_ov031_02211f24_2 = 2 };
extern "C" void func_ov031_02211e08();
extern "C" void func_ov031_02211b08(int, int);
extern "C" int func_ov031_02212fb8();
extern "C" int func_ov031_02207cd0();
extern "C" void func_ov031_022120f8();
extern "C" void func_ov031_02211bd4(Struct_ov031_02211f24*, unsigned short, int, int);
extern "C" int func_ov031_022162f0(void*, void*);

// USA: func_ov031_02211f24
extern "C" ARM int func_ov031_02211f24()
{
    int saved;
    int result;
    unsigned short field;
    Struct_ov031_02211f24* entry;
    Struct_ov031_02211f24* initial = data_ov031_0224e5b4.entry;
    if (initial == NULL) return 0;
    switch (initial->phase)
    {
    case 1: return 2;
    case 2: return 2;
    case 3:
        func_ov031_02211e08();
        func_ov031_02211b08(5, data_ov031_0224e5b4.error);
        data_ov031_0224e5b4.entry->state = 7;
        data_ov031_0224e5b4.entry->phase = 4;
        return 7;
    case 4: return 7;
    case 5: return 5;
    }
    if (initial->state == 1) return initial->state;
    result = func_ov031_02212fb8();
    if (result == 5)
    {
        data_ov031_0224e5b4.entry->state = 4;
        data_ov031_0224e5b4.entry->field6 = 1;
        data_ov031_0224e5b4.entry->unknown_c_ = 1;
        return 4;
    }
    if (result < 0)
    {
        if (result >= -10)
        {
            data_ov031_0224e5b4.entry->unknown_c_ = 1;
            func_ov031_02211b08(9, -50199);
            data_ov031_0224e5b4.entry->state = 8;
            return 8;
        }
        entry = data_ov031_0224e5b4.entry;
        if (!entry->unknown_c_)
        {
            field = entry->field8;
            saved = func_ov031_02207cd0();
            data_ov031_0224e5b4.error = result;
            func_ov031_022120f8();
            func_ov031_02211bd4(entry, field, 1, (unsigned short)saved);
            func_ov031_022162f0(&data_ov031_0224e5b4.entry->payload, (void*)1);
            Enum_ov031_02211f24 status = Enum_ov031_02211f24_2;
            data_ov031_0224e5b4.entry->phase = 1;
            data_ov031_0224e5b4.entry->field0 = 0;
            return status;
        }
        if (data_ov031_0224e5b4.error < result)
            result = data_ov031_0224e5b4.error;
        func_ov031_02211b08(5, result);
        data_ov031_0224e5b4.entry->state = 7;
        return 7;
    }
    return 2;
}
