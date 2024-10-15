# Score_analysis
Inaya Siddiqui
9/27/24

This program reads data from 2 input files and merges old and new data. It then
writes this data into a new output file.

To build this project use the makefile with executable teamData

To compile the program run the command:
gcc analyze_team.c team_member.c -o teamData

To run this program use the command:
./teamData oldData.txt newData.txt outName.txt numStats numPlayers
where oldData.txt is the old input file, newData.txt is the updated input file, outName.txt is 
the output file with merged data, numStats is the number of stats per team member and 
numPlayers is the number of players.

Sources:
CS2303 Lecture notes
Stack Overflow
Winthrop University "Reading and Writing Records"
Geeksforgeeks "C Program to Read Content of a File"
