//
//  
//  testGame.c
//
//  Created by Md Mashiur Rahman on 7/05/2016.
//  Copyright © 2016 Md Mashiur Rahman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"



#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, \
STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, \
STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, \
STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, \
STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}

#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}


void testInitialState(Game g);

int main(int argc, char * argv[]){
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines, dice);
    testInitialState(g);
    disposeGame(g);
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

//sample out testing simple things
void testInitialState(Game g){
    printf("Test initialState!\n");
    
    //Just an example of how to use these functions
      printf("Just letting you know, we are testing getDiscipline\n");

      assert(getDiscipline(g,0) == STUDENT_BQN);
      assert(getDiscipline(g,1) == STUDENT_MMONEY);
      assert(getDiscipline(g,2) == STUDENT_MJ);
      assert(getDiscipline(g,3) == STUDENT_MMONEY);
      assert(getDiscipline(g,4) == STUDENT_MJ);
      assert(getDiscipline(g,5) == STUDENT_BPS);
      assert(getDiscipline(g,6) == STUDENT_MTV);
      assert(getDiscipline(g,7) == STUDENT_MTV);
      assert(getDiscipline(g,8) == STUDENT_BPS);
      assert(getDiscipline(g,9) == STUDENT_MTV);
      assert(getDiscipline(g,10) == STUDENT_BQN);
      assert(getDiscipline(g,11) == STUDENT_MJ);
      assert(getDiscipline(g,12) == STUDENT_BQN);
      assert(getDiscipline(g,13) == STUDENT_THD);
      assert(getDiscipline(g,14) == STUDENT_MJ);
      assert(getDiscipline(g,15) == STUDENT_MMONEY);
      assert(getDiscipline(g,16) == STUDENT_MTV);
      assert(getDiscipline(g,17) == STUDENT_BQN);
      assert(getDiscipline(g,18) == STUDENT_BPS);
    printf ("We are making sure all the dice values are good!\n");
  printf ("testing getDiceValue\n");

    assert(getDiceValue(g,0) == 9);
    assert(getDiceValue(g,1) == 10);
    assert(getDiceValue(g,2) == 8);
    assert(getDiceValue(g,3) == 12);
    assert(getDiceValue(g,4) == 6);
    assert(getDiceValue(g,5) == 5);
    assert(getDiceValue(g,6) == 3);
    assert(getDiceValue(g,7) == 11);
    assert(getDiceValue(g,8) == 3);
    assert(getDiceValue(g,9) == 11);
    assert(getDiceValue(g,10) == 4);
    assert(getDiceValue(g,11) == 6);
    assert(getDiceValue(g,12) == 4);
    assert(getDiceValue(g,13) == 7);
    assert(getDiceValue(g,14) == 9);
    assert(getDiceValue(g,15) == 2);
    assert(getDiceValue(g,16) == 8);
    assert(getDiceValue(g,17) == 10);
    assert(getDiceValue(g,18) == 5);
    
    assert(getMostARCs(g) == NO_ONE);
    assert(getMostPublications(g) == NO_ONE);
    assert(getTurnNumber(g) == -1);
    assert(getWhoseTurn(g) == NO_ONE);
    
    int uni = UNI_A;
    
    while(uni <= UNI_C){
        assert(getKPIpoints(g,uni) == 20);
        assert(getARCs(g,uni) == 0);
        assert(getGO8s(g,uni) == 0);
        assert(getCampuses(g,uni) == 2);
        
        int discipline = STUDENT_BPS;
        while(discipline <= STUDENT_MMONEY){
            assert(getExchangeRate(g,uni,discipline,STUDENT_MMONEY) == 3);
            discipline++;
        }
        uni++;
    }
    printf("passed!\n");
}
