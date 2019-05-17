#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool hnefatafl();
void CapturaGuardianes(char**,bool);
void imprimir(char**);
//funciones usados

int main(){
	int opcm=0;
	while(opcm!=2){//Menu principal
		cout<<"Menu"<<endl
			<<"1. Jugar Hnefatafl"<<endl
			<<"2. Salir"<<endl
			<<"Ingrese una opcion: "<<endl;
		cin>>opcm;
		if(opcm==1){
			if(hnefatafl()){//Validar quien gano
				for(int i=0;i<10;i++)
					cout<<"Ganaron los suecos!"<<endl;
			}else{
				for(int i=0;i<10;i++)
                                        cout<<"Ganaron los moscovitas!"<<endl;		
			}
		}
	}	
	return 0;
}
bool hnefatafl(){//retornara verdadero si ganan los suecos y falso si ganan los moscovitas
	char** tablero= new char*[11];
	for(int i=0; i<11;i++){//Crear Tablero en memoria
		tablero[i]=new char[11];
	}
	bool turno=true;//TRUE==NEGROS FALSE==BLANCOS
	//Crear peones en tablero	
	for(int x=0;x<11;x++){
		for(int y=0;y<11;y++){
			if(((x>=4&&x<=6)&&(y==0||y==10))||((y>=4&&y<=6)&&(x==0||x==10))
					||((x==4||x==6)&&(y==1||y==9))||((y==4||y==6)&&(x==1||x==9))||((x==2||x==8)&&(y==5))
					||((y==2||y==8)&&(x==5))){//Coloca los peones negros
				tablero[x][y]='#';
			}else if(((y==4||y==7)&&(x==5))||((x==4||x==7)&&(y==5))
					||((y>=4&&y<=6)&&(x==4||x==6))||((x>=4&&x<=6)&&(y==4||y==6))){//coloca peones blancos
				tablero[x][y]='O';
			}else if(x==5&&y==5){//Coloca al Rey
				tablero[x][y]='W';
			}else{
				tablero[x][y]='-';
			}
		}//fin for
	}//fin for
	cout<<"El tablero es el siguiente: "<<endl;
	imprimir(tablero);//Muestra el tablero

	for(int i=0; i<11;i++){//Liberar Tablero en memoria
                delete[] tablero[i];
        }
	delete[] tablero;
	return false;
}

void imprimir(char** tablero){
	for(int x=0;x<11;x++){
		for(int y=0;y<11;y++){
			cout<<"["<<tablero[x][y]<<"] ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void CapturaGuardianes(char** tablero,bool turno){
	//se verifica el tablero para ver si se deben eliminar peones con 
	//un bool turno
	
}
