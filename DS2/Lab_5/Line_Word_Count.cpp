#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main()
{
    int now=0,nol=0;
    FILE *fr;
    char fname[20],ch;

    cout << "\nEnter Source File Name: ";
    cin >> (fname);
    fr=fopen(fname,"r");
    
    if(fr==NULL)
    {
        cout << "\nIncorrect File Name. \nNo such File or Directory.";
        exit(0);
    }
    ch=fgetc(fr);
    
    while(ch!=EOF)
    {   
        if(ch==' ')
        now++;
        if(ch=='\n')        
        {
            nol++;
            now++;
        }
        ch=fgetc(fr);
    }
    
    fclose(fr);
    cout << "\nTotal No. of Words: " << now;
    cout << "\nTotal No. of Lines: " << nol;

    return 0;
}