#include <globaldefs.h>
#if defined(jpn)
#define data_020e8cc6 data_020e8de2
#define data_020e8cc5 data_020e8de1
#endif
#include "GameState/GameState.h"

struct Struct_0208ab34;
struct Struct_0208ab34_2;
struct PartyRoster {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};
class Struct_0208ab34_4 {
public:
    virtual int inline_0208ab34(int, void*);
    virtual void inline_0208ab34_2(int);
    char pad4[2];
    unsigned char threshold;
    unsigned char unknown_7_[17];
    unsigned char unknown_18_[17];
};
extern "C" int* LinkSession_GetInstance();
extern "C" Struct_0208ab34* func_020e2ff8();
extern "C" int func_020e34bc(Struct_0208ab34*, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_020e3368(unsigned char*, unsigned char);
extern "C" void func_020e3468(Struct_0208ab34_2*, int);
extern "C" void func_0208ad1c(void*);
extern "C" void func_020e3428(void*, int);
extern unsigned char data_020e8cc6[];
extern unsigned char data_020e8cc5[];

// USA: func_0208ab34
extern "C" ARM void func_0208ab34(Struct_0208ab34_4* entries, void* context) {
    PartyRoster* roster = (PartyRoster*)GameState_GetParty(GameState::GetInstance());
    int* session = LinkSession_GetInstance();
    int activated = 0;
    int var3 = 0;
    Struct_0208ab34* requests = func_020e2ff8();
    for (int i = 0; i < roster->count; ++i) {
        int status = func_020e34bc(requests, 1);
        int id = roster->ids[i];
        if ((!LinkSession_IsActive(session) ||
             (LinkSession_IsActive(session) && status != 1)) &&
            !entries->inline_0208ab34(id, context)) {
            for (int j = 0; j < 3; ++j) {
                if (entries->unknown_18_[id] == data_020e8cc5[j * 2])
                    entries->unknown_7_[id] += data_020e8cc6[j * 2];
            }
            entries->unknown_18_[id] = 0;
        } else {
            if (entries->threshold <= entries->unknown_7_[id]) {
                if (status != 2 && status != 1)
                    func_020e3368((unsigned char*)requests, 1);
                if (status == 1) {
                    entries->unknown_7_[id] = 0;
                    var3 = 1;
                    if (entries->inline_0208ab34(id, context)) {
                        activated = 1;
                        entries->inline_0208ab34_2(id);
                    }
                } else if ((unsigned int)(status - 3) <= 2) {
                    func_020e3468((Struct_0208ab34_2*)requests, 1);
                }
            } else {
                ++entries->unknown_7_[id];
                if (entries->unknown_18_[id] < 0xff) ++entries->unknown_18_[id];
            }
        }
    }
    if (activated) func_0208ad1c(entries);
    if (var3) func_020e3428(requests, 1);
}
