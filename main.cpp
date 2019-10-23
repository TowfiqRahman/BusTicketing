                    ///************************///
                    ///      TOWFIQ RAHMAN     ///
                    ///                        ///
                    ///     ROLL : 1404054     ///
                    ///   SEC : A   GROUP :A2  ///
                    ///   SUB : DATA STRUCTURE ///
                    ///    DPT : CSE, CUET.    ///
                    ///************************///


#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#define number 44
using namespace std;

int totalticketbooked=0;
int ticketremained=44;
bool flag[number+1];
string name[45];
string from[number+1];
string to[number+1];
char seats[45][3]={"","A1","A2","A3","A4","B1","B2","B3","B4","C1","C2","C3","C4","D1","D2","D3","D4","E1","E2","E3","E4","F1","F2","F3","F4","G1","G2","G3","G4","H1","H2","H3","H4","I1","I2","I3","I4","J1","J2","J3","J4","K1","K2","K3","K4"};

int busno();
int busseatnumber(int optsec);
void reservations();
void bookticket(int optsec);
void showchoice();
void getinfo(int n);
void showinfo(int n);
void myticket(int optsec);
void cancelticket(int optsec);

int main()
{
    system("color 03");
    int optsec=2;
    while(1){
        cout<<"\n\t\t *** Bus ticket for Chittagong to Dhaka ***"<<endl<<endl;
        int choice=0;
        char enter[2];
        showchoice();
        cout<<endl<<"\t\t Enter choice number : ";
        cin>>choice;cout<<endl;

        if(choice==1){
            cout<<endl<<"\t\t** ** Your chose show total reservation services ** **"<<endl<<endl;
            reservations();
        }
        else if(choice==2){
            cout<<endl<<"\t\t** ** Your chose ticket booking services ** **"<<endl<<endl;
            cout<<endl<<"\t\t\t ** Number of tickets available : "<<ticketremained<<endl<<endl;
            cout<<"\t\t How many tickets you want to buy ?"<<endl<<endl;
            cout<<"\t\t Number of tickets : ";
            int tkt;
            cin>>tkt;
            cout<<endl<<endl;
            while(tkt--){
                if(ticketremained==0){
                    cout<<endl<<"\t\t ** Sorry no tiket is available to purchase **"<<endl;
                }
                else{
                    optsec=2;
                    bookticket(optsec);
                    ++totalticketbooked;--ticketremained;
                }
            }
        }
        else if(choice==3){
            cout<<"\t\t** ** Your chose ticket cancalation services ** **"<<endl<<endl;
            if(totalticketbooked==0){
                cout<<"\t\t\t ** No tickets have been booked. **\n\n\t\t *** First you have to book a ticket to cancle. **"<<endl;
                }
            else{
                optsec=1;
                cancelticket(optsec);
                --totalticketbooked;++ticketremained;
            }
        }
        else if(choice==4){
            cout<<"\t\t** ** Your chose ticket showing services ** **"<<endl<<endl;
            if(totalticketbooked==0){
                cout<<"\t\t\t ** No tickets have been booked. **\n\n\t\t*** First you have to book a ticket to show. **"<<endl;
            }
            else {
                optsec=1;
                myticket(optsec);
            }
        }
        else if(choice==5){
            cout<<"\t\t\t *** Exiting from facility. *** \n\n\t\t\t ^_^ Have a safe journey. ^_^"<<endl<<endl;
            break;
        }
        else{
            cout<<"\t\t !!!!! Invalid choice !!!!!.\n\t -->See carefully and Enter Choice. "<<endl<<endl;
        }
    }
    return 0;
}
int busseatnumber(int optsec){
    int n=0;
    char seatchoice[3];
    int i;
    bool found=1;
    while(found){
        cout<<" \t\t Chose seat number : ";
            cin>>seatchoice;
        for(i=1;i<45;i++){
            if(!strcmp(seats[i],seatchoice)){
                found=0;
                n=i;
                if(optsec==1){
                    found=0;break;}
                if(optsec==2){
                    while(1){
                        if(flag[n]==1){
                            cout<<endl<<"\t\t This seat is already booked. Please chose any other seat."<<endl<<endl;
                            n=busseatnumber(2);
                        }
                        else {found=0;break;}
                    }
                }
            }
        }
        if(found){
            cout<<endl<<"\t\t !!! SORRY seat not found. Please enter in Capital Letters !!!"<<endl;
        }
    }
    return n;
}
void cancelticket(int optsec){
    int n=0;
    while(1){
        n=busseatnumber(1);
        string namec;
        if(flag[n]==0){
            cout<<endl<<"\t !!! !!! Wrong seat number. Check and Enter your seat no. !!! !!!"<<endl;
            continue;
            }
        cout<<endl<<"\t\t\t Enter passenger name :";
        cin>>namec;
        if(flag[n]==1 && !namec.compare(name[n])){
            flag[n]=0;
            name[n]="Empty";from[n]="Empty";to[n]="Empty";
            showinfo(n);
            cout<<endl<<"\t\t\t *** Ticket canceled. *** "<<endl;
            break;
        }
        else{
            cout<<endl<<"\t\t !!! Wrong passanger name. Enter correct info.!!! "<<endl;
        }
    }
}
void myticket(int optsec){
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    int n=0;
    while(1){
        n=busseatnumber(1);
        if(flag[n]==0){
            cout<<endl<<"\t\t !!! Wrong seat number. Check and Enter your seat no. !!!"<<endl;
            }
        else break;
    }
    const int no=n;
    int i,j,x=0;
    setcolor(BLUE);
    rectangle(20,80,626,336);
    rectangle(19,79,627,337);
    rectangle(21,81,625,335);

    setcolor(CYAN);
    rectangle(40,290,100,315);
    rectangle(39,289,101,316);
    rectangle(38,288,102,317);
    setcolor(YELLOW);
    char door[5]="DOOR";
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(48,295,door);

    setcolor(RED);
    rectangle(40,99,67,221);
    rectangle(41,100,66,220);
    rectangle(39,98,68,222);
    setcolor(GREEN);
    char arrA[20]=" DRIVER ";
    settextstyle(BOLD_FONT,VERT_DIR,2);
    outtextxy(43,210,arrA);

    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(260,440,290,470);
    setcolor(LIGHTRED);
    char stu[25]="YOUR SEAT";
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(310,445,stu);

    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    setcolor(LIGHTGREEN);
    for(i=0,x=1,j=0;j<11;j++){
        if(x==no)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,100,170+i,140);
        outtextxy(130+10+i,100+10,seats[x]);
        i=i+44; x+=4;
    }
    for(i=0,x=2,j=0;j<11;j++){
        if(x==no)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,144,170+i,184);
        outtextxy(130+10+i,144+10,seats[x]);
        i=i+44; x+=4;
    }
    for(i=0,x=3,j=0;j<11;j++){
        if(x==no)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,232,170+i,272);
        outtextxy(130+10+i,232+10,seats[x]);
        i=i+44; x+=4;
    }
    for(i=0,x=4,j=0;j<11;j++){
        if(x==no)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,276,170+i,316);
        outtextxy(130+10+i,276+10,seats[x]);
        i=i+44; x+=4;
    }
    getch();
    closegraph();
}
void reservations(){
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    int i,j,x;
    floodfill(1,1,BLACK);
    setbkcolor(0);
    cleardevice();
    setcolor(BLUE);
    rectangle(20,80,626,336);
    rectangle(19,79,627,337);
    rectangle(21,81,625,335);

    setcolor(CYAN);
    rectangle(40,290,100,315);
    rectangle(39,289,101,316);
    rectangle(38,288,102,317);
    setcolor(YELLOW);
    char door[5]="DOOR";
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(48,295,door);

    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(60,440,90,470);
    setcolor(LIGHTRED);
    char stu[15]="RESERVED";
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(100,445,stu);

    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    bar(400,440,430,470);
    setcolor(LIGHTRED);
    char stuA[6]="EMPTY";
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(450,445,stuA);

    setcolor(RED);
    rectangle(40,99,67,221);
    rectangle(41,100,66,220);
    rectangle(39,98,68,222);
    setcolor(GREEN);
    char arrA[20]=" DRIVER ";
    settextstyle(BOLD_FONT,VERT_DIR,2);
    outtextxy(43,210,arrA);

    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    setcolor(YELLOW);
    for(i=0,x=1,j=0;j<11;j++){
        if(flag[x]==1)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,100,170+i,140);
        outtextxy(130+10+i,100+10,seats[x]);
        i=i+44; x+=4;
    }
    for(i=0,x=2,j=0;j<11;j++){
        if(flag[x]==1)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,144,170+i,184);
        outtextxy(130+10+i,144+10,seats[x]);
        i=i+44; x+=4;
    }
    for(i=0,x=3,j=0;j<11;j++){
        if(flag[x]==1)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,232,170+i,272);
        outtextxy(130+10+i,232+10,seats[x]);
        i=i+44; x+=4;
    }
    for(i=0,x=4,j=0;j<11;j++){
        if(flag[x]==1)setfillstyle(SOLID_FILL, LIGHTBLUE);
        else setfillstyle(SOLID_FILL, LIGHTGREEN);
        bar(130+i,276,170+i,316);
        outtextxy(130+10+i,276+10,seats[x]);
        i=i+44; x+=4;
    }
    getch();
    closegraph();
}
void bookticket(int optsec){
    int n=0;
    n=busseatnumber(2);
    while(1){
        if(flag[n]==1){
        cout<<endl<<"\t\t !!! This seat is already booked. Please chose any other seat. !!! "<<endl<<endl;
        n=busseatnumber(2);
        }
        if(flag[n]==0){
            flag[n]=1;
            getinfo(n);
            showinfo(n);
            cout<<endl<<"\t\t\t ** ** Ticket booking successfull. ** ** "<<endl<<endl;
            break;
        }
    }
}
int busno(){
    int n;
    /*char place[100]="empty",coach[100]="empty";
    cout<<"\t Where do you want to go?  Enter : ";
    cin>>place;
    if(!strcmp(place,"empty")){
        cout<<"Enter correctly :";
        cin>>place;}
    cout<<"\t Day coach or Night coach. Write \"Day\" or \"Night\" ";
    cin>>coach;*/
return n;
}
void showinfo(int n){
    cout<<endl<<"\t\t  *** Showing passenger information *** "<<endl<<endl;
    cout<<"\t\t\t Seat number       : "<<seats[n]<<endl;
    cout<<"\t\t\t Passanger name    : "<<name[n]<<endl;
    cout<<"\t\t\t Get in location   : "<<from[n]<<endl;
    cout<<"\t\t\t Destination name  : "<<to[n]<<endl<<endl;
}
void getinfo(int n){
    cout<<endl<<"\t\t    Enter Passanger name : ";
    getline(cin,name[n]);
    getline(cin,name[n]);
    cout<<endl<<"\t\t    Enter place name from where to get into the bus : ";
    getline(cin,from[n]);
    cout<<endl<<"\t\t    Enter destination    : ";
    getline(cin,to[n]);
    cout<<endl;
}
void showchoice(){
    cout<<"\t\t\t What do you want to do ? "<<endl<<endl;
    cout<<"\t\t 1. Show reservations.\n\n\t\t 2. Book a ticket\n\n\t\t 3. Cancle Ticket\n\n\t\t 4. Show your seat\n\n\t\t 5. Exit facility.\n"<<endl;
}
