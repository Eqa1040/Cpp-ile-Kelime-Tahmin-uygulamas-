
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;
int main(){
    const string words[] = {"program","developer","computer","keyboard","mouse"};
    const int wordCount = sizeof(words)/sizeof(words[0]);
    srand(static_cast<unsigned int>(time(0)));
    string secretWord = words[rand() % wordCount];
    string guessedWord(secretWord.length(),'-');

    int attemps = 6;
    char guess;
    bool isGuessed = false ; 

    cout<<"welcome to word guessing game !"<<endl;
    cout<<"you have " << attemps <<" attemps to guess the word."<<endl;

    while(attemps>0 && !isGuessed){
        cout<<"\nCurrent Word: " << guessedWord <<endl;
        cout<<"Attemps left:"<<attemps<<endl;
        cout<<"enter a letter:";
        cin>>guess;

        bool found = false;
        for(size_t i = 0 ; i<secretWord.length();i++){
            if(secretWord[i]==guess && guessedWord[i]=='-'){
                guessedWord[i]=guess;
                found = true;
            }
        }
        if(!found){
            attemps--; 
            cout<<"Wrong guess ! You lost an attemp."<<endl;
        }else{
            cout<<"good guess !"<<endl;
        }
        if(guessedWord == secretWord){
            isGuessed = true;
        }
    }
    if(isGuessed){
        cout<<"\nCongratulations ! You guessed the word:"<<secretWord<<endl;
    }else{
        cout<<"\nGame over ! the correct word was:"<<secretWord<<endl;
    }
    return 0 ;
}
