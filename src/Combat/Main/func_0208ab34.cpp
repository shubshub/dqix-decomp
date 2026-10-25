#include <globaldefs.h>
#if defined(jpn)
#define data_020e8cc6 data_020e8de2
#define data_020e8cc5 data_020e8de1
#endif
#include "GameState/GameState.h"

struct Struct_0208ab34;
struct Struct_0208ab34_2;
struct Struct_0208ab34_3 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
class Struct_0208ab34_4 {
public:
    virtual int inline_0208ab34(int, void*);
    virtual void inline_0208ab34_2(int);
    char unknown_4_[2];
    unsigned char unknown_6_;
    unsigned char unknown_7_[17];
    unsigned char unknown_18_[17];
};
extern "C" int* func_0202ae18();
extern "C" Struct_0208ab34* func_020e2ff8();
extern "C" int func_020e34bc(Struct_0208ab34*, int);
extern "C" int func_0202b7d8(int*);
extern "C" void func_020e3368(unsigned char*, unsigned char);
extern "C" void func_020e3468(Struct_0208ab34_2*, int);
extern "C" void func_0208ad1c(void*);
extern "C" void func_020e3428(void*, int);
extern unsigned char data_020e8cc6[];
extern unsigned char data_020e8cc5[];

// USA: func_0208ab34
extern "C" ARM void func_0208ab34(TimedPartyEntries* entries, void* context) {
    PartyRoster* roster = (PartyRoster*)GameState_GetParty(GameState::GetInstance());
    int* session = func_0202ae18();
    int activated = 0;
    int dispatched = 0;
    Container020e34bc* requests = GetData02153637_020e2ff8();
    for (int i = 0; i < roster->count; ++i) {
        int status = GetEntryStatusForKey020e34bc(requests, 1);
        int id = roster->ids[i];
        if ((!CheckField0NonZero_0202b7d8(session) ||
             (CheckField0NonZero_0202b7d8(session) && status != 1)) &&
            !entries->Test(id, context)) {
            for (int j = 0; j < 3; ++j) {
                if (entries->counters[id] == data_020e8cc5[j * 2])
                    entries->timers[id] += data_020e8cc6[j * 2];
            }
            arg0->unknown_18_[var7] = 0;
        } else {
            if (arg0->unknown_6_ <= arg0->unknown_7_[var7]) {
                if (var6 != 2 && var6 != 1)
                    func_020e3368((unsigned char*)var4, 1);
                if (var6 == 1) {
                    arg0->unknown_7_[var7] = 0;
                    var3 = 1;
                    if (arg0->inline_0208ab34(var7, arg1)) {
                        var2 = 1;
                        arg0->inline_0208ab34_2(var7);
                    }
                } else if ((unsigned int)(var6 - 3) <= 2) {
                    func_020e3468((Struct_0208ab34_2*)var4, 1);
                }
            } else {
                ++arg0->unknown_7_[var7];
                if (arg0->unknown_18_[var7] < 0xff) ++arg0->unknown_18_[var7];
            }
        }
    }
    if (var2) func_0208ad1c(arg0);
    if (var3) func_020e3428(var4, 1);
}
