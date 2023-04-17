#include <iostream>
#include <fstream>

using namespace std;

void leermaterias(char reng[], char mat[][20]);

int main(){
    ifstream texto;
    ifstream usuario;
    char reng[256];
    char temp;
    char usu[60];
    char fisica[14][20] = {""};
    char ingles[14][20] = {""};
    char algebra[14][20] = {""};
    char calculo[14][20] = {""};
    char infor[14][20] = {""};
    char intro[14][20] = {""};
    int ini = 0;

    texto.open("materias.txt");
    //leyendo renglon
    texto.getline(reng, 256);
    leermaterias(reng, fisica);
    texto.getline(reng, 256);
    leermaterias(reng, ingles);
    texto.getline(reng, 256);
    leermaterias(reng, algebra);
    texto.getline(reng, 256);
    leermaterias(reng, calculo);
    texto.getline(reng, 256);
    leermaterias(reng, infor);
    texto.getline(reng, 256);
    leermaterias(reng, intro);

    //tamaño de los arreglos de las materias
    int tamfisica = 8;
    int tamingles = 8;
    int tamalgebra = 8;
    int tamcalculo = 8;
    int taminfor = 12;
    int tamintro = 5;

    for(int i = 0; i < 8; i ++){
        cout << fisica[i] << endl;
    }
    for(int i = 0; i < 8; i ++){
        cout << ingles[i] << endl;
    }
    for(int i = 0; i < 8; i ++){
        cout << algebra[i] << endl;
    }
    for(int i = 0; i < 8; i ++){
        cout << calculo[i] << endl;
    }
    for(int i = 0; i < 12; i ++){
        cout << infor[i] << endl;
    }
    for(int i = 0; i < 5; i ++){
        cout << intro[i] << endl;
    }

    while(true){
        cout << "Ingrese: " << endl << "'1' Para acceder a un horario." << endl << "'0' Para salir del programa." << endl; cin >> ini;//mirando si cierra el programa o quiere abrir un horario
        while(ini != 0 && ini != 1){
            cout << "Error::Numero invalido." << endl;cin >> ini;
        }
        if(ini == 0) break;
        else{//quiso mirar un archivo
            cout << "Ingrese nombre del archivo del usuario: ";cin >> usu;
            usuario.open(usu);

            if(usuario.is_open())cout << "Horario " << usu << " abierto" << endl;
            else cout << "No se pudo abrir el archivo" << endl;

        }
    }


    return 0;
}

void leermaterias(char reng[], char mat[14][20]){//leer renglon de materias
    char pala[20];
    int pos = 0;
    int cont = 2;
    bool aux = false;

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
                    cout << mat[1] << " nombre1" << endl;
                    cout << reng[a] << " letra de renglon" << endl;
                    mat[1][pos] = reng[a];
                    cout << a << " a" << endl;
                    cout << mat[1] << " nombre" << endl;
                    pos ++;//posicion en la matriz
                }
                else{
                    mat[1][pos] = '\0';
                    break;
                }

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
                    cout << mat[3] << " dia 1" << endl;
                    cout << mat[3] << " dia 2" << endl;
                    cout << "letra de dia: " << reng[a] << endl;
                }
                else if(reng[a] != ',' && reng[a] != '/' && reng[a] != '-'){//guardando hora
                    mat[cont][pos] = reng[a];
                    cout << reng[a] << " letra" << endl;
                    pos ++;
                }
                if(reng[a] == ',' || reng[a] == '/'){//siguiente hora o dia
                    cont ++;
                    pos = 0;
                    cout << reng[a] << " letra" << endl;
                    cout << mat[4] << " hora 3" << endl;
                    cout << mat[5] << " hora 4" << endl;
                    cout << mat[6] << " hora 5" << endl;
                    cout << cont << " posicion" << endl;
                }
                else if(reng[a] == '-'){//final de materia
                    aux = true;
                    break;
                }
            }
        }
        if(aux) break;
        cout << i << " i" << endl;
    }
}



