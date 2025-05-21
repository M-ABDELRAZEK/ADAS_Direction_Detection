# ADAS Vehicle Direction Detection System

## Table of Contents
- [System Overview](#system-overview)
- [Key Components](#key-components)
- [Signal Specifications](#signal-specifications)
- [Simulink Model Structure](#simulink-model-structure)

## System Overview
This MATLAB Simulink model implements an Advanced Driver Assistance System (ADAS) for vehicle direction detection. The system:
- Detects steering direction via yaw rate input
- Validates against recognized road signs
- Provides real-time feedback to ensure correct vehicle movement

## Key Components
| Component | Description |
|-----------|-------------|
| Steering Input Subsystem | Processes yaw rate (-180° to 180°) to detect turns |
| Road Sign Validation | Compares detected direction with camera input |
| Direction Indicator | Outputs Boolean (0/1) confirmation signal |

## Signal Specifications
| Signal | Type | Range | Units | Description |
|--------|------|-------|-------|-------------|
| `Steering_Input_YawRate` | Input | -180 to 180 | Degrees | Yaw rate from steering wheel |
| `RoadSign_Input_Camera` | Input | 0 to 1 | Boolean | Road sign detection signal |
| `Turn_Direction_Status` | Local | -180 to 180 | Degrees | Current direction state |
| `Direction_Indicator_Output` | Output | 0 to 1 | Boolean | Direction confirmation |

## Simulink Model Structure
```plaintext
VehicleDirectionDetector/
├── SteeringDetection/       # Subsystem for yaw rate processing
│   ├── CompareRightTurn     # Checks against +30° threshold
│   ├── CompareLeftTurn      # Checks against -120° threshold
│   └── StraightDetection    # Identifies neutral steering
├── SignValidation/          # Road sign matching logic
└── OutputGeneration/        # Final confirmation signal
