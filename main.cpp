#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;


void main(){
    // fstream input;
    char nextRound;
    do {
    string fileName;
    cout << "Enter name of the file:" << endl;
    cin >> fileName;
    string *title;
    string *url;
    int *score;
    readInput(fileName, title, url, score);
    findMode();
    displayScreen();
    cout << "Another file? Y for yes" << endl;
    cin >> nextRound;
    } while (nextRound == 'Y');


}

void readInput(string file, string *title, string *url, int *score){
    fstream input;
    input.open(file);
    if (input.is_open()) {
        cerr << "FILE IS NOT OPEN" << endl;
    }

    //reading int
    int numStory;
    if (!input >> numStory) {
        cerr << "Failed to read int" << endl;
    } 
    string *title = new string[numStory];
    string* nameArr = new string [numStory];
    int* scores = new int[numStory];
    string newLine;
    
    while(getline(file, newLine)){

    }




}

int findMode(){

return -1;
}

void displayScreen(){

}