#include <iostream>
#include <fstream>

using namespace std;

void leermaterias(char reng[], char mat[][20]);

int main(){
    ifstream texto;
    char reng[256];
    char temp;
    char fisica[14][20] = {""};
    char ingles[14][20] = {""};
    char algebra[14][20] = {""};
    char calculo[14][20] = {""};
    char infor[14][20] = {""};
    char intro[14][20] = {""};

    texto.open("materias.txt");

    texto.getline(reng, 256);
    leermaterias(reng, fisica);
    cout << reng << endl;
    cout << fisica[0] << endl;
    cout << fisica[1] << endl;
    cout << fisica[2] << endl;



    return 0;
}

void leermaterias(char reng[], char mat[14][20]){//leer archivo de materias
    char pala[20];
    int pos = 0;
    int cont = 2;
    for(int i = 0; i < 256; i ++){
        if(reng[i] == '*'){//codigo
            for(int a = i + 1; a < 256; a ++){//creando codigo
                if(reng[a] != '!'){
                    mat[0][pos] = reng[a];//posicion en la matriz
                    cout << mat[0] << " codigo" << endl;
                    pos ++;
                }
                else break;
            }
        }
        else if(reng[i] == '!'){
            pos = 0;
            for(int a = i + 1; a < 256; a ++){//creando nombre de materia
                if(reng[a] != '#'){
                    cout << reng[a] << " letra de renglon" << endl;
                    mat[1][pos] = reng[a];
                    cout << a << " a" << endl;
                    cout << mat[1] << " nombre" << endl;
                    pos ++;//posicion en la matriz
                }
                else break;
            }
        }
        else if(reng[i] == '#'){
            pos = 0;
            for(int a = i + 1; a < 256; a ++){//creando numero de horas docente
                if(reng[a] != '/'){
                    mat[2][pos] = reng[a];
                    cout << a << " a" << endl;
                    cout << mat[2] << " numero" << endl;
                    pos ++;//posicion en matriz
                }
                else break;
            }
        }
        else if(reng[i] == '/'){
            pos = 0;
            for(int a = i + 1; a < 256; a ++){//creando horario
                if(reng[a] - 0 < 90 && reng[a] - 0 > 65){//mirando si es mayuscula
                    pos = 0;
                    mat[cont][pos] = reng[a];//guardando dia
                    cout << mat[3] << " hora 1" << endl;
                    cout << mat[3] << " hora 2" << endl;
                    cont ++;
                }
                else{//guardando hora
                    mat[cont][pos] = reng[a];
                    pos ++;
                }
                if(reng[a] == ','){//siguiente hora o dia
                    cont ++;
                    pos = 0;
                }
                else if(reng[a] == '-'){
                    mat[cont ++][a] == reng[a];
                }
            }
        cout << i << " i" << endl;
    }
}


