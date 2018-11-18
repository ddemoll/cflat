#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "tokens.y"
#include<stdio.h> 
void yyerror(char *);
#line 6 "tokens.y"
typedef union{
  int          int_value;
  unsigned      u_int_value;
  long          l_int_value;
  unsigned long ul_int_value;
  float			float_value;
  double		double_value;
  char*         string_value;
  char*         ident_name;
} YYSTYPE;
#line 26 "y.tab.c"
#define _BOOL_TOK 257
#define _COMPLEX_TOK 258
#define _IMAGINARY_TOK 259
#define AUTO 260
#define BREAK 261
#define CASE 262
#define CHAR 263
#define CONST 264
#define CONTINUE 265
#define DEFAULT 266
#define DO 267
#define DOUBLE 268
#define ELSE 269
#define ENUM 270
#define EXTERN 271
#define FLOAT 272
#define FOR 273
#define GOTO 274
#define IF 275
#define INLINE 276
#define INT 277
#define LONG 278
#define PRINTF 279
#define REGISTER 280
#define RESTRICT 281
#define RETURN 282
#define SCANF 283
#define SHORT 284
#define SIGNED 285
#define SIZEOF 286
#define STATIC 287
#define STRUCT 288
#define SWITCH 289
#define TYPEDEF 290
#define UNION 291
#define UNSIGNED 292
#define VOID 293
#define VOLATILE 294
#define WHILE 295
#define IDENTIFIER 296
#define INT_LITERAL 297
#define REAL_LITERAL 298
#define STR_LITERAL 299
#define LPAREN 300
#define RPAREN 301
#define LBRACKET 302
#define RBRACKET 303
#define LBRACE 304
#define RBRACE 305
#define SEMICOLON 306
#define COMMA 307
#define DOT 308
#define PLUS 309
#define MINUS 310
#define STAR 311
#define SLASH 312
#define PERCENT 313
#define AMPERSAND 314
#define BAR 315
#define CARET 316
#define TILDE 317
#define ARROW 318
#define EXCLAIM 319
#define DBL_PLUS 320
#define DBL_MINUS 321
#define DBL_LESS 322
#define DBL_GTR 323
#define QUESTION 324
#define COLON 325
#define TRIPLE_DOT 326
#define DBL_AMP 327
#define DBL_BAR 328
#define DBL_EQ 329
#define EXCL_EQ 330
#define LESS 331
#define LESS_EQ 332
#define GTR 333
#define GTR_EQ 334
#define EQ 335
#define PLUS_EQ 336
#define MINUS_EQ 337
#define STAR_EQ 338
#define SLASH_EQ 339
#define PERCENT_EQ 340
#define AMP_EQ 341
#define BAR_EQ 342
#define CARET_EQ 343
#define DBL_LESS_EQ 344
#define DBL_GTR_EQ 345
#define POUND 346
#define DBL_POUND 347
#define LOWER_THAN_ELSE 348
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    2,    2,    7,    7,    3,    3,
    6,    6,    6,    6,    6,    6,    9,    9,    9,   10,
   10,   10,   10,   10,   11,    8,    8,   12,   12,   13,
    4,    4,    4,    4,    4,    4,   16,   16,   18,   15,
   15,   19,   19,   20,   20,   21,   21,    5,    5,    5,
    5,   22,   22,   22,   22,   22,   22,   22,   22,   23,
   23,   17,   14,   14,   26,   26,   26,   26,   26,   24,
   27,   27,   28,   28,   29,   29,   29,   30,   30,   30,
   30,   30,   31,   31,   31,   32,   32,   32,   32,   25,
   25,   25,   25,   25,   25,   33,   33,   33,   33,   33,
   33,   33,   33,   34,   34,   34,   34,   34,
};
short yylen[] = {                                         2,
    1,    2,    1,    1,    2,    3,    1,    2,    2,    3,
    2,    1,    1,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    1,    2,    2,
    1,    3,    4,    4,    4,    3,    1,    3,    2,    1,
    3,    1,    2,    1,    3,    1,    2,    4,    3,    3,
    2,    1,    5,    7,    5,    2,    3,    2,    1,    1,
    3,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    3,    1,    3,    1,    3,    3,    1,    3,    3,
    3,    3,    1,    3,    3,    1,    3,    3,    3,    1,
    2,    2,    2,    2,    2,    1,    4,    4,    4,    4,
    3,    2,    2,    1,    1,    1,    1,    3,
};
short yydefred[] = {                                      0,
   17,   25,   24,   19,   23,   20,   22,   18,   21,   31,
    0,    1,    3,    4,    0,    0,   12,   13,   16,    2,
    0,    0,    0,    5,    9,    0,    0,   11,   14,   15,
   26,   32,   42,    0,    0,   37,    0,    0,    0,  104,
  105,  106,  107,    0,   36,    0,    0,    0,    0,    0,
    0,   62,   86,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   51,   59,    7,   52,    0,    0,
    0,    0,   46,   63,    0,    0,    6,   29,   10,    0,
   33,    0,   34,    0,   39,   43,    0,    0,    0,   94,
   93,   95,   91,   92,   35,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  102,  103,
    0,    0,    0,   56,    0,    0,    0,   49,    8,    0,
   58,   50,   47,   65,   66,   67,   68,   69,    0,   30,
   27,    0,   38,    0,   60,    0,   44,    0,  108,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   87,
   88,   89,  101,    0,    0,    0,   57,    0,   48,   64,
   99,    0,   98,    0,  100,   97,    0,    0,   61,   45,
    0,   55,    0,   54,
};
short yydgoto[] = {                                      11,
   12,   13,   14,   15,   68,   16,   70,   27,   17,   18,
   19,   31,   78,   71,   34,   35,   51,   36,   37,  138,
   72,   73,  136,   74,   75,  129,   54,   55,   56,   57,
   58,   59,   60,   61,
};
short yysindex[] = {                                    295,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  295,    0,    0,    0, -282,   92,    0,    0,    0,    0,
 -128,   93, -144,    0,    0, -291, -216,    0,    0,    0,
    0,    0,    0, -284, -261,    0, -244, -298, -285,    0,
    0,    0,    0,  155,    0,  155,  155,  155,  155,  155,
 -268,    0,    0, -262, -233, -204, -133, -180, -166, -184,
 -263, -183,  121, -181,    0,    0,    0,    0,   92,  -90,
 -174,  -58,    0,    0, -103,  155,    0,    0,    0, -137,
    0, -247,    0, -247,    0,    0,  155, -127, -179,    0,
    0,    0,    0,    0,    0,  155,  155,  155,  155,  155,
  155,  155,  155,  155,  155,  155,  155,  155,    0,    0,
  149,  155,  155,    0, -143,  155, -288,    0,    0,  -26,
    0,    0,    0,    0,    0,    0,    0,    0,  155,    0,
    0, -247,    0, -244,    0, -223,    0, -219,    0, -233,
 -204, -133, -133, -180, -180, -180, -180, -166, -166,    0,
    0,    0,    0, -212, -132, -129,    0, -122,    0,    0,
    0,  155,    0, -116,    0,    0,   38,   38,    0,    0,
  -86,    0,   38,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -165,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -209,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -220,  228, -227, -265,  361,  283,  215,
  176,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  268,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -165,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -208,    0,    0,    0,    0,    0,    0,    0,  457,
  192,   79,  427,  369,  377,  411,  419,  317,  327,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6,    0,    0,    0,
};
short yygindex[] = {                                      0,
  173,    0,  -20,  -10,    1,  -19,    0,    0,   -9,  -11,
   -8,  106,    0,  -44,    0,    0,    0,  107,   -7,    0,
  120,  -71,   83,  174,    7,    0,    0,   99,  114,   59,
  164,   63,    0,    0,
};
#define YYTABLESIZE 785
short yytable[] = {                                      89,
  123,   87,   67,   69,   29,   26,   28,   30,   21,   33,
   22,   21,   23,   22,   88,   24,   81,   21,  115,   22,
    3,   23,   82,    3,    5,   86,   77,    5,   53,    6,
    7,  130,    6,    7,   95,   75,  111,   75,  112,   83,
   75,   75,  135,   76,    9,   84,   76,    9,  123,  119,
   69,   85,   90,   91,   92,   93,   94,   29,  117,   28,
   30,   75,   75,   75,   75,   96,  135,  155,  156,  117,
   33,  158,   33,   73,  132,   73,  134,  161,   73,   73,
   70,  163,   70,  162,  160,   70,   70,  164,  165,   79,
   80,   40,   41,   97,  162,  171,  172,   40,   41,   73,
   73,  174,   53,   53,   53,   53,   53,   53,   53,   53,
   53,   53,  150,  151,  152,    1,  113,  169,  116,    2,
   86,  139,   86,    3,   98,   99,    4,    5,  104,  105,
   62,  121,    6,    7,   38,  109,  110,   63,   39,    3,
   28,   28,    8,    5,  106,  107,  108,    9,    6,    7,
   64,   40,   41,   42,   43,   44,  142,  143,   10,   23,
   65,   66,  157,    9,   46,   47,  148,  149,  137,    1,
  166,  167,   32,    2,   48,   49,   50,    3,  168,  170,
    4,    5,  173,   20,   62,  131,    6,    7,   38,  120,
  133,   63,   39,  154,  140,   52,    8,  100,  101,  102,
  103,    9,    0,    0,   64,   40,   41,   42,   43,   44,
  141,    0,    0,   23,  118,   66,   62,    0,   46,   47,
   38,    0,    0,   63,   39,    0,    0,    0,   48,   49,
   50,  124,  125,  126,  127,  128,   64,   40,   41,   42,
   43,   44,    0,    0,    0,   23,  122,   66,   62,    0,
   46,   47,   38,    0,    0,   63,   39,    0,    0,    0,
   48,   49,   50,  144,  145,  146,  147,    0,   64,   40,
   41,   42,   43,   44,    0,    0,    0,   23,  159,   66,
   53,    0,   46,   47,   53,    0,    0,   53,   53,    0,
    0,    0,   48,   49,   50,    0,    0,    0,    0,    0,
   53,   53,   53,   53,   53,   53,    0,    0,    0,   53,
   53,   53,   62,    0,   53,   53,   38,    0,    0,   63,
   39,    0,    0,    0,   53,   53,   53,    0,    0,    0,
    0,    0,   64,   40,   41,   42,   43,   44,    0,    0,
    0,   23,    0,   66,    0,    0,   46,   47,    0,    0,
    0,    1,    0,    0,    0,    2,   48,   49,   50,    3,
    0,    0,    4,    5,    0,    0,    0,    0,    6,    7,
    0,   38,    0,    0,    0,   39,    0,    0,    8,   76,
    0,   76,    0,    9,   76,   76,    0,   10,   40,   41,
   42,   43,   44,    0,    0,   45,    0,   25,    0,   38,
    0,   46,   47,   39,    0,   76,   76,   76,   76,    0,
    0,   48,   49,   50,    0,    0,   40,   41,   42,   43,
   44,    0,    0,    0,    0,    0,  114,   38,    0,   46,
   47,   39,    0,   38,    0,    0,    0,   39,    0,   48,
   49,   50,    0,    0,   40,   41,   42,   43,   44,  153,
   40,   41,   42,   43,   44,    0,    0,   46,   47,    0,
    0,    0,    0,   46,   47,    0,    0,   48,   49,   50,
    0,    0,    0,   48,   49,   50,   96,    0,   96,    0,
    0,   96,   96,    0,   96,   96,   96,   96,   96,    0,
    0,    0,   74,    0,   74,   96,   96,   74,   74,    0,
    0,    0,   96,   96,   96,   96,   96,   96,   96,   96,
   96,   96,   96,   96,   96,   90,    0,   90,   74,   74,
   90,   90,    0,   90,   90,   90,   90,   90,   71,    0,
   71,    0,    0,   71,   71,    0,    0,    0,    0,    0,
    0,   90,   90,   90,   90,   90,   90,   90,   90,   90,
   90,   90,   90,   90,    1,   71,    0,    0,    2,    0,
    0,    0,    3,    0,    0,    4,    5,    0,   86,    0,
   86,    6,    7,   86,   86,    0,   86,   86,   86,   86,
   86,    8,    0,   83,    0,   83,    9,    0,   83,   83,
   10,   83,   83,    0,   86,   86,   86,   86,   86,   86,
   86,   86,    0,    0,    0,    0,    0,    0,    0,   83,
   83,   83,   83,   83,   83,   83,   83,   84,    0,   84,
    0,    0,   84,   84,    0,   84,   84,   85,    0,   85,
    0,    0,   85,   85,    0,   85,   85,    0,    0,    0,
    0,    0,    0,   84,   84,   84,   84,   84,   84,   84,
   84,    0,    0,   85,   85,   85,   85,   85,   85,   85,
   85,   78,    0,   78,    0,    0,   78,   78,    0,   79,
    0,   79,    0,    0,   79,   79,    0,   81,    0,   81,
    0,    0,   81,   81,    0,    0,    0,   78,   78,   78,
   78,   78,   78,   78,   78,   79,   79,   79,   79,   79,
   79,   79,   79,   81,   81,   81,   81,   81,   81,   81,
   81,   80,    0,   80,    0,    0,   80,   80,    0,   82,
    0,   82,    0,    0,   82,   82,    0,   77,    0,   77,
    0,    0,   77,   77,    0,    0,    0,   80,   80,   80,
   80,   80,   80,   80,   80,   82,   82,   82,   82,   82,
   82,   82,   82,   77,   77,   77,   77,   72,    0,   72,
    0,    0,   72,   72,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   72,
};
short yycheck[] = {                                      44,
   72,  300,   23,   23,   16,   16,   16,   16,  300,   21,
  302,  300,  304,  302,  300,   15,  301,  300,   63,  302,
  268,  304,  307,  268,  272,   37,   26,  272,   22,  277,
  278,   76,  277,  278,  303,  301,  300,  303,  302,  301,
  306,  307,   87,  335,  292,  307,  335,  292,  120,   70,
   70,  296,   46,   47,   48,   49,   50,   69,   69,   69,
   69,  327,  328,  329,  330,  328,  111,  112,  113,   80,
   82,  116,   84,  301,   82,  303,   84,  301,  306,  307,
  301,  301,  303,  307,  129,  306,  307,  307,  301,  306,
  307,  301,  301,  327,  307,  167,  168,  307,  307,  327,
  328,  173,   96,   97,   98,   99,  100,  101,  102,  103,
  104,  105,  106,  107,  108,  260,  300,  162,  300,  264,
  132,  301,  134,  268,  329,  330,  271,  272,  309,  310,
  275,  306,  277,  278,  279,  320,  321,  282,  283,  268,
  306,  307,  287,  272,  311,  312,  313,  292,  277,  278,
  295,  296,  297,  298,  299,  300,   98,   99,  296,  304,
  305,  306,  306,  292,  309,  310,  104,  105,  296,  260,
  303,  301,  301,  264,  319,  320,  321,  268,  301,  296,
  271,  272,  269,   11,  275,   80,  277,  278,  279,   70,
   84,  282,  283,  111,   96,   22,  287,  331,  332,  333,
  334,  292,   -1,   -1,  295,  296,  297,  298,  299,  300,
   97,   -1,   -1,  304,  305,  306,  275,   -1,  309,  310,
  279,   -1,   -1,  282,  283,   -1,   -1,   -1,  319,  320,
  321,  335,  336,  337,  338,  339,  295,  296,  297,  298,
  299,  300,   -1,   -1,   -1,  304,  305,  306,  275,   -1,
  309,  310,  279,   -1,   -1,  282,  283,   -1,   -1,   -1,
  319,  320,  321,  100,  101,  102,  103,   -1,  295,  296,
  297,  298,  299,  300,   -1,   -1,   -1,  304,  305,  306,
  275,   -1,  309,  310,  279,   -1,   -1,  282,  283,   -1,
   -1,   -1,  319,  320,  321,   -1,   -1,   -1,   -1,   -1,
  295,  296,  297,  298,  299,  300,   -1,   -1,   -1,  304,
  305,  306,  275,   -1,  309,  310,  279,   -1,   -1,  282,
  283,   -1,   -1,   -1,  319,  320,  321,   -1,   -1,   -1,
   -1,   -1,  295,  296,  297,  298,  299,  300,   -1,   -1,
   -1,  304,   -1,  306,   -1,   -1,  309,  310,   -1,   -1,
   -1,  260,   -1,   -1,   -1,  264,  319,  320,  321,  268,
   -1,   -1,  271,  272,   -1,   -1,   -1,   -1,  277,  278,
   -1,  279,   -1,   -1,   -1,  283,   -1,   -1,  287,  301,
   -1,  303,   -1,  292,  306,  307,   -1,  296,  296,  297,
  298,  299,  300,   -1,   -1,  303,   -1,  306,   -1,  279,
   -1,  309,  310,  283,   -1,  327,  328,  329,  330,   -1,
   -1,  319,  320,  321,   -1,   -1,  296,  297,  298,  299,
  300,   -1,   -1,   -1,   -1,   -1,  306,  279,   -1,  309,
  310,  283,   -1,  279,   -1,   -1,   -1,  283,   -1,  319,
  320,  321,   -1,   -1,  296,  297,  298,  299,  300,  301,
  296,  297,  298,  299,  300,   -1,   -1,  309,  310,   -1,
   -1,   -1,   -1,  309,  310,   -1,   -1,  319,  320,  321,
   -1,   -1,   -1,  319,  320,  321,  301,   -1,  303,   -1,
   -1,  306,  307,   -1,  309,  310,  311,  312,  313,   -1,
   -1,   -1,  301,   -1,  303,  320,  321,  306,  307,   -1,
   -1,   -1,  327,  328,  329,  330,  331,  332,  333,  334,
  335,  336,  337,  338,  339,  301,   -1,  303,  327,  328,
  306,  307,   -1,  309,  310,  311,  312,  313,  301,   -1,
  303,   -1,   -1,  306,  307,   -1,   -1,   -1,   -1,   -1,
   -1,  327,  328,  329,  330,  331,  332,  333,  334,  335,
  336,  337,  338,  339,  260,  328,   -1,   -1,  264,   -1,
   -1,   -1,  268,   -1,   -1,  271,  272,   -1,  301,   -1,
  303,  277,  278,  306,  307,   -1,  309,  310,  311,  312,
  313,  287,   -1,  301,   -1,  303,  292,   -1,  306,  307,
  296,  309,  310,   -1,  327,  328,  329,  330,  331,  332,
  333,  334,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  327,
  328,  329,  330,  331,  332,  333,  334,  301,   -1,  303,
   -1,   -1,  306,  307,   -1,  309,  310,  301,   -1,  303,
   -1,   -1,  306,  307,   -1,  309,  310,   -1,   -1,   -1,
   -1,   -1,   -1,  327,  328,  329,  330,  331,  332,  333,
  334,   -1,   -1,  327,  328,  329,  330,  331,  332,  333,
  334,  301,   -1,  303,   -1,   -1,  306,  307,   -1,  301,
   -1,  303,   -1,   -1,  306,  307,   -1,  301,   -1,  303,
   -1,   -1,  306,  307,   -1,   -1,   -1,  327,  328,  329,
  330,  331,  332,  333,  334,  327,  328,  329,  330,  331,
  332,  333,  334,  327,  328,  329,  330,  331,  332,  333,
  334,  301,   -1,  303,   -1,   -1,  306,  307,   -1,  301,
   -1,  303,   -1,   -1,  306,  307,   -1,  301,   -1,  303,
   -1,   -1,  306,  307,   -1,   -1,   -1,  327,  328,  329,
  330,  331,  332,  333,  334,  327,  328,  329,  330,  331,
  332,  333,  334,  327,  328,  329,  330,  301,   -1,  303,
   -1,   -1,  306,  307,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  328,
};
#define YYFINAL 11
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 348
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"_BOOL_TOK","_COMPLEX_TOK",
"_IMAGINARY_TOK","AUTO","BREAK","CASE","CHAR","CONST","CONTINUE","DEFAULT","DO",
"DOUBLE","ELSE","ENUM","EXTERN","FLOAT","FOR","GOTO","IF","INLINE","INT","LONG",
"PRINTF","REGISTER","RESTRICT","RETURN","SCANF","SHORT","SIGNED","SIZEOF",
"STATIC","STRUCT","SWITCH","TYPEDEF","UNION","UNSIGNED","VOID","VOLATILE",
"WHILE","IDENTIFIER","INT_LITERAL","REAL_LITERAL","STR_LITERAL","LPAREN",
"RPAREN","LBRACKET","RBRACKET","LBRACE","RBRACE","SEMICOLON","COMMA","DOT",
"PLUS","MINUS","STAR","SLASH","PERCENT","AMPERSAND","BAR","CARET","TILDE",
"ARROW","EXCLAIM","DBL_PLUS","DBL_MINUS","DBL_LESS","DBL_GTR","QUESTION",
"COLON","TRIPLE_DOT","DBL_AMP","DBL_BAR","DBL_EQ","EXCL_EQ","LESS","LESS_EQ",
"GTR","GTR_EQ","EQ","PLUS_EQ","MINUS_EQ","STAR_EQ","SLASH_EQ","PERCENT_EQ",
"AMP_EQ","BAR_EQ","CARET_EQ","DBL_LESS_EQ","DBL_GTR_EQ","POUND","DBL_POUND",
"LOWER_THAN_ELSE",
};
char *yyrule[] = {
"$accept : c_flat_trans_unit",
"c_flat_trans_unit : external_decl_defn",
"c_flat_trans_unit : c_flat_trans_unit external_decl_defn",
"external_decl_defn : function_decl_defn",
"external_decl_defn : declaration",
"function_decl_defn : declarator compound_statement",
"function_decl_defn : declaration_specifiers declarator compound_statement",
"declaration_list : declaration",
"declaration_list : declaration_list declaration",
"declaration : declaration_specifiers SEMICOLON",
"declaration : declaration_specifiers init_declarator_list SEMICOLON",
"declaration_specifiers : declaration_specifiers storage_class_specifier",
"declaration_specifiers : storage_class_specifier",
"declaration_specifiers : type_specifier",
"declaration_specifiers : declaration_specifiers type_specifier",
"declaration_specifiers : declaration_specifiers type_qualifier",
"declaration_specifiers : type_qualifier",
"storage_class_specifier : AUTO",
"storage_class_specifier : STATIC",
"storage_class_specifier : EXTERN",
"type_specifier : INT",
"type_specifier : UNSIGNED",
"type_specifier : LONG",
"type_specifier : FLOAT",
"type_specifier : DOUBLE",
"type_qualifier : CONST",
"init_declarator_list : init_declarator",
"init_declarator_list : init_declarator_list COMMA init_declarator",
"init_declarator : declarator",
"init_declarator : declarator initializer",
"initializer : EQ expression",
"declarator : IDENTIFIER",
"declarator : declarator LPAREN RPAREN",
"declarator : declarator LPAREN parameter_type_list RPAREN",
"declarator : declarator LPAREN formal_parm_list RPAREN",
"declarator : declarator LBRACKET const_expression RBRACKET",
"declarator : declarator LBRACKET RBRACKET",
"formal_parm_list : formal_parameter",
"formal_parm_list : formal_parm_list COMMA formal_parameter",
"formal_parameter : type_specifier_list IDENTIFIER",
"parameter_type_list : type_specifier_list",
"parameter_type_list : parameter_type_list COMMA type_specifier_list",
"type_specifier_list : type_specifier",
"type_specifier_list : type_specifier_list type_specifier",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list COMMA IDENTIFIER",
"statement_list : statement",
"statement_list : statement_list statement",
"compound_statement : LBRACE declaration_list statement_list RBRACE",
"compound_statement : LBRACE declaration_list RBRACE",
"compound_statement : LBRACE statement_list RBRACE",
"compound_statement : LBRACE RBRACE",
"statement : compound_statement",
"statement : IF LPAREN expression RPAREN statement",
"statement : IF LPAREN expression RPAREN statement ELSE statement",
"statement : WHILE LPAREN expression RPAREN statement",
"statement : RETURN SEMICOLON",
"statement : RETURN expression SEMICOLON",
"statement : expression SEMICOLON",
"statement : SEMICOLON",
"expression_list : expression",
"expression_list : expression_list COMMA expression",
"const_expression : conditional_expr",
"expression : conditional_expr",
"expression : unary_expr assignment_op expression",
"assignment_op : EQ",
"assignment_op : PLUS_EQ",
"assignment_op : MINUS_EQ",
"assignment_op : STAR_EQ",
"assignment_op : SLASH_EQ",
"conditional_expr : logical_or_expr",
"logical_or_expr : logical_and_expr",
"logical_or_expr : logical_or_expr DBL_BAR logical_and_expr",
"logical_and_expr : equality_expr",
"logical_and_expr : logical_and_expr DBL_AMP equality_expr",
"equality_expr : relational_expr",
"equality_expr : equality_expr DBL_EQ relational_expr",
"equality_expr : equality_expr EXCL_EQ relational_expr",
"relational_expr : add_expr",
"relational_expr : relational_expr LESS add_expr",
"relational_expr : relational_expr GTR add_expr",
"relational_expr : relational_expr LESS_EQ add_expr",
"relational_expr : relational_expr GTR_EQ add_expr",
"add_expr : mult_expr",
"add_expr : add_expr PLUS mult_expr",
"add_expr : add_expr MINUS mult_expr",
"mult_expr : unary_expr",
"mult_expr : mult_expr STAR unary_expr",
"mult_expr : mult_expr SLASH unary_expr",
"mult_expr : mult_expr PERCENT unary_expr",
"unary_expr : postfix_expr",
"unary_expr : DBL_PLUS unary_expr",
"unary_expr : DBL_MINUS unary_expr",
"unary_expr : MINUS unary_expr",
"unary_expr : PLUS unary_expr",
"unary_expr : EXCLAIM unary_expr",
"postfix_expr : primary_expr",
"postfix_expr : primary_expr LBRACKET expression RBRACKET",
"postfix_expr : SCANF LPAREN identifier_list RPAREN",
"postfix_expr : PRINTF LPAREN expression_list RPAREN",
"postfix_expr : primary_expr LPAREN expression_list RPAREN",
"postfix_expr : primary_expr LPAREN RPAREN",
"postfix_expr : postfix_expr DBL_PLUS",
"postfix_expr : postfix_expr DBL_MINUS",
"primary_expr : IDENTIFIER",
"primary_expr : INT_LITERAL",
"primary_expr : REAL_LITERAL",
"primary_expr : STR_LITERAL",
"primary_expr : LPAREN expression RPAREN",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 184 "tokens.y"
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
#line 546 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
