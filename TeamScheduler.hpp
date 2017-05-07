#ifndef TEAMSCHEDULER
#define TEAMSCHEDULER

#include <vector>
#include <stdio.h>
#include <string>

#define BYE_WEEK -777

using namespace std;

class Match{
  public:	
    int team1, team2;	
    Match(){
      team1 = -1;
      team2 = -1;
    }
	  Match(int t1, int t2){
		  team1 = t1;
		  team2 = t2;
	  }
};

class TeamScheduler{
	public:
    TeamScheduler();
		TeamScheduler(int nT, int nW);
		vector<Match> getWeek(int wk);
		vector<vector<Match> > getYear();
    void print();
	private:
		int numTeams, numWeeks;
    vector<vector<Match> > calender;
		void shuffle();
    void generate();
    string pID(int id);
		
};

#endif

