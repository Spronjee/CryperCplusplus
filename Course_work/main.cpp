#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

string secondMethod(string toEncrypt){
    cout << "Requirements about using this ciepher: \n 1.It can't be too long text \n 2.Write the key without spaces \n 3.The key can't be shorter than text \n";
string C,D = "";
           string A = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.()1234567890!;:-? ";
    
           cout << "Enter the key: ";
           cin >> C;
    
    cout << "Decrypted: " << endl;
    auto begin1 = chrono::high_resolution_clock::now();
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
     auto ending1 =chrono::high_resolution_clock::now();
    
    cout << "Encrypted: " << toEncrypt << endl;
     cout << "Потраченное время: "<< chrono::duration_cast<chrono::nanoseconds>(ending1 - begin1).count()<< " ns"<< endl;
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
    //setlocale(LC_ALL, "");
    string toEncrypt;
    cout << "Enter the text u wanna encrypt: "<< endl;
    
    getline(cin, toEncrypt);
    
    cout << "Choose the mode of encrypting: \n 1.Gambet \n 2.Vizhener \n 3.Gilla \n 4.Wodsvord ?"<< endl;
    int mode;
    cin >> mode;
  
    string start,end;
    
    switch (mode) {
        
        case 1:
        {
            cout << "You chose 1 mode: \n";
            auto begin = chrono::high_resolution_clock::now();
            start = encryptDecrypt(toEncrypt);
            auto ending =chrono::high_resolution_clock::now();
            end = encryptDecrypt(encryptDecrypt(toEncrypt));
            ofstream fout;
            fout.open("Input.txt");


            if (!fout.is_open())
            {
                cout << "Oops..something is wrong" << endl;
            }
            else
            {
                fout << "Your encrypted text: " << start << endl;
                fout << "Your decrypted text: " << end << endl;
                
            }
            fout.close();
            cout << "Encrypted: " << end << endl;
            cout << "Decrypted: " << start << endl;
            cout << "Потраченное время: "<< chrono::duration_cast<chrono::nanoseconds>(ending - begin).count()<< " ns"<< endl;
              // cout << "Encrypted:" << encryptDecrypt(toEncrypt)<< "\n";
               //cout << "Decrypted:" << encryptDecrypt(encryptDecrypt(toEncrypt)) << "\n";
           
               break;
        }
        case 2:
        {
            string start2;
            cout << "You chose 2 mode: \n";
            
            start2 = secondMethod(toEncrypt);
           
            
            ofstream fout;
            fout.open("Input.txt");


            if (!fout.is_open())
            {
                cout << "Oops..something is wrong" << endl;
            }
            else
            {
                fout << "Your encrypted text: " << start2 << endl;
                
            }
            fout.close();
            cout << "Encrypted: "<< start2 << endl;
           
            break;
        }
        case 3:
        {
            ofstream ffout;
            ffout.open("messege.txt");
            
            if (ffout.is_open())
            {
                ffout << toEncrypt;
            }
            ffout.close();
            cout << "You chose 3 mode: \n";
            char *source_text;
              char *ciphertext;
              int symbol_amount;
              int string_amount;
              int colum_amount;
              int index;
              
            int file_length;
              ifstream fin("messege.txt");
            
              if (!fin.is_open())
              {
                cout << "can't be opened \n";
              }
              else {
               
                cout << "How many characters to read from a file? " << endl;
                cin >> file_length;
                source_text = new char[file_length];
                fin.getline(source_text, file_length);
                cout << endl << "Text: " << endl;
                  
                  
                  
                for (int i = 0; i < file_length; i++) {
                  cout << source_text[i];
                }
                cout << endl;
                fin.close();
              }

            
              symbol_amount = file_length;
              ciphertext = new char[symbol_amount];
              cout << endl; cout << "Enter the key: ";
              cin >> string_amount;
            auto begin2 = chrono::high_resolution_clock::now();
              colum_amount = ((symbol_amount - 1) / string_amount) + 1;
              cout << "Number of characters in the message: " << symbol_amount << endl;
              cout << "Number of lines: " << string_amount << endl;
              cout << "Number of columns: " << colum_amount << endl;
              for (int i = 0; i < symbol_amount; i++) {
                index = string_amount*(i%colum_amount) + (i / colum_amount);
                ciphertext[index] = source_text[i];
                  
              }
              
              for (int i = 0; i < symbol_amount; i++)
                cout << ciphertext[i];
              cout << endl;
              auto ending2 = chrono::high_resolution_clock::now();
            cout << "Потраченное время: "<< chrono::duration_cast<chrono::nanoseconds>(ending2 - begin2).count()<< " ns"<< endl;
              delete []ciphertext;
              delete []source_text;
            
            
            }
            
            
            break;
        
        default:
        {
            cout << "Something happened..."<< endl;
            break;
        }
    }
    
   
    return 0;
}
