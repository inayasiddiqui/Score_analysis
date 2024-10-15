# This makefile is used as follows to regenerate files for the teamData program:
#   make team_member.o   --  Regenerates team_member.o by compiling
#	make analyze_team.o  --  Regenerates analyze_team.o by compiling
#	make teamData	--	Regenerates the executable teamData file by compiling
#	make			 --  Same as "make teamData"

teamData: analyze_team.o team_member.o
	gcc -g -Wall team_member.o analyze_team.o -lm -o teamData

analyze_team.o: team_member.h analyze_team.c
	gcc -g -Wall -c analyze_team.c

team_member.o: team_member.h team_member.c
	gcc -g -Wall -c team_member.c

clean:
	rm -f team_member.o analyze_team.o teamData

all: teamData
