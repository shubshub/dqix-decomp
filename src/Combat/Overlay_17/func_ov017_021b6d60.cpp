#if defined(jpn)
enum { Enum_ov017_021b6d60_340 = 0x148, Enum_ov017_021b6d60_47 = 0xb, Enum_ov017_021b6d60_860 = 0x13c };
#else
enum { Enum_ov017_021b6d60_340 = 0x154, Enum_ov017_021b6d60_47 = 0x2f, Enum_ov017_021b6d60_860 = 0x35c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Field150Holder02052e2c;

struct Struct_ov017_021b6d60 {
    unsigned char b0;
    unsigned char pad[Enum_ov017_021b6d60_47];
};

extern "C" void PartyMemberRecord_Init(void* p);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" short* func_02052e2c(struct Field150Holder02052e2c* obj);
extern "C" void PartyMember_WriteRecord(void* field150, void* b);
extern "C" void func_02082828(void* field150);
extern "C" void func_020545ac(short* obj);
extern "C" void func_ov017_02190264(int val, int a);
extern "C" void Party_ReformLine(int, int, int, int, int);
extern "C" void func_ov017_02191234(int a);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021cc68c(int a);

// USA: func_ov017_021b6d60
extern "C" ARM int func_ov017_021b6d60(int a, void* b) {
    PartyMemberRecord_Init(b);
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200ff1c(bs, a);
    if (c == NULL) {
        return 0;
    }
    void* field150 = (void*)func_02053c6c((unsigned char*)c);
    short* p488 = func_02052e2c((struct Field150Holder02052e2c*)c);
    if (field150 == NULL) {
        return 0;
    }
    if (p488 == NULL) {
        return 0;
    }
    PartyMember_WriteRecord(field150, b);
    int val = (int)bs->GetResources();
    func_02082828(field150);
    short* f154 = *(short**)((char*)c + Enum_ov017_021b6d60_340);
    if (f154 != NULL) {
        func_020545ac(f154);
    }
    func_ov017_02190264(val, a);
    Party_ReformLine(val, 1, 1, 1, 1);
    func_ov017_02191234(val);
    struct Struct_ov017_021b6d60* arr = (struct Struct_ov017_021b6d60*)(((char*)val + Enum_ov017_021b6d60_860) + 0x4000);
    arr += a;
    arr->b0 = 0;
    void* search = LinkSession_GetInstance();
    if (LinkSession_IsActive((int*)search)) {
        if (LinkSession_IsHostOrSolo(search)) {
            func_ov017_021cc68c(a);
        }
    }
    return b != NULL;
}
