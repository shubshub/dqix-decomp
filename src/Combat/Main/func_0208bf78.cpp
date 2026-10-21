#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Combat/ScriptElementList.h"
#include "Resource/CharacterCreationUI.h"
#include "std_library_functions.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_0208b9a0;
struct Struct_02013fb4;
struct Struct_02020cb8_4;
struct Struct_02020aec;
struct Struct_0208bf78_5;
struct Struct_0205faf4_3;
struct Struct_0205faf4_4;
struct Struct_0205faf4_7;
struct Struct_02015438;
struct Struct_02020cb8;
struct Struct_02020cb8_5;
struct Struct_02020cb8_6;

struct Struct_0208bf78_6 {
    unsigned int unknown_0_0_ : 7;
    unsigned int unknown_0_7_ : 4;
    unsigned int unknown_1_3_ : 5;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 6;
};

struct Struct_02065990_3 {
    unsigned char unknown_0_[0x178];
    Struct_0208bf78_6 unknown_178_[204];
    unsigned char unknown_4a8_[0x20];
};

struct Struct_0208bf78_7 {
    unsigned int unknown_0_0_ : 16;
    unsigned int unknown_2_0_ : 1;
    unsigned int unknown_2_1_ : 15;
    unsigned short unknown_4_[2];
    unsigned short unknown_8_;
    unsigned short unknown_a_[3];
};

struct Struct_020465c0 {
    unsigned char unknown_0_[0x60];
    char* unknown_60_;
};

struct Struct_0208bf78 {
    unsigned char unknown_0_[0x1c];
    short unknown_1c_;
    short unknown_1e_;
    unsigned char unknown_20_[8];
    short unknown_28_;
    short unknown_2a_;
    unsigned char unknown_2c_[0x28];
};

struct Struct_0208bf78_2 {
    unsigned char unknown_0_[8];
    char* unknown_8_;
    unsigned char unknown_c_[0x80];
    Struct_0208bf78 unknown_8c_;
};

struct Struct_0208bf78_3 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

struct Struct_02000c9c_25 {
    unsigned char unknown_0_[0x28];
    SafeAllocator unknown_28_;
    SafeAllocator* inline_0208bf78() { return &unknown_28_; }
};

struct Struct_0208bf78_4 {
    Struct_02000c9c_25* unknown_0_;
    Struct_0201099c_3 unknown_4_;
    unsigned char unknown_c_[0x10];
    Struct_0208d550 unknown_1c_;
    unsigned char unknown_2c_[0x90];
    int unknown_bc_;
    unsigned char unknown_c0_[0x12];
    short unknown_d2_;
    unsigned char unknown_d4_;
    unsigned char unknown_d5_;
    unsigned char unknown_d6_;
    unsigned char unknown_d7_[3];
    unsigned short unknown_da_;
    unsigned char unknown_dc_;
    unsigned char unknown_dd_;
    unsigned char unknown_de_;
    unsigned char unknown_df_;
};

void ForwardInitStreamHeader0208d854(StreamHeader0208d82c*);
GetTableByteOrFFData* GetGlobal02109418_02094d6c();
unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
int RunBufferedScript02095870(void*, StreamHeader*, int, int, unsigned char*);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
int GetElementField4ByKey0208d9e8(List0208d994*, int);
int TestBitInByteArrayAt0x84_02096088(void*, int);
int TestBitInByteArray02096100(int, unsigned char*, int);
int GetFieldByKey020e0434(Container020e0310*, int);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
unsigned char GetEntryField0209618c(FindEntryById02096134Table*, int);
int LookupArrayFieldByCase0208da18(List0208d994*, int, int);
int GetElementField0x10ByKey_0208dac4(List0208d994*, int);
int GetElementField8ByKey0208da00(List0208d994*, int);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
int GetElementField0x14ByKey_0208dadc(List0208d994*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
StoreStruct* GetGlobalField0x1c020421a0();
StatEntry0208bf78* FindEntryById02096134(FindEntryById02096134Table*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void ResetList0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char*, int);
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
void SetSubBg0Control0208c9cc(int, int, int, int, int);
void DispatchByTag0204b2e0(void*, char*);
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0*, char*);
extern "C" void func_0204c684(TextWindow0208bf78*);
extern "C" PackedNibbleArray0206e120* func_0205ec34();
extern "C" void func_0204f41c(TextWindow0208bf78*, short, short, const char*, int, unsigned char, short*, short*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void func_02046608(StoreStruct*, int, const char*, char*, int, int, int);
extern "C" int func_020420e8(char*, int);
extern "C" void func_0208d42c(void*, Struct_0208bf78_2*, short, short, int, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_0204b5b4(void*, int);

extern char data_020f1120[], data_020f113b[], data_020f114d[], data_020f116b[], data_020f117f[];
extern char data_020f1192[], data_020f1197[];

static inline unsigned char inline_0208bf78_2(Struct_02065990_3* arg0, int arg1) {
    return func_020965ac(arg0, arg1);
}

static inline Struct_0208bf78_6 inline_0208bf78_3(Struct_02065990_3* arg0, unsigned char arg1) {
    return arg0->unknown_178_[arg1];
}

static inline bool inline_0208bf78_4(unsigned char arg0, int arg1) {
    return func_0206e120(func_0205ec34(), arg0) == arg1;
}

static inline bool inline_0208bf78_5(Struct_0205faf4_3* arg0, unsigned char arg1, int arg2) {
    return func_0206e120(arg0, arg1) == arg2;
}

// USA: func_0208bf78
extern "C" ARM void func_0208bf78(Struct_0208bf78_4* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_d6_ == 0) {
        func_0208d854((Struct_0208b9a0*)&arg0->unknown_1c_);
        arg0->unknown_bc_ = var0->QueueLoadFileInGP2(data_020f1120, data_020f113b, 0);
        arg0->unknown_d6_++;
    } else if (arg0->unknown_d6_ == 1) {
        if (!var0->GetTaskStatus(arg0->unknown_bc_)) return;
        SafeAllocator* var1 = arg0->unknown_0_->inline_0208bf78();
        var1->Reset();
        void* var2 = 0;
        unsigned int var3 = 0;
        var0->GetLoadedFileByID(arg0->unknown_bc_, &var2, &var3);
        if (var1 && var2 && var3) {
            func_0208d860(&arg0->unknown_1c_, var1, var2, var3, &arg0->unknown_d2_, 1, 0xfff);
        }
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        arg0->unknown_d6_++;
        if (!arg0->unknown_dc_) arg0->unknown_d6_ = 4;
    } else if (arg0->unknown_d6_ == 2) {
        arg0->unknown_bc_ = var0->QueueLoadFile(data_020f114d, 0);
        arg0->unknown_d6_++;
    } else if (arg0->unknown_d6_ == 3) {
        if (!var0->GetTaskStatus(arg0->unknown_bc_)) return;
        void* var4;
        unsigned int var5;
        var0->GetLoadedFileByID(arg0->unknown_bc_, &var4, &var5);
        if (var4) {
            Struct_02065990_3* var6 = func_02094d6c();
            unsigned char var7 = 0;
            func_02095870(var6, (Struct_02013fb4*)var4, var5, inline_0208bf78_2(var6, arg0->unknown_d2_), &var7);
            arg0->unknown_dd_ = var7;
        }
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        arg0->unknown_d6_++;
    } else if (arg0->unknown_d6_ == 4) {
        if (arg0->unknown_d2_ == 9999) {
            arg0->unknown_bc_ = var0->QueueLoadFile(data_020f116b, 0);
        } else {
            arg0->unknown_bc_ = var0->QueueLoadFile(data_020f117f, 0);
        }
        arg0->unknown_d6_++;
    } else if (arg0->unknown_d6_ == 5) {
        if (!var0->GetTaskStatus(arg0->unknown_bc_)) return;
        void* var8[4] = {0};
        void* var9;
        void* var10;
        unsigned int var11;
        var0->GetLoadedFileByID(arg0->unknown_bc_, &var10, &var11);
        int var12 = func_02046900((Struct_02020cb8_4*)var10);
        int var13[4];
        for (int var14 = 0; var14 < var12; var14++) {
            var8[var14] = func_020467f0((Struct_02020aec*)var10, var14, &var9, &var13[var14]);
        }
        Struct_0208bf78_2 var15;
        short var16;
        short var17;
        char* var18 = (char*)var8[0];
        func_0204c684(&var15);
        var15.unknown_8_ = var18 + 0x10;
        var15.unknown_8c_.unknown_1c_ = 0x20;
        var15.unknown_8c_.unknown_1e_ = 0x18;
        var15.unknown_8c_.unknown_28_ = 0xc;
        var15.unknown_8c_.unknown_2a_ = 0x10;
        arg0->unknown_da_ &= ~8;
        if (arg0->unknown_d2_ != 9999) {
            func_0205ec34();
            Struct_02065990_3* var19 = func_02094d6c();
            short var20 = arg0->unknown_d2_;
            char var21[8] = {0};
            sprintf(var21, data_020f1192, var20);
            func_0204f41c(&var15, 0x18, 0x14, var21, 0xc, 0xf, &var16, &var17, 0);
            int var22 = func_0208d9e8((Struct_0208bf78_5*)&arg0->unknown_1c_, var20);
            bool var23 = 0;
            if (arg0->unknown_dd_ && !func_02096088(var19, inline_0208bf78_2(var19, var20))) {
                if (!func_02096100((int)var19, var19->unknown_4a8_, inline_0208bf78_2(var19, var20))) var23 = 1;
            }
            if (var23) var22 = func_020e0434(&arg0->unknown_4_, 3);
            int var24 = 0;
            func_0204f41c(&var15, 0x30, 0x14, (const char*)var22, 0xc, 0xf, &var16, &var17, var24);
            if (inline_0208bf78_4(inline_0208bf78_2(var19, var20), 2)) {
                var22 = func_0208da18((Struct_0208bf78_5*)&arg0->unknown_1c_, var20,
                                                      func_0209618c((Struct_0205faf4_7*)var19, inline_0208bf78_2(var19, var20)));
                var24 = 1;
                if (func_02096088(var19, inline_0208bf78_2(var19, var20))) arg0->unknown_da_ |= 8;
            } else if (inline_0208bf78_4(inline_0208bf78_2(var19, var20), 3)) {
                arg0->unknown_da_ |= 8;
                var22 = func_0208dac4((Struct_0208bf78_5*)&arg0->unknown_1c_, var20);
                var24 = 2;
            } else if (arg0->unknown_df_ && func_02096088(var19, inline_0208bf78_2(var19, var20))) {
                arg0->unknown_da_ |= 8;
                var22 = func_0208dac4((Struct_0208bf78_5*)&arg0->unknown_1c_, var20);
                var24 = 2;
            } else {
                unsigned char id = GetMonsterIndex0208bf78(table, target);
                PackedNibbleArray0206e120* status = func_0205ec34();
                bool seen = IsStatus0208bf78(status, id, 0) || IsStatus0208bf78(status, id, 1);
                if (seen) {
                    text = GetElementField8ByKey0208da00((List0208d994*)&view->elements, target);
                    if (view->flags & 0x40) kind = 1;
                    if (view->revealed) {
                        if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 0)) {
                            text = GetFieldByKey020e0434(&view->strings, 4);
                        } else if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 1)) {
                            GameResources* resources = GameState::GetInstance()->GetResources();
                            if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) == 0x2d) {
                                text = GetElementField0x14ByKey_0208dadc((List0208d994*)&view->elements, target);
                            }
                        }
                    }
                } else {
                    Struct_0205faf4_4* var29 = (Struct_0205faf4_4*)func_0205ec34();
                    if (func_0206e260(var29, inline_0208bf78_2(var19, var20))) {
                        var22 = func_0208da00((Struct_0208bf78_5*)&arg0->unknown_1c_, var20);
                    }
                }
            }
            Struct_020465c0* var30 = func_020421a0();
            char* var31 = var30->unknown_60_;
            memset(var31, 0, 0x960);
            Struct_0208bf78_7* var32 = func_02096134((Struct_0205faf4_7*)var19, inline_0208bf78_2(var19, var20));
            if (var32) {
                func_02046380(var30);
                if (var32->unknown_2_0_) {
                    for (int var33 = 0; var33 < 3; var33++) {
                        int var34 = var32->unknown_a_[var33];
                        if (var34 > 99) var34 = 99;
                        func_020465c0(var30, var33, var34);
                    }
                }
                for (int var35 = 0; var35 < 2; var35++) {
                    int var36 = var32->unknown_4_[var35];
                    if (var36 > 99) var36 = 99;
                    func_020465c0(var30, var35 + 3, var36);
                }
            }
            func_02046608(var30, 0xc, (const char*)var22, var31, 0xe0, 0, 1);
            func_0204f41c(&var15, 0x10, 0x28, var31, 0xc, 0xf, &var16, &var17, 0);
            var15.unknown_8c_.unknown_28_ = 0xa;
            var15.unknown_8c_.unknown_2a_ = 0x10;
            func_0204f41c(&var15, 0, 0, (const char*)func_020e0434(&arg0->unknown_4_, var24), 0xa, 0xe, &var16, &var17, 0);
            var15.unknown_8c_.unknown_28_ = 8;
            var15.unknown_8c_.unknown_2a_ = 0x10;
            if (var24) {
                Struct_0208bf78_6 var37 = inline_0208bf78_3(var19, inline_0208bf78_2(var19, var20));
                char var38[0x100] = {0};
                sprintf(var38, data_020f1197, var37.unknown_1_3_, func_020e0434(&arg0->unknown_4_, (short)(var37.unknown_0_7_ + 4)), var37.unknown_0_0_ + 2000);
                func_0204f41c(&var15, 0xc6 - func_020420e8(var38, 0), 0xa8, var38, 8, 0xf, &var16, &var17, 0);
                func_0208d42c(arg0, &var15, 0xd7, 0xa8, var37.unknown_2_0_, 0xf, 2, 1, 1);
                func_0208d42c(arg0, &var15, 0xda, 0xa8, var37.unknown_2_5_, 0xf, 2, 0, 1);
            }
        }
        Struct_0208bf78_3 var39;
        func_0204af64((Struct_02020cb8*)&var39);
        func_0204b11c((unsigned char*)&var39, 0);
        var39.unknown_1c_0_ = 1;
        var39.unknown_1c_4_ = 0;
        func_0204b5b4(&var39, 0);
        func_0204b5e8((Struct_02020cb8_5*)&var39, 0, 0);
        func_0208c9cc(0, 0, 15, 0, 0);
        for (int var40 = 0; var40 < var12; var40++) {
            func_0204b2e0(&var39, (char*)var8[var40]);
            func_0204b3a0((Struct_02020cb8_6*)&var39, (char*)var8[var40]);
        }
        var0->RemoveTask(arg0->unknown_bc_);
        arg0->unknown_bc_ = -1;
        arg0->unknown_da_ &= ~0x20;
        arg0->unknown_d6_ = 0;
    }
}
