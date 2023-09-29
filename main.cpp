// File Name: project1_hz6973_yyyyy.cpp
//
// Authors: Regina Zhou, Bryan Zhao
// Date: 9/29/2023
// Assignment Number 1
// CS 105C Fall 2023
// Instructor: Dr. Palacios
//
// Description of program: this program reads an input file that stores the 
// information of numerous stories, and find the mode of the stories, then 
// display the mode and appropriate stories.
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;

static int LINES_PER_STORY = 3; // number of lines a story data occupies
static int STORIES_NO_MODE = 5; // number of stories to display when no mode
struct Story { 
    string title;
    string link;
    int score;
}; // structure of each story that stores its data

Story* readInput(string file, int &numElem);
void displayScreen(int mode, int numStory, Story *stories);
int findMode(Story *stories, int numStory);

/* we need: 
 x0. make sure code is right and meets the specs： pointer notation vs array notation?
 x1. design doc
 2. test cases
 3. programming log; fill in eid to header and design doc
 x4. format the code so that it meets the style guide
*/

/*
 * main: controls the entire process of reading file/writing
 * to screen and whether the user wants another round.
 *
 * returns: 0 when finished
 * 
 * Bryan Zhao drives this function
 */
int main(){
    char nextRound; // char stores whether the user chooses another round
    do {
    string fileName; // string stores name of file
    cout << "Enter name of the file:" << endl;
    cin >> fileName;
    int numStory; // numeric value stores total number of stories in file
    fstream input(fileName);
    if (input.is_open()) {
        input.close(); // Close the file after checking
        Story *stories = readInput(fileName, numStory); // stores array of stories
        int mode = findMode(stories, numStory); // integer store mode of stories
        displayScreen(mode, numStory, stories);
    } else {
        cerr << "File DNE or cannot be opened." << endl;
    }
    cout << "Another file? Y for yes" << endl;
    cin >> nextRound;
    } while (nextRound == 'Y');
    return 0;
}


/*
 * readInput: read the input file into the dynamic array of stories
 * string file: name of the file
 * int &numStory: numer of stories the input file contains
 * 
 * returns: array of struct Story that contains the data of all stories
 * 
 * Regina Zhou drives this function
 */
Story* readInput(string file, int &numStory){
    fstream input;
    input.open(file);
    
    string newLine; // string stores one line of the file
    getline(input, newLine);
    numStory = stoi(newLine);
    Story *stories = new Story[numStory];

    int lineNum = 1; // int stores the total line of input file
    while(getline(input, newLine)){
        // store the title/name/score in appropriate array
        if (lineNum % LINES_PER_STORY == 1) { // title
            stories[lineNum/LINES_PER_STORY].title = newLine;
        } else if (lineNum % LINES_PER_STORY == 2) { // url
            stories[lineNum/LINES_PER_STORY].link = newLine;
        } else { // score
            stories[lineNum/LINES_PER_STORY - 1].score = stoi(newLine);
        }
        lineNum++;
    }
    input.close();
    
    // for (int i = 0; i < numStory; i++) {
    // cout << "Element " << i << ":" << endl;
    // cout << "title: " << stories[i].title << endl;
    // cout << "link: " << stories[i].link << endl;
    // cout << "score: " << stories[i].score <<  endl;
    // cout << std::endl; // Add an empty line for separation
    // }
    // remember to free memory with deleted at the end?
    return stories;
}

/*
 * findMode: fines the mode(number that occurs the most frequent) amongst the
 * scores of all the stories
 * Story *stories: array of struct Story that contains the data of all stories 
 * int numStory: number of stories the input file contains
 * 
 * returns: mode of all the scores
 * 
 * Bryan Zhao drives this function
 */
int findMode(Story *stories, int numStory){ // accepts a pointer to array of 
                                            //structures?
    int *scores = new int[numStory]; // int array stores all story scores

    for(int i = 0; i < numStory; i++){
        scores[i] = stories[i].score;
    }

    sort(scores, scores + numStory); 
    int mode = 0; // int stores final mode value
    int modeCount = 0; // int stores frequency of mode
    int currNum = scores[0]; // int store the current number
    int currCount = 1; // int stores the frequency of current number

    for(int i = 1; i < numStory; i++){
        if(scores[i] == currNum){ // if the current number same as previous num
            currCount++;
            if(currCount > modeCount){
                modeCount = currCount;
                mode = currNum;
            }
        } else { // current number differ from previous num
            currNum = scores[i];
            currCount = 1;
        }
    }
   
return mode > 1? mode : -1;
}

/*
 * displayScreen: display the data of stories to the screen
 * int mode: mode of all the scores
 * int numStory: number of stories the input file contains
 * Story *stories: struct Story that contains the data of all stories 
 * 
 * Regina Zhou drives this function
 */
void displayScreen(int mode, int numStory, Story *stories){
    
    if(mode == -1){
        cout << "Mode: No mode was found." << "\n" << endl;

        int count = 0;
        while(count < STORIES_NO_MODE && count < numStory){
            cout << stories[count].title << endl;
            cout << stories[count].link << "\n" << endl;
            count++;
        }   
        
    } else {
        cout << "Mode: " << mode << "\n" << endl;

        int count = 0;
        while(count < numStory){
            if(stories[count].score == mode){
                cout << stories[count].title << endl;
                cout << stories[count].link << "\n" << endl;
            }
            count++;
        }
    }

    
}