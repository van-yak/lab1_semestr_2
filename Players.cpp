#include "Players.hpp"
#include <iostream>
#include <fstream>
using namespace std;
Players::Players(){
        _name = "";
        _group = "";
        _ball = 0;
        _next = NULL;
}
void Players::setBall(int ball){
        _ball = ball;
}
void Players::setName(string name){
        _name = name;
}
void Players::setGroup(string group){
        _group = group;
}
void Players::setNext(Players* next){
        _next = next;
}
void Players::print(){
        cout << "Name: " << _name << endl;
        cout << "Group: " << _group << endl;
        cout << "ball:" << _ball << endl;
}
Players* Players::next(){
        return _next;
}
string Players::name(){
        return _name;
}
string Players::group(){
        return _group;
}
int Players::ball(){
        return _ball;
}
ostream& operator<< (ostream &out, Players &player){
        out << "Name: " << player._name << endl;
        out << "Group: " << player._group << endl;
        out << "ball:" << player._ball << endl;
        return out;
}
istream& operator>> (istream &in, Players &player){
        cout << "Name: ";
        in >> player._name;
        cout << "Group: ";
        in >> player._group;
        cout << "ball: ";
        in >> player._ball;
        return in;
}
ofstream& operator<< (ofstream &fout, Players &player){
        fout << player._name << endl;
        fout << player._group << endl;
        fout << player._ball << endl;
        return fout;
}
ifstream& operator>> (ifstream &fin, Players &player){
        fin >> player._name;
        fin >> player._group;
        fin >> player._ball;
        return fin;
}

