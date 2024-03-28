#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void fact(){
    string fact;
    char choice;
    fstream facts;
    facts.open("facts.txt", ios::in);
    if(!facts){
        cout<<"This feature is disabled for now.\nWhat else can I help you with?\n";
    }
    else{
    cout<<"\nHere's a fun fact for you: \n";
    do{
        getline(facts, fact);
        cout<<endl<<fact<<endl;
        cout<<"\nWould you like to know another fun fact?(Y/N) ";
        cout<<"\nUser: ";
        cin>>choice;
    }while(choice == 'Y');
    cout<<"Okay! What else can I help you with? \n";
    }
}

void joke(){
    string joke;
    string reply;
    char choice;
    fstream jokes;
    jokes.open("jokes.txt", ios::in);
    if(!jokes){
        cout<<"This feature is disabled for now.\nWhat else can I help you with?\n";
    }
    else{
    cout<<"\nHere's a joke: \n";
do{
    if(getline(jokes,joke)){
    getline(jokes, reply);
    cout<<endl<<joke<<endl<<reply<<endl;
    cout<<"\nDo you want to hear another one?(Y/N) ";
    cout<<"\nUser: ";
    cin>>choice;
    }
}while(choice == 'Y');
cout<<"Okay! What else can I help you with? \n";
}
}

void feeling(){
    string feel;
    cout<<"\nUser: ";
    getline(cin, feel);
    for(char &low:feel){
        low = tolower(low);
    }
    if(feel.find("good") != string::npos || feel.find("well") != string::npos || feel.find("fine")!= string::npos
    || feel.find("great")!= string::npos || feel.find("happy")!= string::npos || feel.find("excited")!= string::npos){
        cout<<"That's wonderful to hear! What can I do for you today?\n"; //Positive Sentiment
    }
    else if(feel.find("sad")!= string::npos || feel.find("been better")!= string::npos || feel.find("rough")!= string::npos
    || feel.find("low")!= string::npos || feel.find("under the weather")!= string::npos){
        cout<<"Sorry to hear that. How can I help make your day better?\n"; //Empathy for Negative Sentiment
    }
    else if(feel.find("ok")!= string::npos || feel.find("alright")!= string::npos){
        cout<<"Alright! How can I assist you today? \n";
    }
}
void response(string user, bool &continueconverse){
    for(char &low:user){
        low = tolower(low);
    }
    if(user.find("bye") != string::npos){
        cout<<"Goodbye! Thank you for using ChatBot\n";
        continueconverse = false;
        return;
    }
    else{continueconverse = true;
    if(user.find("hi") != string::npos || user.find("hello") != string::npos  || user.find("hey") != string::npos){
        cout<<"Hello! I'm ChatBot! \n";
    }
    else if(user.find("how are you") != string::npos || user.find("feel") != string::npos){
        cout<<"I am just a software, and therefore not sentient or capable of feelings or emotions.\nHow are you today?\n";
        feeling();
    }
    else if(user.find("do") != string::npos || user.find("doing") != string::npos || user.find("perform") != string::npos 
    || user.find("functions") != string::npos || user.find("tasks") != string::npos){
        cout<<"I'm capable of performing the following tasks: \n";
        cout<<"Telling a joke to cheer you up\n";
        cout<<"Telling you a fun fact you might not have heard of\n";
    }
    else if(user.find("joke") != string::npos || user.find("funny") != string::npos || user.find("laugh") != string::npos){
        joke();
    }
    else if(user.find("fact") != string::npos || user.find("curious") != string::npos || user.find("fun fact") != string::npos){
        fact();
    }
    else if(user.find("thanks") != string::npos || user.find("ty") != string::npos || user.find("thank you") != string::npos ){
        cout<<"You're welcome!\n";
    }
    else{
        cout<<"Sorry I didn't get that. Please rephrase so I can assist you to the best of my abilities.\n";
    }
    }
} 

int main(){
    bool condition = true;
    string user_resp;
    cout<<"\t\t.....Say Hi to begin chat......\t\t\n";
    while(condition){
    cout<<endl<<"User: ";
    cin.clear();
    fflush(stdin);
    getline(cin,user_resp);
    response(user_resp, condition);
    }
}