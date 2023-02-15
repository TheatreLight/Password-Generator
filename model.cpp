#include "model.h"

Model::Model() {}

std::string Model::GetPwd(int mode, int number) {
    std::string s;
    while (!CheckRules(s, mode)) {
        s.clear();
    for (int i = 0; i < number; ++i) {
        if (mode == 1) {
            char ch = OneLevelGen(i);
            while (CheckRepeat(s, ch)) {
                ch = OneLevelGen(i);
            }
            s.append(1, ch);
        }
        if (mode == 2) {
            char ch = TwoLevelGen(i);
            while (CheckRepeat(s, ch)) {
                ch = TwoLevelGen(i);
            }
            s.append(1, ch);
        }
        if (mode == 3) {
            char ch = ThreeLevelGen(i);
            while (CheckRepeat(s, ch)) {
                ch = ThreeLevelGen(i);
            }
            s.append(1, ch);
        }
    }
    }
    if (s.length() == 0) {
        s = "Something was wrong";
    }
    return s;
}

char Model::LetterGen(int step)
{
    int choice = RandomChoice(97, 26, step);
    return (char)choice;
}

char Model::NumberGen(int step)
{
    int choice = RandomChoice(48, 10, step);
    return (char)choice;
}

char Model::UpLetterGen(int step)
{
    int choice = RandomChoice(65, 26, step);
    return (char)choice;
}

char Model::SymbolGen(int step)
{
    int choice = RandomChoice(0, 16, step);
    return symbols[choice];
}

int Model::RandomChoice(int offset, int limit, int step)
{
    unsigned now = (unsigned)time(NULL);
    std::srand(now + step);
    return offset + (rand()%limit);

}

char Model::OneLevelGen(int step)
{
    int choice = RandomChoice(0, 2, step);
    if (choice == 0)
        return LetterGen(step);
    return NumberGen(step);
}

char Model::TwoLevelGen(int step)
{
    int choice = RandomChoice(0, 3, step);
    if (choice == 0)
        return LetterGen(step);
    if (choice == 1)
        return NumberGen(step);
    return UpLetterGen(step);
}

char Model::ThreeLevelGen(int step)
{
    int choice = RandomChoice(0, 4, step);
    if (choice == 0)
        return LetterGen(step);
    if (choice == 1)
        return NumberGen(step);
    if (choice == 2)
        return UpLetterGen(step);
    return SymbolGen(step);
}

bool Model::CheckRepeat(std::string &s, char ch)
{
    int repeat_count = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == ch)
            repeat_count++;
        if (repeat_count >= 2)
            return true;
    }
    return false;
}

bool Model::CheckRules(std::string &s, int mode)
{
    bool b = true;
    int letters = 0;
    int numbers = 0;
    int upletters = 0;
    int symbols = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] >= 97 && s[i] <= 122)
            letters++;
        if (s[i] >= 48 && s[i] <= 57)
            numbers++;
        if (s[i] >= 65 && s[i] <= 90)
            upletters++;
        if (SymbolCheck(s[i]))
            symbols++;
    }
    if (letters < 2) b = false;
    if (numbers < 2) b = false;
    if (upletters < 1 && mode > 1) b = false;
    if (symbols < 1 && mode > 2) b = false;
    return b;
}

bool Model::SymbolCheck(char ch) {
    for (auto elem : symbols) {
        if (ch == elem)
            return true;
    }
    return false;
}
