#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
/** Function printing help
@author Paulina Urbas
@date 20.05.2018
*/
void Help();
/** Function checking terminal
@author Paulina Urbas
@date 20.05.2018
@param int, char *, Image *
@return int
*/
int TerminalCheck(int argc, char * argv[]);
bool CheckIfNumber(int number);