################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/controller.c \
../src/empleado.c \
../src/ioput.c \
../src/main.c \
../src/parser.c 

C_DEPS += \
./src/LinkedList.d \
./src/controller.d \
./src/empleado.d \
./src/ioput.d \
./src/main.d \
./src/parser.d 

OBJS += \
./src/LinkedList.o \
./src/controller.o \
./src/empleado.o \
./src/ioput.o \
./src/main.o \
./src/parser.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/LinkedList.d ./src/LinkedList.o ./src/controller.d ./src/controller.o ./src/empleado.d ./src/empleado.o ./src/ioput.d ./src/ioput.o ./src/main.d ./src/main.o ./src/parser.d ./src/parser.o

.PHONY: clean-src

