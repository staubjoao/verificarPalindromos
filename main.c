#include<stdio.h>
#include<string.h>
#include <ctype.h>

#include "listaDupla.c"

char *limpaEspaco(char *out, char *w)
{
    char *p = w;
    int i = 0;

    while(*p)
    {
        if(!isspace(*p))
            out[i++] = *p;

        p++;
    }
    out[i] = 0;

    return out;
}

char *tudoMin(char *out, char *w)
{
    char *p = w;
    int i = 0;

    while(*p)
    {
        out[i++] = tolower(*p);

        p++;
    }
    out[i] = 0;

    return out;
}

char *limpaCaracEspe(char *out, char *w)
{
    char *p = w;
    int i = 0;

    while(*p)
    {
        if(*p >= 'a' && *p <= 'z')
            out[i++] = *p;

        p++;
    }
    out[i] = 0;

    return out;
}

void insereLista(char w[256])
{
    int i;

    for(i = 0; i < strlen(w); i++)
    {
        insereInicio(w[i]);
    }
}

main()
{
    char w[256];
    char out[256];

    printf("Digite uma palavra ou frase: ");
    fgets(w, 87, stdin);
    w[strlen(w)-1] = '\0';


    limpaEspaco(out, w);
    strcpy(w, out);
    tudoMin(out, w);
    strcpy(w, out);
    limpaCaracEspe(out, w);
    strcpy(w, out);

    criaLista();
    insereLista(w);
    inverteLista(out);
    if(strcmp(w, out))
    {
        printf("w: %s\n", w);
        printf("out: %s\n", out);
        printf("n%co %c um palindromo\n", 198, 130);
    }
    else
    {
        printf("w: %s\n", w);
        printf("out: %s\n", out);
        printf("%c um palindromo\n", 130);
    }
}
