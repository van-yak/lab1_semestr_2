#include <string>
using namespace std;
class Players{
        private:
                string _name;
                string _group;
                int _ball;
                Players* _next;
        public:
                Players();
                void setBall(int ball);
                void setName(string _name);
                void setGroup(string _group);
                void setNext(Players* next);
                void print();
                Players* next();
                string name();
                string group();
                int ball();
                friend ostream& operator<< (ostream &out, Players &player);
                friend istream& operator>> (istream &in, Players &player);
                friend ofstream& operator<< (ofstream &fout, Players &player);
                friend ifstream& operator>> (ifstream &fin, Players &player);
};


