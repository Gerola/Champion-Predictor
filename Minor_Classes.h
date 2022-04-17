/*
        Author: Matthew Gerola
        Class: Cpts 315, Spring 2022; Course Project
        Programming Assignment: Course Project
        Date: April 29, 2022
        Description: Report
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class for the past champions only the vector and the year
class Past_Champions
{
public:
    string team_name;//team name to be used to know if the predictions are correct
    vector<double> stats_for_team;//stats to be used in the similarity calculation
};
//Used for the current team for stats, name and total similarity
class Current_Teams
{
    public:
    string team_name;//name
    vector<double> stats_for_team;//stats
    double similarity;//total similarity
};

//Used to place teams in the correct list
class Team_Conference
{
public:
    char conference;//conference the team plays in
    string name;//team name
};


class future_Champ
{
public:
    string name;//name to search
    vector<Current_Teams> stats_past_Years_Three;//will push back all the stats then get the 
};

