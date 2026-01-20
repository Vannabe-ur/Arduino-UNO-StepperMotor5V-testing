# Joystick-Controlled Stepper Motor Using Arduino UNO
The project focused on testing how Stepper Motor 5V works by using with Joystick Module.

### Objective
Use a joystick module to:
- Control the rotation direction of a stepper motor
- Control the speed of the stepper motor

### HARDWARE NEEDS
- Arduino UNO
- Stepper Motor 5V
- Joystick Module PS2
- ULN2003 Module
- Breadboard and jumper wires

### SOFTWARE NEEDS
- Arduino IDE
- Library `Stepper` by Arduino

### COMPONENTS CONNECTION
**Joystick Module**

| Pin | Function      |
| --- | ------------- |
| VCC | 5 V           |
| GND | GND           |
| VRx | Analog output |
| SW  | Push button   |

**ULN2003 DRIVER**
- Circut Connection

*Joystick → Arduino*
| Joystick | Arduino      |
| -------- | ------------ |
| VCC      | 5 V          |
| GND      | GND          |
| VRx      | A0           |
| SW       | D2           |

*Arduino → ULN2003*
| Arduino  | ULN2003      |
| -------- | ------------ |
| D8       | IN1          |
| D9       | IN2          |
| D10      | IN3          |
| D11      | IN4          |

*Motor Power*
- ULN2003 VCC → external 5 V
- ULN2003 GND → Arduino GND

### Working Principle

- Joystick center ≈ 512 → motor stops
- Joystick moved left → motor rotates **counter-clockwise**
- Joystick moved right → motor rotates **clockwise**
- Distance from center controls **speed**
- Button toggles motor ON/OFF

### Expected Behavior
| Joystick Position | Motor Action  |
| ----------------- | ------------- |
| Center            | Stop          |
| Left              | Rotate CCW    |
| Right             | Rotate CW     |
| Button Press      | Toggle ON/OFF |
