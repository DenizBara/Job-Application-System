#ifndef APP1_JOB_H
#define APP1_JOB_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Job{
    int id;
    string descriere,nume;
    vector <string> skill;
    //vector <Candidat> candidati;
public:
    Job(int, string, string, vector<string>);
    Job(const Job &);
    friend ostream & operator << (ostream &, const Job &);
private:
    void init(int, string, string, vector<string>);
};

class Candidat{
    string nume,prenume;
    int varsta,experienta;
    vector <int> id_job;
public:
    Candidat(string,string,int,int,vector<int>);
    Candidat(const Candidat &);
    friend ostream & operator << (ostream &, const Candidat &);
private:
    void init(string,string,int,int,vector<int>);
};

#endif
