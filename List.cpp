#include "List.hpp"
#include <fstream>
#include <iostream>
using namespace std;
List::List(){
        head = NULL;
        _size = 0;
}
List::~List(){
        while(head != NULL){
                Players* temp = head->next();
                delete head;
                head = temp;
        }
}
void List::add(Players* temp){
        temp->setNext(head);
        head = temp;
        _size++;
}
void List::popHead(){
        Players* temp = head->next();
        delete head;
        head = temp;
        _size--;
}
void List::remove(int n){
        Players* temp = head;
        if(head == NULL || n > _size)
                return;
        for(int i = 0; i < n-1; i++)
                temp = temp->next();
        Players* del = temp->next();
        temp->setNext(del->next());
        delete del;
        _size--;
}
void List::printAll(){
        Players* temp = head;
        for(int i = 0; i < _size; i++){
                cout << "Number of element: " << i << endl;
                temp->print();
                cout << endl;
                temp = temp->next();
        }
}
void List::readFromFile(string filename){
        ifstream input;
        input.open(filename);
        if(!input.is_open()){
                cout << "Can't open this file" << endl;
                return;
        }
        string s_temp;
        int i_temp;
        do{
                Players* temp = new Players;
                input >> s_temp;
                temp->setName(s_temp);
                input >> s_temp;
                temp->setGroup(s_temp);
                input >> i_temp;
                temp->setBall(i_temp);

                this->add(temp);
        } while(!input.eof());
        input.close();
        this->popHead();
}
void List::writeToFile(string filename){
        ofstream output;
        output.open(filename);
        if(!output.is_open()){
                cout << "Can't open thise file" << endl;
                return;
        }
        Players* temp = head;
        while(temp != NULL){
                output << temp->name() << endl;
                output << temp->group() << endl;
                output << temp->ball() << endl;
                temp = temp->next();
        }
        output.close();
}
void List::find(string name){
        Players* temp = head;
        int num = 0;
        while(temp != NULL){
                if(temp->name() == name){
                        cout << "Number of element: " << num << endl;
                        temp->print();
                }
                temp = temp->next();
                num++;
        }
}
void List::find1(string group){
        Players* temp = head;
        int num = 0;
        while(temp != NULL){
                if(temp->group() == group){
                        cout << "Number of element: " << num << endl;
                        temp->print();
                }
                temp = temp->next();
                num++;
        }
}
void List::find(string name, string group){
        Players* temp = head;
        int num = 0;
        while(temp != NULL){
                if(temp->name() == name && temp->group() == group){
                        cout << "Number of element: " << num << endl;
                        temp->print();
                }
                temp = temp->next();
        }
}
void List::find(int ball){
        Players* temp = head;
        int num = 0;
        while(temp != NULL){
                if(temp->ball() == ball){
                        cout << "Number of element: " << num << endl;
                        temp->print();
                        cout << endl;
                }
                temp = temp->next();
                num++;
        }
}
void List::changeName(int n, string name){
        Players* temp = new Players;
        temp = head;
        for(int i = 0; i < n; i++)
                temp = temp->next();
        temp->setName(name);
}
void List::changeGroup(int n, string group){
        Players*temp = new Players;
        temp = head;
        for(int i = 0; i < n; i++)
                temp = temp->next();
        temp->setGroup(group);
}
void List::changeBall(int n, int ball){
        Players* temp = new Players;
        temp = head;
        for(int i = 0; i < n; i++)
                temp = temp->next();
        temp->setBall(ball);
}

ostream& operator<< (ostream &out, List &list){
        Players* temp = list.head;
        for(int i = 0; i < list._size; i++){
                out << "Number of element: " << i << endl;
                out << *temp;
                out << endl;
                temp = temp->next();
        }
        return out;
}

ofstream& operator<< (ofstream &fout, List &list){
        Players* temp = list.head;
        while(temp != NULL){
                fout << *temp;
                temp = temp->next();
        }
        return fout;
}
ifstream& operator>> (ifstream &fin, List &list){

        do{
                Players* temp = new Players;
                fin >> *temp;

                list.add(temp);
        } while(!fin.eof());
        list.popHead();
        return fin;
}
