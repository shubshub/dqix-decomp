#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

void* GetCombatantWithFlag0x1000_0200ff58(GameState*,int);
int GameState_GetProtagonistIndex(GameState*);
int GetClampedArrayField0xd1c_ov000_021761c8(char*,int);
int GetClampedArrayField0xd3c_ov000_021761ec(char*,int);
void EnqueueEventTag67_021c6a9c(unsigned short, int, int, unsigned char, unsigned char, signed char);
struct Node02175be4 {
    char p0[0x1d]; signed char selection; char p1[8]; unsigned short key;
    char p2[6]; signed char state;
};
struct Struct_ov000_02175be4_2 {
    unsigned short unknown_0_[4]; signed char unknown_8_[4],unknown_c_[4];
    char unknown_10_[0xb]; signed char unknown_1b_; char unknown_1c_[8]; unsigned short unknown_24_;
};
struct Struct_ov000_02175be4_3 { unsigned short unknown_0_; unsigned char unknown_2_[4],unknown_6_,unknown_7_; };
struct Struct_ov000_021833a8 { short unknown_0_[4]; };
extern "C" {
Struct_ov000_02175be4* func_ov000_02161318(void*,int);
void func_ov000_02170db0(Struct_ov000_02175be4*);
int rand();
extern const Struct_ov000_021833a8 data_ov000_021833a8;
}

static inline short inline_ov000_02175be4(Struct_ov000_02175be4* arg0) { return (short)arg0->unknown_26_; }

// USA: func_ov000_02175be4
extern "C" ARM void func_ov000_02175be4(Struct_ov000_02175be4_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    for (signed char var1=0;var1<4;var1++) {
        if (!func_0200ff58(var0,var1)) func_ov000_02161318(arg0,var1);
    }
    if (obj->phase != GameState_GetProtagonistIndex(gs)) return;
    unsigned char count = 0;
    short keys[4] = {0};
    FourShort02175be4 selections(data_ov000_021833a8);
    for (signed char i=0;i<4;i++) {
        if (!GetCombatantWithFlag0x1000_0200ff58(gs,i)) {
            Node02175be4* node = func_ov000_02161318(obj,i);
            if (node) {
                keys[count] = node->key;
                selections.v[count] = node->selection;
                count++;
            }
        }
    }
    Struct_ov000_02175be4_3 var7[4];
    int var8[4];
    memset(var7,0,sizeof(var7));
    int var9=0;
    short* var10=var3;
    for (int var11=0;var11<var2;var10++,var11++) {
        Struct_ov000_02175be4_3* var12;
        int var13,var14;
        int var15=*var10;
        if (var15>=0) {
            var12=var7;
            var13=1;
            for (var14=0;var14<var9;var12++,var14++) {
                if (var12->unknown_0_==var15) {var13=0;break;}
            }
            var12->unknown_0_=var15;
            if (var13) var9++;
            var12->unknown_2_[var12->unknown_6_]=var11;
            var12->unknown_6_++;
        }
    }
    Struct_ov000_02175be4_3* var16;
    int var17=-1;
    Struct_ov000_02175be4_3* var18=0;
    int var19=0;
    var16=var7;
    for (int var20=0;var20<var9;var16++,var20++) {
        if (var19<var16->unknown_6_) {
            var19=var16->unknown_6_;
            var18=var16;
            var17=(short)var16->unknown_0_;
        } else if (var19==var16->unknown_6_) var17=-1;
    }
    if (var17==-1) var17=0;
    short var21=0;
    if (var17 && var18) {
        int var22=0;
        for (int var23=0;var23<var18->unknown_6_;var23++) {
            unsigned int var24=((unsigned char*)var18+var23)[2];
            if (var24<4) { var8[var22]=var4.unknown_0_[var24]; var22++; }
        }
        if (var22>0) var21=var8[rand()%var22];
    }
    if (var21==-1) var21=var4.unknown_0_[0];
    if (!var17) {
        for (unsigned char var25=0;var25<4;var25++) {
            Struct_ov000_02175be4* var26=func_ov000_02161318(arg0,var25);
            if (var26) {
                var26->unknown_26_=arg0->unknown_0_[var25];
                var26->unknown_1d_=arg0->unknown_8_[var25];
                var26->unknown_2e_=arg0->unknown_c_[var25];
                func_ov000_02170db0(var26);
            }
        }
    } else {
        for (unsigned char var27=0;var27<4;var27++) {
            Struct_ov000_02175be4* var28=func_ov000_02161318(arg0,var27);
            if (var28) {
                var28->unknown_26_=(unsigned short)var17;
                var28->unknown_1d_=(signed char)var21;
                var28->unknown_2e_=-1;
                func_ov000_02170db0(var28);
            }
        }
    }
    for (signed char var29=0;var29<4;var29++) {
        Struct_ov000_02175be4* var30=func_ov000_02161318(arg0,var29);
        if (var30) {
            unsigned char var31=func_ov000_021761c8((char*)arg0,var30->unknown_1d_);
            unsigned char var32=func_ov000_021761ec((char*)arg0,var30->unknown_1d_);
            func_ov017_021c6a9c(arg0->unknown_24_, var29, (unsigned short)inline_ov000_02175be4(var30), var31, var32, var30->unknown_2e_);
        }
    }
}
