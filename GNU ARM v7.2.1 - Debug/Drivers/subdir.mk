################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/display.c \
../Drivers/displaylpm013m126a.c \
../Drivers/displaypalemlib.c \
../Drivers/dmd_display.c \
../Drivers/glib.c \
../Drivers/glib_bitmap.c \
../Drivers/glib_font_narrow_6x8.c \
../Drivers/glib_font_normal_18x8.c \
../Drivers/glib_font_number_16x20.c \
../Drivers/glib_rectangle.c \
../Drivers/glib_string.c \
../Drivers/udelay.c 

OBJS += \
./Drivers/display.o \
./Drivers/displaylpm013m126a.o \
./Drivers/displaypalemlib.o \
./Drivers/dmd_display.o \
./Drivers/glib.o \
./Drivers/glib_bitmap.o \
./Drivers/glib_font_narrow_6x8.o \
./Drivers/glib_font_normal_18x8.o \
./Drivers/glib_font_number_16x20.o \
./Drivers/glib_rectangle.o \
./Drivers/glib_string.o \
./Drivers/udelay.o 

C_DEPS += \
./Drivers/display.d \
./Drivers/displaylpm013m126a.d \
./Drivers/displaypalemlib.d \
./Drivers/dmd_display.d \
./Drivers/glib.d \
./Drivers/glib_bitmap.d \
./Drivers/glib_font_narrow_6x8.d \
./Drivers/glib_font_normal_18x8.d \
./Drivers/glib_font_number_16x20.d \
./Drivers/glib_rectangle.d \
./Drivers/glib_string.d \
./Drivers/udelay.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/display.o: ../Drivers/display.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/display.d" -MT"Drivers/display.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/displaylpm013m126a.o: ../Drivers/displaylpm013m126a.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/displaylpm013m126a.d" -MT"Drivers/displaylpm013m126a.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/displaypalemlib.o: ../Drivers/displaypalemlib.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/displaypalemlib.d" -MT"Drivers/displaypalemlib.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/dmd_display.o: ../Drivers/dmd_display.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/dmd_display.d" -MT"Drivers/dmd_display.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/glib.o: ../Drivers/glib.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/glib.d" -MT"Drivers/glib.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/glib_bitmap.o: ../Drivers/glib_bitmap.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/glib_bitmap.d" -MT"Drivers/glib_bitmap.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/glib_font_narrow_6x8.o: ../Drivers/glib_font_narrow_6x8.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/glib_font_narrow_6x8.d" -MT"Drivers/glib_font_narrow_6x8.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/glib_font_normal_18x8.o: ../Drivers/glib_font_normal_18x8.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/glib_font_normal_18x8.d" -MT"Drivers/glib_font_normal_18x8.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/glib_font_number_16x20.o: ../Drivers/glib_font_number_16x20.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/glib_font_number_16x20.d" -MT"Drivers/glib_font_number_16x20.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/glib_rectangle.o: ../Drivers/glib_rectangle.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/glib_rectangle.d" -MT"Drivers/glib_rectangle.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/glib_string.o: ../Drivers/glib_string.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/glib_string.d" -MT"Drivers/glib_string.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Drivers/udelay.o: ../Drivers/udelay.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG=1' '-DEFM32TG11B120F128GM32=1' -I"C:\Users\habechma\projects\novagotchi\inc" -I"C:\Users\habechma\projects\novagotchi\Drivers\inc" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/CMSIS/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/Device/SiliconLabs/EFM32TG11B/Include" -I"C:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v2.6//platform/emlib/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -MMD -MP -MF"Drivers/udelay.d" -MT"Drivers/udelay.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


