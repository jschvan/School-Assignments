#ifndef BOOKRECOMMENDER_H_
#define BOOKRECOMMENDER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define BOOK_LIST vector<string>
#define USER_LIST vector<string>
#define USER_RATINGS_MAP map<string, vector<double>>
#define BOOK_AVG_MAP map<string, double>
#define BOOK_AVG_LIST vector<pair<double, string>>

int  indexGet(vector<string> vec, string finderString);
bool pairCompare(const pair<double, string>& pair1, const pair<double, string>& pair2);

class BookRecommender
{
    private:
        BOOK_LIST books;
        USER_LIST users;
        USER_RATINGS_MAP ratings;
        BOOK_AVG_LIST averages;
        BOOK_AVG_MAP averagesMap;
    public:
        BookRecommender();
        BookRecommender(string fileName);
        void printRecommend(string userName);
        void printAverages();
        double getAverage(string bookTitle);
        double getSimilarity(string userName1, string userName2);
        int getBookCount();
        int getUserCount();
        double getUserBookRating(string userName, string bookTitle);
        
};
  

#endif // CARD_H_