#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
using namespace std;

class Candidate
{
public:
    string name;
    string position;
    int votes;

    Candidate();
    Candidate(string n,string p);
};

#endif
