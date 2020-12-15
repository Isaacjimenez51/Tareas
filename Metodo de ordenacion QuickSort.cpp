#include<iostream>
#define max 10000

using namespace std;

void Quicksort(int[],int);
void print (int[],int);
int main(){
	int n;
	cout<<"\n Ingrese cuantos numeros quiere ingresar:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cout<<"\n Ingrese el numero:"<<i+1<<"\n -->";
		cin>>a[i];
	}
	Quicksort(a,n);
	print(a,n);
}
void print (int a[],int tam){
	cout<<"\tArreglo de Numeros Ordenados por el metodo QuickSort. \n\n";
	for(int i=0;i<tam;i++)
	cout<<"\t["<<a[i]<<"] ";
}
void Quicksort(int a[],int n){
	int tope,ini,fin,pos;
		int may[max],menor[max];
		tope=0;
		menor[tope]=0;
		may[tope]=n-1;
		while(tope>=0){
			ini=menor[tope];
			fin=may[tope];
			tope--;
			int izq,der,aux;
			bool band;
			izq=ini;
			der=fin;
			pos=ini;
			band=true;
			while(band==true){
				while((a[pos]<a[der])&&(pos!=der))
					der--;
					if(pos==der)
						band=false;
					else{
						aux=a[pos];
						a[pos]=a[der];
						a[der]=aux;
						pos=der;
					}
					while((a[pos]>a[izq])&&(pos!=izq))
						izq++;
						if(pos==izq)
						band=false;
						else{
							aux=a[pos];
							a[pos]=a[izq];
							a[izq]=aux;
							pos=izq;
						}
				}
					if(ini<=(pos-1)){
						tope++;
						menor[tope]=ini;
						may[tope]=pos-1;
					}
			}
		}


