#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool valueinarray(int val, int arr[], int size);
bool verify_circle(int cycle_start, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i= 0; i <candidate_count; i++)
    {
        if( strcmp(candidates[i],name)==0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    //printf("Calling record_preferences\n");
    for (int i=0; i < candidate_count; i++)
    {
        for (int j=i+1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]+=1;
        }

    }
    /*
    for(int i=0; i< candidate_count; i++)
    {
        printf("(");
        for(int j=0; j< candidate_count; j++)
        {
            printf("%i, ", preferences[i][j]);
        }
        printf(")\n");
    }*/
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //printf("Calling function add pairs\n");
    for(int i =0; i < candidate_count; i++)
    {
        for (int j=0; j< candidate_count; j++)
        {
            if(preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner=i;
                pairs[pair_count].loser=j;
                pair_count+=1;
            }
        }
    }
    /*
    for (int k=0; k<pair_count; k++)
    {
        printf("Pair %i: Winner is %i and loser %i\n", k,pairs[k].winner,pairs[k].loser );
    }*/
    return;

}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    //printf("Calling function sort_pairs\n");
    //create a array called power, that will contain the strenght of victory.
    int power[pair_count];
    int i_new; //will safe the new index of the maximum strenght of vicotry
    int max; // will safe the corrently maximum of strenght of victory
    pair max_pair; //will safe the correspndent pair
    // full fill the array power with the strenght of victory
    for (int i =0; i < pair_count; i++)
    {
        power[i]=preferences[pairs[i].winner][pairs[i].loser];
    }
    //Selection sort of the array power and at the same time the arrar pairs.
    for (int i =0; i < pair_count; i++)
    {
        max=power[i];
        max_pair=pairs[i];
        i_new=i;
        for (int j=i+1; j< pair_count; j++)
        {
            if(power[j]>=max)
            {
                max= power[j];
                max_pair=pairs[j];
                i_new=j;
            }
        }

        if (max> power[i])
        {
            power[i_new]=power[i];
            pairs[i_new]=pairs[i];
            power[i]= max;
            pairs[i]= max_pair;
        }
    }
    /*
    printf("Power: ( ");
    for (int i =0; i<pair_count; i++)
    {
        printf("%i, ", power[i]);
    }
    printf(")\n");
    for (int k=0; k<pair_count; k++)
    {
        printf("Pair %i: Winner is %i and loser %i\n", k,pairs[k].winner,pairs[k].loser );
    }*/

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!verify_circle(pairs[i].winner, pairs[i].loser))
        {
            // Lock the pair unless it makes a circle
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    /*
    for(int i=0; i< candidate_count; i++)
    {
        printf("(");
        for(int j=0; j< candidate_count; j++)
        {
            printf("%s, ", locked[i][j] ?"true":"false");
        }
        printf(")\n");
    }*/
    return;
}

// Print the winner of the election
void print_winner(void)
{

    for (int i=0; i<candidate_count; i++)
    {
        int number_of_false=0;
        for(int j=0; j<candidate_count;j++)
        {
            if (locked[j][i]==false)
            {
                number_of_false+=1;
            }
        }
        if(number_of_false==candidate_count)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

bool valueinarray(int val, int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == val)
            return true;
    }
    return false;
}

// The function verify if by adding true a circle will be created.
// Look who the loser won against and verify if this person wons against the current winner (that would crate a circle)
bool verify_circle(int cycle_start, int loser)
{
    if (loser == cycle_start)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (verify_circle(cycle_start, i))
            {
                return true;
            }
        }
    }
    return false;
}

