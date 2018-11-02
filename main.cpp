#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<cstdlib>

char*** crear(int);
void freeCampo(char***&,int);
void juego(char***,char***,int);
void initCampo(char***,int);

int main(){
    cout<<"       Bienvenido al Battle ship"<<endl;
    cout<<"-------------------------------------------"<<endl;
    char*** campo1=NULL;
    char*** campo2=NULL;
    int size=12;
    campo1=crear(size);
    campo2=crear(size);
    srand(time(NULL));
    initCampo(campo1,size);
    initCampo(campo2,size);
    cout<<endl<<"Llenado con exito"<<endl;
    juego(campo1,campo2,size);
    freeCampo(campo1,size);
    freeCampo(campo2,size);
    return 0;
}

void initCampo(char*** t,int size){
    if(t!=NULL){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                for(int k=0;k<size;k++){
                    t[i][j][k]='.';
                }
            }
        }
        int value=15;
        while(value>0){
            int r1=rand()%12;
            int r2=rand()%12;
            int r3=rand()%12;
            bool pasa=true;
            while(pasa){
                if(t[r1][r2][r3]=='.'){
                    t[r1][r2][r3]=='x';
                    pasa=false;
                    value=value-1;
                }else{
                    r1=rand()%12;
                    r2=rand()%12;
                    r3=rand()%12;
                    pasa=true;
                }
            }
        }
    }//validacion
}

void juego(char*** t1,char*** t2,int size){
    if(t1!=NULL||t2!=NULL){
        int player1=15;
        int player2=15;
        int wave1=3;
        int wave2=3;
        int exp1=3;
        int exp2=3;
        bool vivo=true;
        while(vivo==true){
            
        } 
    }//validacion
}

void freeCampo(char***& t,int size){
    if(t!=NULL){
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
    }//validacion       
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

