################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Exam1.c \
../source/GPIO.c \
../source/NVIC.c \
../source/PIT.c \
../source/main.c 

OBJS += \
./source/Exam1.o \
./source/GPIO.o \
./source/NVIC.o \
./source/PIT.o \
./source/main.o 

C_DEPS += \
./source/Exam1.d \
./source/GPIO.d \
./source/NVIC.d \
./source/PIT.d \
./source/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCPU_MK64FN1M0VLL12_cm4 -DCPU_MK64FN1M0VLL12 -D__REDLIB__ -I"D:\Embebidos\Examen1\examen-1-dsps\Exam1\source" -I"D:\Embebidos\Examen1\examen-1-dsps\Exam1" -I"D:\Embebidos\Examen1\examen-1-dsps\Exam1\CMSIS" -I"D:\Embebidos\Examen1\examen-1-dsps\Exam1\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


