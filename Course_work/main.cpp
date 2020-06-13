#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <math.h>
#include <stdio.h>


using namespace std;



string secondMethod(string toEncrypt){
    cout << "Requirements about using this ciepher: \n 1.It can't be too long text \n 2.Write the key without spaces \n 3.The key can't be shorter than text \n";
string C,D = "";
           string A = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.()1234567890!;:-? ";
    
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
    
    
    cout << "Encrypted: " << toEncrypt << endl;
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
            start = encryptDecrypt(toEncrypt);
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
            cout << "You chose 3 mode: \n";
            char *source_text;
              char *ciphertext; // "матрица" Сциталла
              int symbol_amount; // кол-во символов в сообщении
              int string_amount; // кол-во строк
              int colum_amount; // кол-во столбцов
              int index; // индекс буквы зашифрованного сообщения
              
            int file_length;// сколько символов считать из файла
              ifstream fin("messege.txt");
            
              if (!fin.is_open())
              {// если файл не открыт
                cout << "can't be opened \n"; // сообщить об этом
              }
              else {
               
                cout << "How many characters to read from a file? " << endl;
                cin >> file_length;
                source_text = new char[file_length];
                fin.getline(source_text, file_length); // считали строку из файла
                cout << endl << "Message: " << endl;
                for (int i = 0; i < file_length; i++) {
                  cout << source_text[i];
                }
                cout << endl;
                fin.close(); // закрываем файл
              }
              
              symbol_amount = file_length;
              ciphertext = new char[symbol_amount];
              cout << endl; cout << "Enter the key: ";
              cin >> string_amount;
              colum_amount = ((symbol_amount - 1) / string_amount) + 1; // вычислили кол-во столбцов
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
