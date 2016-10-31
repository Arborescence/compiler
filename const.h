#ifndef __CONST_H__
#define __CONST_H__

// Defines for boolean types. C doesn't have these!
#define bool  char
#define true  1
#define false 0

const int LINE_BUFFER_SIZE  = 256; // Max length of the line buffer
const int TOKEN_BUFFER_SIZE = 16;  // Max length of a token

enum TokenTypes {
    MODULE_SYM
    BEGIN_SYM
    END_SYM
    CONST_SYM
    TYPE_SYM
    VAR_SYM
    PROCEDURE_SYM
    ARRAY_SYM
    OF_SYM
    RECORD_SYM
    EXIT_SYM
    RETURN_SYM
    WHILE_SYM
    DO_SYM
    THEN_SYM
    ELSIF_SYM
    ELSE_SYM
    REPEAT_SYM
    UNTIL_SYM
    FOR_SYM
    TO_SYM
    BY_SYM
    LOOP_SYM
    CASE_SYM
    DIV_SYM     //DIV
    MOD_SYM     //MOD
    OR_SYM      //OR
    ABS_SYM
    BOOLEAN_SYM
    FALSE_SYM
    INTEGER_SYM
    ODD_SYM
    READ_SYM
    READLN_SYM
    TRUE_SYM
    WRITE_SYM
    WRITELN_SYM
    
    IDENT
    NUMBER
    STRING //NOT USED HERE
    
	lte         //<=
	gte         //>=
	plus        //+
    minus       //-
    equal       //=
    octothorp   //#
    lt          //<    
    gt          //>
    star        //*
    ampersand   //&
    lparan      //(
    rparan      //)
    lbrakt      //[
    rbrakt      //]
    pipe        //|
  
};



struct TokenList {
  char*              token;
  enum TokenTypes    type;
  struct TokenList*  next;
};


#endif
