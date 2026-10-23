typedef struct CharacterCreation CharacterCreation;

// A pointer to member function as MWCC lays it out: the function and the adjustment for `this`.
typedef struct CreationTabHandler {
    void (*func)(CharacterCreation* self);
    int adjust;
} CreationTabHandler;

typedef struct CreationTabHandlers {
    CreationTabHandler handlers[13];
} CreationTabHandlers;

void CharacterCreationUI_HandleSetup(CharacterCreation* self);
void CharacterCreationUI_HandleGenderSelection(CharacterCreation* self);
void CharacterCreationUI_HandleBodyType(CharacterCreation* self);
void CharacterCreationUI_HandleHairStyle(CharacterCreation* self);
void CharacterCreationUI_HandleHairColor(CharacterCreation* self);
void CharacterCreationUI_HandleFace(CharacterCreation* self);
void CharacterCreationUI_HandleEyeColor(CharacterCreation* self);
void CharacterCreationUI_HandleSkinColor(CharacterCreation* self);
void CharacterCreationUI_HandleNameEntry(CharacterCreation* self);
void CharacterCreationUI_HandleConfirm(CharacterCreation* self);
void CharacterCreationUI_HandleNewGameFinish(CharacterCreation* self);
void CharacterCreationUI_HandleClose(CharacterCreation* self);

// The handler for each CreationTab, indexed by CharacterCreationUI::state; CreationTab_Done has none.
// Originally data_ov009_0218ab9c (USA/EUR 0x0218ab9c, JPN 0x0218bb04).
const CreationTabHandlers CharacterCreationUI_tabHandlers = {{
    {CharacterCreationUI_HandleSetup, 0},
    {CharacterCreationUI_HandleGenderSelection, 0},
    {CharacterCreationUI_HandleBodyType, 0},
    {CharacterCreationUI_HandleHairStyle, 0},
    {CharacterCreationUI_HandleHairColor, 0},
    {CharacterCreationUI_HandleFace, 0},
    {CharacterCreationUI_HandleSkinColor, 0},
    {CharacterCreationUI_HandleEyeColor, 0},
    {CharacterCreationUI_HandleNameEntry, 0},
    {CharacterCreationUI_HandleConfirm, 0},
    {CharacterCreationUI_HandleNewGameFinish, 0},
    {CharacterCreationUI_HandleClose, 0},
    {0, 0},
}};
