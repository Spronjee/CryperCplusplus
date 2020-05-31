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
    string encrypted = encryptDecrypt("Gamers will not order the world");
    cout << "Encrypted:" << encrypted << "\n";
    
    string decrypted = encryptDecrypt(encrypted);
    cout << "Decrypted:" << decrypted << "\n";
    
    return 0;
}
