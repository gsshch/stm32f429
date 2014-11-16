/**
 *	Snake library for STM32F429-Discovery boards
 *
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@link		
 *	@version 	v1.0
 *	@ide		Keil uVision
 *	@license	GNU GPL v3
 *	
 * |----------------------------------------------------------------------
 * | Copyright (C) Tilen Majerle, 2014
 * | 
 * | This program is free software: you can redistribute it and/or modify
 * | it under the terms of the GNU General Public License as published by
 * | the Free Software Foundation, either version 3 of the License, or
 * | any later version.
 * |  
 * | This program is distributed in the hope that it will be useful,
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * | GNU General Public License for more details.
 * | 
 * | You should have received a copy of the GNU General Public License
 * | along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * |----------------------------------------------------------------------
 */
#ifndef TM_SNAKE_H
#define TM_SNAKE_H 100

/* C++ detection */
#ifdef __cplusplus
extern C {
#endif

/**
 * Includes
 */
#include "stm32f4xx.h"
#include "defines.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"
#include "tm_stm32f4_rng.h"
#include "tm_stm32f4_ili9341_ltdc.h"
#include "tm_stm32f4_usb_hid_host.h"

#define SNAKE_GAME_TITLE		"Snake Game V1.0 by TM"
	
/* Colors for game */
#define SNAKE_COLOR_BORDER		ILI9341_COLOR_BLACK
#define SNAKE_COLOR_MAIN_BCK	ILI9341_COLOR_BLUE2
#define SNAKE_COLOR_GAME_BCK	ILI9341_COLOR_GREEN2
#define SNAKE_COLOR_PIXEL		ILI9341_COLOR_BROWN
#define SNAKE_COLOR_TARGET		ILI9341_COLOR_BLACK
#define SNAKE_COLOR_HEAD		ILI9341_COLOR_RED

/* Number of NxN dimension for snake */
#define SNAKE_PIXELS			39
#define SNAKE_PIXEL_SIZE		5	/* umber for display's pixels for 1 snake section */
#define SNAKE_BACK_START_X		1	/* X coordinate where snake area starts */
#define SNAKE_BACK_START_Y		20	/* Y coordinate where snake area starts */

#define SNAKE_DEFAULT_LENGTH	8	/* Default snake length */
#define SNAKE_SPEED_MAX			15	/* 15Hz movement */
#define SNAKE_SPEED_MIN			1	/* 1Hz movement */

/* Directions for snake */
#define SNAKE_DIRECTION_LEFT	0
#define SNAKE_DIRECTION_RIGHT	1
#define SNAKE_DIRECTION_UP		2
#define SNAKE_DIRECTION_DOWN	3

/* Keyboard buttons */
#define SNAKE_KEY_LEFT			((uint8_t) 'a')	/* Small 'a' */
#define SNAKE_KEY_RIGHT			((uint8_t) 'd')	/* Small 'd' */
#define SNAKE_KEY_UP			((uint8_t) 'w')	/* Small 'w' */
#define SNAKE_KEY_DOWN			((uint8_t) 's')	/* Small 's' */
#define SNAKE_KEY_SPEED_UP		((uint8_t) 'u')	/* Small 'u' */
#define SNAKE_KEY_SPEED_DOWN	((uint8_t) 'i')	/* Small 'i' */
#define SNAKE_KEY_PAUSE			((uint8_t) 'p')	/* Small 'p' */
#define SNAKE_KEY_RESET			((uint8_t) 'r')	/* Small 'r' */
#define SNAKE_KEY_OVERFLOW		((uint8_t) 'm')	/* Small 'm' */

/* Text locations */
#define SNAKE_TEXT_LINE1		265		
#define SNAKE_TEXT_LINE2		285
#define SNAKE_TEXT_LINE3		305

typedef struct {
	int8_t Snake[SNAKE_PIXELS * SNAKE_PIXELS][2];
	uint16_t Length;
	uint16_t LastIndex;
	uint8_t Direction;
	uint16_t Hits;
} TM_SNAKE_t;

typedef struct {
	uint8_t Overflow;
	uint8_t Speed;
	uint32_t Micros;
	uint8_t Pause;
} TM_SNAKE_Settings_t;

void TM_SNAKE_Start(void);

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif
