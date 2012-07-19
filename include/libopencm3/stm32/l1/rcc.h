/** @file

@ingroup STM32L1xx

@brief <b>libopencm3 STM32L1xx Reset and Clock Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2009 Federico Ruiz-Ugalde \<memeruiz at gmail dot com\>
@author @htmlonly &copy; @endhtmlonly 2009 Uwe Hermann <uwe@hermann-uwe.de>
@author @htmlonly &copy; @endhtmlonly 2012 Karl Palsson <karlp@tweak.net.au>

@date 18 May 2012

LGPL License Terms @ref lgpl_license
 */
/** @defgroup STM32L1xx_rcc_defines

@brief Defined Constants and Types for the STM32L1xx Reset and Clock Control

@ingroup STM32L1xx_defines

LGPL License Terms @ref lgpl_license

 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2009 Federico Ruiz-Ugalde <memeruiz at gmail dot com>
 * Copyright (C) 2012 Karl Palsson <karlp@tweak.net.au>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Originally based on the F1 code, as it seemed most similar to the L1
 * TODO: very incomplete still!
 */

#ifndef LIBOPENCM3_RCC_H
#define LIBOPENCM3_RCC_H

#include <libopencm3/stm32/memorymap.h>
#include <libopencm3/cm3/common.h>

/* --- RCC registers ------------------------------------------------------- */

#define RCC_CR					MMIO32(RCC_BASE + 0x00)
#define RCC_ICSCR				MMIO32(RCC_BASE + 0x04)
#define RCC_CFGR				MMIO32(RCC_BASE + 0x08)
#define RCC_CIR					MMIO32(RCC_BASE + 0x0c)
#define RCC_AHBRSTR				MMIO32(RCC_BASE + 0x10)
#define RCC_APB2RSTR				MMIO32(RCC_BASE + 0x14)
#define RCC_APB1RSTR				MMIO32(RCC_BASE + 0x18)
#define RCC_AHBENR				MMIO32(RCC_BASE + 0x1c)
#define RCC_APB2ENR				MMIO32(RCC_BASE + 0x20)
#define RCC_APB1ENR				MMIO32(RCC_BASE + 0x24)
#define RCC_AHBLPENR				MMIO32(RCC_BASE + 0x28)
#define RCC_APB2LPENR				MMIO32(RCC_BASE + 0x2c)
#define RCC_APB1LPENR				MMIO32(RCC_BASE + 0x30)
#define RCC_CSR					MMIO32(RCC_BASE + 0x34)

/* --- RCC_CR values ------------------------------------------------------- */

/* RTCPRE[1:0] at 30:29 */
#define RCC_CR_CSSON				(1 << 28)
#define RCC_CR_PLLRDY				(1 << 25)
#define RCC_CR_PLLON				(1 << 24)
#define RCC_CR_HSEBYP				(1 << 18)
#define RCC_CR_HSERDY				(1 << 17)
#define RCC_CR_HSEON				(1 << 16)
#define RCC_CR_MSIRDY				(1 << 9)
#define RCC_CR_MSION				(1 << 8)
#define RCC_CR_HSIRDY				(1 << 1)
#define RCC_CR_HSION				(1 << 0)

/* --- RCC_ICSCR values ---------------------------------------------------- */

// TODO

/* --- RCC_CFGR values ----------------------------------------------------- */

/* MCOPRE */
#define RCC_CFGR_MCOPRE_DIV1	    0
#define RCC_CFGR_MCOPRE_DIV2	    1
#define RCC_CFGR_MCOPRE_DIV4	    2
#define RCC_CFGR_MCOPRE_DIV8	    3
#define RCC_CFGR_MCOPRE_DIV16	    4

/* MCO: Microcontroller clock output */
#define RCC_CFGR_MCO_NOCLK			0x0
#define RCC_CFGR_MCO_SYSCLK			0x1
#define RCC_CFGR_MCO_HSICLK			0x2
#define RCC_CFGR_MCO_MSICLK			0x3
#define RCC_CFGR_MCO_HSECLK			0x4
#define RCC_CFGR_MCO_PLLCLK			0x5
#define RCC_CFGR_MCO_LSICLK			0x6
#define RCC_CFGR_MCO_LSECLK			0x7

/* PLL Output division selection */
#define RCC_CFGR_PLLDIV_DIV2	0x1
#define RCC_CFGR_PLLDIV_DIV3	0x2
#define RCC_CFGR_PLLDIV_DIV4	0x3

/* PLLMUL: PLL multiplication factor */
#define RCC_CFGR_PLLMUL_MUL3		0x0
#define RCC_CFGR_PLLMUL_MUL4		0x1
#define RCC_CFGR_PLLMUL_MUL6		0x2
#define RCC_CFGR_PLLMUL_MUL8		0x3
#define RCC_CFGR_PLLMUL_MUL12		0x4
#define RCC_CFGR_PLLMUL_MUL16		0x5
#define RCC_CFGR_PLLMUL_MUL24		0x6
#define RCC_CFGR_PLLMUL_MUL32		0x7
#define RCC_CFGR_PLLMUL_MUL48		0x8

/* PLLSRC: PLL entry clock source */
#define RCC_CFGR_PLLSRC_HSI_CLK		0x0
#define RCC_CFGR_PLLSRC_HSE_CLK		0x1

/* PPRE2: APB high-speed prescaler (APB2) */
#define RCC_CFGR_PPRE2_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE2_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE2_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE2_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE2_HCLK_DIV16		0x7

/* PPRE1: APB low-speed prescaler (APB1) */
#define RCC_CFGR_PPRE1_HCLK_NODIV		0x0
#define RCC_CFGR_PPRE1_HCLK_DIV2		0x4
#define RCC_CFGR_PPRE1_HCLK_DIV4		0x5
#define RCC_CFGR_PPRE1_HCLK_DIV8		0x6
#define RCC_CFGR_PPRE1_HCLK_DIV16		0x7

/* HPRE: AHB prescaler */
#define RCC_CFGR_HPRE_SYSCLK_NODIV		0x0
#define RCC_CFGR_HPRE_SYSCLK_DIV2		0x8
#define RCC_CFGR_HPRE_SYSCLK_DIV4		0x9
#define RCC_CFGR_HPRE_SYSCLK_DIV8		0xa
#define RCC_CFGR_HPRE_SYSCLK_DIV16		0xb
#define RCC_CFGR_HPRE_SYSCLK_DIV64		0xc
#define RCC_CFGR_HPRE_SYSCLK_DIV128		0xd
#define RCC_CFGR_HPRE_SYSCLK_DIV256		0xe
#define RCC_CFGR_HPRE_SYSCLK_DIV512		0xf

/* SWS: System clock switch status */
#define RCC_CFGR_SWS_SYSCLKSEL_MSICLK		0x0
#define RCC_CFGR_SWS_SYSCLKSEL_HSICLK		0x1
#define RCC_CFGR_SWS_SYSCLKSEL_HSECLK		0x2
#define RCC_CFGR_SWS_SYSCLKSEL_PLLCLK		0x3

/* SW: System clock switch */
#define RCC_CFGR_SW_SYSCLKSEL_MSICLK		0x0
#define RCC_CFGR_SW_SYSCLKSEL_HSICLK		0x1
#define RCC_CFGR_SW_SYSCLKSEL_HSECLK		0x2
#define RCC_CFGR_SW_SYSCLKSEL_PLLCLK		0x3

/* --- RCC_CIR values ------------------------------------------------------ */

/* Clock security system interrupt clear bit */
#define RCC_CIR_CSSC				(1 << 23)

/* OSC ready interrupt clear bits */
#define RCC_CIR_MSIRDYC				(1 << 21)
#define RCC_CIR_PLLRDYC				(1 << 20)
#define RCC_CIR_HSERDYC				(1 << 19)
#define RCC_CIR_HSIRDYC				(1 << 18)
#define RCC_CIR_LSERDYC				(1 << 17)
#define RCC_CIR_LSIRDYC				(1 << 16)

/* OSC ready interrupt enable bits */
#define RCC_CIR_MSIRDYIE			(1 << 13)
#define RCC_CIR_PLLRDYIE			(1 << 12)
#define RCC_CIR_HSERDYIE			(1 << 11)
#define RCC_CIR_HSIRDYIE			(1 << 10)
#define RCC_CIR_LSERDYIE			(1 << 9)
#define RCC_CIR_LSIRDYIE			(1 << 8)

/* Clock security system interrupt flag bit */
#define RCC_CIR_CSSF				(1 << 7)

/* OSC ready interrupt flag bits */
#define RCC_CIR_MSIRDYF				(1 << 5) /* (**) */
#define RCC_CIR_PLLRDYF				(1 << 4)
#define RCC_CIR_HSERDYF				(1 << 3)
#define RCC_CIR_HSIRDYF				(1 << 2)
#define RCC_CIR_LSERDYF				(1 << 1)
#define RCC_CIR_LSIRDYF				(1 << 0)

/* --- RCC_AHBRSTR values ------------------------------------------------- */
#define RCC_AHBRSTR_DMA1RST			(1 << 24)
#define RCC_AHBRSTR_FLITFRST			(1 << 15)
#define RCC_AHBRSTR_CRCRST			(1 << 12)
#define RCC_AHBRSTR_GPIOHRST			(1 << 5)
#define RCC_AHBRSTR_GPIOERST			(1 << 4)
#define RCC_AHBRSTR_GPIODRST			(1 << 3)
#define RCC_AHBRSTR_GPIOCRST			(1 << 2)
#define RCC_AHBRSTR_GPIOBRST			(1 << 1)
#define RCC_AHBRSTR_GPIOARST			(1 << 0)

/* --- RCC_APB2RSTR values ------------------------------------------------- */

#define RCC_APB2RSTR_USART1RST			(1 << 14)
#define RCC_APB2RSTR_SPI1RST			(1 << 12)
#define RCC_APB2RSTR_ADC1RST			(1 << 9)
#define RCC_APB2RSTR_TIM11RST			(1 << 4)
#define RCC_APB2RSTR_TIM10RST			(1 << 3)
#define RCC_APB2RSTR_TIM9RST			(1 << 2)
#define RCC_APB2RSTR_SYSCFGRST			(1 << 0)

/* --- RCC_APB1RSTR values ------------------------------------------------- */

TODO : up to here

#define RCC_APB1RSTR_DACRST			(1 << 29)
#define RCC_APB1RSTR_PWRRST			(1 << 28)
#define RCC_APB1RSTR_BKPRST			(1 << 27)
#define RCC_APB1RSTR_CAN2RST			(1 << 26) /* (**) */
#define RCC_APB1RSTR_CAN1RST			(1 << 25) /* (**) */
#define RCC_APB1RSTR_CANRST			(1 << 25) /* (XX) Alias for CAN1RST */
#define RCC_APB1RSTR_USBRST			(1 << 23) /* (XX) */
#define RCC_APB1RSTR_I2C2RST			(1 << 22)
#define RCC_APB1RSTR_I2C1RST			(1 << 21)
#define RCC_APB1RSTR_UART5RST			(1 << 20)
#define RCC_APB1RSTR_UART4RST			(1 << 19)
#define RCC_APB1RSTR_USART3RST			(1 << 18)
#define RCC_APB1RSTR_USART2RST			(1 << 17)
#define RCC_APB1RSTR_SPI3RST			(1 << 15)
#define RCC_APB1RSTR_SPI2RST			(1 << 14)
#define RCC_APB1RSTR_WWDGRST			(1 << 11)
#define RCC_APB1RSTR_TIM7RST			(1 << 5)
#define RCC_APB1RSTR_TIM6RST			(1 << 4)
#define RCC_APB1RSTR_TIM5RST			(1 << 3)
#define RCC_APB1RSTR_TIM4RST			(1 << 2)
#define RCC_APB1RSTR_TIM3RST			(1 << 1)
#define RCC_APB1RSTR_TIM2RST			(1 << 0)

/* --- RCC_AHBENR values --------------------------------------------------- */

/** @defgroup rcc_ahbenr_en RCC_AHBENR enable values
@ingroup STM32L1xx_rcc_defines

@{*/
#define RCC_AHBENR_ETHMACENRX			(1 << 16)
#define RCC_AHBENR_ETHMACENTX			(1 << 15)
#define RCC_AHBENR_ETHMACEN			(1 << 14)
#define RCC_AHBENR_OTGFSEN			(1 << 12)
#define RCC_AHBENR_SDIOEN			(1 << 10)
#define RCC_AHBENR_FSMCEN			(1 << 8)
#define RCC_AHBENR_CRCEN			(1 << 6)
#define RCC_AHBENR_FLITFEN			(1 << 4)
#define RCC_AHBENR_SRAMEN			(1 << 2)
#define RCC_AHBENR_DMA2EN			(1 << 1)
#define RCC_AHBENR_DMA1EN			(1 << 0)
/*@}*/

/* --- RCC_APB2ENR values -------------------------------------------------- */

/** @defgroup rcc_apb2enr_en RCC_APB2ENR enable values
@ingroup STM32L1xx_rcc_defines

@{*/
#define RCC_APB2ENR_ADC3EN			(1 << 15) /* (XX) */
#define RCC_APB2ENR_USART1EN			(1 << 14)
#define RCC_APB2ENR_TIM8EN			(1 << 13) /* (XX) */
#define RCC_APB2ENR_SPI1EN			(1 << 12)
#define RCC_APB2ENR_TIM1EN			(1 << 11)
#define RCC_APB2ENR_ADC2EN			(1 << 10)
#define RCC_APB2ENR_ADC1EN			(1 << 9)
#define RCC_APB2ENR_IOPGEN			(1 << 8)  /* (XX) */
#define RCC_APB2ENR_IOPFEN			(1 << 7)  /* (XX) */
#define RCC_APB2ENR_IOPEEN			(1 << 6)
#define RCC_APB2ENR_IOPDEN			(1 << 5)
#define RCC_APB2ENR_IOPCEN			(1 << 4)
#define RCC_APB2ENR_IOPBEN			(1 << 3)
#define RCC_APB2ENR_IOPAEN			(1 << 2)
#define RCC_APB2ENR_AFIOEN			(1 << 0)
/*@}*/

/* --- RCC_APB1ENR values -------------------------------------------------- */

/** @defgroup rcc_apb1enr_en RCC_APB1ENR enable values
@ingroup STM32L1xx_rcc_defines

@{*/
#define RCC_APB1ENR_DACEN			(1 << 29)
#define RCC_APB1ENR_PWREN			(1 << 28)
#define RCC_APB1ENR_BKPEN			(1 << 27)
#define RCC_APB1ENR_CAN2EN			(1 << 26) /* (**) */
#define RCC_APB1ENR_CAN1EN			(1 << 25) /* (**) */
#define RCC_APB1ENR_CANEN			(1 << 25) /* (XX) Alias for CAN1EN */
#define RCC_APB1ENR_USBEN			(1 << 23) /* (XX) */
#define RCC_APB1ENR_I2C2EN			(1 << 22)
#define RCC_APB1ENR_I2C1EN			(1 << 21)
#define RCC_APB1ENR_UART5EN			(1 << 20)
#define RCC_APB1ENR_UART4EN			(1 << 19)
#define RCC_APB1ENR_USART3EN			(1 << 18)
#define RCC_APB1ENR_USART2EN			(1 << 17)
#define RCC_APB1ENR_SPI3EN			(1 << 15)
#define RCC_APB1ENR_SPI2EN			(1 << 14)
#define RCC_APB1ENR_WWDGEN			(1 << 11)
#define RCC_APB1ENR_TIM7EN			(1 << 5)
#define RCC_APB1ENR_TIM6EN			(1 << 4)
#define RCC_APB1ENR_TIM5EN			(1 << 3)
#define RCC_APB1ENR_TIM4EN			(1 << 2)
#define RCC_APB1ENR_TIM3EN			(1 << 1)
#define RCC_APB1ENR_TIM2EN			(1 << 0)
/*@}*/

/* --- RCC_BDCR values ----------------------------------------------------- */

#define RCC_BDCR_BDRST				(1 << 16)
#define RCC_BDCR_RTCEN				(1 << 15)
/* RCC_BDCR[9:8]: RTCSEL */
#define RCC_BDCR_LSEBYP				(1 << 2)
#define RCC_BDCR_LSERDY				(1 << 1)
#define RCC_BDCR_LSEON				(1 << 0)

/* --- RCC_CSR values ------------------------------------------------------ */

#define RCC_CSR_LPWRRSTF			(1 << 31)
#define RCC_CSR_WWDGRSTF			(1 << 30)
#define RCC_CSR_IWDGRSTF			(1 << 29)
#define RCC_CSR_SFTRSTF				(1 << 28)
#define RCC_CSR_PORRSTF				(1 << 27)
#define RCC_CSR_PINRSTF				(1 << 26)
#define RCC_CSR_RMVF				(1 << 24)
#define RCC_CSR_LSIRDY				(1 << 1)
#define RCC_CSR_LSION				(1 << 0)

/* --- RCC_AHBRSTR values -------------------------------------------------- */

#define RCC_AHBRSTR_ETHMACRST			(1 << 14)
#define RCC_AHBRSTR_OTGFSRST			(1 << 12)

/* --- RCC_CFGR2 values ---------------------------------------------------- */

/* I2S3SRC: I2S3 clock source */
#define RCC_CFGR2_I2S3SRC_SYSCLK		0x0
#define RCC_CFGR2_I2S3SRC_PLL3_VCO_CLK		0x1

/* I2S2SRC: I2S2 clock source */
#define RCC_CFGR2_I2S2SRC_SYSCLK		0x0
#define RCC_CFGR2_I2S2SRC_PLL3_VCO_CLK		0x1

/* PREDIV1SRC: PREDIV1 entry clock source */
#define RCC_CFGR2_PREDIV1SRC_HSE_CLK		0x0
#define RCC_CFGR2_PREDIV1SRC_PLL2_CLK		0x1

#define RCC_CFGR2_PLL2MUL			(1 << 0)
#define RCC_CFGR2_PREDIV2			(1 << 0)
#define RCC_CFGR2_PREDIV1			(1 << 0)

/* PLL3MUL: PLL3 multiplication factor */
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL8		0x6
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL9		0x7
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL10	0x8
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL11	0x9
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL12	0xa
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL13	0xb
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL14	0xc
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL16	0xe
#define RCC_CFGR2_PLL3MUL_PLL3_CLK_MUL20	0xf

/* PLL2MUL: PLL2 multiplication factor */
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL8		0x6
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL9		0x7
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL10	0x8
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL11	0x9
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL12	0xa
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL13	0xb
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL14	0xc
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL16	0xe
#define RCC_CFGR2_PLL2MUL_PLL2_CLK_MUL20	0xf

/* PREDIV2: PREDIV2 division factor */
#define RCC_CFGR2_PREDIV2_NODIV			0x0
#define RCC_CFGR2_PREDIV2_DIV2			0x1
#define RCC_CFGR2_PREDIV2_DIV3			0x2
#define RCC_CFGR2_PREDIV2_DIV4			0x3
#define RCC_CFGR2_PREDIV2_DIV5			0x4
#define RCC_CFGR2_PREDIV2_DIV6			0x5
#define RCC_CFGR2_PREDIV2_DIV7			0x6
#define RCC_CFGR2_PREDIV2_DIV8			0x7
#define RCC_CFGR2_PREDIV2_DIV9			0x8
#define RCC_CFGR2_PREDIV2_DIV10			0x9
#define RCC_CFGR2_PREDIV2_DIV11			0xa
#define RCC_CFGR2_PREDIV2_DIV12			0xb
#define RCC_CFGR2_PREDIV2_DIV13			0xc
#define RCC_CFGR2_PREDIV2_DIV14			0xd
#define RCC_CFGR2_PREDIV2_DIV15			0xe
#define RCC_CFGR2_PREDIV2_DIV16			0xf

/* --- Variable definitions ------------------------------------------------ */
extern u32 rcc_ppre1_frequency;
extern u32 rcc_ppre2_frequency;

/* --- Function prototypes ------------------------------------------------- */

typedef enum {
	PLL, HSE, HSI, LSE, LSI
} osc_t;

void rcc_osc_ready_int_clear(osc_t osc);
void rcc_osc_ready_int_enable(osc_t osc);
void rcc_osc_ready_int_disable(osc_t osc);
int rcc_osc_ready_int_flag(osc_t osc);
void rcc_css_int_clear(void);
int rcc_css_int_flag(void);
void rcc_wait_for_osc_ready(osc_t osc);
void rcc_osc_on(osc_t osc);
void rcc_osc_off(osc_t osc);
void rcc_css_enable(void);
void rcc_css_disable(void);
void rcc_osc_bypass_enable(osc_t osc);
void rcc_osc_bypass_disable(osc_t osc);
void rcc_peripheral_enable_clock(volatile u32 *reg, u32 en);
void rcc_peripheral_disable_clock(volatile u32 *reg, u32 en);
void rcc_peripheral_reset(volatile u32 *reg, u32 reset);
void rcc_peripheral_clear_reset(volatile u32 *reg, u32 clear_reset);
void rcc_set_sysclk_source(u32 clk);
void rcc_set_pll_multiplication_factor(u32 mul);
void rcc_set_pll_source(u32 pllsrc);
void rcc_set_pllxtpre(u32 pllxtpre);
void rcc_set_adcpre(u32 adcpre);
void rcc_set_ppre2(u32 ppre2);
void rcc_set_ppre1(u32 ppre1);
void rcc_set_hpre(u32 hpre);
void rcc_set_usbpre(u32 usbpre);
u32 rcc_get_system_clock_source(int i);
void rcc_clock_setup_in_hsi_out_64mhz(void);
void rcc_clock_setup_in_hsi_out_48mhz(void);

/**
 * Maximum speed possible for F100 (Value Line) on HSI
 */
void rcc_clock_setup_in_hsi_out_24mhz(void);
void rcc_clock_setup_in_hse_8mhz_out_24mhz(void);
void rcc_clock_setup_in_hse_8mhz_out_72mhz(void);
void rcc_clock_setup_in_hse_12mhz_out_72mhz(void);
void rcc_clock_setup_in_hse_16mhz_out_72mhz(void);
void rcc_backupdomain_reset(void);

#endif