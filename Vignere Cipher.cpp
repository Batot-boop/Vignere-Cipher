#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

string ValidInput(string TextInput);
string LimitedCharForEncryptOrDecrypt(string TextInputEncryptOrDecrypt);
string LimitedCharForKeyWords(string TextInputkeywords);
string ConvertToUpperCase(string TextInput);
void TheProcessOfEnOrDe(int NumberOfChoice);

int main()
{
    int NumberOfChoice;
    
    while(true)
    {
        cout << "\n** Vignere Cipher **\n" << endl;
        cout << "1- Cipher a message." << endl;
        cout << "2- Decipher a message." << endl;
        cout << "3- End." << endl;
        cout << "\nEnter a number your choice: "; 
        while(true)
        {
            // Verify that the entry integer number
            while(!(cin >> NumberOfChoice))
            {
                cout << "Please Enter a valid choice: ";
                cin.clear();
                cin.ignore(123,'\n');
            }
            
            if(NumberOfChoice == 1 || NumberOfChoice == 2 || NumberOfChoice == 3)
                break;
  
            else
                cout << "Please enter 1,2 or 3: ";
        }
        
        if(NumberOfChoice == 3)
        {
            cout << "\nEnd Program.\n" << endl;
            break;
        }
        
        // This code removes extra spaces when entering the desired value
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        TheProcessOfEnOrDe(NumberOfChoice); // <========= This Funnction Main Block Of Code.
    }
    return 0;    
}

string ValidInput(string TextInput)
{
    while(cin >> TextInput)
    {
        bool ContainsOnlyLetters = true;
        for(char ch : TextInput)
        {
            if(!isalpha(ch))
            {
                ContainsOnlyLetters = false;
                break;
            }
        }
        if(ContainsOnlyLetters)
            break;
        else
            cout << "Error! Pleaes enter a valid input: ";
    }
    return TextInput;
}

string LimitedCharForEncryptOrDecrypt(string TextInputEncryptOrDecrypt)
{
    while(true)
    {
        string ResetInputEnOrDe;
        if(TextInputEncryptOrDecrypt.size() <= 80)
        {
            return TextInputEncryptOrDecrypt;
            break;
        }
        if(!(TextInputEncryptOrDecrypt.size() < 80))
            cout << "Error! Please enter text in limit from 1 to 80 charater: ";
            ResetInputEnOrDe = ValidInput(ResetInputEnOrDe);
            ResetInputEnOrDe = ConvertToUpperCase(ResetInputEnOrDe);
            ResetInputEnOrDe = LimitedCharForEncryptOrDecrypt(ResetInputEnOrDe);
            return ResetInputEnOrDe;
    }
}

string LimitedCharForKeyWords(string TextInputkeywords)
{
    while(true)
    {
        string ResetInputKey;
        if(TextInputkeywords.size() <= 8)
        {
            return TextInputkeywords;
            break;
        }
        if(!(TextInputkeywords.size() < 8))
        {
            cout << "Error! Please enter text in limit from 1 to 8 charater: ";
            ResetInputKey = ValidInput(ResetInputKey);       
            ResetInputKey = ConvertToUpperCase(ResetInputKey);       
            ResetInputKey = LimitedCharForKeyWords(ResetInputKey);       
        }

    }
}

string ConvertToUpperCase(string TextInput)
{
    string Text = TextInput;
    transform(Text.begin(),Text.end(),Text.begin(), ::toupper);
    return Text;
}

void TheProcessOfEnOrDe(int NumberOfChoice)
{
       string TextInputEnOrDe, KeyWord, TextOutputEnOrDe;
       int NumberOfAscii, Key;
       
       // Enter and verify whether the variable meets the conditions mentioned or not
        cout << "\nPlain Text: ";
        getline(cin, TextInputEnOrDe);
        
        // To specify the number of characters entered from 1 to 80
        TextInputEnOrDe = LimitedCharForEncryptOrDecrypt(TextInputEnOrDe); 
        
        // To convert small letter inro large
        TextInputEnOrDe = ConvertToUpperCase(TextInputEnOrDe);

        // Enter and verify whether the variable meets the conditions mentioned or not
        cout << "\nKeyword: ";

        // To verify that the entries are only alphabetical
        KeyWord = ValidInput(KeyWord);

        // To convert small letter inro large
        KeyWord = ConvertToUpperCase(KeyWord);

        // To specify the number of characters entered from 1 to 8
        KeyWord = LimitedCharForKeyWords(KeyWord);

        // Area started decryption
        for(int i = 0; i < TextInputEnOrDe.size(); i++)
        {
            // Two conditions that prevent symbols and numbers from entering mathematical operations
            if(isspace(TextInputEnOrDe[i]) || !isalpha(TextInputEnOrDe[i]))
            {
                TextOutputEnOrDe += char(TextInputEnOrDe[i]);
                continue;
            }
            
            // Encrypt the desired word
            else if(NumberOfChoice == 1)
            {
                // To calculate the encrypted text with keyword
                NumberOfAscii = ( ( int(TextInputEnOrDe[i]) + int(KeyWord[i % KeyWord.size()]) ) % 26 ) + 65;
            }
            
            // Decrypt the desired word
            else if(NumberOfChoice == 2)
            {
                // To calculate the keyword
                Key = (KeyWord[i % KeyWord.size()] - 65) % 26;
                
                // To calculate the decrypted text
                NumberOfAscii = ( (int(TextInputEnOrDe[i]) - 65 - Key + 26) % 26) + 65;
            }
            // Sum EnOrDe text
            TextOutputEnOrDe += char(NumberOfAscii);  
        }
        
        if(NumberOfChoice == 1)
            cout << "\nCipher Text: " << TextOutputEnOrDe << "\n\n";
       
        else if(NumberOfChoice == 2)
            cout << "\nDecipher Text: " << TextOutputEnOrDe << "\n\n";
}