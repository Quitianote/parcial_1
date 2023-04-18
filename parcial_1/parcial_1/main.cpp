#include <iostream>
#include <fstream>

using namespace std;

bool leermaterias(char reng[], char mat[][20], char codi[], int co[]);

int main(){
    ifstream texto;
    ifstream usuario;
    char reng[256];
    char codi[7];
    char usu[60];
    char materia[14][20] = {""};
    char ingles[14][20] = {""};
    char algebra[14][20] = {""};
    char calculo[14][20] = {""};
    char infor[14][20] = {""};
    char intro[14][20] = {""};
    int ini = 0;
    int contmat[2];
    bool aux = true;

    texto.open("materias.txt");

    cout << "Ingrese codigo de materia: ";cin >> codi;

    while(texto.good()){
        texto.getline(reng, 256);
        aux = leermaterias(reng, materia, codi, contmat);
        if(aux){
            cout << "se encontro la materia" << endl;
            break;
        }
    }
    if(!aux) cout << "no se encontro la materia" << endl;
    //leyendo renglon
    /*
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
    */
    //tamaño de los arreglos de las materias

    for(int i = 0; i < 14; i ++){
        cout << materia[i] << endl;
    }
    cout << "contador: " << contmat[0] << endl;
    /*
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
    }*/

    while(true){
        cout << "*****MENU*****" << endl;
        cout << endl;
        cout << "Ingrese: " << endl << "'1' Para acceder a un horario." << endl << "'0' Para salir del programa." << endl << "'2' Para crear un horario." << endl; cin >> ini;//mirando si cierra el programa o quiere abrir un horario
        while(ini != 0 && ini != 1 && ini != 2){
            cout << "Error::Numero invalido." << endl;cin >> ini;
        }
        if(ini == 0) break;//quiso salir del programa
        else if(ini == 1){//quiso mirar un archivo
            cout << "Ingrese nombre del archivo del usuario: ";cin >> usu;
            usuario.open(usu);

            if(usuario.is_open())cout << "Horario " << usu << " abierto" << endl;
            else cout << "No se pudo abrir el archivo" << endl;

        }
    }


    return 0;
}

bool leermaterias(char reng[], char mat[14][20], char codi[], int co[]){//leer renglon de materias
    int pos = 0;
    int cont = 4;
    bool aux = false;

    for(int i = 0; i < 256; i ++){
        if(reng[i] == '*'){//codigo
            for(int a = i + 1; a < 256; a ++){//creando codigo
                if(reng[a] != '!'){
                    mat[0][pos] = reng[a];//posicion en la matriz
                    cout << mat[0] << " codigo" << endl;
                    char temp1 = mat[0][pos];
                    char temp2 = codi[pos];
                    if(temp1 != temp2) return false;
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
                if(reng[a] != '?'){
                    mat[2][pos] = reng[a];
                    cout << a << " a" << endl;
                    cout << mat[2] << " numero" << endl;
                    pos ++;//posicion en matriz
                }
                else break;
            }
        }
        else if(reng[i] == '?'){
            pos = 0;
            for(int a = i + 1; a < 256; a ++){//creando creditos
                if(reng[a] != '/'){
                    mat[3][pos] = reng[a];
                    cout << a << " a" << endl;
                    cout << mat[3] << " numero" << endl;
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
                    co[0] = cont + 1;
                    aux = true;
                    break;
                }
            }
        }
        if(aux) break;//verificando si
        cout << i << " i" << endl;
    }
    return true;
}



