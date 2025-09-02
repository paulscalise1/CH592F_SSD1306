/*********************************************************************************
 * File Name          : Main.c
 * Author             : Paul Scalise
 * Date               : 9/1/2025
 * Descrition         : SSD1306 WCH I2C Driver Example 
 *********************************************************************************/

#include "CH59x_common.h"
#include "app_i2c.h"
#include "driver_ssd1306_basic.h"
#include "driver_ssd1306_advance.h"
#include "driver_ssd1306_display_test.h"

#define ADVANCED
//#define BASIC


int main() {
    SetSysClock(CLK_SOURCE_PLL_60MHz);
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
    uint8_t res;

    while(1) {

        #ifdef ADVANCED
        res = ssd1306_display_test(SSD1306_INTERFACE_IIC, SSD1306_I2C_7_ADDR);
        if (res != 0) {
            (void)ssd1306_basic_deinit();
            return 1;
        }
        #endif

        #ifdef BASIC
        res = ssd1306_basic_init(SSD1306_INTERFACE_IIC, SSD1306_I2C_7_ADDR);
        if (res != 0) {
            return 1;
        }

        res = ssd1306_basic_clear();
        if (res != 0) {
            ssd1306_interface_debug_print("ssd1306: clear screen failed.\n");
            (void)ssd1306_basic_deinit();
            return 1;
        }

        res = ssd1306_basic_string(0, 0, "123", 3, 1, SSD1306_FONT_16);
        if (res != 0) {
            ssd1306_interface_debug_print("ssd1306: show string failed.\n");
            (void)ssd1306_basic_deinit();
            return 1;
        }

        res = ssd1306_basic_rect(0, 31, 31, 31, 1);
        if (res != 0) {
            (void)ssd1306_basic_deinit();
            return 1;
        }

        DelayMs(5000);

        (void)ssd1306_basic_deinit();
        #endif
    }
}
