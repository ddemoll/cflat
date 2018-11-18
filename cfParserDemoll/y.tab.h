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
extern YYSTYPE yylval;
