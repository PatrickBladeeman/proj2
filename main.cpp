#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;

struct Story {
    string title;
    string link;
    int score;
};
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
    
    int numStory;
    string newLine;
    getline(input, newLine);
    numStory = stoi(newLine);
    Story stories[numStory];
    
    int lineNum = 1;
   
    while(getline(input, newLine)){
        // store the title/name/score in appropriate array
        cout<< "executed: " << lineNum << endl;
        if (lineNum % 3 == 1) { // title
            //titles[lineNum/3] = newLine;
            stories[lineNum/3].title = newLine;
        } else if (lineNum % 3 == 2) { // url
            //links[lineNum/3] = newLine;
            stories[lineNum/3].link = newLine;
        } else { // score
            //scores[lineNum/3 - 1] = stoi(newLine);
            stories[lineNum/3 - 1].score = stoi(newLine);
        }
        lineNum++;
    }
    input.close();
    
    for (int i = 0; i < numStory; i++) {
    cout << "Element " << i << ":" << endl;
    cout << "title: " << stories[i].title << endl;
    cout << "link: " << stories[i].link << endl;
    cout << "score: " << stories[i].score <<  endl;
    cout << std::endl; // Add an empty line for separation
}
    // remember to free memory with deleted at the end
}

int findMode(){

return -1;
}

void displayScreen(){

}