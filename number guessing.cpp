#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    int  number , guess , attempts=0;
    const int LOWER =1;
    const int UPPER =100;

    //Now lets generate a random number
    //we use the current time so you get a different number each run.
    srand(time(0));

    //Generate a Random Number between LOWER and UPPER
    number= rand()%(UPPER - LOWER + 1) + LOWER;
    
    cout<<"Hello there! Let's play a guessing game. "<<endl;
    cout<<"I am thinking a number between  "<< LOWER << " and " << UPPER << "."<< "And you have to guess it "<<endl;
    do {
        cout <<" what's your guess : ";
        cin >> guess;
        attempts++;

        if(guess > number ){
            cout<<" Your guess is too high ! go lower and try again ."<<endl;
        }
        else if(guess < number ){
            cout<<" Your guess is too low! go higher and try again. "<<endl;
        }
        else {
            cout<< " Congratulations! You guessed the  number "<<number<<" " << "in"<<" "<<attempts <<" "<<"attempts ."<<endl;
        }
        
    }
    while(guess != number);
    cout<<"Hope you had fun."<<endl;

    return 0;

}