//Program simulates a password authentication system using a
//randomized-challenge response system.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

const int ARRAY_SIZE = 10;
const int PASSWORD_DIGITS = 5;

void input(int userPassword[], int size);
//Precondition: size == 5.
//Postcondition: All elements of userInput has been initialized.

void generateRandomNumbers(int randomNumbers[], int size);
//Precondition: size == 10;
//Postcondition: All elements of the array randomNumbers has been 
//initialized.

void displayUserScreen(int pinNumbers[], int randomNumbers[], int size);
//Precondition: All elements of the array pinNumbers and randomNumbers have
//been initialized. size ==  10.
//Postcondition: Outputs the elements of both arrays pinNumbers and
//randomNumbers.

void outputSystemResponse(bool& systemResponse);
//Precondition: systemResponse has been initialized.
//Postcondition: Outputs whether the users pin input data was correct.

void authenticatePassword(int userPassword[], int passwordOnRecord[], int size1, int randomNumbers[], int size2, bool& systemResponse);
//Precondition: All element of the arrays userPassword, passwordOnRecord, and
//randomNumbers have been initialized. 
//Postcondition: Returns true if the users password is equal to the stored
//password and false if not.

int main()
{
    int userPassword[PASSWORD_DIGITS];
    int passwordOnRecord[PASSWORD_DIGITS] = {1,2,3,4,5};
    int pinNumbers[ARRAY_SIZE] = {0,1,2,3,4,5,6,7,8,9};
    int  randomNumbers[ARRAY_SIZE], count = 0;
    bool systemResponse;

    do
    {
        displayUserScreen(pinNumbers, randomNumbers, ARRAY_SIZE);
        input(userPassword, PASSWORD_DIGITS);
        authenticatePassword(userPassword, passwordOnRecord, PASSWORD_DIGITS, randomNumbers, ARRAY_SIZE, systemResponse);
        outputSystemResponse(systemResponse);
    }while(!systemResponse);

    return 0;
}

void input(int userPassword[], int size)
{
    int n;
    cout<<"\nEnter PIN: ";
    for (int i = 0; i < size; i++)
    {
        cin>>n;
        userPassword[i] = n;
    }
}

void authenticatePassword(int userPassword[], int passwordOnRecord[], int size1, int randomNumbers[], int size2, bool& systemResponse)
{
    int digitsCorrect = 0;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (userPassword[i] == randomNumbers[j] && j == passwordOnRecord[i])
                ++digitsCorrect;
        }
    }

    if (digitsCorrect == 5)
        systemResponse = true;
    else 
        systemResponse = false;
}

void generateRandomNumbers(int randomNumbers[], int size)
{
    for (int i = 0; i < size; i++)
        randomNumbers[i] = rand() % 3 + 1;
}

void displayUserScreen(int pinNumbers[], int randomNumbers[], int size)
{
    generateRandomNumbers(randomNumbers, ARRAY_SIZE);

    cout<<"PIN: ";
    for (int i = 0; i < size; i++)
        cout<<pinNumbers[i]<<" ";

    cout<<"\nNUM: ";
    for (int i = 0; i < size; i++)
        cout<<randomNumbers[i]<<" ";

    cout<<endl;
}

void outputSystemResponse(bool& systemResponse)
{
    if (systemResponse == true)
        cout<<"PIN confirmed. Thank you.\n\n";
    else
    {
        cout<<"PIN denied. Please try again.\n\n";
        systemResponse = false;
    }
}
