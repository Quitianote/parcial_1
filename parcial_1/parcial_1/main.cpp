#include <iostream>
#include <fstream>

using namespace std;

bool leermaterias(char reng[], char mat[][20], char codi[], int co[]);
bool verificar_num(char codi[]);
bool verificar_exis(char codi[], char L[][9],char M[][9], char X[][9], char J[][9], char V[][9], char S[][9], char D[][9]);
void leerusu(char reng[], char dia[][9]);


int main(){
    ifstream texto;
    ifstream usuario;
    char L[16][9] = {""};
    char M[16][9] = {""};
    char X[16][9] = {""};
    char J[16][9] = {""};
    char V[16][9] = {""};
    char S[16][9] = {""};
    char D[16][9] = {""};
    char reng[256];
    char rengd[256];
    char codi[7];
    char usu[60] = "";
    char materia[14][20] = {""};
    /*
    char fisica[14][20] = {""};
    char ingles[14][20] = {""};
    char algebra[14][20] = {""};
    char calculo[14][20] = {""};
    char infor[14][20] = {""};
    char intro[14][20] = {""};*/
    int modi = 0;
    int ini = 0;
    int contmat[2];
    bool aux = true;
    bool aux_exis = true;

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


    //leyendo archivo usuario prueba


    /*
    texto.getline(reng, 256);
    leermaterias(reng, fisica, codi, contmat);
    texto.getline(reng, 256);
    leermaterias(reng, ingles, codi, contmat);
    texto.getline(reng, 256);
    leermaterias(reng, algebra, codi, contmat);
    texto.getline(reng, 256);
    leermaterias(reng, calculo, codi, contmat);
    texto.getline(reng, 256);
    leermaterias(reng, infor, codi, contmat);
    texto.getline(reng, 256);
    leermaterias(reng, intro, codi, contmat);
    */
/*
    usuario.open("jaime.txt");
    cout << "is open: " << usuario.is_open() << endl;
    cout << "archivo: " << usu << endl;

    cout << "Horario "<< usu << " abierto." << endl << endl << endl;*/
/*
    usuario.getline(rengd, 256);//leyendo horario de usuario
    leerusu(rengd, M);
    for(int i = 0; i < 16; i ++){//forma que encontre para solucionar el problema de segmentacion de memoria
        for(int a = 0; a < 9; a ++){
            L[i][a] = M[i][a];
        }
    }
    usuario.getline(rengd, 256);
    leerusu(rengd, M);
    usuario.getline(rengd, 256);
    leerusu(rengd, X);
    usuario.getline(rengd, 256);
    leerusu(rengd, J);
    usuario.getline(rengd, 256);
    leerusu(rengd, V);
    usuario.getline(rengd, 256);
    leerusu(rengd, S);
    usuario.getline(rengd, 256);
    leerusu(rengd, D);
    //imprimir horario
    int i = 0;
    int a = 0;
    int hora = 7;//hora
    //cout << "Dia" << endl; //-----6-----7-----8-----9-----10-----11-----12-----13-----14-----15-----16-----17-----18-----19-----20-----21-----22-----" << endl;
    cout << "Hora ----- Lunes -------- Martes --------- Miercoles ----------- Jueves ---------------- Viernes ------------- Sabado --------------- Domingo ---|" << endl;

    for(; i < 16; i ++){
        if(hora < 10) cout << "0" << hora << ":  ---| " << L[i] << "  ----| " << M[i] << "  ------| " << X[i] << "  --------| " << J[i] << "  -------------| " << V[i] << "  --------| " << S[i] << "  --------------| " << D[i] << "  |" << endl;
        else cout << hora << ":  ---| " << L[i] << "  ----| " << M[i] << "  ------| " << X[i] << "  --------| " << J[i] << "  -------------| " << V[i] << "  --------| " << S[i] << "  --------------| " << D[i] << "  |" << endl;
        hora ++;
    }
*/




    //tamaño de los arreglos de las materias

    for(int i = 0; i < 14; i ++){
        cout << materia[i] << endl;
    }
    for(int i = 0; i < 14; i ++){
        cout << L[i] << " :dia 1" << endl;
        cout << M[i] << " :dia 2" << endl;
        cout << X[i] << " :dia 3" << endl;
        cout << J[i] << " :dia 4" << endl;
        cout << V[i] << " :dia 5" << endl;
        cout << S[i] << " :dia 6" << endl;
        cout << D[i] << " :dia 7" << endl;
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
        cout << "Ingrese: " << endl  << "'0' Para salir del programa." << endl << "'1' Para acceder a un horario." << endl << "'2' Para crear un horario." << endl; cin >> ini;//mirando si cierra el programa o quiere abrir un horario
        while(ini != 0 && ini != 1 && ini != 2){
            cout << "Error::Numero invalido." << endl;cin >> ini;
        }
        if(ini == 0) break;//quiso salir del programa
        else if(ini == 1){//quiso mirar un archivo
            for(;;){
                cout << endl;
                cout << "Ingrese nombre del archivo del usuario o '0' si desea volver: ";cin >> usu;
                //usuario.open(usu);
                if(usu[0] == '0') break;
                usuario.close();
                usuario.open(usu);
                cout << "is open: " << usuario.is_open() << endl;
                cout << "archivo: " << usu << endl;
                if (usuario.is_open()){
                    cout << "Horario "<< usu << " abierto." << endl << endl << endl;

                    usuario.getline(rengd, 256);//leyendo horario de usuario
                    leerusu(rengd, M);

                    for(int i = 0; i < 16; i ++){//forma que encontre para solucionar el problema de segmentacion de memoria
                        for(int a = 0; a < 9; a ++){
                            L[i][a] = M[i][a];
                        }
                    }
                    usuario.getline(rengd, 256);
                    leerusu(rengd, M);
                    usuario.getline(rengd, 256);
                    leerusu(rengd, X);
                    usuario.getline(rengd, 256);
                    leerusu(rengd, J);
                    usuario.getline(rengd, 256);
                    leerusu(rengd, V);
                    usuario.getline(rengd, 256);
                    leerusu(rengd, S);
                    usuario.getline(rengd, 256);
                    leerusu(rengd, D);

                    //imprimir horario
                    int i = 0;
                    int hora = 7;//hora
                    cout << "Hora ----- Lunes -------- Martes --------- Miercoles ----------- Jueves ---------------- Viernes ------------- Sabado --------------- Domingo ---|" << endl;

                    for(; i < 16; i ++){
                        if(hora < 10) cout << "0" << hora << ":  ---| " << L[i] << "  ----| " << M[i] << "  ------| " << X[i] << "  --------| " << J[i] << "  -------------| " << V[i] << "  --------| " << S[i] << "  --------------| " << D[i] << "  |" << endl;
                        else cout << hora << ":  ---| " << L[i] << "  ----| " << M[i] << "  ------| " << X[i] << "  --------| " << J[i] << "  -------------| " << V[i] << "  --------| " << S[i] << "  --------------| " << D[i] << "  |" << endl;
                        hora ++;
                    }
                    //final de imprimir horario
                    //menu de opciones para el horario
                    while(true){
                        cout << endl << "*********Opciones de horario***********" << endl << endl;
                        cout << endl << "Ingrese: " << endl  << "'0' Si desea volver." << endl << "'1' Para calcular horas personales." << endl << "'2' Para agregar una materia." << endl; cin >> modi;//mirando si cierra el programa o quiere abrir un horario
                        while(modi != 0 && modi != 1 && modi != 2){
                            cout << endl << "Error::Numero invalido." << endl;cin >> modi;
                        }
                        if(modi == 0) break;//desea volver atras
                        else if(modi == 1){//calcular horas personales

                        }
                        else if(modi == 2){//agregar materia
                            while(true){
                                cout << endl << "Escriba codigo de la materia o '0' para volver: ";cin >> codi;
                                if(codi[0] == '0') break;

                                aux = verificar_num(codi);//verificando si todos los caracteres son numeros
                                cout << "tam: " << sizeof(codi) / sizeof(codi[0]) << endl;

                                while(aux != true){//verficiando que el codigo esta bien
                                    cout << "Error::Codigo invalido:";cin >> codi;
                                    if(codi[0] == '0') break;
                                    aux = verificar_num(codi);
                                }
                                if(codi[0] == '0') break;

                                aux_exis = verificar_exis(codi, L, M, X, J, V, S, D);//verificando si existe en el horario

                                while(aux_exis == true){
                                    cout << endl << "Error::Codigo ya existente en el horario." << endl << "Vuelva a escribir el codigo o escriba '0' para cancelar: ";cin >> codi;
                                    aux_exis = verificar_exis(codi, L, M, X, J, V, S, D);//verificando si existe en el horario
                                    aux = verificar_num(codi);//verificando si todos los caracteres son numeros
                                    while(aux != true){//verficiando que el codigo esta bien
                                        cout << "Error::Codigo invalido:";cin >> codi;
                                        if(codi[0] == '0') break;
                                        aux = verificar_num(codi);
                                    }
                                }
                                if(codi[0] == '0') break;
                                texto.seekg(0);
                                while(texto.good()){//verificando si el codigo esta en la base de datos
                                    texto.getline(reng, 256);
                                    aux = leermaterias(reng, materia, codi, contmat);
                                    cout << "renglon: " << reng << endl;
                                    if(aux){
                                        cout << "se encontro la materia" << endl;
                                        break;
                                    }
                                }
                                if(!aux){
                                    cout << "no se encontro la materia" << endl;

                                }


                            }
                        }
                    }



                }
                else cout << "Archivo no abierto" << endl;



            }

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
                    //cout << mat[0] << " codigo" << endl;
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
                    //cout << mat[1] << " nombre1" << endl;
                    //cout << reng[a] << " letra de renglon" << endl;
                    mat[1][pos] = reng[a];
                   // cout << a << " a" << endl;
                   // cout << mat[1] << " nombre" << endl;
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
                    //cout << a << " a" << endl;
                    //cout << mat[2] << " numero" << endl;
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
                   // cout << a << " a" << endl;
                    //cout << mat[3] << " numero" << endl;
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
                   // cout << mat[3] << " dia 1" << endl;
                    //cout << mat[3] << " dia 2" << endl;
                    //cout << "letra de dia: " << reng[a] << endl;
                }
                else if(reng[a] != ',' && reng[a] != '/' && reng[a] != '-'){//guardando hora
                    mat[cont][pos] = reng[a];
                    //cout << reng[a] << " letra" << endl;
                    pos ++;
                }
                if(reng[a] == ',' || reng[a] == '/'){//siguiente hora o dia
                    cont ++;
                    pos = 0;
                    /*
                    cout << reng[a] << " letra" << endl;
                    cout << mat[4] << " hora 3" << endl;
                    cout << mat[5] << " hora 4" << endl;
                    cout << mat[6] << " hora 5" << endl;
                    cout << cont << " posicion" << endl;
                    */
                }
                else if(reng[a] == '-'){//final de materia
                    co[0] = cont + 1;
                    aux = true;
                    break;
                }
            }
        }
        if(aux) break;//verificando si ya finalizo el renglon
        //cout << i << " i" << endl;
    }
    return true;
}


void leerusu(char reng[], char dia[][9]){
    int cont = 0;
    int pos = 0;
    /*
    for(int i = 0; i < 16; i ++){
        for(int a = 0; a < 9; a ++){
            dia[i][a] = '\0';
        }
    }
    */
    //cout << "renglon entero: " << reng << endl;
    for(int i = 0; i < 256; i ++){
        //cout << "renglon: " << reng[i] << endl;
        if(reng[i] == '-'){
            dia[cont][0] = 'L';
            dia[cont][1] = 'i';
            dia[cont][2] = 'b';
            dia[cont][3] = 'r';
            dia[cont][4] = 'e';
            dia[cont][5] = ' ';
            dia[cont][6] = ' ';
            dia[cont][7] = ' ';

        }
        else if(reng[i] != ',' && reng[i] != '/'){//mirando cada elemento del renglon
            //cout << dia[cont] << " dia" << endl;
            dia[cont][pos] = reng[i];
            pos ++;
        }
        else if(reng[i] == ','){//cambiando de hora
            cont ++;
            pos = 0;
        }
        else if(reng[i] == '/'){//finalizacion de renglon
            break;
        }
    }


}

bool verificar_num(char codi[]){//verificar si todos los elementos del codigo son numeros
    for(int i = 0; i < 7; i ++){
        if((codi[i] - 0) < 48 || (codi[i] - 0) > 57) return false;
    }
    return true;
}

bool verificar_exis(char codi[], char L[][9],char M[][9], char X[][9], char J[][9], char V[][9], char S[][9], char D[][9]){//verificando si el codigo ya existe en el horario
    char temp[7] = "";
    int a = 0;

    for(int i = 0; i < 16; i ++){
        if(L[i][0] == '*'){
            for(; a < 9; a ++){
                temp[a] = L[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
            a = 0;
         }
    }

    for(int i = 0; i < 16; i ++){
        if(M[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = M[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
           a = 0;
        }
    }

    for(int i = 0; i < 16; i ++){
        if(X[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = X[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
            a = 0;
        }
    }

    for(int i = 0; i < 16; i ++){
        if(J[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = J[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            a = 0;
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
         }
    }

    for(int i = 0; i < 16; i ++){
        if(V[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = V[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
            a = 0;
         }
    }

    for(int i = 0; i < 16; i ++){
        if(S[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = S[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
            a = 0;
         }
    }

    for(int i = 0; i < 16; i ++){
        if(D[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = D[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
            a = 0;
         }
    }

    return false;
}

