/*#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {

    ofstream fout;
    fout.open("text.txt");


    if (!fout.is_open())
    {
        cout << "Oops..something is wrong" << endl;
    }
    else
    {
        fout << "Again against the world";
    }
    fout.close();
    ifstream fin;
    fin.open("text.txt");

    if (!fin.is_open())
    {
        cout << "can't be opened" << endl;
    }
    else
    {
        string strd;
        //char strd[50];
        while (fin >> strd)
        {
            if (strd[0] == 'a' || strd[0] == 'A')
            {
                cout << strd << endl;
            }
        }
        
    }
    
    fin.close();

    return 0;

}
*/
#include <iostream>
#include <fstream>

using namespace std;

string encryptDecrypt(string toEncrypt) {
    
    char key[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N'}; //Any chars will work, in an array of any size
    string output = toEncrypt;
   
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    
    
    return output;
}

int main(int argc, const char * argv[])
{
    setlocale(LC_ALL, "");
    string toEncrypt;
    cout << "Enter the text u wanna encrypt: "<< endl;
    getline(cin, toEncrypt );
    
    cout << "Choose the mode of encrypting: \n 1. Modern way \n 2. Vernam \n 3.Gilla \n 4.Gambetta \n 5."<< endl;
    int mode;
    cin >> mode;
    switch (mode)
    {
        case 1:
            
            cout << "1";
            break;
        case 2:
            cout << "2";
        default: cout << "Something happened..."<< endl;
            break;
    }
    
    string encrypted = encryptDecrypt(toEncrypt);
    cout << "Encrypted:" << encrypted << "\n";
    
    string decrypted = encryptDecrypt(encrypted);
    cout << "Decrypted:" << decrypted << "\n";
    
    return 0;
}
