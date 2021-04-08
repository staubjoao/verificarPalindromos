#include<stdio.h>
#include<string.h>
#include <ctype.h>

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

    printf("%s", w);

}
