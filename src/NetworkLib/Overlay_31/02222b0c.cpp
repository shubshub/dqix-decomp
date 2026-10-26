struct Struct_ov031_02222b0c { unsigned int word0; unsigned short unknown_4_; unsigned short pad6; };
struct Struct_ov031_02222b0c_2 {
    void* callback;
    Struct_ov031_02222b0c* field4;
    unsigned char byte8;
    unsigned char byte9;
    unsigned char pad[2];
};
extern Struct_ov031_02222b0c_2* data_ov031_02250ba4;
extern const unsigned char data_ov031_02248910[];
extern "C" void* func_ov031_0223cf4c(unsigned int, int);
extern "C" int func_ov031_0223be44(int, int);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);
extern "C" void func_ov031_02222c18(void);

// USA: func_ov031_02222b0c
extern "C" void func_ov031_02222b0c(int kind) {
    data_ov031_02250ba4 = (Struct_ov031_02222b0c_2*)func_ov031_0223cf4c(12, 4);
    data_ov031_02250ba4->byte8 = kind;
    data_ov031_02250ba4->field4 = (Struct_ov031_02222b0c*)func_ov031_0223be44(0, 0x47);
    unsigned char type = data_ov031_02248910[kind];
    data_ov031_02250ba4->field4->unknown_4_ = (data_ov031_02250ba4->field4->unknown_4_ & ~0xc00) | 0x400;
    Struct_ov031_02222b0c* entry = data_ov031_02250ba4->field4;
    entry->word0 &= ~0xc00;
    entry->unknown_4_ = (entry->unknown_4_ & ~0xf000) | (type << 12);
    data_ov031_02250ba4->field4->word0 = (data_ov031_02250ba4->field4->word0 & 0xfe00ff00) | 0x8b | 0xe60000;
    data_ov031_02250ba4->callback = func_ov031_0223e218((void*)1, (void*)func_ov031_02222c18, 0, 0x78);
}
