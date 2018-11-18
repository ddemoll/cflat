%{
#define OLD__FILE_LIB 0

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include "y.tab.h"
enum Literal_Type_Names {INTEGER_TYPE, UNSIGNED_TYPE, LONG_TYPE, UNSIGNED_LONG_TYPE,
                         FLOAT_TYPE, DOUBLE_TYPE, STRING_TYPE } literal_type; 
//extern int yylex();  //usually declare, but yylex declaration/definition code placed in lex.yy.c
                       //along the code between this verbatim code, %{ ... %}.

#define TOKEN_INDEX_OFFSET 257

int reservedWordIndex = 0;

static char *mnemonic[ ] = {"", "_BOOL_TOK", "_COMPLEX_TOK", "_IMAGINARY_TOK",
"AUTO", "BREAK", "CASE", "CHAR", "CONST", "CONTINUE",
"DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN",
  "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "PRINTF",
  "REGISTER", "RESTRICT", "RETURN", "SCANF",
  "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE",
    "IDENTIFIER", "INT_LITERAL", "REAL_LITERAL", "STR_LITERAL",
  "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE",
  "SEMICOLON", "COMMA", "DOT", "PLUS", "MINUS", "STAR",
  "SLASH", "PERCENT", "AMPERSAND", "BAR", "CARET", "TILDE",
  "ARROW", "EXCLAIM", "DBL_PLUS", "DBL_MINUS", "DBL_LESS", "DBL_GTR",
  "QUESTION", "COLON", "TRIPLE_DOT", "DBL_AMP", "DBL_BAR", "DBL_EQL",
  "EXCL_EQ", "LESS", "LESS_EQ", "GTR", "GTR_EQ", "EQ",
  "PLUS_EQ", "MINUS_EQ", "STAR_EQ", "SLASH_EQ", "PERCENT_EQ", "AMP_EQ",
  "BAR_EQ", "CARET_EQ", "DBL_LESS_EQ", "DBL_GRT_EQ", "POUND", "DBL_POUND" };
  

#define NUM_OF_RESERVED_WORDS 39
static char *reserveWordTable[]=
       {"_Bool",     "_Complex",  "_Imaginary", 
       "auto",       "break",     "case",     "char",       "const",      
        "continue",   "default",   "do",       "double",     "else",     
        "enum",       "extern",    "float",    "for",        "goto",      
        "if",         "inline",    "int",      "long",       "printf",    
        "register",   "restrict",  "return",   "scanf",      "short",  
        "signed",     "sizeof",    "static",   "struct",     "switch",          
        "typedef",    "union",     "unsigned",  "void",      "volatile",   
        "while"         
    };
 
//filter identifiers and extract reserved words
static int ReserveWordLookup(char* yytext)
{
    int mid, first, last, cmp_test;
    first = 0;
    last = NUM_OF_RESERVED_WORDS - 1; //starting at index 0.
        
    while(first <= last){
        mid = (first + last)/2;
        cmp_test = strcmp(yytext, reserveWordTable[mid]);
            
        if (cmp_test < 0)
            last = mid-1;
        else if (cmp_test > 0)
            first = mid+1;
        else  
            return  mid ; 
    }
    // must be identifier
    yylval.ident_name = _strdup(yytext);
    return -1; /* Reserved Word not Found */
}
typedef  int Boolean;

int isUnsignedLit(char *text){
     return ( strchr( text,'u') || strchr( text,'U') );
}
int isLongLit(char  *text){
     return ( strchr( text,'l') || strchr( text,'L') );
}
int isFloatLit(char *text){
     return ( strchr( text,'f') || strchr( text,'F') );
}

//For processing string literals
#define MAX_STR_LIT_LEN 200
char buf[MAX_STR_LIT_LEN];
char *s;

//Utility for creating filenames based upon the source code name. 
char *changeFileNameExtension(const char *src, const char* extName)
 {
	 unsigned targetBodyNameLen = 0;
	 unsigned extNameLen = strlen(extName);

	 char *targetName = "";
	 char * pch = strrchr(src,'.'); //find last occurrence of . for extension name
	 if( pch != NULL){
		 targetBodyNameLen = pch-src;
	 }
	 else {
		 targetBodyNameLen = strlen(src)+1;
	 }

	 targetName = (char *)malloc(targetBodyNameLen+extNameLen+4);
	 targetName[targetBodyNameLen] = '\0';
	 strncpy(targetName, src, targetBodyNameLen);
	 targetName = strcat(targetName,".");
	 targetName = strcat(targetName, extName);
	 return targetName;
 }
FILE *listingFile;  //stores listfile descriptor. Used by main(), yylex(), functions inside lex.yy.c
                    //will be used by parse-error handling functions
int lines;          //keeps track of current line number of source
                    //used by main(), functions inside lex.yy.c (and future parser for error reporting)
main(int argc, char **argv)
{
    int token;
    char *infile;
    char *listing;
    errno_t fileErrorCode;
    
    extern FILE *yyin;    //declared here; defined in lex.yy.c
   // extern FILE *listingFile;   //good practice to declare here; defined globally 
   // extern int lines;           //good practice to declare here; defined globally
  
    if (argc>1) { 
        infile = argv[1];
#ifndef OLD_FILE_LIB 
        if( (fileErrorCode = fopen_s(&yyin, infile, "r")) != 0 ) { 
              fprintf(stderr,"Source file, %s, was not opened. Error code = %d\n", infile, fileErrorCode); 
              exit(	fileErrorCode ); 
        }
#else
     	if ((yyin = fopen(argv[1], "r"))==0) {
 			fprintf(stderr, "Error opening source file: %s", argv[1]);
 			exit(1);
 		}
#endif
    }
    else { infile = _strdup("yyin"); //establish default listing file for interactive mode
	       yyin = stdin;
	}
        

    listing = changeFileNameExtension(infile, "txt");
#ifndef OLD_FILE_LIB
	if( (fileErrorCode = fopen_s(&listingFile, listing, "w")) != 0 ) {
         fprintf(stderr,"Listing file, %s, was not opened. Error code = %d\n", listing, fileErrorCode);
         exit( 1 );
    }
#else 
	if ((listingFile = fopen(listing, "w"))==0) {
			fprintf(stderr,"Listing file, %s, was not opened.\n", listing);
			exit(1);
		}
#endif
    lines = 1;
	fprintf(listingFile, "%3d   ", lines); 
            
    if( !yyparse() )
{
printf("\nCompilation Complete. 0 errors reported.\n");
printf("Source Program = %4d lines.\n", lines);
fprintf(listingFile, "\nCompilation Complete. 0 errors reported.\n");
fprintf(listingFile, "Source Program = %4d lines.\n", lines);
fclose(yyin);
fclose(listingFile);
return 0;
}
else
{
printf("\nParsing failed. Error on line: %i at %s\n", lines, yytext);
fprintf(listingFile, "\nParsing failed. Error on line: %i at %s\n", lines, yytext);
fclose(listingFile);
return 2; //arbitrary non-zero error number
}
   
}

%}
letter [a-zA-Z_]
decNonZeroDigit  [1-9]
decDigit [0-9]
octalDigit [0-7]
hexDigit [0-9A-Fa-f]

%x STRING

%%
[ \t]+	 {fprintf(listingFile, "%s", yytext); }
{decNonZeroDigit}({decDigit})*([lL]?[uU]?|[uU]?[lL]?) |
0{octalDigit}*([lL]?[uU]?|[uU]?[lL]?) |			
("0X"|"0x"){hexDigit}+([lL]?[uU]?|[uU]?[lL]?)	 {      fprintf(listingFile, "%s", yytext);
                                                        literal_type  = INTEGER_TYPE;
                                                        if( isLongLit(yytext) ) {
                                                                yylval.l_int_value = strtol(yytext, NULL, 0); 
                                                                literal_type = LONG_TYPE;
                                                        }
                                                        if( isUnsignedLit(yytext) ) { /*check for being also long*/                                                    
                                                                if( literal_type == LONG_TYPE  ){
                                                                    literal_type = UNSIGNED_LONG_TYPE;
                                                                    yylval.ul_int_value = strtoul(yytext,NULL,0);
                                                                 }
                                                                 else{
                                                                    literal_type = UNSIGNED_TYPE;
                                                                    yylval.u_int_value = strtoul(yytext,NULL,0);
                                                                 }
                                                        }
                                                        else  /* Possible long or (signed) int */
                                                                if(literal_type != LONG_TYPE){
                                                                       literal_type = INTEGER_TYPE;
                                                                       yylval.int_value =  strtol(yytext,NULL,0);
                                                                }                  
                                                       return INT_LITERAL; }
{decDigit}*\.{decDigit}+([eE][-+]?{decDigit}+)?[fF]?   {    fprintf(listingFile, "%s", yytext);
														    literal_type  = DOUBLE_TYPE;
														    if( isFloatLit(yytext) ) {
                                                                yylval.float_value = strtof(yytext, NULL);
																literal_type = FLOAT_TYPE;
														    }
														    else {
														        yylval.double_value = strtod(yytext,NULL);
														    }
														    return REAL_LITERAL; 
                                                         }
 {decDigit}+(e|E)[-+]?{decDigit}+[fF]?   {    fprintf(listingFile, "%s", yytext);
														    literal_type  = DOUBLE_TYPE;
														    if( isFloatLit(yytext) ) {
                                                                yylval.float_value = strtof(yytext, NULL);
																literal_type = FLOAT_TYPE;
														    }
														    else {
														        yylval.double_value = strtod(yytext,NULL);
														    }
														    return REAL_LITERAL; 
                                            }

{letter}({letter}|{decDigit})*     { fprintf(listingFile, "%s", yytext);   
        return (reservedWordIndex = ReserveWordLookup(yytext))< 0 ?  IDENTIFIER  : (reservedWordIndex  + TOKEN_INDEX_OFFSET); 
                           /* return IDENTIFIER  if yytext not in table */
        }
        
\"           { BEGIN STRING; buf[0] = 0; s = buf; }
<STRING>\\n  { *s++ = '\\'; *s++ = 'n'; }
<STRING>\\t  { *s++ = '\\'; *s++ = 't'; }
<STRING>\\\" { *s++ = '\\'; *s++ = '\"'; }
<STRING>\"   { *s = 0; 
                fprintf(listingFile, "\"%s\"", buf); 
                yylval.string_value = _strdup(buf);
                BEGIN 0; 
                return STR_LITERAL; }
<STRING>.    {  *s++ = *yytext; }
<STRING>\n   {  *s = 0;
                fprintf(listingFile, "\"%s\n", buf);  
                fprintf(listingFile, "invalid string shown above\n"); printf("invalid string\n"); 
                lines++; fprintf(listingFile, "%3d   ", lines);
                yylval.string_value = _strdup(buf); 
                BEGIN 0; 
                return STR_LITERAL; }
       
"("		{fprintf(listingFile, "%s", yytext); return LPAREN;}
")"		{fprintf(listingFile, "%s", yytext); return RPAREN;}
"["		{fprintf(listingFile, "%s", yytext); return LBRACKET;}
"]"		{fprintf(listingFile, "%s", yytext); return RBRACKET;}
"{"		{fprintf(listingFile, "%s", yytext); return LBRACE;}
"}"		{fprintf(listingFile, "%s", yytext); return RBRACE;}
";"		{fprintf(listingFile, "%s", yytext); return SEMICOLON;}
","		{fprintf(listingFile, "%s", yytext); return COMMA;}
"."		{fprintf(listingFile, "%s", yytext); return DOT;}
"+"		{fprintf(listingFile, "%s", yytext); return PLUS;}
"-"		{fprintf(listingFile, "%s", yytext); return MINUS;}
"*"		{fprintf(listingFile, "%s", yytext); return STAR;}
"/"		{fprintf(listingFile, "%s", yytext); return SLASH;}
"%"		{fprintf(listingFile, "%s", yytext); return PERCENT;}
"&"		{fprintf(listingFile, "%s", yytext); return AMPERSAND;}
"|"		{fprintf(listingFile, "%s", yytext); return BAR;}
"^"		{fprintf(listingFile, "%s", yytext); return CARET;}
"~"		{fprintf(listingFile, "%s", yytext); return TILDE;}
"->"	{fprintf(listingFile, "%s", yytext); return ARROW;}
"!"		{fprintf(listingFile, "%s", yytext); return EXCLAIM;}
"++"	{fprintf(listingFile, "%s", yytext); return DBL_PLUS;}
"--"	{fprintf(listingFile, "%s", yytext); return DBL_MINUS;}
"<<"	{fprintf(listingFile, "%s", yytext); return DBL_LESS;}
">>"	{fprintf(listingFile, "%s", yytext); return DBL_GTR;}
"?"		{fprintf(listingFile, "%s", yytext); return QUESTION;}
":"		{fprintf(listingFile, "%s", yytext); return COLON;}
"..."	{fprintf(listingFile, "%s", yytext); return TRIPLE_DOT;}
"&&"	{fprintf(listingFile, "%s", yytext); return DBL_AMP;}
"||"	{fprintf(listingFile, "%s", yytext); return DBL_BAR;}
"=="	{fprintf(listingFile, "%s", yytext); return DBL_EQ;}
"!="	{fprintf(listingFile, "%s", yytext); return EXCL_EQ;}
"<"		{fprintf(listingFile, "%s", yytext); return LESS;}
"<="	{fprintf(listingFile, "%s", yytext); return LESS_EQ;}
">"		{fprintf(listingFile, "%s", yytext); return GTR;}
">="	{fprintf(listingFile, "%s", yytext); return GTR_EQ;}
"="		{fprintf(listingFile, "%s", yytext); return EQ;}
"+="	{fprintf(listingFile, "%s", yytext); return PLUS_EQ;}
"-="	{fprintf(listingFile, "%s", yytext); return MINUS_EQ;}
"*="	{fprintf(listingFile, "%s", yytext); return STAR_EQ;}
"/="	{fprintf(listingFile, "%s", yytext); return SLASH_EQ;}
"%="	{fprintf(listingFile, "%s", yytext); return PERCENT_EQ;}
"&="	{fprintf(listingFile, "%s", yytext); return AMP_EQ;}
"|="	{fprintf(listingFile, "%s", yytext); return BAR_EQ;}
"^="	{fprintf(listingFile, "%s", yytext); return CARET_EQ;}
"<<="	{fprintf(listingFile, "%s", yytext); return DBL_LESS_EQ;}
">>="	{fprintf(listingFile, "%s", yytext); return DBL_GTR_EQ;}
"#"		{fprintf(listingFile, "%s", yytext); return POUND;}
"##"	{fprintf(listingFile, "%s", yytext); return DBL_POUND;}
"<:"	{fprintf(listingFile, "%s", yytext); return LBRACKET;}
":>"	{fprintf(listingFile, "%s", yytext); return RBRACKET;}
"<%"	{fprintf(listingFile, "%s", yytext); return LBRACE;}
"%>"	{fprintf(listingFile, "%s", yytext); return RBRACE;}
"%:"	{fprintf(listingFile, "%s", yytext); return POUND;}
"%:%:"	{fprintf(listingFile, "%s", yytext); return DBL_POUND;}
\n      {fprintf(listingFile, "%s", yytext);  lines++; fprintf(listingFile, "%3d   ", lines);   }
"//".* {fprintf(listingFile, "%s", yytext);    }  
.		 {fprintf(listingFile, "%s", yytext); printf("Lex Error: Illegal Character %s\n", yytext);}

%%


