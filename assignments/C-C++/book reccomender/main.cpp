#include "BookRecommender.h"
using namespace std;


int main(int argc, char* argv[])
{
    //takes in command line argument for file name
    BookRecommender bookRec(argv[1]);
    
    string userInput;
    string user;

    while(userInput!="quit"){
        cin >> userInput;
        if(userInput == "recommend"){
            cin >> user;
            //prints recommendations for given user
            bookRec.printRecommend(user);
            
        }
        else if(userInput == "averages"){
            //prints out books sorted by average rating
            bookRec.printAverages();
        }
    }
    
    return 0;
}