#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

void readInput(string file, string *title, string *url, int *score);
void displayScreen();
int findMode();

int main(){
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

    return 0;
}

void readInput(string file, string *title, string *url, int *score){
    fstream input;
    cout << "file name: " << file << endl;
    input.open(file);
    if (!input.is_open()) {
        cerr << "FILE IS NOT OPEN" << endl;
    }

    //reading int
    int numStory;
    string newLine;
    getline(input, newLine);
    numStory = stoi(newLine);
    
   // cout<<"numStory: "<<numStory<<endl;
    // arrays to store information
    string *titles = new string[numStory];
    string *links = new string[numStory];
    int *scores = new int[numStory];
    
    for (int i = 0; i < numStory; i++) {
    titles[i] = ""; // Allocate memory for an empty string
}

    
    int lineNum = 1;
   
    while(getline(input, newLine)){
        // store the title/name/score in appropriate array
        cout<< "executed: " << lineNum << endl;
        if (lineNum % 3 == 1) { // title
            titles[lineNum/3] = newLine;
        } else if (lineNum % 3 == 2) { // url
            links[lineNum/3] = newLine;
        } else { // score
            scores[lineNum/3 - 1] = stoi(newLine);
        }
        lineNum++;
    }
    input.close();

    // remember to deleted at the end
}

int findMode(){

return -1;
}

void displayScreen(){

}