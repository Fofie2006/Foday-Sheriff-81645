#include "Candidate.h"

Candidate::Candidate()
{
    name = "";
    position = "";
    votes = 0;
}

Candidate::Candidate(string n, string p)
{
    name = n;
    position = p;
    votes = 0;
}
