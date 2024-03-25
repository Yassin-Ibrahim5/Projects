// Program: Assignment 2 - Task 2 - Ciphers
// Authors: Mazen Ahmed Mohamed ElShazly - Rail Fence Cipher - 20230579
// Authors: Yassin Ibrahim Samir Hafez Mohamed - Vigenere Cipher - 20230463
// Authors: Ziyad Mohamed Ahmed ElHawary - Baconian Cipher - 20230564
// Date: 10/3/2024
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <sstream>
using namespace std;
// For Vigenere Cipher encryption >>
// Define a function to make the keyword repeat for the length of the message
string generate_key(string& plain_text, string& key)
{
    for (int i = 0; i < key.size() ;i++)
    {
        // Check if all characters of the keyword are letters or not
        while (isalpha(key[i]) == false)
        {
            cout << "Please enter a keyword containing letters only >> ";
            cin >> key;
        }
    }
    // Use transform() function to capitalize all letters of the keyword
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    // Make a flag that resets the iterator when it equals the length of the message
    int reset = plain_text.size();
    for (int i = 0; ;i++)
    {
        if (reset == i)
        {
            i = 0;
        }
        if (key.size() > plain_text.size())
        {
            break;
        }
        if (key.size() == plain_text.size())
        {
            break;
        }
        // Add the characters of the keyword to the key
        key.push_back(key[i]);
    }
    return key;
}
// Define a function for Vigenere Encryption
string vigenere_encrypt(string& plain_text, string& key){
    // Create a function for the actual encryption part
    string encrypted_message;
    int i;
    for(i = 0; i < plain_text.size() ; i++){
        // Checking if the character is a letter or not, if not, then the program adds it to the encrypted message as it is
        if ((isalpha(plain_text[i]) == false)){
            char x = plain_text[i];
            encrypted_message.push_back(x);
        }
            // Add the characters of the message and the key (ASCII values) then % 26 and add 'A' (or 65 ASCII)
        else {
            char x = (toupper(plain_text[i]) + key[i]) % 26;
            x = x + 'A';
            encrypted_message.push_back(x);
        }
    }
    return encrypted_message;
}
// For Baconian Cipher encryption >>
string baconian_Encrypt(string& message)
{
    string encrypted_message;
    // Loop through the characters of the message
    for (char letter : message)
    {
        if (isalpha(letter) == false)
        {
            encrypted_message += " ";
            continue;
        }
        letter = toupper(letter); // Convert the letter to uppercase
        // Convert the letter to a 6-bit binary string using a stringstream it will return 5bits at the end
        stringstream binary_Stream;
        binary_Stream << bitset<6>(letter - 'A');
        string binary = binary_Stream.str();
        // Remove the leading '0'
        encrypted_message += binary.substr(1) + " ";
    }
    // Remove the trailing space
    encrypted_message.pop_back();
    // Replace '0' and '1' with 'a' and 'b' respectively
    for (int i = 0; i < encrypted_message.length(); i++)
    {
        // Only replace characters that are '0' and '1' not spaces
        if (encrypted_message[i] == '0' || encrypted_message[i] == '1')
        {
            encrypted_message[i] = (encrypted_message[i] == '0') ? 'a' : 'b';
        }
    }
    return encrypted_message;
}
// For Railfence Cipher encryption >>
string railfence_encrypt(string& message)
{
    // Remove any whitespace characters from the input message
    message.erase(remove_if(message.begin(), message.end(), ::isspace), message.end());
    // Store the length of the message
    size_t length1 = message.length();
    // Initialize two empty strings to store the characters of the message
    string string1, string2;
    // Iterate through each character in the message
    for (size_t i = 0; i < length1; ++i)
    {
        // Calculate the index of the current character in the two strings
        size_t y = i % 2;
        // If the current index is even or zero, add the character to the first string
        if (i == 0 || y == 0)
        {
            string1 += message[i];
        }
            // Otherwise, add the character to the second string
        else
        {
            string2 += message[i];
        }
    }
    // Concatenate the two strings to get the encrypted message
    string encrypted_message = string1 + string2;
    // Return the encrypted message
    return encrypted_message;
}
// For Vigenere Cipher decryption >>
string vigenere_decrypt(string& encrypted_text, string& key)
{
    string original_message;
    int i;
    // Loop over the characters of the encrypted text
    for(i = 0; i < encrypted_text.size(); i++){
        // Check if the character is a letter or not, if not, add it to the final answer as is
        if(isalpha(encrypted_text[i]) == false){
            char x = encrypted_text[i];
            original_message.push_back(x);
        }
        else {
            // Make the letter uppercase and subtract it from the corresponding letter in the key then add 26
            // Take mod 26 of the product, then add 'A' and add it to the final answer
            char x = ((toupper(encrypted_text[i]) - key[i]) + 26) % 26;
            x = x + 'A';
            original_message.push_back(x);
        }
    }
    return original_message;
}
// For Baconian Cipher decryption >>
string baconian_decrypt(string& encrypted_message)
{
    string decrypted_message;
    // Replace 'a' and 'b' with '0' and '1' respectively
    for (int i = 0; i < encrypted_message.length(); i++)
    {
        if (encrypted_message[i] == 'a' || encrypted_message[i] == 'b')
        {
            encrypted_message[i] = (encrypted_message[i] == 'a') ? '0' : '1';
        }
    }
    // Split the encrypted message into groups of 5 characters (excluding spaces)
    stringstream messageStream(encrypted_message);
    string binary;
    while (getline(messageStream, binary, ' '))
    {
        if (binary.empty())
        {
            continue; // Skip empty groups
        }
        // Convert the 5-bit binary string to a decimal value (Binary to Decimal)
        int decimalValue = stoi(binary, nullptr, 2);
        // Add the decrypted character to 'A'
        decrypted_message += char(decimalValue + 65);
    }
    return decrypted_message;
}
// For Rail Fence Cipher decryption >>
string railfence_decrypt(string message) {
    // Initialize an empty string to store the final decrypted message
    string final_list;
    // Iterate through each character in the message
    for (int i = 0; i < message.length(); ++i) {
        // Check if the character is an alphabet character
        if (isalpha(message[i]) == false) {
            // If not, display an error message and get a new input
            cout << "Invalid input. Please enter a message that contains letters only >> " << endl;
            cin >> message;
        }
    }
    // Calculate the length of the message string
    int length = message.length();
    // Initialize two empty strings to store the first and second halves of the message
    string list1 = "", list2 = "";
    // Check if the length of the message is even
    if (length % 2 == 0) {
        // If it is, divide the message into two halves and store them in list1 and list2 respectively
        int limit = length / 2;
        for (int i = 0; i < limit; i++) {
            list1 = list1 + message[i];
        }
        while (limit < length) {
            list2 = list2 + message[limit];
            limit += 1;
        }
        // Add the characters of list1 and list2 to the final answer
        int length3 = list1.length();
        for (int i = 0; i < length3; ++i) {
            final_list = final_list + list1[i] + list2[i];
        }
        // Return the decrypted message
        return final_list;
    } else {
        // If the length of the message is odd, divide the message into two halves and store them in list1 and list2
        int limit = (length / 2) + 1.5;
        int finalChar = limit - 1;
        for (int i = 0; i < limit; i++) {
            list1 += message[i];
        }
        while (limit < length) {
            list2 = list2 + message[limit];
            limit += 1;
        }
        // Concatenate the characters of list1 and list2 in order to railfence_decrypt the message
        int length3 = list2.size();
        for (int i = 0; i < length3; ++i) {
            final_list = final_list + list1[i] + list2[i];
        }
        // Add the last character of list1 to the decrypted message
        final_list = final_list + list1[finalChar];

        // Return the decrypted message
        return final_list;
    }
}
int main()
{
    cout << "Welcome to the ciphers program!\n";
    cout << "Please choose one of the following >> \n";
    string choice1, choice2;
    while (true)
    {
        cout << "1- Encrypt a message\n2- Decrypt a message\n3- Exit\n";
        cin >> choice1;
        while (choice1 != "1" && choice1 != "2" && choice1 != "3")
        {
            cout << "Invalid input. Please choose a valid choice";
            cin >> choice1;
        }
        if (choice1 == "3")
        {
            cout << "Exiting the program";
            break;
        }
        if (choice1 == "1")
        {
            cout << "Select the cipher you want to use\n1- Vigenere Cipher\n2- Baconian Cipher\n3- Railfence Cipher\n";
            cin >> choice2;
            while (choice2 != "1" && choice2 != "2" && choice2 != "3")
            {
                cout << "Invalid input. Please choose a valid choice";
                cin >> choice2;
            }
            if (choice2 == "1")
            {
                cout << "We are now encrypting using Vigenere Cipher\n";
                string message1, keyword;
                cout << "Enter the message you want to encrypt >>";
                cin.ignore(1, '\n');
                getline(cin, message1);
                while (message1.size() >= 80)
                {
                    cout << "Please enter a message less than 80 characters";
                    getline(cin, message1);
                }
                cout << "Enter the keyword for the encryption >>";
                cin >> keyword;
                while (keyword.size() >= 8)
                {
                    cout << "Please enter a keyword less than 8 characters";
                    cin >> keyword;
                }
                string vigenere_message;
                // Call the function created earlier to make the proper key
                string key = generate_key(message1, keyword);
                // Use the key to encrypt the final message1
                vigenere_message = vigenere_encrypt(message1, key);
                cout << "The encrypted message is: " << vigenere_message << endl;
            }
            if (choice2 == "2")
            {
                cout << "We are now encrypting using Baconian Cipher\n";
                cout << "Enter the message2 you want to encrypt >>";
                string message2;
                cin.ignore(1, '\n');
                getline(cin, message2);
                string baconian_message = baconian_Encrypt(message2);
                cout << "The encrypted message2 is: " << baconian_message << endl;
            }
            if (choice2 == "3")
            {
                cout << "We are now encrypting using Railfence Cipher\n";
                cout << "Enter the message you want to encrypt >>";
                string message3;
                cin.ignore(1, '\n');
                getline(cin, message3);
                string railfence_message = railfence_encrypt(message3);
                cout << "The encrypted message is: " << railfence_message << endl;
            }
        }
        if (choice1 == "2")
        {
            cout << "Select the cipher you want to use\n1- Vigenere Cipher\n2- Baconian Cipher\n3- Railfence Cipher\n";
            cin >> choice2;
            while (choice2 != "1" && choice2 != "2" && choice2 != "3")
            {
                cout << "Invalid input. Please choose a valid choice";
                cin >> choice2;
            }
            if (choice2 == "1")
            {
                cout << "We are now decrypting using Vigenere Cipher\n";
                cout << "Enter the message you want to railfence_decrypt >>";
                string message1;
                cin.ignore(1, '\n');
                getline(cin, message1);
                while (message1.size() >= 80)
                {
                    cout << "Please enter a message less than 80 characters >>";
                    getline(cin, message1);
                }
                cout << "Enter the keyword for the decryption >>";
                string keyword;
                cin >> keyword;
                while (keyword.size() >= 8)
                {
                    cout << "Please enter a keyword less than 8 characters >>";
                    cin >> keyword;
                }
                string key = generate_key(message1, keyword);
                string original_text = vigenere_decrypt(message1, key);
                cout << "The original message is: " << original_text << endl;
            }
            if (choice2 == "2")
            {
                cout << "We are now using Baconian Cipher\n";
                cout << "Enter the message you want to railfence_decrypt >>";
                string message2;
                cin.ignore(1, '\n');
                getline(cin, message2);
                string original_text = baconian_decrypt(message2);
                cout << "The original message is: " << original_text << endl;
            }
            if (choice2 == "3")
            {
                cout << "We are now using Railfence Cipher\n";
                cout << "Enter the message you want to decrypt >>";
                string message3;
                cin.ignore(1, '\n');
                getline(cin, message3);
                string original_message = railfence_decrypt(message3);
                cout << "The original message is: " << original_message << endl;
            }
        }
    }
}