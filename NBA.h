/*
        Author: Matthew Gerola
        Class: Cpts 315, Spring 2022; Course Project
        Programming Assignment: Course Project
        Date: April 29, 2022
        Description: Report
*/

#include <math.h>
#include <fstream>
#include "Minor_Classes.h"

using namespace std;

class Predict_Champ
{
public:
    Predict_Champ()
    {
        this->place_In_Champ_Calculations = 0;
    }
    ~Predict_Champ()
    {
        //Clear all the lists that were used in the process....
        this->past_championship_teams.clear();
        this->list_of_team_names_conference.clear();
        this->eastern_Conference_Teams.clear();
        this->western_Conference_Teams.clear();
        this->average_of_past_years.clear();
    }
    void Run_Program()
    {
        this->get_champion_teams();//Get all past champions
        this->get_Team_Conference_Info();//Get conference information
        this->get_Stats_Zero_One();//Get stats for the first year
        this->get_Stats_For_Team("2001-2002_Stats.txt");//Get stats all other years
        this->get_Stats_For_Team("2002-2003_Stats.txt");
        this->get_Stats_For_Team("2003-2004_Stats.txt");
        this->get_Stats_For_Team("2004-2005_Stats.txt");
        this->get_Stats_For_Team("2005-2006_Stats.txt");
        this->get_Stats_For_Team("2006-2007_Stats.txt");
        this->get_Stats_For_Team("2007-2008_Stats.txt");
        this->get_Stats_For_Team("2008-2009_Stats.txt");
        this->get_Stats_For_Team("2009-2010_Stats.txt");
        this->get_Stats_For_Team("2010-2011_Stats.txt");
        this->get_Stats_For_Team("2011-2012_Stats.txt");
        this->get_Stats_For_Team("2012-2013_Stats.txt");
        this->get_Stats_For_Team("2013-2014_Stats.txt");
        this->get_Stats_For_Team("2014-2015_Stats.txt");
        this->get_Stats_For_Team("2015-2016_Stats.txt");
        this->get_Stats_For_Team("2016-2017_Stats.txt");
        this->get_Stats_For_Team("2017-2018_Stats.txt");
        this->get_Stats_For_Team("2018-2019_Stats.txt");
        this->get_Stats_For_Team("2019-2020_Stats.txt");
        this->get_Stats_For_Team("2020-2021_Stats.txt");
        this->still_Past_Years = false;//No longer in the past
        this->get_Stats_For_Team("2021-2022_Stats.txt");//Current teams
        this->future_Champ_finding = true;//Now future
        this->get_Sim_and_Champ_Future();//Function for stats and the predictions
        this->get_Confidence_of_Predications();//get the confidence
        this->print_Final_Teams();//print the results
}

private:
    //Functions that the user doesn't need to see...
    void get_champion_teams();//populate the list of past champions only the names for now...
    void get_Team_Conference_Info();//get what team goes where...
    void get_Stats_Zero_One();//get the stats for the first team...
    void get_Stats_For_Team(string file);//Get the stats for the second year included
    //Used to get the stats for the following year...
    void get_Sim_and_Champ_Future();//don't need to get the stats, so get average and then call the sim and playoff functions...
    void get_Confidence_of_Predications();

    //Print the output of the program
    void print_Final_Teams();


    //Similarity function
    void calculate_Similarity();

    //Simulate Playoff series
    void playoff_Sim();

    //get how many points scored for a particular team for that game....
    int get_Points_For_Team(double twos, double threes,double free_throws, double two_per, double three_per, double free_per);

    //Used to get the winner from two teams in that series...
    Current_Teams get_winner_From_two(Current_Teams &one, Current_Teams &two);

    //lists for reference sake...
    vector<Past_Champions> past_championship_teams;//used to to know the stats and the champ from the past
    vector<Team_Conference> list_of_team_names_conference;//to know where to place teams...
    
    //used for the confidence levels...
    int champ_team_in_Final_Six[20];//used to find the confidence
    int champ_team_Pred_Six[20];
    double confidence_team_in_Final_Six;//actual confidence levels from past calulations
    double confidence_team_Pred_Champ;
    bool still_Past_Years = true;//know if past is still being looked at
    bool future_Champ_finding = false;//to know if the future is being predicted
    int place_In_Champ_Calculations;//know what year to look place in the past champions list, and how far to go in the sim calulations for the past teams...


    //Final Four teams array used in the past and present teams...
    Current_Teams final_Six_west[3];
    Current_Teams final_Six_east[3];

    //Used as temp places to put the vectors to be compared from the past years...
    //This is so the stats don't need to be normalized and their stats used later in the task
    vector<double> average_of_past_years;

    //Vectors that are used in the stats getting functions...
    vector<Current_Teams> eastern_Conference_Teams;
    vector<Current_Teams> western_Conference_Teams;



    //Used in the printing function of the task...
    string final_teams_current_year[6];//printed out later...
    string champion_current_year;//the winning team
    //Used in the predicted stats and champ for the next year...
    string final_teams_next_year[6];
    string champion_next_year;
};