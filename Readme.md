# PeeWeeMonster - Arduino-based PWM Add-on for TB-303 and TD-3 Synths

The "Mix" input on the Roland TB-303 and the "Filter" input on Behringer's faithful clone the TD-3 provide the ability to run an additional audio signal through the synth's analog filter. Additionally, the CV and Gate out ports allow these synths to send note on/of and note pitch using Control Voltage, the analog predecessor to MIDI.

PeeWeeMonster reads the CV and Gate output from the synthesizer to run an additional square wave oscillator that can either be fed back into the synth's Mix/Filter input, or into any other audio input. This square wave signal can also be altered using Pulse Width Modulation (PWM) to create interesting phasing effects. PeeWeeMonster also features LFO-like functions to automatically sweep the pulse width in triangle, ramp up, and ramp down waves of variable frequency.

Additionally, PeeWeeMonster features two low-frequency modes in which sending the signal high and low can simply modulate the sound of the external synth's analog filter, creating "bubbly" effects.

Built on an Arduino Uno and PlatformIO.

## Modes

1. RED - CV Voice with Single Potentiometer Driven PWM
2. GREEN - CV Voice with Dual Potentiometer Driven PWM Sweeps
3. BLUE - Potentiometer Driven Tone with Potentiometer Driven PWM
4. CYAN - Potentiometer Driven Tone with PWM Sweeps
5. PURPLE - Low Frequency Filter Wobble in Even Steps
6. YELLOW - Low Frequency Filter Wobble, Smooth
7. WHITE - Repeat Sync Signal (Not quite working Yet)