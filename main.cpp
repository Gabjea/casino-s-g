#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

fstream f("galeti.out",fstream::in | fstream::out);

int bani,miza=0;

void menu();
void blackjack();
void ruleta();
int exit();
int roll();
int update();

int main(){
    srand(time(NULL));
    f>>bani;
    f.close();
    f.open("galeti.out",fstream::out);
    menu();

    f << bani;
    f.close();
}


void menu(){
    int r;
    cout << "1.Blackjack\n";
    cout << "2.Ruleta\n";
    cout << "3.Exit\n";
    cout << "\n\nSOLD: " << bani;
    cout << "\n\nALEGE O OPTIUNE: ";cin>>r;
    switch(r){
        case 1: {blackjack();break;}
        case 2: {ruleta();break;}
        case 3: {exit();break;}
        default: {
            system("cls");
            return menu();
            break;
        }
    }
}

void blackjack(){

}


void ruleta(){
    int k,opt,rez;
    system("cls");
    update();
    cout << "   SOLD: " << bani;
    cout << "\n\n1.ROSU\n";
    cout << "2.VERDE\n";
    cout << "3.NEGRU\n";
    cout << "4.INAPOI\n";
    cout << "5.EXIT\n\n\n";
    cout << "ALEGE O OPTIUNE:";cin>>k;
    system("cls");
    switch(k){
        case 1:{
            opt=1;
            cout << "Ai ales rosu.";
            break;
        }
        case 2:{
            opt=2;
            cout << "Ai ales verde.";
            break;
        }
        case 3:{
            opt=3;
            cout << "Ai ales negru.";
            break;
        }
        case 4:{
            system("cls");
            return menu();
            break;
        }
        case 5:{
            system("cls");
            exit();
            return;
            break;
        }
        default: {
            system("cls");
            return ruleta();
            break;
        }
    }
    cout << "\n\nALEGE SUMA PE CARE O PARIEZI: ";cin>>miza;
    if(miza>bani)
        cout << "Nu ai suficienti bani";
    else{
        int nr;
        nr= rand() % 25 + 1;
        if(nr <=14 && nr!=0)
            rez=1;
        if(nr>14)
            rez=3;
        if(nr==0) rez=2;
        if(opt == rez){
            bani+=miza;
            cout << "\nFelicitari ai castigat!!!";
            cout << "\n\nSOLD: "<< bani;
        }else{
            bani-=miza;
            cout << "Din pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
        }
    }
    cout << "\n\n1.Inapoi\n";
    cout << "2.Exit\n\n\n";
    cout << "ALEGE O OPTIUNE: ";cin>>k;
    switch(k){
        case 1:{
            system("cls");
            return menu();
            break;
        }
        case 2:{
            system("cls");
            exit();
            return;
        }
    }
}

int update(){
    bani+=miza;
    return bani;
}

int exit(){
    system("cls");
    Sleep(400);
    cout << "Exit";
    Sleep(400);
    cout << ".";
    Sleep(400);
    cout << ".";
    Sleep(400);
    cout << ".";
    Sleep(400);
    return 0;
}
