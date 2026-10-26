#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void* LinkSession_GetInstance(void);
void* LinkMessageQueue_GetInstance(void);
void* GetData02153637_020e2ff8(void);
void* GetData02153634_020e3580(void);
extern "C" int func_0202b000(void* obj);
extern "C" void func_ov017_021c37a4(void);
void OrByte0x1029With0x30ClearField0x1034_0202c778(unsigned char* obj);
int SetState2AndCall0202d6c8_0202b7ec(void* obj);
extern "C" void LinkMessageQueue_Reset(void* obj);
struct SlotTable020e3004;
void InitSlotTable020e3004(struct SlotTable020e3004* p);
struct Bytes020e358c;
void ClearThreeBytes020e358c(struct Bytes020e358c* s);
void ClearTwoBytesAtField_02195748(unsigned char* base);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void func_0202c360(void* obj, int val);
extern "C" void LinkSession_Update(void* obj);
void SetField0To5AndField0x1008To1_0202b828(unsigned char* obj);
void BlankFunction020d84dc(void);
extern "C" void Party_ReformLine(int, int, int, int, int);
extern "C" void func_ov017_02191234(int a);
extern "C" void LinkSession_UpdateMemberCount(void* obj);
ARM void ClearBufferAndFlag_021972cc(char* p);
void ClearByteField17182_02195520(void* obj);

// USA: func_ov017_021c35ac  (semantic: ResetBattleStateAndQueues_021c35ac)
extern "C" ARM void func_ov017_021c35ac(void) {
    GameState* battle = GameState::GetInstance();
    int g = ((int)GetGameResources());
    void* search = LinkSession_GetInstance();
    void* d100044 = LinkMessageQueue_GetInstance();
    void* d153637 = GetData02153637_020e2ff8();
    void* d153634 = GetData02153634_020e3580();

    if (func_0202b000(search) != 0) {
        func_ov017_021c37a4();
        return;
    }

#if defined(jpn)

#else
    OrByte0x1029With0x30ClearField0x1034_0202c778((unsigned char*)search);
#endif

    SetState2AndCall0202d6c8_0202b7ec(search);
    LinkMessageQueue_Reset(d100044);
    InitSlotTable020e3004((struct SlotTable020e3004*)d153637);
    ClearThreeBytes020e358c((struct Bytes020e358c*)d153634);
    ClearTwoBytesAtField_02195748((unsigned char*)g);

    GameObject* combatant = battle->GetProtagonist();
    GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    int field134 = *(int*)((char*)combatant + 0x134);
    func_0202c360(search, field134);
    LinkSession_Update(search);
    SetField0To5AndField0x1008To1_0202b828((unsigned char*)search);
    ClearFlags00((GameResources*)g, 2);
    BlankFunction020d84dc();
    Party_ReformLine(g, 1, 1, 1, 1);
    func_ov017_02191234(g);
    LinkSession_UpdateMemberCount(search);
    ClearBufferAndFlag_021972cc((char*)g);
    ClearByteField17182_02195520((void*)g);
}
