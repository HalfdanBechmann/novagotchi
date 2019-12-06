################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/EFM32TG11B/system_efm32tg11b.c 

OBJS += \
./CMSIS/EFM32TG11B/system_efm32tg11b.o 

C_DEPS += \
./CMSIS/EFM32TG11B/system_efm32tg11b.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/EFM32TG11B/system_efm32tg11b.o: ../CMSIS/EFM32TG11B/system_efm32tg11b.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"CMSIS/EFM32TG11B/system_efm32tg11b.d" -MT"CMSIS/EFM32TG11B/system_efm32tg11b.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


