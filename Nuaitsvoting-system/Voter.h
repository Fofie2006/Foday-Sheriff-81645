#ifndef VOTER_H
#define VOTER_H

#include <string>
using namespace std;

class Voter
{
public:
    string name;
    string id;

    bool hasVoted[4];

    Voter();
    Voter(string n,string i);
};

#endif
