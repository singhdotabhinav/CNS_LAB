#include <bits/stdc++.h>
using namespace std;

string encrypt(string pt , string key)
{
    string ct = ""; // ciphertext
    int k = 0; // plaintext iterator
    int num_row = ceil((float) pt.length()/key.length());
    int num_col = key.length();
    char mat[num_row][num_col];

    cout << "\nEncryption Matrix :" << endl;
    cout << "---------------------" << endl;
    for(int i=0; i<num_row ; i++)
    {
        for(int j=0; j<num_col; j++)
        {
            if(k < pt.length())
            {
                cout << (mat[i][j] = pt[k++]) << " ";
            }
            else
            {
                cout << (mat[i][j] = 'x') << " " ;
            }
        }
    cout << endl;
    }
    for(int i=0; i<num_col; i++)
    {
        for(int j=0; j<num_row; j++)
        {
            ct += mat[j][key.find(i+'1')];
        }
    }
    return ct;
}
int main()
{
    string plaintext , key , ciphertext , decryptext;
    cout << "Enter text : ";
    cin >> plaintext;
    cout << "Enter key : ";
    cin >> key;
    ciphertext = encrypt(plaintext , key);
    cout << "\nEncrypted text \t: " << ciphertext << endl;
 //decryptext = decrypt(ciphertext , key);
 //cout << "\nDecrypted text \t: " << decryptext << endl;
}
