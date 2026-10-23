#include <globaldefs.h>

struct Struct_02020cb8 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned short unknown_e_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;

    unsigned char inline_ov023_021f7b98() { return unknown_1c_0_; }
    unsigned char inline_ov023_021f7b98_2() { return unknown_1c_4_; }
    void inline_ov023_021f7b98_3(unsigned char arg0) { unknown_1c_0_ = arg0; }
    void inline_ov023_021f7b98_4(unsigned char arg0) { unknown_1c_4_ = arg0; }
};
void Background_Init(struct List0204af64* obj);

struct ActiveEntry02046900;
int Pac_CountFiles(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

void Background_FlushFile(void* obj, char* str);

struct SelfTag0204b3a0;
void Background_UploadFile(struct SelfTag0204b3a0* self, char* str);

struct Struct_ov023_021f7b98 {
#if defined(jpn)
    char unknown1_0_[0x24];
#else
    char unknown_0_[0x28];
#endif
    struct Struct_02020cb8 unknown_28_;
};

// USA: func_ov023_021f7b98
extern "C" ARM void func_ov023_021f7b98(struct Struct_ov023_021f7b98* arg0, void* arg1, int arg2, struct Struct_02020aec* arg3, unsigned int arg4) {
    int var0;
    void* var1;
    struct Struct_02020cb8 var2;

    if (arg3 == 0 || arg4 == 0) {
        return;
    }
    int count = Pac_CountFiles((struct ActiveEntry02046900*)entry);
    for (int i = 0; i < count; i++) {
        char* rec = (char*)Pac_GetFile(entry, i, &rp, &size);
        if (rec) {
            Background_Init(&list);
            list.SetLo(self->list.GetLo());
            list.SetHi(self->list.GetHi());
            if (useTag) {
                Background_FlushFile(&list, rec);
            } else {
                Background_UploadFile((struct SelfTag0204b3a0*)&list, rec);
            }
        }
    }
}
