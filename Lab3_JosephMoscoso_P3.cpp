#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<cstdlib>

#include<ctime>

#include<string>
using std::string;
using std::to_string;

#include<cstring>

void eje1(char*);
void freeC(char*);
char* initC(int);
void eje2();

int main(){
    cout<<"Bienvenido"<<endl;
    cout<<"-------------------------------------"<<endl;
    int salir=0;
    while(salir=0){
        cout<<"1) Juego de mentes\n2) Convertir a binario\n3) Conjugador de verbos regulares\n4) Salir"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"Ingrese el numero: ";
        int op=0;
        cin>>op;
        cout<<endl;
        while(op<0||op>4){
            cout<<"--------------------------------------"<<endl;
            cout<<"Error, opcion incorrecta, por favor ingrese otra vez: ";
            cin>>op;
            cout<<endl;
        }
        if(op==1){
       // int intentos=3;
            char* ej=NULL;
            ej=initC(3);
            cout<<"--------------------------------------"<<endl;
            cout<<"Bienvenido al juego de mentes"<<endl;
            cout<<"--------------------------------------"<<endl;
            srand(time(NULL));
            eje1(ej);
        }
        if(op==2){
            eje2();
        }
        if(op==3){
        }
        if(op==4){
            salir=1;
        }
    }
    return 0;
}

void eje2(){
    
}

void freeC(char* x){
    delete[] x;
}

char* initC(int s){
    return new char[s];
}

void eje1(char* numero){
    int intentos=5;
    int num=rand()%9999;
    bool v=false;
    bool open=false;
    while(num<1000){
        num=rand()%9999;
    }
    string cc=to_string(num);
    cout<<endl<<cc;
    for(int i=0;i<4;i++){
        numero[i]=cc[i];
    }
   // numero=to_string(num);
    cout<<endl;
    while(intentos>0||open==false){
        int ganar=4;
        cout<<"Ingrese su número de 4 digitos: ";
        int n=0;
        cin>>n;
        cout<<endl;
        while(n<1000){
            cout<<"Error, el número no es de 4 digitos, ingrese de nuevo: ";
            cin>>n;
        }
        cout<<endl;
        char* nume=NULL;
        nume=initC(3);
        string cambiar=to_string(n);
       // nume=to_string(n);
        for(int i=0;i<4;i++){
            nume[i]=cambiar[i];
        }
        for(int i=0;i<4;i++){
            if(nume[i]==numero[i]){
                ganar=ganar-1;
                cout<<"El número "<<nume[i]<<" esta en la posicion correcta "<<endl;
            }   
        }
        freeC(nume);
        cout<<"----------------------------------------"<<endl;
        if(ganar==0){
            v=true;
            intentos=0;
            open=true;
        }else{
            intentos=intentos-1;
            cout<<"Le quedan "<<intentos<<" intentos"<<endl;
        }
        if(intentos==0){
            cout<<endl<<"Se le acabaron los intentos"<<endl;
            open=true;
        }
    }
    cout<<"---------------------------------------"<<endl;
    if(v==true){
        cout<<"Usted ha ganado"<<endl;
    }else{
        cout<<"Usted perdio"<<endl;
    }
    freeC(numero);
}
