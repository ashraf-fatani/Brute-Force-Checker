#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int main()
{
    string password;
    cout << "====================================\n";
    cout << "    Brute Force Password Checker\n";
    cout << "====================================\n\n";
    cout << "Enter password: ";
    cin >> password;
    int length = password.length();
    bool lowercase = false;
    bool uppercase = false;
    bool number = false;
    bool symbol = false;

    // Analyze the password
    for (char c : password)
    {
        if (islower(c))
        {
            lowercase = true;
        }
        else if (isupper(c))
        {
            uppercase = true;
        }
        else if (isdigit(c))
        {
            number = true;
        }
        else
        {
            symbol = true;
        }
    }

    // Count character types
    int types = 0;
    if (lowercase)
        types++;
    if (uppercase)
        types++;
    if (number)
        types++;
    if (symbol)
        types++;

    cout << "\n========== Password Analysis ==========\n";
    cout << "Length: " << length << endl;
    cout << "Lowercase: "
         << (lowercase ? "Yes" : "No") << endl;
    cout << "Uppercase: "
         << (uppercase ? "Yes" : "No") << endl;
    cout << "Numbers: "
         << (number ? "Yes" : "No") << endl;
    cout << "Symbols: "
         << (symbol ? "Yes" : "No") << endl;

    // Build the character set
    string characters;
    if (lowercase)
        characters += "abcdefghijklmnopqrstuvwxyz";
    if (uppercase)
        characters += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (number)
        characters += "0123456789";
    if (symbol)
        characters += "!@#$%^&*";

    // Actual brute force for short passwords
    if (length <= 4)
    {
        cout << "\nStarting brute force...\n";
        long long attempts = 0;
        bool found = false;

        // 1 character
        for (char a : characters)
        {
            string guess;
            guess += a;
            attempts++;
            if (guess == password)
            {
                found = true;
                break;
            }
        }

        // 2 characters
        if (!found && length >= 2)
        {
            for (char a : characters)
            {
                for (char b : characters)
                {
                    string guess;
                    guess += a;
                    guess += b;
                    attempts++;
                    if (guess == password)
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
        }

        // 3 characters
        if (!found && length >= 3)
        {
            for (char a : characters)
            {
                for (char b : characters)
                {
                    for (char c : characters)
                    {
                        string guess;
                        guess += a;
                        guess += b;
                        guess += c;
                        attempts++;
                        if (guess == password)
                        {
                            found = true;
                            break;
                        }
                    }
                    if (found)
                        break;
                }
                if (found)
                    break;
            }
        }

        // 4 characters
        if (!found && length == 4)
        {
            for (char a : characters)
            {
                for (char b : characters)
                {
                    for (char c : characters)
                    {
                        for (char d : characters)
                        {
                            string guess;
                            guess += a;
                            guess += b;
                            guess += c;
                            guess += d;
                            attempts++;
                            if (guess == password)
                            {
                                found = true;
                                break;
                            }
                        }
                        if (found)
                            break;
                    }
                    if (found)
                        break;
                }
            }
        }
        cout << "\n========== Brute Force Result ==========\n";
        cout << "Password found: "
             << (found ? "Yes" : "No") << endl;
        cout << "Attempts: " << attempts << endl;
    }

    // Theoretical attempts for long passwords
    else
    {
        double attempts = pow(characters.length(), length);
        cout << "\n========== Brute Force Analysis ==========\n";
        cout << "Password is too long for an actual brute-force demonstration.\n";
        cout << "Attempts needed: " << attempts << endl;
    }

    // Password resistance
    cout << "\n========== Password Resistance ==========\n";
    if (length <= 4 && types == 1)
        cout << "Resistance: Very Easy\n";
    else if (length <= 6 && types <= 2)
        cout << "Resistance: Easy\n";
    else if (types < 4)
        cout << "Resistance: Medium\n";
    else if (length >= 12 && types == 4)
        cout << "Resistance: Very Hard\n";
    else
        cout << "Resistance: Hard\n";
    return 0;
}