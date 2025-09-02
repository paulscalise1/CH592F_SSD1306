################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/src/Main.c \
../User/src/app_i2c.c \
../User/src/driver_ssd1306.c \
../User/src/driver_ssd1306_advance.c \
../User/src/driver_ssd1306_basic.c \
../User/src/driver_ssd1306_display_test.c \
../User/src/driver_ssd1306_interface.c 

C_DEPS += \
./User/src/Main.d \
./User/src/app_i2c.d \
./User/src/driver_ssd1306.d \
./User/src/driver_ssd1306_advance.d \
./User/src/driver_ssd1306_basic.d \
./User/src/driver_ssd1306_display_test.d \
./User/src/driver_ssd1306_interface.d 

OBJS += \
./User/src/Main.o \
./User/src/app_i2c.o \
./User/src/driver_ssd1306.o \
./User/src/driver_ssd1306_advance.o \
./User/src/driver_ssd1306_basic.o \
./User/src/driver_ssd1306_display_test.o \
./User/src/driver_ssd1306_interface.o 



# Each subdirectory must supply rules for building sources it contributes
User/src/%.o: ../User/src/%.c
	@	riscv-none-embed-gcc -march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -DDEBUG=1 -I"c:/Users/Paul Scalise/CH592F_SSD1306/StdPeriphDriver/inc" -I"c:/Users/Paul Scalise/CH592F_SSD1306/RVMSIS" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
