################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../F-RTOS/croutine.c \
../F-RTOS/event_groups.c \
../F-RTOS/heap_1.c \
../F-RTOS/list.c \
../F-RTOS/port.c \
../F-RTOS/queue.c \
../F-RTOS/stream_buffer.c \
../F-RTOS/tasks.c \
../F-RTOS/timers.c 

OBJS += \
./F-RTOS/croutine.o \
./F-RTOS/event_groups.o \
./F-RTOS/heap_1.o \
./F-RTOS/list.o \
./F-RTOS/port.o \
./F-RTOS/queue.o \
./F-RTOS/stream_buffer.o \
./F-RTOS/tasks.o \
./F-RTOS/timers.o 

C_DEPS += \
./F-RTOS/croutine.d \
./F-RTOS/event_groups.d \
./F-RTOS/heap_1.d \
./F-RTOS/list.d \
./F-RTOS/port.d \
./F-RTOS/queue.d \
./F-RTOS/stream_buffer.d \
./F-RTOS/tasks.d \
./F-RTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
F-RTOS/%.o: ../F-RTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


