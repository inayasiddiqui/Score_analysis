#ifndef TEAM_MEMBER_H
#define TEAM_MEMBER_H


// Define the TeamMember struct
struct TeamMember {
    int ID;         
    char lastName[50];   
    char firstName[50]; 
    float* memberData;     // Points to an array of team member data
};

// Function prototypes


/***************************************************
* void load_data(const char* filename, struct TeamMember team[], int numPlayers, int numStats, char* firstLine)
* Function to load team data from input file into the team array and store the first line of the file
* Parameters:
* const char* filename: the name of the file from which the data should be loaded
* struct TeamMember team[]: an array storing team data
* int numPlayers: the number of players included in the team data
* int numStats: the number of stats for each player
* char* firstLine: a pointer to store the first line of the file (header information)
* Returns: 
* None
* Note:
* Stores data to be updated and printed later
************************************************/
void load_data(const char* filename, struct TeamMember team[], int numPlayers, int numStats, char* firstLine);

/***************************************************
* void add_data(const char* filename, struct TeamMember team[], int size, int numStats)
* Function to update data from the new file and add into the existing team array
* Parameters:
* const char* filename: the name of the file containing new data to be added
* struct TeamMember team[]: an array storing current team data
* int size: the size of the team array (number of players)
* int numStats: the number of stats for each player
* Returns:
* None
************************************************/
void add_data(const char* filename, struct TeamMember team[], int size, int numStats);

/***************************************************
* void print_data(const char* filename, struct TeamMember team[], int totalSize, int numStats, char* firstLine)
* Function to print the team data nd header line to an output file
* Parameters:
* const char* filename: the name of the file to which the data will be printed
* struct TeamMember team[]: an array storing team data
* int totalSize: the total number of players in the team array
* int numStats: the number of stats for each player
* char* firstLine: the first line to be printed at the top of the file
* Returns:
* None
* Prints data to output file
************************************************/
void print_data(const char* filename, struct TeamMember team[], int totalSize, int numStats, char* firstLine);

#endif 
