################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../DIO_program.c \
../EEPROM_program.c \
../GIE_program.c \
../TIMR_program.c \
../TWI_program.c \
../USART_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./DIO_program.o \
./EEPROM_program.o \
./GIE_program.o \
./TIMR_program.o \
./TWI_program.o \
./USART_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./DIO_program.d \
./EEPROM_program.d \
./GIE_program.d \
./TIMR_program.d \
./TWI_program.d \
./USART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


