#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

void citirecnp(char cnp[13])
{
    f>>cnp;
}

void afisarecnp(char cnp[13])
{

    g<<cnp<<endl;
}

void datanasterii(char cnp[13],int &an,int &luna,int &zi)
{

an=(cnp[1]-'0')*10+(cnp[2]-'0');
luna=(cnp[3]-'0')*10+(cnp[4]-'0');
zi=(cnp[5]-'0')*10+(cnp[6]-'0');

if(an>23)
    an+=1900;
else
    an+=2000;

g<<"Data nasterii: ";
if(zi<10)
    g<<"0"<<zi<<".";
else
    g<<zi<<".";
if(luna<10)
    g<<"0"<<luna<<".";
else
    g<<luna<<".";
g<<an<<endl;

}

void varsta(char cnp[13],int an,int luna,int zi)
{
    g<<"Varsta: ";
    if(an>=2000)
        g<<2023-an;
    else
        g<<2000-an+23;

    g<<" ani";
}

void sex(char cnp[13])
{   int sex;
    g<<"Sex: ";
    sex=cnp[0]-'0';
    if(sex%2==1)
     g<<"masculin";
    else
        g<<"feminin";
    g<<endl;
}


int main()
{int index,an,luna,zi;
char cnp[13];

while(f>>index)
{
   citirecnp(cnp);
   g<<"Pentru cnp-ul: ";afisarecnp(cnp);
   datanasterii(cnp,an,luna,zi);
   sex(cnp);
   varsta(cnp,an,luna,zi);
   g<<endl<<endl;
}


    return 0;
}
