################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/src/subdir.mk
-include Drivers/subdir.mk
-include CMSIS/EFM32TG11B/GCC/subdir.mk
-include CMSIS/EFM32TG11B/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: novagotchi.axf

# Tool invocations
novagotchi.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "novagotchi.ld" -Xlinker --gc-sections -Xlinker -Map="novagotchi.map" --specs=nano.specs -o novagotchi.axf "./CMSIS/EFM32TG11B/GCC/startup_efm32tg11b.o" "./CMSIS/EFM32TG11B/system_efm32tg11b.o" "./Drivers/display.o" "./Drivers/displaylpm013m126a.o" "./Drivers/displaypalemlib.o" "./Drivers/dmd_display.o" "./Drivers/glib.o" "./Drivers/glib_bitmap.o" "./Drivers/glib_font_narrow_6x8.o" "./Drivers/glib_font_normal_18x8.o" "./Drivers/glib_font_number_16x20.o" "./Drivers/glib_rectangle.o" "./Drivers/glib_string.o" "./Drivers/udelay.o" "./emlib/src/em_adc.o" "./emlib/src/em_assert.o" "./emlib/src/em_cmu.o" "./emlib/src/em_core.o" "./emlib/src/em_cryotimer.o" "./emlib/src/em_emu.o" "./emlib/src/em_gpio.o" "./emlib/src/em_letimer.o" "./emlib/src/em_prs.o" "./emlib/src/em_rtcc.o" "./emlib/src/em_system.o" "./emlib/src/em_usart.o" "./src/main.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: novagotchi.hex'
	arm-none-eabi-objcopy -O ihex "novagotchi.axf" "novagotchi.hex"
	@echo ' '

	@echo 'Building bin file: novagotchi.bin'
	arm-none-eabi-objcopy -O binary "novagotchi.axf" "novagotchi.bin"
	@echo ' '

	@echo 'Building s37 file: novagotchi.s37'
	arm-none-eabi-objcopy -O srec "novagotchi.axf" "novagotchi.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "novagotchi.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) novagotchi.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
