#ifndef TOURNAMENT_H
#define TOURNAMENT_H


typedef struct player
{
    int team;
    char firstname[10];
    char lastname[10];
    int player_num; 
    int offensive;
    int defensive;
}Player;

typedef struct team
{
    char name[20];
    Player players[10];
}Team;

Player * draftPlayers(char filename[], int team_no , int num_players);

Team * initializeTeam(char * teamname,Player * players);

Team *game(Team *team1, Team *team2);

Team * tournament(Team ** league, int team_count);

int isPowerOfTwo(int x);

int stringToIntConverter(char * str);

void deleteTeam(Team *team1);

#endif
