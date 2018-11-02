#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<cstdlib>

char*** crear(int);
void freeCampo(char***&,int);
void juego(char***,char***,int);
void initCampo(char***,int);
void location(char***,int);

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
    cout<<"------------------------------------------"<<endl;
    cout<<"Jugador 1"<<endl;
    cout<<"------------------------------------------"<<endl;
    location(campo1,size);
    cout<<"Jugador 2"<<endl;
    cout<<"------------------------------------------"<<endl;
    location(campo2,size);
    cout<<"------------------------------------------"<<endl;
    juego(campo1,campo2,size);
    freeCampo(campo1,size);
    freeCampo(campo2,size);
    return 0;
}

void location(char*** t,int size){
    if(t!=NULL){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                for(int k=0;k<size;k++){
                    if(t[i][j][k]=='x'){
                        cout<<"("<<i<<","<<j<<","<<k<<")"<<endl;
                    }
                }
            }
        }
    }//validacion
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
                    t[r1][r2][r3]='x';
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
            cout<<"Jugador 1"<<endl;
            cout<<"-----------------------------------------"<<endl;
            cout<<"¿Que ataque desea?\n1)Ataque normal(ilimitado)\n2)Wave(Quedan "<<wave1<<" restantes)\n3)Expansive(Quedan "<<exp1<<" restantes)"<<endl;
            cout<<"-----------------------------------------"<<endl;
            cout<<"Ingrese el número correspondiente: ";
            int op1=0;
            cin>>op1;
            cout<<endl<<"--------------------------------------"<<endl;
            while(op1>3||op1<0){
                cout<<endl<<"Error, ingrese de nuevo: ";
                cin>>op1;
                cout<<endl<<"-------------------------------------"<<endl;
            }
            if(op1==1){
                cout<<"Ingrese x: ";
                int x=0;
                cin>>x;
                cout<<endl;
                while(x<0||x>12){
                    cout<<endl<<"Error, ingrese de nuevo: ";
                    cin>>x;
                    cout<<endl;
                }
                cout<<"Ingrese y: ";
                int y=0;
                cin>>y;
                cout<<endl;
                while(y<0||y>12){
                    cout<<endl<<"Error, ingrese de nuevo: ";
                    cin>>y;
                    cout<<endl;
                }
                cout<<"Ingrese z: ";
                int z=0;
                cin>>z;
                cout<<endl;
                while(z<0||z>12){
                    cout<<endl<<"Error, ingrese de nuevo: ";
                    cin>>z;
                    cout<<endl;
                }
                if(t2[x][y][z]=='x'){
                    player2=player2-1;
                    cout<<"Le dio a un barco\nAl jugador 2 le quedan: "<<player2<<endl;
                    t2[x][y][z]='*';
                }else{
                    cout<<"No le dio a nada"<<endl;
                }
            }
            if(op1==2){
                
            }
            if(op1==3){
            
            }
            cout<<endl<<"Jugador 2"<<endl;
            cout<<"-----------------------------------------"<<endl;
            cout<<"¿Que ataque desea?\n1)Ataque normal(ilimitado)\n2)Wave(Quedan "<<wave2<<" restantes)\n3)Expansive(Quedan "<<exp2<<" restantes)"<<endl;
            cout<<"-----------------------------------------"<<endl;
            cout<<"Ingrese el número correspondiente: ";
            int op2=0;
            cin>>op2;
            while(op2>3||op2<0){
                cout<<endl<<"Error, ingrese de nuevo: ";
                cin>>op2;
            }
            if(op2==1){
                cout<<"Ingrese x: ";
                int x=0;
                cin>>x;
                cout<<endl;
                while(x<0||x>12){
                    cout<<endl<<"Error, ingrese de nuevo: ";
                    cin>>x;
                    cout<<endl;
                }
                cout<<"Ingrese y: ";
                int y=0;
                cin>>y;
                cout<<endl;
                while(y<0||y>12){
                    cout<<endl<<"Error, ingrese de nuevo: ";
                    cin>>y;
                    cout<<endl;
                }
                cout<<"Ingrese z: ";
                int z=0;
                cin>>z;
                cout<<endl;
                while(z<0||z>12){
                    cout<<endl<<"Error, ingrese de nuevo: ";
                    cin>>z;
                    cout<<endl;
                }
                if(t1[x][y][z]=='x'){
                    player1=player1-1;
                    cout<<"Le dio a un barco\nAl jugador 1 le quedan: "<<player1<<endl;
                    t1[x][y][z]='*';
                }else{
                    cout<<"No le dio a nada"<<endl;
                }

            }
            if(op2==2){
                cout<<endl<<"1)Ataque XY\n2)Ataque XZ\n3)Ataque YZ"<<endl;
                cout<<"Ingrese la opcion correspondiente: ";
                int o=0;
                cin>>o;
                while(o<0||o>3){
                    cout<<"Error, ingrese correctamente: ";
                    cin>>o;
                    cout<<endl;
                }
                if(o==1){
                
                }
                if(o==2){

                }
                if(o==3){

                }
            }
            if(op2==3){

            }
            if(player1==0||player2==0){
                vivo=false;
            }
        }
        if(player1==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"El jugador 2 ha ganado, ¡Felicidades!"<<endl;
        }
        if(player2==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"El jugador 1 ha ganado, ¡Felicidades!"<<endl;
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

