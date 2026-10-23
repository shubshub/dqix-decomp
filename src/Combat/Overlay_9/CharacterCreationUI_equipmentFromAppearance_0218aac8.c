// Which appearance model fills which equipment slot of the new party member (CharacterCreationUI_HandleConfirm
// copies the item record of appearance.models_[appearanceSlot] into equipment[equipmentSlot]).
// Originally data_ov009_0218aac8 (USA/EUR 0x0218aac8, JPN 0x0218ba7c).
typedef struct AppearanceEquipment {
    unsigned char appearanceSlot;
    unsigned char equipmentSlot;
    unsigned char padding[5];
} AppearanceEquipment;

const AppearanceEquipment CharacterCreationUI_equipmentFromAppearance[7] = {
    {0, 0},
    {1, 1},
    {4, 5},
    {5, 6},
    {6, 7},
    {7, 8},
    {8, 9},
};
