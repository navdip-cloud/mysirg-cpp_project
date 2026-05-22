//Challenge your word skills (mysirg project) using modularised approach(sub-task, with the help of different functions) 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

vector<string> load_words() //this function will load words from file (file handling) and put it in vector(STL) (or simply array)
{
    vector<string> words;
    string line;
    ifstream fin("word_list.txt"); //by default reading mode, file given to constructor. fin is an object of ifstream
    while(getline(fin,line))
    {
        if(line.length()>0)
            words.push_back(line);
    }
    return words;
}
string choose_word() //this function will choose word randomly from the vector of strings(words)
{
    vector<string> word_list;
    word_list=load_words();
    srand(time(0));
    int random_index=rand()%word_list.size(); //to get random index from 0 to 9 range (here assume size = 10)
    return word_list[random_index];
}
bool display_word(string word, const vector<char> &guessed_letters) //which will display word and dash dash -------- (length of words)
{
    bool winStatus=true;
    for(char ch:word)
    {
        if(find(guessed_letters.begin(),guessed_letters.end(),ch)!=guessed_letters.end())
            cout<<ch<<" ";
        else
        {
            cout<<"_ ";
            winStatus=false;
        }
    }
    cout<<endl;
    return winStatus;
}
int main()
{
    string word_to_guess = choose_word();
    bool win_status=false;
    int lives=6;
    char guess;
    vector <char> guessed_letters;
    cout<<"Welcome to Hangman!"<<endl;
    while(lives>0)
    {
        cout<<"Lives Remaining: "<<lives<<endl;
        win_status=display_word(word_to_guess, guessed_letters);
        if(win_status)
        {
            cout<<"Congratulations! You guessed the word: "<<word_to_guess<<endl;
            break;
        }
        
        cout<<"Guess the letter : ";
        cin>>guess;
        guessed_letters.push_back(guess);

        if(word_to_guess.find(guess)!=string::npos) //npos - large value static variable in class string
        {
            cout<<"Correct Guess! "<<endl; //this find member fun. will return the index of the matched character
        }
        else
        {
            cout<<"Incorrect Guess! "<<endl;
            lives--;
        }
    }
    if(lives==0)
    {
        cout<<"You lost! The word was: "<<word_to_guess<<endl;
    }
    cout<<endl;
    return 0;
}