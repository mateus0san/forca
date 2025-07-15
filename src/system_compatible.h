/**
 * @file system_compatible.h
 * @brief Define as funções que devem ser usadas para manter compatibilidade
*/
#ifndef WINDOWS_LINUX_H
#define WINDOWS_LINUX_H

#include <stdlib.h>


/**
 * @brief Limpa a tela 
*/
void clear_screen(void);

/**
 * @brief Pausa o terminal
*/
void system_pause(void);

/**
 * @brief Igual a malloc, mas fecha o programa se o ponteiro retornado for NULL 
*/
void *system_malloc(size_t);

#endif
