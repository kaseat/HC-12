// Copyright 2017 Oleg Petrochenko
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _STM8S003F3_DEF_
#define _STM8S003F3_DEF_

/*======================================================================
*      Interrupt vector table
*=======================================================================*/
#define AWU_ISR                         0x03
#define CLK_CSS_ISR                     0x04
#define CLK_SWITCH_ISR                  0x04
#define EXTI0_ISR                       0x05
#define EXTI1_ISR                       0x06
#define EXTI2_ISR                       0x07
#define EXTI3_ISR                       0x08
#define EXTI4_ISR                       0x09
#define SPI_CRCERR_ISR                  0x0C
#define SPI_MODF_ISR                    0x0C
#define SPI_OVR_ISR                     0x0C
#define SPI_RXNE_ISR                    0x0C
#define SPI_TXE_ISR                     0x0C
#define SPI_WKUP_ISR                    0x0C
#define TIM1_CAPCOM_BIF_ISR             0x0D
#define TIM1_CAPCOM_TIF_ISR             0x0D
#define TIM1_OVR_UIF_ISR                0x0D
#define TIM1_CAPCOM_CC1IF_ISR           0x0E
#define TIM1_CAPCOM_CC2IF_ISR           0x0E
#define TIM1_CAPCOM_CC3IF_ISR           0x0E
#define TIM1_CAPCOM_CC4IF_ISR           0x0E
#define TIM1_CAPCOM_COMIF_ISR           0x0E
#define TIM2_OVR_UIF_ISR                0x0F
#define TIM2_CAPCOM_CC1IF_ISR           0x10
#define TIM2_CAPCOM_CC2IF_ISR           0x10
#define TIM2_CAPCOM_CC3IF_ISR           0x10
#define TIM2_CAPCOM_TIF_ISR             0x10
#define UART1_T_TC_ISR                  0x13
#define UART1_T_TXE_ISR                 0x13
#define UART1_R_IDLE_ISR                0x14
#define UART1_R_LBDF_ISR                0x14
#define UART1_R_OR_ISR                  0x14
#define UART1_R_PE_ISR                  0x14
#define UART1_R_RXNE_ISR                0x14
#define I2C_ADD10_ISR                   0x15
#define I2C_ADDR_ISR                    0x15
#define I2C_AF_ISR                      0x15
#define I2C_ARLO_ISR                    0x15
#define I2C_BERR_ISR                    0x15
#define I2C_BTF_ISR                     0x15
#define I2C_OVR_ISR                     0x15
#define I2C_RXNE_ISR                    0x15
#define I2C_SB_ISR                      0x15
#define I2C_STOPF_ISR                   0x15
#define I2C_TXE_ISR                     0x15
#define I2C_WUFH_ISR                    0x15
#define ADC1_AWDG_ISR                   0x18
#define ADC1_AWS0_ISR                   0x18
#define ADC1_AWS1_ISR                   0x18
#define ADC1_AWS2_ISR                   0x18
#define ADC1_AWS3_ISR                   0x18
#define ADC1_AWS4_ISR                   0x18
#define ADC1_AWS5_ISR                   0x18
#define ADC1_AWS6_ISR                   0x18
#define ADC1_AWS7_ISR                   0x18
#define ADC1_AWS8_ISR                   0x18
#define ADC1_AWS9_ISR                   0x18
#define ADC1_EOC_ISR                    0x18
#define TIM4_OVR_UIF_ISR                0x19
#define FLASH_EOP_ISR                   0x1A
#define FLASH_WR_PG_DIS_ISR             0x1A

/*======================================================================
*      General purpose I/O ports (GPIO)
*=======================================================================*/
typedef struct
{
	volatile unsigned char ODR;
	volatile unsigned char IDR;
	volatile unsigned char DDR;
	volatile unsigned char CR1;
	volatile unsigned char CR2;
} GpioTypedef;

#define GPIOA_BASE          (0x005000)
#define GPIOB_BASE          (0x005005)
#define GPIOC_BASE          (0x00500A)
#define GPIOD_BASE          (0x00500F)
#define GPIOE_BASE          (0x005014)
#define GPIOF_BASE          (0x005019)

#define GPIOA               ((GpioTypedef *) GPIOA_BASE)
#define GPIOB               ((GpioTypedef *) GPIOB_BASE)
#define GPIOC               ((GpioTypedef *) GPIOC_BASE)
#define GPIOD               ((GpioTypedef *) GPIOD_BASE)
#define GPIOE               ((GpioTypedef *) GPIOE_BASE)
#define GPIOF               ((GpioTypedef *) GPIOF_BASE)

/*======================================================================
*      Flash
*=======================================================================*/
typedef struct
{
	volatile unsigned char CR1;
	volatile unsigned char CR2;
	volatile unsigned char NCR2;
	volatile unsigned char FPR;
	volatile unsigned char NFPR;
	volatile unsigned char IAPSR;
	volatile unsigned short : 16;
	volatile unsigned char PUKR;
	volatile unsigned char : 8;
	volatile unsigned char DUKR;
} FlashTypedef;

#define FLASH_BASE                (0x00505A)

#define FLASH                     ((FlashTypedef *) FLASH_BASE)

#define FLASH_RASS_KEY1           ((uint8_t)0xAE)
#define FLASH_RASS_KEY2           ((uint8_t)0x56)
/*-------------------------------------------------------------------------
*      Flash control register 1 (FLASH_CR1)
*-----------------------------------------------------------------------*/

// Fixed Byte programming time
#define FLASH_CR1_FIX_Pos         (0U)
#define FLASH_CR1_FIX_Msk         (0x1U << FLASH_CR1_FIX_Pos)
#define FLASH_CR1_FIX             FLASH_CR1_FIX_Msk
// Flash Interrupt enable
#define FLASH_CR1_IE_Pos          (1U)
#define FLASH_CR1_IE_Msk          (0x1U << FLASH_CR1_IE_Pos)
#define FLASH_CR1_IE              FLASH_CR1_IE_Msk
// Power-down in Active-halt mode
#define FLASH_CR1_AHALT_Pos       (2U)
#define FLASH_CR1_AHALT_Msk       (0x1U << FLASH_CR1_AHALT_Pos)
#define FLASH_CR1_AHALT           FLASH_CR1_AHALT_Msk
// Power-down in Halt mode
#define FLASH_CR1_HALT_Pos        (3U)
#define FLASH_CR1_HALT_Msk        (0x1U << FLASH_CR1_HALT_Pos)
#define FLASH_CR1_HALT            FLASH_CR1_HALT_Msk

/*-------------------------------------------------------------------------
*      Flash control register 2 (FLASH_CR2)
*-----------------------------------------------------------------------*/

// Standard block programming
#define FLASH_CR2_PRG_Pos         (0U)
#define FLASH_CR2_PRG_Msk         (0x1U << FLASH_CR2_PRG_Pos)
#define FLASH_CR2_PRG             FLASH_CR2_PRG_Msk
// Fast block programming
#define FLASH_CR2_FPRG_Pos        (4U)
#define FLASH_CR2_FPRG_Msk        (0x1U << FLASH_CR2_FPRG_Pos)
#define FLASH_CR2_FPRG            FLASH_CR2_FPRG_Msk
// Block erasing
#define FLASH_CR2_ERASE_Pos       (5U)
#define FLASH_CR2_ERASE_Msk       (0x1U << FLASH_CR2_ERASE_Pos)
#define FLASH_CR2_ERASE           FLASH_CR2_ERASE_Msk
// Word programming
#define FLASH_CR2_WPRG_Pos        (6U)
#define FLASH_CR2_WPRG_Msk        (0x1U << FLASH_CR2_WPRG_Pos)
#define FLASH_CR2_WPRG            FLASH_CR2_WPRG_Msk
// Write option bytes
#define FLASH_CR2_OPT_Pos         (7U)
#define FLASH_CR2_OPT_Msk         (0x1U << FLASH_CR2_OPT_Pos)
#define FLASH_CR2_OPT             FLASH_CR2_OPT_Msk

/*-------------------------------------------------------------------------
*      Flash complementary control register 2 (FLASH_NCR2)
*-----------------------------------------------------------------------*/

// Block programming
#define FLASH_NCR2_NPRG_Pos        (0U)
#define FLASH_NCR2_NPRG_Msk        (0x1U << FLASH_NCR2_NPRG_Pos)
#define FLASH_NCR2_NPRG            FLASH_NCR2_NPRG_Msk
// Fast block programming
#define FLASH_NCR2_NFPRG_Pos       (4U)
#define FLASH_NCR2_NFPRG_Msk       (0x1U << FLASH_NCR2_NFPRG_Pos)
#define FLASH_NCR2_NFPRG           FLASH_NCR2_NFPRG_Msk
// Block erase
#define FLASH_NCR2_NERASE_Pos      (5U)
#define FLASH_NCR2_NERASE_Msk      (0x1U << FLASH_NCR2_NERASE_Pos)
#define FLASH_NCR2_NERASE          FLASH_NCR2_NERASE_Msk
// Word programming
#define FLASH_NCR2_NWPRG_Pos       (6U)
#define FLASH_NCR2_NWPRG_Msk       (0x1U << FLASH_NCR2_NWPRG_Pos)
#define FLASH_NCR2_NWPRG           FLASH_NCR2_NWPRG_Msk
// Write option bytes
#define FLASH_NCR2_NOPT_Pos        (7U)
#define FLASH_NCR2_NOPT_Msk        (0x1U << FLASH_NCR2_NOPT_Pos)
#define FLASH_NCR2_NOPT            FLASH_NCR2_NOPT_Msk

/*-------------------------------------------------------------------------
*      Flash status register (FLASH_IAPSR)
*-----------------------------------------------------------------------*/

// Write attempted to protected page flag
#define FLASH_IAPSR_WR_PG_DIS_Pos        (0U)
#define FLASH_IAPSR_WR_PG_DIS_Msk        (0x1U << FLASH_IAPSR_WR_PG_DIS_Pos)
#define FLASH_IAPSR_WR_PG_DIS            FLASH_IAPSR_WR_PG_DIS_Msk
// Flash Program memory unlocked flag
#define FLASH_IAPSR_PUL_Pos              (1U)
#define FLASH_IAPSR_PUL_Msk              (0x1U << FLASH_IAPSR_PUL_Pos)
#define FLASH_IAPSR_PUL                  FLASH_IAPSR_PUL_Msk
// End of programming (write or erase operation) flag
#define FLASH_IAPSR_EOP_Pos              (2U)
#define FLASH_IAPSR_EOP_Msk              (0x1U << FLASH_IAPSR_EOP_Pos)
#define FLASH_IAPSR_EOP                  FLASH_IAPSR_EOP_Msk
// Data EEPROM area unlocked flag
#define FLASH_IAPSR_DUL_Pos              (3U)
#define FLASH_IAPSR_DUL_Msk              (0x1U << FLASH_IAPSR_DUL_Pos)
#define FLASH_IAPSR_DUL                  FLASH_IAPSR_DUL_Msk
// End of high voltage flag
#define FLASH_IAPSR_HVOFF_Pos            (6U)
#define FLASH_IAPSR_HVOFF_Msk            (0x1U << FLASH_IAPSR_HVOFF_Pos)
#define FLASH_IAPSR_HVOFF                FLASH_IAPSR_HVOFF_Msk


/*======================================================================
*      Serial peripheral interface (SPI)
*=======================================================================*/
typedef struct
{
	// SPI control register 1 (SPI_CR1)
	volatile unsigned char CR1;
	// SPI control register 2 (SPI_CR2)
	volatile unsigned char CR2;
	// SPI interrupt control register (SPI_ICR)
	volatile unsigned char ICR;
	// SPI status register (SPI_SR)
	volatile unsigned char SR;
	// SPI data register (SPI_DR)
	volatile unsigned char DR;
	// SPI CRC polynomial register (SPI_CRCPR)
	volatile unsigned char CRCPR;
	// SPI Rx CRC register (SPI_RXCRCR)
	volatile unsigned char RXCRCR;
	// SPI Tx CRC register (SPI_TXCRCR)
	volatile unsigned char TXCRCR;
} SpiTypedef;

#define SPI_BASE                (0x005200)

#define SPI                     ((SpiTypedef *) SPI_BASE)

/*-------------------------------------------------------------------------
*      SPI control register 1 (SPI_CR1)
*-----------------------------------------------------------------------*/

// Clock phase bit position
#define SPI_CR1_CPHA_Pos        (0U)
// Clock phase bit mask
#define SPI_CR1_CPHA_Msk        (0x1U << SPI_CR1_CPHA_Pos)
// Clock phase (This bit should not be changed when the communication is ongoing)
//    0: The first clock transition is the first data capture edge
//    1: The second clock transition is the first data capture edge
#define SPI_CR1_CPHA            (SPI_CR1_CPHA_Msk)

// Clock polarity bit position
#define SPI_CR1_CPOL_Pos        (1U)
// Clock polarity bit mask
#define SPI_CR1_CPOL_Msk        (0x1U << SPI_CR1_CPOL_Pos)
// Clock polarity (This bit should not be changed when the communication is ongoing)
//    0: SCK to 0 when idle
//    1: SCK to 1 when idle
#define SPI_CR1_CPOL            (SPI_CR1_CPOL_Msk)

// Master selection bit position
#define SPI_CR1_MSTR_Pos        (2U)
// Master selection bit mask
#define SPI_CR1_MSTR_Msk        (0x1U << SPI_CR1_MSTR_Pos)
// Master selection (This bit should not be changed when the communication is ongoing)
//    0: Slave configuration
//    1: Master configuration
#define SPI_CR1_MSTR            (SPI_CR1_MSTR_Msk)

// Baud rate control bit position
#define SPI_CR1_BR_Pos          (3U)
// Baud rate control bit mask
#define SPI_CR1_BR_Msk          (0x7U << SPI_CR1_BR_Pos)
// Baud rate control (These bits should not be changed when the communication is ongoing)
//    000: fMASTER / 2
//    001: fMASTER / 4
//    010: fMASTER / 8
//    011: fMASTER / 16
//    100: fMASTER / 32
//    101: fMASTER / 64
//    110: fMASTER / 128
//    111: fMASTER / 256
#define SPI_CR1_BR              (SPI_CR1_BR_Msk)
// Baud rate control bit 0
#define SPI_CR1_BR_0            (0x1U << SPI_CR1_BR_Pos)
// Baud rate control bit 1
#define SPI_CR1_BR_1            (0x2U << SPI_CR1_BR_Pos)
// Baud rate control bit 2
#define SPI_CR1_BR_2            (0x4U << SPI_CR1_BR_Pos)

// SPI enable bit position
#define SPI_CR1_SPE_Pos         (6U)
// SPI enable bit mask
#define SPI_CR1_SPE_Msk         (0x1U << SPI_CR1_SPE_Pos)
// SPI enable ( When disabling the SPI, follow the procedure described in Section 20.3.8: Disabling the SPI on page 277)
//    0: Peripheral disabled
//    1: Peripheral enabled
#define SPI_CR1_SPE             (SPI_CR1_SPE_Msk)

// Frame format bit position
#define SPI_CR1_LSBFIRST_Pos    (7U)
// Frame format bit mask
#define SPI_CR1_LSBFIRST_Msk    (0x1U << SPI_CR1_LSBFIRST_Pos)
// Frame format (This bit should not be changed when the communication is ongoing)
//    0: MSB is transmitted first
//    1: LSB is transmitted first
#define SPI_CR1_LSBFIRST        (SPI_CR1_LSBFIRST_Msk)

/*-------------------------------------------------------------------------
*      SPI control register 2 (SPI_CR2)
*-----------------------------------------------------------------------*/

// Internal slave select bit position
#define SPI_CR2_SSI_Pos        (0U)
// Internal slave select bit mask
#define SPI_CR2_SSI_Msk        (0x1U << SPI_CR2_SSI_Pos)
// Internal slave select
// This bit has effect only when SSM bit is set. The value of this bit is forced onto the NSS pin and the I/O value of the NSS pin is ignored
//    0: Slave mode
//    1: Master mode
#define SPI_CR2_SSI            (SPI_CR2_SSI_Msk)

// Software slave management bit position
#define SPI_CR2_SSM_Pos        (1U)
// Software slave management bit mask
#define SPI_CR2_SSM_Msk        (0x1U << SPI_CR2_SSM_Pos)
// Software slave management
//    0: Software slave management disabled
//    1: Software slave management enabled
// When the SSM bit is set, the NSS pin input is replaced with the value coming from the SSI bit
#define SPI_CR2_SSM            (SPI_CR2_SSM_Msk)

// Receive only bit position
#define SPI_CR2_RXONLY_Pos     (2U)
// Receive only bit mask
#define SPI_CR2_RXONLY_Msk     (0x1U << SPI_CR2_RXONLY_Pos)
// Receive only
//    0: Full duplex(Transmit and receive)
//    1: Output disabled(Receive only mode)
// This bit combined with BDM bit selects the direction of transfer in 2 line uni-directional mode
// This bit is also useful in a multi-slave system in which this particular slave is not accessed, the output from the accessed slave is not corrupted
#define SPI_CR2_RXONLY         (SPI_CR2_RXONLY_Msk)

// Transmit CRC next bit position
#define SPI_CR2_CRCNEXT_Pos    (4U)
// Transmit CRC next bit mask
#define SPI_CR2_CRCNEXT_Msk    (0x1U << SPI_CR2_CRCNEXT_Pos)
// Transmit CRC next
//    0: Next transmit value is from Tx buffer
//    1: Next transmit value is from Tx CRC register
#define SPI_CR2_CRCNEXT        (SPI_CR2_CRCNEXT_Msk)

// Hardware CRC calculation enable bit position
#define SPI_CR2_CRCEN_Pos      (5U)
// Hardware CRC calculation enable bit mask
#define SPI_CR2_CRCEN_Msk      (0x1U << SPI_CR2_CRCEN_Pos)
// Hardware CRC calculation enable
//    0: CRC calculation disabled
//    1: CRC calculation Enabled
// Note : This bit should be written only when SPI is disabled(SPE = '0') for correct operation
#define SPI_CR2_CRCEN          (SPI_CR2_CRCEN_Msk)

// Input/Output enable in bidirectional mode bit position
#define SPI_CR2_BDOE_Pos       (6U)
// Input/Output enable in bidirectional mode bit mask
#define SPI_CR2_BDOE_Msk       (0x1U << SPI_CR2_BDOE_Pos)
// Input/Output enable in bidirectional mode
// This bit selects the direction of transfer in bidirectional mode when BDM is set to 1
//    0: Input enabled(receive - only mode)
//    1: Output enabled(transmit - only mode)
// In master mode, the MOSI pin is used and in slave mode, the MISO pin is used
#define SPI_CR2_BDOE           (SPI_CR2_BDOE_Msk)

// Bidirectional data mode enable bit position
#define SPI_CR2_BDM_Pos        (7U)
// Bidirectional data mode enable bit mask
#define SPI_CR2_BDM_Msk        (0x1U << SPI_CR2_BDM_Pos)
// Bidirectional data mode enable
//    0: 2 - line unidirectional data mode selected
//    1: 1 - line bidirectional data mode selected
#define SPI_CR2_BDM            (SPI_CR2_BDM_Msk)

/*-------------------------------------------------------------------------
*      SPI interrupt control register (SPI_ICR)
*-----------------------------------------------------------------------*/

// Wakeup interrupt enable bit position
#define SPI_ICR_WKIE_Pos       (4U)
// Wakeup interrupt enable bit mask
#define SPI_ICR_WKIE_Msk       (0x1U << SPI_ICR_WKIE_Pos)
// Wakeup interrupt enable
//    0: Wakeup interrupt masked
//    1: Wakeup interrupt enabled.This allows an interrupt request to be generated when the WKUP flag is set
#define SPI_ICR_WKIE           (SPI_ICR_WKIE_Msk)

// Error interrupt enable bit position
#define SPI_ICR_ERRIE_Pos      (5U)
// Error interrupt enable bit mask
#define SPI_ICR_ERRIE_Msk      (0x1U << SPI_ICR_ERRIE_Pos)
// Error interrupt enable
//    0: Error interrupt is masked
//    1: Error interrupt is enabled.This allows an interrupt request to be generated when an error condition occurs(CRCERR, OVR, MODF)
#define SPI_ICR_ERRIE          (SPI_ICR_ERRIE_Msk)

// RX buffer not empty interrupt enable bit position
#define SPI_ICR_RXIE_Pos       (6U)
// RX buffer not empty interrupt enable bit mask
#define SPI_ICR_RXIE_Msk       (0x1U << SPI_ICR_RXIE_Pos)
// RX buffer not empty interrupt enable
//    0: RXNE interrupt masked
//    1: RXNE interrupt not masked.This allows an interrupt request to be generated when the RXNE flag is set
#define SPI_ICR_RXIE           (SPI_ICR_RXIE_Msk)

// Tx buffer empty interrupt enable bit position
#define SPI_ICR_TXIE_Pos       (7U)
// Tx buffer empty interrupt enable bit mask
#define SPI_ICR_TXIE_Msk       (0x1U << SPI_ICR_TXIE_Pos)
// Tx buffer empty interrupt enable
//    0: TXE interrupt masked
//    1: TXE interrupt not masked.This allows an interrupt request to be generated when the TXE flag is set
#define SPI_ICR_TXIE           (SPI_ICR_TXIE_Msk)

/*-------------------------------------------------------------------------
*      SPI status register (SPI_SR)
*-----------------------------------------------------------------------*/

// Receive buffer not empty bit position
#define SPI_SR_RXNE_Pos       (0U)
// Receive buffer not empty bit mask
#define SPI_SR_RXNE_Msk       (0x1U << SPI_SR_RXNE_Pos)
// Receive buffer not empty
//    0: Rx buffer empty
//    1: Rx buffer not empty
#define SPI_SR_RXNE           (SPI_SR_RXNE_Msk)

// Transmit buffer empty bit position
#define SPI_SR_TXE_Pos        (1U)
// Transmit buffer empty bit mask
#define SPI_SR_TXE_Msk        (0x1U << SPI_SR_TXE_Pos)
// Transmit buffer empty
//    0: Tx buffer not empty
//    1: Tx buffer empty
#define SPI_SR_TXE            (SPI_SR_TXE_Msk)

// Transmit buffer empty bit position
#define SPI_SR_WKUP_Pos       (3U)
// Transmit buffer empty bit mask
#define SPI_SR_WKUP_Msk       (0x1U << SPI_SR_WKUP_Pos)
// Transmit buffer empty
//    0: No wakeup event occurred
//    1 : Wakeup event occurred
// This flag is set on the first sampling edge on SCK when the STM8 is in Halt mode and the SPI is configured as slave
// This flag is reset by software writing 0
#define SPI_SR_WKUP           (SPI_SR_WKUP_Msk)

// CRC error flag bit position
#define SPI_SR_CRCERR_Pos     (4U)
// CRC error flag bit mask
#define SPI_SR_CRCERR_Msk     (0x1U << SPI_SR_CRCERR_Pos)
// CRC error flag
//    0: CRC value received matches the SPI_RXCRCR value
//    1: CRC value received does not match the SPI_RXCRCR value
// This flag is set by hardware and cleared by software writing 0
#define SPI_SR_CRCERR         (SPI_SR_CRCERR_Msk)

// Mode fault bit position
#define SPI_SR_MODF_Pos       (5U)
// Mode fault bit mask
#define SPI_SR_MODF_Msk       (0x1U << SPI_SR_MODF_Pos)
// Mode fault
//    0: No Mode fault occurred
//    1: Mode fault occurred
// This flag is set by hardware and reset by a software sequence
#define SPI_SR_MODF           (SPI_SR_MODF_Msk)

// Overrun flag bit position
#define SPI_SR_OVR_Pos        (6U)
// Overrun flag bit mask
#define SPI_SR_OVR_Msk        (0x1U << SPI_SR_OVR_Pos)
// Overrun flag
//    0: No Overrun occurred
//    1: Overrun occurred
//This flag is set by hardware and reset by a software sequence
#define SPI_SR_OVR            (SPI_SR_OVR_Msk)

// Busy flag bit position
#define SPI_SR_BSY_Pos        (7U)
// Busy flag bit mask
#define SPI_SR_BSY_Msk        (0x1U << SPI_SR_BSY_Pos)
// Busy flag
//    0: SPI not busy
//    1: SPI is busy in communication
// This flag is set and reset by hardware.
// Note: BSY flag must be used with cautious: refer to Section 20.3.7: Status flags on page 277 and Section 20.3.8: Disabling the SPI on page 277
#define SPI_SR_BSY            (SPI_SR_BSY_Msk)

/*======================================================================
*      External interrupts (EXTI)
*=======================================================================*/
typedef struct
{
	volatile unsigned char CR1;
	volatile unsigned char CR2;
} ExtiTypedef;

#define EXTI_BASE                (0x0050A0)

#define EXTI                     ((ExtiTypedef *) EXTI_BASE)

#define EXTI_CR1_PAIS_Pos        (0U)
#define EXTI_CR1_PAIS_Msk        (0x3U << EXTI_CR1_PAIS_Pos)
#define EXTI_CR1_PAIS            EXTI_CR1_PAIS_Msk
#define EXTI_CR1_PAIS_0          (0x01U << EXTI_CR1_PAIS_Pos)
#define EXTI_CR1_PAIS_1          (0x02U << EXTI_CR1_PAIS_Pos)
#define EXTI_CR1_PBIS_Pos        (2U)
#define EXTI_CR1_PBIS_Msk        (0x3U << EXTI_CR1_PBIS_Pos)
#define EXTI_CR1_PBIS            EXTI_CR1_PBIS_Msk
#define EXTI_CR1_PBIS_0          (0x01U << EXTI_CR1_PBIS_Pos)
#define EXTI_CR1_PBIS_1          (0x02U << EXTI_CR1_PBIS_Pos)
#define EXTI_CR1_PCIS_Pos        (4U)
#define EXTI_CR1_PCIS_Msk        (0x3U << EXTI_CR1_PCIS_Pos)
#define EXTI_CR1_PCIS            EXTI_CR1_PCIS_Msk
#define EXTI_CR1_PCIS_0          (0x01U << EXTI_CR1_PCIS_Pos)
#define EXTI_CR1_PCIS_1          (0x02U << EXTI_CR1_PCIS_Pos)
#define EXTI_CR1_PDIS_Pos        (6U)
#define EXTI_CR1_PDIS_Msk        (0x3U << EXTI_CR1_PDIS_Pos)
#define EXTI_CR1_PDIS            EXTI_CR1_PDIS_Msk
#define EXTI_CR1_PDIS_0          (0x01U << EXTI_CR1_PDIS_Pos)
#define EXTI_CR1_PDIS_1          (0x02U << EXTI_CR1_PDIS_Pos)
#define EXTI_CR2_PEIS_Pos        (0U)
#define EXTI_CR2_PEIS_Msk        (0x3U << EXTI_CR1_PEIS_Pos)
#define EXTI_CR2_PEIS            EXTI_CR1_PEIS_Msk
#define EXTI_CR2_PEIS_0          (0x01U << EXTI_CR1_PEIS_Pos)
#define EXTI_CR2_PEIS_1          (0x02U << EXTI_CR1_PEIS_Pos)
#define EXTI_CR2_TLIS_Pos        (2U)
#define EXTI_CR2_TLIS_Msk        (0x3U << EXTI_CR2_TLIS_Pos)
#define EXTI_CR2_TLIS            EXTI_CR2_TLIS_Msk



/*======================================================================
*      WWDG
*=======================================================================*/
typedef struct
{
	volatile unsigned char CR;
	volatile unsigned char WR;
} WwdgTypedef;

#define WWDG_BASE              (0x0050D1)

#define WWDG                   ((WwdgTypedef *) WWDG_BASE)

#define WWDG_CR_WDGA_Pos       (7U)
#define WWDG_CR_WDGA_Msk       (0x1U << WWDG_CR_WDGA_Pos)
#define WWDG_CR_WDGA           WWDG_CR_WDGA_Msk

#define WWDG_CR_T6_Pos         (6U)
#define WWDG_CR_T6_Msk         (0x1U << WWDG_CR_T6_Pos)
#define WWDG_CR_T6             WWDG_CR_T6_Msk

#define WWDG_CR_T5_Pos         (5U)
#define WWDG_CR_T5_Msk         (0x1U << WWDG_CR_T5_Pos)
#define WWDG_CR_T5             WWDG_CR_T5_Msk

#define WWDG_CR_T4_Pos         (4U)
#define WWDG_CR_T4_Msk         (0x1U << WWDG_CR_T4_Pos)
#define WWDG_CR_T4             WWDG_CR_T4_Msk

#define WWDG_CR_T3_Pos         (3U)
#define WWDG_CR_T3_Msk         (0x1U << WWDG_CR_T3_Pos)
#define WWDG_CR_T3             WWDG_CR_T3_Msk

#define WWDG_CR_T2_Pos         (2U)
#define WWDG_CR_T2_Msk         (0x1U << WWDG_CR_T2_Pos)
#define WWDG_CR_T2             WWDG_CR_T2_Msk

#define WWDG_CR_T1_Pos         (1U)
#define WWDG_CR_T1_Msk         (0x1U << WWDG_CR_T1_Pos)
#define WWDG_CR_T1             WWDG_CR_T1_Msk

#define WWDG_CR_T0_Pos         (0U)
#define WWDG_CR_T0_Msk         (0x1U << WWDG_CR_T0_Pos)
#define WWDG_CR_T0             WWDG_CR_T0_Msk

/*======================================================================
*      16-bit advanced control timer (TIM1)
*=======================================================================*/
typedef struct
{
	volatile unsigned char CR1;
	volatile unsigned char CR2;
	volatile unsigned char SMCR;
	volatile unsigned char ETR;
	volatile unsigned char IER;
	volatile unsigned char SR1;
	volatile unsigned char SR2;
	volatile unsigned char EGR;
	volatile unsigned char CCMR1;
	volatile unsigned char CCMR2;
	volatile unsigned char CCMR3;
	volatile unsigned char CCMR4;
	volatile unsigned char CCER1;
	volatile unsigned char CCER2;
	volatile unsigned char CNTRH;
	volatile unsigned char CNTRL;
	volatile unsigned char PSCRH;
	volatile unsigned char PSCRL;
	volatile unsigned char ARRH;
	volatile unsigned char ARRL;
	volatile unsigned char RCR;
	volatile unsigned char CCR1H;
	volatile unsigned char CCR1L;
	volatile unsigned char CCR2H;
	volatile unsigned char CCR2L;
	volatile unsigned char CCR3H;
	volatile unsigned char CCR3L;
	volatile unsigned char CCR4H;
	volatile unsigned char CCR4L;
	volatile unsigned char BKR;
	volatile unsigned char DTR;
	volatile unsigned char OISR;
} Tim1Typedef;

#define TIM1_BASE                (0x005250)
#define TIM1                     ((Tim1Typedef *) TIM1_BASE)

/*-------------------------------------------------------------------------
*      Control register 1 (TIM1_CR1)
*-----------------------------------------------------------------------*/

// Counter enable
#define TIM1_CR1_CEN_Pos         (0U)
#define TIM1_CR1_CEN_Msk         (0x1U << TIM1_CR1_CEN_Pos)
#define TIM1_CR1_CEN             TIM1_CR1_CEN_Msk
// Update disable
#define TIM1_CR1_UDIS_Pos        (1U)
#define TIM1_CR1_UDIS_Msk        (0x1U << TIM1_CR1_UDIS_Pos)
#define TIM1_CR1_UDIS            TIM1_CR1_UDIS_Msk
// Update request source
#define TIM1_CR1_URS_Pos         (2U)
#define TIM1_CR1_URS_Msk         (0x1U << TIM1_CR1_URS_Pos)
#define TIM1_CR1_URS             TIM1_CR1_URS_Msk
// One-pulse mode
#define TIM1_CR1_OPM_Pos         (3U)
#define TIM1_CR1_OPM_Msk         (0x1U << TIM1_CR1_OPM_Pos)
#define TIM1_CR1_OPM             TIM1_CR1_OPM_Msk
// Direction
#define TIM1_CR1_DIR_Pos         (4U)
#define TIM1_CR1_DIR_Msk         (0x1U << TIM1_CR1_DIR_Pos)
#define TIM1_CR1_DIR             TIM1_CR1_DIR_Msk
// Center-aligned mode selection
#define TIM1_CR1_CMS_Pos         (5U)
#define TIM1_CR1_CMS_Msk         (0x3U << TIM1_CR1_CMS_Pos)
#define TIM1_CR1_CMS             TIM1_CR1_CMS_Msk
#define TIM1_CR1_CMS_0           (0x1U << TIM1_CR1_CMS_Pos)
#define TIM1_CR1_CMS_1           (0x2U << TIM1_CR1_CMS_Pos)
// Auto-reload preload enable
#define TIM1_CR1_ARPE_Pos        (7U)
#define TIM1_CR1_ARPE_Msk        (0x1U << TIM1_CR1_ARPE_Pos)
#define TIM1_CR1_ARPE            TIM1_CR1_ARPE_Msk

/*-------------------------------------------------------------------------
*      Control register 2 (TIM1_CR2)
*-----------------------------------------------------------------------*/

// Capture/compare preloaded control
#define TIM1_CR2_CCPC_Pos        (0U)
#define TIM1_CR2_CCPC_Msk        (0x1U << TIM1_CR2_CCPC_Pos)
#define TIM1_CR2_CCPC            TIM1_CR2_CCPC_Msk
// Capture/compare control update selection
#define TIM1_CR2_COMS_Pos        (2U)
#define TIM1_CR2_COMS_Msk        (0x1U << TIM1_CR2_COMS_Pos)
#define TIM1_CR2_COMS            TIM1_CR2_COMS_Msk
// Master mode selection
#define TIM1_CR2_MMS_Pos         (4U)
#define TIM1_CR2_MMS_Msk         (0x7U << TIM1_CR2_MMS_Pos)
#define TIM1_CR2_MMS             TIM1_CR2_MMS_Msk
#define TIM1_CR2_MMS_0           (0x1U << TIM1_CR2_MMS_Pos)
#define TIM1_CR2_MMS_1           (0x2U << TIM1_CR2_MMS_Pos)
#define TIM1_CR2_MMS_2           (0x4U << TIM1_CR2_MMS_Pos)

/*-------------------------------------------------------------------------
*      Slave mode control register (TIM1_SMCR)
*-----------------------------------------------------------------------*/

// Clock/trigger/slave mode selection
#define TIM1_SMCR_SMS_Pos        (0U)
#define TIM1_SMCR_SMS_Msk        (0x7U << TIM1_SMCR_SMS_Pos)
#define TIM1_SMCR_SMS            TIM1_SMCR_SMS_Msk
#define TIM1_SMCR_SMS_0          (0x1U << TIM1_SMCR_SMS_Pos)
#define TIM1_SMCR_SMS_1          (0x2U << TIM1_SMCR_SMS_Pos)
#define TIM1_SMCR_SMS_2          (0x4U << TIM1_SMCR_SMS_Pos)
// Trigger selection
#define TIM1_SMCR_TS_Pos         (4U)
#define TIM1_SMCR_TS_Msk         (0x7U << TIM1_SMCR_TS_Pos)
#define TIM1_SMCR_TS             TIM1_SMCR_TS_Msk
#define TIM1_SMCR_TS_0           (0x1U << TIM1_SMCR_TS_Pos)
#define TIM1_SMCR_TS_1           (0x2U << TIM1_SMCR_TS_Pos)
#define TIM1_SMCR_TS_2           (0x4U << TIM1_SMCR_TS_Pos)
// Master/slave mode
#define TIM1_SMCR_MSM_Pos        (7U)
#define TIM1_SMCR_MSM_Msk        (0x1U << TIM1_SMCR_MSM_Pos)
#define TIM1_SMCR_MSM            TIM1_SMCR_MSM_Msk

/*-------------------------------------------------------------------------
*      External trigger register (TIM1_ETR)
*-----------------------------------------------------------------------*/

// External trigger filter
#define TIM1_ETR_ETF_Pos        (0U)
#define TIM1_ETR_ETF_Msk        (0xFU << TIM1_ETR_ETF_Pos)
#define TIM1_ETR_ETF            TIM1_ETR_ETF_Msk
#define TIM1_ETR_ETF_0          (0x1U << TIM1_ETR_ETF_Pos)
#define TIM1_ETR_ETF_1          (0x2U << TIM1_ETR_ETF_Pos)
#define TIM1_ETR_ETF_2          (0x4U << TIM1_ETR_ETF_Pos)
#define TIM1_ETR_ETF_3          (0x8U << TIM1_ETR_ETF_Pos)
// External trigger prescaler
#define TIM1_ETR_ETPS_Pos       (4U)
#define TIM1_ETR_ETPS_Msk       (0x3U << TIM1_ETR_ETPS_Pos)
#define TIM1_ETR_ETPS           TIM1_ETR_ETPS_Msk
#define TIM1_ETR_ETPS_0         (0x1U << TIM1_ETR_ETPS_Pos)
#define TIM1_ETR_ETPS_1         (0x2U << TIM1_ETR_ETPS_Pos)
// External clock enable
#define TIM1_ETR_ECE_Pos        (6U)
#define TIM1_ETR_ECE_Msk        (0x1U << TIM1_ETR_ECE_Pos)
#define TIM1_ETR_ECE            TIM1_ETR_ECE_Msk
// External trigger polarity
#define TIM1_ETR_ETP_Pos        (7U)
#define TIM1_ETR_ETP_Msk        (0x1U << TIM1_ETR_ETP_Pos)
#define TIM1_ETR_ETP            TIM1_ETR_ETP_Msk

/*-------------------------------------------------------------------------
*      Interrupt enable register (TIM1_IER)
*-----------------------------------------------------------------------*/

// Update interrupt enable
#define TIM1_IER_UIE_Pos        (0U)
#define TIM1_IER_UIE_Msk        (0x1U << TIM1_IER_UIE_Pos)
#define TIM1_IER_UIE            TIM1_IER_UIE_Msk
// Capture/compare 1 interrupt enable
#define TIM1_IER_CC1IE_Pos      (1U)
#define TIM1_IER_CC1IE_Msk      (0x1U << TIM1_IER_CC1IE_Pos)
#define TIM1_IER_CC1IE          TIM1_IER_CC1IE_Msk
// Capture/compare 2 interrupt enable
#define TIM1_IER_CC2IE_Pos      (2U)
#define TIM1_IER_CC2IE_Msk      (0x1U << TIM1_IER_CC2IE_Pos)
#define TIM1_IER_CC2IE          TIM1_IER_CC2IE_Msk
// Capture/compare 3 interrupt enable
#define TIM1_IER_CC3IE_Pos      (3U)
#define TIM1_IER_CC3IE_Msk      (0x1U << TIM1_IER_CC3IE_Pos)
#define TIM1_IER_CC3IE          TIM1_IER_CC3IE_Msk
// Capture/compare 4 interrupt enable
#define TIM1_IER_CC4IE_Pos      (4U)
#define TIM1_IER_CC4IE_Msk      (0x1U << TIM1_IER_CC4IE_Pos)
#define TIM1_IER_CC4IE          TIM1_IER_CC4IE_Msk
// Commutation interrupt enable
#define TIM1_IER_COMIE_Pos      (5U)
#define TIM1_IER_COMIE_Msk      (0x1U << TIM1_IER_COMIE_Pos)
#define TIM1_IER_COMIE          TIM1_IER_COMIE_Msk
// Trigger interrupt enable
#define TIM1_IER_TIE_Pos        (6U)
#define TIM1_IER_TIE_Msk        (0x1U << TIM1_IER_TIE_Pos)
#define TIM1_IER_TIE            TIM1_IER_TIE_Msk
// Break interrupt enable
#define TIM1_IER_BIE_Pos        (7U)
#define TIM1_IER_BIE_Msk        (0x1U << TIM1_IER_BIE_Pos)
#define TIM1_IER_BIE            TIM1_IER_BIE_Msk

/*-------------------------------------------------------------------------
*      Status register 1 (TIM1_SR1)
*-----------------------------------------------------------------------*/

// Update interrupt flag
#define TIM1_SR1_UIF_Pos        (0U)
#define TIM1_SR1_UIF_Msk        (0x1U << TIM1_SR1_UIF_Pos)
#define TIM1_SR1_UIF            TIM1_SR1_UIF_Msk
// Capture/compare 1 interrupt flag
#define TIM1_SR1_CC1IF_Pos      (1U)
#define TIM1_SR1_CC1IF_Msk      (0x1U << TIM1_SR1_CC1IF_Pos)
#define TIM1_SR1_CC1IF          TIM1_SR1_CC1IF_Msk
// Capture/compare 2 interrupt flag
#define TIM1_SR1_CC2IF_Pos      (2U)
#define TIM1_SR1_CC2IF_Msk      (0x1U << TIM1_SR1_CC2IF_Pos)
#define TIM1_SR1_CC2IF          TIM1_SR1_CC2IF_Msk
// Capture/compare 3 interrupt flag
#define TIM1_SR1_CC3IF_Pos      (3U)
#define TIM1_SR1_CC3IF_Msk      (0x1U << TIM1_SR1_CC3IF_Pos)
#define TIM1_SR1_CC3IF          TIM1_SR1_CC3IF_Msk
// Capture/compare 4 interrupt flag
#define TIM1_SR1_CC4IF_Pos      (4U)
#define TIM1_SR1_CC4IF_Msk      (0x1U << TIM1_SR1_CC4IF_Pos)
#define TIM1_SR1_CC4IF          TIM1_SR1_CC4IF_Msk
// Commutation interrupt flag
#define TIM1_SR1_COMIF_Pos      (5U)
#define TIM1_SR1_COMIF_Msk      (0x1U << TIM1_SR1_COMIF_Pos)
#define TIM1_SR1_COMIF          TIM1_SR1_COMIF_Msk
// Trigger interrupt flag
#define TIM1_SR1_TIF_Pos        (6U)
#define TIM1_SR1_TIF_Msk        (0x1U << TIM1_SR1_TIF_Pos)
#define TIM1_SR1_TIF            TIM1_SR1_TIF_Msk
// Break interrupt flag
#define TIM1_SR1_BIF_Pos        (7U)
#define TIM1_SR1_BIF_Msk        (0x1U << TIM1_SR1_BIF_Pos)
#define TIM1_SR1_BIF            TIM1_SR1_BIF_Msk

/*-------------------------------------------------------------------------
*      Status register 2 (TIM1_SR2)
*-----------------------------------------------------------------------*/

// Capture/compare 1 overcapture flag
#define TIM1_SR2_CC1OF_Pos        (1U)
#define TIM1_SR2_CC1OF_Msk        (0x1U << TIM1_SR2_CC1OF_Pos)
#define TIM1_SR2_CC1OF            TIM1_SR2_CC1OF_Msk
// Capture/compare 2 overcapture flag
#define TIM1_SR2_CC2OF_Pos        (2U)
#define TIM1_SR2_CC2OF_Msk        (0x1U << TIM1_SR2_CC2OF_Pos)
#define TIM1_SR2_CC2OF            TIM1_SR2_CC2OF_Msk
// Capture/compare 3 overcapture flag
#define TIM1_SR2_CC3OF_Pos        (3U)
#define TIM1_SR2_CC3OF_Msk        (0x1U << TIM1_SR2_CC3OF_Pos)
#define TIM1_SR2_CC3OF            TIM1_SR2_CC3OF_Msk
// Capture/compare 4 overcapture flag
#define TIM1_SR2_CC4OF_Pos        (4U)
#define TIM1_SR2_CC4OF_Msk        (0x1U << TIM1_SR2_CC4OF_Pos)
#define TIM1_SR2_CC4OF            TIM1_SR2_CC4OF_Msk

/*-------------------------------------------------------------------------
*      Event generation register (TIM1_EGR)
*-----------------------------------------------------------------------*/

// Update generation
#define TIM1_EGR_UG_Pos           (0U)
#define TIM1_EGR_UG_Msk           (0x1U << TIM1_EGR_UG_Pos)
#define TIM1_EGR_UG               TIM1_EGR_UG_Msk
// Capture/compare 1 generation
#define TIM1_EGR_CC1G_Pos         (1U)
#define TIM1_EGR_CC1G_Msk         (0x1U << TIM1_EGR_CC1G_Pos)
#define TIM1_EGR_CC1G             TIM1_EGR_CC1G_Msk
// Capture/compare 2 generation
#define TIM1_EGR_CC2G_Pos         (2U)
#define TIM1_EGR_CC2G_Msk         (0x1U << TIM1_EGR_CC2G_Pos)
#define TIM1_EGR_CC2G             TIM1_EGR_CC2G_Msk
// Capture/compare 3 generation
#define TIM1_EGR_CC3G_Pos         (3U)
#define TIM1_EGR_CC3G_Msk         (0x1U << TIM1_EGR_CC3G_Pos)
#define TIM1_EGR_CC3G             TIM1_EGR_CC3G_Msk
// Capture/compare 4 generation
#define TIM1_EGR_CC4G_Pos         (4U)
#define TIM1_EGR_CC4G_Msk         (0x1U << TIM1_EGR_CC4G_Pos)
#define TIM1_EGR_CC4G             TIM1_EGR_CC4G_Msk
// Capture/compare control update generation
#define TIM1_EGR_COMG_Pos         (5U)
#define TIM1_EGR_COMG_Msk         (0x1U << TIM1_EGR_COMG_Pos)
#define TIM1_EGR_COMG             TIM1_EGR_COMG_Msk
// Trigger generation
#define TIM1_EGR_TG_Pos           (6U)
#define TIM1_EGR_TG_Msk           (0x1U << TIM1_EGR_TG_Pos)
#define TIM1_EGR_TG               TIM1_EGR_TG_Msk
// Break generation
#define TIM1_EGR_BG_Pos           (7U)
#define TIM1_EGR_BG_Msk           (0x1U << TIM1_EGR_BG_Pos)
#define TIM1_EGR_BG               TIM1_EGR_BG_Msk

/*-------------------------------------------------------------------------
*      Capture/compare mode register 1 (TIM1_CCMR1)
*-----------------------------------------------------------------------*/

// Capture/compare 1 selection
#define TIM1_CCMR1_CC1S_Pos       (0U)
#define TIM1_CCMR1_CC1S_Msk       (0x3U << TIM1_CCMR1_CC1S_Pos)
#define TIM1_CCMR1_CC1S           TIM1_CCMR1_CC1S_Msk
#define TIM1_CCMR1_CC1S_0         (0x1U << TIM1_CCMR1_CC1S_Pos)
#define TIM1_CCMR1_CC1S_1         (0x2U << TIM1_CCMR1_CC1S_Pos)
// Output compare 1 fast enable
#define TIM1_CCMR1_OC1FE_Pos      (2U)
#define TIM1_CCMR1_OC1FE_Msk      (0x1U << TIM1_CCMR1_OC1FE_Pos)
#define TIM1_CCMR1_OC1FE          TIM1_CCMR1_OC1FE_Msk
// Output compare 1 preload enable
#define TIM1_CCMR1_OC1PE_Pos      (3U)
#define TIM1_CCMR1_OC1PE_Msk      (0x1U << TIM1_CCMR1_OC1PE_Pos)
#define TIM1_CCMR1_OC1PE          TIM1_CCMR1_OC1PE_Msk
// Output compare 1 mode
#define TIM1_CCMR1_OC1M_Pos       (4U)
#define TIM1_CCMR1_OC1M_Msk       (0x7U << TIM1_CCMR1_OC1M_Pos)
#define TIM1_CCMR1_OC1M           TIM1_CCMR1_OC1M_Msk
#define TIM1_CCMR1_OC1M_0         (0x1U << TIM1_CCMR1_OC1M_Pos)
#define TIM1_CCMR1_OC1M_1         (0x2U << TIM1_CCMR1_OC1M_Pos)
#define TIM1_CCMR1_OC1M_2         (0x4U << TIM1_CCMR1_OC1M_Pos)
// Output compare 1 clear enable
#define TIM1_CCMR1_OC1CE_Pos      (7U)
#define TIM1_CCMR1_OC1CE_Msk      (0x1U << TIM1_CCMR1_OC1CE_Pos)
#define TIM1_CCMR1_OC1CE          TIM1_CCMR1_OC1CE_Msk

/*-------------------------------------------------------------------------
*      Capture/compare mode register 2 (TIM1_CCMR2)
*-----------------------------------------------------------------------*/

// Capture/compare 2 selection
#define TIM1_CCMR2_CC2S_Pos       (0U)
#define TIM1_CCMR2_CC2S_Msk       (0x3U << TIM1_CCMR2_CC2S_Pos)
#define TIM1_CCMR2_CC2S           TIM1_CCMR2_CC2S_Msk
#define TIM1_CCMR2_CC2S_0         (0x1U << TIM1_CCMR2_CC2S_Pos)
#define TIM1_CCMR2_CC2S_1         (0x2U << TIM1_CCMR2_CC2S_Pos)
// Output compare 2 fast enable
#define TIM1_CCMR2_OC2FE_Pos      (2U)
#define TIM1_CCMR2_OC2FE_Msk      (0x1U << TIM1_CCMR2_OC2FE_Pos)
#define TIM1_CCMR2_OC2FE          TIM1_CCMR2_OC2FE_Msk
// Output compare 2 preload enable
#define TIM1_CCMR2_OC2PE_Pos      (3U)
#define TIM1_CCMR2_OC2PE_Msk      (0x1U << TIM1_CCMR2_OC2PE_Pos)
#define TIM1_CCMR2_OC2PE          TIM1_CCMR2_OC2PE_Msk
// Output compare 2 mode
#define TIM1_CCMR2_OC2M_Pos       (4U)
#define TIM1_CCMR2_OC2M_Msk       (0x7U << TIM1_CCMR2_OC2M_Pos)
#define TIM1_CCMR2_OC2M           TIM1_CCMR2_OC2M_Msk
#define TIM1_CCMR2_OC2M_0         (0x1U << TIM1_CCMR2_OC2M_Pos)
#define TIM1_CCMR2_OC2M_1         (0x2U << TIM1_CCMR2_OC2M_Pos)
#define TIM1_CCMR2_OC2M_2         (0x4U << TIM1_CCMR2_OC2M_Pos)
// Output compare 2 clear enable
#define TIM1_CCMR2_OC2CE_Pos      (7U)
#define TIM1_CCMR2_OC2CE_Msk      (0x1U << TIM1_CCMR2_OC2CE_Pos)
#define TIM1_CCMR2_OC2CE          TIM1_CCMR2_OC2CE_Msk

/*-------------------------------------------------------------------------
*      Capture/compare mode register 3 (TIM1_CCMR3)
*-----------------------------------------------------------------------*/

// Capture/compare 3 selection
#define TIM1_CCMR3_CC3S_Pos       (0U)
#define TIM1_CCMR3_CC3S_Msk       (0x3U << TIM1_CCMR3_CC3S_Pos)
#define TIM1_CCMR3_CC3S           TIM1_CCMR3_CC3S_Msk
#define TIM1_CCMR3_CC3S_0         (0x1U << TIM1_CCMR3_CC3S_Pos)
#define TIM1_CCMR3_CC3S_1         (0x2U << TIM1_CCMR3_CC3S_Pos)
// Output compare 3 fast enable
#define TIM1_CCMR3_OC3FE_Pos      (2U)
#define TIM1_CCMR3_OC3FE_Msk      (0x1U << TIM1_CCMR3_OC3FE_Pos)
#define TIM1_CCMR3_OC3FE          TIM1_CCMR3_OC3FE_Msk
// Output compare 3 preload enable
#define TIM1_CCMR3_OC3PE_Pos      (3U)
#define TIM1_CCMR3_OC3PE_Msk      (0x1U << TIM1_CCMR3_OC3PE_Pos)
#define TIM1_CCMR3_OC3PE          TIM1_CCMR3_OC3PE_Msk
// Output compare 3 mode
#define TIM1_CCMR3_OC3M_Pos       (4U)
#define TIM1_CCMR3_OC3M_Msk       (0x7U << TIM1_CCMR3_OC3M_Pos)
#define TIM1_CCMR3_OC3M           TIM1_CCMR3_OC3M_Msk
#define TIM1_CCMR3_OC3M_0         (0x1U << TIM1_CCMR3_OC3M_Pos)
#define TIM1_CCMR3_OC3M_1         (0x2U << TIM1_CCMR3_OC3M_Pos)
#define TIM1_CCMR3_OC3M_2         (0x4U << TIM1_CCMR3_OC3M_Pos)
// Output compare 3 clear enable
#define TIM1_CCMR3_OC3CE_Pos      (7U)
#define TIM1_CCMR3_OC3CE_Msk      (0x1U << TIM1_CCMR3_OC3CE_Pos)
#define TIM1_CCMR3_OC3CE          TIM1_CCMR3_OC3CE_Msk

/*-------------------------------------------------------------------------
*      Capture/compare mode register 4 (TIM1_CCMR4)
*-----------------------------------------------------------------------*/

// Capture/compare 4 selection
#define TIM1_CCMR4_CC4S_Pos       (0U)
#define TIM1_CCMR4_CC4S_Msk       (0x3U << TIM1_CCMR4_CC4S_Pos)
#define TIM1_CCMR4_CC4S           TIM1_CCMR4_CC4S_Msk
#define TIM1_CCMR4_CC4S_0         (0x1U << TIM1_CCMR4_CC4S_Pos)
#define TIM1_CCMR4_CC4S_1         (0x2U << TIM1_CCMR4_CC4S_Pos)
// Output compare 4 fast enable
#define TIM1_CCMR4_OC4FE_Pos      (2U)
#define TIM1_CCMR4_OC4FE_Msk      (0x1U << TIM1_CCMR4_OC4FE_Pos)
#define TIM1_CCMR4_OC4FE          TIM1_CCMR4_OC4FE_Msk
// Output compare 4 preload enable
#define TIM1_CCMR4_OC4PE_Pos      (3U)
#define TIM1_CCMR4_OC4PE_Msk      (0x1U << TIM1_CCMR4_OC4PE_Pos)
#define TIM1_CCMR4_OC4PE          TIM1_CCMR4_OC4PE_Msk
// Output compare 4 mode
#define TIM1_CCMR4_OC4M_Pos       (4U)
#define TIM1_CCMR4_OC4M_Msk       (0x7U << TIM1_CCMR4_OC4M_Pos)
#define TIM1_CCMR4_OC4M           TIM1_CCMR4_OC4M_Msk
#define TIM1_CCMR4_OC4M_0         (0x1U << TIM1_CCMR4_OC4M_Pos)
#define TIM1_CCMR4_OC4M_1         (0x2U << TIM1_CCMR4_OC4M_Pos)
#define TIM1_CCMR4_OC4M_2         (0x4U << TIM1_CCMR4_OC4M_Pos)
// Output compare 4 clear enable
#define TIM1_CCMR4_OC4CE_Pos      (7U)
#define TIM1_CCMR4_OC4CE_Msk      (0x1U << TIM1_CCMR4_OC4CE_Pos)
#define TIM1_CCMR4_OC4CE          TIM1_CCMR4_OC4CE_Msk

/*-------------------------------------------------------------------------
*      Capture/compare enable register 1 (TIM1_CCER1)
*-----------------------------------------------------------------------*/

// Capture/compare 1 output enable
#define TIM1_CCER1_CC1E_Pos       (0U)
#define TIM1_CCER1_CC1E_Msk       (0x1U << TIM1_CCER1_CC1E_Pos)
#define TIM1_CCER1_CC1E           TIM1_CCER1_CC1E_Msk
// Capture/compare 1 output polarity
#define TIM1_CCER1_CC1P_Pos       (1U)
#define TIM1_CCER1_CC1P_Msk       (0x1U << TIM1_CCER1_CC1P_Pos)
#define TIM1_CCER1_CC1P           TIM1_CCER1_CC1P_Msk
// Capture/compare 1 complementary output enable
#define TIM1_CCER1_CC1NE_Pos      (2U)
#define TIM1_CCER1_CC1NE_Msk      (0x1U << TIM1_CCER1_CC1NE_Pos)
#define TIM1_CCER1_CC1NE          TIM1_CCER1_CC1NE_Msk
// Capture/compare 1 complementary output polarity
#define TIM1_CCER1_CC1NP_Pos      (3U)
#define TIM1_CCER1_CC1NP_Msk      (0x1U << TIM1_CCER1_CC1NP_Pos)
#define TIM1_CCER1_CC1NP          TIM1_CCER1_CC1NP_Msk
// Capture/compare 2 output enable
#define TIM1_CCER1_CC2E_Pos       (4U)
#define TIM1_CCER1_CC2E_Msk       (0x1U << TIM1_CCER1_CC2E_Pos)
#define TIM1_CCER1_CC2E           TIM1_CCER1_CC2E_Msk
// Capture/compare 2 output polarity
#define TIM1_CCER1_CC2P_Pos       (5U)
#define TIM1_CCER1_CC2P_Msk       (0x1U << TIM1_CCER1_CC2P_Pos)
#define TIM1_CCER1_CC2P           TIM1_CCER1_CC2P_Msk
// Capture/compare 2 complementary output enable
#define TIM1_CCER1_CC2NE_Pos      (6U)
#define TIM1_CCER1_CC2NE_Msk      (0x1U << TIM1_CCER1_CC2NE_Pos)
#define TIM1_CCER1_CC2NE          TIM1_CCER1_CC2NE_Msk
// Capture/compare 2 complementary output polarity
#define TIM1_CCER1_CC2NP_Pos      (7U)
#define TIM1_CCER1_CC2NP_Msk      (0x1U << TIM1_CCER1_CC2NP_Pos)
#define TIM1_CCER1_CC2NP          TIM1_CCER1_CC2NP_Msk

/*-------------------------------------------------------------------------
*      Capture/compare enable register 2 (TIM1_CCER2)
*-----------------------------------------------------------------------*/

// Capture/compare 3 output enable
#define TIM1_CCER2_CC3E_Pos       (0U)
#define TIM1_CCER2_CC3E_Msk       (0x1U << TIM1_CCER2_CC3E_Pos)
#define TIM1_CCER2_CC3E           TIM1_CCER2_CC3E_Msk
// Capture/compare 3 output polarity
#define TIM1_CCER2_CC3P_Pos       (1U)
#define TIM1_CCER2_CC3P_Msk       (0x1U << TIM1_CCER2_CC3P_Pos)
#define TIM1_CCER2_CC3P           TIM1_CCER2_CC3P_Msk
// Capture/compare 3 complementary output enable
#define TIM1_CCER2_CC3NE_Pos      (2U)
#define TIM1_CCER2_CC3NE_Msk      (0x1U << TIM1_CCER2_CC3NE_Pos)
#define TIM1_CCER2_CC3NE          TIM1_CCER2_CC3NE_Msk
// Capture/compare 3 complementary output polarity
#define TIM1_CCER2_CC3NP_Pos      (3U)
#define TIM1_CCER2_CC3NP_Msk      (0x1U << TIM1_CCER2_CC3NP_Pos)
#define TIM1_CCER2_CC3NP          TIM1_CCER2_CC3NP_Msk
// Capture/compare 4 output enable
#define TIM1_CCER2_CC4E_Pos       (4U)
#define TIM1_CCER2_CC4E_Msk       (0x1U << TIM1_CCER2_CC4E_Pos)
#define TIM1_CCER2_CC4E           TIM1_CCER2_CC4E_Msk
// Capture/compare 4 output polarity
#define TIM1_CCER2_CC4P_Pos       (5U)
#define TIM1_CCER2_CC4P_Msk       (0x1U << TIM1_CCER2_CC4P_Pos)
#define TIM1_CCER2_CC4P           TIM1_CCER2_CC4P_Msk

/*-------------------------------------------------------------------------
*      Break register (TIM1_BKR)
*-----------------------------------------------------------------------*/

// Lock configuration
#define TIM1_BKR_LOCK_Pos         (0U)
#define TIM1_BKR_LOCK_Msk         (0x3U << TIM1_BKR_LOCK_Pos)
#define TIM1_BKR_LOCK             TIM1_BKR_LOCK_Msk
#define TIM1_BKR_LOCK_0           (0x1U << TIM1_BKR_LOCK_Pos)
#define TIM1_BKR_LOCK_1           (0x2U << TIM1_BKR_LOCK_Pos)
// Off state selection for idle mode
#define TIM1_BKR_OSSI_Pos         (2U)
#define TIM1_BKR_OSSI_Msk         (0x1U << TIM1_BKR_OSSI_Pos)
#define TIM1_BKR_OSSI             TIM1_BKR_OSSI_Msk
// Off state selection for Run mode
#define TIM1_BKR_OSSR_Pos         (3U)
#define TIM1_BKR_OSSR_Msk         (0x1U << TIM1_BKR_OSSR_Pos)
#define TIM1_BKR_OSSR             TIM1_BKR_OSSR_Msk
// Break enable
#define TIM1_BKR_BKE_Pos          (4U)
#define TIM1_BKR_BKE_Msk          (0x1U << TIM1_BKR_BKE_Pos)
#define TIM1_BKR_BKE              TIM1_BKR_BKE_Msk
// Break polarity
#define TIM1_BKR_BKP_Pos          (5U)
#define TIM1_BKR_BKP_Msk          (0x1U << TIM1_BKR_BKP_Pos)
#define TIM1_BKR_BKP              TIM1_BKR_BKP_Msk
// Automatic output enable
#define TIM1_BKR_AOE_Pos          (6U)
#define TIM1_BKR_AOE_Msk          (0x1U << TIM1_BKR_AOE_Pos)
#define TIM1_BKR_AOE              TIM1_BKR_AOE_Msk
// Main output enable
#define TIM1_BKR_MOE_Pos          (7U)
#define TIM1_BKR_MOE_Msk          (0x1U << TIM1_BKR_MOE_Pos)
#define TIM1_BKR_MOE              TIM1_BKR_MOE_Msk

/*-------------------------------------------------------------------------
*      Deadtime register (TIM1_DTR)
*-----------------------------------------------------------------------*/

// Deadtime generator set-up
#define TIM1_DTR_DTG_Pos          (0U)
#define TIM1_DTR_DTG_Msk          (0xFFU << TIM1_DTR_DTG_Pos)
#define TIM1_DTR_DTG              TIM1_DTR_DTG_Msk

/*-------------------------------------------------------------------------
*      Output idle state register (TIM1_OISR)
*-----------------------------------------------------------------------*/

// Output idle state 1 (OC1 output)
#define TIM1_OISR_OIS1_Pos          (0U)
#define TIM1_OISR_OIS1_Msk          (0xFFU << TIM1_OISR_OIS1_Pos)
#define TIM1_OISR_OIS1              TIM1_OISR_OIS1_Msk
// Output idle state 1 (OC1N output).
#define TIM1_OISR_OIS1N_Pos          (1U)
#define TIM1_OISR_OIS1N_Msk          (0xFFU << TIM1_OISR_OIS1N_Pos)
#define TIM1_OISR_OIS1N              TIM1_OISR_OIS1N_Msk
// Output idle state 2 (OC2 output)
#define TIM1_OISR_OIS2_Pos          (2U)
#define TIM1_OISR_OIS2_Msk          (0xFFU << TIM1_OISR_OIS2_Pos)
#define TIM1_OISR_OIS2              TIM1_OISR_OIS2_Msk
// Output idle state 2 (OC2N output)
#define TIM1_OISR_OIS2N_Pos          (3U)
#define TIM1_OISR_OIS2N_Msk          (0xFFU << TIM1_OISR_OIS2N_Pos)
#define TIM1_OISR_OIS2N              TIM1_OISR_OIS2N_Msk
// Output idle state 3 (OC3 output)
#define TIM1_OISR_OIS3_Pos          (4U)
#define TIM1_OISR_OIS3_Msk          (0xFFU << TIM1_OISR_OIS3_Pos)
#define TIM1_OISR_OIS3              TIM1_OISR_OIS3_Msk
// Output idle state 3 (OC3N output)
#define TIM1_OISR_OIS3N_Pos          (5U)
#define TIM1_OISR_OIS3N_Msk          (0xFFU << TIM1_OISR_OIS3N_Pos)
#define TIM1_OISR_OIS3N              TIM1_OISR_OIS3N_Msk
// Output idle state 4 (OC4 output)
#define TIM1_OISR_OIS4_Pos          (6U)
#define TIM1_OISR_OIS4_Msk          (0xFFU << TIM1_OISR_OIS4_Pos)
#define TIM1_OISR_OIS4              TIM1_OISR_OIS4_Msk

/*======================================================================
*      16-bit general purpose timer (TIM2)
*=======================================================================*/
typedef struct
{
	volatile unsigned char CR1;
	volatile unsigned short : 16;
	volatile unsigned char IER;
	volatile unsigned char SR1;
	volatile unsigned char SR2;
	volatile unsigned char EGR;
	volatile unsigned char CCMR1;
	volatile unsigned char CCMR2;
	volatile unsigned char CCMR3;
	volatile unsigned char CCER1;
	volatile unsigned char CCER2;
	volatile unsigned char CNTRH;
	volatile unsigned char CNTRL;
	volatile unsigned char PSCR;
	volatile unsigned char ARRH;
	volatile unsigned char ARRL;
	volatile unsigned char CCR1H;
	volatile unsigned char CCR1L;
	volatile unsigned char CCR2H;
	volatile unsigned char CCR2L;
	volatile unsigned char CCR3H;
	volatile unsigned char CCR3L;
} Tim2Typedef;

#define TIM2_BASE                (0x005300)
#define TIM2                     ((Tim2Typedef *) TIM2_BASE)

/*-------------------------------------------------------------------------
*      Control register 1 (TIM2_CR1)
*-----------------------------------------------------------------------*/

// Counter enable
#define TIM2_CR1_CEN_Pos          (0U)
#define TIM2_CR1_CEN_Msk          (0x1U << TIM2_CR1_CEN_Pos)
#define TIM2_CR1_CEN              TIM2_CR1_CEN_Msk
// Update disable
#define TIM2_CR1_UDIS_Pos         (1U)
#define TIM2_CR1_UDIS_Msk         (0x1U << TIM2_CR1_UDIS_Pos)
#define TIM2_CR1_UDIS             TIM2_CR1_UDIS_Msk
// Update request source
#define TIM2_CR1_URS_Pos          (2U)
#define TIM2_CR1_URS_Msk          (0x1U << TIM2_CR1_URS_Pos)
#define TIM2_CR1_URS              TIM2_CR1_URS_Msk
// One-pulse mode
#define TIM2_CR1_OPM_Pos          (3U)
#define TIM2_CR1_OPM_Msk          (0x1U << TIM2_CR1_OPM_Pos)
#define TIM2_CR1_OPM              TIM2_CR1_OPM_Msk
// Direction
#define TIM2_CR1_DIR_Pos          (4U)
#define TIM2_CR1_DIR_Msk          (0x1U << TIM2_CR1_DIR_Pos)
#define TIM2_CR1_DIR              TIM2_CR1_DIR_Msk
// Auto-reload preload enable
#define TIM2_CR1_ARPE_Pos         (7U)
#define TIM2_CR1_ARPE_Msk         (0x1U << TIM2_CR1_ARPE_Pos)
#define TIM2_CR1_ARPE             TIM2_CR1_ARPE_Msk

/*-------------------------------------------------------------------------
*      Interrupt enable register (TIM2_IER)
*-----------------------------------------------------------------------*/

// Update interrupt enable
#define TIM2_IER_UIE_Pos          (0U)
#define TIM2_IER_UIE_Msk          (0x1U << TIM2_IER_UIE_Pos)
#define TIM2_IER_UIE              TIM2_IER_UIE_Msk
// Capture/compare 1 interrupt enable
#define TIM2_IER_CC1IE_Pos        (1U)
#define TIM2_IER_CC1IE_Msk        (0x1U << TIM2_IER_CC1IE_Pos)
#define TIM2_IER_CC1IE            TIM2_IER_CC1IE_Msk
// Capture/compare 2 interrupt enable
#define TIM2_IER_CC2IE_Pos        (2U)
#define TIM2_IER_CC2IE_Msk        (0x1U << TIM2_IER_CC2IE_Pos)
#define TIM2_IER_CC2IE            TIM2_IER_CC2IE_Msk
// Capture/compare 3 interrupt enable
#define TIM2_IER_CC3IE_Pos        (3U)
#define TIM2_IER_CC3IE_Msk        (0x1U << TIM2_IER_CC3IE_Pos)
#define TIM2_IER_CC3IE            TIM2_IER_CC3IE_Msk
// Trigger interrupt enable
#define TIM2_IER_TIE_Pos          (6U)
#define TIM2_IER_TIE_Msk          (0x1U << TIM2_IER_TIE_Pos)
#define TIM2_IER_TIE              TIM2_IER_TIE_Msk

/*-------------------------------------------------------------------------
*      Status register 1 (TIM2_SR1)
*-----------------------------------------------------------------------*/

// Update interrupt flag
#define TIM2_SR2_CC1OF_Pos        (1U)
#define TIM2_SR1_UIF_Msk          (0x1U << TIM2_SR1_UIF_Pos)
#define TIM2_SR1_UIF              TIM2_SR1_UIF_Msk
// Capture/compare 1 interrupt flag
#define TIM2_SR1_CC1IF_Pos        (1U)
#define TIM2_SR1_CC1IF_Msk        (0x1U << TIM2_SR1_CC1IF_Pos)
#define TIM2_SR1_CC1IF            TIM2_SR1_CC1IF_Msk
// Capture/compare 2 interrupt flag
#define TIM2_SR1_CC2IF_Pos        (2U)
#define TIM2_SR1_CC2IF_Msk        (0x1U << TIM2_SR1_CC2IF_Pos)
#define TIM2_SR1_CC2IF            TIM2_SR1_CC2IF_Msk
// Capture/compare 3 interrupt flag
#define TIM2_SR1_CC3IF_Pos        (3U)
#define TIM2_SR1_CC3IF_Msk        (0x1U << TIM2_SR1_CC3IF_Pos)
#define TIM2_SR1_CC3IF            TIM2_SR1_CC3IF_Msk
// Trigger interrupt flag
#define TIM2_SR1_TIF_Pos          (6U)
#define TIM2_SR1_TIF_Msk          (0x1U << TIM2_SR1_TIF_Pos)
#define TIM2_SR1_TIF              TIM2_SR1_TIF_Msk

/*-------------------------------------------------------------------------
*      Status register 2 (TIM2_SR2)
*-----------------------------------------------------------------------*/

// Capture/compare 1 overcapture flag
#define TIM2_SR2_CC1OF_Pos        (1U)
#define TIM2_SR2_CC1OF_Msk        (0x1U << TIM2_SR2_CC1OF_Pos)
#define TIM2_SR2_CC1OF            TIM2_SR2_CC1OF_Msk
// Capture/compare 2 overcapture flag
#define TIM2_SR2_CC2OF_Pos        (2U)
#define TIM2_SR2_CC2OF_Msk        (0x1U << TIM2_SR2_CC2OF_Pos)
#define TIM2_SR2_CC2OF            TIM2_SR2_CC2OF_Msk
// Capture/compare 3 overcapture flag
#define TIM2_SR2_CC3OF_Pos        (3U)
#define TIM2_SR2_CC3OF_Msk        (0x1U << TIM2_SR2_CC3OF_Pos)
#define TIM2_SR2_CC3OF            TIM2_SR2_CC3OF_Msk

/*-------------------------------------------------------------------------
*      Event generation register (TIM2_EGR)
*-----------------------------------------------------------------------*/

// Update generation
#define TIM2_EGR_UG_Pos           (0U)
#define TIM2_EGR_UG_Msk           (0x1U << TIM2_EGR_UG_Pos)
#define TIM2_EGR_UG               TIM2_EGR_UG_Msk
// Capture/compare 1 generation
#define TIM2_EGR_CC1G_Pos         (1U)
#define TIM2_EGR_CC1G_Msk         (0x1U << TIM2_EGR_CC1G_Pos)
#define TIM2_EGR_CC1G             TIM2_EGR_CC1G_Msk
// Capture/compare 2 generation
#define TIM2_EGR_CC2G_Pos         (2U)
#define TIM2_EGR_CC2G_Msk         (0x1U << TIM2_EGR_CC2G_Pos)
#define TIM2_EGR_CC2G             TIM2_EGR_CC2G_Msk
// Capture/compare 3 generation
#define TIM2_EGR_CC3G_Pos         (3U)
#define TIM2_EGR_CC3G_Msk         (0x1U << TIM2_EGR_CC3G_Pos)
#define TIM2_EGR_CC3G             TIM2_EGR_CC3G_Msk
// Trigger generation
#define TIM2_EGR_TG_Pos           (6U)
#define TIM2_EGR_TG_Msk           (0x1U << TIM2_EGR_TG_Pos)
#define TIM2_EGR_TG               TIM2_EGR_TG_Msk

/*-------------------------------------------------------------------------
*      Capture/compare mode register 1 (TIM2_CCMR1)
*-----------------------------------------------------------------------*/

// Capture/compare 1 selection
#define TIM2_CCMR1_CC1S_Pos       (0U)
#define TIM2_CCMR1_CC1S_Msk       (0x3U << TIM2_CCMR1_CC1S_Pos)
#define TIM2_CCMR1_CC1S           TIM2_CCMR1_CC1S_Msk
#define TIM2_CCMR1_CC1S_0         (0x1U << TIM2_CCMR1_CC1S_Pos)
#define TIM2_CCMR1_CC1S_1         (0x2U << TIM2_CCMR1_CC1S_Pos)
// Output compare 1 preload enable
#define TIM2_CCMR1_OC1PE_Pos      (3U)
#define TIM2_CCMR1_OC1PE_Msk      (0x1U << TIM2_CCMR1_OC1PE_Pos)
#define TIM2_CCMR1_OC1PE          TIM2_CCMR1_OC1PE_Msk
// Output compare 1 mode
#define TIM2_CCMR1_OC1M_Pos       (4U)
#define TIM2_CCMR1_OC1M_Msk       (0x7U << TIM2_CCMR1_OC1M_Pos)
#define TIM2_CCMR1_OC1M           TIM2_CCMR1_OC1M_Msk
#define TIM2_CCMR1_OC1M_0         (0x1U << TIM2_CCMR1_OC1M_Pos)
#define TIM2_CCMR1_OC1M_1         (0x2U << TIM2_CCMR1_OC1M_Pos)
#define TIM2_CCMR1_OC1M_2         (0x4U << TIM2_CCMR1_OC1M_Pos)

/*-------------------------------------------------------------------------
*      Capture/compare mode register 2 (TIM2_CCMR2)
*-----------------------------------------------------------------------*/

// Capture/compare 2 selection
#define TIM2_CCMR2_CC2S_Pos       (0U)
#define TIM2_CCMR2_CC2S_Msk       (0x3U << TIM2_CCMR2_CC2S_Pos)
#define TIM2_CCMR2_CC2S           TIM2_CCMR2_CC2S_Msk
#define TIM2_CCMR2_CC2S_0         (0x1U << TIM2_CCMR2_CC2S_Pos)
#define TIM2_CCMR2_CC2S_1         (0x2U << TIM2_CCMR2_CC2S_Pos)
// Output compare 2 preload enable
#define TIM2_CCMR2_OC2PE_Pos      (3U)
#define TIM2_CCMR2_OC2PE_Msk      (0x1U << TIM2_CCMR2_OC2PE_Pos)
#define TIM2_CCMR2_OC2PE          TIM2_CCMR2_OC2PE_Msk
// Output compare 2 mode
#define TIM2_CCMR2_OC2M_Pos       (4U)
#define TIM2_CCMR2_OC2M_Msk       (0x7U << TIM2_CCMR2_OC2M_Pos)
#define TIM2_CCMR2_OC2M           TIM2_CCMR2_OC2M_Msk
#define TIM2_CCMR2_OC2M_0         (0x1U << TIM2_CCMR2_OC2M_Pos)
#define TIM2_CCMR2_OC2M_1         (0x2U << TIM2_CCMR2_OC2M_Pos)
#define TIM2_CCMR2_OC2M_2         (0x4U << TIM2_CCMR2_OC2M_Pos)

/*-------------------------------------------------------------------------
*      Capture/compare mode register 3 (TIM2_CCMR3)
*-----------------------------------------------------------------------*/

// Capture/compare 3 selection
#define TIM2_CCMR3_CC3S_Pos       (0U)
#define TIM2_CCMR3_CC3S_Msk       (0x3U << TIM2_CCMR3_CC3S_Pos)
#define TIM2_CCMR3_CC3S           TIM2_CCMR3_CC3S_Msk
#define TIM2_CCMR3_CC3S_0         (0x1U << TIM2_CCMR3_CC3S_Pos)
#define TIM2_CCMR3_CC3S_1         (0x2U << TIM2_CCMR3_CC3S_Pos)
// Output compare 3 preload enable
#define TIM2_CCMR3_OC3PE_Pos      (3U)
#define TIM2_CCMR3_OC3PE_Msk      (0x1U << TIM2_CCMR3_OC3PE_Pos)
#define TIM2_CCMR3_OC3PE          TIM2_CCMR3_OC3PE_Msk
// Output compare 3 mode
#define TIM2_CCMR3_OC3M_Pos       (4U)
#define TIM2_CCMR3_OC3M_Msk       (0x7U << TIM2_CCMR3_OC3M_Pos)
#define TIM2_CCMR3_OC3M           TIM2_CCMR3_OC3M_Msk
#define TIM2_CCMR3_OC3M_0         (0x1U << TIM2_CCMR3_OC3M_Pos)
#define TIM2_CCMR3_OC3M_1         (0x2U << TIM2_CCMR3_OC3M_Pos)
#define TIM2_CCMR3_OC3M_2         (0x4U << TIM2_CCMR3_OC3M_Pos)

/*-------------------------------------------------------------------------
*      Capture/compare enable register 1 (TIM2_CCER1)
*-----------------------------------------------------------------------*/

// Capture/compare 1 output enable
#define TIM2_CCER1_CC1E_Pos       (0U)
#define TIM2_CCER1_CC1E_Msk       (0x1U << TIM2_CCER1_CC1E_Pos)
#define TIM2_CCER1_CC1E           TIM2_CCER1_CC1E_Msk
// Capture/compare 1 output polarity
#define TIM2_CCER1_CC1P_Pos       (1U)
#define TIM2_CCER1_CC1P_Msk       (0x1U << TIM2_CCER1_CC1P_Pos)
#define TIM2_CCER1_CC1P           TIM2_CCER1_CC1P_Msk
// Capture/compare 2 output enable
#define TIM2_CCER1_CC2E_Pos       (4U)
#define TIM2_CCER1_CC2E_Msk       (0x1U << TIM2_CCER1_CC2E_Pos)
#define TIM2_CCER1_CC2E           TIM2_CCER1_CC2E_Msk
// Capture/compare 2 output polarity
#define TIM2_CCER1_CC2P_Pos       (5U)
#define TIM2_CCER1_CC2P_Msk       (0x1U << TIM2_CCER1_CC2P_Pos)
#define TIM2_CCER1_CC2P           TIM2_CCER1_CC2P_Msk

/*-------------------------------------------------------------------------
*      Capture/compare enable register 2 (TIM2_CCER2)
*-----------------------------------------------------------------------*/

// Capture/compare 3 output enable
#define TIM2_CCER2_CC3E_Pos       (0U)
#define TIM2_CCER2_CC3E_Msk       (0x1U << TIM2_CCER2_CC3E_Pos)
#define TIM2_CCER2_CC3E           TIM2_CCER2_CC3E_Msk
// Capture/compare 3 output polarity
#define TIM2_CCER2_CC3P_Pos       (1U)
#define TIM2_CCER2_CC3P_Msk       (0x1U << TIM2_CCER2_CC3P_Pos)
#define TIM2_CCER2_CC3P           TIM2_CCER2_CC3P_Msk

/*======================================================================
*      8-bit basic timer (TIM4)
*=======================================================================*/
typedef struct
{
	volatile unsigned char CR1;
	volatile unsigned short : 16;
	volatile unsigned char IER;
	volatile unsigned char SR;
	volatile unsigned char EGR;
	volatile unsigned char CNTR;
	volatile unsigned char PSCR;
	volatile unsigned char ARR;
} Tim4Typedef;

#define TIM4_BASE                (0x005340)
#define TIM4                     ((Tim4Typedef *) TIM4_BASE)

/*-------------------------------------------------------------------------
*      Control register 1 (TIM4_CR1)
*-----------------------------------------------------------------------*/

// Counter enable
#define TIM4_CR1_CEN_Pos         (0U)
#define TIM4_CR1_CEN_Msk         (0x1U << TIM4_CR1_CEN_Pos)
#define TIM4_CR1_CEN             (TIM4_CR1_CEN_Msk)
// Update disable
#define TIM4_CR1_UDIS_Pos        (1U)
#define TIM4_CR1_UDIS_Msk        (0x1U << TIM4_CR1_UDIS_Pos)
#define TIM4_CR1_UDIS            (TIM4_CR1_UDIS_Msk)
// Update request source
#define TIM4_CR1_URS_Pos         (2U)
#define TIM4_CR1_URS_Msk         (0x1U << TIM4_CR1_URS_Pos)
#define TIM4_CR1_URS             (TIM4_CR1_URS_Msk)
// One-pulse mode
#define TIM4_CR1_OPM_Pos         (3U)
#define TIM4_CR1_OPM_Msk         (0x1U << TIM4_CR1_OPM_Pos)
#define TIM4_CR1_OPM             (TIM4_CR1_OPM_Msk)
// Auto-reload preload enable
#define TIM4_CR1_ARPE_Pos        (7U)
#define TIM4_CR1_ARPE_Msk        (0x1U << TIM4_CR1_ARPE_Pos)
#define TIM4_CR1_ARPE            (TIM4_CR1_ARPE_Msk)

/*-------------------------------------------------------------------------
*      Interrupt enable register (TIM4_IER)
*-----------------------------------------------------------------------*/

// Reserved, must be kept cleared
#define TIM4_IER_UIE_Pos         (0U)
#define TIM4_IER_UIE_Msk         (0x1U << TIM4_IER_UIE_Pos)
#define TIM4_IER_UIE             (TIM4_IER_UIE_Msk)
// Trigger interrupt enable
#define TIM4_IER_TIE_Pos         (6U)
#define TIM4_IER_TIE_Msk         (0x1U << TIM4_IER_TIE_Pos)
#define TIM4_IER_TIE             (TIM4_IER_TIE_Msk)

/*-------------------------------------------------------------------------
*      Status register 1 (TIM4_SR)
*-----------------------------------------------------------------------*/

// Update interrupt flag
#define TIM4_SR_UIF_Pos         (0U)
#define TIM4_SR_UIF_Msk         (0x1U << TIM4_SR_UIF_Pos)
#define TIM4_SR_UIF             (TIM4_SR_UIF_Msk)
// Trigger interrupt flag
#define TIM4_SR_TIF_Pos         (6U)
#define TIM4_SR_TIF_Msk         (0x1U << TIM4_SR_TIF_Pos)
#define TIM4_SR_TIF             (TIM4_SR_TIF_Msk)

/*-------------------------------------------------------------------------
*      Event generation register (TIM4_EGR)
*-----------------------------------------------------------------------*/

// Update generation
#define TIM4_EGR_UG_Pos         (0U)
#define TIM4_EGR_UG_Msk         (0x1U << TIM4_EGR_UG_Pos)
#define TIM4_EGR_UG             (TIM4_EGR_UG_Msk)
// Trigger generation
#define TIM4_EGR_TG_Pos         (6U)
#define TIM4_EGR_TG_Msk         (0x1U << TIM4_EGR_TG_Pos)
#define TIM4_EGR_TG             (TIM4_EGR_TG_Msk)

/*-------------------------------------------------------------------------
*      Prescaler register (TIM4_PSCR)
*-----------------------------------------------------------------------*/

// Prescaler value
#define TIM4_PSCR_PSC_Pos         (0U)
#define TIM4_PSCR_PSC_Msk         (0x7U << TIM4_PSCR_PSC_Pos)
#define TIM4_PSCR_PSC             TIM4_PSCR_PSC_Msk
#define TIM4_PSCR_PSC_0           (0x1U << TIM4_PSCR_PSC_Pos)
#define TIM4_PSCR_PSC_1           (0x2U << TIM4_PSCR_PSC_Pos)
#define TIM4_PSCR_PSC_2           (0x4U << TIM4_PSCR_PSC_Pos)

/*======================================================================
*      Clock control (CLK)
*=======================================================================*/
typedef struct
{
	volatile unsigned char ICKR;
	volatile unsigned char ECKR;
	volatile unsigned char : 8;
	volatile unsigned char CMSR;
	volatile unsigned char SWR;
	volatile unsigned char SWCR;
	volatile unsigned char CKDIVR;
	volatile unsigned char PCKENR1;
	volatile unsigned char CSSR;
	volatile unsigned char CCOR;
	volatile unsigned char ARR;
	volatile unsigned char PCKENR2;
	volatile unsigned char : 8;
	volatile unsigned char HSITRIMR;
	volatile unsigned char SWIMCCR;
} ClkTypedef;

#define CLK_BASE                (0x0050C0)
#define CLK                     ((ClkTypedef *) CLK_BASE)

/*-------------------------------------------------------------------------
*      Internal clock register (CLK_ICKR)
*-----------------------------------------------------------------------*/

// High speed internal RC oscillator enable
#define CLK_ICKR_HSIEN_Pos         (0U)
#define CLK_ICKR_HSIEN_Msk         (0x1U << CLK_ICKR_HSIEN_Pos)
#define CLK_ICKR_HSIEN             CLK_ICKR_HSIEN_Msk
// High speed internal oscillator ready
#define CLK_ICKR_HSIRDY_Pos        (1U)
#define CLK_ICKR_HSIRDY_Msk        (0x1U << CLK_ICKR_HSIRDY_Pos)
#define CLK_ICKR_HSIRDY            CLK_ICKR_HSIRDY_Msk
// Fast wakeup from Halt/Active-halt modes
#define CLK_ICKR_FHW_Pos           (2U)
#define CLK_ICKR_FHW_Msk           (0x1U << CLK_ICKR_FHW_Pos)
#define CLK_ICKR_FHW               CLK_ICKR_FHW_Msk
// Low speed internal RC oscillator enable
#define CLK_ICKR_LSIEN_Pos         (3U)
#define CLK_ICKR_LSIEN_Msk         (0x1U << CLK_ICKR_LSIEN_Pos)
#define CLK_ICKR_LSIEN             CLK_ICKR_LSIEN_Msk
// Low speed internal oscillator ready
#define CLK_ICKR_LSIRDY_Pos        (4U)
#define CLK_ICKR_LSIRDY_Msk        (0x1U << CLK_ICKR_LSIRDY_Pos)
#define CLK_ICKR_LSIRDY            CLK_ICKR_LSIRDY_Msk
// Regulator power off in Active-halt mode
#define CLK_ICKR_REGAH_Pos         (5U)
#define CLK_ICKR_REGAH_Msk         (0x1U << CLK_ICKR_REGAH_Pos)
#define CLK_ICKR_REGAH             CLK_ICKR_REGAH_Msk

/*-------------------------------------------------------------------------
*      External clock register (CLK_ECKR)
*-----------------------------------------------------------------------*/

// High speed external crystal oscillator enable
#define CLK_ECKR_HSEEN_Pos         (0U)
#define CLK_ECKR_HSEEN_Msk         (0x1U << CLK_ECKR_HSEEN_Pos)
#define CLK_ECKR_HSEEN             CLK_ECKR_HSEEN_Msk
// High speed external crystal oscillator ready
#define CLK_ECKR_HSERDY_Pos        (1U)
#define CLK_ECKR_HSERDY_Msk        (0x1U << CLK_ECKR_HSERDY_Pos)
#define CLK_ECKR_HSERDY            CLK_ECKR_HSERDY_Msk

/*-------------------------------------------------------------------------
*      Clock master switch register (CLK_SWR)
*-----------------------------------------------------------------------*/

// HSI selected as master clock source (reset value)
#define CLK_SWR_HSI             0xE1
// LSI selected as master clock source (only if LSI_EN option bit is set)
#define CLK_SWR_LSI             0xD2
// HSE selected as master clock source
#define CLK_SWR_HSE             0xB4

/*-------------------------------------------------------------------------
*      Switch control register (CLK_SWCR)
*-----------------------------------------------------------------------*/

// Switch busy
#define CLK_SWCR_SWBSY_Pos        (0U)
#define CLK_SWCR_SWBSY_Msk        (0x1U << CLK_SWCR_SWBSY_Pos)
#define CLK_SWCR_SWBSY            CLK_SWCR_SWBSY_Msk
// Switch start/stop
#define CLK_SWCR_SWEN_Pos         (1U)
#define CLK_SWCR_SWEN_Msk         (0x1U << CLK_SWCR_SWEN_Pos)
#define CLK_SWCR_SWEN             CLK_SWCR_SWEN_Msk
// Clock switch interrupt enable
#define CLK_SWCR_SWIEN_Pos        (2U)
#define CLK_SWCR_SWIEN_Msk        (0x1U << CLK_SWCR_SWIEN_Pos)
#define CLK_SWCR_SWIEN            CLK_SWCR_SWIEN_Msk
// Clock switch interrupt flag
#define CLK_SWCR_SWIF_Pos         (3U)
#define CLK_SWCR_SWIF_Msk         (0x1U << CLK_SWCR_SWIF_Pos)
#define CLK_SWCR_SWIF             CLK_SWCR_SWIF_Msk

/*-------------------------------------------------------------------------
*      Clock divider register (CLK_CKDIVR)
*-----------------------------------------------------------------------*/

// CPU clock prescaler
#define CLK_SWCR_CPUDIV_Pos           (0U)
#define CLK_SWCR_CPUDIV_Msk           (0x7U << CLK_SWCR_CPUDIV_Pos)
#define CLK_SWCR_CPUDIV               CLK_SWCR_CPUDIV_Msk
#define CLK_SWCR_CPUDIV_0             (0x1U << CLK_SWCR_CPUDIV_Pos)
#define CLK_SWCR_CPUDIV_1             (0x2U << CLK_SWCR_CPUDIV_Pos)
#define CLK_SWCR_CPUDIV_2             (0x4U << CLK_SWCR_CPUDIV_Pos)
// High speed internal clock prescaler
#define CLK_SWCR_HSIDIV_Pos           (3U)
#define CLK_SWCR_HSIDIV_Msk           (0x3U << CLK_SWCR_HSIDIV_Pos)
#define CLK_SWCR_HSIDIV               CLK_SWCR_HSIDIV_Msk
#define CLK_SWCR_HSIDIV_0             (0x1U << CLK_SWCR_HSIDIV_Pos)
#define CLK_SWCR_HSIDIV_1             (0x2U << CLK_SWCR_HSIDIV_Pos)

/*-------------------------------------------------------------------------
*      Peripheral clock gating register 1 (CLK_PCKENR1)
*-----------------------------------------------------------------------*/

// Enable I2C clock
#define CLK_PCKENR1_I2C_Pos           (0U)
#define CLK_PCKENR1_I2C_Msk           (0x1U << CLK_PCKENR1_I2C_Pos)
#define CLK_PCKENR1_I2C               CLK_PCKENR1_I2C_Msk
// Enable SPI clock
#define CLK_PCKENR1_SPI_Pos           (1U)
#define CLK_PCKENR1_SPI_Msk           (0x1U << CLK_PCKENR1_SPI_Pos)
#define CLK_PCKENR1_SPI               CLK_PCKENR1_SPI_Msk
// Enable UART1 clock
#define CLK_PCKENR1_UART1_Pos         (3U)
#define CLK_PCKENR1_UART1_Msk         (0x1U << CLK_PCKENR1_UART1_Pos)
#define CLK_PCKENR1_UART1             CLK_PCKENR1_UART1_Msk
// Enable TIM4 clock
#define CLK_PCKENR1_TIM4_Pos          (4U)
#define CLK_PCKENR1_TIM4_Msk          (0x1U << CLK_PCKENR1_TIM4_Pos)
#define CLK_PCKENR1_TIM4              CLK_PCKENR1_TIM4_Msk
// Enable TIM2 clock
#define CLK_PCKENR1_TIM2_Pos          (5U)
#define CLK_PCKENR1_TIM2_Msk          (0x1U << CLK_PCKENR1_TIM2_Pos)
#define CLK_PCKENR1_TIM2              CLK_PCKENR1_TIM2_Msk
// Enable TIM1 clock
#define CLK_PCKENR1_TIM1_Pos          (7U)
#define CLK_PCKENR1_TIM1_Msk          (0x1U << CLK_PCKENR1_TIM1_Pos)
#define CLK_PCKENR1_TIM1              CLK_PCKENR1_TIM1_Msk

/*-------------------------------------------------------------------------
*      Clock security system register (CLK_CSSR)
*-----------------------------------------------------------------------*/

// Clock security system enable
#define CLK_CSSR_CSSEN_Pos            (0U)
#define CLK_CSSR_CSSEN_Msk            (0x1U << CLK_CSSR_CSSEN_Pos)
#define CLK_CSSR_CSSEN                CLK_CSSR_CSSEN_Msk
// Auxiliary oscillator connected to master clock
#define CLK_CSSR_AUX_Pos              (1U)
#define CLK_CSSR_AUX_Msk              (0x1U << CLK_CSSR_AUX_Pos)
#define CLK_CSSR_AUX                  CLK_CSSR_AUX_Msk
// Clock security system detection interrupt enable
#define CLK_CSSR_CSSDIE_Pos           (2U)
#define CLK_CSSR_CSSDIE_Msk           (0x1U << CLK_CSSR_CSSDIE_Pos)
#define CLK_CSSR_CSSDIE               CLK_CSSR_CSSDIE_Msk
// Clock security system detection
#define CLK_CSSR_CSSD_Pos             (3U)
#define CLK_CSSR_CSSD_Msk             (0x1U << CLK_CSSR_CSSD_Pos)
#define CLK_CSSR_CSSD                 CLK_CSSR_CSSD_Msk

/*-------------------------------------------------------------------------
*      Configurable clock output register (CLK_CCOR)
*-----------------------------------------------------------------------*/

// Configurable clock output enable
#define CLK_CCOR_CCOEN_Pos            (0U)
#define CLK_CCOR_CCOEN_Msk            (0x1U << CLK_CCOR_CCOEN_Pos)
#define CLK_CCOR_CCOEN                CLK_CCOR_CCOEN_Msk
// Configurable clock output selection.
#define CLK_CCOR_CCOSEL_Pos           (1U)
#define CLK_CCOR_CCOSEL_Msk           (0xFU << CLK_CCOR_CCOSEL_Pos)
#define CLK_CCOR_CCOSEL               CLK_CCOR_CCOSEL_Msk
#define CLK_CCOR_CCOSEL_0             (0x1U << CLK_CCOR_CCOSEL_Pos)
#define CLK_CCOR_CCOSEL_1             (0x2U << CLK_CCOR_CCOSEL_Pos)
#define CLK_CCOR_CCOSEL_2             (0x4U << CLK_CCOR_CCOSEL_Pos)
#define CLK_CCOR_CCOSEL_3             (0x8U << CLK_CCOR_CCOSEL_Pos)
// Configurable clock output ready
#define CLK_CCOR_CCORDY_Pos           (5U)
#define CLK_CCOR_CCORDY_Msk           (0x1U << CLK_CCOR_CCORDY_Pos)
#define CLK_CCOR_CCORDY               CLK_CCOR_CCORDY_Msk
// Configurable clock output busy
#define CLK_CCOR_CCOBSY_Pos           (6U)
#define CLK_CCOR_CCOBSY_Msk           (0x1U << CLK_CCOR_CCOBSY_Pos)
#define CLK_CCOR_CCOBSY               CLK_CCOR_CCOBSY_Msk

/*-------------------------------------------------------------------------
*      Peripheral clock gating register 2 (CLK_PCKENR2)
*-----------------------------------------------------------------------*/

// Enable AWU clock
#define CLK_PCKENR2_AWU_Pos           (2U)
#define CLK_PCKENR2_AWU_Msk           (0x1U << CLK_PCKENR2_AWU_Pos)
#define CLK_PCKENR2_AWU               CLK_PCKENR2_AWU_Msk
// Enable ADC clock
#define CLK_PCKENR2_ADC_Pos           (3U)
#define CLK_PCKENR2_ADC_Msk           (0x1U << CLK_PCKENR2_ADC_Pos)
#define CLK_PCKENR2_ADC               CLK_PCKENR2_ADC_Msk

/*-------------------------------------------------------------------------
*      HSI clock calibration trimming register (CLK_HSITRIMR)
*-----------------------------------------------------------------------*/

// HSI trimming value
#define CLK_HSITRIMR_HSITRIM_Pos           (0U)
#define CLK_HSITRIMR_HSITRIM_Msk           (0xFU << CLK_HSITRIMR_HSITRIM_Pos)
#define CLK_HSITRIMR_HSITRIM               CLK_HSITRIMR_HSITRIM_Msk
#define CLK_HSITRIMR_HSITRIM_0             (0x1U << CLK_HSITRIMR_HSITRIM_Pos)
#define CLK_HSITRIMR_HSITRIM_1             (0x2U << CLK_HSITRIMR_HSITRIM_Pos)
#define CLK_HSITRIMR_HSITRIM_2             (0x4U << CLK_HSITRIMR_HSITRIM_Pos)
#define CLK_HSITRIMR_HSITRIM_3             (0x8U << CLK_HSITRIMR_HSITRIM_Pos)

/*-------------------------------------------------------------------------
*      SWIM clock control register (CLK_SWIMCCR)
*-----------------------------------------------------------------------*/

// SWIM clock divider
#define CLK_SWIMCCR_SWIMCLK_Pos           (0U)
#define CLK_SWIMCCR_SWIMCLK_Msk           (0x1U << CLK_SWIMCCR_SWIMCLK_Pos)
#define CLK_SWIMCCR_SWIMCLK               CLK_SWIMCCR_SWIMCLK_Msk


/*======================================================================
*      Beeper (BEEP)
*=======================================================================*/
typedef struct
{
	volatile unsigned char CSR;
} BeeperTypedef;

#define BEEP_BASE                (0x0050F3)
#define BEEP                     ((BeeperTypedef *) BEEP_BASE)

/*-------------------------------------------------------------------------
*      Beeper control/status register (BEEP_CSR)
*-----------------------------------------------------------------------*/

// Beep prescaler divider
#define BEEP_CSR_BEEPDIV_Pos           (0U)
#define BEEP_CSR_BEEPDIV_Msk           (0x1FU << BEEP_CSR_BEEPDIV_Pos)
#define BEEP_CSR_BEEPDIV               BEEP_CSR_BEEPDIV_Msk
#define BEEP_CSR_BEEPDIV_0             (0x1U << BEEP_CSR_BEEPDIV_Pos)
#define BEEP_CSR_BEEPDIV_1             (0x2U << BEEP_CSR_BEEPDIV_Pos)
#define BEEP_CSR_BEEPDIV_2             (0x4U << BEEP_CSR_BEEPDIV_Pos)
#define BEEP_CSR_BEEPDIV_3             (0x8U << BEEP_CSR_BEEPDIV_Pos)
#define BEEP_CSR_BEEPDIV_4             (0x10U << BEEP_CSR_BEEPDIV_Pos)
// Beep enable
#define BEEP_CSR_BEEPEN_Pos            (5U)
#define BEEP_CSR_BEEPEN_Msk            (0x1U << BEEP_CSR_BEEPEN_Pos)
#define BEEP_CSR_BEEPEN                BEEP_CSR_BEEPEN_Msk
// Beep selection
#define BEEP_CSR_BEEPSEL_Pos           (6U)
#define BEEP_CSR_BEEPSEL_Msk           (0x3U << BEEP_CSR_BEEPSEL_Pos)
#define BEEP_CSR_BEEPSEL               BEEP_CSR_BEEPSEL_Msk
#define BEEP_CSR_BEEPSEL_0             (0x1U << BEEP_CSR_BEEPSEL_Pos)
#define BEEP_CSR_BEEPSEL_1             (0x2U << BEEP_CSR_BEEPSEL_Pos)


/*======================================================================
*      Universal asynchronous receiver transmitter (UART)
*=======================================================================*/
typedef struct
{
	volatile unsigned char SR;
	volatile unsigned char DR;
	volatile unsigned char BRR1;
	volatile unsigned char BRR2;
	volatile unsigned char CR1;
	volatile unsigned char CR2;
	volatile unsigned char CR3;
	volatile unsigned char CR4;
	volatile unsigned char CR5;
	volatile unsigned char GTR;
	volatile unsigned char PSCR;
} UartTypedef;

#define UART1_BASE                (0x005230)
#define UART1                     ((UartTypedef *) UART1_BASE)

/*-------------------------------------------------------------------------
*      Status register (UART_SR)
*-----------------------------------------------------------------------*/

// Parity error
#define UART_SR_PE_Pos         (0U)
#define UART_SR_PE_Msk         (0x1U << UART_SR_PE_Pos)
#define UART_SR_PE             UART_SR_PE_Msk
// Framing error
#define UART_SR_FE_Pos         (1U)
#define UART_SR_FE_Msk         (0x1U << UART_SR_FE_Pos)
#define UART_SR_FE             UART_SR_FE_Msk
// Noise flag
#define UART_SR_NF_Pos         (2U)
#define UART_SR_NF_Msk         (0x1U << UART_SR_NF_Pos)
#define UART_SR_NF             UART_SR_NF_Msk
// Overrun error
#define UART_SR_OR_Pos         (3U)
#define UART_SR_OR_Msk         (0x1U << UART_SR_OR_Pos)
#define UART_SR_OR             UART_SR_OR_Msk
// LIN Header Error
#define UART_SR_LHE_Pos        (3U)
#define UART_SR_LHE_Msk        (0x1U << UART_SR_LHE_Pos)
#define UART_SR_LHE            UART_SR_LHE_Msk
// IDLE line detected
#define UART_SR_IDLE_Pos       (4U)
#define UART_SR_IDLE_Msk       (0x1U << UART_SR_IDLE_Pos)
#define UART_SR_IDLE           UART_SR_IDLE_Msk
// Read data register not empty
#define UART_SR_RXNE_Pos       (5U)
#define UART_SR_RXNE_Msk       (0x1U << UART_SR_RXNE_Pos)
#define UART_SR_RXNE           UART_SR_RXNE_Msk
// Transmission complete
#define UART_SR_TC_Pos         (6U)
#define UART_SR_TC_Msk         (0x1U << UART_SR_TC_Pos)
#define UART_SR_TC             UART_SR_TC_Msk
// Transmit data register empty
#define UART_SR_TXE_Pos        (7U)
#define UART_SR_TXE_Msk        (0x1U << UART_SR_TXE_Pos)
#define UART_SR_TXE            UART_SR_TXE_Msk

/*-------------------------------------------------------------------------
*      Control register 1 (UART_CR1)
*-----------------------------------------------------------------------*/

// Parity interrupt enable
#define UART_CR1_PIEN_Pos         (0U)
#define UART_CR1_PIEN_Msk         (0x1U << UART_CR1_PIEN_Pos)
#define UART_CR1_PIEN             UART_CR1_PIEN_Msk
// Parity selection
#define UART_CR1_PS_Pos           (1U)
#define UART_CR1_PS_Msk           (0x1U << UART_CR1_PS_Pos)
#define UART_CR1_PS               UART_CR1_PS_Msk
// Parity control enable
#define UART_CR1_PCEN_Pos         (2U)
#define UART_CR1_PCEN_Msk         (0x1U << UART_CR1_PCEN_Pos)
#define UART_CR1_PCEN             UART_CR1_PCEN_Msk
// Wakeup method
#define UART_CR1_WAKE_Pos         (3U)
#define UART_CR1_WAKE_Msk         (0x1U << UART_CR1_WAKE_Pos)
#define UART_CR1_WAKE             UART_CR1_WAKE_Msk
// word length
#define UART_CR1_M_Pos            (4U)
#define UART_CR1_M_Msk            (0x1U << UART_CR1_M_Pos)
#define UART_CR1_M                UART_CR1_M_Msk
// UART Disable (for low power consumption)
#define UART_CR1_UARTD_Pos        (5U)
#define UART_CR1_UARTD_Msk        (0x1U << UART_CR1_UARTD_Pos)
#define UART_CR1_UARTD            UART_CR1_UARTD_Msk
// Transmit data bit 8
#define UART_CR1_T8_Pos           (6U)
#define UART_CR1_T8_Msk           (0x1U << UART_CR1_T8_Pos)
#define UART_CR1_T8               UART_CR1_T8_Msk
// Receive Data bit 8
#define UART_CR1_R8_Pos           (7U)
#define UART_CR1_R8_Msk           (0x1U << UART_CR1_R8_Pos)
#define UART_CR1_R8               UART_CR1_R8_Msk

/*-------------------------------------------------------------------------
*      Control register 2 (UART_CR2)
*-----------------------------------------------------------------------*/

// Send break
#define UART_CR2_SBK_Pos         (0U)
#define UART_CR2_SBK_Msk         (0x1U << UART_CR2_SBK_Pos)
#define UART_CR2_SBK             UART_CR2_SBK_Msk
// Receiver wakeup
#define UART_CR2_RWU_Pos         (1U)
#define UART_CR2_RWU_Msk         (0x1U << UART_CR2_RWU_Pos)
#define UART_CR2_RWU             UART_CR2_RWU_Msk
// Receiver enable
#define UART_CR2_REN_Pos         (2U)
#define UART_CR2_REN_Msk         (0x1U << UART_CR2_REN_Pos)
#define UART_CR2_REN             UART_CR2_REN_Msk
// Transmitter enable
#define UART_CR2_TEN_Pos         (3U)
#define UART_CR2_TEN_Msk         (0x1U << UART_CR2_TEN_Pos)
#define UART_CR2_TEN             UART_CR2_TEN_Msk
// IDLE Line interrupt enable
#define UART_CR2_ILIEN_Pos       (4U)
#define UART_CR2_ILIEN_Msk       (0x1U << UART_CR2_ILIEN_Pos)
#define UART_CR2_ILIEN           UART_CR2_ILIEN_Msk
// Receiver interrupt enable
#define UART_CR2_RIEN_Pos        (5U)
#define UART_CR2_RIEN_Msk        (0x1U << UART_CR2_RIEN_Pos)
#define UART_CR2_RIEN            UART_CR2_RIEN_Msk
// Transmission complete interrupt enable
#define UART_CR2_TCIEN_Pos       (6U)
#define UART_CR2_TCIEN_Msk       (0x1U << UART_CR2_TCIEN_Pos)
#define UART_CR2_TCIEN           UART_CR2_TCIEN_Msk
// Transmitter interrupt enable
#define UART_CR2_TIEN_Pos        (7U)
#define UART_CR2_TIEN_Msk        (0x1U << UART_CR2_TIEN_Pos)
#define UART_CR2_TIEN            UART_CR2_TIEN_Msk

/*-------------------------------------------------------------------------
*      Control register 3 (UART_CR3)
*-----------------------------------------------------------------------*/

// Last bit clock pulse
#define UART_CR3_LBCL_Pos         (0U)
#define UART_CR3_LBCL_Msk         (0x1U << UART_CR3_LBCL_Pos)
#define UART_CR3_LBCL             UART_CR3_LBCL_Msk
// Clock phase
#define UART_CR3_CPHA_Pos         (1U)
#define UART_CR3_CPHA_Msk         (0x1U << UART_CR3_CPHA_Pos)
#define UART_CR3_CPHA             UART_CR3_CPHA_Msk
// Clock polarity
#define UART_CR3_CPOL_Pos         (2U)
#define UART_CR3_CPOL_Msk         (0x1U << UART_CR3_CPOL_Pos)
#define UART_CR3_CPOL             UART_CR3_CPOL_Msk
// Clock enable
#define UART_CR3_CLKEN_Pos        (3U)
#define UART_CR3_CLKEN_Msk        (0x1U << UART_CR3_CLKEN_Pos)
#define UART_CR3_CLKEN            UART_CR3_CLKEN_Msk
// STOP bits
#define UART_CR3_STOP_Pos         (4U)
#define UART_CR3_STOP_Msk         (0x3U << UART_CR3_STOP_Pos)
#define UART_CR3_STOP             UART_CR3_STOP_Msk
#define UART_CR3_STOP_0           (0x1U << UART_CR3_STOP_Pos)
#define UART_CR3_STOP_1           (0x2U << UART_CR3_STOP_Pos)
// LIN mode enable
#define UART_CR3_LINEN_Pos        (6U)
#define UART_CR3_LINEN_Msk        (0x1U << UART_CR3_LINEN_Pos)
#define UART_CR3_LINEN            UART_CR3_LINEN_Msk

/*-------------------------------------------------------------------------
*      Control register 4 (UART_CR4)
*-----------------------------------------------------------------------*/

// Address of the UART node
#define UART_CR4_ADD_Pos         (0U)
#define UART_CR4_ADD_Msk         (0xFU << UART_CR4_ADD_Pos)
#define UART_CR4_ADD             UART_CR4_ADD_Msk
#define UART_CR4_ADD_0           (0x1U << UART_CR4_ADD_Pos)
#define UART_CR4_ADD_1           (0x2U << UART_CR4_ADD_Pos)
#define UART_CR4_ADD_2           (0x4U << UART_CR4_ADD_Pos)
#define UART_CR4_ADD_3           (0x8U << UART_CR4_ADD_Pos)
// LIN Break Detection Flag
#define UART_CR4_LBDF_Pos        (4U)
#define UART_CR4_LBDF_Msk        (0x1U << UART_CR4_LBDF_Pos)
#define UART_CR4_LBDF            UART_CR4_LBDF_Msk
// LIN Break Detection Length
#define UART_CR4_LBDL_Pos        (5U)
#define UART_CR4_LBDL_Msk        (0x1U << UART_CR4_LBDL_Pos)
#define UART_CR4_LBDL            UART_CR4_LBDL_Msk
// LIN Break Detection Interrupt Enable
#define UART_CR4_LBDIEN_Pos      (6U)
#define UART_CR4_LBDIEN_Msk      (0x1U << UART_CR4_LBDIEN_Pos)
#define UART_CR4_LBDIEN          UART_CR4_LBDIEN_Msk

/*-------------------------------------------------------------------------
*      Control register 5 (UART_CR5)
*-----------------------------------------------------------------------*/

// IrDA mode Enable
#define UART_CR5_IREN_Pos        (1U)
#define UART_CR5_IREN_Msk        (0x1U << UART_CR5_IREN_Pos)
#define UART_CR5_IREN            UART_CR5_IREN_Msk
// IrDA Low Power
#define UART_CR5_IRLP_Pos        (2U)
#define UART_CR5_IRLP_Msk        (0x1U << UART_CR5_IRLP_Pos)
#define UART_CR5_IRLP            UART_CR5_IRLP_Msk
// Half-Duplex Selection
#define UART_CR5_HDSEL_Pos        (3U)
#define UART_CR5_HDSEL_Msk        (0x1U << UART_CR5_HDSEL_Pos)
#define UART_CR5_HDSEL            UART_CR5_HDSEL_Msk
// Smartcard NACK enable
#define UART_CR5_NACK_Pos        (4U)
#define UART_CR5_NACK_Msk        (0x1U << UART_CR5_NACK_Pos)
#define UART_CR5_NACK            UART_CR5_NACK_Msk
// Smartcard mode enable
#define UART_CR5_SCEN_Pos        (5U)
#define UART_CR5_SCEN_Msk        (0x1U << UART_CR5_SCEN_Pos)
#define UART_CR5_SCEN            UART_CR5_SCEN_Msk


/*======================================================================
*      Global configuration register (GCR)
*=======================================================================*/
typedef struct
{
	volatile unsigned char GCR;
} CfgTypedef;

#define CFG_BASE                 (0x007F60)

#define CFG                      ((CfgTypedef *) CFG_BASE)

#define CFG_GCR_SWD_Pos          (0U)
#define CFG_GCR_SWD_Msk          (0x1U << CFG_GCR_SWD_Pos)
#define CFG_GCR_SWD              CFG_GCR_SWD_Msk
#define CFG_GCR_AL_Pos           (1U)
#define CFG_GCR_AL_Msk           (0x1U << CFG_GCR_AL_Pos)
#define CFG_GCR_AL               CFG_GCR_AL_Msk

#endif