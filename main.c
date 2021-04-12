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
        switch (*p)
        {
            case-96:case-123:case-58:case-124:case-125:case-75:case-73:case-57:case-114:case-74:
                out[i++] = 'a';
                break;
            case-126:case-118:case-120:case-119:case-112:case-44:case-46:case-45:
                out[i++] = 'e';
                break;
            case-95:case-115:case-117:case-116:case-42:case-34:case-40:case-41:
                out[i++] = 'i';
                break;
            case-94:case-107:case-28:case-108:case-109:case-32:case-29:case-27:case-103:case-30:
                out[i++] = 'o';
                break;
            case-93:case-105:case-127:case-106:case-23:case-21:case-102:case-22:
                out[i++] = 'u';
                break;
            case-121:case-128:
                out[i++] = 'c';
                break;
            default:
                out[i++] = *p;
                break;
        }
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
    strcpy(w, out);
    limpaCaracEspe(out, w);
    strcpy(w, out);

    criaLista();
    insereLista(w);
    retornaInvertido(out);
    if(strcmp(w, out))
    {
        printf("w: %s\n", w);
        printf("out: %s\n", out);
        printf("n%co %c um pal%cndromo\n", 198, 130, 161);
    }
    else
    {
        printf("w: %s\n", w);
        printf("out: %s\n", out);
        printf("%c um pal%cndromo\n", 130, 161);
    }
}
