#include "TeamScheduler.hpp"

TeamScheduler::TeamScheduler(){
  numTeams = 2;
  numWeeks = 1;
  while(calender.size() < numWeeks){
    calender.push_back(vector<Match>());
  }
  generate();
}

TeamScheduler::TeamScheduler(int nT, int nW){
	numTeams = nT;
  numWeeks = nW;
  while(calender.size() < numWeeks){
    calender.push_back(vector<Match>());
  }
  generate();
}

void TeamScheduler::generate(){
  int *table;
  int *rotation;
  int tableSize;
  int crux;

  if(numTeams % 2 == 1){
    tableSize = numTeams + 1;
  }else{
    tableSize = numTeams;
  }
  crux = tableSize / 2;
  table = new int[tableSize];
  rotation = new int[tableSize];
  
  //set first table position
  for(int i = 0; i < numTeams; i++){
    table[i] = i;
  }
  if(numTeams != tableSize){
    table[numTeams] = BYE_WEEK;
  }

  //add to vector
  for(int i = 0; i < numWeeks; i++){
    for(int j = 0; j < crux; j++){
      calender[i].push_back(Match(table[j], table[j + crux]));
    }
    //rotate the table
    rotation[0] = table[0];
    for(unsigned int j = 1; j < tableSize; j++){
      if(j < crux){
        if(j == crux-1){
          rotation[j] = table[tableSize-1];
        }else{
          rotation[j] = table[j+1];
        } 
      }else{
        if(j == crux){
          rotation[j] = table[1];
        }else{
          rotation[j] = table[j-1];
        }
      }
    }
    for(unsigned int k = 0; k < tableSize; k++){
      table[k] = rotation[k];
    }
  }
}

vector<Match> TeamScheduler::getWeek(int wk){
  return calender[wk - 1];
}

vector<vector<Match> > TeamScheduler::getYear(){
  return calender;
}

string TeamScheduler::pID(int id){
  if(id == BYE_WEEK){
    return "Bye Wk";
  }
  return "Team " + to_string(id);
}

void TeamScheduler::print(){
  string toPrint = "";
  for(unsigned int i = 0; i < calender.size(); i++){
    toPrint += "Week" + to_string(i + 1) + "\n";
    for(unsigned int j = 0; j < calender[i].size(); j++){
      toPrint += "\t" + pID(calender[i][j].team1) + " : " + pID(calender[i][j].team2) + "\n";
    }
  }
  printf("%s", toPrint.c_str());
}


