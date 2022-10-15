# IR_RemoteControl
Infrared (IR) Remote Control

Microcontroller: STM32F10x

The code is based on the most popular IR protocol “NEC” 
IR receiver/sensor module is based on 38KHz. It gives logic 0 when an IR radiation and logic 1 otherwise 
Logic 0 – a 562.5μs pulse burst followed by a 562.5μs space, with a total transmit time of 1.125ms
Logic 1 – a 562.5μs pulse burst followed by a 1.6875ms space, with a total transmit time of 2.25ms
IR frame: Start bit, 8 bits address, 8 bits inverted address, 8 bits data, 8 bits inverted data

Algorithm:
• Enable external interrupt on pin A0, falling edge (since o/p of IR sensor is high without receiving any IR communication)
• Once interrupt received, a timer (SysTick) starts counting until the next interrupt (falling edge). With each interrupt, timer is reinitialized.  
• ElapsedTime function calculates Time interval between 2 successive falling edges and save the elapsed time in array of 50 elements to cater for the repeat code i.e, longer press on the button. 
• If elapsed time is around 13500us then this is a valid IR frame (start bit) then run InterpretIRData function, which determines whether received data is zero or one based on the calculated pulse duration.
• A flag is set to zero as indication for the start bit then set to one to be cleared at the end of the frame 
• Start bit and 16 bits of address and its inversion are ignored so the extracted data represents bit 17th to bit 24th 
• Received data (8 bits) represents the decimal value of each button on the remote control; action/s would be taken based on the received decimal value.
