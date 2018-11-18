%{
#include<stdio.h> 
void yyerror(char *);
%}

%union{
  int          int_value;
  unsigned      u_int_value;
  long          l_int_value;
  unsigned long ul_int_value;
  float			float_value;
  double		double_value;
  char*         string_value;
  char*         ident_name;
}
%token _BOOL_TOK _COMPLEX_TOK _IMAGINARY_TOK
%token AUTO BREAK CASE CHAR CONST CONTINUE
%token DEFAULT DO DOUBLE ELSE ENUM EXTERN
%token FLOAT FOR GOTO IF INLINE INT LONG
%token PRINTF REGISTER RESTRICT RETURN
%token SCANF SHORT SIGNED SIZEOF STATIC STRUCT SWITCH
%token TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE
%token IDENTIFIER INT_LITERAL REAL_LITERAL STR_LITERAL  
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE
%token SEMICOLON COMMA DOT PLUS MINUS STAR
%token SLASH PERCENT AMPERSAND BAR CARET TILDE
%token ARROW EXCLAIM DBL_PLUS DBL_MINUS DBL_LESS DBL_GTR
%token QUESTION COLON TRIPLE_DOT DBL_AMP DBL_BAR DBL_EQ
%token EXCL_EQ LESS LESS_EQ GTR GTR_EQ EQ
%token PLUS_EQ MINUS_EQ STAR_EQ SLASH_EQ PERCENT_EQ AMP_EQ
%token BAR_EQ CARET_EQ DBL_LESS_EQ DBL_GTR_EQ POUND DBL_POUND

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
c_flat_trans_unit : external_decl_defn
			| c_flat_trans_unit external_decl_defn
			;

external_decl_defn : function_decl_defn
				| declaration
				;

function_decl_defn: declarator compound_statement
	| declaration_specifiers declarator compound_statement
	;
declaration_list: declaration
	| declaration_list declaration
	;
declaration: declaration_specifiers SEMICOLON
	| declaration_specifiers init_declarator_list SEMICOLON
	;
declaration_specifiers: declaration_specifiers storage_class_specifier
	| storage_class_specifier
	| type_specifier
	| declaration_specifiers type_specifier
	| declaration_specifiers type_qualifier
	| type_qualifier
	;
storage_class_specifier: AUTO
	| STATIC
	| EXTERN
	;
type_specifier: INT
	| UNSIGNED
	| LONG
	| FLOAT
	| DOUBLE
	;
type_qualifier: CONST
;
init_declarator_list: init_declarator
	| init_declarator_list COMMA init_declarator
	;
init_declarator: declarator
	| declarator initializer
	;
initializer: EQ expression
	;
declarator: IDENTIFIER
	| declarator LPAREN RPAREN
	| declarator LPAREN parameter_type_list RPAREN
	| declarator LPAREN formal_parm_list RPAREN
	| declarator LBRACKET const_expression RBRACKET
	| declarator LBRACKET RBRACKET
	;
formal_parm_list: formal_parameter
	| formal_parm_list COMMA formal_parameter
	;
formal_parameter: type_specifier_list IDENTIFIER
;
parameter_type_list: type_specifier_list
	| parameter_type_list COMMA type_specifier_list
	;
type_specifier_list: type_specifier
	| type_specifier_list type_specifier
	;
identifier_list: IDENTIFIER
	| identifier_list COMMA IDENTIFIER
	;
statement_list: statement
	|statement_list statement
	;
compound_statement: LBRACE declaration_list statement_list RBRACE
	| LBRACE declaration_list RBRACE
	| LBRACE statement_list RBRACE
	| LBRACE RBRACE
	;
statement: compound_statement
	| IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE
	| IF LPAREN expression RPAREN statement ELSE statement
	| WHILE LPAREN expression RPAREN statement
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	| expression SEMICOLON
	| SEMICOLON
	;
expression_list: expression
	| expression_list COMMA expression
	;
const_expression: conditional_expr
;
expression: conditional_expr
	| unary_expr assignment_op expression
	;
assignment_op: EQ
	| PLUS_EQ
	| MINUS_EQ
	| STAR_EQ
	| SLASH_EQ
	;
conditional_expr: logical_or_expr
;
logical_or_expr: logical_and_expr
	| logical_or_expr DBL_BAR logical_and_expr
	;
logical_and_expr: equality_expr
	| logical_and_expr DBL_AMP equality_expr
	;
equality_expr: relational_expr
	| equality_expr DBL_EQ relational_expr
	| equality_expr EXCL_EQ relational_expr
	;
relational_expr: add_expr
	| relational_expr LESS add_expr
	| relational_expr GTR add_expr
	| relational_expr LESS_EQ add_expr
	| relational_expr GTR_EQ add_expr
	;
add_expr: mult_expr
	| add_expr PLUS mult_expr
	| add_expr MINUS mult_expr
	;
mult_expr: unary_expr
	| mult_expr STAR unary_expr
	| mult_expr SLASH unary_expr
	| mult_expr PERCENT unary_expr
	;
unary_expr: postfix_expr
	| DBL_PLUS unary_expr
	| DBL_MINUS unary_expr
	| MINUS unary_expr
	| PLUS unary_expr
	| EXCLAIM unary_expr
	;
postfix_expr: primary_expr
	| primary_expr LBRACKET expression RBRACKET
	| SCANF LPAREN identifier_list RPAREN
	| PRINTF LPAREN expression_list RPAREN
	| primary_expr LPAREN expression_list RPAREN
	| primary_expr LPAREN RPAREN
	| postfix_expr DBL_PLUS
	| postfix_expr DBL_MINUS
	;
primary_expr: IDENTIFIER
	| INT_LITERAL
	| REAL_LITERAL
	| STR_LITERAL
	| LPAREN expression RPAREN
	;
		
%%
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}