#include <globaldefs.h>
#include "std_library_functions.h"

// Indexes of characters in the "me" font (data/pack_lv5/fi_me.bin), the font of the tokens.
enum MeFont {
    MeFont_Zero = 8, // '0'-'9' are 8-17
    MeFont_A = 18,
    MeFont_Z = 43,
};

// What Font_EncodeText writes for ' ' (CheckName also turns its separators into it).
enum NameToken {
    NameToken_Space = 0xff,
};

// ".{0,60}X" skips ahead to the next X: the wildcard repeated 0 to 60 times, 7 tokens before X.
enum SkipPattern {
    SkipPattern_MaxRepeat = 60,
    SkipPattern_Length = 7,
};

// What a "[...]" group holds: members, or a range "first-last"; "^" negates either.
enum GroupKind {
    GroupKind_Set = 0,
    GroupKind_Range = 1,
    GroupKind_Negated = 2,
    GroupKind_NegatedSet = GroupKind_Negated + GroupKind_Set,
    GroupKind_NegatedRange = GroupKind_Negated + GroupKind_Range,
};

// The name filter (NameFilter_Reset fills the ids). Its tag stays PatternSyntax0218a518: NameFilter_GroupContains's
// symbol is mangled with it.
struct PatternSyntax0218a518 {
    unsigned char reservedNames[0x18];
    unsigned char patterns[0xc];
    unsigned char reservedNamesData[4];
    unsigned char reservedNamesSize[2];
    unsigned char letterClassId;
    unsigned char groupStartId;
    unsigned char groupEndId;
    unsigned char repeatStartId;
    unsigned char repeatEndId;
    unsigned char negateId;
    unsigned char rangeId;
    unsigned char wildcardId;
};
typedef PatternSyntax0218a518 NameFilter;
int NameFilter_GroupContains(NameFilter*, unsigned char*, int, int);

// Overlay 9, originally func_ov009_0218a518 (USA/EUR 0x0218a518; JPN not identified)
extern "C" ARM int NameFilter_MatchPattern(NameFilter* self, const unsigned char* pattern, const unsigned char* input, int length, int count) {
    int letterClassId = self->letterClassId;
    int groupStartId = self->groupStartId;
    int groupEndId = self->groupEndId;
    int repeatStartId = self->repeatStartId;
    int repeatEndId = self->repeatEndId;
    int wildcardId = self->wildcardId;
    for (int start = 0; start < count; ++start, ++input) {
        const unsigned char* token = pattern;
        const unsigned char* text = input;
        while (1) {
            unsigned char patternToken = *token;
            if (!patternToken) return 1;
            unsigned int textToken = *text;
            int memberCount;
            int minRepeat = 1;
            int maxRepeat = minRepeat;
            const unsigned char* quantifier = token;
            if (patternToken == groupStartId) {
                while (1) {
                    if (*quantifier == groupEndId) { ++quantifier; break; }
                    ++quantifier;
                }
            } else quantifier = token + 1;
            if (*quantifier == repeatStartId) {
                minRepeat = quantifier[1] - MeFont_Zero;
                maxRepeat = quantifier[3] - MeFont_Zero;
                if (quantifier[4] - MeFont_Zero == 0) maxRepeat *= 10;
            }
            int matches = 1;
            if (patternToken == wildcardId) {
                if (minRepeat == 0 && maxRepeat == SkipPattern_MaxRepeat) {
                    int terminator = token[SkipPattern_Length];
                    while (1) {
                        if (!*text || *text == NameToken_Space) return 0;
                        if (terminator == *text) break;
                        ++text;
                    }
                    token += SkipPattern_Length + 1;
                    ++text;
                    continue;
                }
            } else if (patternToken == letterClassId) {
                if (textToken < MeFont_A || textToken > MeFont_Z) matches = 0;
            } else if (patternToken == groupStartId) {
                unsigned char members[8] = {};
                int groupKind = GroupKind_Set;
                const unsigned char* source;
                unsigned char* destination = members;
                source = token + 1;
                memberCount = 0; // GroupKind_Negated until the members are counted
                int rangeId;
                int negateId;
                int endId;
                endId = self->groupEndId;
                negateId = self->negateId;
                rangeId = self->rangeId;
                int member;
                while ((member = *source, member != endId)) {
                    *destination = member;
                    if (member == negateId) memberCount = GroupKind_Negated;
                    if (member == rangeId) groupKind = GroupKind_Range;
                    ++source;
                    ++destination;
                }
                groupKind += memberCount;
                memberCount = strlen((char*)members);
                if (groupKind == GroupKind_Set) matches = NameFilter_GroupContains(self, members, memberCount, textToken);
                else if (groupKind == GroupKind_Range) {
                    unsigned int last = members[memberCount - 1];
                    matches = members[0] <= textToken && textToken <= last;
                }
                else if (groupKind == GroupKind_NegatedSet) matches = !NameFilter_GroupContains(self, members + 1, memberCount - 1, textToken);
                else if (groupKind == GroupKind_NegatedRange) {
                    unsigned int last = (members + 1)[memberCount - 2];
                    matches = !((members + 1)[0] <= textToken && textToken <= last);
                }
                token += memberCount + 1;
            } else if (patternToken != textToken) matches = 0;
            if (matches) {
                for (int repeat = 0; repeat < minRepeat; ++repeat, ++text) {
                    if (textToken != *text) { matches = 0; break; }
                }
                if (!matches) break;
                while (minRepeat < maxRepeat) {
                    if (textToken != *text) break;
                    ++minRepeat;
                    ++text;
                }
            } else if (!matches && minRepeat != 0) break;
            ++token;
            if (*token == repeatStartId) {
                while (1) {
                    if (*token == repeatEndId) break;
                    ++token;
                }
                ++token;
            }
        }
    }
    return 0;
}
