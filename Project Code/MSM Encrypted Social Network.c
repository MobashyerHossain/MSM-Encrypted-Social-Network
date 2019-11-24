//MSM Encrypted Social Network

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct info;

void msm();

void encrypt(char c[]);

void encrypt2(char c[]);

void decrypt(char c[]);

void decrypt2(char c[]);

void decrypt3(char c[]);

void signup();

void homepage(char u[]);

void profiletab(char u[]);

int usercheck(char u[]);

int passcheck(char u[], char p[]);

int gendercheck(char u[]);

void messageboard();

void messagename(char u[]);

void messagewrite();

void pmessageread(char u[]);

void pmessagename(char u[], char k[]);

void pmessagewrite(char u[]);

void messagetab(char u[]);

void pmessagetab(char u[]);

void findfriend(char j[]);

int tab();

int main()
{
    int s=0, t=0, n, k, x=0;
    char u[20], p[20], j[20], f[20], c[5];

    while(1)
    {
        msm();

        if((s!=0)||(t!=0))
        {
            printf("\t\t\t\tWrong Password or User Name. Try Again!!!");
        }

        s=0;
        t=0;

        printf("\n\n\n");
        printf("\t\t\t\t\tInput 'New' to Sign Up\n\n");

        printf("\t\t\t\t\tUser Name   : ");
        scanf("%s", u);
        strupr(u);

        if(strcmp(u,"NEW")==0)
        {
            msm();
            signup();
            continue;
        }

        else
        {
            encrypt(u);
        }

        printf("\t\t\t\t\tPassword    : ");
        scanf("%s", p);

        s=passcheck(u, p);
        t=usercheck(u);

        if((s!=0)||(t!=0))
        {
            continue;
        }

        else
        {
            for(k=0;k<2000;k++)
            {
                msm();

                if((k==0)||(x==0))
                {
                    msm();

                    homepage(u);
                    x=tab();
                }

                if(x==1)
                {
                    msm();

                    printf("Profile\n");
                    printf("-------\n\n");

                    profiletab(u);

                    x=tab();
                    continue;
                }

                else if(x==2)
                {
                    msm();

                    printf("Message Room\n");
                    printf("------------\n\n");

                    messagetab(u);

                    x=tab();
                    continue;
                }

                else if(x==3)
                {
                    msm();

                    printf("Notifications\n");
                    printf("-------------\n\n");

                    pmessageread(u);

                    printf("\nWant to Reply (Yes or No) : ");
                    scanf("%s", c);

                    if((strcmpi(c,"yes"))==0)
                    {
                        msm();

                        printf("Message\n");
                        printf("-------\n\n");

                        pmessagetab(u);

                        x=tab();
                        continue;
                    }

                    else
                    {
                        msm();

                        homepage(u);
                        x=tab();
                        continue;
                    }
                }

                else if(x==4)
                {
                    msm();

                    printf("Message\n");
                    printf("-------\n\n");

                    pmessagetab(u);

                    x=tab();
                    continue;
                }

                else if(x==5)
                {
                    msm();

                    printf("Friend Finder\n");
                    printf("-------------\n\n");

                    printf("User Name of Friend : ");
                    scanf("%s", j);

                    strupr(j);
                    encrypt(j);

                    findfriend(j);

                    x=tab();
                    continue;
                }

                else if(x==6)
                {
                    break;
                }

            }

        }

    }

    return 0;
}


struct
    {
        char fname[30];
        char lname[30];
        char uname[30];
        char pass[20];
        char pass2[20];
        char email[50];
        char gender[10];
        char mobi[15];
        char dob[3][5];
        char data[8][17];
    } info;

void msm()
{
    system("cls");
    printf("\t\t\t<<<<<<<<<<<<<<<    Encrypted MSM Social Network    >>>>>>>>>>>>>>>\t\t\t\n");

    printf("\t\t\t\t\t   ----------------------------   \t\t\t\t\t\n\n");
}

void encrypt(char c[])
{
    int i, q;

    for(i=0;i<strlen(c);i++)
    {
        q=(int)c[i];
        q=q+39;
        c[i]=q;
    }
}

void encrypt2(char c[])
{
    int i, q;

    for(i=0;c[i]!='\0';i++)
    {
        q=(int)c[i];
        q=q+39;
        c[i]=q;
    }
}

void decrypt(char c[])
{
    int i, q;

    for(i=0;i<strlen(c)-1;i++)
    {
        q=(int)c[i];
        q=q-39;
        c[i]=q;
    }
}

void decrypt2(char c[])
{
    int i, q;

    for(i=0;i<strlen(c);i++)
    {
        q=(int)c[i];
        q=q-39;
        c[i]=q;
    }
}

void decrypt3(char c[])
{
    int i, q;

    for(i=0;c[i]!='\0';i++)
    {
        q=(int)c[i];
        q=q-39;
        c[i]=q;
    }
}

void signup()
{
    int i, j, s;
    char f[100];
    FILE *fp;

    printf("\n\n");
    printf("\t\t\t\tFirst name (Ex. Adam)           : ");
    scanf("%s", info.fname);
    encrypt(info.fname);

    printf("\t\t\t\tLast name (Ex. Smith)           : ");
    scanf("%s", info.lname);
    encrypt(info.lname);

    printf("\t\t\t\tUser Name (Must be Unique)      : ");
    scanf("%s", info.uname);
    strupr(info.uname);
    encrypt(info.uname);

    strcpy(f,"Data\\IDS\\");
    strcat(f,info.uname);
    strcat(f,".txt");

    printf("\t\t\t\tPassword (6-18Characters)       : ");
    scanf("%s", info.pass);

    for(j=0;j<20;j++)
    {
        s=strlen(info.pass);
        if(s<=5)
        {
            printf("\n\t\t\tYour Password Contains Less Than 6 Characters. Try again!!!\n");
            printf("\t\t\t\tPassword (In (6-18) Characters) : ");
            scanf("%s", info.pass);
        }

        else if(s>=19)
        {
            printf("\n\t\t\tYour Password Contains More Than 18 Characters. Try again!!!\n");
            printf("\t\t\t\tPassword (In (6-18) Characters) : ");
            scanf("%s", info.pass);
        }

        else
        {
            break;
        }
    }

    for(j=0;j<20;j++)
    {
        if(j!=0)
        {
            printf("\n\t\t\tYou Have Entered a Different Password. Try again!!!\n");
        }

        printf("\t\t\t\tRe Enter Password               : ");
        scanf("%s", info.pass2);
        if((strcmp(info.pass2,info.pass))==0)
        {
            encrypt(info.pass);
            break;
        }
        else
        {
            continue;
        }
    }

    printf("\t\t\t\tEmail (Ex. apple678@yahoo.com)  : ");
    scanf("%s", info.email);
    encrypt(info.email);

    printf("\t\t\t\tGender (Ex. Male or Female)     : ");
    scanf("%s", info.gender);
    encrypt(info.gender);

    printf("\t\t\t\tMobile Number (Ex. 01967543845) : ");
    scanf("%s", info.mobi);
    encrypt(info.mobi);

    printf("\t\t\t\tDate of Birth (Ex. 23 Jun 1987) : ");
    scanf("%s", info.dob[0]);
    encrypt(info.dob[0]);
    strrev(info.dob[0]);

    scanf("%s", info.dob[1]);
    encrypt(info.dob[1]);
    strrev(info.dob[1]);

    scanf("%s", info.dob[2]);
    encrypt(info.dob[2]);
    strrev(info.dob[2]);

    strcpy(info.data[0],"First Name    : ");
    encrypt(info.data[0]);

    strcpy(info.data[1],"Last Name     : ");
    encrypt(info.data[1]);

    strcpy(info.data[2],"User Name     : ");
    encrypt(info.data[2]);

    strcpy(info.data[3],"Password      : ");
    encrypt(info.data[3]);

    strcpy(info.data[4],"Email         : ");
    encrypt(info.data[4]);

    strcpy(info.data[5],"Gender        : ");
    encrypt(info.data[5]);

    strcpy(info.data[6],"Mobile No.    : ");
    encrypt(info.data[6]);

    strcpy(info.data[7],"Date of Birth : ");
    encrypt(info.data[7]);

    fp=fopen(f, "w");

    fputs(info.data[0],fp);
    fputs(info.fname,fp);
    putc('\n',fp);

    fputs(info.data[1],fp);
    fputs(info.lname,fp);
    putc('\n',fp);

    fputs(info.data[2],fp);
    fputs(info.uname,fp);
    putc('\n',fp);

    fputs(info.data[3],fp);
    fputs(info.pass,fp);
    putc('\n',fp);

    fputs(info.data[4],fp);
    fputs(info.email,fp);
    putc('\n',fp);

    fputs(info.data[5],fp);
    fputs(info.gender,fp);
    putc('\n',fp);

    fputs(info.data[6],fp);
    fputs(info.mobi,fp);
    putc('\n',fp);

    fputs(info.data[7],fp);
    fputs(info.dob[0],fp);
    fputs(info.dob[1],fp);
    fputs(info.dob[2],fp);
    putc('\n',fp);

    fputs("š Œ™“š Œ™“GGGGGGGGGaG‘–’Œjš Œ™“š Œ™“",fp);
    putc('\n',fp);
    fputs("™“š Œ™“GGGGGGGGGaG‘–’Œjš “š Œ™“",fp);
    putc('\n',fp);
    fputs("š Œ™š Œ™“GGGGGGGGGaG‘™“Œ™“",fp);
    putc('\n',fp);
    fputs("š Œ™“š ŒŒ™“GGGGGGGGGaG‘™“Œ™“",fp);
    putc('\n',fp);
    fputs("š Œš Œ™“GGGGGGGGGaG‘™“Œ™“š Œ™“",fp);


    fclose(fp);
}

void homepage(char u[])
{
    int i, k;
    char f[100], c[50], n1[30], n2[30];
    FILE *fq;

    printf("Home\n");
    printf("----\n\n");

    k=gendercheck(u);

    strcpy(f,"Data\\IDS\\");
    strcat(f,u);
    strcat(f,".txt");

    if(k==1)
    {
        printf("Welcome Back!!\n\t\tMr. ");
    }
    else if(k==2)
    {
        printf("Welcome Back!!\n\t\tMs. ");
    }
    else
    {
        printf("Welcome Back!!\n\t\tMr./Ms. ");
    }

    fq = fopen(f, "r");

    //First Name
    fgets(c, 17, (FILE*)fq);
    fgets(n1, 30, (FILE*)fq);
    decrypt(n1);

    //Last Name
    fgets(c, 17, (FILE*)fq);
    fgets(n2, 30, (FILE*)fq);
    decrypt(n2);

    strrev(n1);
    strrev(n2);
    strnset(n1,' ',1);
    strnset(n2,',',1);
    strrev(n1);
    strrev(n2);

    printf("%s %s\n", n2, n1 );

    fclose(fq);
}

void profiletab(char u[])
{
    int i, r;
    char f[100], c[50], k[2][20], n[2][30];
    FILE *fq;

    r=gendercheck(u);

    strcpy(f,"Data\\IDS\\");
    strcat(f,u);
    strcat(f,".txt");

    if(r==1)
    {
        printf("\t\tMr. ");
    }
    else if(r==2)
    {
        printf("\t\tMs. ");
    }
    else
    {
        printf("\t\tMr./Ms. ");
    }

    fq = fopen(f, "r");

    //First Name
    fgets(k[0], 17, (FILE*)fq);
    decrypt2(k[0]);
    fgets(n[0], 30, (FILE*)fq);
    decrypt(n[0]);

    //Last Name
    fgets(k[1], 17, (FILE*)fq);
    decrypt2(k[1]);
    fgets(n[1], 30, (FILE*)fq);
    decrypt(n[1]);

    strrev(n[0]);
    strrev(n[1]);
    strnset(n[0],' ',1);
    strnset(n[1],',',1);
    strrev(n[0]);
    strrev(n[1]);

    printf("%s %s\n\n", n[1], n[0]);
    printf("%s%s\n",k[0], n[0]);

    strrev(n[1]);
    strnset(n[1],' ',1);
    strrev(n[1]);

    printf("%s%s\n",k[1], n[1]);

    //User Name
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );

    //Password
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );



    //Email
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );

    //Gender
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );

     //Mobile No.
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );

    //Date of Birth
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 3, (FILE*)fq);
    strrev(c);
    decrypt3(c);
    printf("%s\t", c );
    fgets(c, 4, (FILE*)fq);
    strrev(c);
    decrypt3(c);
    printf("%s\t", c );
    fgets(c, 5, (FILE*)fq);
    strrev(c);
    decrypt3(c);
    printf("%s", c );

    printf("\n");

    fclose(fq);
}

int usercheck(char u[])
{
    int i, k=0;
    char f[100], c[50];
    FILE *fq;

    strcpy(f,"Data\\IDS\\");
    strcat(f,u);
    strcat(f,".txt");

    if((fq = fopen(f, "r"))==NULL)
    {
        k=1;
    }

    fclose(fq);

    return k;
}

int passcheck(char u[], char p[])
{
    int i, k=0;
    char f[100], c[50];
    FILE *fq;
    k=0;

    strcpy(f,"Data\\IDS\\");
    strcat(f,u);
    strcat(f,".txt");

    fq = fopen(f, "r");

    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);
    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);
    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);

    //Password
    fgets(c, 17, (FILE*)fq);
    fgets(c, 20, (FILE*)fq);
    decrypt(c);
    strcat(p,"\n");

    if(strcmp(c,p)!=0)
    {
        k=1;
    }

    fclose(fq);

    return k;
}

int gendercheck(char u[])
{
    int i, k=0;
    char f[100], c[50];
    FILE *fq;

    strcpy(f,"Data\\IDS\\");
    strcat(f,u);
    strcat(f,".txt");

    fq = fopen(f, "r");

    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);
    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);
    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);
    fgets(c, 17, (FILE*)fq);
    fgets(c, 20, (FILE*)fq);
    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);
    fgets(c, 17, (FILE*)fq);
    fgets(c, 10, (FILE*)fq);
    decrypt(c);

    if(strcmpi(c,"Male\n")==0)
    {
        k=1;
    }
    else if(strcmpi(c,"Female\n")==0)
    {
        k=2;
    }
    else
    {
        k=0;
    }

    fclose(fq);

    return k;
}

void messageboard()
{
    char e;
    FILE *fr;

    if((fr=fopen("Data\\MSG\\Board.txt", "r"))==NULL)
    {
        fr=fopen("Data\\MSG\\Board.txt", "w");
    }

    while((e=fgetc(fr))!=EOF)
    {
        printf("%c", e);
    }

    fclose(fr);
}

void messagename(char u[])
{
    int j=0;
    char e='a', f[100], c1[50], c2[50];
    FILE *fq;

    strcpy(f,"Data\\IDS\\");
    strcat(f,u);
    strcat(f,".txt");

    fq = fopen(f, "r");

    //First Name
    fgets(c1, 17, (FILE*)fq);
    fgets(c1, 22, (FILE*)fq);
    decrypt(c1);
    //Last Name
    fgets(c2, 17, (FILE*)fq);
    fgets(c2, 22, (FILE*)fq);
    decrypt(c2);

    strrev(c1);
    strrev(c2);
    strnset(c1,' ',1);
    strnset(c2,' ',1);
    strrev(c1);
    strrev(c2);
    strcat(c1,c2);

    fclose(fq);

    strrev(c1);
    strcat(c1, " #");
    strrev(c1);

    FILE *fr;

    if((fr=fopen("Data\\MSG\\Board.txt", "a"))==NULL)
    {
        fr=fopen("Data\\MSG\\Board.txt", "w");
    }

    fputc('\n', fr);
    fputs(c1, fr);

    fclose(fr);
}

void messagewrite()
{
    int j=0;
    char e;
    FILE *fr;

    if((fr=fopen("Data\\MSG\\Board.txt", "a"))==NULL)
    {
        fr=fopen("Data\\MSG\\Board.txt", "w");
    }

    while((e=getchar())!='*')
    {
        fputc(e, fr);
    }

    fputc('\n', fr);

    fclose(fr);
}

void pmessageread(char u[])
{
    char e, f[100];
    FILE *fr;

    strcpy(f,"Data\\MSG\\");
    strcat(f,u);
    strcat(f,".txt");

    if((fr=fopen(f, "r"))==NULL)
    {
        printf("\t\tNo Notifications.");
    }

    else
    {
        while((e=fgetc(fr))!=EOF)
        {
            printf("%c", e);
        }
    }

    fclose(fr);
}

void pmessagename(char u[], char k[])
{

    int j=0;
    char e='a', f[100], g[100], c1[50], c2[50];
    FILE *fq;

    strcpy(f,"Data\\IDS\\");
    strcat(f,u);
    strcat(f,".txt");

    fq = fopen(f, "r");

    //First Name
    fgets(c1, 17, (FILE*)fq);
    fgets(c1, 22, (FILE*)fq);
    decrypt(c1);
    //Last Name
    fgets(c2, 17, (FILE*)fq);
    fgets(c2, 22, (FILE*)fq);
    decrypt(c2);

    strrev(c1);
    strrev(c2);
    strnset(c1,' ',1);
    strnset(c2,' ',1);
    strrev(c1);
    strrev(c2);
    strcat(c1,c2);

    fclose(fq);

    strrev(c1);
    strcat(c1, " morF");
    strrev(c1);
    strcat(c1, ">>");

    FILE *fr;

    strcpy(g,"Data\\MSG\\");
    strcat(g,k);
    strcat(g,".txt");

    if((fr=fopen(g, "a"))==NULL)
    {
        fr=fopen(g, "w");
    }

    fputc('\n', fr);
    fputs(c1, fr);

    fclose(fr);
}

void pmessagewrite(char u[])
{
    int j=0;
    char e, g[100];
    FILE *fr;

    strcpy(g,"Data\\MSG\\");
    strcat(g,u);
    strcat(g,".txt");

    if((fr=fopen(g, "a"))==NULL)
    {
        fr=fopen(g, "w");
    }

    while((e=getchar())!='*')
    {
        fputc(e, fr);
    }

    fputc('\n', fr);

    fclose(fr);
}

void messagetab(char u[])
{
    char y[5];

    messageboard();

    printf("\n\nLeave a Message? (Yes or No) : ");
    scanf("%s", y);

    if((strcmpi(y,"yes"))==0)
    {
        messagename(u);

        printf("(Enter '*' sign to end your massage) : ");

        messagewrite();
    }

    else
    {
        system("cls");
        msm();
        homepage(u);
    }
}

void pmessagetab(char u[])
{
    int s=0, d;
    char f[20], g[100];
    FILE *fr;

    for(d=0;d<10;d++)
    {
        s=0;

        printf("Friends User Name : ");
        scanf("%s", f);

        strupr(f);
        encrypt(f);

        strcpy(g,"Data\\IDS\\");
        strcat(g,f);
        strcat(g,".txt");

        if((fr = fopen(g, "r"))==NULL)
        {
            s=1;
        }

        fclose(fr);

        if(s!=1)
        {

            pmessagename(u, f);

            printf("(Enter '*' sign to end your massage) : ");

            pmessagewrite(f);

            break;
        }

        else
        {
            msm();

            printf("Message\n");
            printf("-------\n\n");

            printf("Nobody With this User Name is a MSM User. Try again..\n\n");
            continue;
        }
    }
}

void findfriend(char j[])
{
    int i, k;
    char f[100], c[50], n1[30], n2[30];
    FILE *fq;

    k=gendercheck(j);

    strcpy(f,"Data\\IDS\\");
    strcat(f,j);
    strcat(f,".txt");

    if(k==1)
    {
        printf("\n\t\tMr. ");
    }
    else if(k==2)
    {
        printf("\n\t\tMs. ");
    }
    else
    {
        printf("\n\t\tMr./Ms. ");
    }

    if((fq = fopen(f, "r"))==NULL)
    {
        msm();
        printf("Friend Finder\n");
        printf("-------------\n\n");
        printf("Nobody with this Name is a MSM user. Try again...");
    }

    else
    {
        //First Name
    fgets(c, 17, (FILE*)fq);
    fgets(n1, 30, (FILE*)fq);
    decrypt(n1);

    //Last Name
    fgets(c, 17, (FILE*)fq);
    fgets(n2, 30, (FILE*)fq);
    decrypt(n2);

    strrev(n1);
    strrev(n2);
    strnset(n1,' ',1);
    strnset(n2,',',1);
    strrev(n1);
    strrev(n2);

    printf("%s %s\n\n", n2, n1 );

    //User Name
    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);

    //Password
    fgets(c, 17, (FILE*)fq);
    fgets(c, 30, (FILE*)fq);

    //Email
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );

    //Gender
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );

     //Mobile No.
    fgets(c, 17, (FILE*)fq);
    decrypt2(c);
    printf("%s", c );
    fgets(c, 30, (FILE*)fq);
    decrypt(c);
    printf("%s", c );

    fclose(fq);
    }

}

int tab()
{
    int x;

    printf("\n\n");
    printf("Home               = '0'\n");
    printf("Profile            = '1'\n");
    printf("Message Room       = '2'\n");
    printf("Notifications      = '3'\n");
    printf("Send Message       = '4'\n");
    printf("Friend Finder      = '5'\n");
    printf("Sign Out           = '6'\n");

    printf("\nWhat do you want to do? : ");
    scanf("%d", &x);

    return x;
}
