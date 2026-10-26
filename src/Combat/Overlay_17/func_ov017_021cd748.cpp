#include <globaldefs.h>
#include <GameState/GameState.h>


struct Struct_0202c1a4;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_ov017_0218e674;
struct Struct_ov017_021cd748_6 {
    char unknown_0_[4];
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned char unknown_e_;
    signed char unknown_f_;
    float unknown_10_;
};
struct Struct_ov017_021cd748_7 {
    char unknown_0_[2];
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    char unknown_4_[4];
    unsigned short unknown_8_;
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
    signed char unknown_116_;
    char unknown_117_;
    unsigned short unknown_118_;
    char unknown_11a_[0x5e];
    unsigned char unknown_178_0_ : 1;
    unsigned char unknown_178_1_ : 7;
    unsigned char unknown_179_;
    unsigned char unknown_17a_;
    unsigned char unknown_17b_;
    float unknown_17c_;
    char unknown_180_[0x48];
};
#if defined(jpn)
struct Struct_ov017_021cd748 { unsigned short unknown_0_; char unknown_2_[0x2814]; unsigned short unknown_27d6_; };
#else
struct Struct_ov017_021cd748 { unsigned short unknown_0_; char unknown_2_[0x27d4]; unsigned short unknown_27d6_; };
#endif
struct Struct_ov017_021cd748_2 { unsigned short unknown_0_; };
struct Struct_ov017_021cd748_3 { char unknown_0_[3]; unsigned char unknown_3_; };
#if defined(jpn)
struct Struct_ov017_021cd748_4 { char unknown_0_[0x5a4c]; unsigned char unknown_5cac_; };
#else
struct Struct_ov017_021cd748_4 { char unknown_0_[0x5cac]; unsigned char unknown_5cac_; };
#endif
#if defined(jpn)
struct Struct_ov017_021cd748_5 { char unknown_0_[0x41fc]; unsigned short unknown_44ac_; };
#else
struct Struct_ov017_021cd748_5 { char unknown_0_[0x44ac]; unsigned short unknown_44ac_; };
#endif
struct Get28ByteElementAt0x334Elem { unsigned char field_0; unsigned char field_1; unsigned char field_2; char pad_3[25]; };
struct Get28ByteElementAt0x334Struct { char pad_0[0x332]; unsigned char index; char field_333; };
extern "C" Get28ByteElementAt0x334Struct* Scenario_GetInstance();
extern "C" AreaState* Zone3D_GetInstance();
extern "C" int LinkSession_IsGuest(SearchStruct0202c1a4*);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
void* GameState_GetZoneTransition(GameState*);
int FieldTaskQueue_IsEmpty(void**);
extern "C" void func_ov017_021baedc(void*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
Get28ByteElementAt0x334Elem* Get28ByteElementAt0x334_0206ea7c(Get28ByteElementAt0x334Struct*, int);
int HasFlag3orFlag2And9a_021bd3a4(Obj_021bd3a4*);
extern "C" int LinkSession_IsHostOrSolo(SearchStruct0202c1a4*);
extern "C" void func_ov017_021bc6e0(TransitionState*, int, int);

// USA: func_ov017_021cd748
extern "C" ARM void func_ov017_021cd748(int sender, TransitionEvent* event, GameState* game, GameResources* resources, SearchStruct0202c1a4* search) {
    int matches;
    GameState* instance;
    TransitionState* state;
    unsigned short area;
    instance = GameState::GetInstance();
    TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
    state = (TransitionState*)resources->unknown_ptr_array_371c[6];
    Scenario_GetInstance();
    AreaState* areaState = Zone3D_GetInstance();
    area = areaState->area;
    if ((LinkSession_IsGuest(search) && sender == 0) || event->enabled) {
        if (event->recipient >= 0 && event->recipient != LinkSession_GetOwnSlot(search)) return;
        if (((GameStatus*)instance)->blocked) return;
        matches = 0;
        if (area == event->firstArea) matches = 1;
        if (area == event->secondArea) matches = 1;
        if (!matches && ((AlternateMode*)resources->unknown_ptr_array_3700[3])->enabled) {
            unsigned short alternate = ((AlternateArea*)GameState_GetZoneTransition(game))->area;
            if (alternate == event->firstArea) matches = 1;
            if (alternate == event->secondArea) matches = 1;
        }
        if (!matches) return;
        unsigned short destination = event->destination;
        if (!destination) destination = event->fallbackDestination;
        if (!destination) return;
        if (FieldTaskQueue_IsEmpty((void**)list) || event->enabled) {
            int changed = 0;
            if (!state->active) {
                if (state->queued) {
                    if (event->destination == state->currentDestination) return;
                    state->destination = destination;
                    if (event->enabled) state->sender = sender;
                    changed = 1;
                } else {
                    if (var7 == var5->unknown_27d6_) return;
                    func_ov017_021baedc(var2, 1);
                    var2->unknown_8_ = var7;
                    if (arg1->unknown_e_) var2->unknown_116_ = arg0;
                    func_020469b4(var4, (Struct_0201bdac*)var2);
                    var8 = 1;
                }
            }
            if (changed && LinkSession_IsGuest(search)) {
                Get28ByteElementAt0x334Struct* party = Scenario_GetInstance();
                Get28ByteElementAt0x334Elem* entry = Get28ByteElementAt0x334_0206ea7c(party, party->index);
                state->valid = 0;
                state->flags = 0;
                state->field_179 = 0;
                state->field_17a = 0;
                state->field_17b = 0;
                state->parameter = -1.0f;
                state->valid = 1;
                state->field_179 = entry->field_0;
                state->field_17a = entry->field_1;
                state->field_17b = entry->field_2;
                state->parameter = event->parameter;
            }
        } else {
            if (!func_ov017_021bd3a4((Struct_ov017_0218e674*)var2)) ((Struct_ov017_021cd748_5*)arg3)->unknown_44ac_ = var7;
        }
    } else {
        if (LinkSession_IsHostOrSolo(search) && HasFlag3orFlag2And9a_021bd3a4((Obj_021bd3a4*)state)) {
            unsigned short requested = event->fallbackDestination;
            unsigned short second = state->secondDestination;
            unsigned short first = state->firstDestination;
            if (requested == second || requested == first) func_ov017_021bc6e0(state, sender, state->field_50);
        }
    }
}
