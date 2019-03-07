#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

fstream f("bani.out",fstream::in | fstream::out);

int bani,miza=0;

void menu();
void blackjack();
void ruleta();
void dice();
int exit();
int roll();
void update();

int main(){
    srand(time(NULL));
    f>>bani;
    f.close();
    f.open("bani.out",fstream::out);
    f << bani;
    f.close();
    menu();
    f.open("bani.out",fstream::out);
    f << bani;
    f.close();
}


void menu(){
    int r;
    cout << "1.Blackjack\n";
    cout << "2.Ruleta\n";
    cout << "3.Dice\n";
    cout << "4.Exit\n";
    cout << "\n\nSOLD: " << bani;
    cout << "\n\nALEGE O OPTIUNE: ";cin>>r;
    switch(r){
        case 1: {blackjack();break;}
        case 2: {ruleta();break;}
        case 3: {dice();break;}
        case 4: {exit();break;}
        default: {
            system("cls");
            return menu();
            break;
        }
    }
}

void blackjack(){ // este un bug in care nu poti alege nimic check it my boy xD
    system("cls");
    int carti,player=0,dealer=0,fdown=0,r;
    cout << "\n\nALEGE SUMA PE CARE O PARIEZI: ";cin>>miza;
    if(miza>bani)
        cout << "Nu ai suficienti bani";
    else{
        bani-=miza;
        for(int i =0;i<2;i++){
            srand(time(NULL));
            carti=rand() % 10 +1;
            dealer+=carti;
            if(i==1)
                fdown=carti;
            carti= rand() % 10 +1;
            player+=carti;
            system("cls");
            Sleep(500);
            cout << "Dealer-ul are: " << dealer-fdown;
            Sleep(500);
            cout << "\nTu ai: " << player;
            Sleep(1500);
        }
        while(dealer <=17 && player<21){
            system("cls");
            Sleep(500);
            cout << "Dealer-ul are: " << dealer-fdown;
            Sleep(500);
            cout << "\nTu ai: " << player;
            Sleep(1000);
            cout << "\n\n|   HIT   |   STAND   |   DOUBLE-DOWN   |";
            cout << "\n\n ALEGE O OPTIUNE: ";cin >> r;
            if(r==1){
                srand(time(NULL));
                carti=rand() % 10 +1;
                player+=carti;
            }
            if(r==2){
                while(dealer<=17){
                    system("cls");
                    Sleep(500);
                    cout << "Dealer-ul are: " << dealer;
                    Sleep(500);
                    cout << "\nTu ai: " << player;
                    Sleep(1000);
                    srand(time(NULL));
                    carti=rand() % 10 +1;
                    dealer+=carti;
                }
                system("cls");
                Sleep(500);
                cout << "Dealer-ul are: " << dealer;
                Sleep(500);
                cout << "\nTu ai: " << player;
                Sleep(1000);
                break;
            }
            if(r==3){
                if(miza>bani)
                    cout << "Nu ai destui bani";
                else bani-=miza;
                miza+=miza;
                srand(time(NULL));
                carti= rand() % 10 +1;
                player+=carti;
                system("cls");
                Sleep(500);
                cout << "Dealer-ul are: " << dealer;
                Sleep(500);
                cout << "\nTu ai: " << player;
                Sleep(1000);
                while(dealer<17){
                    system("cls");
                    Sleep(500);
                    cout << "Dealer-ul are: " << dealer;
                    Sleep(500);
                    cout << "\nTu ai: " << player;
                    Sleep(1000);
                    srand(time(NULL));
                    carti=rand() % 10 +1;
                    dealer+=carti;
                    break;
                }
            }
        }
        system("cls");
        Sleep(500);
        cout << "Dealer-ul are: " << dealer;
        Sleep(500);
        cout << "\nTu ai: " << player;
        Sleep(1000);
        if(dealer>21){
            bani+=2*miza;
            cout << "\nFelicitari ai castigat!!!";
            cout << "\n\nSOLD: "<< bani;
        }
        else if(player>21){
            cout << "\n\nDin pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
        }else {
            if(dealer < player){
                bani+=2*miza;
                cout << "\nFelicitari ai castigat!!!";
                cout << "\n\nSOLD: "<< bani;
            }
            else if(player < dealer){
                    cout << "\n\nDin pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
            }else cout << "\n\nEste egalitate.Nimeni nu a castigat!!";

        }

    }
}


void ruleta(){
    int k,opt,rez;
    system("cls");
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
        nr= rand() % 25;
        if(nr <=14 && nr!=0)
            rez=1;
        if(nr>14)
            rez=3;
        if(nr==0) rez=2;
        if(opt == rez){
            if(opt==2)
                bani+=miza*14;
            else bani+=miza;
            cout << "\nFelicitari ai castigat!!!";
            cout << "\n\nSOLD: "<< bani;
        }else{
            bani-=miza;
            cout << "Din pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
        }
    }
    update();
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

void dice(){
    system("cls");
    int r,opt,rez,nr;
    cout << "1.LOW[1-3]\n2.ALEGE UN NR\n3.HIGH[4-5]\n4.INAPOI\n5.EXIT";
    cout << "\n\n\nALEGE O OPTIUNE: ";cin>>r;
    system("cls");
    switch(r){
        case 1: {opt=1;break;}
        case 2: {opt=2;break;}
        case 3: {opt=3;break;}
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
    }
    cout << "\n\nALEGE SUMA PE CARE O PARIEZI: ";cin>>miza;
    if(miza>bani)
        cout << "Nu ai suficienti bani";
    else{
        nr=rand() % 6 + 1;
        switch(opt){
            case 1: {
                if(nr <=3){
                    bani+=miza;
                    cout << "\nFelicitari ai castigat!!!";
                    cout << "\n\nSOLD: "<< bani;
                }else{
                    bani-=miza;
                    cout << "Din pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
                }
                break;
            }
            case 2: {
                system("cls");
                cout << "ALEGE UN NUMAR: ";cin>>r;
                if(r==nr){
                    bani+=5*miza;
                    cout << "\nFelicitari ai castigat!!!";
                    cout << "\n\nSOLD: "<< bani;
                }else{
                    bani-=miza;
                    cout << "Din pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
                }
                break;
            }
            case 3: {
                 if(nr >3){
                    bani+=miza;
                    cout << "\nFelicitari ai castigat!!!";
                    cout << "\n\nSOLD: "<< bani;
                }else{
                    bani-=miza;
                    cout << "Din pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
                }
                break;
            }
        }
        cout << "\n\nA cazut " << nr;
    }

    update();
    cout << "\n\n1.Inapoi\n";
    cout << "2.Exit\n\n\n";
    cout << "ALEGE O OPTIUNE: ";cin>>r;
    switch(r){
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

void update(){
    f.open("bani.out",fstream::out);
    f << bani;
    f.close();
}
///
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
