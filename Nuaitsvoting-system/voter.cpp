#include "Voter.h"

Voter::Voter()
{
    name = "";
    id = "";

    for(int i=0;i<4;i++)
    {
        hasVoted[i] = false;
    }
}

Voter::Voter(string n,string i)
{
    name = n;
    id = i;

    for(int j=0;j<4;j++)
    {
        hasVoted[j] = false;
    }
}
