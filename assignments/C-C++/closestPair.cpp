#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


struct point
{
    double x;
    double y;
};

double closestPair(string filename);
double dist(point pointA, point pointB);

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename){
    fstream infile(filename); //creates file stream based on file passed to function
    string input; //creates general purpose string to take in input from the file
    getline(infile, input); //takes the first line of the file to determine the size of the data set
    int size = stoi(input); //stores size of dataset in integer variable
    
    int b = sqrt(size); //determines dimension of spatial hash table
    double mathB = b;
    double portion = 1/mathB;
    vector<vector<vector<point>>> map(b, vector<vector<point>>(b, vector<point>(0)));
    double leastDist = 1;
    while(infile >> input){ //takes data from file and adds it to spacial hash map
        point inputPoint; //used to add point to vector each loop
        
        inputPoint.x = stod(input);
        infile >> input;
        inputPoint.y = stod(input);
        
        int xPos = inputPoint.x/portion;
        int yPos = inputPoint.y/portion;
        
        //cout << "point at x: " << inputPoint.x << " y: " << inputPoint.y << " belongs in sector " << xPos << "," << yPos << endl;
        map[xPos][yPos].push_back(inputPoint);
    }    
        for(int i = 0; i < b; i++){ //nested loop to run through each square of the hash table
            for(int j = 0; j < b; j++){
                for(int k = 0; k < map[i][j].size(); k++){
                    point testPoint = map[i][j][0];//take the top item of the vector and compare
                    //compare to all other items in same vector
                    for(int l = 1; l < map[i][j].size(); l++){
                        if((dist(testPoint, map[i][j][l])) < leastDist){
                            leastDist = dist(testPoint, map[i][j][l]);
                        }  
                    }
                    //compare to north vector
                    if(j-1 >= 0){
                        for(int l = 0; l < map[i][j-1].size(); l++){
                            if((dist(testPoint, map[i][j-1][l])) < leastDist){
                                leastDist = dist(testPoint, map[i][j-1][l]);
                            }      
                        }
                    }
                    //compare to northeast vector
                    if(j-1 >= 0 && i+1 < b){
                        for(int l = 0; l < map[i+1][j-1].size(); l++){
                            if((dist(testPoint, map[i+1][j-1][l])) < leastDist){
                                leastDist = dist(testPoint, map[i+1][j-1][l]);
                            }      
                        }
                    }
                    //compare to east vector
                    if(i+1 < b){
                        for(int l = 0; l < map[i+1][j].size(); l++){
                            if((dist(testPoint, map[i+1][j][l])) < leastDist){
                                leastDist = dist(testPoint, map[i+1][j][l]);
                            }      
                        }
                    }
                    //compare to southeast vector
                    if(i+1 < b && j+1 < b){
                        for(int l = 0; l < map[i+1][j+1].size(); l++){
                            if((dist(testPoint, map[i+1][j+1][l])) < leastDist){
                                leastDist = dist(testPoint, map[i+1][j+1][l]);
                            }      
                        }
                    }
                    //compare to south vector
                    if(j+1 < b){
                        for(int l = 0; l < map[i][j+1].size(); l++){
                            if((dist(testPoint, map[i][j+1][l])) < leastDist){
                                leastDist = dist(testPoint, map[i][j+1][l]);
                            }      
                        }
                    }
                    //compare to southwest vector
                    if(j+1 < b && i-1 >= 0){
                        for(int l = 0; l < map[i-1][j+1].size(); l++){
                            if((dist(testPoint, map[i-1][j+1][l])) < leastDist){
                                leastDist = dist(testPoint, map[i-1][j+1][l]);
                            }      
                        }
                    }
                    //compare to west vector
                    if(i-1 >= 0){
                        for(int l = 0; l < map[i-1][j].size(); l++){
                            if((dist(testPoint, map[i-1][j][l])) < leastDist){
                                leastDist = dist(testPoint, map[i-1][j][l]);
                            }      
                        }
                    }
                    //compare to northwest vector
                    if(i-1 >= 0 && j-1 >= 0){
                        for(int l = 0; l < map[i-1][j-1].size(); l++){
                            if((dist(testPoint, map[i-1][j-1][l])) < leastDist){
                                leastDist = dist(testPoint, map[i-1][j-1][l]);
                            }      
                        }
                    }
                    map[i][j].erase(map[i][j].begin());
                }
                    
            }
        }
        
    
    
    return leastDist;

}

double dist(point pointA, point pointB){
    double x1 = pointA.x;
    double y1 = pointA.y;
    double x2 = pointB.x;
    double y2 = pointB.y;
    double distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    return distance;
}
