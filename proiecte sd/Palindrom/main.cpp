#include <iostream>

using namespace std;

int main()
{
    int nr,nr1,cop,i,s;
    cout<<"Introduceti numarul :";
    cin>>nr;cout<<endl;

    nr1=nr;
    s=10;
    cop=0;
    while(nr1!=0)
    {if (nr1<10)
    {cop=cop+nr1%s;
    nr1=nr1/10;}
    else
    {cop=cop+nr1%s;
    nr1=nr1/10;
    cop=cop*10;
    }
    }


   if(cop==nr)  cout<<"Numarul este palindrom";
    else cout<<"Numarul nu este palindrom";

   return 0;
}
