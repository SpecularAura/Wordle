#include "colorfulterminal.h"
#include <stdio.h>
#include <string.h>
static const int wordsize = 5;
struct WordLoc
{
    int find[5];
    int noofyellow;
    char ch;
};

struct WordLoc strfind(const char str[], char ch)
{
    int i = 0;
    struct WordLoc rep;
    rep.ch = ch;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
        {
            rep.find[i] = i;
        }
        else
        {
            rep.find[i] = -1;
        }
        i++;
    }
    return rep;
}

int isgrey(struct WordLoc* loc1, struct WordLoc loc2, char ch)
{
    int countloc2 = 0, countloc1 = 0, correct = 0, incorrect;

    for( int i = 0; i < 5; i++)
    {
        if(loc1->find[i] == loc2.find[i] && loc1->find[i] != -1)
        {
            correct++;
        }
        if( loc2.find[i] != -1)
        {
            countloc2++;
        }
        if( loc1->find[i] != -1)
        {
            countloc1++;
        }
    }
    //incorrect = countloc2 - correct;

    //printf("%d", countloc1);
    loc1->noofyellow = countloc1 - correct;
    //printf("%d", loc1->noofyellow);
    return loc1->noofyellow;
}

int locfind(struct WordLoc fin, int j, int size)
{
    
    for(int i=0; i<5; i++)
    {
        if(fin.find[i] != -1)
        {
            return 1;
        }
    }
    return 0;
}

int contains(struct WordLoc loc[], char ch, int j)
{
    int i = 0;
    for(i = 0; i < j ; i++)
    {
        if( (ch == loc[i].ch) && i != j )
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    char s1[6] = "start", s2[48];
    // printf("Enter word to guess :");
    // gets(s1);
    // system("cls");
    int i=0, j, k, flag = 0, grey;
    struct WordLoc s2Loc[5], s3Loc;
    char str[2];
    while( i < 6)
    {
        gets(s2);
        printf("\033[A\33[2K\r");
        if(strlen(s2) != 5)
        {
            flag = 1;
            printf("ENTER THE CORRECT WORD SIZE\n");
            continue;
        }
        if(flag)
        {
            flag = 0;
            printf("\033[A\33[2K\r");
        }
        for (j = 0; j < 5; j++)
        {
            int cont = contains(s2Loc, s2[j], j);
            if(cont != -1)
            {
                s2Loc[j] = s2Loc[cont];
                grey = s2Loc[j].noofyellow;
                // printf("%d", grey);
            }
            else
            {
                s2Loc[j] = strfind(s1, s2[j]);
                s3Loc = strfind(s2, s2[j]);
                grey = isgrey(&s2Loc[j], s3Loc, s2[j]);
                //printf("%d", grey);
            }
            // s2Loc = strfind(s2, s2[j]);
            // grey = isgrey(&s2Loc[j], s2Loc);
            str[0]= s2[j];
            str[1]= '\0';
            if (j == s2Loc[j].find[j])
            {
                green_disp(str);
            }
            else if (locfind(s2Loc[j], j, (sizeof(s2Loc[j].find)/sizeof(int))) && grey != 0)
            {
                s2Loc[j].noofyellow--;
                yellow_disp(str);
            }
            else
            {
                grey_disp(str);
            }
        }
        printf("\n");
        if (strcmp(s1, s2) == 0)
        {
            printf("Your score : %d/6", i + 1);
            break;
        }
        i++;
    }
    if (i == 6)
        printf("The word was %s", s1);
}