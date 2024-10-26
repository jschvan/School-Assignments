#include "BookRecommender.h"

//empty default constructor
BookRecommender::BookRecommender(){
        
}

//primary constructor that takes in file name as argument
BookRecommender::BookRecommender(string fileName){
    string name, book, stringRating;
    ifstream file(fileName);

    //ensures file can be opened, gives error and quits if can't
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        exit(1);
    }
    
    set<string> initialBookList;
    set<string> initialNameList;
    pair<double, string> tempPair;
    

    //collects names and books and adds to set
    while (getline(file, name) && getline(file, book) && getline(file, stringRating)) {
        //takes off extra character at eol
        name.pop_back();
        book.pop_back();
        stringRating.pop_back();
        
        //adds names and books to sets
        initialNameList.emplace(name); 
        initialBookList.emplace(book);
    }
    
    //turns sets into vectors
    for (auto& it : initialBookList) {
        books.push_back(it);    
    }
    for (auto& it : initialNameList) {
        users.push_back(it);
    }
    
    //creates empty vector of zeros of quantity equal to the number of books
    vector<double> emptyVec;
    for(int i = 0; i < books.size(); i++){
        emptyVec.push_back(0);
    }
    
    //runs through the name list and adds the name with
    //the empty vector of zeros as members of the rating map
    for(int i = 0; i < users.size(); i++){
        ratings.emplace(users[i], emptyVec);
    }
    
    //begins new file stream and runs through file again,
    //adding rating values to the item vectors of the map
    ifstream file2(fileName);
    while (getline(file2, name) && getline(file2, book) && getline(file2, stringRating)) {
        name.pop_back();
        book.pop_back();
        stringRating.pop_back();
        
        double rating = stoi(stringRating);
        int index = indexGet(books, book);
        ratings[name][index] = rating;
    }
    
    //averages
    for(int i = 0; i < books.size(); i++){
        double sum = 0;
        double count = 0;

        for(int n = 0; n < users.size(); n++){
            if(ratings[users[n]][i] != 0){
                sum += ratings[users[n]][i];
                count ++;
            }
        }
        double average = sum/count;
        averagesMap.emplace(books[i], average);
        
        tempPair.first = average;
        tempPair.second = books[i];
        
        averages.push_back(tempPair);
    }
    sort(averages.begin(), averages.end(), pairCompare);
    
}


void BookRecommender::printRecommend(string userName){
    int checker = 0;

    //ensures given user is in list of users
    for(int i = 0; i < users.size(); i++){
        if(userName == users[i]){
            checker = 1;
        }
    }

    //if user is in the list, recommends
    if(checker == 1){
        vector<pair<double, string>> recPairs;
        pair<double, string> tempPair;
    
        
        //finds reccomender score for each user
        for(int i = 0; i < users.size(); i++){
            double recScore = 0;
            
            for(int n = 0; n < books.size(); n++){
                if(userName!=users[i]){
                    recScore += ratings[userName][n]*ratings[users[i]][n];
                }
            }
            
            tempPair.first = recScore;
            tempPair.second = users[i];
            if(userName!=users[i]){
                recPairs.push_back(tempPair);
            }
        }
        
        sort(recPairs.begin(), recPairs.end(), pairCompare); 
        //sort(recPairs.begin(), recPairs.end()); 
        
        //finds top 3 users 
        vector<string> top3;
        for(int i = 0; i < 3; i++){
            top3.push_back(recPairs[i].second);
            
        }
        
        
        //finds average of top 3 users
        vector<double> recScores(books.size(), 0);
        for(int i = 0; i < books.size(); i++){
            double sum = 0;
            double count = 0;
    
            for(int n = 0; n < top3.size(); n++){
                if(ratings[top3[n]][i] != 0){
                    sum += ratings[top3[n]][i];
                    count ++;
                }
            }
            double average;
            if(count != 0){
                average = sum/count;
            }
            else{
                average = 0;
            }
            
            recScores[i] = average;
        }
        
    
        vector<pair<double, string>> avgRec;
        
        //print out book with average reccomended score
        for(int i = 0; i < books.size(); i++){
            tempPair.first = recScores[i];
            tempPair.second = books[i];
            if(tempPair.first != 0){
                avgRec.push_back(tempPair);
            }
            
        }
        
        sort(avgRec.begin(), avgRec.end(), pairCompare);
        for(int i = 0; i < avgRec.size(); i++){
            if(avgRec[i].first > 0){
                cout << avgRec[i].second << " ";
                cout << fixed<< setprecision(2) << avgRec[i].first  << "\n";
            }
        }
    }
    //if given user not in list, prints out averages
    else{
        for(int i = 0; i < books.size(); i++){
            cout << averages[i].second << " " << fixed<< setprecision(2) << averages[i].first << endl;
        }
        
    }
    
}

void BookRecommender::printAverages(){
    for(int i = 0; i < books.size(); i++){
            cout << averages[i].second << " " << fixed << setprecision(2)<< averages[i].first << endl;
    }
       
}

double BookRecommender::getAverage(string bookTitle){
    return averagesMap[bookTitle];
}
double BookRecommender::getSimilarity(string userName1, string userName2){
    double recScore = 0;
    for(int n = 0; n < books.size(); n++){
        recScore += ratings[userName1][n]*ratings[userName2][n];
    }
    return recScore;
}
int BookRecommender::getBookCount(){
   return books.size(); 
}
int BookRecommender::getUserCount(){
   return users.size(); 
}
double BookRecommender::getUserBookRating(string userName, string bookTitle){
    return ratings[userName][indexGet(books, bookTitle)];
}

//function to return index of string in vector
int indexGet(vector<string> searchVector, string finderString)
{
    auto it = find(searchVector.begin(), searchVector.end(), finderString);
  
    if (it != searchVector.end()) 
    {
        int index = it - searchVector.begin();
        return index;
        
    }
    else {
        cout << "Error in index search" << endl;
        return 0;
    }
}

//compare function for sorting of pairs
//sorts first by larger double value, then by alphabetical order
bool pairCompare(const pair<double, string>& pair1, const pair<double, string>& pair2){
    if(pair1.first != pair2.first){
        return pair1.first > pair2.first;
    }
    else{
        return pair1.second < pair2.second;
    }
    
}