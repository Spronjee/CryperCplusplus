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
#include <ctime>
#include <string>
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
    
    cout << "Choose the mode of encrypting: \n 1. Modern way \n 2. Vernam \n 3.Gilla \n 4.Gambetta \n 5.Vertical-horizont \n 6.Wodsvord "<< endl;
    int mode;
    cin >> mode;
    switch (mode)
    {
            
            
            
        case 1:
            cout << "You chose 1 mode: \n";
            //string encrypted = encryptDecrypt(toEncrypt);
               cout << "Encrypted:" << encryptDecrypt(toEncrypt)<< "\n";
              // string decrypted = encryptDecrypt(encrypted);
               cout << "Decrypted:" << encryptDecrypt(encryptDecrypt(toEncrypt)) << "\n";
               break;
        case 2:
            
            cout << "2";
            string C,D = "";
            string A = "abcdefghijklmnopqrstuvwxyz";
            
            cout << "Enter the key: ";
            cin >> C;
            string B = toEncrypt;
            int *F = new int [B.size()];
            int *G = new int [B.size()];
            unsigned long c=C.size();
            unsigned long b=B.size();
            if (b>=c)
            {
                for (int i =0; i< (b/c); i++)
                {
                    D=D+C;
                }
                for(int j=0; j<(b%c); j++)
                {
                    D=D+C[j];
                }
            }
            else
            {
                for (int s=0; s<b; s++)
                {
                    D=D+B[s];
                }
            }
            cout << D << endl;
            for (int k=0; k<b ; k++)
            {
                for(int n=0;n <26 ;n++)
                {
                    if(B[k]==A[n])
                    {
                        F[k] =n;
                    }
                
                if (D[k]==A[n])
                {
                    G[k]=n;
                }
                }
            }
            int e=0;
            for(int u=0;u <b; u++)
            {
                e=((F[u]+G[u])%26);
                B[u] = A[u];
            }
            cout << "Your word: " << B << endl;
            break;
        default: cout << "Something happened..."<< endl;
            break;
    }
    
   
    
    return 0;
}
