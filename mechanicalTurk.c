

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"
#include "mechanicalTurk.h"

action decideAction (Game g) {
    action nextAction;
    
    nextAction.actionCode = BUILD_CAMPUS;
    if (isLegalAction(g, nextAction) == TRUE) {
        printf("You Built a Campus\n");
        return nextAction;
    }
    
    nextAction.actionCode = BUILD_GO8;
    if (isLegalAction(g, nextAction) == TRUE) {
        printf("You Built a GO8 campus\n");
        return nextAction;
    }
    nextAction.actionCode = OBTAIN_ARC;
    if (isLegalAction(g, nextAction) == TRUE) {
        printf("You Got an Arc!\n");
        return nextAction;
    }
    
    nextAction.actionCode = START_SPINOFF;
    if (isLegalAction(g, nextAction) == TRUE) {
        printf("You Started a Spinoff!\n");
        return nextAction;
    }
    

    
    nextAction.actionCode = PASS;
    printf("You are useless - you pass\n");
    return nextAction;




}