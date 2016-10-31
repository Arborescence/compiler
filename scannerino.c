/**
TERMINAL lIST

MODULE
BEGIN
END
CONST
TYPE
VAR
PROCEDURE
ARRAY
OF
RECORD
EXIT
RETURN
WHILE
DO
THEN
ELSIF
ELSE
REPEAT
UNTIL
FOR
TO
BY
LOOP
CASE
OR
DIV
MOD
ABS
BOOLEAN
FALSE
INTEGER
ODD
READ
READLN
TRUE
WRITE
WRITELN
ABS
BOOLEAN
FALSE
INTEGER
ODD
READ
READLN
TRUE
WRITE
WRITELN
+
-
=
#
<
<=
>
>=
*
&
(
)
[
]
|

Ident -> Letter { Letter | Digit }

Integer -> Digit { Digit } | Digit { HexDigit } H

HexDigit -> Digit | A | B | C | D | E | F

**/

#include "const.h"

int numberOfReservedWords = 52;
int maxLengthOfReservedWords = 10;

char reservedWords[numberOfReservedWords][maxLengthOfReservedWords];
TokenTypes reservedWordsSymbols[numberOfReservedWords];

//Create a searchable array of Oberon's reserved words
void initReservedWords(){
	
    strcpy(reservedWords[0] , "MODULE");
    strcpy(reservedWords[1] , "BEGIN");
    strcpy(reservedWords[2] , "END");
    strcpy(reservedWords[3] , "CONST");
    strcpy(reservedWords[4] , "TYPE");
    strcpy(reservedWords[5] , "VAR");
    strcpy(reservedWords[6] , "PROCEDURE");
    strcpy(reservedWords[7] , "ARRAY");
    strcpy(reservedWords[8] , "OF");
    strcpy(reservedWords[9] , "RECORD");
    strcpy(reservedWords[10] , "EXIT");
    strcpy(reservedWords[11] , "RETURN");
    strcpy(reservedWords[12] , "WHILE");
    strcpy(reservedWords[13] , "DO");
    strcpy(reservedWords[14] , "THEN");
    strcpy(reservedWords[15] , "ELSIF");
    strcpy(reservedWords[16] , "ELSE");
    strcpy(reservedWords[17] , "REPEAT");
    strcpy(reservedWords[18] , "UNTIL");
    strcpy(reservedWords[19] , "FOR");
    strcpy(reservedWords[20] , "TO");
    strcpy(reservedWords[21] , "BY");
    strcpy(reservedWords[22] , "LOOP");
    strcpy(reservedWords[23] , "CASE");
    strcpy(reservedWords[24] , "OR");
    strcpy(reservedWords[25] , "DIV");
    strcpy(reservedWords[26] , "MOD");
    strcpy(reservedWords[27] , "ABS");
    strcpy(reservedWords[28] , "BOOLEAN");
    strcpy(reservedWords[29] , "FALSE");
    strcpy(reservedWords[30] , "INTEGER");
    strcpy(reservedWords[31] , "ODD");
    strcpy(reservedWords[32] , "READ");
    strcpy(reservedWords[33] , "READLN");
    strcpy(reservedWords[34] , "TRUE");
    strcpy(reservedWords[35] , "WRITE");
    strcpy(reservedWords[36] , "WRITELN");
    strcpy(reservedWords[37] , "<="); //Technically not reserved words
    strcpy(reservedWords[38] , ">="); //but our implementation makes this the easiest implementation
    strcpy(reservedWords[39] , '+');
    strcpy(reservedWords[40] , '-');
    strcpy(reservedWords[41] , '=');
    strcpy(reservedWords[42] , '#');
    strcpy(reservedWords[43] , '<');
    strcpy(reservedWords[44] , '>');
    strcpy(reservedWords[45] , '*');
    strcpy(reservedWords[46] , '&');
    strcpy(reservedWords[47] , '(');
    strcpy(reservedWords[48] , ')');
    strcpy(reservedWords[49] , '[');
    strcpy(reservedWords[50] , ']');
    strcpy(reservedWords[51] , '|');
}

//These are all mapped the appropriate reservedWords[] index
//Seriously though, make sure the reservedWords[] array and this next one match indices
void initSyms(){
    
    reservedWordsSymbols[0] = MODULE_SYM;
    reservedWordsSymbols[1] = BEGIN_SYM;
    reservedWordsSymbols[2] = END_SYM;
    reservedWordsSymbols[3] = CONST_SYM;
    reservedWordsSymbols[4] = TYPE_SYM;
    reservedWordsSymbols[5] = VAR_SYM;
    reservedWordsSymbols[6] = PROCEDURE_SYM;
    reservedWordsSymbols[7] = ARRAY_SYM;
    reservedWordsSymbols[8] = OF_SYM;
    reservedWordsSymbols[9] = RECORD_SYM;
    reservedWordsSymbols[10] = EXIT_SYM;
    reservedWordsSymbols[11] = RETURN_SYM;
    reservedWordsSymbols[12] = WHILE_SYM;
    reservedWordsSymbols[13] = DO_SYM;
    reservedWordsSymbols[14] = THEN_SYM;
    reservedWordsSymbols[15] = ELSIF_SYM;
    reservedWordsSymbols[16] = ELSE_SYM;
    reservedWordsSymbols[17] = REPEAT_SYM;
    reservedWordsSymbols[18] = UNTIL_SYM;
    reservedWordsSymbols[19] = FOR_SYM;
    reservedWordsSymbols[20] = TO_SYM;
    reservedWordsSymbols[21] = BY_SYM;
    reservedWordsSymbols[22] = LOOP_SYM;
    reservedWordsSymbols[23] = CASE_SYM;
    reservedWordsSymbols[24] = OR_SYM;
    reservedWordsSymbols[25] = DIV_SYM;
    reservedWordsSymbols[26] = MOD_SYM;
    reservedWordsSymbols[27] = ABS_SYM;
    reservedWordsSymbols[28] = BOOLEAN_SYM;
    reservedWordsSymbols[29] = FALSE_SYM;
    reservedWordsSymbols[30] = INTEGER_SYM;
    reservedWordsSymbols[31] = ODD_SYM;
    reservedWordsSymbols[32] = READ_SYM;
    reservedWordsSymbols[33] = READLN_SYM;
    reservedWordsSymbols[34] = TRUE_SYM;
    reservedWordsSymbols[35] = WRITE_SYM;
    reservedWordsSymbols[36] = WRITELN_SYM;
    reservedWordsSymbols[37] = lt;
    reservedWordsSymbols[38] = gt;
    reservedWordsSymbols[39] = plus     ; //'+';
    reservedWordsSymbols[40] = minus    ; //'-';
    reservedWordsSymbols[41] = equal    ; //'=';
    reservedWordsSymbols[42] = octothorp; //'#';
    reservedWordsSymbols[43] = lt       ; //'<';
    reservedWordsSymbols[44] = gt       ; //'>';
    reservedWordsSymbols[45] = star     ; //'*';
    reservedWordsSymbols[46] = ampersand; //'&';
    reservedWordsSymbols[47] = lparan   ; //'(';
    reservedWordsSymbols[48] = rparan   ; //')';
    reservedWordsSymbols[49] = lbrakt   ; //'[';
    reservedWordsSymbols[50] = rbrakt   ; //']';
    reservedWordsSymbols[51] = pipe     ; //'|';
    
}

//This just inits the arrays that are used to compare the inputted tokens
void initScanner() {
initReservedWords();
initSyms();
}

enum verifyToken(char* token){
    
    for(i=0;i<=52; ==i){ //check to see if token matches reserved word
        if(strcmp(reservedWords[i], token) == 0)
            return reservedWordsSymbols[i];
    }
    
    if(isLetter(*token)){
        return scanIdent(*token);
    }
    
    if(isdigit(*token)){
        return scanDigit(*token);
    }
    
}

enum scanIdent(char* token){
    
    int idx = 1; //we already checked first char
    
    while(*(token+idx)!= '\0'))
        if(isLetter(*(token+idx)) || isDigit(*(token+idx))){
            ++idx;
        } else {
            //TODO ERROR, NOT IDENT
        }
    
    return IDENT_SYM;        
}

enum scanNumber(char* token){
    
    int idx = 1; //we already checked first char
    int isHex = 0;
    
    while(*(token+idx)!= '\0'))
        if(isHex(*(token+idx)) || isDigit(*(token+idx))){
            if(isHex(*(token+idx))) //yes I am a terrible person
                isHex = 1;
            ++idx;
        } else {
            //TODO ERROR, NOT Number
        }
    
    if(isHex = 1)
        return HEX_SYM;
    
    return NUMBER_SYM;        
}


int isLetter(char c){
    
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'); //thank you ASCII
}

int isDigit(char c){
    
    return c >= 0 && c <= 9;
}

int isHex(char c){
    
    return (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'); //thank you ASCII
}

//stolen from c library, mwahaha
int strcmp(const char *s1, const char *s2){
    for ( ; *s1 == *s2; s1++, s2++)
	if (*s1 == '\0')
	    return 0;
    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}

//You can change this name at your leisure
//This is what is called to make the whole thing work
TokenList Scannerino(Tokenlist tokens){   
    
    initScanner();
    
    char* currentToken = tokens -> token;
    while (currentToken != NULL){
        
        tokens -> type = verifyToken(currentToken);
        tokens = tokens -> next;
        currentToken = tokens -> token;
    }
}