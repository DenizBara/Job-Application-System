#include <iostream>
#include <cstring>
#include <fstream>
#include "/Users/istrateioana/Desktop/proiect_pp/shared/data/job.h"
using namespace std;

void Job::init(int id, string nume, string d, vector<string> skill){
    this->id = id;
    this->nume = nume;
    this->descriere = d;
    this->skill = skill;
}

Job::Job(int id, string nume, string d, vector<string> skill){
    this->init(id, nume, d, skill);
}

Job::Job(const Job &j){
    this->init(j.id, j.nume, j. descriere, j.skill);
}

ostream & operator << (ostream &o, const Job &j){
    o << j.id << " " << j.nume << " " << j.descriere << " " << j.skill.size() << " ";
    for(vector<string> :: const_iterator i = j.skill.begin(); i != j.skill.end(); ++i){
        o << *i << " ";
    }
    return o;
}
void Candidat::init(string nume, string prenume, int v,int e,vector<int> id_job){
    this->nume=nume;
    this->prenume=prenume;
    this->varsta=v;
    this->experienta=e;
    this->id_job=id_job;}

Candidat::Candidat(const Candidat &c){
    this->init(c.nume,c.prenume,c.varsta,c.experienta,c.id_job);}

ostream & operator <<(ostream &o, const Candidat &c){
    o << c.nume << " " << c.prenume<< " " << c.varsta<< " "<<c.experienta<<" ";
    for(vector<int> :: const_iterator i = c.id_job.begin(); i != c.id_job.end(); ++i){
        o << *i << " ";
    }
    return o;
}

vector<string> Job::getSkill() const{
    return this->skill;
}

int c, id;
char nume[250], d[250], oras[250];
char a[250];
int n;
vector <Job> j;
vector <string> skill;
string descriere;

void creare(){
    ifstream g("/Users/istrateioana/Desktop/proiect_pp/shared/files/job.txt");
    g >> c;
    while(g >> id ) {
        g >> nume;
        g.ignore();
        g >> d;
        g.ignore();
        g >> oras;
        g.ignore();
        descriere = string(d) + " " + string(oras);
        g >> n;
        for (int i = 0; i < n; i++) {
            g >> a;
            string s(a);
            skill.push_back(s);
        }
        g.ignore();
        Job e(id, nume, descriere, skill);
        j.push_back(e);
        skill.clear();
    }
    g.close();

}
int main(int argc, char **argv) {
    if(strcmp(argv[1],"aplicare_job") == 0 ) {
        if (argc < 8)
            cout << "Sintaxa invalida! Sintaxa corecta: ./a.out aplicare_job <prenume><nume><varsta><experienta><nr_id_job><id_job";
        else {
            int i;
            ofstream f("/Users/istrateioana/Desktop/proiect_pp/shared/files/candidat.txt", ios::app);
            for (i = 2; i < argc; i++)
                f << argv[i] << " ";
            f << endl;
            f.close();
        }
    }
    else if(strcmp(argv[1],"vizualizare_joburi")==0) {
        if (argc != 2)
            cout << "Sintaxa invalida! Sintaxa corecta: ./a.out vizualizare_joburi";
            else
        {

            cout << "ID " << "   NUME    " << "   DESCRIERE    " << "    SKILL-URI    " << endl;
            creare();
            for (vector<Job>::iterator i = j.begin(); i != j.end(); ++i)
                cout << *i << endl;
        }
    }
    else if(strcmp ( argv[1],"cautare_job_in_functie_de_skill")==0)
    {   if(argc != 3)
        cout << "Sintaxa invalida! Sintaxa corecta: ./a.out cautare_job_in_functie_de_skill <skill>";
       else {
            creare();
            string str(argv[2]);
            for (vector<Job>::iterator i = j.begin(); i != j.end(); ++i) {
                vector<string> skill = i->getSkill();
                for (vector<string>::iterator k = skill.begin(); k != skill.end(); k++)
                    if (*k == str)
                        cout << *i;
            }
        }
    }

}
