################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cbase.c \
../src/dlist.c \
../src/main.c \
../src/program.c \
../src/slist.c 

OBJS += \
./src/cbase.o \
./src/dlist.o \
./src/main.o \
./src/program.o \
./src/slist.o 

C_DEPS += \
./src/cbase.d \
./src/dlist.d \
./src/main.d \
./src/program.d \
./src/slist.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


