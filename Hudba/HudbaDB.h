#pragma once

#define CHAR_ARRAY_SIZE 21

struct t_album
{
    char interpret[CHAR_ARRAY_SIZE];
    char album[CHAR_ARRAY_SIZE];
    int rok;
    struct t_album* dalsi;
};

void add(char* interpret, char* album, int rok, struct t_album** uk_prvni);
void del(char* interpret, struct t_album** uk_prvni);
