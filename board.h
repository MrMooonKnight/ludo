#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <iomanip>
#include <list>

using namespace std;




void disclaimer(){
        
            cout << "\033[1;" << 40 << "m" << "\033[1;" << 31 << "m" << "\033[1;" << 53 << "m" << "|" << setw(106) << right  << "|" << "\033[0m" << endl;}

void header(){
    disclaimer();
    // cout << "\033[1;" << 100 << "m" << "\033[1;" << 40 << "m";
     cout << "\033[1;" << 40 << "m" << "\033[1;" << 40 << "m";
    cout << "|                                                                                                         |" << endl;
    cout << "|                    ██▓     █    ██ ▓█████▄  ▒█████       ▄████  ▄▄▄       ███▄ ▄███▓▓█████              |" << endl;
    cout << "|                   ▓██▒     ██  ▓██▒▒██▀ ██▌▒██▒  ██▒    ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀              |" << endl;
    cout << "|                   ▒██░    ▓██  ▒██░░██   █▌▒██░  ██▒   ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███                |" << endl;
    cout << "|                   ▒██░    ▓▓█  ░██░░▓█▄   ▌▒██   ██░   ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄              |" << endl;
    cout << "|                   ░██████▒▒▒█████▓ ░▒████▓ ░ ████▓▒░   ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒             |" << endl;
    cout << "|                   ░ ▒░▓  ░░▒▓▒ ▒ ▒  ▒▒▓  ▒ ░ ▒░▒░▒░     ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░             |" << endl;
    cout << "|                   ░ ░ ▒  ░░░▒░ ░ ░  ░ ▒  ▒   ░ ▒ ▒░      ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░             |" << endl;
    cout << "|                     ░ ░    ░░░ ░ ░  ░ ░  ░ ░ ░ ░ ▒     ░ ░   ░   ░   ▒   ░      ░      ░                |" << endl;
    cout << "|                       ░  ░   ░        ░        ░ ░           ░       ░  ░       ░      ░  ░             |" << endl;
    cout << "|                                     ░                                                                   |" << endl;
    cout << "|                                                                                                         |" << "\033[0m";
    cout << endl;
    disclaimer();}

void blackBackground() {
    cout << "\033[1;40m";}

void redText() {
    cout << "\033[1;31m";}

void upperLine() {
    cout << "\033[1;53m";}

void yellowBackground(){    
    cout << "\033[1;103m";}

void whiteBackground(){    
    cout << "\033[1;7m";}

void redBackground(){    
    cout << "\033[1;41m";}

void greenBackground(){    
    cout << "\033[1;42m";}

void blueBackground(){    
    cout << "\033[1;44m";}

void blackText(){    
    cout << "\033[1;90m";}

void reset() {
    cout << "\033[0m" << endl;}

void resetNoEnd() {
    cout << "\033[0m";}


    void yellowBox(){
        
        yellowBackground();
        blackText();
        cout  << "  ";
        resetNoEnd();}
    void yellowBoxL(string str = " "){
        
        yellowBackground();
        blackText();
        upperLine();
        cout  << "|" << str;
        resetNoEnd();}

    void whiteBox(string str = " "){
        
        whiteBackground();
        cout  << " " << str;
        resetNoEnd();}
    void whiteBoxL(string str = " "){
        
        whiteBackground();
        upperLine();
        cout  << "|" << str;
        resetNoEnd();}

    void redBoxL(string str = " "){
        
        redBackground();
        blackText();
        upperLine();
        cout  << "|" << str;
        resetNoEnd();}
    void redBox(){
        
        redBackground();
        blackText();
        cout  << "  ";
        resetNoEnd();}

    void greenBox(){
        
        greenBackground();
        blackText();
        cout  << "  ";
        resetNoEnd();}
    void greenBoxL(string str = " "){
        
        greenBackground();
        blackText();
        upperLine();
        cout  << "|" << str;
        resetNoEnd();}

    void blueBox(){
        
        blueBackground();
        blackText();
        cout  << "  ";
        resetNoEnd();}
    void blueBoxL(string str = " "){
        
        blueBackground();
        blackText();
        upperLine();
        cout  << "|" << str;
        resetNoEnd();}



void blueLine(string txt, int num){    
    cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << " " << num <<"\33[0m" << endl;}
void blueLine(string txt, string text1){    
    cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << " " << text1 << "\33[0m" << endl;}
void blueLine(string txt){
    cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << "\33[0m" << endl;}
void blueLineNoEndl(string txt){
    cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << " " << "\33[0m" ;} 

void menuNum(string txt, int num){
    cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| "  << num << ". " << setw(30) << left  <<  txt << "\33[0m" << endl;}

void blankBlueLine(){

    cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << "|" << "\033[1;" << 31 << "m";
    cout << setw(105) << " ";
    cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << "|"<< "\033[0m" << endl;}
void disclaimer(string txt){
    int length;
    length = txt.length();

    int leftW = 53;
    int rightW = 53;

    leftW += length/2;
    rightW -= length/2;

    cout << "\033[1;" << 40     << "m" << "\033[1;" << 31 << "m" << "\033[1;" << 53 << "m";
    cout << "|" << setw(leftW) << right << txt << setw(rightW)  << "|" << "\033[0m" << endl;}
void disclaimer(int n){
    
        cout << "\033[1;" << 40 << "m" << "\033[1;" << 31 << "m" << "\033[1;" << 53 << "m" << "|" ;

        for (int i = 0; i < n; ++i)
        {
            cout << " ";
        }
        cout << "|" << "\033[0m" << endl;}



// IOMANIP AND COLORS AND STUFF
void menu(string txt){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << "\33[0m" << endl;}
void line(string txt, int n){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << n << "\33[0m" << endl;}
void line(string txt, float n){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << n << "\33[0m" << endl;}
void line(string txt, string n){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << n << "\33[0m" << endl;}
void line(string txt, bool n){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(33) << left  <<  txt << n << "\33[0m" << endl;}
    

  
// INPUTTERS
string inputString(string text){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m";
    cout << "| " << text;
    string temp;
    cin >> temp;
    cout << "\033[0m";
    return temp;}
string getlineString(string text){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m";
    cout <<"| " <<text;
    string temp;
    getline(cin , temp);
    cout  << "\033[0m";
    return temp;}
int inputInt(string text){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m";
    cout << text;
    int temp;
    cin >> temp;
    cout << "\033[0m";
    return temp;}

        // void disclaimer(string txt) {
    //     int txtlength = txt.length();
    //     int leftW = length / 2;
    //     int rightW = length / 2;
    //     length % 2 != 0 ? rightW++ : rightW;
    //     leftW += txtlength / 2;
    //     rightW -= txtlength / 2;

    //     blackBackground();
    //     redText();
    //     upperLine();
    //     cout << "|" << setw(leftW) << right << txt << setw(rightW) << "|";
    //     reset();}

    // void footer() {
    //     blackBackground();
    //     redText();
    //     upperLine();
    //     cout << "|" << setw(length) << right << "|";
    //     reset();}

    // void header() {
    //     int txtlength = headerText.length();
    //     int leftW = length / 2;
    //     int rightW = length / 2;
    //     length % 2 != 0 ? rightW++ : rightW;
    //     leftW += txtlength / 2;
    //     rightW -= txtlength / 2;

    //     blackBackground();
    //     redText();
    //     upperLine();
    //     cout << "|" << setw(leftW) << right << headerText << setw(rightW) << "|";
    //     reset();}


    // void display(){
        
    //     // white = 1
    //     // red = 2
    //     // green = 3
    //     // blue = 4
    //     // yellow = 5
    //     // white = 11
    //     // red = 22
    //     // green = 33
    //     // blue = 44
    //     // yellow = 55

    //     int grid[15][15] = {{2,2,2,2,2,2, 11,11,11, 3,3,3,3,3,3},
    //                         {2,1,1,1,1,2, 11,33,33, 3,1,1,1,1,3},
    //                         {2,1,1,1,1,2, 33,33,11, 3,1,1,1,1,3},
    //                         {2,1,1,1,1,2, 11,33,11, 3,1,1,1,1,3},
    //                         {2,1,1,1,1,2, 11,33,11, 3,1,1,1,1,3},
    //                         {2,2,2,2,2,2, 11,33,11, 3,3,3,3,3,3},
                            
    //                         {11,22,11,11,11,11, 33,33,33, 11,11,11,55,11,11},
    //                         {11,22,22,22,22,22, 22,11,55, 55,55,55,55,55,11},
    //                         {11,11,22,11,11,11, 44,44,44, 11,11,11,11,55,11},
                            
    //                         {4,4,4,4,4,4, 11,44,11, 5,5,5,5,5,5},
    //                         {4,1,1,1,1,4, 11,44,11, 5,1,1,1,1,5},
    //                         {4,1,1,1,1,4, 11,44,11, 5,1,1,1,1,5},
    //                         {4,1,1,1,1,4, 11,44,44, 5,1,1,1,1,5},
    //                         {4,1,1,1,1,4, 44,44,11, 5,1,1,1,1,5},
    //                         {4,4,4,4,4,4, 11,11,11, 5,5,5,5,5,5}};



    //     // int grid[15][15] = {{2,2,2,2,2,2, 11,11,11, 3,3,3,3,3,3},
    //     //                     {2,1,1,1,1,2, 11,33,33, 3,1,1,1,1,3},
    //     //                     {2,1,1,1,1,2, 33,33,11, 3,1,1,1,1,3},
    //     //                     {2,1,1,1,1,2, 11,33,11, 3,1,1,1,1,3},
    //     //                     {2,1,1,1,1,2, 11,33,11, 3,1,1,1,1,3},
    //     //                     {2,2,2,2,2,2, 11,33,11, 3,3,3,3,3,3},
                            
    //     //                     {1,2,1,1,1,1, 33,33,33, 1,1,1,5,1,1},
    //     //                     {1,2,2,2,2,2, 22,11,55, 5,5,5,5,5,1},
    //     //                     {1,1,2,1,1,1, 44,44,44, 1,1,1,1,5,1},
                            
    //     //                     {4,4,4,4,4,4, 11,44,11, 5,5,5,5,5,5},
    //     //                     {4,1,1,1,1,4, 44,44,11, 5,1,1,1,1,5},
    //     //                     {4,1,1,1,1,4, 11,44,11, 5,1,1,1,1,5},
    //     //                     {4,1,1,1,1,4, 11,44,44, 5,1,1,1,1,5},
    //     //                     {4,1,1,1,1,4, 44,44,11, 5,1,1,1,1,5},
    //     //                     {4,4,4,4,4,4, 11,41,11, 5,5,5,5,5,5}};

    //     for (int i = 0; i < 15; ++i)
    //     {

    //         for (int j = 0; j < 15; ++j)
    //         {
    //             string str = " ";
                
    //             if (grid[i][j] == 1)
    //             {
    //                 whiteBox();  
    //             }
    //             if (grid[i][j] == 2)
    //             {
    //                 redBox();
    //             }
    //             if (grid[i][j] == 3)
    //             {
    //                 greenBox();
    //             }
    //             if (grid[i][j] == 4)
    //             {
    //                 blueBox();
    //             }
    //             if (grid[i][j] == 5)
    //             {
    //                 yellowBox();
    //             }if (grid[i][j] == 11)
    //             {
    //                 whiteBoxL(str);  
    //             }
    //             if (grid[i][j] == 22)
    //             {
    //                 redBoxL(str);
    //             }
    //             if (grid[i][j] == 33)
    //             {
    //                 greenBoxL(str);
    //             }
    //             if (grid[i][j] == 44)
    //             {
    //                 blueBoxL(str);
    //             }
    //             if (grid[i][j] == 55)
    //             {
    //                 yellowBoxL(str);
    //             }
    //         }
    //             cout << endl;
    //     }







    // }





#endif 