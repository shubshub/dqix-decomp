typedef struct CharacterCreation CharacterCreation;

// A pointer to member function as MWCC lays it out: the function and the adjustment for `this`.
typedef struct CreationTabHandler {
    void (*func)(CharacterCreation* self);
    int adjust;
} CreationTabHandler;

typedef struct CreationTabHandlers {
    CreationTabHandler handlers[13];
} CreationTabHandlers;

void CharacterCreationUI_HandleSetup();
void CharacterCreationUI_HandleGenderSelection();
void CharacterCreationUI_HandleBodyType();
void CharacterCreationUI_HandleHairStyle();
void CharacterCreationUI_HandleHairColor();
void CharacterCreationUI_HandleFace();
void CharacterCreationUI_HandleEyeColor();
void CharacterCreationUI_HandleSkinColor();
void CharacterCreationUI_HandleNameEntry();
void CharacterCreationUI_HandleConfirm();
void CharacterCreationUI_HandleNewGameFinish();
void CharacterCreationUI_HandleClose();

// The handler for each CreationTab, indexed by CharacterCreationUI::state; CreationTab_Done has none.
// Originally CharacterCreationUI_tabHandlers (USA/EUR 0x0218ab9c, JPN 0x0218bb04).
void (*const CharacterCreationUI_tabHandlers[26])() = {
    CharacterCreationUI_HandleSetup, 0,
    CharacterCreationUI_HandleGenderSelection, 0,
    CharacterCreationUI_HandleBodyType, 0,
    CharacterCreationUI_HandleHairStyle, 0,
    CharacterCreationUI_HandleHairColor, 0,
    CharacterCreationUI_HandleFace, 0,
    CharacterCreationUI_HandleSkinColor, 0,
    CharacterCreationUI_HandleEyeColor, 0,
    CharacterCreationUI_HandleNameEntry, 0,
    CharacterCreationUI_HandleConfirm, 0,
    CharacterCreationUI_HandleNewGameFinish, 0,
    CharacterCreationUI_HandleClose, 0,
    0, 0,
};
