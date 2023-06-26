#include <iostream>
#include <stdlib.h>
#include <time.h>
#define NUMBERS 5
#define MIN 1
#define MAX 45
#define JOCKER 1
#define JOCKERMIN 1
#define JOCKERMAX 20
using namespace std;


int getRandom(int min, int max)
{
    max = max - min + 1;

    int r = rand() % max + min;

    return r;
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void bubbleShort(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int swaps = 0;

        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swaps = 1;
            }
        }
        if (!swaps)
            break;
    }
}

void initArray(int pinax[], int length)
{
    for (int i = 0; i < length; i++)
    {
        pinax[i] = 0;
    }
}

void printArray(int pinax[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << pinax[i] << "\t";
    }
}

bool hasNumber(int pinax[], int length, int num)
{
    bool is = false;

    for (int i = 0; i < length; i++)
    {
        if (num == pinax[i])
        {
            is == true;
            break;
        }
    }
    return is;
}

void setRow(int pinax[], int length)
{
    int num;
    int counter = 0;

    do
    {
        num = getRandom(MIN, MAX);

        if (!hasNumber(pinax, length, num))
        {
            pinax[counter] = num;
            counter++;
        }

    } while (counter < length);
}
void initArrayJocker(int pinax[], int length)
{
    for (int i = 0; i < length; i++)
    {
        pinax[i] = 0;
    }
}

void printArrayJocker(int pinax[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << pinax[i] << "\t";
    }
    cout << endl << endl<< endl<< endl<< endl;
}

void setRowJocker(int pinax[], int length)
{
    int num;
    int counter = 0;

    do
    {
        num = getRandom(JOCKERMIN, JOCKERMAX);

        if (!hasNumber(pinax, length, num))
        {
            pinax[counter] = num;
            counter++;
        }

    } while (counter < length);
}
int main()
{
    int row[NUMBERS];
    int jocker[JOCKER];
    int draws;

    srand(time(0));

    cout << "Give number of draws: ";
    cin >> draws;

    for (int i = 0; i < draws; i++)
    {
        initArray(row, NUMBERS);
        initArrayJocker(jocker, JOCKER);

        setRow(row, NUMBERS);
        setRowJocker(jocker, JOCKER);

        bubbleShort(row, NUMBERS);

        printArray(row, NUMBERS);cout << " jocker\t";
        printArrayJocker(jocker, JOCKER);
    }


    return 0;
}
