#include <plib.h>

int main()
{
	TRISE = 0x00;
	PORTE = 0x00;

	TRISD |= 1 << 10;
	PORTD = 0x00;

	INTCON &= ~(1 << 1);

	IPC3 = 1 << 26;

	IFS0 &= ~(1 << 15);
	IEC0 |= 1 << 15;

	INTEnableSystemMultiVectoredInt();

	while (1);
}

void _ISR(15, ipl6) ChangeNotice_Handler(void)
{
	IFS0 &= ~(1 << 15);
	PORTE ^= 1;
}
