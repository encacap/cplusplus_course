#include "inheritance.h"

BieuThucSoHoc::BieuThucSoHoc()
{
    srand((int)time(0));
    this->level = this->randomNumber(1, 5);
    switch (level)
    {
    case 1:
        this->max = 10;
        this->pheptoan = strdup("+");
        break;
    case 2:
        this->max = 10;
        this->pheptoan = strdup("+-");
        break;
    case 3:
        this->max = 10;
        this->pheptoan = strdup("+-*");
        break;
    case 4:
        this->max = 100;
        this->pheptoan = strdup("+-");
        break;
    case 5:
        this->max = 100;
        this->pheptoan = strdup("+-*");
        break;
    default:
        break;
    }
}

int BieuThucSoHoc::randomNumber(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

int BieuThucSoHoc::selectOperator(char allowOperator[])
{
    return this->randomNumber(0, strlen(allowOperator) - 1);
}

int BieuThucSoHoc::printQuestion()
{
    int level = this->level;
    int length = strlen(this->pheptoan);
    int operands[7] = {0};
    int result = 0;
    cout << "Level: " << level << endl;
    for (int i = 0; i <= length * 2; i++)
    {
        if (i == 0)
        {
            int num = this->randomNumber(1, max);
            result = num;
            operands[0] = 0;
            cout << num;
        }
        else if (i % 2 == 0)
        {
            int num = this->randomNumber(1, max);
            operands[i] = num;
            cout << num;
        }
        else
        {
            int operatorChar = this->selectOperator(this->pheptoan);
            switch (operatorChar)
            {
            case 0:
                result += operands[i - 1];
                cout << " + ";
                break;
            case 1:
                result -= operands[i - 1];
                cout << " - ";
                break;
            case 2:
                result *= operands[i - 1];
                cout << " * ";
                break;
            default:
                break;
            }
            // a + b + c + d
            // 1 2 3 4 5 6 7
        }
    }

    cout << endl
         << result;

    return 0;
}

int main()
{
    BieuThucSoHoc expresstions;
    BieuThucCong plusExpresstions;

    expresstions.printQuestion();
    return 0;
}