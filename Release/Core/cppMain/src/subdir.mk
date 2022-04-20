################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/cppMain/src/Block.cpp \
../Core/cppMain/src/Bullet.cpp \
../Core/cppMain/src/Controller.cpp \
../Core/cppMain/src/GPU.cpp \
../Core/cppMain/src/GameEngine.cpp \
../Core/cppMain/src/Player.cpp \
../Core/cppMain/src/Vector.cpp \
../Core/cppMain/src/gameObject.cpp \
../Core/cppMain/src/main.cpp \
../Core/cppMain/src/protocol.cpp 

OBJS += \
./Core/cppMain/src/Block.o \
./Core/cppMain/src/Bullet.o \
./Core/cppMain/src/Controller.o \
./Core/cppMain/src/GPU.o \
./Core/cppMain/src/GameEngine.o \
./Core/cppMain/src/Player.o \
./Core/cppMain/src/Vector.o \
./Core/cppMain/src/gameObject.o \
./Core/cppMain/src/main.o \
./Core/cppMain/src/protocol.o 

CPP_DEPS += \
./Core/cppMain/src/Block.d \
./Core/cppMain/src/Bullet.d \
./Core/cppMain/src/Controller.d \
./Core/cppMain/src/GPU.d \
./Core/cppMain/src/GameEngine.d \
./Core/cppMain/src/Player.d \
./Core/cppMain/src/Vector.d \
./Core/cppMain/src/gameObject.d \
./Core/cppMain/src/main.d \
./Core/cppMain/src/protocol.d 


# Each subdirectory must supply rules for building sources it contributes
Core/cppMain/src/%.o Core/cppMain/src/%.su: ../Core/cppMain/src/%.cpp Core/cppMain/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m0 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F030x8 -c -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-cppMain-2f-src

clean-Core-2f-cppMain-2f-src:
	-$(RM) ./Core/cppMain/src/Block.d ./Core/cppMain/src/Block.o ./Core/cppMain/src/Block.su ./Core/cppMain/src/Bullet.d ./Core/cppMain/src/Bullet.o ./Core/cppMain/src/Bullet.su ./Core/cppMain/src/Controller.d ./Core/cppMain/src/Controller.o ./Core/cppMain/src/Controller.su ./Core/cppMain/src/GPU.d ./Core/cppMain/src/GPU.o ./Core/cppMain/src/GPU.su ./Core/cppMain/src/GameEngine.d ./Core/cppMain/src/GameEngine.o ./Core/cppMain/src/GameEngine.su ./Core/cppMain/src/Player.d ./Core/cppMain/src/Player.o ./Core/cppMain/src/Player.su ./Core/cppMain/src/Vector.d ./Core/cppMain/src/Vector.o ./Core/cppMain/src/Vector.su ./Core/cppMain/src/gameObject.d ./Core/cppMain/src/gameObject.o ./Core/cppMain/src/gameObject.su ./Core/cppMain/src/main.d ./Core/cppMain/src/main.o ./Core/cppMain/src/main.su ./Core/cppMain/src/protocol.d ./Core/cppMain/src/protocol.o ./Core/cppMain/src/protocol.su

.PHONY: clean-Core-2f-cppMain-2f-src

