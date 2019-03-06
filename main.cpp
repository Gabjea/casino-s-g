#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

ifstream f("galeti.in");
ofstream g("galeti.out");

int bani;

void menu();
void blackjack();
void ruleta();
int exit();
int update();

int main(){
    srand(time(NULL));
    f>>bani;
    menu();

    g << bani;
    g.close();
}


void menu(){
    int r;
    cout << "1.Blackjack\n";
    cout << "2.Ruleta\n";
    cout << "3.Exit\n";
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

void roll(){
    int nr,roll=0;
    nr= rand() % 25 + 1;
    if(nr <=14 && nr!=0)
        roll=1;
    if(nr>14)
        roll=3;
    else roll=2;
}

void ruleta(){
    int k,opt,miza;
    system("cls");
    update();
    cout << "   SOLD: " << bani;
    cout << "\n\n1.ROSU\n";
    cout << "2.VERDE\n";
    cout << "3.NEGRU\n";
    cout << "4.INAPOI\n";
    cout << "5.EXIT\n\n\n";
    cout << "ALEGE O OPTIUNE:";cin>>k;
    roll();
    switch(k){
        case 1:{
            opt=1;break;
        }
        case 2:{
            opt=2;break;
        }
        case 3:{
            opt=3;break;
        }
        default: {
            system("cls");
            return ruleta();
            break;
        }
    }

    //if(opt == roll)
}

int update(){
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
