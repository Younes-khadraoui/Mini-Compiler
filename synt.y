%{
    #include <stdio.h>
    extern int nb_ligne;
    extern int col;
    int yylex();  
%}

%token mc_code mc_routine mc_entier mc_real mc_logical mc_character mc_dimension mc_read mc_write mc_if mc_then
       mc_else mc_endif mc_dowhile mc_enddo mc_or mc_and mc_gt mc_ge mc_eq mc_ne mc_le mc_lt mc_call mc_end mc_endr

%start program

%%

program : statement_list
        ;

statement_list : statement
               | statement_list statement
               ;

statement : mc_code
          | mc_routine
          ;

%%

int main(int argc, char** argv) {
    yyparse();
    return 0;
}
