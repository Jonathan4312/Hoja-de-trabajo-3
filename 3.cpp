/*Ejercicio # 3:
Un empresa que se dedica a la venta de seguros de vehiculos, calcula el importe
según el modelo y color del automovil, asi como la edad del conductor.

Modelo       Color             Precio
A           Blanco             240.50
            Metalizado    	   330.00
            Otros              270.50
B           Blanco             300.00
            Metalizado         360.50
            Otros              330.00
           
Incremento de precio
Edad              % Incremento
<31                    25%
Entre 31 y 65          0%
>65                    30%

Determine el importe a pagar mostrandolo en pantalla según los datos del vehículo (modelo y color)
y la edad del conductor.
Grabe los datos a un archivo.*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//Creo mi Estructura Principal
struct aseguradora{
	int edad;
	int modelo;
	int color;
	float importe;
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
		cout<<" Menu Principal Aseguradora de Vehiculos"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Nuevo Vehiculo "<<"\n";
		cout<<" 2 - Mostrar Reporte "<<"\n";
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
void grabar_archivo(){
	int edad;
	int modelo;
	int color;
	float importe;
	
	fflush(stdin);
	cout<<"Digite la edad del conductor: "<<endl;
	cin>>edad;
	cout<<"Digite el modelo del vehiculo: "<<endl<<"1:Modelo A"<<"\t"<<"0:Modelo B"<<endl;
	cin>>modelo;
	fflush(stdin);
	cout<<"Digite el color del vehiculo: "<<endl<<"1:Blanco"<<"\t"<<"2:Metalizado"<<"\t"<<"3:Otros"<<endl;
	cin>>color;

	if (modelo == 1) {
      if (color == 1){
      	if (edad<31){
		importe=(240.50*0.25)+240.50;
      	cout<<importe;
		}
		else if (edad>=31 and edad <=65){
			importe=240.50;
			cout<<importe;
		}
		else if (edad>65){
			importe=(240.50*0.30)+240.50;
			cout<<importe;
		}
      	}
      	else if (color == 2){
      	if (edad<=31){
		importe=(330*0.25)+330;
      	cout<<importe;
		}
		else if (edad<=31 and edad >=65){
			importe=330;
			cout<<importe;
		}
		else if (edad<65){
			importe=(330*0.30)+330;
			cout<<importe;
		}
      	}
      	else if (color == 3){
      	if (edad<=31){
		importe=(270.50*0.25)+270.50;
      	cout<<importe;
		}
		else if (edad<=31 and edad >=65){
			importe=270.50;
			cout<<importe;
		}
		else if (edad<65){
			importe=(270.50*0.30)+270.50;
			cout<<importe;
		}
      	}
    else {
       if (color == 1){
      	if (edad<31){
		importe=(300*0.25)+300;
      	cout<<importe;
		}	
		}
		else if (edad>=31 and edad <=65){
			importe=300;
			cout<<importe;
		}
		else if (edad>65){
			importe=(300*0.30)+300;
			cout<<importe;
		}
		else if (color == 2){
      	if (edad<=31){
		importe=(360.50*0.25)+360.50;
      	cout<<importe;
		}
		else if (edad<=31 and edad >=65){
			importe=360.50;
			cout<<importe;
		}
		else if (edad<65){
			importe=(360.50*0.30)+360.50;
			cout<<importe;
		}
      	}
      	else if (color == 3){
      	if (edad<=31){
		importe=(330*0.25)+2220;
      	cout<<importe;
		}
		else if (edad<=31 and edad >=65){
			importe=330;
			cout<<importe;
		}
		else if (edad<65){
			importe=(330*0.30)+330;
			cout<<importe;
    	}
		}
	}  	
      	
      	}
//Agregamos datos al archivo
	ofstream archivo; 
	archivo.open("aseguradora.txt",ios::app);
	archivo<<edad<<"\t"<<modelo<<"\t"<<color<<"\t"<<importe<<endl;
	archivo.close();
}

void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("aseguradora.txt",ios::in);
	cout << "---------------------------------------------" << endl;
	cout << "EDAD"<< "\t" << "MODELO" << "\t" <<"\t"<< "COLOR"<< "\t"<< "IMPORTE Q."<< endl;
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
	
	aseguradora recordset[lineas];
	
	archivo.open("aseguradora.txt",ios::in);
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
        archivo>>recordset[i].edad>>recordset[i].modelo>>recordset[i].color>>recordset[i].importe;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].edad<<"\t"<<recordset[i].modelo<<"\t"<<"\t"<<recordset[i].color<<"\t"<<recordset[i].importe<<endl;
    	
    	sumatoriaventa+=recordset[i].importe;
	}
	cout<<endl<<"Total Aseguradora: "<<"Q."<<sumatoriaventa<<endl<<endl;
	
	system("PAUSE");
	}
