#include "inheritance.h"

BieuThucSoHoc::BieuThucSoHoc()
{
    this->point = 0;
    this->score = 0;
}

void BieuThucSoHoc::createQuestion()
{
    this->level = this->randomNumber(1, 5);
    this->point = level;
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
    this->createQuestion();
    this->point = this->level;
    int level = this->level;
    int length = strlen(this->pheptoan);
    int operands[7] = {0};
    int operators[7] = {0};
    int result = 0;
    cout << LINE << endl;
    cout << "Level: " << level << endl;
    cout << "Current score: " << this->score << endl;
    cout << ">> ";
    for (int i = 0; i <= length * 2; i++)
    {
        if (i % 2 == 0)
        {
            int num = this->randomNumber(1, max);
            operands[i] = num;
            cout << num;
        }
        else
        {
            int o = this->selectOperator(this->pheptoan);
            operators[i] = o + 1;
            cout << " " << this->pheptoan[o] << " ";
        }
    }

    cout << " = ";

    for (int i = 0; i < 7; i++)
        if (operators[i] == 3)
        {
            if (operands[i - 1] == 0)
            {
                result *= operands[i + 1];
                operands[i + 1] = 0;
            }
            else
            {
                result += operands[i - 1] * operands[i + 1];
                operands[i - 1] = operands[i + 1] = 0;
            }
            operators[i] = 0;
        }

    for (int i = 0; i < 7; i++)
    {
        if (operators[i] == 1)
            result += operands[i - 1] + operands[i + 1];
        else
            result += operands[i - 1] - operands[i + 1];
        operands[i - 1] = operands[i + 1] = 0;
    }

    return result;
}

void BieuThucSoHoc::updateScore()
{
    this->score += this->point;
}

int main()
{
    srand((int)time(0));
    int questionsPerTurn = 5; // Number of questions per turn
    int answer;
    int question = 0;
    BieuThucSoHoc expresstions;
    BieuThucCong plusExpresstions;
    cout << "Each round will have " << questionsPerTurn << " question." << endl;
    cout << "The number of points received will correspond to the level of the question" << endl;
    for (int i = 0; i < questionsPerTurn; i++)
    {
        question = expresstions.printQuestion();
        cin >> answer;
        if (answer == question)
        {
            cout << "Congratulation!";
            expresstions.updateScore();
        }
        else
        {
            cout << "Incorrect";
        }
        cout << endl;
    }

    return 0;
}