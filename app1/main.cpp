#include <iostream>
#include <cstring>
#include <fstream>
#include "../shared/data/job.h"
using namespace std;

void Job::init(int id, string nume, string d, int v, int e, vector<string> skill){
    this->id = id;
    this->nume = nume;
    this->descriere = d;
    this->varsta = v;
    this->experienta = e;
    this->skill = skill;
}

Job::Job(int id, string nume, string d, int v, int e, vector<string> skill){
    this->init(id, nume, d, v, e, skill);
}

Job::Job(const Job &j){
    this->init(j.id, j.nume, j. descriere, j.varsta, j.experienta, j.skill);
}

ostream & operator <<(ostream &o, const Job &j){
    o << j.id << " " << j.nume << " " << j.descriere << " ";
    for(vector<string> :: const_iterator i = j.skill.begin(); i != j.skill.end(); ++i){
        o << *i << " ";
    }
    return o;
}
int main(int argc, char **argv) {
    if(strcmp(argv[1],"adaugare_job") == 0 ){
        ofstream f("job.txt",ios::app);
        f << argv[2] ;

        f.close();


    }

}

