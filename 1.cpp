/*Ejercicio # 1:
El presidente de un club de futbol requiere calcular el sueldo de sus jugadores
si se tiene como dato la edad y la nacionalidad del jugador.

Ademas se sabe que el sueldo se calculara de la siguiente manera:
Sueldo fijo $2500.00
Si es extranjero recibe un bono de $500.00

Si la edad esta entre 15 y 20, el salario incrementa en $1400.00
Si la edad esta entre 21 y 25, el salario incrementa en $1500.00
Si la edad esta entre 26 y 30, el salario incrementa en $1200.00
Si la edad es mayor a 30, el salario incrementa en $800.00
Determine el sueldo del jugador si se tiene como datos la edad y nacionalidad.

Mostrar un reporte del total a pagar de planilla, as� como el total de jugadores por
los rangos de edad. Ademas de indicar que rango de edad es el mas remunerado.*/

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Crear estructura
struct catalogo{
	int edad;
	int nacionalidad;
	int sueldo;
};

void mp();
void leer_aarchivo();
void grabar_aarchivo();

int main(){
	mp();
}

void mp(){
	int r;
	do {
		system("CLS");
		cout<<"----------------------------------------"<<"\n";
		cout<<" Menu Principal Planilla Club de Futbol"<<"\n";
		cout<<"----------------------------------------"<<"\n";
		cout<<" 1 - Ingresar Jugador "<<"\n";
		cout<<" 2 - Mostrar Planilla "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>r;
		if (r==1){		
			system("CLS");
			grabar_aarchivo();			
		}
		else if (r==2){		
			system("CLS");
			leer_aarchivo();
		}			
		else if (r==3)
			break;
		else 
			break;
		
	} while(r!=3);	
}

void grabar_aarchivo(){
	int ed_jug;
	int nacion_jug;
	int sueldo;
	
	fflush(stdin);
	cout<<"Ingrese Edad del jugador: "<<endl;
	cin>>ed_jug;
	fflush(stdin);
	cout<<"Eres extranjero? 1=Si - 0=No "<<endl;
	cin>>nacion_jug;

	if (nacion_jug == 1) {
	    if (ed_jug<=14){
			sueldo=(3000);
			cout<<sueldo;
		}
		else if (ed_jug >=15 and ed_jug <= 20){
      	sueldo=(2500+1400)+500;
      	cout<<sueldo;
      	}
	   else if (ed_jug>=21 and ed_jug <= 25){
	  	sueldo=(2500+1500)+500;
      	cout<<sueldo;	
	   }else if (ed_jug>=26 and ed_jug <= 30){
	  	sueldo=(2500+1200)+500;
      	cout<<sueldo;	
	   }else if (ed_jug>30){
	  	sueldo=(2500+800)+500;
      	cout<<sueldo;	
	    }
	}else {	
		if (ed_jug<=14){
			sueldo=(2500);
			cout<<sueldo;
		}
	   else if (ed_jug>=15 and ed_jug <= 20){
      	sueldo=(2500+1400);
      	cout<<sueldo;
	  }else if (ed_jug>=21 and ed_jug <= 25){
	  	sueldo=(2500+1500);
      	cout<<sueldo;	
	  }else if (ed_jug>=26 and ed_jug <= 30){
	  	sueldo=(2500+1200);
      	cout<<sueldo;	
	  }else if (ed_jug>30){
	  	sueldo=(2500+800);
      	cout<<sueldo;	
	  }
	  }
	
    
	
	ofstream archivo; //Agregar archivo 
	archivo.open("planilla.txt",ios::app);
	
	archivo<<ed_jug<<"\t"<<nacion_jug<<"\t"<<sueldo<<endl;
	archivo.close();
}

void leer_aarchivo(){
	ifstream archivo; //leer archivo 
	archivo.open("planilla.txt",ios::in);
	cout << "---------------------------------------------" << endl;
	cout << "EDAD"<< "\t" << "NACIONALIDAD" << "\t" <<"\t"<< "SUELDO" << endl;
	cout << "---------------------------------------------" << endl; 
	int lineas,i=0;
	string s,linea;
	float suma_salario=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); 
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	catalogo recordset[lineas];
	
	archivo.open("planilla.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	

	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].edad>>recordset[i].nacionalidad>>recordset[i].sueldo;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].edad<<"\t"<<"\t"<<recordset[i].nacionalidad<<"\t"<<"\t"<<recordset[i].sueldo<<endl;
    	
    	suma_salario+=recordset[i].sueldo;
	}
	cout<<endl<<"Total a pagar de planilla: "<<suma_salario<<endl<<endl;
	system("PAUSE");
}
