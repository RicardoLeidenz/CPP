#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "libreriaultima.h"
using namespace std;
void menu1(){
	cout<<"\n\n\t\t --->SOLITARIO<--- \n \n"<< endl;
	cout<<"1. Nueva partida"<< endl;
	cout<<"2. Cargar partida"<< endl;
	cout<<"3. Salir";
	cout<<"\n\n Ingresar opcion: ";
}
void partida(){

}
int main(){
	Tprincipal l = new (struct lprincipal);
	srand(time(NULL));
	int op,clave,pinta,columna;
	do{
			menu1(); cin>> op;
			switch(op){
				case 1:
					crearMazo(l);
					distribuirMazo (l);
					imprimirMazo(l);
					cout<< "introduce el valor de la carta"<< endl;
					cin>>clave;
					cout<< "introduce la pinta de la carta"<< endl;
					cin>> pinta;
					cout<< "introduce la columna a la que la quieres mover"<< endl;
					cin>> columna;
					if (verificarMovilidad (clave,pinta,columna,l)==true)cout<< "La carta se puede mover"<< endl;
					else cout<< "La carta no se puede mover"<< endl;
				break;
				case 2: 
				system("tput clear");
				break;	
			}
		}while (op != 3);
	system("pause");
  	return 0;
}