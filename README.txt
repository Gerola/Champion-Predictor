# Data_Mining_Project_2022
This data was taken from the official NBA website https://www.nba.com/stats/teams/traditional/?sort=W_PCT&dir=-1, with the commas added after to be able to
    better traverse the data since it was seperated with spaces beforehand. The years were changed when going to the link to get the stats for the desired year.

How the data is arranged in this way in all the Stats files:
<Team>
<Team Stats>
    
Example:
    Golden State Warriors
    79,63,16,.797,48.1,115.0,43.7,89.7,48.7,11.6,31.7,36.5,16.1,20.2,79.8,9.5,35.6,45.1,27.4,13.0,8.5,4.4,3.9,19.7,19.0,7.8
    
The numbers for each team correspond to the following features in this order as well:
GP W L WIN% MIN PTS FGM FGA FG% 3PM 3PA 3P% FTM FTA FT% OREB DREB REB AST TOV STL BLK BLKA PF PFD +/-

What each feature means:
    GP- Games Played in the Season
    W- Wins
    L- Losses
    WIN%- Amount of wins out of total games Played
    MIN- total minutes played each games in average
    PTS- Average amount of points score in a games
    FGM- Field goals made in a game on average
    FGA- The average amount of field goals attempted in a game
    FG%- Percentage to make the shot in a game
    3PM- Total 3 pointers made in a game on average
    3PA- Total 3 pointers attempted in a game on average
    3P%- Percentage to make the 3 point shot
    FTM- Free-throws made on average in each game
    FTA- Average amount of free-throws attempted in each game
    FT%- Percentage to make the free-throw in a game
    OREB- Average offensive rebounds per game
    DREB- Average defensive rebounds per game
    REB- Average rebounds per game
    AST- Average assists per game
    TOV- Average turn-overs per game
    STL- Average steals per game
    BLK- Average blocks per game
    BLKA- Average blocks taken per game (The average amount of times this team gets their shots blocked per game)
    PF- Average personal fouls a game
    PFD- Average fouls draw per game (The average amount of fouls a team gets when playing this team)
    +/- - What this stat means is when a player comes in their +/- is at zero and when they go out of the game the total change 
            in points is their +/- and this is the team average 
            Example:
                The player comes in at score 15:20
                and goes out of the game at 35:35
                The +/- would be at a 5 since the total change in points was 5 and positive since
                the team gained points on the opposing team.

Here are the Champions for each year that was included in the data set (Reference Purposes):
2000-2001: Los Angeles Lakers
2001-2002: Los Angeles Lakers
2002-2003: San Antonio Spurs
2003-2004: Detroit Pistons
2004-2005: San Antonio Spurs
2005-2006: Miami Heat
2006-2007: San Antonio Spurs
2007-2008: Boston Celtics
2008-2009: Los Angeles Lakers
2009-2010: Los Angeles Lakers
2010-2011: Dallas Mavericks
2011-2012: Miami Heat
2012-2013: Miami Heat
2013-2014: San Antonio Spurs
2014-2015: Golden State Warriors
2015-2016: Cleveland Cavaliers
2016-2017: Golden State Warriors
2017-2018: Golden State Warriors
2018-2019: Toronto Raptors
2019-2020: Los Angeles Lakers
2020-2021: Milwaukee Bucks

Predicted Years for the program:
2021-2022
and
2022-2023
