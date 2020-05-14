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

    if (level == 1)
    {
        this->max = 10;
        this->pheptoan = strdup("+");
        return;
    }

    if (level == 2)
    {
        this->max = 10;
        this->pheptoan = strdup("+-");
        return;
    }

    if (level == 3)
    {
        this->max = 10;
        this->pheptoan = strdup("+-*/");
        return;
    }

    if (level == 4)
    {
        this->max = 100;
        this->pheptoan = strdup("+-");
        return;
    }

    if (level == 5)
    {
        this->max = 100;
        this->pheptoan = strdup("+-*/");
        return;
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
    int operands[9] = {0};
    int operators[9] = {0};
    float result = 0;
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

    for (int i = 0; i < 9; i++)
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
        else if (operators[i] == 4)
        {
            if (operands[i - 1] == 0)
            {
                result /= (float)operands[i + 1];
                operands[i + 1] = 0;
            }
            else
            {
                result += (float)operands[i - 1] / operands[i + 1];
                operands[i - 1] = operands[i + 1] = 0;
            }
        }

    for (int i = 0; i < 9; i++)
    {
        if (operators[i] == 1)
            result += operands[i - 1] + operands[i + 1];
        else if (operators[i] == 2)
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
    float answer;
    float question = 0;
    BieuThucSoHoc expresstions;
    BieuThucCong plusExpresstions;
    cout << "Moi luot choi se co " << questionsPerTurn << " cau hoi." << endl;
    cout << "So diem ban nhan duoc o moi luot tuong duong voi cap do cua cau hoi" << endl;
    cout << "**Chu y: Doi voi phep chia, ket qua chi lay phan nguyen!" << endl;
    for (int i = 0; i < questionsPerTurn; i++)
    {
        question = expresstions.printQuestion();
        cin >> answer;
        if (answer == question)
        {
            cout << "Chinh xac!";
            expresstions.updateScore();
        }
        else
        {
            cout << "Khong chinh xac!";
        }
        cout << endl;
    }

    cout << LINE << endl;
    cout << "Key thuc! Tong so diem cua ban la: " << expresstions.score;

    return 0;
}