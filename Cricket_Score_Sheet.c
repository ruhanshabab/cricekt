#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <unistd.h>

int choich(int innings);
void scorebord();
void start();

int i,t,cunt,X,Ball,ball,Over,pl[2];
int temp = 0 ;
int total_run=0;
int flag = 0 ;
int run_counter            = 0 ;
int out_every_over         = 0 ;
int wide     = 0 ;
int noball     = 0 ;
int lb=0;
int wide_flag         = 0 ;
int target=0;
int freehit=0;
int d=0;
char current_bowler[20];
int current_bowler_no=-1;
int current_batsman_no;
char current_batsman[20];
int wicket;
int extra, bowler_used_no[10], bowler_used_total;
char team1[30],team2[30];
int innings1run,innings1ball,innings1wicket,innings1runrate,innings2runrate;

COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)//change Cursor Location
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void initialize()//initialize Value
{
    i,t,cunt,X,Ball,ball,Over,pl[2];
    temp = 0 ;
    total_run=0;
    flag = 0 ;
    run_counter            = 0 ;
    out_every_over         = 0 ;
    wide     = 0 ;
    noball     = 0 ;
    lb=0;
    wide_flag         = 0 ;
    target=0;
    freehit=0;
    d=0;
    current_bowler[20];
    current_bowler_no=-1;
    current_batsman_no;
    current_batsman[20];
    wicket=0;
    extra;
    bowler_used_no[10];
    bowler_used_total=0;



}
void hundred(char nm[])//100 run celebration
{
    int x,i,j=300000;
    system("cls");
    gotoxy(50,9);
    puts(nm);
    for(i=1; i<105; i++)
    {
        gotoxy(i,2);
        printf("   ____     ________    ________\n");
        gotoxy(i,3);
        printf("  |__  |   |  ____  |  |  ____  |\n");
        gotoxy(i,4);
        printf("     | |   | |    | |  | |    | |\n");
        gotoxy(i,5);
        printf("     | |   | |    | |  | |    | |\n");
        gotoxy(i,6);
        printf("   __| |_  | |____| |  | |____| |\n");
        gotoxy(i,7);
        printf("  |______| |________|  |________|\n");
        usleep(j);
        j = (int)(j * .8);
    }
    system("cls");
}

void fifty(char nm[])//50 Run Celebration
{
    int x,i,j=300000;
    system("cls");
    gotoxy(50,9);
    puts(nm);
    for(i=1; i<95; i++)
    {

        gotoxy(i,2);
        printf("    ________     ________\n");
        gotoxy(i,3);
        printf("   |  ______|   |  ____  |\n");
        gotoxy(i,4);
        printf("   | |______    | |    | |\n");
        gotoxy(i,5);
        printf("   |______  |   | |    | |\n");
        gotoxy(i,6);
        printf("    ______| |   | |____| |\n");
        gotoxy(i,7);
        printf("   |________|   |________|\n");
        usleep(j);
        j = (int)(j * .8);
    }
    //system("pause");
    system("cls");
}

void Out()//Out Celebration
{
    int x,i,j=300000;

    for(i=62; i<75; i++)
    {

        gotoxy(i,2);
        printf("  ________    _      _    __________\n");
        gotoxy(i,3);
        printf(" |  ____  |  | |    | |  |___   ____|\n");
        gotoxy(i,4);
        printf(" | |    | |  | |    | |      | |\n");
        gotoxy(i,5);
        printf(" | |    | |  | |    | |      | |\n");
        gotoxy(i,6);
        printf(" | |____| |  | |____| |      | |\n");
        gotoxy(i,7);
        printf(" |________|  |________|      |_|\n");
        gotoxy(i,8);
        usleep(j);
        j = (int)(j * .8);
    }
    //system("pause");
    system("cls");
}

void four()//Four Celebration
{
    int x,i,j=300000;

    for(i=62; i<95; i++)
    {

        gotoxy(i,2);
        printf("   _      _\n");
        gotoxy(i,3);
        printf("  | |    | |\n");
        gotoxy(i,4);
        printf("  | |____| |\n");
        gotoxy(i,5);
        printf("  |______  |\n");
        gotoxy(i,6);
        printf("         | |\n");
        gotoxy(i,7);
        printf("         |_|\n");
        gotoxy(i,8);
        usleep(j);
        j = (int)(j * .8);
    }
    //system("pause");
    system("cls");
}

void six()//Six Celebration
{
    int x,i,j=300000;

    for(i=62; i<95; i++)
    {

        gotoxy(i,2);
        printf("   ________\n");
        gotoxy(i,3);
        printf("  |  ______|\n");
        gotoxy(i,4);
        printf("  | |______\n");
        gotoxy(i,5);
        printf("  |  ____  |\n");
        gotoxy(i,6);
        printf("  | |____| |\n");
        gotoxy(i,7);
        printf("  |________|\n");
        gotoxy(i,8);
        usleep(j);
        j = (int)(j * .8);
    }
    //system("pause");
    system("cls");
}

struct gamedetails//for the records of game details//
{
    char competition[20];
    char playedAt[50];
    char venue[30];
    char matchbetween[30];
    char versus[30];
    char tosswonby[30];
    char electedto[20];
    int inningsof;
    char date[30];
    char input;
    int overs;
    char Batting_team_Name[20];
    char Bowling_team_Name[20];
    int over;
    int Bowler_max_over;

} game,GAME;

struct player_details//making data type
{
    char name[50];
    int run;
    int ball;
    double strick_rate;
    int out;
    int four;
    int six;

    int maiden_over;
    int totalball;
    int given_run;
    int wicket;
    int maiden;
    int NB;
    int WD;
    float ECO;
    char skill[20];
} Batsman[12],Bowler[12],cng;

void instruction()// instruction
{
    system("cls");
    system("COLOR 0A");
    printf(" \n\n\n\t\t\t _____________________________________________________________\n");
    printf(" \t\t\t|                        Instruction                         |\n");
    printf(" \t\t\t|____________________________________________________________|\n");
    printf("\t\t\t For,\n\t\t\t  Run      -   0-6\n");
    printf("\t\t\t  Wicket   - \'w\'\n");
    printf("\t\t\t  Run Out  -  ro\'0-3\'\n");
    printf("\t\t\t  No Ball  - \"nb\" \n");
    printf("\t\t\t  Bye      - \'b\' \n");
    printf("\t\t\t  Wide     - \"wd\" \n");
    printf("\t\t\t  Lag bye  - \"lb\" \n");
    printf("\t\t\t  Wide and Run       - wd\'0-4\'\n");
    printf("\t\t\t  Lag bye and Run    - lb\'0-4\'\n");
    printf("\t\t\t  No Ball and Run    - nb\'0-6\'\n");
    printf("\t\t\t  Bye and Run        - b\'0-3\'\n");
    printf("\t\t\t  For No Ball and Lag bye - \"nblb\'0-4\'\" \n");
    printf("\t\t\t  Wide and Run Out        - wdro\'0-3\'\n");
    printf("\t\t\t  For No Ball and Wicket  - \"nbw\" \n");
    printf("\t\t\t  No Ball and Bye Run     - nbb\'0-4\' \n");
    printf("\t\t\t  ScoreBoard  - \'s\' \n");
    printf("\t\t\t  ");
    system("pause");
    system("cls");
}
void details(int cunter)//Details
{
    cunter++;
    system("cls");
    system("COLOR 0A");
    printf(" \n\n\n\t\t\t _____________________________________________________________\n");
    printf(" \t\t\t|                        Game Details                        |\n");
    printf(" \t\t\t|____________________________________________________________|\n");
    printf(" \t\t\t||------------------------------|                            |\n");
    printf(" \t\t\t||           MANU               |                            |\n");
    printf(" \t\t\t||------------------------------|                            |\n");
    printf("\t\t\t|| Vanue         : %13s|                            |\n",game.venue);
    printf("\t\t\t|| Match between : %13s|                            |\n",game.matchbetween);
    printf("\t\t\t|| Versus        : %13s|                            |\n",game.versus);
    printf("\t\t\t|| Toss won by   : %13s|                            |\n",game.tosswonby);
    if(cunter==7)
        printf("\t\t\t|| Total Over    : %13d|                            |\n",game.over);
    else
        printf("\t\t\t|| Total Over    :              |                            |\n");
    printf("\t\t\t||______________________________|                            |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t|                                                            |\n");
    printf("\t\t\t|____________________________________________________________|\n");
    if(cunter==2)
    {
        gotoxy(45,9);
        //printf(" Vanue  : ");
        gets(game.venue);
        system("cls");
        details(cunter);
        d=0;
    }
    else if(cunter==3)
    {
        gotoxy(59,6);
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n");
        gotoxy(59,7);
        printf("| 1.   |  Bangladesh    |\n");
        gotoxy(59,8);
        printf("| 2.   |  India         |\n");
        gotoxy(59,9);
        printf("| 3.   |  Australia     |\n");
        gotoxy(59,10);
        printf("| 4.   |  England       |\n");
        gotoxy(59,11);
        printf("| 5.   |  Ireland       |\n");
        gotoxy(59,12);
        printf("| 6.   |  New Zealand   |\n");
        gotoxy(59,13);
        printf("| 7.   |  Pakistan      |\n");
        gotoxy(59,14);
        printf("| 8.   |  South Africa  |\n");
        gotoxy(59,15);
        printf("| 9.   |  Sri Lanka     |\n");
        gotoxy(59,16);
        printf("|10.   |  West Indies   |\n");
        gotoxy(59,17);
        printf("|11.   |  Zimbabwe      |\n");
        gotoxy(59,18);
        printf("|");
        for(int i=0; i<23; i++)
            printf("_");

        printf("|");

        int ck=-1;
        gotoxy(53,10);
        scanf("%d",&ck);
        if(ck>11&&ck<0)
            d=-1,cunter--,game.matchbetween[0]='\0';
        else
        {
            d=0;
            if(ck==1)
                strcpy(game.matchbetween,"Bangladesh");
            if(ck==2)
                strcpy(game.matchbetween,"India");
            if(ck==3)
                strcpy(game.matchbetween,"Australia");
            if(ck==4)
                strcpy(game.matchbetween,"England");
            if(ck==5)
                strcpy(game.matchbetween,"Ireland");
            if(ck==6)
                strcpy(game.matchbetween,"New Zealand");
            if(ck==7)
                strcpy(game.matchbetween,"Pakistan");
            if(ck==8)
                strcpy(game.matchbetween,"South Africa");
            if(ck==9)
                strcpy(game.matchbetween,"Sri Lanka");
            if(ck==10)
                strcpy(game.matchbetween,"West Indies");
            if(ck==11)
                strcpy(game.matchbetween,"Zimbabwe");
        }
        system("cls");
        details(cunter);
    }
    else if(cunter==4)
    {

        gotoxy(59,6);
        for(int i=0; i<25; i++)
            printf("_");
        printf("\n");
        gotoxy(59,7);
        printf("| 1.   |  Bangladesh    |\n");
        gotoxy(59,8);
        printf("| 2.   |  India         |\n");
        gotoxy(59,9);
        printf("| 3.   |  Australia     |\n");
        gotoxy(59,10);
        printf("| 4.   |  England       |\n");
        gotoxy(59,11);
        printf("| 5.   |  Ireland       |\n");
        gotoxy(59,12);
        printf("| 6.   |  New Zealand   |\n");
        gotoxy(59,13);
        printf("| 7.   |  Pakistan      |\n");
        gotoxy(59,14);
        printf("| 8.   |  South Africa  |\n");
        gotoxy(59,15);
        printf("| 9.   |  Sri Lanka     |\n");
        gotoxy(59,16);
        printf("|10.   |  West Indies   |\n");
        gotoxy(59,17);
        printf("|11.   |  Zimbabwe      |\n");
        gotoxy(59,18);
        printf("|");
        for(int i=0; i<23; i++)
            printf("_");

        printf("|");

        gotoxy(53,11);
        int ck;
        scanf("%d",&ck);
        if(ck<=11&&ck>0)
        {
            d=0;

            if(ck==1)
                strcpy(game.versus,"Bangladesh");
            if(ck==2)
                strcpy(game.versus,"India");
            if(ck==3)
                strcpy(game.versus,"Australia");
            if(ck==4)
                strcpy(game.versus,"England");
            if(ck==5)
                strcpy(game.versus,"Ireland");
            if(ck==6)
                strcpy(game.versus,"New Zealand");
            if(ck==7)
                strcpy(game.versus,"Pakistan");
            if(ck==8)
                strcpy(game.versus,"South Africa");
            if(ck==9)
                strcpy(game.versus,"Sri Lanka");
            if(ck==10)
                strcpy(game.versus,"West Indies");
            if(ck==11)
                strcpy(game.versus,"Zimbabwe");
        }
        else
            d=-1,cunter--,game.versus[0]='\0';

        if(strcmp(game.matchbetween,game.versus)==0)
            d=-1,cunter--,game.versus[0]='\0';
        system("cls");
        details(cunter);
    }
    else if(cunter==5)
    {

        int ck=0;
        d=0;
        gotoxy(59,10);
        printf(" 1.  %12s \n",game.matchbetween);
        gotoxy(59,11);
        printf(" 2.  %12s \n",game.versus);
        gotoxy(59,12);
        printf(" 1/2 \n");
        gotoxy(45,12);
        scanf("%d",&ck);
        if(ck==1 )
        {
            strcpy(game.Batting_team_Name,game.matchbetween);
            strcpy(game.Bowling_team_Name,game.versus);
            strcpy(game.tosswonby,game.matchbetween);
        }
        else if(ck==2)
        {
            strcpy(game.Batting_team_Name,game.versus);
            strcpy(game.Bowling_team_Name,game.matchbetween);
            strcpy(game.tosswonby,game.versus);
        }
        else
            d=-1,cunter--,game.tosswonby[0]='\0';
        system("cls");
        details(cunter);
    }
    else if(cunter==6)
    {
        gotoxy(53,13);
        scanf("%d",&game.over);
        details(cunter);
        d=0;
        system("cls");
    }
    else
        system("pause");

}



void takedata_batsman()//save batsman
{
    char name[50];
    FILE *file,*f;//=fopen("bd.txt","r");

    if(strcmp(game.Batting_team_Name,"Bangladesh")==0)
    {
        file =fopen("bd.txt","r");
        f=fopen("bdskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"India")==0)
    {
        file =fopen("ind.txt","r");
        f=fopen("indskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Australia")==0)
    {
        file =fopen("australianame.txt","r");
        f=fopen("australiaskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"England")==0)
    {
        file =fopen("englandname.txt","r");
        f=fopen("englandskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Ireland")==0)
    {
        file =fopen("irelandname.txt","r");
        f=fopen("irelandskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"New Zealand")==0)
    {
        file =fopen("newzlandname.txt","r");
        f=fopen("newzlandskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Pakistan")==0)
    {
        file =fopen("pakistanname.txt","r");
        f=fopen("pakistanskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"South Africa")==0)
    {
        file =fopen("southafricaname.txt","r");
        f=fopen("southafricaskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Sri Lanka")==0)
    {
        file =fopen("srilankaname.txt","r");
        f=fopen("srilankaskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"West Indies")==0)
    {
        file =fopen("westindiesname.txt","r");
        f=fopen("westindiesskill.txt","r");
    }
    else if(strcmp(game.Batting_team_Name,"Zimbabwe")==0)
    {
        file =fopen("zimbabuwename.txt","r");
        f=fopen("zimbabuweskill.txt","r");
    }

    int line=1;

    while(fgets(name,50,file))
    {
        for(int i=0; i<strlen(name); i++)
        {
            if((name[i]>='a'&&name[i]<='z')||name[i]==' '||(name[i]>='A'&&name[i]<='Z'))
                Batsman[line].name[i]=name[i];
        }
        line++;
        if(line==12)
            break;
    }

    char skill[50];
    line=1;
    while(fgets(skill,50,f))
    {
        for(int i=0; i<strlen(skill); i++)
        {
            if((skill[i]>='a'&&skill[i]<='z')||skill[i]==' '||(skill[i]>='A'&&skill[i]<='Z'))
                Batsman[line].skill[i]=skill[i];
        }
        Batsman[line].run=0;
        Batsman[line].ball=0;
        Batsman[line].out=0;
        Batsman[line].four=0;
        Batsman[line].six=0;
        Batsman[line].totalball=0;
        Batsman[line].given_run=0;
        Batsman[line].wicket;
        Batsman[line].NB=0;
        Batsman[line].WD=0;
        Batsman[line].ECO=0;
        Batsman[line].maiden_over=0;
        line++;
        if(line==12)
            break;
    }

    fclose(file);
    fclose(f);
}

void takedata_bowler()// save bowlers
{
    char name[50];
    FILE *file,*f;

    if(strcmp(game.Bowling_team_Name,"Bangladesh")==0)
    {
        file =fopen("bd.txt","r");
        f=fopen("bdskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"India")==0)
    {
        file =fopen("ind.txt","r");
        f=fopen("indskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Australia")==0)
    {
        file =fopen("australianame.txt","r");
        f=fopen("australiaskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"England")==0)
    {
        file =fopen("englandname.txt","r");
        f=fopen("englandskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Ireland")==0)
    {
        file =fopen("irelandname.txt","r");
        f=fopen("irelandskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"New Zealand")==0)
    {
        file =fopen("newzlandname.txt","r");
        f=fopen("newzlandskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Pakistan")==0)
    {
        file =fopen("pakistanname.txt","r");
        f=fopen("pakistanskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"South Africa")==0)
    {
        file =fopen("southafricaname.txt","r");
        f=fopen("southafricaskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Sri Lanka")==0)
    {
        file =fopen("srilankaname.txt","r");
        f=fopen("srilankaskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"West Indies")==0)
    {
        file =fopen("westindiesname.txt","r");
        f=fopen("westindiesskill.txt","r");
    }
    else if(strcmp(game.Bowling_team_Name,"Zimbabwe")==0)
    {
        file =fopen("zimbabuwename.txt","r");
        f=fopen("zimbabuweskill.txt","r");
    }





    int line=1;
    while(fgets(name,50,file))
    {
        for(int i=0; i<strlen(name); i++)
        {
            if((name[i]>='a'&&name[i]<='z')||name[i]==' '||(name[i]>='A'&&name[i]<='Z'))
                Bowler[line].name[i]=name[i];
        }
        line++;
        if(line==12)
            break;
    }

    char skill[50];

    line=1;
    while(fgets(skill,50,f))
    {
        for(int i=0; i<strlen(skill); i++)
        {
            if((skill[i]>='a'&&skill[i]<='z')||skill[i]==' '||(skill[i]>='A'&&skill[i]<='Z'))
                Bowler[line].skill[i]=skill[i];
        }
        Bowler[line].run=0;
        Bowler[line].ball=0;
        Bowler[line].out=0;
        Bowler[line].four=0;
        Bowler[line].six=0;
        Bowler[line].totalball=0;
        Bowler[line].given_run=0;
        Bowler[line].wicket;
        Bowler[line].NB=0;
        Bowler[line].WD=0;
        Bowler[line].ECO=0;
        Bowler[line].maiden_over=0;
        line++;
        if(line==12)
            break;
    }
    fclose(file);
    fclose(f);
}


void showdata()//for output
{
    system("COLOR 06");
    printf("\n\n\n\t\t\t ________________________________________________________________\n");
    printf("\t\t\t||      Batsman Name         |   R   |   B  |  4  |  6  |   SR  ||\n");
    printf("\t\t\t| ---------------------------------------------------------------|\n");
    for( int i=1; i<=11; i++)
    {
        printf("\t\t\t|| ");
        if(Batsman[i].out==0)
            printf("*%2d .",i);
        else if(Batsman[i].out==1)
            printf("#%2d .",i);
        else
            printf("%3d .",i);
        printf("%20s",Batsman[i].name);

        printf(" |  %.3d  | %.3d  |",Batsman[i].run,Batsman[i].ball);
        if(Batsman[i].ball==0)
            Batsman[i].strick_rate=0;
        else
            Batsman[i].strick_rate=Batsman[i].run*10000/Batsman[i].ball;

        int tem= Batsman[i].strick_rate;
        printf(" %2d  | %2d  |",Batsman[i].four,Batsman[i].six);
        printf("%3d.%2d || \n", tem/100, tem%100);
    }
    printf("\t\t\t||______________________________________________________________||\n");
    printf("\t\t\t||                               Extra - %.2d          Total = %.2d ||\n",extra,total_run);
    printf("\t\t\t||______________________________________________________________||\n");
    if(bowler_used_total==0)
        return;
    printf("\t\t\t __________________________________________________________________________\n");
    printf("\t\t\t||     Bowlers Name        |  O  |   R  |  W  |  M  |  NB |  WD  |   ECO  ||\n");
    printf("\t\t\t||________________________________________________________________________||\n");

    for(int i=0; i<bowler_used_total; i++)
    {
        printf("\t\t\t|| %d .",i+1);
        printf("%20s",Bowler[bowler_used_no[i]].name);
        printf(" | %d.%d | %3d  | %2d  |  %d  | %2d  |  %3d | ",Bowler[bowler_used_no[i]].totalball/6,Bowler[bowler_used_no[i]].totalball%6,Bowler[bowler_used_no[i]].given_run,Bowler[bowler_used_no[i]].wicket,Bowler[bowler_used_no[i]].maiden_over,Bowler[bowler_used_no[i]].NB,Bowler[bowler_used_no[i]].WD);
        if(Bowler[bowler_used_no[i]].totalball==0)
        {
            Bowler[bowler_used_no[i]].ECO=0;
        }
        else
        {
            Bowler[bowler_used_no[i]].ECO=Bowler[bowler_used_no[i]].given_run*600/Bowler[bowler_used_no[i]].totalball;
        }
        int tem=Bowler[bowler_used_no[i]].ECO;
        printf("%2d.%2d  ||\n",tem/100,tem%100);
    }
    printf("\t\t\t||________________________________________________________________________||\n");
}

int checkbowler(int prev_bowler,int current_Bowler)//Check Bowler Validity
{
    if(prev_bowler!=current_Bowler)
    {
        if(Bowler[current_Bowler].totalball<game.Bowler_max_over)
            return i;
        else
            return -2;
    }
    return -1;
}

int checkbatsman(int non,int strick)// Check Batsman Validity
{
    if(Batsman[strick].out==0)
        return strick;
    else if(Batsman[strick].out==2)
        return -2;
    return -1;
}

void change()//End Of 1st innings
{
    char tempp[20];
    strcpy(tempp,game.Bowling_team_Name);
    strcpy(game.Bowling_team_Name,game.Batting_team_Name);
    strcpy(game.Batting_team_Name,tempp);

    for(i=1; i<=11; i++)
    {
        cng=Batsman[i];
        Batsman[i]=Bowler[i];
        Bowler[i]=cng;
    }
}

int main()
{
    while(1)
    {
        int x;
        system("color f1");
        system("cls");
        printf("\t\t\t_________________________________\n");
        printf("\t\t\t---------------------------------\n");
        printf("\t\t\t    ***ENTER YOUR CHOICE***    \n");
        printf("\t\t\t_________________________________\n");
        printf("\t\t\t---------------------------------\n");

        printf("\t\t\t|\t\t\t\t|\n");
        printf("\t\t\t|\tStart The Game  [1]\t|\n");
        printf("\t\t\t|\tExit            [2]\t|\n");
        printf("\t\t\t|\t\t\t\t|\n");
        printf("\t\t\t_________________________________\n");
        printf("\t\t\t---------------------------------\n\t\t\t");

        scanf("%d",&x);
        getchar();
        switch(x)
        {
        case 1:
            system("cls");
            start();
            break;
        case 2:
            printf("Thank you!!\n");
            return 0;

        default:
            printf("YOU ENTER WRONG CHICE!!!\n\nPlease enter any key to continue\n\n");

            getchar();
            break;
        }
    }

}

void start()//Starting Things
{
    int i,choice;

    system("color f1");
    system("cls");
    const char rocket[] ="          \n\
          \t\t\t/^\\\n\
          \t\t\t|-|\n\
          \t\t\t|W|\n\
          \t\t\t|E|\n\
          \t\t\t|L|\n\
          \t\t\t|C|\n\
        \t\t       /|O|\\\n\
       \t\t\t      / |M| \\\n\
      \t\t\t     /  |E|  \\\n\
     \t\t\t    /!!!!!!!!!\\\n\ \t\t\t   TO OUR PROJECT"
                         ;
    ;
    gotoxy(50,50);
    system("COLOR 04");
    printf("\t\t\t\t\t %s", rocket);
    int j = 300000;
    for ( i = 0; i <= 100; i ++)
    {
        if(i==1)
            system("COLOR 06");
        else if(i==2)
            system("COLOR 02");
        else if(i==3)
            system("COLOR 0D");
        else if(i==4)
            system("COLOR 00");
        else if(i==5)
            system("COLOR 06");
        else if(i==6)
            system("COLOR 09");

        else if(i==7)
            system("COLOR 0B");
        else if(i==8)
            system("COLOR 02");
        else if(i==9)
            system("COLOR 0C");
        else if(i==10)
            system("COLOR 0E");
        else if(i==11)
            system("COLOR 07");

        else if(i==12)
            system("COLOR 05");
        else if(i==13)
            system("COLOR 0E");
        else if(i==14)
            system("COLOR 04");
        else if(i==15)
            system("COLOR 0d");
        else if(i==16)
            system("COLOR 0B");

        else if(i==17)
            system("COLOR 0C");
        else if(i==18)
            system("COLOR 0A");
        else if(i==19)
            system("COLOR 0D");
        else if(i==20)
            system("COLOR 07");
        else if(i==21)
            system("COLOR 06");

        else if(i==22)
            system("COLOR 05");
        else if(i==23)
            system("COLOR 01");
        else if(i==24)
            system("COLOR 06");
        else if(i==25)
            system("COLOR 09");
        else if(i==26)
            system("COLOR 0E");

        else if(i==27)
            system("COLOR 02");
        else if(i==28)
            system("COLOR 0D");
        else if(i==29)
            system("COLOR 09");
        else if(i==30)
            system("COLOR 03");

        usleep(j); // move faster and faster,
        j = (int)(j * .8); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
    printf("                                                                                              ||Made by Cse-16 Mbstu||\n");
    getchar();
    game=GAME;
    instruction();
    details(1);
    choich(1);
    return;
}
void run(int Run)//Calculate Run
{
    if(Run!=0)
    {
        run_counter++;
    }


    Bowler[current_bowler_no].given_run+=Run ;
    Batsman[pl[0]].run+=Run;
    total_run+=Run;
    if(Run==4)
    {
        four();
        Batsman[pl[0]].four++;
    }
    if(Run==6)
    {
        six();
        Batsman[pl[0]].six++;
    }

    if(Batsman[pl[0]].run>=50&&Batsman[pl[0]].run-Run<50)//50
    {
        fifty(Batsman[pl[0]].name);//50
    }
    if(Batsman[pl[0]].run>=100&&Batsman[pl[0]].run-Run<100)//100
        hundred(Batsman[pl[0]].name);//100

    if(Run==1||Run==3||Run==5)//change batsman
    {
        flag = 0 ;
        X=pl[0];
        pl[0]=pl[1];
        pl[1]=X;

    }
}
int out(int innings)
{
    Out();
    wicket++;
    Batsman[pl[0]].out=2;
    Bowler[current_bowler_no].wicket++ ;
    cunt++;
    system("cls");
    showdata();
    if(cunt>=10)
    {
        printf("\n\nAll players out!!\n\n");
        if(innings==2)
        {
            if(total_run<target)
            {
//                printf("%15s team Won By %d Run .....\n",game.Bowling_team_Name,target-total_run-1);
//                system("pause");
                return -3;
            }
        }
        else
            return -10;
    }
    while(1)
    {
        printf("\t\t\tEnter Batsman Number : ");
        scanf("%d",&pl[0]);

        if( checkbatsman(pl[1],pl[0])==-1)
        {
            printf("\t\t\tInvalid Name.\n");
        }
        else if( checkbatsman(pl[1],pl[0])==-2)
        {
            printf("\t\t\tAlready Out !!! \n");
        }
        else
        {
            break;
        }
    }
    Batsman[pl[0]].out=1;
    getchar();
}

void Wide(int run)
{
    wide++;
    Ball--;
    run_counter++;
    Bowler[current_bowler_no].WD++;


    extra+=run+1;
    total_run+=run+1;
    Bowler[current_bowler_no].given_run+=run+1;
    Bowler[current_bowler_no].WD+=run;
    if(run==1||run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }

}
void Noball(int run)
{
    run_counter++;
    noball++;
    Ball--;
    Bowler[current_bowler_no].NB++;
    Bowler[current_bowler_no].given_run+=run+1;

    extra++;
    total_run+=run+1;
    Batsman[pl[0]].run+=run;
    if(run==1||run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }
    if(run==4)
    {
        Batsman[pl[0]].four++;
        four();
    }
    if(run==6)
    {
        Batsman[pl[0]].six++;
        six();
    }
}
void leg_bye(int Run)
{
    run_counter++;
    lb+=Run;
    extra+=Run;
    total_run+=Run;
    if(Run==1||Run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }
    // freehit=0;
}

void bye(int Run)
{
    extra+=Run;
    total_run+=Run;
    if(Run==1||Run==3)
    {
        int temporary=pl[0];
        pl[0]=pl[1];
        pl[1]=temporary;
    }
    //freehit=0;
}

int choich( int innings)//innings 1/2
{
    game.Bowler_max_over=game.over*6/5;
    temp = 0 ;
    total_run=0;
    flag = 0 ;
    run_counter   = 0 ;
    wide     = 0 ;
    noball     = 0 ;
    lb=0;
    wide_flag         = 0 ;
    current_bowler_no=-1;
    current_batsman_no=-1;
    wicket=0;
    extra=0;
    bowler_used_total=0;
    freehit=0;

    cunt=0;
    if(innings==1)//batsman&&bowler skill
    {
        initialize();
        takedata_batsman();
        takedata_bowler();
        strcpy(team1,game.Batting_team_Name);
        strcpy(team2,game.Bowling_team_Name);
        system("cls");
        system("COLOR 0B");
        printf("\n\n\t\t ______________________________________________________________________________________\n");
        printf("\t\t||         %15s                 ||          %15s                ||\n",game.Batting_team_Name,game.Bowling_team_Name);
        printf("\t\t||____________________________________________________________________________________||\n");
        printf("\t\t||          Name         |    Skill        ||          Name         |       Skill     ||\n");
        printf("\t\t||____________________________________________________________________________________||\n");
        for(i=1; i<=11; i++)
        {
            printf("\t\t||  %20s |  %14s || %20s  |  %14s ||\n",Batsman[i].name,Batsman[i].skill,Bowler[i].name,Bowler[i].skill);
        }
        printf("\t\t||____________________________________________________________________________________||\n");
        system("pause");
        system("cls");
    }

    pl[0]=-1;
    pl[1]=-1;
    while(1)//1st Batsman
    {
        system("cls");
        showdata();
        printf("\t\t\t Enter Batsman Number : ");
        scanf("%d",&pl[0]);
        if( checkbatsman(0,pl[0])==-1)
        {
            printf("Invalid Name.\n");
        }
        else if( checkbatsman(0,pl[0])==-2)
            printf("Already Out !!! \n");
        else
        {
            break;
        }
    }
    Batsman[pl[0]].out=1;
    while(1)//2nd Batsman
    {
        system("cls");
        showdata();
        printf("\t\t\t Enter Batsman Number : ");
        scanf("%d",&pl[1]);
        if( checkbatsman(pl[0],pl[1])==-1)
        {
            printf("Invalid Player.\n");
        }
        else if( checkbatsman(pl[0],pl[1])==-2)
            printf("Already Out !!! \n");
        else
        {
            break;
        }
    }
    Batsman[pl[1]].out=1;
    current_batsman_no=pl[0];

    while(1)//Bowler
    {
        system("cls");
        int tem[10],j,bowlerr;
        printf("\n\n\n\t\t\t\t ___________________________\n");
        printf("\t\t\t\t|        Bowler list        |\n");
        printf("\t\t\t\t|---------------------------|\n");
        for(i=1, j=1; i<=11; i++)
        {
            if(i==current_bowler_no)
                continue;
            if(strcmp(Bowler[i].skill,"Bowler")==0||strcmp(Bowler[i].skill,"All Rounder")==0)
            {
                tem[j]=i;
                printf("\t\t\t\t|%d . %20s   |\n",j,Bowler[i].name);
                j++;
            }
        }
        printf("\t\t\t\t|___________________________|\n");
        printf("\t\t\t\t Enter Bowlers Number : ");
        int prev_bowler=current_bowler_no;
        scanf("%d",&bowlerr);
        if(checkbowler(prev_bowler,tem[bowlerr])==-1)
        {
            printf("Invalid Name.\n");
        }
        else
        {
            current_bowler_no=tem[bowlerr];
            break;
        }

    }
    bowler_used_no[bowler_used_total]=current_bowler_no;
    bowler_used_total++;
    getchar();

    for(Ball=0, i = 0 ; Ball<game.over*6; Ball++)//total ball
    {
        if(Ball%6==0 && Ball!=0 && wide_flag==0)//over
        {
            X=pl[0];
            pl[0]=pl[1];
            pl[1]=X;
            if(run_counter   == 0 )
                Bowler[current_bowler_no].maiden_over++;

            run_counter         = 0 ;
            i++;
            system("cls");
            int check=0;
            while(1)//bowler list
            {
                int tem[10],j,bowlerr=0,cunter=0;
                system("cls");
                printf("\n\n\n\t\t\t____________________________\n");
                printf("\t\t\t|       Bowler list        |\n");
                printf("\t\t\t----------------------------\n");
                for(i=1, j=1; i<=11; i++)
                {
                    if(i==current_bowler_no)
                        continue;
                    if(strcmp(Bowler[i].skill,"Bowler")==0||strcmp(Bowler[i].skill,"All Rounder")==0)
                    {
                        tem[j]=i;
                        printf("\t\t\t|%d . %20s  |\n",j,Bowler[i].name);
                        j++;
                        cunter++;
                    }
                }
                printf("\t\t\t|__________________________|\n");

                if(check==-1)
                {
                    printf("\t\t\tInvalid Name.\n");
                }
                else if(check==-2)
                {
                    printf("\t\t\tOver Finished Already\n");
                }

                printf("\t\t\tBowlers Number : ");
                int prev_bowler=current_bowler_no;
                char bwlr[20];
                gets(bwlr);
                for(int z=0;z<strlen(bwlr);z++)
                    bowlerr=bowlerr*10+bwlr[z]-48;

                if(bowlerr<1||bowlerr>cunter)
                    check=-1;
                else
                {
                    check=checkbowler(prev_bowler,tem[bowlerr]);
                }
                if(check!=-1&&check!=-2)
                {
                    current_bowler_no=tem[bowlerr];
                    break;
                }

            }
            if(Bowler[current_bowler_no].totalball==0)
            {
                bowler_used_no[bowler_used_total]=current_bowler_no;
                bowler_used_total++;
            }
        }
        system("cls");

        printf("_____________________________________________________________\n");
        printf("|  %c%c%c %d/%d  (%d.%d)  Extra - %.2d ",game.Batting_team_Name[0],game.Batting_team_Name[1],game.Batting_team_Name[2],total_run,cunt,Ball/6,Ball%6,extra);
        if(innings==1)
        {
            int run_rate=0;
            if(Ball!=0)
            {
                run_rate=total_run*600/Ball;
            }
            printf(" RR - %.2d.%.2d                    \n",run_rate/100,run_rate%100);
            printf("|  %c%c%c                                                       |\n",team2[0],team2[1],team2[2]);
            printf("|                                                            |\n");
        }
        else
        {
            printf("Target - %3d                   \n",target);
            printf("|  %c%c%c %3d/%d(%2d.%d) RR-%3d.%2d                                 \n",team1[0],team1[1],team1[2],innings1run,innings1wicket,innings1ball/6,innings1ball%6,innings1runrate/100,innings1runrate%100 );
            printf("|                                                            |\n");
            printf("|  Need %.2d Run in %.2d Ball                                    |\n",target-total_run,game.over*6-Ball);
        }
        printf("|______________________________________________________      |\n");
        printf("|  Batsman                   |   R   B   4   6     SR  |     |\n");
        printf("|____________________________|_________________________|     |\n");
        printf("| *%s ",Batsman[pl[0]].name);
        int sz=strlen(Batsman[pl[0]].name);
        for(int k=0; k<25-sz; k++)
            printf(" ");
        printf("| %3d %3d  %2d  %2d ",Batsman[pl[0]].run,Batsman[pl[0]].ball,Batsman[pl[0]].four,Batsman[pl[0]].six);
        int strikerate1;
        if(Batsman[pl[0]].ball==0)
            strikerate1=0;
        else
            strikerate1=Batsman[pl[0]].run*10000/Batsman[pl[0]].ball;
        printf(" %3d.%2d |     |\n", strikerate1/100, strikerate1%100);




        printf("|  %s ",Batsman[pl[1]].name);
        int szz=strlen(Batsman[pl[1]].name);
        for(int k=0; k<25-szz; k++)
            printf(" ");
        printf("| %3d %3d  %2d  %2d ",Batsman[pl[1]].run,Batsman[pl[1]].ball,Batsman[pl[1]].four,Batsman[pl[1]].six);
        int strikerate2;
        if(Batsman[pl[1]].ball==0)
            strikerate2=0;
        else
            strikerate2=Batsman[pl[1]].run*10000/Batsman[pl[1]].ball;
        printf(" %3d.%2d |     |\n", strikerate2/100, strikerate2%100);


        printf("|____________________________|_________________________|     |\n");
        printf("|___________________________________________________________ |\n");
        printf("|  Bowler                    |   O   R   W   NB  WD   ECO  | |\n");
        printf("|____________________________|_____________________________| |\n");
        printf("|  %s",Bowler[current_bowler_no].name);
        int sze=strlen(Bowler[current_bowler_no].name);
        for(int k=0; k<25-sze; k++)
            printf(" ");
        printf(" | %d.%d %3d  %2d  %2d  %3d ",Bowler[current_bowler_no].totalball/6,Bowler[current_bowler_no].totalball%6,Bowler[current_bowler_no].given_run,Bowler[current_bowler_no].wicket,Bowler[current_bowler_no].NB,Bowler[current_bowler_no].WD);
        if(Bowler[current_bowler_no].totalball==0)
        {
            Bowler[current_bowler_no].ECO=0;
        }
        else
        {
            Bowler[current_bowler_no].ECO=Bowler[current_bowler_no].given_run*600/Bowler[current_bowler_no].totalball;
        }
        int tem=Bowler[current_bowler_no].ECO;
        printf("%3d.%2d | |\n",tem/100,tem%100);
        printf("|____________________________|_____________________________| |\n");
        if(innings==2)
        {
            if(total_run>=target)
            {
                printf("%15s Won by %d Wicket .....\n",game.Batting_team_Name,10-cunt);
                system("pause");
                return 0;
            }
        }
        printf("|");
        for(i=0; i<60; i++)
            printf("_");
        printf("|\n");

        gotoxy(61,1);
        printf("|");
        gotoxy(61,2);
        printf("|");
        gotoxy(1,16);
        wide_flag=1;
        char ran[10];
        int Run=-1;
        int invalid=0;
        while(1)
        {
            if(freehit==1)
                printf("\nFree Hit\n");
            if(invalid==-1)
            {
                printf("\nInvalid Run !!!\n");
            }
            printf("\nEnter the Run: ");

            gets(ran);
            if(ran[0]=='s')//Scoreboard
            {
                system("cls");
                showdata();
                system("pause");
                Run=-2;
                Ball--;
            }
            else if(ran[0]>='0'&&ran[0]<='7'&&strlen(ran)==1)//Run
            {
                Batsman[pl[0]].ball++;
                Bowler[current_bowler_no].totalball++;
                freehit=0;
                wide_flag=0;
                Run=ran[0]-48;
                run(Run);
            }
            else if(ran[0]=='w'&&strlen(ran)==1)//wicket
            {
                printf(" ______________\n");
                printf("|    WICKET    |\n");
                printf("|--------------|\n");
                printf("| 1. Bowled    |\n");
                printf("| 2. Catch     |\n");
                printf("| 3. Run out   |\n");
                printf("| 4. Stamping  |\n");
                printf("| 5. LBW       |\n");
                printf("| 6. Baimani   |\n");
                printf("----------------\n");
                printf("Enter Your Choice : ");
                int w;
                while( scanf("%d",&w))
                {

                    if(w==1||w==2||w==4||w==5)
                    {
                        Batsman[pl[0]].ball++;
                        Bowler[current_bowler_no].totalball++;
                        int check=0;
                        if(freehit==0)
                        {
                            check=out(innings);
                            wide_flag=0;
                        }
                        if(check==-3)
                            Run=-3;
                        if(check==-10)
                            Run=-10;
                        Run=0;
                        freehit=0;
                    }
                    else if(w==3)
                    {
                        printf("Enter Run : ");
                        scanf("%d",&Run);
                        Batsman[pl[0]].ball++;
                        Bowler[current_bowler_no].totalball++;
                        freehit=0;
                        run(Run);
                        out(innings);
                        wide_flag=0;
                    }
                    else if(w==6)
                    {
                        Batsman[pl[0]].ball++;
                        Bowler[current_bowler_no].totalball++;
                        freehit=0;
                        int tem=pl[0];
                        pl[0]=pl[1];
                        pl[1]=tem;
                        out(innings);
                        tem=pl[0];
                        pl[0]=pl[1];
                        pl[1]=tem;
                        wide_flag=0;
                        Run=0;
                    }
                    if(w>0&&w<7)
                        break;
                    else
                        printf("INvalid Wicket\nEnter Your Choice : ");
                }
            }
            else if(ran[0]=='w'&&ran[1]=='d')//wide
            {
                if(strlen(ran)==2)
                {
                    Wide(0);
                    Run=0;
                }
                else if(strlen(ran)==3)
                {
                    if(ran[2]>'0'&&ran[2]<'5')
                    {
                        Run=ran[2]-48;
                        Wide(Run);
                    }
                }
                else if(ran[2]=='r'&&ran[3]=='o')//runout
                {
                    if(strlen(ran)==5&&ran[4]>='0'&&ran[4]<'4')
                    {
                        Run=ran[4]-48;
                        Wide(Run);
                        out(innings);
                        Bowler[current_bowler_no].wicket--;
                    }
                }
            }

            else if(ran[0]=='n'&&ran[1]=='b')//noball
            {
                if(strlen(ran)==2)
                {
                    Run=0,Noball(0);
                    Batsman[pl[0]].ball++;
                    freehit=1;
                }
                else if(strlen(ran)==3&&ran[2]=='w')
                {
                    Run=0,Noball(0);
                    Batsman[pl[0]].ball++;
                    freehit=1;
                }
                else if(strlen(ran)==3&&ran[2]>'0'&&ran[2]<'7')
                {
                    Batsman[pl[0]].ball++;
                    Run=ran[2]-48;
                    Noball(Run);
                    freehit=1;
                }
                else if(ran[2]=='r'&&ran[3]=='o')
                {
                    if(strlen(ran)==5&&ran[4]>='0'&&ran[4]<'4')
                    {
                        Batsman[pl[0]].ball++;
                        Run=ran[4]-48;
                        Noball(Run);
                        out(innings);
                        freehit=1;
                    }
                }
                else if(ran[2]=='l'&&ran[3]=='b')
                {
                    if(strlen(ran)==5&&ran[4]>'0'&&ran[4]<'4')
                    {
                        Batsman[pl[0]].ball++;
                        Run=ran[4]-48;
                        Noball(0);
                        leg_bye(Run);
                        freehit=1;
                    }
                }
                else if(ran[2]=='b')
                {
                    if(strlen(ran)==4&&ran[3]>'0'&&ran[3]<'4')
                    {
                        Batsman[pl[0]].ball++;
                        Run=ran[3]-48;
                        Noball(0);
                        bye(Run);
                        freehit=1;
                    }
                }
            }
            else if(ran[0]=='l'&&ran[1]=='b')//leg bye
            {
                if(ran[2]>'0'&&ran[2]<'5')
                {
                    Batsman[pl[0]].ball++;
                    Bowler[current_bowler_no].totalball++;
                    freehit=0;
                    Run=ran[2]-48;
                    leg_bye(Run);
                    wide_flag=0;
                }
            }
            else if(ran[0]=='b'&&strlen(ran)==2)//by
            {
                if(ran[1]>'0'&&ran[1]<'5')
                {
                    Batsman[pl[0]].ball++;
                    Bowler[current_bowler_no].totalball++;
                    freehit=0;
                    wide_flag=0;
                    Run=ran[1]-48;
                    bye(Run);
                }
            }

            if(Run==-1)
            {
                invalid=-1;
            }
            else
            {
                break;
            }
        }



        if(wicket>=10)
            break;
        if(innings==2)
        {
            if(total_run>target)
            {
                break;
            }
        }
    }
    if(run_counter   == 0 )
        Bowler[current_bowler_no].maiden_over++;

    system("cls");
    system("COLOR 0B");
    showdata();
    int run_rate=0;
    run_rate=total_run*600/(game.over*6);
    if(innings==1)
    {
        innings1run=total_run;
        innings1ball=Ball;
        innings1runrate=run_rate;
        innings1wicket=wicket;
        target=total_run+1;
        printf("\t\t\t\t\t\t\t\t\t Target : %d\n",target);
        system("pause");
        system("cls");
        change();
        innings++;
        choich(innings);
    }
    else
    {
        system("cls");
        showdata();
        if(total_run<target-1)
            printf("%15s team Won By %d Runs .....\n",game.Bowling_team_Name,target-total_run-1);
        else if(total_run==target-1)
        {
            printf("Match Draw !!\n");
            int j=300000;
            for(i=0; i<50; i++)
            {
                usleep(j); // move faster and faster,
                j = (int)(j * .8);
            }
        }
        else
        {
            printf("%15s Won by %d Wicket .....\n",game.Batting_team_Name,10-cunt);
        }
        system("pause");
        game=GAME;
        return 0;
    }
}

