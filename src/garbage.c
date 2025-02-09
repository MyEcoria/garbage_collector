/*
** EPITECH PROJECT, 2025
** garbage.c
** File description:
** This code is a garbage collector
*/
#include "garbage.h"

const garbage_t *garbage = NULL;

void *gc_malloc(size_t size)
{
    garbage_t *new = malloc(sizeof(garbage_t));

    if (new == NULL)
        return (NULL);
    new->ptr = malloc(size);
    if (new->ptr == NULL) {
        free(new);
        return (NULL);
    }
    new->next = (garbage_t *)garbage;
    garbage = new;
    return (new->ptr);
}

static void gc_free_condition(garbage_t *tmp, garbage_t *prev)
{
    if (tmp->ptr != NULL)
        free(tmp->ptr);
    if (prev == NULL)
        garbage = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
}

void *gc_free(void *ptr)
{
    garbage_t *tmp = (garbage_t *)garbage;
    garbage_t *prev = NULL;

    while (tmp != NULL) {
            if (tmp->ptr == ptr) {
                gc_free_condition(tmp, prev);
                return (NULL);
            }
            prev = tmp;
            tmp = tmp->next;
        }
    return (NULL);
}

void gc_collect(void)
{
    garbage_t *tmp = (garbage_t *)garbage;
    garbage_t *prev = NULL;

    while (tmp != NULL) {
        if (tmp->ptr)
            free(tmp->ptr);
        prev = tmp;
        tmp = tmp->next;
        free(prev);
    }
    garbage = NULL;
}

void *gc_realloc(void *ptr, size_t size)
{
    garbage_t *tmp = (garbage_t *)garbage;

    while (tmp != NULL) {
        if (tmp->ptr == ptr) {
            tmp->ptr = realloc(tmp->ptr, size);
            return (tmp->ptr);
        }
        tmp = tmp->next;
    }
    return (NULL);
}
