#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

struct voter_information
{
    char aadhar[12];
    char name[50];
    char dob[10];
    struct voter_information *next;
};

typedef struct voter_information Node;

Node *head;
Node *sample, *start = nullptr;
int attempts = 3;
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0;

Node *main_logs(Node *);
Node *voter_entry(Node *);
Node *search_voter(char x[], char y[], char z[], Node *, int *);
void voting();
void not_again();
void admin_entry();
void display();
void stop();
void winner();
void exit_();

int main()
{
    while (1)
    {
        system("cls");
        cout << "\n\n\n";
        cout << "\t            * * * * * * WELCOME TO THE ONLINE VOTING PORTAL * * * * * *        \n\n\n\n\n";
        cout << "\t           ************************************************************        \n\n\n\n\n";
        cout << "\t           * * * * * Please Press 1 for logging into vote main Logs * * * * *    \n\n\n";
        int T;
        cin >> T;
        if (T == 1)
        {
            start = main_logs(start);
        }
    }

    return 0;
}

Node *main_logs(Node *start)
{
    system("cls");
    cout << "\n\n\n";
    cout << "        \t\t\t1.  VOTER ENTRY     \n";
    Sleep(500);
    cout << "        \t\t\t2.  ADMIN PANEL ENTRY    \n";
    Sleep(500);
    cout << "        \t\t\t3.  WINNER DECLARATION          \n";
    cout << "    \t IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU ARE ELIGIBLE TO CAST VOTE ELSE NOT ELIGIBLE    \n\n\n";
    Sleep(500);
    cout << "    \t * * * * * * PLEASE DO ENTRY ACCORDINGLY FROM ABOVE MENTIONED ENTRIES * * * * * * \n\n\n";
    int T;
    cin >> T;
    if (T == 1)
    {
        start = voter_entry(start);
    }
    else if (T == 2)
    {
        admin_entry();
    }
    else if (T == 3)
    {
        winner();
    }
    else
    {
        cout << "\n\n PLEASE ENTER A VALID ENTRY FROM ABOVE MENTIONED ENTRIES \n\n";
        main_logs(start);
    }

    return start;
}

Node *voter_entry(Node *start)
{
    int count = 0;
    int *z;
    z = &count;
    Node *temp;
    char name[50], dob[15], aadhar[20];
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES IN THE VOTING DIRECTORY THEN YOU ARE ELIGIBLE FOR VOTING ELSE NOT\n\n";
    Sleep(500);
    cout << "\t\t\t IF INVALID CREDENTIALS ARE ENTERED " << attempts << " TIMES, THE PORTAL WILL CLOSE AUTOMATICALLY\n\n\n";
    Sleep(500);
    cout << "\n\n\n";
    Sleep(500);
    cout << "\t\t\tEnter your AADHAR ID number: -  ";
    cin.ignore();
    cin.getline(aadhar, 20);
    cout << "\t\t\tEnter Your NAME: -  ";
    cin.getline(name, 50);
    cout << "\t\t\tEnter Your BIRTH DATE in dd-mm-yyyy format: -  ";
    cin.getline(dob, 15);
    temp = new Node;
    strcpy(temp->aadhar, aadhar);
    strcpy(temp->name, name);
    strcpy(temp->dob, dob);
    temp->next = nullptr;
    head = temp;
    while (temp != nullptr)
    {
        if ((strcmp(temp->aadhar, "10001") == 0 && strcmp(temp->name, "Sher Gill") == 0 && strcmp(temp->dob, "01-08-2002") == 0) ||
            (strcmp(temp->aadhar, "10002") == 0 && strcmp(temp->name, "Bhuvnesh Purohit") == 0 && strcmp(temp->dob, "18-09-2001") == 0) ||
            (strcmp(temp->aadhar, "10003") == 0 && strcmp(temp->name, "Himanshu Jangid") == 0 && strcmp(temp->dob, "28-01-2002") == 0) ||
            (strcmp(temp->aadhar, "10004") == 0 && strcmp(temp->name, "Gungun Mehta") == 0 && strcmp(temp->dob, "01-01-1999") == 0) ||
            (strcmp(temp->aadhar, "10005") == 0 && strcmp(temp->name, "Aniket Arora") == 0 && strcmp(temp->dob, "28-08-1999") == 0) ||
            (strcmp(temp->aadhar, "10006") == 0 && strcmp(temp->name, "Dipika Singh") == 0 && strcmp(temp->dob, "20-10-2000") == 0) ||
            (strcmp(temp->aadhar, "10007") == 0 && strcmp(temp->name, "Arya Jha") == 0 && strcmp(temp->dob, "02-03-1999") == 0) ||
            (strcmp(temp->aadhar, "10008") == 0 && strcmp(temp->name, "Ravi Raj") == 0 && strcmp(temp->dob, "26-12-1999") == 0) ||
            (strcmp(temp->aadhar, "10009") == 0 && strcmp(temp->name, "Shubham Rai") == 0 && strcmp(temp->dob, "02-01-1999") == 0) ||
            (strcmp(temp->aadhar, "10010") == 0 && strcmp(temp->name, "Priya Pandey") == 0 && strcmp(temp->dob, "03-01-1999") == 0))
        {
            attempts = 3;
            start = search_voter(temp->aadhar, temp->name, temp->dob, start, &count);
            if (count == 0)
            {
                voting();
            }
            else
            {
                not_again();
            }
        }
        else
        {
            attempts--;
            if (attempts == 0)
            {
                stop();
                break;
            }
            cout << "\n\n\n\n";
            cout << "\tYour AADHAR ID or NAME or DATE OF BIRTH is wrong\n\n";
            Sleep(500);
            cout << "\t\t\tPlz Re-Enter\n\n";
            Sleep(500);
            system("pause");
            start = main_logs(start);
        }
        temp = temp->next;
    }
    return start;
}

Node *search_voter(char x[], char y[], char z[], Node *start, int *U)
{
    *U = 0;
    Node *tail, *sample;
    if (start == nullptr)
    {
        sample = new Node;
        strcpy(sample->aadhar, x);
        strcpy(sample->name, y);
        strcpy(sample->dob, z);
        start = sample;
        sample->next = nullptr;
    }
    else
    {
        tail = start;
        while (tail != nullptr)
        {
            if ((strcmp(tail->aadhar, x) == 0 && strcmp(tail->name, y) == 0 && strcmp(tail->dob, z) == 0))
            {
                *U = 1;
                break;
            }
            tail = tail->next;
        }
        if (*U == 0)
        {
            sample = new Node;
            strcpy(sample->aadhar, x);
            strcpy(sample->name, y);
            strcpy(sample->dob, z);
            tail = sample;
            sample->next = nullptr;
        }
    }
    return start;
}

void voting()
{
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t     * * * * * LIST OF CANDIDATES * * * * * \n\n\n";
    Sleep(500);
    cout << "\t\t\t NAME  --------------------------->   SYMBOL\n\n";
    Sleep(500);
    cout << "\t\t\t 1.Jayesh P. Modi                   1.Lotus\n";
    Sleep(500);
    cout << "\t\t\t 2.Sanskar Gandhi                   2.Hand\n";
    Sleep(500);
    cout << "\t\t\t 3.Harilal Kumar                    3.Broomstick\n";
    Sleep(500);
    cout << "\t\t\t 4.Kuntal Banerjee                  4.Fish\n";
    Sleep(500);
    cout << "\t\t\t 5.Deepika Sharma                   5.Wheel\n\n\n";
    int vote;
    cout << "\n\t\t\t Enter Your Choice : - ";
    cin >> vote;
    if (vote == 1)
    {
        vote1++;
        cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Jayesh P. Modi\n";
    }
    else if (vote == 2)
    {
        vote2++;
        cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Sanskar Gandhi\n";
    }
    else if (vote == 3)
    {
        vote3++;
        cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Harilal Kumar\n";
    }
    else if (vote == 4)
    {
        vote4++;
        cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Kuntal Banerjee\n";
    }
    else if (vote == 5)
    {
        vote5++;
        cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Deepika Sharma\n";
    }
    else
    {
        cout << "\n\t\t* * * * * * * * * * * * * INVALID CHOICE ENTERED * * * * * * * * * * * * * * \t\t\n";
        cout << "\n\t\t\t\tENTER AGAIN\t\t\t\t\n";
    }
    cout << "\n\n* * * * * * * * * * * * * THANK YOU * * * * * * * * * * * * * \n\n";
    cout << "press any key";
    cin.ignore();
    cin.get();
}

void not_again()
{
    int A;
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t        * * * * * YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY * * * * *       \n\n\n";
    Sleep(500);
    cout << "\t\t\t        * * * * * YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE * * * * *     \n\n\n";
    Sleep(500);
    cout << "\t\t\t Press 1 for Entering Main Logs\n\n";
    Sleep(500);
    cin >> A;
    if (A == 1)
    {
        main_logs(start);
    }
}

void stop()
{
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t (:- SORRY YOU ENTERED WRONG CREDENTIALS FOR 3 TIMES IN A ROW -:) \n\n\n";
    Sleep(500);
    cout << "\t\t\t\t\t TRY AGAIN AFTER A WHILE \n\n\n";
    Sleep(500);
    cout << "\t\t\t\t\t * * * * * Thank You * * * * * \n\n\n";
    Sleep(10000);
    cout << "press any key";
    cin.ignore();
    cin.get();
}

void admin_entry()
{
    int B;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\tEnter Your Admin Password: -   ";
    cin >> B;
    if (B == 501)
    {
        display();
    }
    else
    {
        cout << "\n\nINVALID ADMIN PASSWORD\n";
    }
}

void display()
{
    int P;
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\tPresent Vote Counts of Election is :\n\n";
    Sleep(500);
    cout << "\t\t\t  Jayesh P. Modi  got       " << vote1 << " Votes\n";
    Sleep(500);
    cout << "\t\t\t  Sanskar Gandhi  got       " << vote2 << " Votes\n";
    Sleep(500);
    cout << "\t\t\t  Harilal Kumar   got       " << vote3 << " Votes\n";
    Sleep(500);
    cout << "\t\t\t  Kuntal Banerjee got       " << vote4 << " Votes\n";
    Sleep(500);
    cout << "\t\t\t  Deepika Sharma  got       " << vote5 << " Votes\n\n\n\n";
    Sleep(500);
    cout << "\t\t\t\t\tPress Any Key For Main Logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\t\tENTER THE PASSWORD TO CLOSE VOTING PORTAL\n ";
    cin >> P;
    if (P == 405)
        exit_();
    else
        main_logs(start);
}

void winner()
{
    system("cls");
    cout << "\n\n\n\n";
    if (vote2 < vote1 && vote3 < vote1 && vote4 < vote1 && vote5 < vote1)
        cout << "\t\t\tThe present Winner is 'Jayesh P. Modi' and he has got " << vote1 << " votes\n\n\n\n";
    else if (vote1 < vote2 && vote3 < vote2 && vote4 < vote2 && vote5 < vote2)
        cout << "\t\t\tThe present Winner is 'Sanskar Gandhi' and he has got " << vote2 << " votes\n\n\n\n";
    else if (vote1 < vote3 && vote2 < vote3 && vote4 < vote3 && vote5 < vote3)
        cout << "\t\t\tThe present Winner is 'Harilal Kumar' and he has got " << vote3 << " votes\n\n\n\n";
    else if (vote1 < vote4 && vote2 < vote4 && vote3 < vote4 && vote5 < vote4)
        cout << "\t\t\tThe present Winner is 'Kuntal Banerjee' and he has got " << vote4 << " votes\n\n\n\n";
    else if (vote1 < vote5 && vote2 < vote5 && vote3 < vote5 && vote4 < vote5)
        cout << "\t\t\tThe present Winner is 'Deepika Sharma' and she has got " << vote5 << " votes\n\n\n\n";
    cout << "\t\t\t\tEnter Any Key for Main Log\n\n";
    cin.ignore();
    cin.get();
    main_logs(start);
}

void exit_()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n";
    Sleep(300);
    cout << "\t\t\t * * * * * Thank You For Using This ONLINE PLATFORM For VOTING* * * * *   \n\n\n";
    Sleep(300);
    exit(0);
}
