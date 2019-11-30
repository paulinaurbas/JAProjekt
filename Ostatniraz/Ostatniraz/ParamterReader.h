#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h> 
/** Function printing help
@author Paulina Urbas
@date 16.11.2019
*/
void Help();
/** Function checking terminal
@author Paulina Urbas
@date 16.11.2019
@param int, char *
@return int
*/
int TerminalCheck(int argc, char * argv[]);
/** Function checking if amount of threat is correct
@author Paulina Urbas
@date 16.11.2019
@param int, char *
@return int
*/
bool CheckIfNumber(int number);
/** Function checking if file exist 
@author Paulina Urbas
@date 16.11.2019
@param int, char *
@return int
*/
bool checkIfExist(const std::string & inputName);