#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <ctime>
#include <cctype>

class Model
{
public:
    Model();
    std::string GetPwd(int mode, int number, int seed);


private:
    std::vector<char> symbols {'~', '!', '@', '?',
                               '#', '$', '%', '^',
                               '&', '*', '+', '-',
                               '/', '_', '<', '>'};
    char LetterGen(int step);
    char NumberGen(int step);
    char UpLetterGen(int step);
    char SymbolGen(int step);
    int RandomChoice(int offset, int limit, int step);
    char OneLevelGen(int step);
    char TwoLevelGen(int step);
    char ThreeLevelGen(int step);
    bool CheckRepeat(std::string& s, char ch);
    bool CheckRules(std::string& s, int mode);
    bool SymbolCheck(char ch);
};

#endif // MODEL_H
