/*
 * gconio.h v0.5
 *
 * A replacement library for Borland C-specific conio.h functions for gcc
 * and MSVC.
 *
 * Implemented functions: clrscr, delay, delline, gotoxy, kader,
 *                        lijnh, lijnv, textbackground, textcolor,
 *                        getch, getche, setcursortype.
 *
 * Implemented MSVC-only functions: wherex, wherey.
 *
 * Added functions: get_screen_rows, get_screen_columns
 *
 * Warning: The Linux functions in this library rely on ANSI code sequences
 *          _ALOT_. Output might look weird on non-ANSI-compliant terminals.
 *
 * Warning: gotoxy() uses (0, 0) as topleft corner. This is different from
 *          what MSVC users may be used to.
 *
 * An updated version of this file can be requested by sending email
 * to Wence Van der Meersch <wence@wence.be> or
 * Filip Duyck <filip@factor9.be>.
 *
 * Copyright (C) 2002-2003 Wence Van der Meersch & Filip Duyck
 *
 * The MSVC versions of setcursortype, textcolor and textbackground were
 * kindly donated by Sebastien Boelpaep <sebastien@pi.be>.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 * History:
 *
 * v0.5:  - gconio.h should now be compatible with MSVC!
 *        - Rewrote clrscr, lineh, linev functions to evade ANSI codes.
 *        - Added wherex, wherey, setcursortype functions (MSVC only).
 * v0.2:  - Added getch, getche, strlwr, strupr functions.
 *        - Added aliases for stricmp, strnicmp.
 *
 * v0.1:  - First release.
 */

#ifndef __GCONIO_H
#define __GCONIO_H

#include <stdio.h>
#ifdef _WIN32
#include <conio.h>
#include <time.h>
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#endif

/**** DEFINITIONS **************************/
#define kader(x,y,l,h,t) box(x,y,l,h,t)
#define lijnh(x,y,l,c)   lineh(x,y,l,c)
#define lijnv(x,y,l,c)   linev(x,y,l,c)
#ifdef __linux__
#define stricmp          strcasecmp
#define strnicmp         strncasecmp
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/**** PROTOTYPES ***************************/
void delline (void);
void clrscr (void);
void delay (unsigned long milliseconds);
void textbackground (int newcolor);
void textcolor (int newcolor);
void box (int x, int y, int length, int height, int type);
void lineh (int x, int y, int length, int character);
void linev (int x, int y, int length, int character);
void gotoxy (short int x,short int y);
#ifdef __linux__
void flushall (void);
int getch (void);
int getche (void);
char *strlwr (char *text);
char *strupr (char *text);
#endif
#ifdef _WIN32
int wherex (void);
int wherey (void);

#endif

/**** GLOBAL VARIABLES *********************/
#ifdef __linux__
int __gconio_h_ansi_attr = 0;
int __gconio_h_ansi_fg = 37;
int __gconio_h_ansi_bg = 40;
#endif
#ifdef _WIN32
enum COLORS {
    BLACK        = 0,
    BLUE         = FOREGROUND_BLUE,
    GREEN        = FOREGROUND_GREEN,
    CYAN         = FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED          = FOREGROUND_RED,
    MAGENTA      = FOREGROUND_RED | FOREGROUND_BLUE,
    BROWN        = FOREGROUND_RED | FOREGROUND_GREEN,
    LIGHTGRAY    = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKGRAY     = FOREGROUND_INTENSITY,
    LIGHTBLUE    = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHTGREEN   = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHTCYAN    = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHTRED     = FOREGROUND_RED | FOREGROUND_INTENSITY,
    LIGHTMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    YELLOW       = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    WHITE        = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
};
enum CURSOR {
    NORMALCURSOR = 0,
    NOCURSOR = 100,
    SOLIDCURSOR = 20,
};
WORD __gconio_h_ansi_fg = WHITE;
WORD __gconio_h_ansi_bg = BLACK << 4;
#endif

/**** FUNCTIONS ****************************/

void delay (unsigned long milliseconds)
{
#ifdef __linux__
    usleep (milliseconds * 1000);
#endif
#ifdef _WIN32
    unsigned long tstart, tnow;
    milliseconds *= CLK_TCK/1000;
    tstart = clock();
    while ((tnow = clock() - tstart) < milliseconds) { }
#endif
}


#ifdef __linux__
int getch (void)
{
    int kbdinput;
    struct termios t_orig, t_new;

    // We need to change terminal settings so getchar() does't
    // require a CR at the end. Also disable local echo.
    tcgetattr(0, &t_orig);
    t_new = t_orig;
    t_new.c_lflag &= ~ICANON; t_new.c_lflag &= ~ECHO;
    t_new.c_lflag &= ~ISIG;   t_new.c_cc[VMIN] = 1;
    t_new.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &t_new);

    // Get actual input
    kbdinput = getchar();

    // Reset terminal settings.
    tcsetattr(0, TCSANOW, &t_orig);

    return (kbdinput);
}
#endif

#ifdef __linux__
int getche (void)
{
    int kbdinput;
    kbdinput = getch();
    putchar (kbdinput);
    return (kbdinput);
}
#endif

#ifdef __linux__
char *strlwr (char *text)
{
    char *origtext = text;
    while (*text != '\0')
    {
      if ((*text > 64) && (*text < 91)) *text += 32;
      text++;
    }
    return (origtext);
}
#endif

#ifdef __linux__
char *strupr (char *text)
{
    char *origtext = text;
    while (*text != '\0')
    {
      if ((*text > 96) && (*text < 123)) *text -= 32;
      text++;
    }
    return (origtext);
}
#endif


void clrscr (void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void gotoxy (short int x, short int y)
{
#ifdef __linux__
        printf("\033[%d;%dH", y + 1, x + 1);
#endif
#ifdef _WIN32
    COORD cxy = { x, y };
    CONSOLE_SCREEN_BUFFER_INFO conScrBufInfo;
    if (GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &conScrBufInfo))
        cxy.Y = y + conScrBufInfo.srWindow.Top;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), cxy);
#endif
}

void textcolor (int newcolor)
{
#ifdef __linux__
    if (newcolor > 7) { __gconio_h_ansi_attr = 1; newcolor -= 8; }
    else { __gconio_h_ansi_attr = 0; }
    switch(newcolor)
    {
        case 0:  __gconio_h_ansi_fg = 30; break; // black
        case 1:  __gconio_h_ansi_fg = 34; break; // blue
        case 2:  __gconio_h_ansi_fg = 32; break; // green
        case 3:  __gconio_h_ansi_fg = 36; break; // cyan
        case 4:  __gconio_h_ansi_fg = 31; break; // red
        case 5:  __gconio_h_ansi_fg = 35; break; // magenta
        case 6:  __gconio_h_ansi_fg = 33; break; // brown
        case 7:  __gconio_h_ansi_fg = 37; break; // gray
	default: return ;
    }
    printf ("\033[%d;%d;%dm", __gconio_h_ansi_attr, __gconio_h_ansi_fg, __gconio_h_ansi_bg);
#endif
#ifdef _WIN32
    __gconio_h_ansi_fg = newcolor;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (__gconio_h_ansi_fg | __gconio_h_ansi_bg));
#endif
}

void textbackground (int newcolor)
{
#ifdef __linux__
    switch(newcolor)
    {
        case 0:  __gconio_h_ansi_bg = 40; break;
        case 1:  __gconio_h_ansi_bg = 44; break;
        case 2:  __gconio_h_ansi_bg = 42; break;
        case 3:  __gconio_h_ansi_bg = 46; break;
        case 4:  __gconio_h_ansi_bg = 41; break;
        case 5:  __gconio_h_ansi_bg = 45; break;
        case 6:  __gconio_h_ansi_bg = 43; break;
        case 7:  __gconio_h_ansi_bg = 47; break;
        default: return ;
    }
    printf ("\033[%d;%d;%dm", __gconio_h_ansi_attr, __gconio_h_ansi_fg, __gconio_h_ansi_bg);
#endif
#ifdef _WIN32
    __gconio_h_ansi_bg = newcolor << 4;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), (WORD) (__gconio_h_ansi_fg | __gconio_h_ansi_bg));
#endif
}

#ifdef _WIN32
int wherex (void)
{
    CONSOLE_SCREEN_BUFFER_INFO conScrBufInfo;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &conScrBufInfo);
    return conScrBufInfo.dwCursorPosition.X - conScrBufInfo.srWindow.Left;
}
#endif

#ifdef _WIN32
int wherey (void)
{
    CONSOLE_SCREEN_BUFFER_INFO conScrBufInfo;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &conScrBufInfo);
    return conScrBufInfo.dwCursorPosition.Y - conScrBufInfo.srWindow.Top;
}
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __GCONIO_H */

