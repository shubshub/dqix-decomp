#include <globaldefs.h>
#include <GameState/GameState.h>


struct SearchStruct0202c1a4;
struct TailList020469b4;
struct TailNode020469b4;
struct Obj_021bd3a4;
struct Struct_ov017_021cd748_6 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short destination;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned char enabled;
    signed char recipient;
    float parameter;
};
struct Struct_ov017_021cd748_7 {
    char unknown_0_[2];
    unsigned char queued;
    unsigned char active;
    char unknown_4_[4];
    unsigned short destination;
    char unknown_a_[0xc];
    unsigned short unknown_16_;
    unsigned short unknown_18_;
    char unknown_1a_[0x36];
    unsigned short unknown_50_;
#if defined(jpn)
    char unknown_52_[0xc0];
#else
    char unknown1_52_[0xc4];
#endif
    signed char sender;
    char unknown_117_;
    unsigned short unknown_118_;
    char unknown_11a_[0x5e];
    unsigned char unknown_178_0_ : 1;
    unsigned char flags : 7;
    unsigned char unknown_179_;
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    float parameter;
    char unknown_180_[0x48];
};
#if defined(jpn)
struct AreaState { unsigned short area; char unknown_2_[0x2814]; unsigned short destination; };
#else
struct AreaState { unsigned short area; char unknown_2_[0x27d4]; unsigned short destination; };
#endif
struct AlternateArea { unsigned short area; };
struct AlternateMode { char unknown_0_[3]; unsigned char enabled; };
#if defined(jpn)
struct Struct_ov017_021cd748_4 { char unknown_0_[0x5a4c]; unsigned char blocked; };
#else
struct Struct_ov017_021cd748_4 { char unknown_0_[0x5cac]; unsigned char blocked; };
#endif
#if defined(jpn)
struct Struct_ov017_021cd748_5 { char unknown_0_[0x41fc]; unsigned short destination; };
#else
struct Struct_ov017_021cd748_5 { char unknown_0_[0x44ac]; unsigned short destination; };
#endif
struct Struct_0206ea7c_2 { unsigned char field_0; unsigned char unknown_1_; unsigned char unknown_2_; char unknown_3_[25]; };
struct Get28ByteElementAt0x334Struct { char unknown_0_[0x332]; unsigned char index; char unknown_333_; };
extern "C" Get28ByteElementAt0x334Struct* Scenario_GetInstance();
extern "C" AreaState* Zone3D_GetInstance();
extern "C" int LinkSession_IsGuest(SearchStruct0202c1a4*);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_ov017_021baedc(void*, int);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" Struct_0206ea7c_2* func_0206ea7c(Get28ByteElementAt0x334Struct*, int);
extern "C" int func_ov017_021bd3a4(Obj_021bd3a4*);
extern "C" int LinkSession_IsHostOrSolo(SearchStruct0202c1a4*);
extern "C" void func_ov017_021bc6e0(Struct_ov017_021cd748_7*, int, int);

// USA: func_ov017_021cd748
extern "C" ARM void func_ov017_021cd748(int sender, Struct_ov017_021cd748_6* event, GameState* game, GameResources* resources, SearchStruct0202c1a4* search) {
    int matches;
    GameState* instance;
    Struct_ov017_021cd748_7* state;
    unsigned short area;
    instance = GameState::GetInstance();
    TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
    state = (Struct_ov017_021cd748_7*)resources->unknown_ptr_array_371c[6];
    Scenario_GetInstance();
    AreaState* areaState = Zone3D_GetInstance();
    area = areaState->area;
    if ((LinkSession_IsGuest(search) && sender == 0) || event->enabled) {
        if (event->recipient >= 0 && event->recipient != LinkSession_GetOwnSlot(search)) return;
        if (((Struct_ov017_021cd748_4*)instance)->blocked) return;
        matches = 0;
        if (area == event->unknown_4_) matches = 1;
        if (area == event->unknown_a_) matches = 1;
        if (!matches && ((AlternateMode*)resources->unknown_ptr_array_3700[3])->enabled) {
            unsigned short alternate = ((AlternateArea*)GameState_GetZoneTransition(game))->area;
            if (alternate == event->unknown_4_) matches = 1;
            if (alternate == event->unknown_a_) matches = 1;
        }
        if (!matches) return;
        unsigned short destination = event->destination;
        if (!destination) destination = event->unknown_6_;
        if (!destination) return;
        if (FieldTaskQueue_IsEmpty((void**)list) || event->enabled) {
            int changed = 0;
            if (!state->active) {
                if (state->queued) {
                    if (event->destination == state->unknown_118_) return;
                    state->destination = destination;
                    if (event->enabled) state->sender = sender;
                    changed = 1;
                } else {
                    if (destination == areaState->destination) return;
                    func_ov017_021baedc(state, 1);
                    state->destination = destination;
                    if (event->enabled) state->sender = sender;
                    func_020469b4(list, (TailNode020469b4*)state);
                    changed = 1;
                }
            }
            if (changed && LinkSession_IsGuest(search)) {
                Get28ByteElementAt0x334Struct* party = Scenario_GetInstance();
                Struct_0206ea7c_2* entry = func_0206ea7c(party, party->index);
                state->unknown_178_0_ = 0;
                state->flags = 0;
                state->unknown_179_ = 0;
                state->unknown_17a_ = 0;
                state->unknown_17b_ = 0;
                state->parameter = -1.0f;
                state->unknown_178_0_ = 1;
                state->unknown_179_ = entry->field_0;
                state->unknown_17a_ = entry->unknown_1_;
                state->unknown_17b_ = entry->unknown_2_;
                state->parameter = event->parameter;
            }
        } else {
            if (!func_ov017_021bd3a4((Obj_021bd3a4*)state)) ((Struct_ov017_021cd748_5*)resources)->destination = destination;
        }
    } else {
        if (LinkSession_IsHostOrSolo(search) && func_ov017_021bd3a4((Obj_021bd3a4*)state)) {
            unsigned short var11 = event->unknown_6_;
            unsigned short second = state->unknown_18_;
            unsigned short first = state->unknown_16_;
            if (var11 == second || var11 == first) func_ov017_021bc6e0(state, sender, state->unknown_50_);
        }
    }
}
