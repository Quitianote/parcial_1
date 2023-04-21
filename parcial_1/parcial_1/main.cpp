#include <iostream>
#include <fstream>

using namespace std;

bool leermaterias(char reng[], char mat[][20], char codi[]);
bool verificar_num(char codi[]);
bool verificar_exis(char codi[], char L[][9],char M[][9], char X[][9], char J[][9], char V[][9], char S[][9], char D[][9]);
void leerusu(char reng[], char dia[][9]);
void crear_mat(char mat[16][20], char codi[], char nom[], char hor[], char credi[]);
void modificar(char L[16][9], char M[16][9], char X[16][9], char J[16][9], char V[16][9], char S[16][9], char D[16][9], char codi[]);
void modificar_codi(char dia[16][9], int hora, char codi[]);
bool verificar_libre(int hora, char codi[]);
void vaciar(char a[16][9], int pos);

int main(){
    ifstream texto;
    ifstream usuario;
    ofstream lect_mat;
    char L[16][9] = {""};
    char M[16][9] = {""};
    char X[16][9] = {""};
    char J[16][9] = {""};
    char V[16][9] = {""};
    char S[16][9] = {""};
    char D[16][9] = {""};
    char dia = '\0';
    char temp;
    char reng[256];
    char rengd[256];
    char codi[8];
    char nom_mat[17] = "";
    char num_do[2] = "";
    char creditos[2] = "";
    char usu[60] = "";
    char materia[14][20] = {""};
    char mat_new[16][20] = {""};
    char mat_tot[256] = "";
    /*
    char fisica[14][20] = {""};
    char ingles[14][20] = {""};
    char algebra[14][20] = {""};
    char calculo[14][20] = {""};
    char infor[14][20] = {""};
    char intro[14][20] = {""};*/
    int h = 0;
    int tam = 0;
    int modi = 0;
    int ini = 0;
    int deci = 0;
    int contmat[2];
    bool aux = true;
    bool aux_exis = true;

    texto.open("materias.txt");
/*
    cout << "Ingrese codigo de materia: ";cin >> codi;

    while(texto.good()){
        texto.getline(reng, 256);
        aux = leermaterias(reng, materia, codi, contmat);
        if(aux){
            cout << "se encontro la materia" << endl;
            break;
        }
    }
    if(!aux) cout << "no se encontro la materia" << endl;*/
/*

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
    }*/
    //cout << "contador: " << contmat[0] << endl;
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
                                    aux = leermaterias(reng, materia, codi);

                                    if(aux){
                                        break;
                                    }
                                }

                                if(!aux){//sino se encontro el codigo en la base de datos se le preguntara al usuario si quiere agregar el codigo como una nueva materia aen la base de datos
                                    cout << "No se encontro el codigo, Desea agregar la materia a la base de datos?" << endl << "Ingrese: " << endl  << "'0' Para no." << endl << "'1' Para si." << endl;cin >> deci;
                                    while(deci != 0 && deci != 1){
                                        cout << "Error::Numero invalido." << endl;cin >> deci;
                                    }
                                    if(deci == 0) continue;
                                    else{
                                        cout << "Ingrese nombre de materia(maximo 16 caracteres y con '_' en lugar de espacios): ";cin >> nom_mat;
                                        cout << "Ingrese numero de horas de docente a la semana: ";cin >> num_do;
                                        cout << "Ingrese creditos: ";cin >> creditos;
                                        crear_mat(mat_new, codi, nom_mat, num_do, creditos);
                                        texto.seekg(0);
                                        tam = 1;
                                        for(i = 0; texto.good();i ++){//guardando todo el archivo materia en un arreglo
                                            temp = texto.get();
                                            if(temp != EOF){//que sea diferente al -1 que retorna al leer caracter por caracter, se le llama EOF
                                                mat_tot[i] = temp;
                                                tam ++;
                                            }
                                        }
                                        cout << "codi: " << codi << endl;
                                        texto.close();//cerrando archivo en modo lectura
                                        lect_mat.open("materias.txt");//abriendo archivo en modo escritura
                                        for(i = 0; i < tam; i ++){//escribiendo materias normales
                                            lect_mat.put(mat_tot[i]);
                                            cout << "escri 1: " << mat_tot[i] << endl;
                                        }
                                        lect_mat.put('\n');
                                        for(i = 0; i < 16; i ++){//escribiendo materia nueva
                                            for(int a = 0; a < 20; a ++){
                                                if(mat_new[i][a] == '\0') break;
                                                else{
                                                    lect_mat.put(mat_new[i][a]);
                                                    cout << "escri 2: " << mat_new[i][a] << endl;
                                                }
                                            }
                                            if(i == 0) lect_mat.put('!');
                                            else if(i == 1) lect_mat.put('#');
                                            else if(i == 2) lect_mat.put('?');
                                            else if(i == 3){
                                                lect_mat.put('-');
                                                break;
                                            }
                                        }
                                        lect_mat.close();//cerrando archivo modo escritura
                                        texto.open("materias.txt");//abriendo archivo modo lectura
                                    }
                                }
                                else{//el archivo si esta en la base de datos, por lo tanto le pregunta al usuario el horario de su materia
                                    //como ya anteriormente use la funcion para buscar la materia con el codigo, entonces ya se abra guardado en el arreglo materia
                                    modificar(L, M, X, J, V, S, D, codi);
                                    cout << "Dia: " << L[0];



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

bool leermaterias(char reng[], char mat[14][20], char codi[]){//leer renglon de materias
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
        else if(reng[i] == '-'){//final de materia
            break;
        }
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
        }
    }

    for(int i = 0; i < 16; i ++){
        if(X[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = X[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
        }
    }

    for(int i = 0; i < 16; i ++){
        if(J[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = J[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
         }
    }

    for(int i = 0; i < 16; i ++){
        if(V[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = V[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
         }
    }

    for(int i = 0; i < 16; i ++){
        if(S[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = S[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
         }
    }

    for(int i = 0; i < 16; i ++){
        if(D[i][0] == '*'){
            for(a = 0; a < 9; a ++){
                temp[a] = D[i][(a + 1)];//construyendo arreglo que luego se va a comparar
            }
            if(temp[0] == codi[0] && temp[1] == codi[1] && temp[2] == codi[2] && temp[3] == codi[3] && temp[4] == codi[4] && temp[5] == codi[5] && temp[6] == codi[6])return true;
         }
    }

    return false;
}

void crear_mat(char mat[16][20], char codi[], char nom[], char hor[], char credi[]){//creando materia para registrar en la base de datos
    int pos = 0;
    mat[0][0] = '*';

    for(int i = 1; i < 9; i ++){//guardando codigo
        if(i == 8) mat[0][8] = '\0';
        else{
            mat[0][i] = codi[pos];
            pos ++;
            cout << "mat codi: " << mat[0] << endl;
        }
    }
    for(int i = 0; i < 17; i ++){//guardando nombre de materia
       mat[1][i] = nom[i];
       cout << "mat nom: " << mat[1] << endl;
    }
    mat[2][0] = hor[0];//guardando horas de docente
    mat[2][1] = '\0';
    cout << "mat hor: " << mat[2] << endl;
    mat[3][0] = credi[0];//guardando creditos
    mat[3][1] = '\0';
    cout << "mat credi: " << mat[3] << endl;
}

bool verificar_libre(int hora, char dia[16][9]){//verificar si la posicion esta libre para modificarla
    char temp[8] = "";
    hora = hora - 7;//obteniendo posicion

    for(int i = 0; i < 8; i ++){//creando arreglo temporal que se va a comparar
        if(dia[hora][i] != ' '){
            temp[i] = dia[hora][i];
        }
        else break;
    }

    if(temp[0] == 'L' && temp[1] == 'i' && temp[2] == 'b' && temp[3] == 'r' && temp[4] == 'e') return true;
    return false;
}

void modificar(char L[16][9], char M[16][9], char X[16][9], char J[16][9], char V[16][9], char S[16][9], char D[16][9], char codi[]){//pidiendole al usuario los dias a modificar
    bool aux = true;
    char dia = '\0';
    int h = 0;

    for(;;){
        cout << endl << "Ingrese el dia que ve la materia(en mayuscula): ";cin >> dia;
        switch(dia){
            case 'L':
            for(;;){
                cout << endl << "Ingrese hora a la que ve la materia(en formato de 24 horas): ";cin >> h;
                aux = verificar_libre(h, L);
                cout << "aux: " << aux;
                while(!aux){
                    cout << endl << "Error::No se puede agregar la hora porque ya esta ocupada" << endl << "Vuelva a intentar: ";cin >> h;
                    aux = verificar_libre(h, L);
                }
                vaciar(L, h);
                modificar_codi(L, h, codi);
                cout << "materia nueva: " << L[h-7] << endl;

            }
            break;
        }

    }
}

void modificar_codi(char dia[16][9], int hora, char codi[]){
    int pos = 0;
    hora = hora - 7;
    dia[hora][0] = '*';

    for(int i = 1; i < 9; i ++){//vaciando posicion del arreglo
        dia[hora][i] = codi[pos];
        pos ++;
    }
}

void vaciar(char a[16][9], int pos){//vaciando la posicion que se va reemplazar por la materia
    pos = pos - 7;//obteniendo posicion
    for(int i = 0; i < 9; i ++){//vaciando posicion del arreglo
        a[pos][i] = '\0';
    }
}


