// Preview model scale per sex and body type (fx32, 0x1000 = 1.0): width (x and z) and height (y).
// Originally data_ov009_0218aa70 (USA/EUR 0x0218aa70; jpn has the values in a switch).
typedef struct BodyDimensions {
    short width, height;
} BodyDimensions;

const BodyDimensions CharacterCreationUI_bodyDimensions[2][5] = {
    {{3768, 4255}, {3637, 4136}, {3850, 4014}, {4132, 3891}, {3870, 3764}},
    {{3768, 4177}, {3641, 4091}, {3809, 3973}, {4132, 3891}, {3768, 3764}},
};
