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
string secondMethod(string toEncrypt){
    cout << "Requirements about using this ciepher: \n 1.It can't be too long text \n 2.Write the key without spaces \n 3.The key can't be shorter than text \n";
string C,D = "";
           string A = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.()1234567890!;:-? ";
    //
           cout << "Enter the key: ";
           cin >> C;
    
    cout << "Decrypted: " << endl;
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
           
           int e=0;
           for(int u=0;u <b; u++)
           {
               e=((F[u]+G[u])%26);
               B[u] = A[u];
           }
           }
    cout << "Encrypted: " << endl;
    return B;
    
}
string encryptDecrypt(string toEncrypt) {
    
    char key[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N'};
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
    
    
    ifstream fin;
    fin.open("text.txt");
    getline(cin, toEncrypt );
    
    cout << "Choose the mode of encrypting: \n 1.Modern way \n 2.Vizhener \n 3.Gilla \n 4.Gambetta \n 5.Vertical-horizont \n 6.Wodsvord "<< endl;
    int mode;
    cin >> mode;
     ofstream fout;
    string start,end;
    switch (mode)
    {
            
            
            
        case 1:
            cout << "You chose 1 mode: \n";
            start = encryptDecrypt(toEncrypt);
            end = encryptDecrypt(encryptDecrypt(toEncrypt));
            cout << "Encrypted: " << start;
            cout << "Decrypted: " << end;
              // cout << "Encrypted:" << encryptDecrypt(toEncrypt)<< "\n";
               //cout << "Decrypted:" << encryptDecrypt(encryptDecrypt(toEncrypt)) << "\n";
           
            fout.open("text.txt", std::ios::app);
            if (!fout.is_open())
            {
                cout << "Oops..something is wrong" << endl;
            }
            else
            {
                fout << start << " " << end;
            }
            
            
               break;
        case 2:
            
            cout << "You chose 2 mode: \n";
            cout << secondMethod(toEncrypt) << "\n";
            break;
            
        case 3:
            cout << "You chose 3 mode: \n";
        default: cout << "Something happened..."<< endl;
            break;
    }
    
   
    
  //  fout.close();
  //  ifstream fin;
    fin.open("text.txt");

    if (!fin.is_open())
    {
        cout << "can't be opened" << endl;
    }
    
     fin.close();
    
    return 0;
}
