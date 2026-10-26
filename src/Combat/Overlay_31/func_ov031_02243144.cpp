#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Struct_ov031_02243144_2 { unsigned char address[6]; unsigned char age; unsigned char unknown_7_; };
struct Struct_ov031_02243144 { int field0; unsigned char address[6]; };
#if defined(jpn)
struct Struct_ov031_02291e04 {
    unsigned char pad0; unsigned char unknown_6_; unsigned char pad2; unsigned char changed;
    unsigned char pad4; unsigned char unknown1_7_; unsigned char age; char unknown_7_[9];
    void* active; char unknown_14_[4]; Struct_ov031_02243144* identity;
};
#else
struct Struct_ov031_02291e04 {
    unsigned char pad0[3]; unsigned char changed; unsigned char age; unsigned char pad5;
    unsigned char unknown_6_; unsigned char unknown1_7_; char pad8[0x10]; Struct_ov031_02243144* identity;
    char unknown_1c_[0x18]; void* active;
};
#endif
extern Struct_ov031_02291e04 data_ov031_02291e04;
extern "C" int memcmp(const void*,const void*,unsigned int);

// USA: func_ov031_02243144
extern "C" ARM int func_ov031_02243144(Script::Parameter* parameters) {
    if(!data_ov031_02291e04.active) return 1;
    if(data_ov031_02291e04.changed) return 1;
    parameters++->ToInt();
    unsigned char address[6];
    for(int i=0;i<6;++i) address[i]=(parameters++)->ToInt();
    if(!memcmp(address,data_ov031_02291e04.identity->address,6)) {
        data_ov031_02291e04.unknown_6_=1;
        int slot=-1;
        int var3=-1;
#if defined(jpn)
        Struct_ov031_02243144_2* var4=(Struct_ov031_02243144_2*)((char*)GameState::GetInstance()+0x7cdc);
#else
        Struct_ov031_02243144_2* var4=(Struct_ov031_02243144_2*)&GameState::GetInstance()->unk_6fc0[0x7fb0-0x6fc0];
#endif
        Struct_ov031_02243144_2* peer=var4;
        for(int i=0;i<8;++i,++peer) {
            if(!memcmp(peer,address,6)) {
                slot=i;
                if(peer->age!=255 && !data_ov031_02291e04.unknown1_7_) {
                    data_ov031_02291e04.age=peer->age;
                    return 1;
                }
                break;
            }
            if(var3>peer->age || var3<0) { slot=i; var3=peer->age; }
        }
        data_ov031_02291e04.changed=1;
        peer=var4;
        for(int i=0;i<8;++i,++peer) {
            if(peer->age) {
                if(peer->age==255) peer->age=0;
                else --peer->age;
                if(!peer->age) memset(peer,0,sizeof(*peer));
            }
        }
        peer=&var4[slot];
        memcpy(peer,address,6);
        peer->age=7;
    }
    return 1;
}
