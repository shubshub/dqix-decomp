#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Struct_ov031_02243144_2 { unsigned char unknown_0_[6]; unsigned char unknown_6_; unsigned char unknown_7_; };
struct Struct_ov031_02243144 { int unknown_0_; unsigned char unknown_4_[6]; };
#if defined(jpn)
struct Struct_ov031_02291e04 {
    unsigned char unknown_0_; unsigned char unknown_6_; unsigned char unknown_2_; unsigned char unknown_3_;
    unsigned char unknown_4_; unsigned char unknown1_7_; unsigned char unknown1_4_; char unknown_7_[9];
    void* unknown_34_; char unknown_14_[4]; Struct_ov031_02243144* unknown_18_;
};
#else
struct Struct_ov031_02291e04 {
    unsigned char unknown_0_[3]; unsigned char unknown_3_; unsigned char unknown1_4_; unsigned char unknown_5_;
    unsigned char unknown_6_; unsigned char unknown1_7_; char unknown_8_[0x10]; Struct_ov031_02243144* unknown_18_;
    char unknown_1c_[0x18]; void* unknown_34_;
};
#endif
extern PeerScriptState data_ov031_02291e04;
extern "C" int memcmp(const void*,const void*,unsigned int);

// USA: func_ov031_02243144
extern "C" ARM int func_ov031_02243144(Script::Parameter* parameters) {
    if(!data_ov031_02291e04.active) return 1;
    if(data_ov031_02291e04.changed) return 1;
    parameters++->ToInt();
    unsigned char address[6];
    for(int i=0;i<6;++i) address[i]=(parameters++)->ToInt();
    if(!memcmp(address,data_ov031_02291e04.identity->address,6)) {
        data_ov031_02291e04.received=1;
        int slot=-1;
        int oldest=-1;
#if defined(jpn)
        Struct_ov031_02243144_2* var4=(Struct_ov031_02243144_2*)((char*)GameState::GetInstance()+0x7cdc);
#else
        Struct_ov031_02243144_2* var4=(Struct_ov031_02243144_2*)&GameState::GetInstance()->unk_6fc0[0x7fb0-0x6fc0];
#endif
        RecentPeer* peer=peers;
        for(int i=0;i<8;++i,++peer) {
            if(!memcmp(peer,address,6)) {
                slot=i;
                if(peer->age!=255 && !data_ov031_02291e04.ignoreAge) {
                    data_ov031_02291e04.age=peer->age;
                    return 1;
                }
                break;
            }
            if(var3>var5->unknown_6_ || var3<0) { var2=var6; var3=var5->unknown_6_; }
        }
        data_ov031_02291e04.unknown_3_=1;
        var5=var4;
        for(int var7=0;var7<8;++var7,++var5) {
            if(var5->unknown_6_) {
                if(var5->unknown_6_==255) var5->unknown_6_=0;
                else --var5->unknown_6_;
                if(!var5->unknown_6_) memset(var5,0,sizeof(*var5));
            }
        }
        var5=&var4[var2];
        memcpy(var5,var0,6);
        var5->unknown_6_=7;
    }
    return 1;
}
