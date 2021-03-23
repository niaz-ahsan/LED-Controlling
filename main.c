/**
 ******************************************************************************
 Problem statement: Take user input and turn on/off LEDs
 ******************************************************************************
 */

#include <stdint.h>
#include <unistd.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

uint32_t *GPIO_D_mode = (uint32_t*) 0x40020C00; // GPIO D Mode Register Address
uint32_t *GPIO_D_output_data = (uint32_t*) 0x40020C14; // GPIO D O/P Data Register Address

// Green LED
void toggle_LD4() {
	// 25,24 bit position of GPIO D Mode Register should be 0 and 1.
	// First, clear 25 bit position
	*GPIO_D_mode &= ~(1 << 25);
	// set 24 bit position
	*GPIO_D_mode |= (1 << 24);

	// setting 12 bit position of GPIO D o/p data, controlled by PD12
	*GPIO_D_output_data |= (1 << 12);

	// Toggling 12 bit position of GPIO D o/p data, controlled by PD12
	//*GPIO_D_output_data ^= (1 << 12);
}

// Orange LED
void toggle_LD3() {
	// 27,26 bit position of GPIO D Mode Register should be 0 and 1.
	// First, clear 27 bit position
	*GPIO_D_mode &= ~(1 << 27);
	// set 26 bit position
	*GPIO_D_mode |= (1 << 26);

	// setting 13 bit position of GPIO D o/p data, controlled by PD13
	*GPIO_D_output_data |= (1 << 13);
}

// Red LED
void toggle_LD5() {
	// 29,28 bit position of GPIO D Mode Register should be 0 and 1.
	// First, clear 29 bit position
	*GPIO_D_mode &= ~(1 << 29);
	// set 28 bit position
	*GPIO_D_mode |= (1 << 28);

	// setting 14 bit position of GPIO D o/p data, controlled by PD14
	*GPIO_D_output_data |= (1 << 14);
}

// Blue LED
void toggle_LD6() {
	// 31,30 bit position of GPIO D Mode Register should be 0 and 1.
	// First, clear 31 bit position
	*GPIO_D_mode &= ~(1 << 31);
	// set 30 bit position
	*GPIO_D_mode |= (1 << 30);

	// setting 15 bit position of GPIO D o/p data, controlled by PD15
	*GPIO_D_output_data |= (1 << 15);
}

int main(void)
{
	uint32_t *RCC_clock = (uint32_t*) 0x40023830; // RCC_AHB1ENR Address

	// setting 3rd bit of RCC Clock register to enable GPIO D peripheral
	*RCC_clock |= (1 << 3);

    /* Loop forever */
	for(int i=0; i < 5; i++) {
		toggle_LD3();
		toggle_LD4();
		toggle_LD5();
		toggle_LD6();

		//sleep(5);
	}
}
