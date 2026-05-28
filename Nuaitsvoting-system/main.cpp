#include <iostream>
#include "Voter.h"
#include "Candidate.h"
#include "Admin.h"

using namespace std;

int main()
{
    Admin admin;

    Voter voters[100];

    Candidate candidates[4][10];

    string positions[4]=
    {
        "President",
        "Vice President",
        "Secretary",
        "Treasurer"
    };

    int totalCandidates[4]={2,1,1,1};

    int totalVoters=0;

    int choice;

    // Default candidates

    candidates[0][0]=Candidate("Fofie","President");
    candidates[0][1]=Candidate("Shaw","President");

    candidates[1][0]=Candidate("Ibrahim","Vice President");

    candidates[2][0]=Candidate("Mariama","Secretary");

    candidates[3][0]=Candidate("Mark","Treasurer");

    do
    {
        cout<<"\n===== NUAITS VOTING SYSTEM ====="<<endl;

        cout<<"1. Register Student"<<endl;
        cout<<"2. View Candidates"<<endl;
        cout<<"3. Cast Vote"<<endl;
        cout<<"4. Admin Login"<<endl;
        cout<<"5. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice)
        {

        case 1:
        {
            string name,id;
            bool found=false;

            cout<<"Enter Name: ";
            getline(cin,name);

            cout<<"Enter Student ID: ";
            getline(cin,id);

            for(int i=0;i<totalVoters;i++)
            {
                if(voters[i].id==id)
                {
                    found=true;
                    break;
                }
            }

            if(found)
            {
                cout<<"Student already registered"<<endl;
            }
            else
            {
                voters[totalVoters]=Voter(name,id);

                totalVoters++;

                cout<<"Registration successful"<<endl;
            }

            break;
        }

        case 2:
        {
            cout<<"\n===== CANDIDATES ====="<<endl;

            for(int p=0;p<4;p++)
            {
                cout<<"\n"<<positions[p]<<endl;

                for(int i=0;i<totalCandidates[p];i++)
                {
                    cout<<i+1<<". "
                        <<candidates[p][i].name
                        <<endl;
                }
            }

            break;
        }

        case 3:
        {
            string id;

            bool found=false;

            int index;

            cout<<"Enter Student ID: ";
            getline(cin,id);

            for(int i=0;i<totalVoters;i++)
            {
                if(voters[i].id==id)
                {
                    found=true;
                    index=i;
                }
            }

            if(found==false)
            {
                cout<<"Student not found"<<endl;
                break;
            }

            for(int p=0;p<4;p++)
            {
                if(voters[index].hasVoted[p])
                {
                    continue;
                }

                cout<<"\nVote for "
                    <<positions[p]
                    <<endl;

                for(int i=0;i<totalCandidates[p];i++)
                {
                    cout<<i+1
                    <<". "
                    <<candidates[p][i].name
                    <<endl;
                }

                int vote;

                cout<<"Choice: ";
                cin>>vote;

                candidates[p][vote-1].votes++;

                voters[index].hasVoted[p]=true;
            }

            cin.ignore();

            cout<<"Voting completed"<<endl;

            break;
        }

        case 4:
        {
            string user,pass;

            cout<<"Username: ";
            getline(cin,user);

            cout<<"Password: ";
            getline(cin,pass);

            if(user==admin.username &&
               pass==admin.password)
            {
                int adminChoice;

                cout<<"\n===== ADMIN MENU ====="<<endl;

                cout<<"1. View Results"<<endl;
                cout<<"2. Add Candidate"<<endl;
                cout<<"3. Remove Candidate"<<endl;
                cout<<"4. Reset Election"<<endl;

                cout<<"Choice: ";
                cin>>adminChoice;

                cin.ignore();

                switch(adminChoice)
                {
                case 1:

                    for(int p=0;p<4;p++)
                    {
                        cout<<"\n"<<positions[p]<<endl;

                        int highest=0;
                        string winner="";

                        for(int i=0;i<totalCandidates[p];i++)
                        {
                            cout
                            <<candidates[p][i].name
                            <<" : "
                            <<candidates[p][i].votes
                            <<endl;

                            if(candidates[p][i].votes>highest)
                            {
                                highest=
                                candidates[p][i].votes;

                                winner=
                                candidates[p][i].name;
                            }
                        }

                        cout<<"Winner: "
                            <<winner
                            <<endl;
                    }

                    break;

                case 2:
                {
                    int pos;

                    string newName;

                    cout<<"\nSelect Position"<<endl;

                    for(int i=0;i<4;i++)
                    {
                        cout<<i+1
                        <<". "
                        <<positions[i]
                        <<endl;
                    }

                    cin>>pos;

                    cin.ignore();

                    cout<<"Candidate name: ";

                    getline(cin,newName);

                    candidates[pos-1]
                              [totalCandidates[pos-1]]
                    =
                    Candidate(
                    newName,
                    positions[pos-1]);

                    totalCandidates[pos-1]++;

                    cout<<"Candidate added"<<endl;

                    break;
                }

                case 3:
                {
                    int pos;

                    cout<<"Select Position"<<endl;

                    for(int i=0;i<4;i++)
                    {
                        cout<<i+1
                        <<". "
                        <<positions[i]
                        <<endl;
                    }

                    cin>>pos;

                    cout<<"Candidate number: ";

                    int remove;

                    cin>>remove;

                    remove--;

                    for(int i=remove;
                    i<totalCandidates[pos-1]-1;
                    i++)
                    {
                        candidates[pos-1][i]
                        =
                        candidates[pos-1][i+1];
                    }

                    totalCandidates[pos-1]--;

                    cout<<"Candidate removed"<<endl;

                    break;
                }

                case 4:

                    for(int p=0;p<4;p++)
                    {
                        for(int i=0;
                        i<totalCandidates[p];
                        i++)
                        {
                            candidates[p][i].votes=0;
                        }
                    }

                    cout<<"Election reset"<<endl;

                    break;
                }
            }

            else
            {
                cout<<"Invalid Login"<<endl;
            }

            break;
        }

        case 5:

            cout<<"Program Closed"<<endl;

            break;
        }

    }while(choice!=5);

    return 0;
}
