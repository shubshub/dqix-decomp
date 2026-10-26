
struct Struct_ov008_02186cec {
    unsigned char unknown_0_[0x744];
    unsigned char entries[8];
    unsigned char count;
    unsigned char unknown_74d_[0xb18 - 0x74d];
    unsigned int flags;
};

extern "C" {
    char* Scenario_GetInstance();
    bool Scenario_TestFlag(void*, void*, int);

    void func_ov008_02186cec(Struct_ov008_02186cec* menu) {
        menu->count = 0;
        for (int i = 0; i < 8; ++i)
            menu->entries[i] = 0xff;

        menu->entries[menu->count++] = 0;
        menu->entries[menu->count++] = 1;
        menu->entries[menu->count++] = 2;

        char* state = Scenario_GetInstance();
        if (Scenario_TestFlag(state, state + 0x8c, 0x1198))
            menu->entries[menu->count++] = 3;
        if (menu->flags & 0x2000)
            menu->entries[menu->count++] = 4;
        if (Scenario_TestFlag(state, state + 0x8c, 0x119d))
            menu->entries[menu->count++] = 5;
        if (Scenario_TestFlag(state, state + 0x8c, 0x119b))
            menu->entries[menu->count++] = 6;
        if (menu->flags & 4)
            menu->entries[menu->count++] = 7;
    }
}
