#include<iostream>
using std::cin;
using std::cout;
using std::endl;

char*** crear(int);
void freeCampo(char***&,int);
void juego(char***&,int);
void initCampo(char***&,int);

int main(){
    cout<<"       Bienvenido al Battle ship"<<endl
    cout<<"-------------------------------------------"<<endl;
    char*** campo=NULL;
    int size=12;
    campo=crear(size);
    initCampo(campo,size);
    juego(campo,size);
    freeCampo(campo,size);
    return 0;
}

void initCampo(char*** t,int size){
    
}

void juego(char*** t,int size){
    
}

void freeCampo(char***& t,int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
//            for(int k=0;k<size;k++){
            delete[] t[i][j];
            t[i][j]=NULL;
//            }
        }
    }
    for(int i=0;i<size;i++){
        //for(int j=0;j<size;j++){
        delete[] t[i];
        t[i]=NULL;
        //}
    }
    delete[] t;
    t=NULL;       
}

char*** crear(int size){
    char*** t=new char**[size];
    for(int i=0; i<size;i++){
        t[i]=new char*[size];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            t[i][j]=new char[size];
        }
    }
    return t;
}

