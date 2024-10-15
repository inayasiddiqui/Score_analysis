
#include <stdio.h>
#include <stdlib.h>
#include "team_member.h"

// Function to load data from the old file into the array theTeam
void load_data(const char* filename, struct TeamMember theTeam[], int numPlayers, int numStats, char* firstLine) {
    FILE* inFile = fopen(filename, "r");
    if (inFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    fgets(firstLine, 199, inFile);
    printf("%s", firstLine);
    for (int i = 0; i < numPlayers; i++) {
        // Read ID, first name, last name
        if (fscanf(inFile, "%d %s %s", &theTeam[i].ID, theTeam[i].firstName, theTeam[i].lastName) != 3) {
            printf("%s %s\n", theTeam[i].firstName, theTeam[i].lastName);
            fprintf(stderr, "1 Error reading data for theTeam member %d\n", i);
            exit(1);
        }
        
        printf("%s %s\n", theTeam[i].firstName, theTeam[i].lastName);
        // Allocate memory for memberData
        theTeam[i].memberData = (float*)malloc(numStats * sizeof(float));
        if (theTeam[i].memberData == NULL) {
            fprintf(stderr, "Memory allocation failed for theTeam member %d\n", i);
            exit(1);
        }

        // Read stats
        for (int j = 0; j < numStats; j++) {
            if (fscanf(inFile, "%f", &theTeam[i].memberData[j]) != 1) {
                fprintf(stderr, "2 Error reading stats for theTeam member %d\n", i);
                exit(1);
            }
            printf("%d " , (int)theTeam[i].memberData[j]);
        }
        printf("\n");
    }

    fclose(inFile);
    printf("Data loaded successfully from %s\n", filename);
}

// Function to add new data from a file into the existing theTeam array
void add_data(const char* filename, struct TeamMember theTeam[], int size, int numStats) {
    FILE* newFile = fopen(filename, "r");
    if (newFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    //skip the first line
    char firstLine[200];
    fgets(firstLine, sizeof(firstLine), newFile);

    // temporary variables for new data
    int newID;
    char newFirstName[50];
    char newLastName[50];
    float newStat;

    //loop over each new member in the update file
    while (fscanf(newFile, "%d", &newID) == 1) {
        // Loop over all old data in theTeam[]
        for (int i = 0; i < size; i++) {
            // If the ID matches update stats
            if (theTeam[i].ID == newID) {
                // Read and discard the first and last name
                fscanf(newFile, "%s %s", newFirstName, newLastName);

                //loop over numStats and update each stat
                for (int j = 0; j < numStats; j++) {
                    if (fscanf(newFile, "%f", &newStat) == 1) {
                        theTeam[i].memberData[j] += newStat;
                        printf("%d " , (int)theTeam[i].memberData[j]);
                    } else {
                        fprintf(stderr, "Error reading stat for ID %d\n", newID);
                        fclose(newFile);
                        return;
                    }
                }
                break;
            }
        }
    }
    fclose(newFile);
}

// Function to print the data to the output file
void print_data(const char* filename, struct TeamMember theTeam[], int totalSize, int numStats, char* firstLine) {
    FILE* outFile = fopen(filename, "w");
    if (outFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    // Print the first line
    fprintf(outFile, "%s", firstLine);

    // Print each theTeam member's data
    for (int i = 0; i < totalSize; i++) {
        fprintf(outFile, "%d\t%s\t%s\t", theTeam[i].ID, theTeam[i].firstName, theTeam[i].lastName);
        for (int j = 0; j < numStats; j++) {
            if (j < numStats - 1) {
                fprintf(outFile, "%d\t", (int)theTeam[i].memberData[j]);  
            } else {
                fprintf(outFile, "%d", (int)theTeam[i].memberData[j]);    // No tab after last stat
            }
        }
        fprintf(outFile, "\n"); 
    }

    fclose(outFile);
    printf("Data written successfully to %s\n", filename);
}
