################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/InOutTp1.c \
../src/OperacionesTp1.c \
../src/TP_1.c \
../src/ValidacionesTp1.c 

C_DEPS += \
./src/InOutTp1.d \
./src/OperacionesTp1.d \
./src/TP_1.d \
./src/ValidacionesTp1.d 

OBJS += \
./src/InOutTp1.o \
./src/OperacionesTp1.o \
./src/TP_1.o \
./src/ValidacionesTp1.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/InOutTp1.d ./src/InOutTp1.o ./src/OperacionesTp1.d ./src/OperacionesTp1.o ./src/TP_1.d ./src/TP_1.o ./src/ValidacionesTp1.d ./src/ValidacionesTp1.o

.PHONY: clean-src

