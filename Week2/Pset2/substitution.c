#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int verify_key(string key);
string transformation (string word, char cipher[]);
//char convert_key (string key);


int main (int argc, string argv[])
{
    //Verifiy if the comand-line arguments are correct
    if (argc != 2)
    {
        printf ("Unvalid number of arguments!");
        return 1;
    }
    //Verificfy if the key is valid
    int verification = verify_key(argv[1]);
    // In the case, that the Key is invalid, than main function will return 1 (falied)
    if (verification == 1)
    {
        return 1;
    }
    //Convert the Key in a array
    char KEY[26];
    for (int i =0; i <26; i++)
        {
            KEY[i]=argv[1][i];
        }
    // Aks the user for the word:
    string word = get_string("plaintext: ");
     //Print the ciphertext calling the function transformation;
    printf ("ciphertext: %s\n", transformation(word, KEY));
    return 0;
}


int verify_key(string key)
{
    char LETTERS[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int count = 0;
    char substitution = '!';
    if (strlen(key) != 26 )
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i =0; i <26;i++)
        {
            for (int j=0; j<26; j++)
            {
                if (toupper(key[i])==LETTERS[j])
                {
                    count+=1;
                    LETTERS[j] = substitution;
                }
            }
        }
        if (count == 26)
        {
            printf("Valid Key!\n");
            return 0;
        }
        else
        {
            printf("Key has not valid caracteres\n");
            return 1;
        }

    }

}

string transformation (string word, char cipher[])
{
    char LETTERS[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string ciphertext = word;
    for (int i =0, n=strlen(word); i<n; i++)
    {
        for (int j =0; j<26; j++)
        {
            if (word[i]==LETTERS[j])
            {
                ciphertext[i] =toupper(cipher[j]);
                break;
            }
            else if (word[i]==tolower(LETTERS[j]))
            {
                ciphertext[i] =tolower(cipher[j]);
                break;
            }
        }
    }
    return ciphertext;
}

