# Vole Machine Language Simulator

## Description:
**In this machine, data is taken as a file of space separated chars representing the instructions, e.g. 10FF, then apply instructions(Machine Language).**

## Machine Components:
- **Register:** 16 register storage space for units of memory that are used to transfer data for immediate use.
- **Memory:** 256 cell to store data.
- **Instructions:** applying some operations in the machine.
- **Machine:** run the whole program and link it together.

## Machine Language:
| **Opcode** | **Format** | **Description** |
|--------|--------|-------------|
| 1      | RXY    | **LOAD** the register R with the bit pattern found in the memory cell whose address is XY. |
| 2      | RXY    | **LOAD** the register R with the bit pattern XY. |
| 3      | RXY    | **STORE** the bit pattern found in register R in the memory cell whose address is XY. |
| 4      | 0RS    | **MOVE** the bit pattern found in register R to register S. |
| 5      | RST    | **ADD** the bit patterns in registers S and T as though they were **two’s complement representations** and leave the result in register R. |
| 6      | RST    | **ADD** the bit patterns in registers S and T as though they **represented values in floating-point notation** and leave the floating-point result in register R. |
| 7      | RST    | **OR** the bit patterns in registers S and T and place the result in register R. |
| 8      | RST    | **AND** the bit patterns in registers S and T and place the result in register R. |
| 9      | RST    | **EXCLUSIVE OR** the bit patterns in registers S and T and place the result in register R. |
| A      | R0X    | **ROTATE** the bit pattern in register R one bit to the right X times. Each time place the bit that started at the low-order end at the high-order end. |
| B      | RXY    | **JUMP** to the location in the memory cell at address XY if the bit pattern in register R is equal to the bit pattern in register number 0. Otherwise, continue with the normal sequence of execution. |
| C      | 000    | **HALT** execution. |
| D      | RXY    | **JUMP** to instruction in RAM cell XY if the content of register R is greater than (>) the content of register 0. Data is interpreted as integers in two's complement notation. |

## Contributing:
If you'd like to contribute to this repository, feel free to fork the project and create a pull request with your changes. Make sure to follow the coding standards and ensure your changes are well-documented.


## Authors:
- [Esraa Emary Abd El-Salam](https://www.linkedin.com/in/esraa-emary-b372b8303/) - (20230054)
- [Mohammed Atef Abd El-Kader](https://www.linkedin.com/in/mohammed-atef-b0a408299/) - (20231143)
- [Nagham Wael Mohamed El-Sayed](https://www.linkedin.com/in/nagham-wael-5aa70a318/) - (20231189)

## License:
This project is licensed under the MIT License – see the [LICENSE](https://github.com/esraa-emary/Vole-Machine-Language-Simulator/blob/main/LICENSE) file for details.

## Version: 7.0
