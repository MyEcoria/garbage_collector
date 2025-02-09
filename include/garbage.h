/*
** EPITECH PROJECT, 2024
** garbage.h
** File description:
** my
*/

#ifndef GARBAGE_H
    #define GARBAGE_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>

typedef struct garbage_s {
    void *ptr;
    struct garbage_s *next;
} garbage_t;
#endif
