#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>

using namespace std;

class BieuThucSoHoc
{
public:
    int a, b, level, max = 10;
    char *pheptoan;
    BieuThucSoHoc();
    int randomNumber(int min, int max);
    int printQuestion();
    int selectOperand(int maximum);
    int selectOperator(char allowOperator[]);
};

class BieuThucCong : public BieuThucSoHoc
{
};