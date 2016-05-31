//
//  Game.c
//  Project Game
//
//  Created by Mash, Ben, Thomas & Brandon.
//  Copyright © 2016 GameZone. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"

//KPI Points

#define CAMPUS_KPI 10
#define GO8_KPI 20
#define ARC_KPI 2
#define IP_KPI 10
#define PRESTIGE_KPI 10

#define TOTAL_DISCIPLINES 6

typedef struct _game {
    // your group puts here the details of the data
    // you want to store in the _game struct
    int currentTurn;
    int mostARCs;
    int mostPublications;
    int numARCgrants[NUM_UNIS];
    int numCampuses[NUM_UNIS];
    int numGO8campuses[NUM_UNIS];
    int numIPpatents[NUM_UNIS];
    int numPublications[NUM_UNIS];
    int Disciplines[NUM_UNIS][TOTAL_DISCIPLINES];
  
} game;

Game newGame (int discipline[], int dice[]){
	Game g = malloc(sizeof(struct _game)); // sets aside memory for game
	assert (g!= NULL); 
	//g->currentTurn = -1;// q: why are we using the arrow operator here instead of the dot operator? 
						// Isn't the struct in this .c file, so just use dot operator? isnt the arrow
						// used only when we get the pointer to the struct? or am i wrong?
	return g;
}

void disposeGame (Game g){
        assert (g != NULL);
        free (g);
    
}

void makeAction (Game g, action a){
	
}

/* The actual act of throwing the dice is done in runGame. Here, we 
   have to assert that the dice has been rolled, and that the game
   will increment currentTurn. Then it also needs to pay out the 
   students to the players who are on the hexagons with the rice
   diceScore number.*/
void throwDice (Game g, int diceScore){
	assert (diceScore >= 2 && diceScore <=12);
	g->currentTurn = currentTurn + 1; // incrementing the turn counter	
}

int getDiscipline (Game g, int regionID){
	return 0;
}

int getDiceValue (Game g, int regionID){
	return 0;
}

int getMostARCs (Game g){
    int mostARCs = NO_ONE;
    // if uni A has more arcs that b and more than c, it has the most arcs
	// repeat for each uni
    if ((getARCs(g, UNI_A) > getARCs(g, UNI_B)) && (getARCs(g, UNI_A) > getARCs(g, UNI_C))){
        mostARCs = UNI_A;
    }
    
    if ((getARCs(g, UNI_B) > getARCs(g, UNI_A)) && (getARCs(g, UNI_B) > getARCs(g, UNI_C))){
        mostARCs = UNI_B;
    }
    
    if ((getARCs(g, UNI_C) > getARCs(g, UNI_B)) && (getARCs(g, UNI_C) > getARCs(g, UNI_A))){
        mostARCs = UNI_C;
    }
    
    //assert(mostARCs != 0); i dont think we should assert this because at the start of the game
	// no onoe has any arcs, but that just means we return a 0; with this assert the game would just stop
    
    return mostARCs;
}

int getMostPublications (Game g){

	int mostPublications = 0;
	
	if ((getPublications(g, UNI_A) > getPublications(g, UNI_B)) && (getPublications(g, UNI_A) > getPublications(g, UNI_C))){
		mostPublications = UNI_A;
	}
	
	if ((getPublications(g, UNI_B) > getPublications(g, UNI_A)) && (getPublications(g, UNI_B) > getPublications(g, UNI_C))){
		mostPublications = UNI_B;
	}
   
	if ((getPublications(g, UNI_C) > getPublications(g, UNI_B)) && (getPublications(g, UNI_C) > getPublications(g, UNI_A))){
		mostPublications = UNI_C;
	}
   
	//assert(mostPublications != 0);
	
	return mostPublications;
}	


int getTurnNumber (Game g){
	return g->currentTurn;
}

int getWhoseTurn (Game g){
	return (g->currentTurn)% NUM_UNIS;
}

int getCampus(Game g, path pathToVertex){
	return 0;
}

int getARC(Game g, path pathToEdge){
	return 0;
}

int isLegalAction (Game g, action a){
	return 0;
}

int getKPIpoints (Game g, int player){
	int KPI = 0;
	
	KPI += (ARC_KPI * getARCs(g, player));
	KPI += (CAMPUS_KPI * getCampuses(g, player));
	KPI += (GO8_KPI * getGO8s(g, player));
	KPI += (IP_KPI * getIPs(g, player));
    
	if(g->mostARCs == player) {
		KPI += PRESTIGE_KPI;
	}
    
	if(g->mostPublications == player) {
		KPI += PRESTIGE_KPI;
	}
 
	return KPI;
}

int getARCs (Game g, int player){
	return (g->numARCgrants[player]);
}

int getGO8s (Game g, int player){
	return (g->numGO8campuses[player]);
}
	

int getCampuses (Game g, int player){
	return (g->numCampuses[player]);
}

int getIPs (Game g, int player){
	return (g->numIPpatents[player]);
}

int getPublications (Game g, int player){
	return (g->numPublications[player]);
}

int getStudents (Game g, int player, int discipline){
	return (g->Disciplines[player][discipline]);
}

int getExchangeRate (Game g, int player,
                     int disciplineFrom, int disciplineTo){
	return 0;
}
