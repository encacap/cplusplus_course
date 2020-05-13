#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>

#define LINE "=================================="

using namespace std;

class BieuThucSoHoc
{
public:
    int level, max, point, score = 0;
    char *pheptoan;
    BieuThucSoHoc();
    int randomNumber(int min, int max);
    int printQuestion();
    int selectOperand(int maximum);
    int selectOperator(char allowOperator[]);
    void createQuestion();
    void updateScore();
};

class BieuThucCong : public BieuThucSoHoc
{
};