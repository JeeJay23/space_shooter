/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
void cppMain(SPI_HandleTypeDef*);
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define Ctrl_B_Btn_A_Pin GPIO_PIN_6
#define Ctrl_B_Btn_A_GPIO_Port GPIOA
#define Ctrl_A_Btn_B_Pin GPIO_PIN_10
#define Ctrl_A_Btn_B_GPIO_Port GPIOB
#define Ctrl_B_Btn_Start_Pin GPIO_PIN_7
#define Ctrl_B_Btn_Start_GPIO_Port GPIOC
#define Ctrl_B_Btn_Right_Pin GPIO_PIN_8
#define Ctrl_B_Btn_Right_GPIO_Port GPIOA
#define Ctrl_B_Btn_Left_Pin GPIO_PIN_9
#define Ctrl_B_Btn_Left_GPIO_Port GPIOA
#define Ctrl_A_Btn_Left_Pin GPIO_PIN_10
#define Ctrl_A_Btn_Left_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define Ctrl_A_Btn_Right_Pin GPIO_PIN_3
#define Ctrl_A_Btn_Right_GPIO_Port GPIOB
#define Ctrl_A_Btn_A_Pin GPIO_PIN_4
#define Ctrl_A_Btn_A_GPIO_Port GPIOB
#define Ctrl_A_Btn_Start_Pin GPIO_PIN_5
#define Ctrl_A_Btn_Start_GPIO_Port GPIOB
#define Ctrl_B_Btn_B_Pin GPIO_PIN_9
#define Ctrl_B_Btn_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
