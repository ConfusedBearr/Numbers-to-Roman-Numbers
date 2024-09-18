//Coded by Rodrigo Peixoto
//Coded on 03/20/2023
//Purpose to turn numbers between 1 and 1000 into roman numerals

#include <iostream>
#include <string>

using namespace std;

string romanNumeral(int num);

int main() {
    int input;
    char choice;
    // The do loop, so it can keep looping till the user says "n" to stop
    do{
        cout << "Enter a number between 1 and 1000: ";
        cin >> input;

        //Checks to see if the number entered is between 1 and 1000
        if(input < 1 || input > 1000){
            cout << "Invalid input. Enter a number between 1 and 1000: " << endl;
            continue;
        }

        //uses the users number inputted into the roman numeral calculator I made
        string roman = romanNumeral(input);
        cout << "Roman numeral: " << roman << endl;

        //Asks the user if they want to run again
        cout << "Enter another number? (y/n): ";
        cin >> choice;

    }   while (tolower(choice) == 'y');
    return 0;
}

string romanNumeral(int num){
    //empty string to return roman numeral
    string roman = "";
    //settings array to the number each letter indicates
    int values[] = {1000, 500, 100, 50, 10, 5, 1};
    //giving everything letters for each number
    char symbols[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int i = 0;
    //sets a loop to find the roman numeral for the number given
    while (num > 0) {
        int digit = num / values[i];
        if (digit > 0) { // if the digit is greater than zero add the correct letter for each number
            if (digit == 4) { // if the digit is 4 use subtraction notation
                roman += symbols[i];
                roman += symbols[i-1];
            } else if (digit == 9) { // if the digit is 9 use subtraction notation
                roman += symbols[i];
                roman += symbols[i-2];
            } else { // if the digit isnt 4 or 9 we add the corresponding symbols to the string
                if (digit >= 5) roman += symbols[i-1];
                for (int j = 0; j < digit % 5; j++){
                    roman += symbols[i];
                }
            }
            num -= digit * values[i];
        }
        i++;
    }
    return roman;
}