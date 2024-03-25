// File Name: CS112_A2_T3_S2_20230463_20230564_20230579
// Program: Assignment 2 - Task 3 - Fraction Calculator
// Author: Mazen Ahmed Mohamed ElShazly - 20230579 - S2 - mazenelshazly3@gmail.com
// Author: Yassin Ibrahim Samir Hafez Mohamed - 20230463 - S2 - yassinhafez661@gmail.com
// Author: Ziyad Mohamed Ahmed ElHawary - 20230564 - S2 - ziyadmohamed366@gmail.com
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;
// Define a function to simplify a fraction if needed
void simplify_fraction(int numerator, int denominator)
{
    // loop over the denominator until it equals 2
    for (int i = denominator; i >= 2; i--)
    {
        // If both the numerator and denominator are divisible by 'i', divide both by 'i'
        if (numerator % i == 0 && denominator % i == 0)
        {
            numerator = numerator / i;
            denominator = denominator / i;
        }
    }
    // If the denominator is 1, print the numerator alone
    if (denominator == 1)
    {
        cout << numerator;
    }
    else
    {
        // Else, print the simplified fraction
        cout << numerator << "/" << denominator << endl;
    }
}
int main()
{
    // Create a menu
    cout << "Welcome to the fraction calculator!";
    while (true)
    {
        cout << "\nChoose one of the following:\n1) Perform an operation\n2) Exit\n";
        string choice;
        cin >> choice;
        // If the choice is not 1 or 2, display an error message
        while (choice != "1" && choice != "2")
        {
            cout << "Invalid input. Please enter a valid choice";
            cout << "1) Perform an operation\n2) Exit\n";
            cin >> choice;
        }
        if (choice == "2")
        {
            cout << "Exiting the program.";
            break;
        }else if (choice == "1") {

            float deno1 = 1, num1, deno2 = 1, num2;
            char slash = '/';
            char oprtr;
            string input;
            cout << "Enter your expression (n/d 'operator' n/d) >>" << endl;
            cin.ignore(1, '\n');
            // Get the input string and place it in a string stream
            getline(cin, input);
            stringstream expression(input);
            expression >> num1 >> slash >> deno1 >> oprtr >> num2 >> slash >> deno2;
            // Define a regex variable for what the expression should look like
            regex validity_checker("[-+]?[0-9]+[/]*[0-9]*[ ]+[/*+-]+[ ]+[-+]?[0-9]+[/]*[0-9]*");
            string validator;
            // If the inputted string doesn't match the checker, keep asking for an input
            while ((!regex_match(input, validity_checker)) || deno1 == 0 || deno2 == 0)
            {
                cout << "Invalid input. Please enter a valid expression (n/d 'operator' n/d) >>";
                getline(cin, input);
                expression.clear();
                expression.str(input);
                expression >> num1 >> slash >> deno1 >> oprtr >> num2 >> slash >> deno2;
            }
            // Perform the desired operation based on the inputted operator
            if (oprtr == '/')
            {
                cout << num1 << '/' << deno1 << " / " << num2 << '/' << deno2 << " = ";
                simplify_fraction((num1 * deno2), (num2 * deno1));
            }
            if (oprtr == '*')
            {
                cout << num1 << '/' << deno1 << " * " << num2 << '/' << deno2 << " = ";
                simplify_fraction((num1 * num2), (deno1 * deno2));
            }
            if (oprtr == '+')
            {
                cout << num1 << '/' << deno1 << " + " << num2 << '/' << deno2 << " = ";
                simplify_fraction(((num1 * deno2) + (num2 * deno1)), (deno1 * deno2));
            }
            if (oprtr == '-')
            {
                cout << num1 << '/' << deno1 << " - " << num2 << '/' << deno2 << " = ";
                simplify_fraction(((num1 * deno2) - (num2 * deno1)), (deno1 * deno2));
            }
        }
    }
    return 0;
}