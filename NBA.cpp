/*
        Author: Matthew Gerola
        Class: Cpts 315, Spring 2022; Course Project
        Programming Assignment: Course Project
        Date: April 29, 2022
        Description: Refer to the README
*/

#include "NBA.h"

void Predict_Champ::get_champion_teams()
{
    Past_Champions placeholder;//only a placeholder
    vector<double> nothing;//only a placeholder
    placeholder.stats_for_team = nothing;
    fstream Champion;
    Champion.open("Past_Champions.txt",std::ios::in);
    string temp = "", team = "";
    int place = 0;
    while(!Champion.eof())
    {
        getline(Champion,temp,'\n');//get each champion...
        while(temp[place] != ':')
        {
            place++;//increase place until reach the team name
        }
        place++;//increase the get out of : character
        while(place < temp.length())
        {
            team += temp[place];//add to the team name
            place += 1;
        }
        placeholder.team_name = team;//set as the team name
        this->past_championship_teams.push_back(placeholder);//push back the team name and the stats will be added later.
        temp.clear();//clear the temp and team string to be used again.
        team.clear();
        place = 0;
    }
    Champion.close();//close the file
}
void Predict_Champ::get_Team_Conference_Info()
{
    Team_Conference placeholder;
    fstream Conference;
    Conference.open("Teams_and_Conference.txt",std::ios::in);//open the file to be read
    string temp = "", team = "";//get some string
    char confernce_placement = '\0';//char for the conference
    int place = 0;//place in the string
    while(!Conference.eof())//while still things to be read in
    { 
        getline(Conference,temp,'\n');//get the team name
        while(temp[place] != ',')//while not at a comma meaning team name not done yet
        {
            team += temp[place];
            place +=1;
        }
        place+= 1;//only need to go one more space to get the conference
        confernce_placement = temp[place];//set the conference
        placeholder.conference = confernce_placement;//set to the placeholder
        placeholder.name = team;//set the team name

        this->list_of_team_names_conference.push_back(placeholder);//pushback to the desired list
        temp.clear();//clear the strings for temp and team to be used again
        team.clear();
        place = 0;
    }
    Conference.close();//close the file
}

//Work on this....
void Predict_Champ::get_Sim_and_Champ_Future()
{
    vector<future_Champ> future_champion_vector;
    fstream First_Year;
    future_Champ champion_temp;
    Current_Teams team_to_be_placed;
    First_Year.open("2019-2020_Stats.txt",std::ios::in);
    vector<double> stats;
    double value = 0.0;
    string team_name = "", inital_stats = "";
    for(int pop = 0; pop < 26; pop++)
    {
        stats.push_back(0.0);
    }
    getline(First_Year,team_name,'\n');
    while(!First_Year.eof())
    {
        getline(First_Year,team_name,'\n');
        for(int s = 0; s < 26; s++)
        {
            if(s != 25)
            {
                getline(First_Year,inital_stats,',');
                value = stold(inital_stats);
                stats[s] = value;
            }
            else
            {
                getline(First_Year,inital_stats,'\n');
                value = stold(inital_stats);
                stats[s] = value;
            }
        }
        champion_temp.name = team_name;//set the name for the larger list
        team_to_be_placed.stats_for_team = stats;//set the stats for this year
        champion_temp.stats_past_Years_Three.push_back(team_to_be_placed);//push this year onto this team's stats
        future_champion_vector.push_back(champion_temp);//push back the first team onto the future champ vector
        champion_temp.stats_past_Years_Three.clear();
     }
    First_Year.close();
    fstream Year_Two;
    Year_Two.open("2020-2021_Stats.txt",std::ios::in);
    getline(Year_Two,team_name,'\n');
    while(!Year_Two.eof())
    {
        getline(Year_Two,team_name,'\n');
        for(int s = 0; s < 26; s++)
        {
            if(s != 25)
            {
                getline(Year_Two,inital_stats,',');
                value = stold(inital_stats);
                stats[s] = value;
            }
            else
            {
                getline(Year_Two,inital_stats,'\n');
                value = stold(inital_stats);
                stats[s] = value;
            }
        }
        team_to_be_placed.stats_for_team = stats;
        for(int find = 0; find < future_champion_vector.size(); find++)
        {
            if(team_name == future_champion_vector[find].name)
            {
                future_champion_vector[find].stats_past_Years_Three.push_back(team_to_be_placed);
                find = future_champion_vector.size() + 1;
            }
        }

    }
    Year_Two.close();
    fstream Year_Three;
    Year_Three.open("2021-2022_Stats.txt",std::ios::in);
    getline(Year_Three,team_name,'\n');
    while(!Year_Three.eof())
    {
        getline(Year_Three,team_name,'\n');
        for(int s = 0; s < 26; s++)
        {
            if(s != 25)
            {
                getline(Year_Three,inital_stats,',');
                value = stold(inital_stats);
                stats[s] = value;
            }
            else
            {
                getline(Year_Three,inital_stats,'\n');
                value = stold(inital_stats);
                stats[s] = value;
            }
        }
        team_to_be_placed.stats_for_team = stats;
        for(int find = 0; find < future_champion_vector.size(); find++)
        {
            if(team_name == future_champion_vector[find].name)
            {
                future_champion_vector[find].stats_past_Years_Three.push_back(team_to_be_placed);
                find = future_champion_vector.size() + 1;
            }
        }
    }
    Year_Three.close();
    //Now all the stats have been found, so now the predicted stats for the next year....
    double perc_one = 0.0, perc_two = 0.0, new_stat = 0.0;
    char conference_place = '\0';
    for(int teams_stats = 0; teams_stats < future_champion_vector.size(); teams_stats++)
    {
        for(int stat = 0; stat < 26; stat++)
        {
            perc_one = future_champion_vector[teams_stats].stats_past_Years_Three[1].stats_for_team[stat] / future_champion_vector[teams_stats].stats_past_Years_Three[0].stats_for_team[stat];
            perc_two = future_champion_vector[teams_stats].stats_past_Years_Three[2].stats_for_team[stat] / future_champion_vector[teams_stats].stats_past_Years_Three[1].stats_for_team[stat];
            perc_one = (perc_one + perc_two) / 2;
            new_stat = perc_one * future_champion_vector[teams_stats].stats_past_Years_Three[2].stats_for_team[stat];
            stats[stat] = new_stat;
        }

        team_to_be_placed.stats_for_team = stats;
        team_to_be_placed.team_name = future_champion_vector[teams_stats].name;

        for(int conference = 0; conference < this->list_of_team_names_conference.size(); conference++)
        {
            if(this->list_of_team_names_conference[conference].name == future_champion_vector[teams_stats].name)
            {
                conference_place = this->list_of_team_names_conference[conference].conference;
                conference = this->list_of_team_names_conference.size() + 1;
            }
        }
        if(conference_place == 'E')
        {
            this->eastern_Conference_Teams.push_back(team_to_be_placed);
        }
        else
        {
            this->western_Conference_Teams.push_back(team_to_be_placed);
        }
    }
}

int Predict_Champ::get_Points_For_Team(double twos, double threes, double free_throws, double two_per, double three_per, double free_per)
{

    int random_number = rand() % 100 + 1;
    int points = 0;
    for(int point_two = 0; point_two <= twos; point_two++)
    {
        random_number = rand() % 100 + 1;
        if(random_number <= two_per)
        {
            points += 2;
        }
    }
    for(int three_points = 0; three_points <= threes; three_points++)
    {
        random_number = rand() % 100 + 1;
        if(random_number <= three_per)
        {
            points += 3;
        }

    }
    for(int one_points = 0; one_points <= free_throws; one_points++)
    {
        random_number = rand() % 100 + 1;
        if(random_number <= free_per)
        {
            points += 1;
        }

    }

    return points;
}

Current_Teams Predict_Champ::get_winner_From_two(Current_Teams one, Current_Teams two)
{
    Current_Teams returning_Team;
    int points_one = 0, points_two = 0, t_two = 0, t_one = 0, one_team = 0, two_team = 0;

            for(int series = 0; series < 7 && t_one != 1 && t_two != 1; series++)
            {
                points_one = get_Points_For_Team(one.stats_for_team[7] - one.stats_for_team[10], one.stats_for_team[10], //get the total points
                one.stats_for_team[13], one.stats_for_team[8],one.stats_for_team[11],one.stats_for_team[14]);

                points_two = get_Points_For_Team(two.stats_for_team[7] - two.stats_for_team[10], two.stats_for_team[10], //get the total points
                two.stats_for_team[13], two.stats_for_team[8],two.stats_for_team[11],two.stats_for_team[14]);
                if(points_one == points_two)
                {
                    if(one.stats_for_team[3] > two.stats_for_team[3])//win %
                    {
                        one_team++;
                    }
                    else if (one.stats_for_team[3] == two.stats_for_team[3])// win % ==
                    {
                        if(one.stats_for_team[5] > two.stats_for_team[5])// total points scored on average
                        {
                            one_team++;
                        }
                        else
                        {
                            two_team++;
                        }
                    }
                    else
                    {
                        two_team++;//win % larger than the other team
                    }

                }
                else if(points_one > points_two)
                {
                    one_team++;
                }
                else
                {
                    two_team++;
                }
                if(one_team == 4)
                {
                    t_one = 1;
                    returning_Team = one;
                }
                else if (two_team == 4)
                {
                    t_two = 1;
                    returning_Team = two;
                }
            }

            return returning_Team;
}
//Add to this like % and such....
void Predict_Champ::print_Final_Teams()
{
    fstream Champ;
    Champ.open("Predicted_Champions.txt",std::ios::out);
    Champ << "Final Teams 2021-2022: ";
    for(int teams = 0; teams < 6; teams++)
    {
        Champ << this->final_teams_current_year[teams];
        if(teams != 5)
        {
        Champ << ", ";
        }
    }
    Champ << '\n';
    Champ << "Predicted Champion 2021-2022: ";
    Champ << this->champion_current_year;
    Champ.close(); 
}

//Playoff Simulation in this function...
void Predict_Champ::playoff_Sim()
{
    //Now have the top two teams from each conference in the array in this class...
    Current_Teams team_one_west, team_two_west, team_three_west, team_one_east, team_two_east, team_three_east;
    //set all the teams
    Current_Teams final_Teams[2];
    Current_Teams winner;
    Current_Teams team_that_won[2]; // 0 will be the west and 1 will be the east
    int t_one_west = 0, t_two_west = 0, t_one_east = 0, t_two_east = 0, t_three_east = 0, t_three_west = 0, t_one = 0, t_two = 0;
    int one_team = 0, two_team = 0;
    int points_one = 0, points_two = 0;//the total points for the two teams competing
    int two = 0, three = 0, free = 0;//amount of shots
    team_one_west = this->final_Six_west[0];
    team_two_west = this->final_Six_west[1];
    team_three_west = this->final_Six_west[2];
    team_one_east = this->final_Six_east[0];
    team_two_east = this->final_Six_east[1];
    team_three_east = this->final_Six_east[2];

    if(still_Past_Years == true)//past champions
    {
        if(team_one_west.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name || 
           team_two_west.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name ||
           team_three_west.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name || 
           team_two_east.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name || 
           team_one_east.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name || 
           team_three_east.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name)
        {
            this->champ_team_in_Final_Six[this->place_In_Champ_Calculations - 1] = 1; // in the final four teams...
        }
        else
        {
            this->champ_team_in_Final_Six[this->place_In_Champ_Calculations - 1] = 0; // not in the final four teams...
        }
    }
    else if(this->future_Champ_finding == true)//year 2022-2023
    {
        this->final_teams_next_year[0] = team_one_west.team_name;
        this->final_teams_next_year[1] = team_two_west.team_name;
        this->final_teams_next_year[2] = team_three_west.team_name;
        this->final_teams_next_year[3] = team_one_east.team_name;
        this->final_teams_next_year[4] = team_two_east.team_name;
        this->final_teams_next_year[5] = team_three_east.team_name;
    }
    else//the current year 2021-2022
    {
        //Note the final four teams to be printed later in the program...
        this->final_teams_current_year[0] = team_one_west.team_name;
        this->final_teams_current_year[1] = team_two_west.team_name;
        this->final_teams_current_year[2] = team_three_west.team_name;
        this->final_teams_current_year[3] = team_one_east.team_name;
        this->final_teams_current_year[4] = team_two_east.team_name;
        this->final_teams_current_year[5] = team_three_east.team_name;
    }

    while(t_one_west != 10 && t_two_west != 10 && t_one_east != 10 && t_two_east != 10 && t_three_east != 10 && t_three_west != 10)//won a total of 10 times...
    {
            //western conference first    
            team_that_won[0] = get_winner_From_two(team_two_west,team_three_west);
            //eastern conference next
            team_that_won[1] = get_winner_From_two(team_two_east,team_three_east);
            //western finals
            final_Teams[0] = get_winner_From_two(team_that_won[0], team_one_west);
            //eastern finals
            final_Teams[1] = get_winner_From_two(team_that_won[1], team_one_east);
            //Finals
            winner = get_winner_From_two(final_Teams[0],final_Teams[1]);

            //check to see who won the championship for this iteration
            if(winner.team_name == team_one_west.team_name)
            {
                t_one_west++;
            }
            else if (winner.team_name == team_two_west.team_name)
            {
                t_two_west++;
            }
            else if (winner.team_name == team_three_west.team_name)
            {
                t_three_west++;
            }
            else if (winner.team_name == team_one_east.team_name)
            {
                t_one_east++;   
            }
            else if (winner.team_name == team_two_east.team_name)
            {
                t_two_east++;
            }
            else if (winner.team_name == team_three_east.team_name)
            {
                t_three_east++;
            }
    }
    if(still_Past_Years == true)//past champions
     {   //make note if the predicted champion is the team that actually won for that year...
         if(t_one_east == 10)
        {
            if(team_one_east.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name)
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 1;
            }
            else
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 0;
            }
        }
        else if (t_two_east == 10)
        {
            if(team_two_east.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name)
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 1;
            }
            else
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 0;
            }
        }
        else if (t_three_east == 10)
        {
            if(team_three_east.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name)
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 1;
            }
            else
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 0;
            }
        }
        else if (t_one_west == 10)
        {
            if(team_one_west.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name)
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 1;
            }
            else
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 0;
            }
        }
        else if (t_two_west == 10)
        {
            if(team_two_west.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name)
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 1;
            }
            else
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 0;
            }
        }
        else if (t_three_west == 10)
        {
            if(team_three_west.team_name == this->past_championship_teams[this->place_In_Champ_Calculations].team_name)
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 1;
            }
            else
            {
                this->champ_team_Pred_Six[this->place_In_Champ_Calculations - 1] = 0;
            }
        }
    }
    else if(this->future_Champ_finding == true)//year 2022-2023
    {
        if(t_one_east == 10)
        {
            this->champion_next_year = team_one_east.team_name;
        }
        else if (t_two_east == 10)
        {
            this->champion_next_year = team_two_east.team_name;
        }
        else if (t_three_east == 10)
        {
            this->champion_next_year = team_three_east.team_name;
        }
        else if (t_one_west == 10)
        {
            this->champion_next_year = team_one_west.team_name;
        }
        else if (t_two_west == 10)
        {
            this->champion_next_year = team_two_west.team_name;
        }
        else if (t_three_west == 10)
        {
            this->champion_next_year = team_three_west.team_name;
        }
    }
    else//the current year 2021-2022
    {
        Past_Champions champion;
        vector<double> champ;
        double data = 0.0;
        if(t_one_east == 10)
        {
            this->champion_current_year = team_one_east.team_name;
            for(int index = 0; index < 26; index++)
            {
                data = team_one_east.stats_for_team[index] - this->average_of_past_years[index];
                champ.push_back(data);
            }
        }
        else if (t_two_east == 10)
        {
            this->champion_current_year = team_two_east.team_name;
            for(int index = 0; index < 26; index++)
            {
                data = team_two_east.stats_for_team[index] - this->average_of_past_years[index];
                champ.push_back(data);
            }
        }
        else if (t_three_east == 10)
        {
            this->champion_current_year = team_three_east.team_name;
            for(int index = 0; index < 26; index++)
            {
                data = team_three_east.stats_for_team[index] - this->average_of_past_years[index];
                champ.push_back(data);
            }
        }
        else if (t_one_west == 10)
        {
            this->champion_current_year = team_one_west.team_name;
            for(int index = 0; index < 26; index++)
            {
                data = team_one_west.stats_for_team[index] - this->average_of_past_years[index];
                champ.push_back(data);
            }
        }
        else if (t_two_west == 10)
        {
            this->champion_current_year = team_two_west.team_name;
            for(int index = 0; index < 26; index++)
            {
                data = team_two_west.stats_for_team[index] - this->average_of_past_years[index];
                champ.push_back(data);
            }
        }
        else if (t_three_west == 10)
        {
            this->champion_current_year = team_three_west.team_name;        
            for(int index = 0; index < 26; index++)
            {
                data = team_three_west.stats_for_team[index] - this->average_of_past_years[index];
                champ.push_back(data);
            }

        }
        champion.stats_for_team = champ;
        champion.team_name = this->champion_current_year;
        this->past_championship_teams.push_back(champion);
    }

}
void Predict_Champ::calculate_Similarity()
{
    double sim = 0, team_mag = 0.0, champ_mag = 0.0, numerator = 0.0;
    Current_Teams place;
    place.similarity = -100;
    //Reset to be used for the placement of teams...
    this->final_Six_west[0] = place;
    this->final_Six_west[1] = place;
    this->final_Six_west[2] = place;
    this->final_Six_east[0] = place;
    this->final_Six_east[1] = place;
    this->final_Six_east[2] = place;

    for(int champ = 0; champ < this->place_In_Champ_Calculations; champ++)
    {
        for(int i = 0; i < 26; i++)
        {
            champ_mag += this->past_championship_teams[champ].stats_for_team[i] * this->past_championship_teams[champ].stats_for_team[i]; 
        }
        champ_mag = sqrt(champ_mag);
        //Now for all the teams...
        for(int west = 0; west < this->western_Conference_Teams.size(); west++)
        {
            for(int values = 0; values < 26; values++)
            {
                numerator += (this->western_Conference_Teams[west].stats_for_team[values] - this->average_of_past_years[values]) * this->past_championship_teams[champ].stats_for_team[values];
                team_mag += (this->western_Conference_Teams[west].stats_for_team[values] - this->average_of_past_years[values]) * (this->western_Conference_Teams[west].stats_for_team[values] - this->average_of_past_years[values]);
            }
            team_mag = sqrt(team_mag);
            
            sim = numerator / (team_mag * champ_mag);
            this->western_Conference_Teams[west].similarity += sim;
            numerator = 0.0;
            team_mag = 0.0;
        }
        for(int east = 0; east < this->eastern_Conference_Teams.size(); east++)
        {
            for(int values = 0; values < 26; values++)
            {
                numerator += (this->eastern_Conference_Teams[east].stats_for_team[values] - this->average_of_past_years[values]) * this->past_championship_teams[champ].stats_for_team[values];
                team_mag += (this->eastern_Conference_Teams[east].stats_for_team[values] - this->average_of_past_years[values]) * (this->eastern_Conference_Teams[east].stats_for_team[values] - this->average_of_past_years[values]);
            }
            team_mag = sqrt(team_mag);
            
            sim = numerator / (team_mag * champ_mag);
            this->eastern_Conference_Teams[east].similarity += sim;
            numerator = 0.0;
            team_mag = 0.0;
        }
        //reset all the values that were used
        champ_mag = 0.0;
        sim = 0.0;
        team_mag = 0.0;
        numerator = 0.0;
    }


    //Now all the teams have been compared to the past champions now who has the highest similarity
    for(int west = 0; west < this->western_Conference_Teams.size(); west++)
    {
        if(this->western_Conference_Teams[west].similarity > this->final_Six_west[0].similarity)
        {
            this->final_Six_west[2] = this->final_Six_west[1];
            this->final_Six_west[1] = this->final_Six_west[0];
            this->final_Six_west[0] = this->western_Conference_Teams[west];
        }
        else if(this->western_Conference_Teams[west].similarity > this->final_Six_west[1].similarity)
        {   
            this->final_Six_west[2] = this->final_Six_west[1];
            this->final_Six_west[1] = this->western_Conference_Teams[west];   
        }
        else if(this->western_Conference_Teams[west].similarity > this->final_Six_west[2].similarity)
        {
            this->final_Six_west[2] = this->western_Conference_Teams[west];
        }
    }


    for(int east = 0; east < this->eastern_Conference_Teams.size(); east++)
    {
        if(this->eastern_Conference_Teams[east].similarity > this->final_Six_east[0].similarity)
        {
            this->final_Six_east[2] = this->final_Six_east[1];
            this->final_Six_east[1] = this->final_Six_east[0];
            this->final_Six_east[0] = this->eastern_Conference_Teams[east];
        }
        else if(this->eastern_Conference_Teams[east].similarity > this->final_Six_east[1].similarity)
        {   
            this->final_Six_east[2] = this->final_Six_east[1];
            this->final_Six_east[1] = this->eastern_Conference_Teams[east];
        }
        else if(this->eastern_Conference_Teams[east].similarity > this->final_Six_east[2].similarity)
        {
            this->final_Six_east[2] = this->eastern_Conference_Teams[east];
        }
    }
    //Now have the two top teams from each conference...
}

void Predict_Champ::get_Stats_Zero_One()
{
    fstream First_Team;
    First_Team.open("2000-2001_Stats.txt",std::ios::in);
    double stat_value = 0.0;
    int total_teams = 0;//used in the normalized process...
    vector<double> champion_vector, average_of_year;
    string champion = this->past_championship_teams[this->place_In_Champ_Calculations].team_name;//set the team name to the first champion is this case for 2000-2001 year
    string temp = "", stat_inital = "";
    for(int pop = 0; pop < 26; pop++)
    {
        champion_vector.push_back(0.0);//so the placing goes by quicker...
        average_of_year.push_back(0.0);
    }
    getline(First_Team,temp,'\n');//get the beginning of the file, this information is not useful for the algorithm to run only to know what each number means
    while(!First_Team.eof())
    {
        getline(First_Team,temp,'\n');
        if(temp == champion)
        {
            for(int index = 0; index < 26; index++)
            {
                if(index != 25)
                {
                    getline(First_Team,stat_inital,',');
                }
                else
                {
                    getline(First_Team,stat_inital,'\n');
                }
                stat_value = stold(stat_inital);
                champion_vector[index] = stat_value;
                average_of_year[index] += stat_value;

            }
        }
        else
        {
            for(int index = 0; index < 26; index++)
            {
                if(index != 25)
                {
                    getline(First_Team,stat_inital,',');
                }
                else
                {
                    getline(First_Team,stat_inital,'\n');
                }
                stat_value = stold(stat_inital);
                average_of_year[index] += stat_value;
            }

        }
        total_teams++;

    }
    First_Team.close();
    for(int norm = 0; norm < 26; norm++)
    {
        average_of_year[norm] = average_of_year[norm] / total_teams;
        champion_vector[norm] = champion_vector[norm] - average_of_year[norm];//normalize the vector so it can be used later in the calulations...
    }
    this->past_championship_teams[this->place_In_Champ_Calculations].stats_for_team = champion_vector;
    this->place_In_Champ_Calculations++;//increament the years so 1 years has been completed after this process...

}
void Predict_Champ::get_Stats_For_Team(string file)
{  
    fstream Year_Two;
    Year_Two.open(file,std::ios::in);
    string temp = "", stat_inital = "";
    double stat_value = 0.0;
    int place = 0, total_teams = 0;
    char conference;
    Current_Teams team;
    string champion = "";
    vector<double> champion_vector, average_of_year, team_total;
    if(this->still_Past_Years == true)
    {
         champion = this->past_championship_teams[this->place_In_Champ_Calculations].team_name;//set the team name to the first champion is this case for 2000-2001 year
    }
    for(int pop = 0; pop < 26; pop++)
    {
        champion_vector.push_back(0.0);//so the placing goes by quicker...
        average_of_year.push_back(0.0);
        team_total.push_back(0.0);
    }
    getline(Year_Two,temp,'\n');
    while(!Year_Two.eof())
    {
        getline(Year_Two,temp,'\n');
        if(temp == champion)
        {
            for(int t = 0; t < 26; t++)
            {
                if(t != 25)
                {
                    getline(Year_Two,stat_inital,',');
                    stat_value = stold(stat_inital);
                    champion_vector[t] = stat_value;
                    team_total[t] = stat_value;
                    average_of_year[t] += stat_value;
                }
                else
                {
                    getline(Year_Two,stat_inital,'\n');
                    stat_value = stold(stat_inital);
                    average_of_year[t] += stat_value;
                    team_total[t] = stat_value;
                    champion_vector[t] = stat_value;
                }
            }
        }
        else
        {
            for(int t = 0; t < 26; t++)
            {
                if(t != 25)
                {
                    getline(Year_Two,stat_inital,',');
                    stat_value = stold(stat_inital);
                    team_total[t] = stat_value;
                    average_of_year[t] += stat_value;
                }
                else
                {
                    getline(Year_Two,stat_inital,'\n');
                    stat_value = stold(stat_inital);
                    average_of_year[t] += stat_value;
                    team_total[t] = stat_value;
                }
            }

        }
            team.team_name = temp;
            team.stats_for_team = team_total;
            team.similarity = 0.0;


            for(int index = 0; index < this->list_of_team_names_conference.size(); index++)
            {
                if(this->list_of_team_names_conference[index].name == temp)
                {
                    place = index;
                }
            }
            conference = this->list_of_team_names_conference[place].conference;            
            if(conference == 'E')
            {
                this->eastern_Conference_Teams.push_back(team);
            }
            else
            {
                this->western_Conference_Teams.push_back(team);
            }

            place = 0;
            total_teams++;
    }
    Year_Two.close();
    //normalize the feature vectors
    for(int norm = 0; norm < 26; norm++)
    {
        average_of_year[norm] = average_of_year[norm] / total_teams;
        champion_vector[norm] = champion_vector[norm] - average_of_year[norm];
    }
    if(this->still_Past_Years == true)
    {
        this->past_championship_teams[this->place_In_Champ_Calculations].stats_for_team = champion_vector;//set as the champion vector for this list...
    }
    this->average_of_past_years = average_of_year;//set the average so if the playoff sim the stats are still available to use...
    //call the function to make this function not as complicated
    this->calculate_Similarity();//calculate the similarity and the vectors for all the other teams will be normalized there as well...
    this->playoff_Sim();//now with the four teams have a playoff simulation...


    //clear the vectors and increase the championship years done...
    this->place_In_Champ_Calculations++;//after all done with everything increase the value...
    this->eastern_Conference_Teams.clear();
    this->western_Conference_Teams.clear();
}