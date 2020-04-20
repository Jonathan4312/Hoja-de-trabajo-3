/*En la Pizzeria "Gran sabor" se tienen las siguientes ofertas:
Por la compra de una pizza grande (Q80.00), recibe un descuento de 10%
Por la compra de una pizza familiar (Q115.00), recibe un descuento de 15%
Por la compra de una pizza fiesta(Q100.00), recibe un descuento de 20%

Solicitar el tipo de pizza, el precio unitario y hallar el precio a pagar.

Grabar los datos a un archivo y mostrar el total global de la venta del dia y
determinar el total de lo vendido por producto, mostrando tambien el porcentaje
con relacion al total.*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct datos{
	int tipo;
	int cantidad;
	float calculo;
	float total;
};

void mp();
void leer_archivo();
void grabar_archivo();

int main(){
	mp();
}

void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal de la Pizzeria Gran Sabor"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Nueva Venta de Pizza "<<"\n";
		cout<<" 2 - Mostrar la Venta del Dia "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
//grabar archivo
void grabar_archivo(){

	int tipo;
	int cantidad_pizzas;
	float calculo;
	float total;
	
	fflush(stdin);
	cout<<"Ingrese el tipo de pizza: "<<endl<<"1:Grande"<<"\t"<<"2:Familiar"<<"\t"<<"3:Fiesta"<<endl;
	cin>>tipo;
	fflush(stdin);
	cout<<"Ingrese la cantidad de pizzas: "<<endl;
	cin>>cantidad_pizzas;
//Establezco las condiciones planteadas
	if (tipo == 1) {
      	calculo=cantidad_pizzas*80;
      	total=calculo-(calculo*0.10);
      	cout<<total;
      	}
	else if (tipo == 2){
	  	calculo=cantidad_pizzas*115;
      	total=calculo-(calculo*0.15);
      	cout<<total;	
	   }
	else{
	  	calculo=cantidad_pizzas*100;
      	total=calculo-(calculo*0.20);
      	cout<<total;	
	   }
	  
	
//Agregamos datos al archivo
	ofstream archivo; 
	archivo.open("datos.txt",ios::app);
	archivo<<tipo<<"\t"<<cantidad_pizzas<<"\t"<<total<<endl;
	archivo.close();
}
//Creo mi funcion para leer el archivo
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("datos.txt",ios::in);
	cout << "---------------------------------------------" << endl;
	cout << "TIPO DE PIZZA"<< "\t" << "CANTIDAD" << "\t" <<"\t"<< "TOTAL EN DINERO Q." << endl;
	cout << "---------------------------------------------" << endl; 
	int lineas,i=0;
	string s,linea;
	float sumatoriaventa=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); //break;
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	datos recordset[lineas];
	
	archivo.open("datos.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
//Leer datos del archivo
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].tipo>>recordset[i].cantidad>>recordset[i].total;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].tipo<<"\t"<<"\t"<<recordset[i].cantidad<<"\t"<<"\t"<<"\t"<<recordset[i].total<<endl;
    	
    	sumatoriaventa+=recordset[i].total;
	}
	cout<<endl<<"Total Ventas: "<<"Q."<<sumatoriaventa<<endl<<endl;
	
	system("PAUSE");
}
