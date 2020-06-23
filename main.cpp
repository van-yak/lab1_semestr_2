#include "List.hpp"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]){
        bool flag = true;
        int action;
        int n, num;
        string s_temp, s_temp1;
        int ball;
        ofstream output;
        if(argc != 2){
                cout << "Incorrect number of arguments" << endl;
                return -1;
        }
        List playList;
        //studList.readFromFile(argv[1]);
        ifstream input(argv[1]);
        if(!input.is_open()){
                cout << "Can't open thise file" << endl;
                return -1;
        }
        input >> playList;
        input.close();
        while(flag){
                cout << "Choose what you want " << endl;
                cout << "1. Add new player" << endl;
                cout << "2. Remove player" << endl;
                cout << "3. Change player's data" << endl;
                cout << "4. Find a player" << endl;
                cout << "5. Print the whole database" << endl;
                cout << "6. Save the list to the file" << endl;
                cout << "7. Exit" << endl;
                cin >> action;
                Players* temp;
                switch(action){
                        case 1:
                                temp = new Players;
                                cin >> *temp;
                                playList.add(temp);
                                break;
                        case 2:
                                cout << "Enter player's number: ";
                                cin >> n;
                                if(n == 0)
                                        playList.popHead();
                                else
                                        playList.remove(n);
                                break;
                        case 3:
                                cout << "Enter player's number: ";
                                cin >> num;
                                cout << "What would you like to change?" << endl;
                                cout << "1. Name" << endl;
                                cout << "2. Group" << endl;
                                cout << "3. Ball" << endl;
                                cin >> n;
                                switch(n){
                                        case 1:
                                                cout << "Enter new name: ";
                                                cin >> s_temp;
                                                playList.changeName(num, s_temp);
                                                break;
                                        case 2:
                                                cout << "Enter new group: ";
                                                cin >> s_temp;
                                                playList.changeGroup(num, s_temp);
                                                break;
                                        case 3:
                                                cout << "Enter ball: ";
                                                cin >> ball;
                                                playList.changeBall(num, ball);
                                                break;
                                }
                                break;
                        case 4:
                                cout << "Enter the way to find" << endl;
                                cout << "1. Name" << endl;
                                cout << "2. Group" << endl;
                                cout << "3. Name and group" << endl;
                                cout << "4. ball" << endl;
                                cin >> n;
                                switch(n){
                                        case 1:
                                                cout << "Enter name: ";
                                                cin >> s_temp;
                                                playList.find(s_temp);
                                                break;
                                        case 2:
                                                cout << "Enter group: ";
                                                cin >> s_temp;
                                                playList.find1(s_temp);
                                                break;
                                        case 3:
                                                cout << "Enter name: ";
                                                cin >> s_temp;
                                                cout << "Enter group: ";
                                                cin >> s_temp1;
                                                playList.find(s_temp, s_temp1);
                                                break;
                                        case 4:
                                                cout << "What ball do you want to find?" << endl;
                                                cin >> ball;
                                                playList.find(ball);
                                                break;
                                }
                                break;
                        case 5:
                                cout << playList;
                                break;
                        case 6:
                                output.open(argv[1]);
                                if(!output.is_open()){
                                        cout << "Can't open file" << endl;
                                        return -1;
                                }
                                output << playList;
                                output.close();
                                break;
                        case 7:
                                flag = false;
                                break;
                        default:
                                cout << "Incorrect action" << endl;
                                break;
                }
        }
}





