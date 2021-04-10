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

char *removeAcento(char *out, char *w)
{
    char *p = w;
    int i = 0;

    while(*p)
    {
        //fazer switch case
        if(*p==-96||*p==-123||*p==-58||*p==-124||*p==-125||*p==-75||*p==-73||*p==-57||*p==-114||*p==-74)
            out[i++] = 'a';
        else
            out[i++] = *p;
        if(*p==-126||*p==-118||*p==-120||*p==-119||*p==-112||*p==-44||*p==-46||*p==-45)
            out[i++] = 'e';
        else
            out[i++] = *p;
        if(*p==-95||*p==-115||*p==-117||*p==-116||*p==-42||*p==-34||*p==-40||*p==-41)
            out[i++] = 'i';
        else
            out[i++] = *p;
        if(*p==-94||*p==-107||*p==-28||*p==-108||*p==-109||*p==-32||*p==-29||*p==-27||*p==-103||*p==-30)
            out[i++] = 'o';
        else
            out[i++] = *p;
        if(*p==-93||*p==-105||*p==-127||*p==-106||*p==-23||*p==-21||*p==-102||*p==-22)
            out[i++] = 'u';
        else
            out[i++] = *p;
        if(*p==-121||*p==-128)
            out[i++] = 'c';
        else
            out[i++] = *p;
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
    removeAcento(out, w);
    printf("w: %s\n", w);
    printf("out: %s\n", out);
    strcpy(w, out);
    limpaCaracEspe(out, w);
    strcpy(w, out);

    /*int i;

    for(i = 0; i < strlen(comAcento); i++)
    {
        printf("%c: %d\n", comAcento[i], comAcento[i]);
    }*/

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
