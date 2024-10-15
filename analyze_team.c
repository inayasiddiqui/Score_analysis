#include <stdio.h>
#include <stdlib.h>
#include "team_member.h"

int main(int argc, char* argv[]) {
    // Check for the correct number of command line arguments
    if (argc != 6) {
        printf("Missing command line arguments\n\n");
        printf("./teamData oldData.txt newData.txt outName.txt numStats numPlayers\n");
        return 1;
    }

    // Parse command line arguments
    char* oldDataFile = argv[1];
    char* newDataFile = argv[2];
    char* outNameFile = argv[3];
    int numStats = atoi(argv[4]);
    int numPlayers = atoi(argv[5]);

    // Create an array of TeamMember structs
    struct TeamMember theTeam[numPlayers + 100];  // Allocate enough space for new players

    // Load existing data
    char firstLine[200];  // array to store first line
    load_data(oldDataFile, theTeam, numPlayers, numStats, firstLine);

    // Current size of the team
    int currentSize = numPlayers;

    // Add new data
    add_data(newDataFile, theTeam, currentSize, numStats);

    // Print all team data to the output file
    print_data(outNameFile, theTeam, currentSize, numStats, firstLine);

    // Free allocated memory
    for (int i = 0; i < currentSize; i++) {
        free(theTeam[i].memberData);
    }

    return 0;
}
