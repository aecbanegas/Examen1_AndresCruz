#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

bool hnefatafl();
void CapturaGuardianes(char**,bool);
void imprimir(char**);
bool termino(char**);
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
			}else if(((y==3||y==7)&&(x==5))||((x==3||x==7)&&(y==5))
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
	string lugar,ficha;
	int fillugar,collugar,filficha,colficha;
	while(termino(tablero)){
		cout<<"**RECUERDE** Las coordenadas de cada ficha se escriben (Letra)-(posicion)"<<endl
			<<"siendo la letra las filas de la A-K y la posicion el numero de columna del 0-10"<<endl
			<<"Solo puede moverse en linea recta!!"<<endl;
		cout<<"Ingrese que ficha desea mover: "<<endl;
                        cin>>ficha;
                        cout<<"Ingrese a que lugar desea mover la ficha: "<<endl;
                        cin>>lugar;
		filficha=ficha[0]-65;
                if(ficha.length()==3){
                        colficha=(int)ficha[2]-48;
                }else if((ficha[2]=='1'&&ficha[3]=='0')&&ficha.length()==4){
                        colficha=10;
                }else{
                        cout<<"La posicion de la ficha es incorrecta o no existe"<<endl;
			colficha=100;
                }
		fillugar=lugar[0]-65;
		if(lugar.length()==3){
                        collugar=(int)lugar[2]-48;
                }else if((lugar[2]=='1'&&lugar[3]=='0')&&lugar.length()==4){
                        collugar=10;
                }else{
                        cout<<"La posicion a la que desea moverse es incorrecta o no existe"<<endl;
			collugar=100;
                }
		if((filficha>=0&&filficha<=10)&&(colficha>=0&&colficha<=10)&&(fillugar>=0&&fillugar<=10)&&(collugar>=0&&collugar<=10)){
			if((filficha==fillugar||collugar==colficha)&&(filficha==fillugar&&colficha==collugar)==false){
				//se valida el movimiento de la ficha y que el lugar y la posicion de la ficha no sea igual
				if((tablero[filficha][colficha]=='#'&&turno==true)
						||((tablero[filficha][colficha]=='O'||tablero[filficha][colficha]=='W')&&turno==false)){
					if(turno){//TRUE==NEGROS FALSE==BLANCOS
						//Turno de fichas negras
						int obstaculos=0;
						if(filficha==fillugar){//verifica si la fila es la misma o la columna para hacer el movimiento
							if(colficha<collugar){
								//valida si se mueve a la izquierda o derecha
								for(int y=colficha+1;y<=collugar;y++){
									if(tablero[filficha][y]=='#'||tablero[filficha][y]=='O'
											||tablero[filficha][y]=='W'){
										obstaculos++;
									}
								}
								if(obstaculos==0){
									tablero[filficha][colficha]='-';
									tablero[fillugar][collugar]='#';
									turno=!(turno);
								}else{
									cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
								}
							}else{
								for(int y=colficha-1;y>=collugar;y--){
									if(tablero[filficha][y]=='#'||tablero[filficha][y]=='O'
                                                                                        ||tablero[filficha][y]=='W'){
                                                                                obstaculos++;
                                                                        }
                                                                }
								if(obstaculos==0){
                                                                        tablero[filficha][colficha]='-';
                                                                        tablero[fillugar][collugar]='#';
                                                                        turno=!(turno);
                                                                }else{
                                                                        cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
                                                                }
							}//fin if
						}else{
							if(filficha<fillugar){
								//valida si es hacia arriba o abajo
								for(int x=filficha+1;x<=fillugar;x++){
                                                                        if(tablero[x][colficha]=='#'||tablero[x][colficha]=='O'
                                                                                        ||tablero[x][colficha]=='W'){
                                                                                obstaculos++;
                                                                        }
                                                                }
                                                                if(obstaculos==0){
                                                                        tablero[filficha][colficha]='-';
                                                                        tablero[fillugar][collugar]='#';
                                                                        turno=!(turno);
                                                                }else{
                                                                        cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
                                                                }
							}else{
								for(int x=filficha-1;x>=fillugar;x--){
                                                                        if(tablero[x][colficha]=='#'||tablero[x][colficha]=='O'
                                                                                        ||tablero[x][colficha]=='W'){
                                                                                obstaculos++;
                                                                        }
                                                                }
                                                                if(obstaculos==0){
                                                                        tablero[filficha][colficha]='-';
                                                                        tablero[fillugar][collugar]='#';
                                                                        turno=!(turno);
                                                                }else{
                                                                        cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
                                                                }

							}//fin if
						
						}//fin if
						imprimir(tablero);
					}else{//turno fichas blancas
						int obstaculos=0;
						if(filficha==fillugar){//verifica si la fila es la misma o la columna para hacer el movimiento
							if(colficha<collugar){
								//valida si se mueve a la izquierda o derecha
								for(int y=colficha+1;y<=collugar;y++){
									if(tablero[filficha][y]=='#'||tablero[filficha][y]=='O'
											||tablero[filficha][y]=='W'){
										obstaculos++;
									}
								}
								if(obstaculos==0){
									tablero[filficha][colficha]='-';
									tablero[fillugar][collugar]='O';
									turno=!(turno);
								}else{
									cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
								}
							}else{
								for(int y=colficha-1;y>=collugar;y--){
									if(tablero[filficha][y]=='#'||tablero[filficha][y]=='O'
                                                                                        ||tablero[filficha][y]=='W'){
                                                                                obstaculos++;
                                                                        }
                                                                }
								if(obstaculos==0){
                                                                        tablero[filficha][colficha]='-';
                                                                        tablero[fillugar][collugar]='O';
                                                                        turno=!(turno);
                                                                }else{
                                                                        cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
                                                                }
							}//fin if
						}else{
							if(filficha<fillugar){
								//valida si es hacia arriba o abajo
								for(int x=filficha+1;x<=fillugar;x++){
                                                                        if(tablero[x][colficha]=='#'||tablero[x][colficha]=='O'
                                                                                        ||tablero[x][colficha]=='W'){
                                                                                obstaculos++;
                                                                        }
                                                                }
                                                                if(obstaculos==0){
                                                                        tablero[filficha][colficha]='-';
                                                                        tablero[fillugar][collugar]='O';
                                                                        turno=!(turno);
                                                                }else{
                                                                        cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
                                                                }
							}else{
								for(int x=filficha-1;x>=fillugar;x--){
                                                                        if(tablero[x][colficha]=='#'||tablero[x][colficha]=='O'
                                                                                        ||tablero[x][colficha]=='W'){
                                                                                obstaculos++;
                                                                        }
                                                                }
                                                                if(obstaculos==0){
                                                                        tablero[filficha][colficha]='-';
                                                                        tablero[fillugar][collugar]='O';
                                                                        turno=!(turno);
                                                                }else{
                                                                        cout<<"Hay fichas en el camino, no se completo el movimiento"<<endl;
                                                                }

							}//fin if
						
						}//fin if	
						imprimir(tablero);
					}//fin if
				}else{
					cout<<"La ficha seleccionada no existe o no es de su color."<<endl;
				}//fin if
			}else{
				cout<<"Solo puede moverse en linea recta."<<endl;
			}//fin if
		}else{
			cout<<"Aqui!"<<filficha<<" "<<colficha<<" "<<fillugar<<" "<<collugar<<endl;
			cout<<"lugar[3]:"<<lugar[3]<<endl;
			cout<<"ficha[3]:"<<ficha[3]<<endl;
		}//fin if
	}//fin while

	for(int i=0; i<11;i++){//Liberar Tablero en memoria
                delete[] tablero[i];
        }
	delete[] tablero;
	return false;
}

bool termino(char** tablero){//verifica si el juego ha terminado
	int rey=0;
	for(int x=0;x<11;x++){
		for(int y=0;y<11;y++){
			if(tablero[x][y]=='W'){
				rey++;
				break;
			}
		}
	}
	if(rey==0||tablero[0][0]=='W'||tablero[10][10]=='W'||tablero[0][10]=='W'||tablero[10][0]=='W'){
		return false;
	}else{
		return true;
	}
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
