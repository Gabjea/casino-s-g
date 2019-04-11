#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#define ach_len 15
#define coma_set(shift) std::cout<<fixed<<showpoint<<setprecision(shift)
#define ullg unsigned long long
using namespace std;
vector <char> user_status;
vector <string> game_name;
vector <char>::iterator item_status;
vector <string>::iterator game_item;
const string g1=" blackjack:",g2=" ruleta:",g3=" dice:";
#define add_status(g_mode,status) game_name.push_back(g_mode); user_status.push_back(status)
#define set_tab '\t'
  HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);///
  const unsigned short red=1,ver=2,neg=3;
  unsigned long long vic;
  static signed v_r[4],v_BJ,v_dice;
fstream f("bani.out",fstream::in | fstream::out);
fstream nrt_hand("nrtheme.txt",fstream::in | fstream::out);
fstream pro_hand("progres.txt", ios::in | ios::out);
fstream h_handler("histo.txt",fstream::in | fstream::out);
fstream h_status("status.txt",fstream::in | fstream::out);
long double bani,miza=0;
const char win='w',draw='d',lose='l';
void update_funds();
void fix_status();
void get_stats();
void update_status();
void display_stats();
void display_ach();
void get_ach();
void update_theme();
void sch_theme();
void welcome();
void menu();
void blackjack();
void ruleta();
void dice();
int exit();
int roll();
void update();
    short theme,nr_ach;
    bool getted[ach_len+1];


int main(){
    system("Title CASINO");
    get_stats();
    nrt_hand>>theme;
    srand(time(NULL));
    f>>bani;
    nrt_hand.close();
    f.close();
    f.open("bani.out",fstream::out);
    f << bani;
    f.close();
    welcome();///**********
    get_stats();
    update_theme();
    menu();
    f.open("bani.out",fstream::out);
    f << bani;
    f.close();
}


void menu(){
    system("cls");
     cout<<"                              CASINO            "<<endl;
 cout<<"                        |--------------------------|"<<endl;
 cout<<"                        |            BY            |"<<endl;
 cout<<"                        |     GABJEA & $TANA       |"<<endl;
 cout<<"                        |                     v2.0 |"<<endl;
 cout<<"                        |--------------------------|"<<endl;//*/
    int r;
    cout << "1.Blackjack\n";
    cout << "2.Ruleta\n";
    cout << "3.Dice\n";
    cout << "4.Exit\n";
    cout<<"5.Schimba tema\n";
    cout<<"6.Realizarile mele\n";
    cout<<"7.Istoric\n";
    cout<<"8.Adauga/Schimba nr de bani\n";
    cout << "\n\nSOLD: " << bani<<"\n\n\n";
    cout << "\n\nALEGE O OPTIUNE: ";cin>>r;
    switch(r){
        case 1: {blackjack();break;}
        case 2: {ruleta();break;}
        case 3: {dice();break;}
        case 4: {exit();break;}
        case 5:{sch_theme();break;}
        case 6:{get_ach();break;}
        case 7:{display_stats();break;}
        case 8:{update_funds();break;}
        default: {
	            system("cls");
            return menu();
            break;
        }
    }
}
void blackjack(){ // este un bug in care nu poti alege nimic check it my boy xD
    ///***********
    system("cls");
    int carti,player=0,dealer=0,fdown=0,r;
    cout << "\n\nSOLD: "<< bani;
    cout << "\nALEGE SUMA PE CARE O PARIEZI: ";cin>>miza;
    if(miza>bani)
        cout << "Nu ai suficienti bani";
    else{
        bani-=miza;
        for(int i =0;i<2;i++){
            srand(time(NULL));
            carti=rand() % 10 +1;
            if(carti==1)
                carti=11;
            dealer+=carti;
            if(i==1)
                fdown=carti;
            carti= rand() % 10 +1;
            if(carti==1)
                carti=11;
            player+=carti;
            system("cls");
            Sleep(500);
            cout << "Dealer-ul are: " << dealer-fdown;
            Sleep(500);
            cout << "\nTu ai: " << player;
            Sleep(1500);
        }
        if(dealer==22){
            dealer=12;
            system("cls");
            Sleep(500);
            cout << "Dealer-ul are: " << dealer-1;
            Sleep(500);
            cout << "\nTu ai: " << player;
            Sleep(700);
            cout << "\n\nDealer-ul are Blackjack!!";
            cout << "\n\nDin pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
           add_status(g1,lose);
        }
        if(player==22){
            player=12;
            system("cls");
            Sleep(500);
            cout << "Dealer-ul are: " << dealer;
            Sleep(500);
            cout << "\nTu ai: " << player;
            Sleep(700);
            cout << "\n\nDealer-ul are Blackjack!!";
            cout << "\n\nDin pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
             add_status(g1,lose);
        }
        if(dealer==21){
            system("cls");
            Sleep(500);
            cout << "Dealer-ul are: " << dealer;
            Sleep(500);
            cout << "\nTu ai: " << player;
            Sleep(700);
            cout << "\n\nDealer-ul are Blackjack!!";
            cout << "\n\nDin pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
             add_status(g1,lose);
        }
        if(player==21){
            bani-=miza;
            system("cls");
            Sleep(500);
            cout << "Dealer-ul are: " << dealer;
            Sleep(500);
            cout << "\nTu ai: " << player;
            Sleep(700);
            cout << "\n\nAi Blackjack!!!";
            cout << "\n\nFelicitari ai castigat!!!";
            cout << "\n\nSOLD: "<< bani;
         v_BJ++;  ///*****
          add_status(g1,win);
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
        Sleep(300);
        cout << "Dealer-ul are: " << dealer;
        Sleep(500);
        cout << "\nTu ai: " << player;
        Sleep(1000);
        if(dealer>21){
            bani+=2*miza;
            cout << "\nFelicitari ai castigat!!!";
            cout << "\n\nSOLD: "<< bani;
            add_status(g1,win);
           ///*************
           v_BJ++;
        }
        else if(player>21){
            cout << "\n\nDin pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
             add_status(g1,0);
        }else {
            if(dealer < player){
                bani+=2*miza;
                cout << "\nFelicitari ai castigat!!!";
                cout << "\n\nSOLD: "<< bani;
                v_BJ++;///************************
                 add_status(g1,win);
            }
            else if(player < dealer){
                    cout << "\n\nDin pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
                    add_status(g1,lose);
            }else {cout << "\n\nEste egalitate.Nimeni nu a castigat!!";
                bani+=miza;
                add_status(g1,draw);
            }

        }
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
    cout << "\n\nSOLD: "<< bani;
    cout << "\nALEGE SUMA PE CARE O PARIEZI: ";cin>>miza;
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
        switch(rez){
                case 1: {cout << "\nA cazut rosu!";break;}
                case 2: {cout << "\nA cazut verde!";break;}
                case 3: {cout << "\nA cazut negru!";break;}
            }
        if(opt == rez){
            if(opt==2)
                bani+=miza*14;
            else bani+=miza;
            cout << "\nFelicitari ai castigat!!!";
            cout << "\n\nSOLD: "<< bani;
            ///****************************************************
          add_status(g2,win);
            if (opt==red)
                v_r[red]++;
            else
                if (opt==ver)
                v_r[ver]++;
            else
                if (opt==neg)
                v_r[neg]++;
        }else{
            bani-=miza;
            cout << "\nDin pacate ai pierdut, mai incearca!";
            cout << "\n\nSOLD: "<< bani;
           add_status(g2,lose);
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
    cout << "\n\nSOLD: "<< bani;
    cout << "\nALEGE SUMA PE CARE O PARIEZI: ";cin>>miza;
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
                    v_dice++;///************
                    add_status("dice:",win);
                }else{
                    bani-=miza;
                    cout << "Din pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
                    add_status("dice:",lose);
                }
                break;
            }
            case 2: {
                system("cls");
                cout << "ALEGE UN NUMAR: ";cin>>r;
                if(r==nr){
                    bani+=5*miza;
                    cout << "\nFelicitari ai castigat!!!";
                    cout << "\n\nSOLD: "<< bani;///*****
                  v_dice++;
                  add_status("dice:",win);
                }else{
                    bani-=miza;
                    cout << "Din pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
                    add_status("dice:",lose);
                }
                break;
            }
            case 3: {
                 if(nr >3){
                    bani+=miza;
                    cout << "\nFelicitari ai castigat!!!";
                    cout << "\n\nSOLD: "<< bani;
                    v_dice++;
                    add_status("dice:",win);
                }else{
                    bani-=miza;
                    cout << "Din pacate ai pierdut, mai incearca!";
                    cout << "\n\nSOLD: "<< bani;
                     add_status("dice:",lose);
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
        case 2:{ //
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
    fix_status();
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
void welcome ()
{
    short aux;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

    for (short i=0;i<=100;i++)
    {
        cout<<' '<<i<<'%'<<endl;
        SetConsoleTextAttribute(hStdOut,25);
        for (short j=0;j<=i;j++) {
            cout<<"  ";
         if (j==100) {
                SetConsoleTextAttribute(hStdOut,17);
         }
        }
        Sleep(25);
        if (i!=100) {
           SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
        system("cls");
        }
    }
 SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    while (true) {
        cout<<endl;
            for (int j=1;j<=98;j++)
            cout<<" ";
    cout<<" Apasa orice pt a continua!\n";
    char ch;

        if (kbhit) {
            ch = getch();
            if (int(ch))
                break;
          }
        }
SetConsoleTextAttribute(hStdOut,15);
system("cls");
}
///****************************************************
void sch_theme()
{

    for (short i=1;i<=256;i++)
    {
        SetConsoleTextAttribute(col,i);
        cout<<"Tema numarul "<<i<<endl;
    }
    SetConsoleTextAttribute(col,15);
    cout<<"Alege una din temele de mai sus:";
    cin>>theme;
    nrt_hand.open("nrtheme.txt",fstream::out);
        nrt_hand<<theme;
        cout<<"Aplicatia se va inchide,pls deschide-o din nou apoi pt a avea tema noua!";
        nrt_hand.close();
        Sleep(3998);
        exit();//*/
}

void update_theme()
{

    if (!theme)
    theme=15;
    else {
    SetConsoleTextAttribute(col,theme);
    }
    system("cls");
    return;
}///******************************************************

void display_ach()
{

    size_t cont;
    double p;
    system("cls");
  cout<<"\n Aici sunt realizarile tale,joaca cat mai mult pt a obtine mai multe!(aceste realizari trebuie facute fara sa inchizi casinoul)\n\n";
string ach_list[ach_len+1];
 ach_list[0]="  NOROCU INCEPATORULUI (ai castigat o data la BLACJACK in aceasta sesiune)";
ach_list[1]="  NOVICE (ai castigat de 3 ori la BLACJACK in aceasta sesiune)";
ach_list[2]="  MAESTRU (ai castigat de 5 ori la BLACJACK in aceasta sesiune)";
ach_list[3]="  CAMPION PA SATE (ai castigat de 10 ori la BLACJACK in aceasta sesiune)";
ach_list[4]="  ROSIATICUL (castiga o data la ruleta cu rosu in aceasta sesiune)";
ach_list[5]="  ROSU ADUCE NOROC (castiga de 3 ori la ruleta cu rosu in aceasta sesiune)";
ach_list[6]="  FULL RED (castiga de 5 de ori la ruleta cu rosu in aceasta sesiune)";
ach_list[7]="  VERZISOR (castiga odata la ruleta cu verde in aceasta sesiune)";
ach_list[8]="  ECOLOGIC (castiga de 3 de ori la ruleta cu verde in aceasta sesiune)";
ach_list[9]="  NATURAL (castiga de 5 de ori la ruleta cu verde in aceasta sesiune)";
ach_list[10]="  NEGROTEL (castiga odata la ruleta cu negru in aceasta sesiune)";
ach_list[11]="  INTUNECATUL (castiga de 3 ori la ruleta cu negru in aceasta sesiune)";
ach_list[12]="  TIGAN (castiga de 5 de ori la ruleta cu negru in aceasta sesiune)";
ach_list[13]="  INCEPATOR (castiga odata la dice in aceasta sesiune)";
ach_list[14]="  NOROCOS (castiga de 3 ori la dice in aceasta sesiune)";
ach_list[15]="  MAESTRU AL ZARURILOR (castiga de 7 de ori la zaruri in aceasta sesiune)";

 nr_ach=0;///**********
  for ( cont=0;cont<ach_len;cont++)///
      if (getted[cont]) {
           cout<<ach_list[cont]<<endl;
           nr_ach++;
  }//*/
  ///***************************************************************************
  cout<<"\n Realizari obtinute:";
  cout<<nr_ach<<"/"<<ach_len+1;
  p=(float)nr_ach/((float)ach_len+1.0);
  p*=100.0;
  coma_set(2);
  cout<<"  ("<<p<<"%)"<<endl;
 ullg nr;
      pro_hand.close();
        pro_hand.open("progres.txt",fstream::in);
        pro_hand>>nr;
         pro_hand.close();
         cout<<"Ai obtinut toate realizarile de in aceasi tura de "<<nr<<" ori\n";
 if (nr_ach/ach_len==1) {
  cout<<"Felicitari ai obtinut toate realizarile in aceasta sesiune!!!"<<endl;
 ullg x;
    pro_hand>>x;
    pro_hand.close();
    x++;
    pro_hand.open("progres.txt",fstream::out);
    pro_hand<<x;
    pro_hand.close();
    cout<<" Aceasta e sesiunea cu nr "<<x<<" in care le-ai obtinut pe toate!!!\n"<<endl;
  }
    int o;
cout<<"\n \n 1.Inapoi\n 2.Exit\n";cin>>o;
 if (o==1)
 {
 system("cls");
 return menu();}
 else {
    exit();
 }
}
void get_ach()
{
    cout<<"\a";
 switch (v_BJ)
{
 case 1 ... 2:getted[0]=true;break;
 case 3 ... 4: getted[1]=true;break;
 case 5 ...9 :getted[2]=true;break;
 default : if (v_BJ>=10)
               getted[3]=true;
}
for (short i=1;i<4;i++)
switch (v_r[i])
{
    case 1 ... 2:getted[i*3+1]=true;break;
    case 3 ... 4:getted[i*3+2]=true;break;
    default : if (v_r[i]>=5)
                getted[3*(i+1)]=true;
}

switch (v_dice)
{
    case 1 ... 2:getted[13]=true;break;
    case 3 ... 6:getted[14]=true;;break;
    default : if (v_dice>=7)
                 getted[15]=true;
}

return display_ach();
}
///******************
void get_stats()
{
    string g_type;
    char curr_s;
  while (h_handler>>g_type)
game_name.push_back(g_type);
h_handler.close();
while (h_status>>curr_s)
    user_status.push_back(curr_s);
            return;
}

void fix_status()
{
 h_handler.close();///***********************************************************************
 h_handler.open("histo.txt",fstream::out);
 item_status=user_status.begin();
 game_item=game_name.begin();
 while (game_item!=game_name.end())
 {
     h_handler<<*game_item<<' ';
     game_item++;
     //h_handler<<"\n";
 }
h_handler.close();
h_status.close();
h_status.open("status.txt",fstream::out);
while (item_status!=user_status.end())
{
    h_status<<*item_status<<' ';
   item_status++;
}
h_status.close();
    return;
}

void display_stats()
{///***
    system("cls");
 cout<<" Istoric victorii/infrangeri:\n";
 cout<<" Tip joc";
 for (int i=0;i<3;i++)///
    cout<<set_tab;
 cout<<" Rezultat\n";
 for (int i=0;i<45;i++)
    cout<<'-';
    cout<<"\n\n";
    ///***/***************************************************//////////////***********
if (user_status.empty())
    cout<<" WOW,istoricul e gol , mai joaca si tu ceva!\n";
item_status=user_status.begin();
game_item=game_name.begin();
while (item_status!=user_status.end()&&game_item!=game_name.end())
    {
      cout<<*game_item;
 for (int i=0;i<3;i++)
    cout<<set_tab;
 if (*item_status=='w')
    cout<<"victorie";
 else
    if (*item_status=='d')
     cout<<"remiza";
  else
     cout<<"invins";
        cout<<endl;
   game_item++;
   item_status++;
 }
 for (int i=0;i<45;i++)
    cout<<'-';

    ullg games_nr,games_draw,games_win,games_lost;
    games_nr=user_status.size();
    games_win=count(user_status.begin(),user_status.end(),win);
    games_lost=count(user_status.begin(),user_status.end(),lose);
    games_draw=games_nr-(games_lost+games_win);
    coma_set(3);
    float p1,p2,p3=100;
    p1=(static_cast<float>(games_win)/static_cast<float>(games_nr))*100;
    p2=(static_cast<float>(games_lost)/static_cast<float>(games_nr))*100;
    p3-=(p2+p1);
    cout<<"\n Numar total de meciuri: "<<games_nr<<endl;
    cout<<" Dintre care:"<<endl;
    cout<<games_win<<" castigate ";
    cout<<" ("<<p1<<"%)\n";
    cout<<games_lost<<" pierdute ";
    cout<<" ("<<p2<<"%)\n";
    cout<<games_draw<<" remiza ";
    cout<<" ("<<p3<<"%)\n";///********************************

    ///*****

  cout<<"\n\n\n";
      short o;
      cout<<" Alege o optiune:\n";
      cout<<" 1.Inapoi"<<endl;
      cout<<" 2.Sterge istoricul\n";
      cout<<" 3.Exit"<<endl;
      coma_set(2);
      cin>>o;
      system("cls");
      if (o==1)
        return menu();
  else
      if (o==2)
 {
     user_status.clear();
     game_name.clear();
     cout<<"Istoricul se sterge ";
     for (short i=0;i<4;i++)
     {
         cout<<'.';
         Sleep(1000);
     }
     return display_stats();
 }
 else
    if (o==3)
        exit();
else
    return display_stats();
}

void update_funds()
{
    system("cls");
    cout<<"1.Adauga bani\n";
    cout<<"2.Schimba nr de bani\n";
    short o;
    long double nr_f;
    cin>>o;
    system("cls");
    if (o==1)
    {
        cout<<"Cati bani adaugi:";
        cin>>nr_f;
        bani+=nr_f;
    }
    else
        if (o==2)
    {
        cout<<"Cati bani ai:";
        cin>>nr_f;
        bani=nr_f;
    }
    else
        return update_funds();
     f.close();
    f.open("bani.out",fstream::out);
    f << bani;
    f.close();
    return menu();
}
///******
