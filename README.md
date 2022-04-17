# Data_Mining_Project_2022
This data was taken from the official NBA website https://www.nba.com/stats/teams/traditional/?sort=W_PCT&dir=-1, with the commas added after to be able to
    better traverse the data since it was seperated with spaces beforehand. The years were changed when going to the link to get the stats for the desired year.

How the data is arranged in this way in all the Stats files:<br>
<Team>
<Team Stats>
    
Example:<br>
    Golden State Warriors<br>
    79,63,16,.797,48.1,115.0,43.7,89.7,48.7,11.6,31.7,36.5,16.1,20.2,79.8,9.5,35.6,45.1,27.4,13.0,8.5,4.4,3.9,19.7,19.0,7.8<br>
    
The numbers for each team correspond to the following features in this order as well:<br>
GP W L WIN% MIN PTS FGM FGA FG% 3PM 3PA 3P% FTM FTA FT% OREB DREB REB AST TOV STL BLK BLKA PF PFD +/-<br>

What each feature means:<br>
    GP- Games Played in the Season<br>
    W- Wins<br>
    L- Losses<br>
    WIN%- Amount of wins out of total games Played<br>
    MIN- total minutes played each games in average<br>
    PTS- Average amount of points score in a games<br>
    FGM- Field goals made in a game on average<br>
    FGA- The average amount of field goals attempted in a game<br>
    FG%- Percentage to make the shot in a game<br>
    3PM- Total 3 pointers made in a game on average<br>
    3PA- Total 3 pointers attempted in a game on average<br>
    3P%- Percentage to make the 3 point shot<br>
    FTM- Free-throws made on average in each game<br>
    FTA- Average amount of free-throws attempted in each game<br>
    FT%- Percentage to make the free-throw in a game<br>
    OREB- Average offensive rebounds per game<br>
    DREB- Average defensive rebounds per game<br>
    REB- Average rebounds per game<br>
    AST- Average assists per game<br>
    TOV- Average turn-overs per game<br>
    STL- Average steals per game<br>
    BLK- Average blocks per game<br>
    BLKA- Average blocks taken per game (The average amount of times this team gets their shots blocked per game)<br>
    PF- Average personal fouls a game<br>
    PFD- Average fouls draw per game (The average amount of fouls a team gets when playing this team)<br>
    +/- - What this stat means is when a player comes in their +/- is at zero and when they go out of the game the total change<br>
            in points is their +/- and this is the team average<br>
            Example:<br>
                The player comes in at score 15:20 and goes out of the game at 35:35, the +/- would be at a 5 since the total change in points was 5 and positive since the team gained points on the opposing team.<br>

Here are the Champions for each year that was included in the data set (Reference Purposes):<br>
2000-2001: Los Angeles Lakers<br>
2001-2002: Los Angeles Lakers<br>
2002-2003: San Antonio Spurs<br>
2003-2004: Detroit Pistons<br>
2004-2005: San Antonio Spurs<br>
2005-2006: Miami Heat<br>
2006-2007: San Antonio Spurs<br>
2007-2008: Boston Celtics<br>
2008-2009: Los Angeles Lakers<br>
2009-2010: Los Angeles Lakers<br>
2010-2011: Dallas Mavericks<br>
2011-2012: Miami Heat<br>
2012-2013: Miami Heat<br>
2013-2014: San Antonio Spurs<br>
2014-2015: Golden State Warriors<br>
2015-2016: Cleveland Cavaliers<br>
2016-2017: Golden State Warriors<br>
2017-2018: Golden State Warriors<br>
2018-2019: Toronto Raptors<br>
2019-2020: Los Angeles Lakers<br>
2020-2021: Milwaukee Bucks<br>
<br>
Predicted Years for the program:<br>
2021-2022<br>
and<br>
2022-2023
