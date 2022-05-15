/**
 * This Library was originally written by Olivier Van den Eede (4ilo) in 2016.
 * Some refactoring was done and SPI support was added by Aleksander Alekseev (afiskon) in 2018.
 *
 * https://github.com/afiskon/stm32-ssd1306
 */

#ifndef __SSD1306_H__
#define __SSD1306_H__

#include <stddef.h>
#include <_ansi.h>

_BEGIN_STD_C

#include "stm32g0xx_hal.h"

#include "display_fonts.h"

/* vvv I2C config vvv */

#ifndef DISPLAY_I2C_PORT
#define DISPLAY_I2C_PORT        hi2c2
#endif

#ifndef DISPLAY_I2C_ADDR
#define DISPLAY_I2C_ADDR        (0x3C << 1)
#endif

/* ^^^ I2C config ^^^ */

extern I2C_HandleTypeDef DISPLAY_I2C_PORT;

// SSD1306 OLED height in pixels
#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT          64
#endif

// SSD1306 width in pixels
#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH           128
#endif

#ifndef DISPLAY_BUFFER_SIZE
#define DISPLAY_BUFFER_SIZE   DISPLAY_WIDTH * DISPLAY_HEIGHT / 8
#endif

// Enumeration for screen colors
typedef enum {
    Black = 0x00, // Black color, no pixel
    White = 0x01  // Pixel is set. Color depends on OLED
} DISPLAY_COLOR;

typedef enum {
    SSD1306_OK = 0x00,
    SSD1306_ERR = 0x01  // Generic error.
} SSD1306_Error_t;

// Struct to store transformations
typedef struct {
    uint16_t CurrentX;
    uint16_t CurrentY;
    uint8_t Initialized;
    uint8_t DisplayOn;
} DISPLAY_t;

// Procedure definitions
void display_init(void);
void display_fill(DISPLAY_COLOR color);
void display_update(void);
void display_draw_pixel(uint8_t x, uint8_t y, DISPLAY_COLOR color);
char display_write_char(char ch, FontDef Font, DISPLAY_COLOR color);
void display_set_cursor(uint8_t x, uint8_t y);

/**
 * @brief Sets the contrast of the display.
 * @param[in] value contrast to set.
 * @note Contrast increases as the value increases.
 * @note RESET = 7Fh.
 */
void display_set_contrast(const uint8_t value);
/**
 * @brief Set Display ON/OFF.
 * @param[in] on 0 for OFF, any for ON.
 */
void display_set_on(const uint8_t on);
/**
 * @brief Reads DisplayOn state.
 * @return  0: OFF.
 *          1: ON.
 */
uint8_t display_get_on();

// Low-level procedures
void display_write_command(uint8_t byte);
void display_write_data(uint8_t* buffer, size_t buff_size);
SSD1306_Error_t display_fill_framebuffer(uint8_t* buf, uint32_t len);

_END_STD_C

#endif // __SSD1306_H__
