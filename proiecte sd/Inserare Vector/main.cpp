#include <iostream>

using namespace std;


void init(int v[20],int &dim)
{
    int i;
    for (i=0;i<7;i++)
        v[i]=i;

    dim=6;
}

void inslainceput(int v[20],int &dim,int nr)
{
    for(int i=dim;i>=0;i--)
        v[i+1]=v[i];
    v[0]=nr;
    dim++;

}

void inslafinal(int v[20],int &dim, int nr)
{

    v[dim]=nr;
    dim++;

}

void stergere(int v[20],int &dim,int poz)
{   int i,j;
    for(i=0;i<dim;i++)
        if(i==poz)
            {for( j=i;j<dim;j++)
                v[j]=v[j+1];
                dim--;
            }
}

void afisaj(int v[20],int dim)
{   int i;
    for(i=0;i<dim;i++)
        cout<<v[i]<<"  ";
        cout<<endl;

}


void bubble_sort(int v[20],int dim)
{int i,j,aux;
    for(i=0; i<=dim-1; i++)
    for(j=0; j<=dim-i; j++)
        if(v[j]>v[j+1])
            {aux = v[j];
            v[j] = v[j+1];
            v[j+1] = aux;
            }
}

int main()
{
   int v[20],dim=0;

   init(v,dim);
   cout<<"Vector initial: ";afisaj(v,dim);
    inslainceput(v,dim,22);
    inslainceput(v,dim,8);
    inslainceput(v,dim,63);
    cout<<"Elementele vectorului dupa inserarea la inceput: ";afisaj(v,dim);
    inslafinal(v,dim,33);
    inslafinal(v,dim,96);
    inslafinal(v,dim,202);
    inslafinal(v,dim,100);
    cout<<"Elementele vectorului dupa inserarea la sfarsit: ";afisaj(v,dim);
    stergere(v,dim,3);
    stergere(v,dim,0);
    afisaj(v,dim);
    bubble_sort(v,dim);
    cout<<"Elementele vectorului dupa sortare: ";afisaj(v,dim);




    return 0;
}
