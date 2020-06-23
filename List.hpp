#include "Players.hpp"
class List{
        private:
                Players* head;
                int _size;
        public:
                List();
                ~List();
                void add(Players* t);
                void popHead();
                void remove(int n);
                void printAll();
                void readFromFile(string filename);
                void writeToFile(string filename);
                void find(string name);
                void find1(string group);
                void find(string name, string group);
                void find(int ball);
                void changeName(int n, string name);
                void changeGroup(int n, string group);
                void changeBall(int n, int ball);

                friend ostream& operator<< (ostream &out, List &list);
                friend ofstream& operator<< (ofstream &fout, List &list);
                friend ifstream& operator>> (ifstream &fin, List &list);
};

