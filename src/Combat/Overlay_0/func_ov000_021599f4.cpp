#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_ov000_021599f4 { char pad[0x5c]; unsigned char remaining[35]; unsigned char unknown_7f_[35]; };
struct Struct_ov000_02182efc { int index; int value; };
struct Struct_02088660;
extern "C" int func_ov000_02156038(GameObject*);
extern "C" int func_020882f8(unsigned char*);
extern "C" int func_ov000_021543f4(GameObject*);
extern "C" int func_ov000_02156404(GameObject*);
extern "C" int func_ov000_02153a8c(GameObject*);
extern "C" int func_ov000_02156b20(GameObject*);
extern "C" int func_ov000_0215985c(GameObject*);
extern "C" int func_ov000_02159874(GameObject*);
extern "C" int func_ov000_0215516c(GameObject*);
extern "C" int func_ov000_0215988c(GameObject*);
extern "C" int func_ov000_021598a4(GameObject*);
extern "C" int func_ov000_021598bc(GameObject*);
extern "C" int func_ov000_021598d4(GameObject*);
extern "C" int func_ov000_02156c94(GameObject*);
extern "C" int func_02088660(Struct_02088660*);
extern "C" int func_ov000_02156cac(GameObject*);
extern "C" int func_ov000_021598ec(GameObject*);
extern "C" int func_ov000_02159904(GameObject*);
extern "C" int func_ov000_0215991c(GameObject*);
extern "C" int func_ov000_02159934(GameObject*);
extern "C" int func_ov000_0215994c(GameObject*);
extern "C" int func_ov000_02159964(GameObject*);
extern "C" int func_ov000_0215997c(GameObject*);
extern "C" int func_ov000_02159994(GameObject*);
extern "C" int func_ov000_021599ac(GameObject*);
extern "C" int func_ov000_021599c4(GameObject*);
extern "C" int func_ov000_02156258(GameObject*);
extern "C" int func_ov000_021563ec(GameObject*);
extern "C" int func_ov000_021599dc(GameObject*);
extern int data_ov000_02182a94[3];
extern Struct_ov000_02182efc data_ov000_02182efc[26];

// USA: func_ov000_021599f4
extern "C" ARM void func_ov000_021599f4(void*, int id) {
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(id);
    if (!combatant) return;
    unsigned char* remaining = ((Struct_ov000_021599f4*)combatant->currentStats_)->remaining;
    unsigned char* var2 = ((Struct_ov000_021599f4*)combatant->currentStats_)->unknown_7f_;
    unsigned char var3[3];
    var3[0] = func_ov000_02156038(combatant);
    var3[1] = func_020882f8((unsigned char*)combatant->currentStats_);
    var3[2] = func_ov000_021543f4(combatant);
    unsigned char* flag = var3;
    int* index = data_ov000_02182a94;
    for (int i = 0; i < 3; i++, flag++, index++) {
        if (*flag) {
            if (remaining[*index]) {
                remaining[*index]--;
                if (!remaining[*index]) {
                    remaining[*index] = 0;
                    var2[*index] = 4;
                }
            }
            break;
        }
    }
    unsigned char active[26];
    active[0] = func_ov000_02156404(combatant);
    active[1] = func_ov000_02153a8c(combatant);
    active[2] = func_ov000_02156b20(combatant);
    active[3] = func_ov000_0215985c(combatant);
    active[4] = func_ov000_02159874(combatant);
    active[5] = func_ov000_0215516c(combatant);
    active[6] = func_ov000_0215988c(combatant);
    active[7] = func_ov000_021598a4(combatant);
    active[8] = func_ov000_021598bc(combatant);
    active[9] = func_ov000_021598d4(combatant);
    active[10] = func_ov000_02156c94(combatant);
    active[11] = func_02088660((Struct_02088660*)combatant->currentStats_);
    active[12] = func_ov000_02156cac(combatant);
    active[13] = func_ov000_021598ec(combatant);
    active[14] = func_ov000_02159904(combatant);
    active[15] = func_ov000_0215991c(combatant);
    active[16] = func_ov000_02159934(combatant);
    active[17] = func_ov000_0215994c(combatant);
    active[18] = func_ov000_02159964(combatant);
    active[19] = func_ov000_0215997c(combatant);
    active[20] = func_ov000_02159994(combatant);
    active[21] = func_ov000_021599ac(combatant);
    active[22] = func_ov000_021599c4(combatant);
    active[23] = func_ov000_02156258(combatant);
    active[24] = func_ov000_021563ec(combatant);
    active[25] = func_ov000_021599dc(combatant);
    unsigned char* var8 = active;
    Struct_ov000_02182efc* rule = data_ov000_02182efc;
    for (int i = 0; i < 26; i++, var8++, rule++) {
        if (*var8 && remaining[rule->index]) {
            remaining[rule->index]--;
            if (!remaining[rule->index]) {
                remaining[rule->index] = 0;
                var2[rule->index] = rule->value;
            }
        }
    }
}
