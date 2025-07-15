/**
 * @file forca_system.h
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
 * @brief Pause o terminal
*/
void system_pause(void);

/**
 * @brief igual a malloc, mas crash o programa se o ponteiro retornado seja null 
*/
void *system_malloc(size_t);

#endif
