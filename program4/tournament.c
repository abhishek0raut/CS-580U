#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"tournament.h"
#include<string.h>

Player * draftPlayers(char * filename, int team_no , int num_players)
{
    Player * playerptr = malloc(10 * sizeof(*playerptr));
    FILE *fp = fopen(filename, "r");
    int j = 0;
    char line[100];
    while (j < num_players) 
    {
        if (fgets(line,sizeof(line), fp) == NULL) 
            break;

        char *p = strtok (line, ",");
        char *array[6];
        int i = 0;
        while (p != NULL)
        {
            array[i++] = p;
            p = strtok (NULL, ",");
        }

        if(stringToIntConverter(array[0]) == team_no)
        {
            playerptr[j].team = stringToIntConverter(array[0]);
            strcpy(playerptr[j].firstname,array[1]);
            strcpy(playerptr[j].lastname,array[2]);
            playerptr[j].player_num = stringToIntConverter(array[3]); 
            playerptr[j].offensive = stringToIntConverter(array[4]);
            playerptr[j].defensive = stringToIntConverter(array[5]);
            j++; 

        }
    }
    fclose(fp);
    return playerptr;
}

int stringToIntConverter(char * str)
{
    int num = 0, i, len;
	len = strlen(str);
    
    for(i=0; i < len; i++)
    {
		num = num * 10 + (str[i]  - '0' );
	}
    return num;
}

Team * initializeTeam(char * teamname,Player * players)
{
    int i,j;
    Team * teamptr = malloc(sizeof(Team));
    srand(time(NULL));
    strcpy(teamptr->name,teamname);
    
    for(i=0; i<10; i++)
    {
        int offensive = 1 + rand() % 10;
        teamptr->players[i].offensive=offensive;
    }
    
    for(j=0; j<10; j++)
    {
        int defensive = 1 + rand() % 7;
        teamptr->players[j].defensive=defensive;
    }
    return teamptr;  
}

Team *game(Team *team1, Team *team2)
{
    int i,j,a,b,value1,value2;
    int total_offensive1 = 0;
    int total_defensive1 = 0;
    int total_offensive2 = 0;
    int total_defensive2 = 0;
    int score1 = 0;
    int score2 = 0;
    
    if(team1 == NULL && team2 == NULL)
    {
        return NULL;
    }
   
    if(team1 == team2)
    {
        return team1;
    }
   
    else
    {
        for(i=0; i<10; i++)
        {
            total_offensive1 = total_offensive1 + team1->players[i].offensive;
            total_defensive1 = total_defensive1 + team1->players[i].defensive;
        }
     
        for(j=0; j<10; j++)
        {
            total_offensive2 = total_offensive2 + team2->players[j].offensive;
            total_defensive2 = total_defensive2 + team2->players[j].defensive;
        }
    
        if(team1->name == "Lilly")
        {
        	total_offensive1=total_offensive1+10;	
	    }
      
        if(team2->name == "Lilly")
        {
	        total_offensive2=total_offensive2+10;	
    	}
      
        for(a=0; a<10; a++)
        {
            value1 = rand() % total_offensive1;
            
            if(total_defensive2>value1)
            {
                score1++;
            }
        }
       
        for(b=0; b<10; b++)
        {
            value2 = rand() % total_offensive2;
          
            if(total_defensive1>value2)
            {
                score2++;
            }
        }
    
        if (score1 > score2)
        {
	        printf("\n Winning Team is: %s with Score %d \n",team1->name,score1);
            return team1;
        }
        else if(score1 == score2) 
        {
            if(total_offensive1 > total_offensive2)
            {
	            printf("\n Winning Team is: %s with Score %d \n",team1->name,score1);
                return team1;
            }
            else
            {
	            printf("\n Winning Team is: %s with Score %d \n",team2->name,score2);
                return team2;
            }
        }
        else
        {
	        printf("\n Winning Team is: %s with Score %d \n",team2->name,score2);
	        return team2;
	    } 
    }
}

Team * tournament(Team ** league, int team_count)
{
    Team *teamptr[team_count];
    int x = 0;
    Team *winner = NULL;
    x=isPowerOfTwo(team_count);
   
    if(x == 0)
    {
        printf("Number of teams is invalid \n");
        return NULL;
    }
    else
    {
        int n;
        Team * winner1[team_count];
        int i = 0;
        
        while(i<team_count)
        {
	        winner1[i] = league[i];	
	        i++;
	    }
       
        while(team_count > 1)
        {
	        int half = team_count/2;
            for(i=0; i<half; i++)
            {
		        winner1[i] = game(winner1[i],winner1[half+i]);
	        }
            
            if(team_count > 2)
		        team_count = team_count/2;
	        else
		        break;
	    }   
	    winner = winner1[0];
	    return winner;
    }
}

int isPowerOfTwo(int x)
{
    printf("\n Team count %d \n",x);
    while (((x % 2) == 0) && x > 1)
        x /= 2;
    return (x == 1);                       
}
    
void deleteTeam(Team *team1)
{
	free(team1);
}
